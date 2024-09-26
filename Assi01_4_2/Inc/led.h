/*
 * led.h
 *
 *  Created on: Sep 24, 2024
 *      Author: spam
 */

#include<stdio.h>
#include"stm32f4xx.h"

#ifndef LED_H_
#define LED_H_

#define GPIO_LED 			GPIOD
#define LED_RED_PIN     	14
#define LED_BLUE_PIN		15

#define GPIOD_CCLKEN		3

void led_init(uint32_t pin);
void led_on(uint32_t pin);
void led_off(uint32_t pin);

#endif /* LED_H_ */
