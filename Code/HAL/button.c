#include "button.h"


void button_init(button_t button){
	setPinAsDigital(button.port, button.pin);
	selectPullUp(button.port, button.pin);
	setPinDirection(button.port, button.pin, Dio_input);
}

void buttonEnableInterrupt(button_t button, interruptLevel_t level){
	GPIOF_enablePinInterrupt(button.pin, level);
}

void buttonClearInterrupt(button_t button){
	SET_BIT(GPIO_PORTF_IC, button.pin);
}

