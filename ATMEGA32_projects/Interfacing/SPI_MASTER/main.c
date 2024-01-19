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

#define SPI_MASTER_ASYNCH_ISR_TEST  main


void Action(u8 copy_u8RxData)
{
	if(copy_u8RxData == 70)
		Dio_FlipChannel(PA_4);
}

int SPI_MASTER_ASYNCH_ISR_TEST() {

	Port_Init(pin_cfg);
	Dio_WriteChannel(PA_4, STD_LOW);
	GI_voidEnable();
	SPI_voidInit();




	while (1) {
//		Dio_WriteChannel(PB_4, STD_HIGH);
//		_delay_ms(1);
//		Dio_WriteChannel(PB_4, STD_LOW);

	SPI_voidTransmitAsynchronous(2,&Action);

//	_delay_ms(300);
	}
	return 0;
}
