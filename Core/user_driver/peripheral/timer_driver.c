/*
 * timer_driver.c
 *
 *  Created on: Jun 5, 2021
 *      Author: Yolo
 */



#include "timer_driver.h"
#include "main.h"
#include "stm32l0xx_hal_tim.h"
/***********************************************************************************************************************
* static  Varible
***********************************************************************************************************************/
uint32_t timer_1s_count = 0;
uint32_t timer_1ms_count = 0;

/***********************************************************************************************************************
* Public Functions
***********************************************************************************************************************/
extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim7;
/***********************************************************************************************************************
* public Functions
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name:  user_timer_1s_start
* Description  :
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void user_timer_1s_start(void)
{
	HAL_TIM_Base_Start_IT(&htim6);
}

uint32_t user_timer_1s_get_tick(void)
{
	return timer_1s_count;
}

/***********************************************************************************************************************
* Function Name:  vsm_protocol_cmd_handler
* Description  :
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void user_timer_1ms_start(void)
{
	HAL_TIM_Base_Start_IT(&htim7);
}

uint32_t user_timer_1ms_get_tick(void)
{
	return timer_1ms_count;
}
/***********************************************************************************************************************
* Static Functions
***********************************************************************************************************************/

/***********************************************************************************************************************
* End of file
***********************************************************************************************************************/
