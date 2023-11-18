/*
 * TWI_register.h
 *
 *  Created on: Oct 31, 2023
 *      Author: AhmedAbogabl
 */


#ifndef TWI_REGISTERS_H
#define TWI_REGISTERS_H

#include "../../../utils/STD_TYPES.h"

/* TWI (I2C) REGISTERS */


// TWI Control Register
#define TWCR    (*(volatile u8*)0x56)
#define TWIE    0
#define TWEN    2
#define TWWC    3
#define TWSTO   4
#define TWSTA   5
#define TWEA    6
#define TWINT   7

// TWI Status Register
#define TWSR    (*(volatile u8*)0x21)
#define TWPS0   0
#define TWPS1   1
#define TWS3    3
#define TWS4    4
#define TWS5    5
#define TWS6    6
#define TWS7    7

// TWI Bit Rate Register
#define TWBR    (*(volatile u8*)0x20)

// TWI Address Register
#define TWAR    (*(volatile u8*)0x22)
#define TWA0    1
#define TWA1    2
#define TWA2    3
#define TWA3    4
#define TWA4    5
#define TWA5    6
#define TWA6    7
#define TWGCE   0

// TWI Data Register
#define TWDR    (*(volatile u8*)0x23)

#endif /* TWI_REGISTER_H */
