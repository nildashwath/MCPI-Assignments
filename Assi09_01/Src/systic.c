/*
 * systic.c
 *
 *  Created on: Oct 6, 2024
 *      Author: spam
 */

#include "systic.h"


volatile uint32_t jiffies = 0;
void SysTick_Handler(void) {
	jiffies++;
}

void SysTick_Delay(uint32_t ms)
{
	uint32_t unit = jiffies + ms;
	while(jiffies < unit)
	;
}
