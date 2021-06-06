/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_RED_Pin GPIO_PIN_13
#define LED_RED_GPIO_Port GPIOC
#define LED_GREEN_Pin GPIO_PIN_0
#define LED_GREEN_GPIO_Port GPIOH
#define LED_BLUE_Pin GPIO_PIN_1
#define LED_BLUE_GPIO_Port GPIOH
#define ROTARY1_P1_Pin GPIO_PIN_5
#define ROTARY1_P1_GPIO_Port GPIOA
#define ROTARY1_P2_Pin GPIO_PIN_6
#define ROTARY1_P2_GPIO_Port GPIOA
#define ROTARY1_P3_Pin GPIO_PIN_7
#define ROTARY1_P3_GPIO_Port GPIOA
#define ROTARY1_P4_Pin GPIO_PIN_0
#define ROTARY1_P4_GPIO_Port GPIOB
#define ROTARY2_P1_Pin GPIO_PIN_1
#define ROTARY2_P1_GPIO_Port GPIOB
#define ROTARY2_P2_Pin GPIO_PIN_2
#define ROTARY2_P2_GPIO_Port GPIOB
#define ROTARY2_P3_Pin GPIO_PIN_10
#define ROTARY2_P3_GPIO_Port GPIOB
#define ROTARY2_P4_Pin GPIO_PIN_11
#define ROTARY2_P4_GPIO_Port GPIOB
#define FAN_CTRL_Pin GPIO_PIN_12
#define FAN_CTRL_GPIO_Port GPIOB
#define MODE_BTN_Pin GPIO_PIN_15
#define MODE_BTN_GPIO_Port GPIOB
#define LORA_RST_Pin GPIO_PIN_8
#define LORA_RST_GPIO_Port GPIOA
#define CHARGE_STAT2_Pin GPIO_PIN_15
#define CHARGE_STAT2_GPIO_Port GPIOA
#define CHARGE_STAT1_Pin GPIO_PIN_5
#define CHARGE_STAT1_GPIO_Port GPIOB
#define POWER_CTRL_Pin GPIO_PIN_8
#define POWER_CTRL_GPIO_Port GPIOB
#define HEATING_CTRL_Pin GPIO_PIN_9
#define HEATING_CTRL_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
