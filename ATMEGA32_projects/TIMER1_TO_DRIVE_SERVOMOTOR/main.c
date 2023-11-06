/*
 * main.c

 *
 *  Created on: Oct 17, 2023
 *      Author: AhmedAbogabl
 */
//#define F_CPU 16000000UL

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/PORT/PORT.h"
#include <avr/delay.h>
#include "MCAL/TIMERS/TIMER1/includes/TMR1_interface.h"


int main(){
	Port_Init(pin_cfg);
	u8 angle=0;
	while(1){
		angle+=10;
		SRVM_voidOn(angle);
		if(angle==180)angle=0;
		_delay_ms(100);
	}
	return 0;
}
