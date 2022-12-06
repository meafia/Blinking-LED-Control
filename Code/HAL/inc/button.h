#ifndef BUTTON_H_
#define BUTTON_H_

#include "GpioCfg.h"
#include "interrupt.h"

typedef struct {
	port_t port;
	pinNumber_t pin;
}button_t;

void button_init(button_t button);
void buttonEnableInterrupt(button_t button, interruptLevel_t level);
void buttonClearInterrupt(button_t button);


#endif
