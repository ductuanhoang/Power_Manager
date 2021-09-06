/*
 * MyUart.c
 *
 *  Created on: Sep 22, 2019
 *      Author: ADMIN94
 */
#include "uart_com.h"
#include "vsm_fifo.h"
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/* Static variables ---------------------------------------------------------*/
extern UART_HandleTypeDef huart5;

#define UART_COM huart5

//extern fifo_t com_fifo;
//extern uint8_t com_rx_buffer[128];

static uint8_t u8RxByte2 = 0;

static void user_coom_init(void);

/**
* Khoi tao ham uart.
* @author Tuanhd2
* @param void
* @date 09/22/2019
*/
void user_uart_init(void)
{
	/* USER CODE BEGIN USART1_Init 0 */

	/* USER CODE END USART1_Init 0 */

	/* USER CODE BEGIN USART1_Init 1 */

	/* USER CODE END USART1_Init 1 */
	huart5.Instance = USART5;
	huart5.Init.BaudRate = 115200;
	huart5.Init.WordLength = UART_WORDLENGTH_8B;
	huart5.Init.StopBits = UART_STOPBITS_1;
	huart5.Init.Parity = UART_PARITY_NONE;
	huart5.Init.Mode = UART_MODE_TX_RX;
	huart5.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart5.Init.OverSampling = UART_OVERSAMPLING_16;
	huart5.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
	huart5.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
	if (HAL_UART_Init(&huart5) != HAL_OK)
	{
//		Error_Handler();
	}
	/* USER CODE BEGIN USART1_Init 2 */
//	user_coom_init();
	// register call back

	/* USER CODE END USART1_Init 2 */
}

//static void user_coom_init(void)
//{
//	fifo_create(
//		&com_fifo,
//		com_rx_buffer,
//		sizeof(com_rx_buffer) / sizeof(uint8_t),
//		sizeof(uint8_t));
//	/* Infinite loop */
//	HAL_UART_Receive_IT(&UART_COM, (uint8_t *)&u8RxByte2, 1);
//}

//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
//{
//	if (huart == &UART_COM)
//	{
//		fifo_add(&com_fifo, &u8RxByte2);
//		HAL_UART_Receive_IT(&UART_COM, &u8RxByte2, 1);
//	}
//}

/**
* Xoa ham khoi tao uart.
* @author Tuanhd2
* @param void
* @date 09/22/2019
*/
void user_uart_deinit(void)
{
	HAL_UART_DeInit(&UART_COM);
}

bool uart_trasmit(uint8_t *buffer, uint16_t Size)
{
	HAL_StatusTypeDef status;
	status = HAL_UART_Transmit(&UART_COM, (uint8_t *)buffer, Size, 100);

	return (status ? HAL_OK : 1, 0);
}
