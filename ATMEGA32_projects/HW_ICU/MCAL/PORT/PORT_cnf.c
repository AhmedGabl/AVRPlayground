/*
 * PORT_cnf.c
 *
 *  Created on: Oct 20, 2023
 *      Author: AhmedAbogabl
 */

#include "PORT_cnf.h"

/*
 * a structure contains all mcu port configurations 1)port# 2) pin#  3)Direction (in or out)
 *                   {Dio_PORTB ,PORT_PIN0 ,PORT_PIN_OUT},
 */

Port_ConfigType pin_cfg[33] = {

		 //Lcd
		 { Dio_PORTB, PORT_PIN4, PORT_PIN_OUT },
		 { Dio_PORTA, PORT_PIN3, PORT_PIN_OUT },
		 { Dio_PORTA, PORT_PIN2, PORT_PIN_OUT },
		 { Dio_PORTB, PORT_PIN0, PORT_PIN_OUT },
		 { Dio_PORTB, PORT_PIN1, PORT_PIN_OUT },
		 { Dio_PORTB, PORT_PIN2, PORT_PIN_OUT },
	//	 { Dio_PORTB, PORT_PIN3, PORT_PIN_OUT },
		{Dio_PORTD , PORT_PIN6,PORT_PIN_IN},
		 { -1 }
};

////PORTA
//{Dio_PORTA ,PORT_PIN0 ,PORT_PIN_IN},
//{Dio_PORTA ,PORT_PIN1 ,PORT_PIN_IN},
//{Dio_PORTA ,PORT_PIN2 ,PORT_PIN_IN},
//{Dio_PORTA ,PORT_PIN3 ,PORT_PIN_IN},
//{Dio_PORTA ,PORT_PIN4 ,PORT_PIN_IN},
//{Dio_PORTA ,PORT_PIN5 ,PORT_PIN_IN},
//{Dio_PORTA ,PORT_PIN6 ,PORT_PIN_IN},
//{Dio_PORTA ,PORT_PIN7 ,PORT_PIN_IN},
//
////PORTB
//{Dio_PORTB ,PORT_PIN0 ,PORT_PIN_IN},
//{Dio_PORTB ,PORT_PIN1 ,PORT_PIN_IN},
//{Dio_PORTB ,PORT_PIN2 ,PORT_PIN_IN},
//{Dio_PORTB ,PORT_PIN3 ,PORT_PIN_IN},
//{Dio_PORTB ,PORT_PIN4 ,PORT_PIN_IN},
//{Dio_PORTB ,PORT_PIN5 ,PORT_PIN_IN},
//{Dio_PORTB ,PORT_PIN6 ,PORT_PIN_IN},
//{Dio_PORTB ,PORT_PIN7 ,PORT_PIN_IN},
//
////PORTC
//{Dio_PORTC ,PORT_PIN0 ,PORT_PIN_IN},
//{Dio_PORTC ,PORT_PIN1 ,PORT_PIN_IN},
//{Dio_PORTC ,PORT_PIN2 ,PORT_PIN_IN},
//{Dio_PORTC ,PORT_PIN3 ,PORT_PIN_IN},
//{Dio_PORTC ,PORT_PIN4 ,PORT_PIN_IN},
//{Dio_PORTC ,PORT_PIN5 ,PORT_PIN_IN},
//{Dio_PORTC ,PORT_PIN6 ,PORT_PIN_IN},
//{Dio_PORTC ,PORT_PIN7 ,PORT_PIN_IN},
////PORTD
//{Dio_PORTD ,PORT_PIN0 ,PORT_PIN_IN},
//{Dio_PORTD ,PORT_PIN1 ,PORT_PIN_IN},
//{Dio_PORTD ,PORT_PIN2 ,PORT_PIN_IN},
//{Dio_PORTD ,PORT_PIN3 ,PORT_PIN_IN},
//{Dio_PORTD ,PORT_PIN4 ,PORT_PIN_IN},
//{Dio_PORTD ,PORT_PIN5 ,PORT_PIN_IN},
//{Dio_PORTD ,PORT_PIN6 ,PORT_PIN_IN},
//{Dio_PORTD ,PORT_PIN7 ,PORT_PIN_IN},
