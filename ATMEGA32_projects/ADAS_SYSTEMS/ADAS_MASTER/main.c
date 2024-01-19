/*
 * main.c

 *
 *  Created on: Oct 17, 2023
 *      Author: AhmedAbogabl
 */
//#define F_CPU 16000000UL
#include <avr/delay.h>
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/PORT/PORT.h"
#include "MCAL/SPI/includes/SPI_interface.h"
#include "MCAL/GI/GI_interface.h"
#include "ADAS_APP.h"



u8 Lock_state = 0 ;
u8 function_toAct = 0;

//test getting unlocked vehicle so u can proceed with ur actions
void Act(u8 data){
	if(data == APP_VEHICLE_UNLOCKED)
		{
		Lock_state = 1;
	    UART_TransmitString("\r\n\r\n vehicle unlocked \r\n\r\n");
	    Dio_WriteChannel(PB_4, STD_HIGH);
		}
}

//test reciving obstacle  or autopark
void Act0(u8 data){
	if(data == 'O' )
			{
		//	Lock_state = 1;
		    UART_TransmitString("\r\n\r\n UNLOCKED OBStacle AVOIDENCE FEATUURE\r\n\r\n");
			}
	else if( data == 'I')
			{
		//	Lock_state = 1;
		    UART_TransmitString("\r\n\r\n UNLOCKED  AUTOPARK \r\n\r\n");
			}

}


//test reciving feedback 0xEE
void NOAct(u8 data){
	if(data == 0xEE)
		Dio_FlipChannel(PA_4);
//		Dio_WriteChannel(PA_4,STD_HIGH);
}

int main() {
	Port_Init(pin_cfg);
	GI_voidEnable();
	UART_Init();
	SPI_voidInit();
    Dio_WriteChannel(PA_5, STD_HIGH);
//    Dio_WriteChannel(PB_4, STD_HIGH);

    while (1) {


		if(Lock_state == 0)
		{
			SPI_voidTransmitAsynchronous(APP_VEHICLE_ACCESS_INFO_REQUEST , Act);
//            UART_TransmitString("\r\n inside LOCK StATE \r\n");
		}
		else if (Dio_ReadChannel(PA_5) == 0)
		{

			SPI_voidTransmitAsynchronous(APP_MOTORS_CONTROL_REQUEST ,NOAct);
	//	    UART_TransmitString("\r\n inside APP_MOTORS_CONTROL_REQUEST \r\n");
		    _delay_ms(10);
		    SPI_voidTransmitAsynchronous('W', NOAct);
		    _delay_ms(1000);

			SPI_voidTransmitAsynchronous(APP_MOTORS_CONTROL_REQUEST ,NOAct);
	//	    UART_TransmitString("\r\n inside APP_MOTORS_CONTROL_REQUEST \r\n");
		    _delay_ms(10);
		    SPI_voidTransmitAsynchronous('S', NOAct);
		    _delay_ms(1000);

			SPI_voidTransmitAsynchronous(APP_MOTORS_CONTROL_REQUEST ,NOAct);
		//    UART_TransmitString("\r\n inside APP_MOTORS_CONTROL_REQUEST \r\n");
		    _delay_ms(10);
		    SPI_voidTransmitAsynchronous('D', NOAct);
		    _delay_ms(1000);

			SPI_voidTransmitAsynchronous(APP_MOTORS_CONTROL_REQUEST ,NOAct);
	//	    UART_TransmitString("\r\n inside APP_MOTORS_CONTROL_REQUEST \r\n");
		    _delay_ms(10);
		    SPI_voidTransmitAsynchronous('A', NOAct);
		    _delay_ms(1000);

			SPI_voidTransmitAsynchronous(APP_MOTORS_CONTROL_REQUEST ,NOAct);
	//	    UART_TransmitString("\r\n inside APP_MOTORS_CONTROL_REQUEST \r\n");
		    _delay_ms(10);
		    SPI_voidTransmitAsynchronous('P', NOAct);
		    _delay_ms(1000);

			SPI_voidTransmitAsynchronous(APP_MOTORS_CONTROL_REQUEST ,NOAct);
	//	    UART_TransmitString("\r\n inside APP_MOTORS_CONTROL_REQUEST \r\n");
		    _delay_ms(10);
		    SPI_voidTransmitAsynchronous('K', NOAct);
		    _delay_ms(1000);
		}
		else
		{
			SPI_voidTransmitAsynchronous(0x36 , Act0);
			   //         UART_TransmitString("\r\n inside 0x36  \r\n");
		}
		_delay_ms(10);
	}
	return 0;
}