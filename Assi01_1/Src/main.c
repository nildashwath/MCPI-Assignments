#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#define LED_PIN 13
#define BV(x) (1 << (x))  // Bit value macro for easy bit manipulation

// Delay function (assuming you have a working delay function)
void DelayMs(uint32_t ms);

int main(void) {
	SystemInit();
	// Enable GPIOD clock -- RCC AHB1ENR[3] = 1
	RCC->AHB1ENR |= BV(3);

	// Configure GPIOD.13 as output -- MODER[27:26] = 01
	GPIOD->MODER &= ~BV(27);
	GPIOD->MODER |= BV(26);

	// Configure GPIOD.13 as push-pull -- OTYPER[13] = 0
	GPIOD->OTYPER &= ~BV(13);

	// Configure GPIOD.13 as low-speed -- OSPEEDR[27:26] = 00
	GPIOD->OSPEEDR &= ~(BV(27) | BV(26));

	// Configure GPIOD.13 with no pull-up/pull-down resistors -- PUPDR[27:26] = 00
	GPIOD->PUPDR &= ~(BV(27) | BV(26));

	while (1) {
		// Turn LED ON by setting GPIOD.13 -- BSRR[13] = 1
		GPIOD->BSRR = BV(13);  // Sets the pin to HIGH (LED ON)
		DelayMs(500);  // Delay for 500ms

		// Turn LED OFF by resetting GPIOD.13 -- BSRR[29] = 1
		GPIOD->BSRR = BV(13 + 16);  // Resets the pin to LOW (LED OFF)
		DelayMs(500);  // Delay for 500ms
	}

	return 0;
}
