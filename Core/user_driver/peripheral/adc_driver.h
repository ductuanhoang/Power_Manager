#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

 #include "stm32l0xx_hal.h"
//#include "stm32f4xx_hal.h"
#include "stdint.h"
#include "string.h"
#include "main.h"

#define ADC_SAMPLE_COUNT            (4)
#define ADC_CHANNEL_COUNT           (5)//(8)

// #define PRESSURE_PROXIMAL_IDX       (0)
// #define PRESSURE_INTERNAL_IDX       (1)
// #define PRESSURE_VALVE_IDX          (2)
// #define FLOW_INHALE_IDX             (3)
// #define FLOW_EXHALE_IDX             (4)

#define ADC_VREF_MV                 3282
#define ADC_SCALE                   1.47f
#define ADC_RESOLUTION              4095
#define ADC_SCALE_FLOW              2



void adc_start_process(void);

uint16_t* adc_get_sample(void);

void adc_init(void);
uint16_t adc_read_func(void);
#endif /* ADC_DRIVER_H_ */
