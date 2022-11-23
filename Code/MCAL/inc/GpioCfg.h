#ifndef GPIOCFG_H_
#define GPIOCFG_H_

#include "GpioTypes.h"
#include "../../Common/STD_TYPES.h"
#include "../../Common/BIT_MATH.h"


#define SYSCTL_RCGCGPIO (*(( volatile uint32 *)0x400FE608 ) )
	
#define GPIO_PORTA_DATA (*(( volatile uint32 *)0x400043FC ) ) 
#define GPIO_PORTA_DIR  (*(( volatile uint32 *)0x40004400 ) ) 
#define GPIO_PORTA_DEN  (*(( volatile uint32 *)0x4000451C ) )
	
#define GPIO_PORTB_DATA (*(( volatile uint32 *)0x400053FC ) ) 
#define GPIO_PORTB_DIR  (*(( volatile uint32 *)0x40005400 ) ) 
#define GPIO_PORTB_DEN  (*(( volatile uint32 *)0x4000551C ) )
	
#define GPIO_PORTC_DATA (*(( volatile uint32 *)0x400063FC ) ) 
#define GPIO_PORTC_DIR  (*(( volatile uint32 *)0x40006400 ) ) 
#define GPIO_PORTC_DEN  (*(( volatile uint32 *)0x4000651C ) )
	
#define GPIO_PORTD_DATA (*(( volatile uint32 *)0x400073FC ) ) 
#define GPIO_PORTD_DIR  (*(( volatile uint32 *)0x40007400 ) ) 
#define GPIO_PORTD_DEN  (*(( volatile uint32 *)0x4000751C ) )
	
#define GPIO_PORTE_DATA (*(( volatile uint32 *)0x400243FC ) ) 
#define GPIO_PORTE_DIR  (*(( volatile uint32 *)0x40024400 ) ) 
#define GPIO_PORTE_DEN  (*(( volatile uint32 *)0x4002451C ) )
	
#define GPIO_PORTF_DATA (*(( volatile uint32 *)0x400253FC ) ) 
#define GPIO_PORTF_DIR  (*(( volatile uint32 *)0x40025400 ) ) 
#define GPIO_PORTF_DEN  (*(( volatile uint32 *)0x4002551C ) )
	

void port_init(port_t port);

void setPinAsDigital(port_t port, pinNumber_t pin);

void setPinDirection(port_t port, pinNumber_t pin, DioDirecrtion_t direction);

void Dio_Write(port_t port, pinNumber_t pin, DioLevel_t level);


void Dio_toogle(port_t port, pinNumber_t pin);

#endif
