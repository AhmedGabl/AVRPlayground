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


#define   SPI_SLAVE_TEST main

void Action(u8 copy_u8RxData)
{
	if(copy_u8RxData == 2)
		Dio_FlipChannel(PA_4);
//	_delay_ms(300);
}


int SMART_HOME_USR_TEST(){
	Port_Init(pin_cfg);
Lcd_Init();
	//slave select low
//	Dio_WriteChannel(PB_4,STD_LOW);
	Dio_WriteChannel(PA_4,STD_LOW);
	GI_voidEnable();

	SPI_voidInit();
	_delay_ms(100);
	_delay_ms(100);

	u8 Local_u8RXData;
 	while(1)
	{
		Dio_WriteChannel(PA_6,STD_LOW);

//		Lcd_PutChar("H");
		_delay_ms(100);
		SPI_voidTransieve(3,&Local_u8RXData);
		_delay_ms(100);
		SPI_voidTransieve(1,&Local_u8RXData);
		_delay_ms(100);
		SPI_voidTransieve(2,&Local_u8RXData);
		_delay_ms(100);
		SPI_voidTransieve(3,&Local_u8RXData);
		_delay_ms(100);

		SPI_voidTransieve(1,&Local_u8RXData);
		if (Local_u8RXData == 1) {
			Dio_WriteChannel(PA_4,STD_HIGH);
		}
	//	exit(1);
		_delay_ms(5000);
	//	exit(0);
		Dio_WriteChannel(PA_6,STD_HIGH);

//	SPI_voidTransmitAsynchronous(0,&Action);
//	_delay_ms(100);
//	SPI_voidTransmitAsynchronous(1,&Action);
//	_delay_ms(100);
//	SPI_voidTransmitAsynchronous(2,&Action);
//	_delay_ms(100);
//
//	SPI_voidTransmitAsynchronous(3,&Action);
	//	_delay_ms(100);

}
	return 0;
}


int SPI_SLAVE_TEST(){
	Port_Init(pin_cfg);

	//slave select low
//	Dio_WriteChannel(PB_4,STD_LOW);
//	Dio_WriteChannel(PA_4,STD_LOW);

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
