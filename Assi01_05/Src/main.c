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
#include "i2c.h"
#include "i2c_lcd.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	SystemInit();
	//int ret, count;
	//char str[32];
	SystemInit();
	int ret = Lcd_Init();
	if(ret)
	{
		//lcd display shift command
		while(1){
		Lcd_WriteByte(LCD_CMD, LCD_DISP_SHIFT_LEFT);
		Lcd_Puts(LCD_LINE1, "Nilanshu...!@DESD SunBeam, Pune.");
		//Lcd_Puts(LCD_LINE2, "STMElectronics STM32F407 CORTEX 5");
		DelayMs(500);
		}

		}


//		for(count = 1; count<100; count++)
//		{
//			sprintf(str, "God Bless me %d", count);
//			Lcd_Puts(LCD_LINE2, str);
//			DelayMs(500);
//		}


	return 0;
}













