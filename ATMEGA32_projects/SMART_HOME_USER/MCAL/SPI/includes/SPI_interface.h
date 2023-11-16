/*
 * SPI_interface.h
 *
 *  Created on: Oct 30, 2023
 *      Author: AhmedAbogabl
 */

#ifndef MCAL_SPI_INCLUDES_SPI_INTERFACE_H_
#define MCAL_SPI_INCLUDES_SPI_INTERFACE_H_

#include "../../../utils/BIT_MATH.h"
#include "../../../utils/STD_TYPES.h"
//
//
//
////SPI_SYNCHRONOUS_ACTIVE
////OPTions
//#define SPI_SYNCH 1
//#define SPI_ASYNCH 2

//SPI  modes
#define SPI_MASTER 1
#define SPI_SLAVE  2

//@brief Function to initialize the spi mode master/slave  and enable the spi
void SPI_voidInit(void);

void SPI_voidTransieve(u8 copy_u8TXdata , u8* copy_pu8_RXdata);

void SPI_voidTransmitAsynchronous(u8 copy_u8TxData, void(*ptrToFun)(u8));

#endif /* MCAL_SPI_INCLUDES_SPI_INTERFACE_H_ */
