/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "timer_pwm.h"
#include "switch_inter.h"



#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void) {
	SystemInit();
	int16_t ccr = 0;
	SwitchInit();
	PWM_Init();
	while(1)
	{
		while(switch_flag == 0)
			;
		DelayMs(300);
			TIM8->CCR1 = ccr;
			ccr+=10;
			switch_flag = 0;
			if(ccr > 100)
			{
				while(ccr >0)
				{
					while(switch_flag == 0)
						;
					DelayMs(300);
					TIM8->CCR1 = ccr;
					ccr-=10;
					switch_flag = 0;
				}
			}

}
    return 0;
}
