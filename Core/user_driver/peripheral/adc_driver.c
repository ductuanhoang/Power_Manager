#include "adc_driver.h"
#include <stdlib.h> /* atoi */
#include "stm32l0xx_hal_adc.h"
/***********************************************************************************************************************
* static  Varible
***********************************************************************************************************************/

/***********************************************************************************************************************
* Public Functions
***********************************************************************************************************************/
volatile uint16_t adc_value[ADC_CHANNEL_COUNT];
volatile uint16_t adc_buffer_sample[ADC_CHANNEL_COUNT * ADC_SAMPLE_COUNT];

extern ADC_HandleTypeDef hadc;
extern TIM_HandleTypeDef htim3;


#define TIMER_TRIGGER               htim3
/***********************************************************************************************************************
* public Functions
***********************************************************************************************************************/

void adc_init(void)
{
//	HAL_ADC_Start_IT(&hadc);
	adc_start_process();
}

uint16_t adc_read = 0;
uint16_t adc_read_func(void)
{
	return adc_value[0];
}

//void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
//{
//	if( hadc->Instance == hadc1.Instance)
//	{
//		adc_read = HAL_ADC_GetValue(&hadc1);
//	}
//}

/***********************************************************************************************************************
* Function Name:  vsm_protocol_cmd_handler
* Description  :
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
    uint16_t i = 0, j = 0;
    uint32_t sumTmp = 0;
    HAL_TIM_Base_Stop(&TIMER_TRIGGER);
//    for(j = 0; j < ADC_CHANNEL_COUNT; j++) {
//        sumTmp = 0;
//        for(i = 0; i < ADC_SAMPLE_COUNT; i++)
//        {
//            sumTmp += adc_buffer_sample[i * ADC_CHANNEL_COUNT + j]; // 0 3 6 9 12
//        }
//        adc_value[j] = sumTmp / ADC_SAMPLE_COUNT;
//    }
    for (int i = 0; i < ADC_CHANNEL_COUNT; i++)
    {
    	adc_value[i] = adc_buffer_sample[i];
	}
//    HAL_TIM_Base_Start(&TIMER_TRIGGER);
    adc_start_process();
}
/***********************************************************************************************************************
* Function Name:  vsm_protocol_cmd_handler
* Description  :
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void adc_start_process(void)
{
    HAL_ADC_Start_DMA(&hadc, (uint32_t*)&adc_buffer_sample, ADC_CHANNEL_COUNT * ADC_SAMPLE_COUNT);
    HAL_TIM_Base_Start(&TIMER_TRIGGER);
}
/***********************************************************************************************************************
* Function Name:  vsm_protocol_cmd_handler
* Description  :
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
uint16_t* adc_get_sample(void)
{
    return (uint16_t*)adc_value;
}



/***********************************************************************************************************************
* Static Functions
***********************************************************************************************************************/

/***********************************************************************************************************************
* End of file
***********************************************************************************************************************/
