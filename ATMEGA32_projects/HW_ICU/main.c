/*
 * main.c

 *
 *  Created on: Oct 17, 2023
 *      Author: AhmedAbogabl
 */
//#define F_CPU 16000000UL

#include "utils/BIT_MATH.h"
#include "utils/STD_TYPES.h"

#include "MCAL/HICU/includes/HICU_interface.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/PORT/PORT.h"
#include "MCAL/PORT/PORT_cnf.h"
#include "avr/delay.h"
#include "HAL/LCD/LCD.h"

int main() {

	u8 duty ; u16 freq;
	Port_Init(pin_cfg);

	LCD_Init();
	GI_voidEnable();

	ICU_voidInit();
	_delay_ms(20);

	ICU_voidGetDutyCycle(&duty);

	ICU_voidGetFrequency(&freq);

	LCD_PutInt(duty);
	LCD_PutString("F");
	LCD_PutInt(freq);

	while (1)
	{	_delay_ms(10);

		LCD_CLR();
		ICU_voidGetDutyCycle(&duty);

		ICU_voidGetFrequency(&freq);

		LCD_PutInt(duty);
		LCD_PutString("F");
		LCD_PutInt(freq);

	}

return 0;
}
