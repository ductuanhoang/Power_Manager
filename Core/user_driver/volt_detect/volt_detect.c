/*
 * volt_detect.c
 *
 *  Created on: Sep 6, 2021
 *      Author: Yolo
 */
#include "volt_detect.h"
#include "adc_driver.h"


#define kVCC                            (3300) //(mini Volt)
#define kADC_SENSOR_SCALE               (1.0f * kVCC /4095.0f)
/* ADC_VCHG_IN measure
 DC1_IN+
  |
 [ ] R_CONST_01
  |
  --------- v_measure
  |
 [ ] R_CONST_02
  |
 GND
*/
#define kVDC1_IN_R_CONST_01    100 // kOmh
#define kVDC1_IN_R_CONST_02    10 // kOmh

uint16_t DC1_In_Volt(void)
{
	float dc1_value = 0;
	uint16_t u16DC1 = 0;
	dc1_value = (adc_get_sample()[0] * kADC_SENSOR_SCALE) * ((kVDC1_IN_R_CONST_01+kVDC1_IN_R_CONST_02) / kVDC1_IN_R_CONST_02);
	u16DC1 = (dc1_value / 10)*10;
	return u16DC1;
}
