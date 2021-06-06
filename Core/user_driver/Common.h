/*
 *
 *  Created on: Sep 22, 2019
 *      Author: ADMIN94
 */

#ifndef COMMON_H_
#define COMMON_H_
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "stm32l0xx_hal.h"
//#include "stm32f4xx_hal.h"
/* Console color */
#define kRESET "\x1B[0m"
#define kKRED "\x1B[31m"
#define kKGRN "\x1B[32m"
#define kKYEL "\x1B[33m"
#define kKBLU "\x1B[34m"
#define kKMAG "\x1B[35m"
#define kKCYN "\x1B[36m"
#define KWHT "\x1B[37m"

#define APP_DEBUG printf

enum
{
	E_LOG_LVL_NONE,
	E_LOG_LVL_ERROR,
	E_LOG_LVL_INFO,
	E_LOG_LVL_DEBUG,
	E_LOG_LVL_NEVER
};

#define LOG_SHOULD_I(level) (level <= LOG_BUILD_LEVEL && level <= E_LOG_LVL_DEBUG)
#define LOG(level, tag, fmt, ...)                                                                \
	do                                                                                           \
	{                                                                                            \
		if (LOG_SHOULD_I(level))                                                                 \
		{                                                                                        \
			printf("[%s] %s:%d: " fmt "\r\n" RESET, tag, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
		}                                                                                        \
	} while (0)

#define APP_LOGE(format, ...) LOG(E_LOG_LVL_ERROR, kKRED "ERROR" RESET, format, ##__VA_ARGS__)
#define APP_LOGI(format, ...) LOG(E_LOG_LVL_INFO, kKGRN "INFO" RESET, format, ##__VA_ARGS__)
#define APP_LOGD(format, ...) LOG(E_LOG_LVL_DEBUG, kKYEL "DEBUG" RESET, format, ##__VA_ARGS__)

#define LOG_BUILD_LEVEL E_LOG_LVL_DEBUG
//#define LOG_BUILD_LEVEL			E_LOG_LVL_NONE

typedef enum
{
	E_DURATION, //(1, 2,4,5min)
	E_INTERVAL  //(1, 5,10,15,20,30,60min)
} e_rotation_type;

typedef enum
{
	E_NORMAL_MODE,
	E_SAVE_MODE
} e_mode;

typedef enum
{
	E_OFF,
	E_ON
} e_state;
typedef struct
{
	e_state power;
	e_state heating;
	e_state fan;
} switching_state_t;

typedef struct
{
	uint32_t time_duration;
	uint32_t time_interval;
} time_setting_t;

typedef struct
{
	uint16_t dc_1_in_volt;
	uint16_t dc_1_out_volt;
	uint16_t dc_2_out_volt;
	uint16_t dc_3_out_volt;
	uint16_t bat_volt;
} dc_volt_t;

typedef struct
{
	uint16_t temprature;
	dc_volt_t dc_volt;
	e_rotation_type rotation_type;
	e_mode mode;
	switching_state_t switching_state;
	time_setting_t time;
} device_state_t;


extern device_state_t device_state;
extern uint32_t user_timer_1ms_get_tick(void);
extern uint32_t user_timer_1s_get_tick(void);
#endif /* COMMON_H_ */
