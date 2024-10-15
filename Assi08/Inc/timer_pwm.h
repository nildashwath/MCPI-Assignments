/*
 * timer_pwm.h
 *
 *  Created on: Oct 2, 2024
 *      Author: spam
 */

#ifndef TIMER_PWM_H_
#define TIMER_PWM_H_

#include "stm32f4xx.h"

#define TCLK		16000000
#define PR			16
#define ARR_VAL		100

void PWM_Init(void);
#endif /* TIMER_PWM_H_ */
