#ifndef DIOTYPES_H_
#define DIOTYPES_H_


typedef enum {
    PORTA,
    PORTB,
    PORTC,
    PORTD,
    PORTE,
    PORTF
}port_t;

typedef enum {
	pin0,
	pin1,
	pin2,
	pin3,
	pin4,
	pin5,
	pin6,
	pin7
}pinNumber_t;

typedef enum {
	DioLevel_low,
	DioLevel_high
}DioLevel_t;

typedef enum {
	Dio_input,
	Dio_output
}DioDirecrtion_t;


#endif
