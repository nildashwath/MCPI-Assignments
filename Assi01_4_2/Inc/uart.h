/*
 * uart.h
 *
 *  Created on: Sep 24, 2024
 *      Author: spam
 */

#ifndef UART_H_
#define UART_H_

#include"stm32f4xx.h"

#define UART 					USART2
#define GPIO_UART				GPIOA
#define UART_TX					2
#define UART_RX					3

#define UART_CLKEN				17
#define GPIO_UART_CLKEN			0



#define UBRR_9600					0x683
#define UBRR_38400					0x1A1
#define UBRR_115200					0x8B

void init_uart(uint32_t bps);
void uartputc(uint8_t ch);
uint8_t uartgetc(void);
void uartputs(char str[]);
void uartgets(char str[]);


#endif /* UART_H_ */
