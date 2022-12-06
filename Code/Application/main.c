#include "led.h"
#include "SysTick.h"
#include "button.h"


typedef enum{
	RUNNING,
	set_onTime,
	set_offTime,
}AppState_t;

void ledControl(void);

static Led_t led = {PORTF, pin1, DioLevel_low};
static button_t button_1 = {PORTF, pin4};
static button_t button_2 = {PORTF, pin0};
static AppState_t appState;
static uint8 ONTIME_SETTING = 0;
static uint8 OFFTIME_SITTING = 0;
static uint8 onTime;
static uint8 offTime;



int main ( void )
{
	
	port_init(led.port);
	led_init(led);
	button_init(button_1);
	button_init(button_2);
	
	GPIOF_INT_init();
	buttonEnableInterrupt(button_1, RISING_EDGE);
	buttonEnableInterrupt(button_2, RISING_EDGE);
	
	sysTick_init();
	

	
	while(1){
		
	}
	
}


void GPIOF_Handler(void){
	if(GPIO_PORTF_MIS & 0x10){
		switch(appState){
			case set_onTime:
				appState = set_offTime;
				onTime = ONTIME_SETTING;
				OFFTIME_SITTING = 0;
				break;
			case set_offTime:
				appState = RUNNING;
				offTime = OFFTIME_SITTING;
				turnOnLed(&led);
				sysTick_oneSecDelay(ledControl);
				break;
			case RUNNING:
				appState = set_onTime;
				turnOffLed(&led);
				ONTIME_SETTING = 0;
				break;
			default:
				appState = set_onTime;
		}
		buttonClearInterrupt(button_1);
	}else if(GPIO_PORTF_MIS & 0x01){
		if(appState == set_onTime){
			ONTIME_SETTING++;
		}else if (appState == set_offTime){
			OFFTIME_SITTING++;
		}
		buttonClearInterrupt(button_2);
	}
}


void ledControl(void){
	if(appState == RUNNING){
		switch(led.level){
			case DioLevel_high:
				if(onTime > 1){
					sysTick_oneSecDelay(ledControl);
					onTime--;
				}else if(onTime == 1){
					toggleLed(&led);
					onTime = ONTIME_SETTING;
					sysTick_oneSecDelay(ledControl);
				}
				break;
			case DioLevel_low:
				if(offTime > 1){
					sysTick_oneSecDelay(ledControl);
					offTime--;
				}else if(offTime == 1){
					toggleLed(&led);
					offTime = OFFTIME_SITTING;
					sysTick_oneSecDelay(ledControl);
				}
				break;
		}
	}
}
