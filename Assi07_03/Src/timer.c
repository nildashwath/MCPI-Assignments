/*
Author: Nilesh Ghule <nilesh@sunbeaminfo.com>
Course: PG-DESD @ Sunbeam Infotech
Date: Sep 30, 2024
*/

#include<stdio.h>
#include "timer.h"
#include "led.h"
#include "i2c_lcd.h"

int count = 0;
volatile int switch_flag = 0;
char str[100] = "\0";
#include "timer.h"
#include "led.h"

void Timer_Init(uint32_t ms) {
	//* Enable Timer APB clock
	RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;
	//* Set Timer clock -- PCLK = TCLK = 16 MHz : * Set PR = 16000
	TIM6->PSC = (PR-1);
	//* Calculate number of clocks to count (CNT).
	uint32_t cnt = (TCLK / 1000) * (ms / PR);
	//* Set CNT in ARR.
	TIM6->ARR = (cnt-1);
	//* Reset Timer Counter to 0.
	TIM6->CNT = 0;
	//* Enable Timer Interrupt in DIER.
	TIM6->DIER |= TIM_DIER_UIE;
	//* Enable Timer Interrupt in NVIC.
	NVIC_EnableIRQ(TIM6_DAC_IRQn);
	//* Start Timer in CR1.
	TIM6->CR1 |= TIM_CR1_CEN;

}

void TIM6_DAC_IRQHandler(void) {
	//* Check if UIF flag is set (in SR).
	if(TIM6->SR & TIM_SR_UIF) {
		Lcd_WriteByte(LCD_CMD, LCD_CLEAR);
		DelayMs(100);
		//* Clear UIF in SR (Ack)
		TIM6->SR &= ~TIM_SR_UIF;
		LedToggle(LED_BLUE_PIN);
		count++;
		sprintf(str, "count: %d", count);
		Lcd_Puts(LCD_LINE1, str);
}
}
