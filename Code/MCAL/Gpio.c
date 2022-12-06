#include "inc/GpioCfg.h"



void port_init(port_t port){
	
	
	switch (port)
    {
    case PORTA:
				SET_BIT(SYSCTL_RCGCGPIO,0);
        break;
		case PORTB:
				SET_BIT(SYSCTL_RCGCGPIO,1);
        break;
		case PORTC:
				SET_BIT(SYSCTL_RCGCGPIO,2);
        break;
		case PORTD:
				SET_BIT(SYSCTL_RCGCGPIO,3);
        break;
		case PORTE:
				SET_BIT(SYSCTL_RCGCGPIO,4);
        break;
		case PORTF:
        SET_BIT(SYSCTL_RCGCGPIO,5);
        break;
    }
}



void setPinAsDigital(port_t port, pinNumber_t pin){
		switch (port)
    {
    case PORTA:
				SET_BIT(GPIO_PORTA_DEN,pin);
        break;
		case PORTB:
				SET_BIT(GPIO_PORTB_DEN,pin);
        break;
		case PORTC:
				SET_BIT(GPIO_PORTC_DEN,pin);
        break;
		case PORTD:
				SET_BIT(GPIO_PORTD_DEN,pin);
        break;
		case PORTE:
				SET_BIT(GPIO_PORTE_DEN,pin);
        break;
		case PORTF:
        SET_BIT(GPIO_PORTF_DEN,pin);
        break;
    }
}

void selectPullUp(port_t port, pinNumber_t pin){
	switch (port)
    {
    case PORTA:
				SET_BIT(GPIO_PORTA_PUR, pin);
        break;
		case PORTB:
				SET_BIT(GPIO_PORTB_PUR, pin);
        break;
		case PORTC:
				SET_BIT(GPIO_PORTC_PUR, pin);
        break;
		case PORTD:
				SET_BIT(GPIO_PORTD_PUR, pin);
        break;
		case PORTE:
				SET_BIT(GPIO_PORTE_PUR, pin);
        break;
		case PORTF:
        SET_BIT(GPIO_PORTF_PUR, pin);
        break;
    }
}


void setPinDirection(port_t port, pinNumber_t pin, DioDirecrtion_t direction){
	if(direction == Dio_input){
		switch (port)
    {
    case PORTA:
				CLR_BIT(GPIO_PORTA_DIR,pin);
        break;
		case PORTB:
				CLR_BIT(GPIO_PORTB_DIR,pin);
        break;
		case PORTC:
				CLR_BIT(GPIO_PORTC_DIR,pin);
        break;
		case PORTD:
				CLR_BIT(GPIO_PORTD_DIR,pin);
        break;
		case PORTE:
				CLR_BIT(GPIO_PORTE_DIR,pin);
        break;
		case PORTF:
        CLR_BIT(GPIO_PORTF_DIR,pin);
        break;
    }
	}
	else if(direction == Dio_output){
		switch (port)
    {
    case PORTA:
				SET_BIT(GPIO_PORTA_DIR,pin);
        break;
		case PORTB:
				SET_BIT(GPIO_PORTB_DIR,pin);
        break;
		case PORTC:
				SET_BIT(GPIO_PORTC_DIR,pin);
        break;
		case PORTD:
				SET_BIT(GPIO_PORTD_DIR,pin);
        break;
		case PORTE:
				SET_BIT(GPIO_PORTE_DIR,pin);
        break;
		case PORTF:
        SET_BIT(GPIO_PORTF_DIR,pin);
        break;
    }
	}
}

void Dio_Write(port_t port, pinNumber_t pin, DioLevel_t level){
	if(level == DioLevel_low){
		switch (port)
    {
    case PORTA:
				CLR_BIT(GPIO_PORTA_DATA,pin);
        break;
		case PORTB:
				CLR_BIT(GPIO_PORTB_DATA,pin);
        break;
		case PORTC:
				CLR_BIT(GPIO_PORTC_DATA,pin);
        break;
		case PORTD:
				CLR_BIT(GPIO_PORTD_DATA,pin);
        break;
		case PORTE:
				CLR_BIT(GPIO_PORTE_DATA,pin);
        break;
		case PORTF:
        CLR_BIT(GPIO_PORTF_DATA,pin);
        break;
    }
	}
	else if(level == DioLevel_high){
		switch (port)
    {
    case PORTA:
				SET_BIT(GPIO_PORTA_DATA,pin);
        break;
		case PORTB:
				SET_BIT(GPIO_PORTB_DATA,pin);
        break;
		case PORTC:
				SET_BIT(GPIO_PORTC_DATA,pin);
        break;
		case PORTD:
				SET_BIT(GPIO_PORTD_DATA,pin);
        break;
		case PORTE:
				SET_BIT(GPIO_PORTE_DATA,pin);
        break;
		case PORTF:
        SET_BIT(GPIO_PORTF_DATA,pin);
        break;
    }
	}
}

void Dio_toogle(port_t port, pinNumber_t pin){
	switch (port)
    {
    case PORTA:
				TOGGLE_BIT(GPIO_PORTA_DATA,pin);
        break;
		case PORTB:
				TOGGLE_BIT(GPIO_PORTB_DATA,pin);
        break;
		case PORTC:
				TOGGLE_BIT(GPIO_PORTC_DATA,pin);
        break;
		case PORTD:
				TOGGLE_BIT(GPIO_PORTD_DATA,pin);
        break;
		case PORTE:
				TOGGLE_BIT(GPIO_PORTE_DATA,pin);
        break;
		case PORTF:
        TOGGLE_BIT(GPIO_PORTF_DATA,pin);
        break;
    }
}
