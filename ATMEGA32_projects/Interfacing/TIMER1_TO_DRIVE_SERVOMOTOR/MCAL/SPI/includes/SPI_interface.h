/*
 * SPI_interface.h
 *
 *  Created on: Oct 30, 2023
 *      Author: AhmedAbogabl
 */

#ifndef MCAL_SPI_INCLUDES_SPI_INTERFACE_H_
#define MCAL_SPI_INCLUDES_SPI_INTERFACE_H_

#include "../includes/SPI_registers.h"

#include "../../../utils/BIT_MATH.h"


void SPI_voidInit_Master_SLAVE(void);

void SPI_voidTranceive(u8 TX_data , u8 *RX_data);





#define SPI_MASTER 1
#define SPI_SLAVE  2

#define SPI_MODE SPI_MASTER


#endif /* MCAL_SPI_INCLUDES_SPI_INTERFACE_H_ */
