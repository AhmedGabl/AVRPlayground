/*
 * I2C_PRIV.h
 *
 * Created: 10/30/2023 11:35:08 AM
 *  Author: ahmed radwan
 */ 


#ifndef I2C_PRIV_H_
#define I2C_PRIV_H_

#define  TWBR			(*((volatile ptr_u8)0x20))
#define  TWDR			(*((volatile ptr_u8)0x23))
#define  TWAR			(*((volatile ptr_u8)0x22))
#define  TWCR			(*((volatile ptr_u8)0x56))
#define  TWSR			(*((volatile ptr_u8)0x21))


#define TWINT 7
#define TWEA  6
#define TWSTA 5
#define TWSTO 4
#define TWWC  3
#define TWEN  2
#define TWIE  0

#define TWS7 7
#define TWS6 6
#define TWS5 5
#define TWS4 4
#define TWS3 3
#define TWPS1 1
#define TWPS0 0


#endif /* I2C_PRIV_H_ */