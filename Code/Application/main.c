#include "led.h"
#include "SysTick.h"

#define ON_TIME 5
#define OFF_TIME 3

void ledControl(void);
static Led_t led = {PORTF, pin0, DioLevel_low};
static int onTime = ON_TIME;
static int offTime = OFF_TIME;
int main ( void )
{
	
	port_init(led.port);
	led_init(led);
	
	sysTick_init();
	
  toggleLed(&led);	
  
	sysTick_oneSecDelay(ledControl);
	
	while(1){
		
	}
	
}

void ledControl(void){
	switch(led.level){
		case DioLevel_high:
			if(onTime > 1){
				sysTick_oneSecDelay(ledControl);
				onTime--;
			}else if(onTime == 1){
				toggleLed(&led);
				onTime = ON_TIME;
				sysTick_oneSecDelay(ledControl);
			}
			break;
		case DioLevel_low:
			if(offTime > 1){
				sysTick_oneSecDelay(ledControl);
				offTime--;
			}else if(offTime == 1){
				toggleLed(&led);
				offTime = OFF_TIME;
				sysTick_oneSecDelay(ledControl);
			}
			break;
	}
}
