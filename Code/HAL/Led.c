#include "inc/led.h"


void led_init(Led_t led){
	setPinAsDigital(led.port, led.pin);
	setPinDirection(led.port, led.pin, Dio_output);
}

void turnOnLed(Led_t* led){
	Dio_Write(led->port, led->pin, DioLevel_high);
	led->level = DioLevel_high;
}

void turnOffLed(Led_t* led){
	Dio_Write(led->port, led->pin, DioLevel_low);
	led->level = DioLevel_low;
}

void toggleLed(Led_t* led){
	Dio_toogle(led->port, led->pin);
	led->level = (led->level == DioLevel_low) ? DioLevel_high : DioLevel_low;
}
