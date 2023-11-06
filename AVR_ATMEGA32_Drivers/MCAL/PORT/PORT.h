/*
 * PORT.h
 *
 *  Created on: Oct 20, 2023
 *      Author: AhmedAbogabl
 */

#ifndef MCAL_PORT_PORT_H_
#define MCAL_PORT_PORT_H_


#include  "PORT_cnf.h" //NUM_OF_CNF //  Port_ConfigType pin_cfg[NUM_OF_CNF]
#include <avr/io.h>
#include "../DIO/DIO_interface.h"

void Port_Init(const Port_ConfigType* ConfigPtr);


#endif /* MCAL_PORT_PORT_H_ */
