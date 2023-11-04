/*
 * SPI_register.h
 *
 *  Created on: Oct 30, 2023
 *      Author: AhmedAbogabl
 */

#include "../includes/SPI_interface.h"
#include "../includes/SPI_registers.h"
#include "../includes/SPI_config.h"



void SPI_voidInit(void){

	//select master
	#if SPI_MODE == SPI_MASTER
	SET_BIT(SPI->SPCR,MSTR);

	//set frequency 1Mhz  /only master selcts the clk
	SET_BIT(SPI->SPCR,SPR0);
	CLR_BIT(SPI->SPCR,SPR1);
	CLR_BIT(SPI->SPSR,SPI2X);
	//select slave
	#elif SPI_MODE == SPI_SLAVE
	CLR_BIT(SPI->SPCR,MSTR);
	#endif

	//select LSB
	SET_BIT(SPI->SPCR,DORD);

	//select clk polarity falling  select rising sample

	SET_BIT(SPI->SPCR,CPOL);//polarity
	SET_BIT(SPI->SPCR,CPHA);//phase


	//enable
	SET_BIT(SPI->SPCR,SPE);
}


void SPI_voidTransieve(u8 copy_u8TXdata , u8* copy_pu8_RXdata){

	if(copy_pu8_RXdata != NULL){
		while(1 == GET_BIT(SPI->SPSR,WCOL));
		SPI->SPDR = copy_u8TXdata;
		//Budy wait
		while(0 == GET_BIT(SPI->SPSR,SPIF));
	* copy_pu8_RXdata =  SPI->SPDR;
	}
}
