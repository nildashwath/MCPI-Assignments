/*
 * adc_header.h
 *
 *  Created on: Oct 6, 2024
 *      Author: spam
 */

#ifndef ADC_HEADER_H_
#define ADC_HEADER_H_

#include "stm32f4xx.h"

void ADC_Init(void);
uint16_t ADC_GetValue(void);



#endif /* ADC_HEADER_H_ */
