/*
 * main.c

 *
 *  Created on: Oct 17, 2023
 *      Author: AhmedAbogabl
 */
//#define F_CPU 16000000UL

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/PORT/PORT.h"
//#include "HAL/SEVEN_SEGMENT.h"
#include <avr/delay.h>

#include "MCAL/EXTI/includes/EXTI_interface.h"
#include "MCAL/TIMERS/TIMER0/includes/TMR0_interface.h"
#include "HAL/KEYPAD/KP_interface.h"
#include "HAL/LCD/LCD_interface.h"
#include "MCAL/ADC/includes/ADC_interface.h"

int main() {

	Port_Init(pin_cfg);
	lcd4_Init();

	ADC_Init();
	u16 get = 0;
	//lcd4_disply_string("ADC=");
	while (1) {
		get = ADC_ReadChannel(ADC0);
		lcd4_disply_num(get);
		_delay_ms(100);
		lcd4_CLR();

	}
	return 0;
}
