/*
 * SPI_registers.h
 *
 *  Created on: Oct 30, 2023
 *      Author: AhmedAbogabl
 */

#ifndef SPI_REGISTER_H
#define SPI_REGISTER_H

#include "../../../utils/STD_TYPES.h"


/* SPI REGISTERS */

typedef struct{
	u8 SPCR;// SPI Control Register
	u8 SPSR;// SPI Status Register
	u8 SPDR;// SPI Data Register
}SPI_REGS;


#define SPI  ((volatile SPI_REGS *)0x2D)

//#define SPI = (volatile unsigned char*)0x2D;

// SPI Control Register
//#define SPCR    (*(volatile unsigned char*)0x2D)
#define SPR0    0
#define SPR1    1
#define CPHA    2
#define CPOL    3
#define MSTR    4
#define DORD    5
#define SPE     6
#define SPIE    7

// SPI Status Register
//#define SPSR    (*(volatile unsigned char*)0x2E)
#define SPI2X   0
#define WCOL    6
#define SPIF    7

// SPI Data Register
//#define SPDR    (*(volatile unsigned char*)0x2F)

#endif /* SPI_REGISTER_H */
