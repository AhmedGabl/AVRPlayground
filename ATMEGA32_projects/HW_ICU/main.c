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


int main() {

	u8 duty ; u16 freq;
	Port_Init(pin_cfg);

	GI_voidEnable();
	Lcd_Init();
	ICU_voidInit();

	ICU_voidGetDutyCycle(&duty);
	//Lcd_Clear();
	//Lcd_PutString("Back from duty ");
	ICU_voidGetFrequency(&freq);

	//Lcd_Clear();
//	Lcd_PutInt(duty);
	//Lcd_PutChar("-");
	//Lcd_PutInt(freq);
	while (1)
	{

	}

return 0;
}