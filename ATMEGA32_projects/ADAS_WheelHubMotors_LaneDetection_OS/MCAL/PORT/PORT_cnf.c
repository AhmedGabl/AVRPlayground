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


		//LANE SENSORS
		   { Dio_PORTC, PORT_PIN0, PORT_PIN_IN },
		    { Dio_PORTC, PORT_PIN1, PORT_PIN_IN },

		//PORT A
			 { Dio_PORTA, PORT_PIN4, PORT_PIN_OUT },
			 { Dio_PORTA, PORT_PIN5, PORT_PIN_OUT },
			 { Dio_PORTA, PORT_PIN6, PORT_PIN_OUT },
//
////SPI pins
//		{Dio_PORTB ,PORT_PIN4 ,PORT_PIN_OUT},
//		{Dio_PORTB ,PORT_PIN5 ,PORT_PIN_OUT},
//		{Dio_PORTB ,PORT_PIN6 ,PORT_PIN_IN},
//		{Dio_PORTB ,PORT_PIN7 ,PORT_PIN_OUT},


//		//Alert system BUZZ and led
//		{Dio_PORTA ,PORT_PIN4 ,PORT_PIN_OUT},
//		{Dio_PORTA ,PORT_PIN5 ,PORT_PIN_OUT},
//
//		//timer1
//		{Dio_PORTD ,PORT_PIN5 ,PORT_PIN_OUT},
//		{Dio_PORTA ,PORT_PIN6 ,PORT_PIN_IN},

//				 //Lcd
//				 { Dio_PORTB, PORT_PIN3, PORT_PIN_OUT },
//				 { Dio_PORTA, PORT_PIN3, PORT_PIN_OUT },
//				 { Dio_PORTA, PORT_PIN2, PORT_PIN_OUT },
//				 { Dio_PORTB, PORT_PIN0, PORT_PIN_OUT },
//				 { Dio_PORTB, PORT_PIN1, PORT_PIN_OUT },
//				 { Dio_PORTB, PORT_PIN2, PORT_PIN_OUT },
//			//	 { Dio_PORTB, PORT_PIN3, PORT_PIN_OUT },


		//MOTOR 1 speed
					{ Dio_PORTB, PORT_PIN3, PORT_PIN_OUT },
				   { Dio_PORTB, PORT_PIN4, PORT_PIN_OUT },
				   { Dio_PORTB, PORT_PIN5, PORT_PIN_OUT },
		//MOTOR 2 steering
				   { Dio_PORTD, PORT_PIN3, PORT_PIN_OUT },
				   { Dio_PORTD, PORT_PIN4, PORT_PIN_OUT },
				   { Dio_PORTD, PORT_PIN5, PORT_PIN_OUT },

		 { -1 }
};
