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

int main() {

	Port_Init(pin_cfg);
	Dio_WriteChannel(PA_4, STD_LOW);

	SPI_voidInit();
	u8 Local_u8RXData;

	while (1) {
		Dio_WriteChannel(PB_4, STD_HIGH);
		_delay_ms(1);
		Dio_WriteChannel(PB_4, STD_LOW);

		SPI_voidTransieve(2, &Local_u8RXData);
		if (Local_u8RXData == 70 ) {
			Dio_FlipChannel(PA_4);
			_delay_ms(1000);
		}
	}
	return 0;
}
