#ifndef LED_H_
#define LED_H_

#include "GpioCfg.h"


typedef struct {
	port_t port;
	pinNumber_t pin;
	DioLevel_t level;
}Led_t;

void led_init(Led_t led);

void turnOnLed(Led_t* led);

void turnOffLed(Led_t* led);

void toggleLed(Led_t* led);

#endif
