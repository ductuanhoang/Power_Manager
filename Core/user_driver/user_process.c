/*
 * user_process.c
 *
 *  Created on: Jun 5, 2021
 *      Author: Yolo
 */

#include "Common.h"
#include "user_process.h"
#include "button_driver.h"
#include "user_control.h"
#include "user_led.h"
#include "rotary_driver.h"
#include "timer_driver.h"
#include "charger_status.h"
#include "volt_detect.h"
#include "lora_com.h"
#include "adc_driver.h"
#include "sht2x_for_stm32_hal.h"
/***********************************************************************************************************************
* typedef  Varible
***********************************************************************************************************************/
extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;
#define USER_VOLT_USE 12 //12 volt
/***********************************************************************************************************************
* static Functions
***********************************************************************************************************************/
static void user_set_switch_state(void);
static void user_set_switch_control(void);
static void user_power_switch_set_state(void);
static void user_clear_power_change_state(void);
static void user_set_led_status(void);
static void user_process(void);
static void user_sht20_test(void);
static void user_get_tem_pcb_start(void);
static void charger_get_state(void);
static e_mode old_mode;
/***********************************************************************************************************************
* public Functions
***********************************************************************************************************************/
void user_pripheral_init(void)
{
	//	user_uart_init();
	lora_com_init();
	user_timer_1s_start();
	user_timer_1ms_start();
	SHT2x_Init(&hi2c1); // internal sensor on PCB
	SHT2x_SetResolution(RES_14_12);

	user_get_tem_pcb_start();
	adc_init();
}

void user_driver_init(void)
{
	device_state.mode = E_NORMAL_MODE;
	device_state.switching_state.power = E_OFF;
	device_state.switching_state.heating = E_OFF;
	device_state.switching_state.fan = E_OFF;

	device_state.charger_status = E_CHARGE_DONE;
	device_state.dc_volt.dc_1_in_volt = 0;
	old_mode = device_state.mode;
}

void user_driver_process(void) // call in loop
{
	user_process();
}

uint32_t time_sht_read = 0;
static void user_process(void)
{
	/*
	 * get value sensor
	 */
	device_state.dc_volt.dc_1_in_volt = DC1_In_Volt();
	roatary_time_get_value(); // get state rotary
	user_set_switch_state();  //set switch state
	charger_get_state();	  // check charger state
	/*
	 * action
	 * action switch control
	 *
	 */
	user_set_switch_control();
	user_set_led_status();

	if (user_timer_1s_get_tick() - time_sht_read > 2)
	{
		time_sht_read = user_timer_1s_get_tick();
		user_sht20_test();
		switch (device_state.charger_status)
		{
		case E_CHARGE_SUSPEND:
			APP_LOGI("E_CHARGE_SUSPEND");
			break;
		case E_CHARGE_DONE:
			APP_LOGI("E_CHARGE_DONE");
			break;
		case E_CHARGE_FAST:
			APP_LOGI("E_CHARGE_FAST");
			break;
		case E_CHARGER_PRE:
			APP_LOGI("E_CHARGER_PRE");
			break;
		default:
			APP_LOGI("E_CHARGER_ERR overfload value = %d", device_state.charger_status);
			break;
		}
	}
	/*
	 * send lora message
	 */
	lora_com_send_interval();
}
/***********************************************************************************************************************
* static Functions
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name:  user_set_switch_state
* Description  :
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
static void user_set_switch_state(void)
{
	// check mode process
	if (device_state.dc_volt.dc_1_in_volt < (USER_VOLT_USE * 1000 - 0.5 * 1000))
	{
		device_state.mode = E_SAVE_MODE;
	}
	else if (device_state.dc_volt.dc_1_in_volt > (USER_VOLT_USE * 1000 + 0.5 * 1000))
	{
		device_state.mode = E_NORMAL_MODE;
	}
	/*
	else if (device_state.dc_volt.dc_1_in_volt < (240 - 5))
	{
		device_state.mode = E_SAVE_MODE;
	}
	else if (device_state.dc_volt.dc_1_in_volt > (240 + 5))
	{
		device_state.mode = E_NORMAL_MODE;
	}
	*/
	else
	{
		// keep mode
		device_state.mode = device_state.mode;
	}

	if (old_mode != device_state.mode)
	{
		old_mode = device_state.mode;
		user_clear_power_change_state();
	}
	// control heating and fan follow temperature
	if (device_state.mode == E_NORMAL_MODE)
	{
		if (device_state.temperature_pcb < (5.0 - 0.5)) // <5°C
		{
			device_state.switching_state.heating = E_ON;
			device_state.switching_state.fan = E_ON;
		}
		else if (device_state.temperature_pcb < (5.0 - 0.5)) // > 5°C
		{
			device_state.switching_state.heating = E_OFF;
			device_state.switching_state.fan = E_OFF;
		}
		else
		{
			// keep
		}
	}
	// control power switch
	user_power_switch_set_state();
}

/***********************************************************************************************************************
* Function Name:  user_power_switch_set_state
* Description  :
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
uint32_t tick_power_switch = 0;
static uint8_t state_save_power_switch = 0;
static void user_power_switch_set_state(void)
{
	if (device_state.mode == E_SAVE_MODE) // process save mode
	{
		// after 60 min will turn on according duration time
		switch (state_save_power_switch)
		{
		case 0:
			tick_power_switch = user_timer_1s_get_tick();
			state_save_power_switch = 1;
			device_state.switching_state.power = E_OFF;
			break;
		case 1:
			if (user_timer_1s_get_tick() - tick_power_switch > (60 * 60 * 60)) //power ON according rotation switch duration only EVERY 60min
			{
				tick_power_switch = user_timer_1s_get_tick();
				state_save_power_switch = 2;
			}
			break;
		case 2:
			APP_LOGI("switching_state.power E_ON after 60 minutes");
			device_state.switching_state.power = E_ON;
			tick_power_switch = user_timer_1s_get_tick();
			state_save_power_switch = 3;
			break;
		case 3:
			if (user_timer_1s_get_tick() - tick_power_switch > (device_state.time.time_duration))
			{
				device_state.switching_state.power = E_OFF;
				state_save_power_switch = 0;
				APP_LOGI("switching_state.power OFF after time_duration ");
			}
			break;
		default:
			break;
		}
	}
	else if (device_state.mode == E_NORMAL_MODE)
	{
		switch (state_save_power_switch)
		{
		case 0:
			/* code */
			device_state.switching_state.power = E_OFF;
			tick_power_switch = user_timer_1s_get_tick();
			state_save_power_switch = 1;
			break;
		case 1: // interval time
			if (user_timer_1s_get_tick() - tick_power_switch > (device_state.time.time_interval))
			{
				device_state.switching_state.power = E_ON;
				state_save_power_switch = 2;
				tick_power_switch = user_timer_1s_get_tick();
			}
			break;
		case 2: // duration time
			if (user_timer_1s_get_tick() - tick_power_switch > (device_state.time.time_duration))
			{
				device_state.switching_state.power = E_OFF;
				state_save_power_switch = 0;
			}
			break;
		default:
			break;
		}
	}
}
/***********************************************************************************************************************
* Function Name:  user_power_reset_state
* Description  :
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
static void user_clear_power_change_state(void)
{
	state_save_power_switch = 0;
}
/***********************************************************************************************************************
* Function Name:  user_set_switch_control
* Description  :
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/

static void user_set_switch_control(void)
{
	if (device_state.switching_state.power == E_ON)
		User_Power_On();
	else if (device_state.switching_state.power == E_OFF)
		User_Power_Off();

	if (device_state.switching_state.heating == E_ON)
		User_Heating_On();
	else if (device_state.switching_state.heating == E_OFF)
		User_Heating_Off();

	if (device_state.switching_state.fan == E_ON)
		User_Fan_On();
	else if (device_state.switching_state.fan == E_OFF)
		User_Fan_Off();
}
/***********************************************************************************************************************
* Function Name:  user_set_led_status
* Description  :
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
static void user_set_led_status(void)
{
	if (device_state.mode == E_NORMAL_MODE)
	{
		User_Led_Green_On();
		User_Led_Blue_Off();
		User_Led_Red_Off();
	}
	else if (device_state.mode == E_SAVE_MODE)
	{
		User_Led_Blue_On();
		User_Led_Red_Off();
		User_Led_Green_Off();
	}
}
/***********************************************************************************************************************
* Function Name:  user_get_tem_pcb_start
* Description  :
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
static void user_get_tem_pcb_start(void)
{
	unsigned char buffer[20] = {0};
	float cel = SHT2x_GetTemperature(1);
	device_state.temperature_pcb = cel;
	sprintf(buffer, "%d.%dºC", SHT2x_GetInteger(cel), SHT2x_GetDecimal(cel, 1));
	APP_LOGD("device read temp start = %s", buffer);
}
/***********************************************************************************************************************
 * Function Name:  user_sht20_test
 * Description  :
 * Arguments    : none
 * Return Value : none
 ***********************************************************************************************************************/

static void user_sht20_test(void)
{
	unsigned char buffer[100] = {0};
	/* Gets current temperature & relative humidity. */
	float cel = SHT2x_GetTemperature(1);
	device_state.temperature_pcb = cel;
	/* Converts temperature to degrees Fahrenheit and Kelvin */
	float fah = SHT2x_CelsiusToFahrenheit(cel);
	float kel = SHT2x_CelsiusToKelvin(cel);
	float rh = SHT2x_GetRelativeHumidity(1);
	/* May show warning below. Ignore and proceed. */
	sprintf(buffer,
			"%d.%dºC, %d.%dºF, %d.%d K, %d.%d%% RH",
			SHT2x_GetInteger(cel), SHT2x_GetDecimal(cel, 1),
			SHT2x_GetInteger(fah), SHT2x_GetDecimal(fah, 1),
			SHT2x_GetInteger(kel), SHT2x_GetDecimal(kel, 1),
			SHT2x_GetInteger(rh), SHT2x_GetDecimal(rh, 1));
	APP_LOGD(buffer);
}
/***********************************************************************************************************************
 * Function Name:  charger_get_state
 * Description  :
 * Arguments    : none
 * Return Value : none
 ***********************************************************************************************************************/
void charger_get_state(void)
{
	device_state.charger_status = driver_charger_status();
}
