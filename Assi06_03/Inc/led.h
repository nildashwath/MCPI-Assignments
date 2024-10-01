/*
 * led.h
 *
 *  Created on: Sep 19, 2024
 *      Author: spam
 */

#ifndef LED_H_
#define LED_H_

#include"stm32f4xx.h"
//green, orange, red, yellow
#define GPIO_LED GPIOD

#define LED_GREEN_PIN 12
#define LED_ORANGE_PIN 13
#define LED_RED_PIN 14
#define LED_BLUE_PIN 15

#define GPIO_LED_AHBENR 3

void led_init(uint32_t pin);
void led_on(uint32_t pin);
void led_off(uint32_t pin);
void ledblink(uint32_t pin1,uint32_t delay);
void remaining_off(uint16_t pin1, uint16_t pin2, uint16_t pin3);





#endif /* LED_H_ */
