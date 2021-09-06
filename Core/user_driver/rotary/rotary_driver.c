/*
 * rotary_driver.c
 *
 *  Created on: Jun 5, 2021
 *      Author: Yolo
 */
#include "Common.h"
#include "rotary_driver.h"
#include "stm32l0xx_hal_gpio.h"
#include "main.h"
/***********************************************************************************************************************
* typedef  Varible
***********************************************************************************************************************/


static uint8_t rotary_detect(GPIO_TypeDef *r_port_1, uint16_t pin_1,
							 GPIO_TypeDef *r_port_2, uint16_t pin_2,
							 GPIO_TypeDef *r_port_4, uint16_t pin_4,
							 GPIO_TypeDef *r_port_8, uint16_t pin_8);

typedef enum
{
	E_DURATION_TIME_1_MINUTES = 1 * 60,
	E_DURATION_TIME_2_MINUTES = 2 * 60,
	E_DURATION_TIME_4_MINUTES = 4 * 60,
	E_DURATION_TIME_5_MINUTES = 5 * 60
} e_duration_time;

typedef enum
{
	E_INTERVAL_TIME_1_MINUTES = 1 * 60,
	E_INTERVAL_TIME_5_MINUTES = 5 * 60,
	E_INTERVAL_TIME_10_MINUTES = 10 * 60,
	E_INTERVAL_TIME_15_MINUTES = 15 * 60,
	E_INTERVAL_TIME_20_MINUTES = 20 * 60,
	E_INTERVAL_TIME_30_MINUTES = 30 * 60,
	E_INTERVAL_TIME_60_MINUTES = 60 * 60
} e_interval_time;
/***********************************************************************************************************************
* static Functions
***********************************************************************************************************************/
uint8_t time_rotary_1_old_location = 0;
uint8_t time_rotary_2_old_location = 0;
uint8_t rotary_state_update = 0;
uint32_t rotary_time_update;
bool timer_update_value = true;
/***********************************************************************************************************************
* public Functions
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name:  roatary_time_get_value
* Description  :
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
uint32_t time_test = 0;
void roatary_time_get_value(void) // call in loop
{
	uint8_t time_rotary_1_location = 0;
	uint8_t time_rotary_2_location = 0;
	if (user_timer_1s_get_tick() - time_test > 2)
	{
		time_test = user_timer_1s_get_tick();
//		time_rotary_1_location = rotary_detect(ROTARY1_P4_GPIO_Port, ROTARY1_P4_Pin,
//											   ROTARY1_P2_GPIO_Port, ROTARY1_P2_Pin,
//											   ROTARY1_P3_GPIO_Port, ROTARY1_P3_Pin,
//											   ROTARY1_P1_GPIO_Port, ROTARY1_P1_Pin);
//
//		time_rotary_2_location = rotary_detect(ROTARY2_P4_GPIO_Port, ROTARY2_P4_Pin,
//											   ROTARY2_P2_GPIO_Port, ROTARY2_P2_Pin,
//											   ROTARY2_P3_GPIO_Port, ROTARY2_P3_Pin,
//											   ROTARY2_P2_GPIO_Port, ROTARY2_P1_Pin);
//		APP_LOGD("time_rotary_1_location = %d", time_rotary_1_location);
//		APP_LOGD("time_rotary_2_location = %d", time_rotary_2_location);
	}
	time_rotary_1_location = rotary_detect(ROTARY1_P4_GPIO_Port, ROTARY1_P4_Pin,
										   ROTARY1_P2_GPIO_Port, ROTARY1_P2_Pin,
										   ROTARY1_P3_GPIO_Port, ROTARY1_P3_Pin,
										   ROTARY1_P1_GPIO_Port, ROTARY1_P1_Pin);

	time_rotary_2_location = rotary_detect(ROTARY2_P4_GPIO_Port, ROTARY2_P4_Pin,
										   ROTARY2_P2_GPIO_Port, ROTARY2_P2_Pin,
										   ROTARY2_P3_GPIO_Port, ROTARY2_P3_Pin,
										   ROTARY2_P2_GPIO_Port, ROTARY2_P1_Pin);
	// check rotary location change will update time after 2s
	if ((time_rotary_1_location != time_rotary_1_old_location) |
		(time_rotary_2_location != time_rotary_2_old_location))
	{
		time_rotary_1_old_location = time_rotary_1_location;
		time_rotary_2_old_location = time_rotary_2_location;
		rotary_state_update = 1;
		APP_LOGD("rotary 1  = %d", time_rotary_1_old_location);
		APP_LOGD("rotary 2  = %d", time_rotary_2_old_location);
	}
	switch (rotary_state_update)
	{
	case 0:

		break;
	case 1:
		rotary_time_update = user_timer_1ms_get_tick();
		rotary_state_update = 2;
		break;
	case 2:
		if (user_timer_1ms_get_tick() - rotary_time_update > 2000) // update after 2s
		{
			timer_update_value = true;
			rotary_state_update = 0;
			APP_LOGD("update new value rotary done");
		}
		break;
	default:
		break;
	}

	if (timer_update_value)
	{
		timer_update_value = false; // clear update timer by rotary
		switch (time_rotary_1_location)
		{
		case 0:
			device_state.time.time_duration = E_DURATION_TIME_1_MINUTES;
			break;
		case 1:
			device_state.time.time_duration = E_DURATION_TIME_2_MINUTES;
			break;
		case 2:
			device_state.time.time_duration = E_DURATION_TIME_4_MINUTES;
			break;
		case 3:
			device_state.time.time_duration = E_DURATION_TIME_5_MINUTES;
			break;
		default:
			device_state.time.time_duration = E_DURATION_TIME_5_MINUTES;
			break;
		}

		switch (time_rotary_2_location)
		{
		case 0:
			device_state.time.time_interval = E_INTERVAL_TIME_1_MINUTES;
			break;
		case 1:
			device_state.time.time_interval = E_INTERVAL_TIME_5_MINUTES;
			break;
		case 2:
			device_state.time.time_interval = E_INTERVAL_TIME_10_MINUTES;
			break;
		case 3:
			device_state.time.time_interval = E_INTERVAL_TIME_15_MINUTES;
			break;
		case 4:
			device_state.time.time_interval = E_INTERVAL_TIME_20_MINUTES;
			break;
		case 5:
			device_state.time.time_interval = E_INTERVAL_TIME_30_MINUTES;
			break;
		case 6:
			device_state.time.time_interval = E_INTERVAL_TIME_60_MINUTES;
			break;
		default:
			device_state.time.time_interval = E_INTERVAL_TIME_60_MINUTES;
			break;
		}
		APP_LOGD("device_state.time.time_duration = %d ", device_state.time.time_duration);
		APP_LOGD("device_state.time.time_interval = %d ", device_state.time.time_interval);
	}
}
/***********************************************************************************************************************
* Function Name:  vsm_protocol_cmd_handler
* Description  :
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name:  vsm_protocol_cmd_handler
* Description  :
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/

/***********************************************************************************************************************
* Static Functions
***********************************************************************************************************************/
static uint8_t rotary_detect(GPIO_TypeDef *r_port_1, uint16_t pin_1,
							 GPIO_TypeDef *r_port_2, uint16_t pin_2,
							 GPIO_TypeDef *r_port_4, uint16_t pin_4,
							 GPIO_TypeDef *r_port_8, uint16_t pin_8)
{
	// union_rotary_t rotary_value;
	uint8_t rotary_1;
	uint8_t rotary_2;
	uint8_t rotary_3;
	uint8_t rotary_4;
	uint8_t sum_rotary;
	rotary_4 = HAL_GPIO_ReadPin(r_port_1, pin_1);
	if (rotary_4 == 0)
		rotary_4 = 1;
	else
		rotary_4 = 0;
	rotary_3 = HAL_GPIO_ReadPin(r_port_2, pin_2);
	if (rotary_3 == 0)
		rotary_3 = 1;
	else
		rotary_3 = 0;
	rotary_2 = HAL_GPIO_ReadPin(r_port_4, pin_4);
	if (rotary_2 == 0)
		rotary_2 = 1;
	else
		rotary_2 = 0;
	rotary_1 = HAL_GPIO_ReadPin(r_port_8, pin_8);
	if (rotary_1 == 0)
		rotary_1 = 1;
	else
		rotary_1 = 0;
	sum_rotary = (rotary_4 << 3) | (rotary_3 << 2) | (rotary_2 << 1) | rotary_1;
	// return rotary_value.sum_rotary;

	return sum_rotary;
}
/***********************************************************************************************************************
* End of file
***********************************************************************************************************************/
