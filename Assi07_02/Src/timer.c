/*
 * timer.c
 *
 *  Created on: Oct 1, 2024
 *      Author: spam
 */

#include "timer.h"


void Timer_Init(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM7EN;
	TIM6->PSC = (PR - 1);
}

void Timer_Delay(uint32_t ms)
{
	uint32_t cnt = (TCLK / 1000) * ms / PR;
	TIM7->ARR = cnt - 1;
	TIM7->CNT = 0;
	TIM7->CR1 |= TIM_CR1_CEN;
	while(!(TIM7->SR & TIM_SR_UIF));
	TIM7->SR &= ~TIM_SR_UIF;
	TIM7->CR1 &= ~TIM_CR1_CEN;
}
