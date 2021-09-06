/*
 * lora_com.h
 *
 *  Created on: Sep 6, 2021
 *      Author: Yolo
 */

#ifndef USER_DRIVER_LORA_COM_LORA_COM_H_
#define USER_DRIVER_LORA_COM_LORA_COM_H_

void lora_com_init(void);

void lora_hanlder_loop(void);

void lora_com_send_interval();

#endif /* USER_DRIVER_LORA_COM_LORA_COM_H_ */
