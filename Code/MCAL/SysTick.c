#include "SysTick.h"

static void (*ISR)(void);

void sysTick_init(void){
	SET_BIT(SYSTICK_STCTRL,2); // Enable System clock
	SET_BIT(SYSTICK_STCTRL,1); // Enable Interrupt
	SET_BIT(SYSTICK_STCTRL,0); // Enable SysTick counter
}

void sysTick_oneSecDelay(void (*callback)(void)){
	uint32 numOfClocks = 0xF42400 ;
	SYSTICK_RELOAD = numOfClocks;
	
	ISR = callback;
}

void SysTick_Handler(void){
	ISR();
}
