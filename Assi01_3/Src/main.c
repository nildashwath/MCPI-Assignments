#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "switch_intr.h"
#include "led.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


int main(void) {
	int i=0;
	SystemInit();
	SwitchInit();
	LedInit(LED_ORANGE_PIN);
	LedInit(LED_GREEN_PIN);
	LedInit(LED_RED_PIN);
	LedInit(LED_BLUE_PIN);

	while(1) {

		while(SwitchExtiFlag == 0);

		LedBlink(LED_GREEN_PIN+i, 2000);
		SwitchExtiFlag = 0;
		i>4 ? i=0: i++;
	}
	return 0;
}
