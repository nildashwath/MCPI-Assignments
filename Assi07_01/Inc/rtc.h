/*
 * rtc.h
 *
 *  Created on: Sep 30, 2024
 *      Author: spam
 */

#ifndef RTC_H_
#define RTC_H_

#include "stm32f4xx.h"

typedef struct {
	uint8_t Date, Month, year, weakday;
} RTC_Date;

typedef struct {
	uint8_t Hour, minute, second, milisecond;
} RTC_Time;

void RTC_Init(RTC_Date *dr, RTC_Time *tm);
void RTC_SetDate(RTC_Date *dt);
void RTC_SetTime(RTC_Time *dm);
void RTC_GetDate(RTC_Date *dt);
void RTC_GetTime(RTC_Time *tm);






#endif /* RTC_H_ */
