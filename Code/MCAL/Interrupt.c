#include "interrupt.h"

void GPIOF_INT_init(void){
	 SET_BIT(NVIC_EN0, 30);
}


void GPIOF_enablePinInterrupt(pinNumber_t pin, interruptLevel_t level){
	SET_BIT(GPIOF_IM, pin);
	switch(level){
		case FALLINF_EDGE:
			CLR_BIT(GPIOF_IS, pin);
			CLR_BIT(GPIOF_IEV, pin);
			break;
		case RISING_EDGE:
			CLR_BIT(GPIOF_IS, pin);
			SET_BIT(GPIOF_IEV, pin);
			break;
		case LOW_LEVEL:
			SET_BIT(GPIOF_IS, pin);
			CLR_BIT(GPIOF_IEV, pin);
			break;
		case HIGH_LEVEL:
			SET_BIT(GPIOF_IS, pin);
			SET_BIT(GPIOF_IEV, pin);
			break;
	}
}
