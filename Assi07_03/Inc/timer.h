/*
Author: Nilesh Ghule <nilesh@sunbeaminfo.com>
Course: PG-DESD @ Sunbeam Infotech
Date: Sep 30, 2024
*/

#ifndef TIMER_H_
#define TIMER_H_
#include<string.h>
#include "stm32f4xx.h"

#define TCLK	16000000UL
#define PR		16000
extern volatile int switch_flag;
extern int count;
void Timer_Init(uint32_t ms);
void TIM6_DAC_IRQHandler(void);


#endif /* TIMER_H_ */
