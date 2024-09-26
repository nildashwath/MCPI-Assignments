/*
 * uart.c
 *
 *  Created on: Sep 24, 2024
 *      Author: spam
 */

#include "uart.h"


void init_uart(uint32_t bps)
{
	//ENABLE GPIO PINS
	RCC->AHB1ENR |= (BV(GPIO_UART_CLKEN));
	GPIO_UART->MODER |= (BV((UART_TX<<1) + 1 ) | BV((UART_RX<<1) + 1));
    GPIO_UART->MODER &= ~(BV(UART_TX<<1) | BV(UART_RX<<1));
    GPIO_UART->AFR[0] |= BV(14) | BV(13) | BV(12) | BV(10) | BV(9) | BV(8);
    GPIO_UART->AFR[0] &= ~(BV(15) | BV(11));


    //ENABLE UART PINS
    RCC->APB1ENR |= (BV(UART_CLKEN));

    UART->CR1 |= (BV(USART_CR1_TE_Pos) | BV(USART_CR1_RE_Pos));
    UART->CR1 &= ~(BV(USART_CR1_M_Pos) | BV(USART_CR1_OVER8_Pos));
    UART->CR2 &= ~((USART_CR2_STOP_0) | (USART_CR2_STOP_1));
    if(bps == 9600)
    	UART->BRR = UBRR_9600;
    else if(bps == 38400)
    	UART->BRR = UBRR_38400;
    else if(bps == 115200)
    		UART->BRR = UBRR_115200;

    UART->CR1 |= (BV(USART_CR1_UE_Pos));
}


void uartputc(uint8_t ch)
{
	UART->DR = ch;
	while(!(UART->SR & BV(USART_SR_TXE_Pos)))
			;
}

uint8_t uartgetc(void)
{
    while(!((UART->SR) & BV(USART_SR_RXNE_Pos)));
    uint8_t ch = UART->DR;
    return ch;
}

void uartputs(char str[])
{
	for(int i=0; str[i]!='\0'; i++)
		uartputc((uint8_t)str[i]);
}

void uartgets(char str[])
{
	char ch;
	int i=0;
	do
	{
		ch = uartgetc();
		str[i++] = ch;
	}while(ch != '\r');
	str[i++] = '\n';
	str[i] = '\0';
}


















