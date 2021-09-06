/*
 * lora_com.c
 *
 *  Created on: Sep 6, 2021
 *      Author: Yolo
 */

#include "lora_com.h"
#include <stdlib.h> /* atoi */
#include "Common.h"
#include "vsm_fifo.h"
#include "uart_com.h"
#include "main.h"

/***********************************************************************************************************************
* define  Varilora
***********************************************************************************************************************/
#define HEADER_01 0xAA
#define HEADER_02 0x55

/***********************************************************************************************************************
* static  Varilora
***********************************************************************************************************************/

fifo_t com_fifo;
uint8_t com_rx_buffer[128] = {0};
static uint8_t length_count = 0;

static uint8_t ch = 0;

#define DATA_RX_MAX_LENGHT 128
bool new_message = false;
uint32_t previous_tick_count = 0;
uint32_t previous_tick_send = 0;
static uint8_t step_lora_send = 0;
/***********************************************************************************************************************
* Public Functions
***********************************************************************************************************************/
static bool lora_packet_message(uint8_t *buf, uint8_t buf_len);
static void device_send_report(void);
/***********************************************************************************************************************
* Function Name:  vsm_protocol_cmd_handler
* Description  :
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void lora_com_init(void)
{
//	user_lora_uart_init(); // for lora communication init
}

void lora_com_send_interval(void)
{
	switch (step_lora_send) {
		case 0:
			previous_tick_send = user_timer_1ms_get_tick();
			step_lora_send = 1;
			break;
		case 1:
			if( user_timer_1ms_get_tick() - previous_tick_send > (60*60*60)) // 60 minutes
			{
				step_lora_send = 0;
				device_send_report();
			}
			break;
		default:
			break;
	}

}

/***********************************************************************************************************************
* Function Name:  lora_hanlder_loop
* Description  :
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void lora_hanlder_loop(void)
{

	if (fifo_is_empty(&com_fifo) != true && fifo_get(&com_fifo, &ch) == true)
	{
		if( new_message == false)
		{
			APP_LOGD("new message");
			previous_tick_count = user_timer_1ms_get_tick();
			new_message = true;
		}
		if( (ch == '\n') | (ch == '\r'))
		{
			APP_LOGD("data read: = %s", com_rx_buffer);
			length_count = 0;
			memset( com_rx_buffer, 0x00, sizeof(com_rx_buffer));
		}
		else
		{
			if (length_count >= DATA_RX_MAX_LENGHT)
			{
				memset( com_rx_buffer, 0x00, sizeof(com_rx_buffer));
			}
			com_rx_buffer[length_count] = ch;
			length_count++;
		}
	}

	if( new_message == true)
	{
		if(user_timer_1ms_get_tick() - previous_tick_count > 200)
		{
			new_message = false;
			APP_LOGD("data read: = %s", com_rx_buffer);
			length_count = 0;
		}
	}
}
#define MESSAGE_LENGTH 7
/***********************************************************************************************************************
* Static Functions
***********************************************************************************************************************/

static void device_send_report(void)
{
	// message will send battery (volt), knock, oild pressuare, rpm
	uint8_t tmp_data[MESSAGE_LENGTH];
	uint16_t temp;
	temp = (device_state.temperature_pcb / 10)*10;
	tmp_data[0] = 0x00; // command id
	tmp_data[1] = device_state.dc_volt.dc_1_in_volt >> 8;
	tmp_data[2] = device_state.dc_volt.dc_1_in_volt & 0x00FF;

	tmp_data[3] = temp;

	tmp_data[4] = device_state.switching_state.power;
	tmp_data[5] = device_state.switching_state.heating;
	tmp_data[6] = device_state.switching_state.fan;

	lora_packet_message(tmp_data, MESSAGE_LENGTH);

}

static bool lora_packet_message(uint8_t *buf, uint8_t buf_len)
{
	bool status = false;
    uint8_t tmp_cksa = 0;
    uint8_t tmp_cksb = 0;
    uint8_t i = 0;
    uint8_t sum_data[MESSAGE_LENGTH + 5];

    sum_data[0] = HEADER_01;
    sum_data[1] = HEADER_02;
    sum_data[2] = buf_len;

    tmp_cksa += buf_len;
    tmp_cksb += tmp_cksa;

    for (i = 0; i < buf_len; i++)
    {
        sum_data[3 + i] = buf[i];
        tmp_cksa += buf[i];
        tmp_cksb += tmp_cksa;
    }

    sum_data[3 + i] = tmp_cksa;
    sum_data[4 + i] = tmp_cksb;

    user_lora_trasmit(sum_data, buf_len + 5);
	return status;
}

/***********************************************************************************************************************
* End of file
***********************************************************************************************************************/

