/*
 * main.c

 *
 *  Created on: Oct 17, 2023
 *      Author: AhmedAbogabl
 */
//#define F_CPU 16000000UL

#include "utils/BIT_MATH.h"
#include "utils/STD_TYPES.h"

#include "MCAL/WDT/includes/WDT_interface.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/PORT/PORT.h"
#include "MCAL/PORT/PORT_cnf.h"
#include "avr/delay.h"
int main() {

	Port_Init(pin_cfg);

	Dio_WriteChannel(PA_5, STD_HIGH);
	_delay_ms(1000);
	Dio_WriteChannel(PA_5,STD_LOW);

 WDT_voidEnable(WDT_TIME_1_S);

	while (1)
	{

	}
WDT_voidDisable();

return 0;
}
