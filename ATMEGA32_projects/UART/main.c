/*
 * main.c

 *
 *  Created on: Oct 17, 2023
 *      Author: AhmedAbogabl
 */
//#define F_CPU 16000000UL
#include <avr/io.h>
//#include "utils/STD_TYPES.h"
//#include "utils/BIT_MATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/PORT/PORT.h"
//#include "HAL/SEVEN_SEGMENT.h"
#include <avr/delay.h>

#include "MCAL/UART/includes/UART_interface.h"

//#include "HAL/LCD/LCD_interface.h"
#include "MCAL/EXTI/includes/EXTI_interface.h"
#include "MCAL/TIMERS/TIMER0/includes/TMR0_interface.h"

void LED (u8 data){
    UART_Send(data);
}
u8 intdata=0;
int main() {
	Port_Init(pin_cfg);
	GI_voidEnable();
	 // Initialize UART with baud rate 9600
	    UART_Init();

	    // Send a character 'A'
	    UART_Send('A');

	    // Receive and store the received character
	    u8 receivedData = UART_Receive();

	    // Check the received character
	    if (receivedData == 'A')
//	        // If 'A' was received, send a 'B'
	        UART_Send('B');


	    UART_RX_InterruptEnable();
	    UART_RX_SetCallBack(LED);

	    //	    }
	    // Loop to continuously check for incoming data
	    while (1) {
	    	//if(intdata != 0)
	    		//UART_Send(intdata);
//	        if (UART_ReceivePerodic(&receivedData)) {
	            // Process the received data
	            // For example, toggle an LED or perform an action based on the received data
	//        }
	    }

	    return 0;
}
