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

/***********************************************************************************************************************
* typedef  Varible
***********************************************************************************************************************/

/***********************************************************************************************************************
* static Functions
***********************************************************************************************************************/
static void user_set_switch_state(void);
static void user_set_switch_control(void);
static void user_power_switch_set_state(void);
static void user_power_change_state(void);
static void user_set_led_status(void);
static e_mode old_mode;
/***********************************************************************************************************************
* public Functions
***********************************************************************************************************************/

void user_driver_init(void)
{
	device_state.mode = E_NORMAL_MODE;
	device_state.switching_state.power = E_OFF;
	device_state.switching_state.heating = E_OFF;
	device_state.switching_state.fan = E_OFF;
	old_mode = device_state.mode;
}

void user_driver_process(void) // call in loop
{
}

void user_process(void)
{
	//control_switch_time
	user_set_switch_state();
	user_set_switch_control();
	user_set_led_status();
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
	if (device_state.dc_volt.dc_1_in_volt < (120 - 5))
	{
		device_state.mode = E_SAVE_MODE;
	}
	else if (device_state.dc_volt.dc_1_in_volt > (120 + 5))
	{
		device_state.mode = E_NORMAL_MODE;
	}
	else
	{
		// keep mode
		device_state.mode = device_state.mode;
	}

	if (old_mode != device_state.mode)
	{
		old_mode = device_state.mode;
		user_power_change_state();
	}
	// control heating and fan follow temperature
	if (device_state.mode == E_NORMAL_MODE)
	{
		if (device_state.temprature < (50 - 5)) // 49.5 d
		{
			device_state.switching_state.heating = E_ON;
			device_state.switching_state.fan = E_ON;
		}
		else if (device_state.temprature < (50 + 5)) // 50.5
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
uint8_t state_save_power_switch = 0;
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
			if (user_timer_1s_get_tick() - tick_power_switch > (60 * 60 * 60))
			{
				tick_power_switch = user_timer_1s_get_tick();
				state_save_power_switch = 2;
			}
		case 2:
			device_state.switching_state.power = E_ON;
			tick_power_switch = user_timer_1s_get_tick();
			state_save_power_switch = 3;
			break;
		case 3:
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
static void user_power_change_state(void)
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
