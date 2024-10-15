/*
 * systic.h
 *
 *  Created on: Oct 6, 2024
 *      Author: spam
 */

#ifndef SYSTIC_H_
#define SYSTIC_H_

#include "stm32f4xx.h"
extern volatile uint32_t jiffies;

void SysTick_Handler(void);
void SysTick_Delay(uint32_t ms);

#endif /* SYSTIC_H_ */
