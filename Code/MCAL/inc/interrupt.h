#ifndef INT_H_
#define INT_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GpioCfg.h"

typedef enum {
	LOW_LEVEL,
	HIGH_LEVEL,
	FALLINF_EDGE,
	RISING_EDGE,
}interruptLevel_t;


#define NVIC_BASEADD  0xE000E000
#define NVIC_EN0 (*(( volatile uint32 *) (NVIC_BASEADD+0x100)))
#define GPIOF_IM (*(( volatile uint32 *) (0x40025410)))
#define GPIOF_IS (*(( volatile uint32 *) (0x40025404)))
#define GPIOF_IEV (*(( volatile uint32 *) (0x4002540C))) 

	
void GPIOF_INT_init(void);
void GPIOF_enablePinInterrupt(pinNumber_t pin, interruptLevel_t level);

#endif
