/*
 * SPI_PRIV.h
 *
 * Created: 10/29/2023 9:22:45 AM
 *  Author: ahmed radwan
 */ 


#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_

#define SPCR         (*((volatile ptr_u8)0x2D))
#define SPSR         (*((volatile ptr_u8)0x2E))
#define SPDR         (*((volatile ptr_u8)0x2F))


#endif /* SPI_PRIV_H_ */