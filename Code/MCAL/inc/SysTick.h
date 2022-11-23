#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#define SYSTICK_BASEADD 0xE000E000
#define SYSTICK_STCTRL (*(( volatile uint32 *) (SYSTICK_BASEADD+0x010)))
#define SYSTICK_RELOAD (*(( volatile uint32 *) (SYSTICK_BASEADD+0x014)))
#define SYSTICK_CURRENT (*(( volatile uint32 *) (SYSTICK_BASEADD+0x018)))
	
void sysTick_init(void);

void sysTick_oneSecDelay(void (*callback)(void));

void SysTick_Handler(void);

#endif
