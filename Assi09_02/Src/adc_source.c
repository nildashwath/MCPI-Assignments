/*
 * adc_source.c
 *
 *  Created on: Oct 6, 2024
 *      Author: spam
 */

#include "adc_header.h"

void ADC_Init(void)
{
	//GPIO CONFIGURATION
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= BV(0*2) | BV(0*2+1);

	//CONFIGURATION FOR ADC PINS
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	ADC1->CR1 &= ~(ADC_CR1_RES_0 | ADC_CR1_RES_1);
	ADC1->CR2 &= ~ADC_CR2_ADON;
	ADC1->SQR1 |= (0 << ADC_SQR1_L_Pos);
	ADC1->SQR3 |= (0 << ADC_SQR3_SQ1_Pos);
	ADC1->CR2 |= ADC_CR2_ADON;
}

uint16_t ADC_GetValue(void)
{
	ADC1->CR2 |= ADC_CR2_SWSTART;
	while(!(ADC1->SR & ADC_SR_EOC));

	uint16_t val = ADC1->DR;
	return val;
}

