/*
 * charger_status.c
 *
 *  Created on: Sep 5, 2021
 *      Author: Yolo
 */

#include "main.h"
#include "stm32l0xx_hal_gpio.h"
#include "charger_status.h"

uint8_t value_return = 0;
uint8_t driver_charger_status(void)
{
	uint8_t STAT1 = 0;
	uint8_t STAT2 = 0;

	STAT1 = HAL_GPIO_ReadPin(CHARGE_STAT1_GPIO_Port, CHARGE_STAT1_Pin);
	STAT1 = HAL_GPIO_ReadPin(CHARGE_STAT2_GPIO_Port, CHARGE_STAT2_Pin);
	value_return = ((STAT1 << 1) | STAT2 );
	return value_return;
}

