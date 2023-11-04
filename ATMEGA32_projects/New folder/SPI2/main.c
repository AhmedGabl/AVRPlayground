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

int main(){
	Port_Init(pin_cfg);

	//slave select low
//	Dio_WriteChannel(PB_4,STD_LOW);
	Dio_WriteChannel(PA_4,STD_LOW);

	SPI_voidInit();

	u8 Local_u8RXData;
	while(1){
	SPI_voidTransieve(70,&Local_u8RXData);
	if(Local_u8RXData == 2)
	{
		Dio_FlipChannel(PA_4);
		_delay_ms(1000);
	}
	}
	return 0;
}
