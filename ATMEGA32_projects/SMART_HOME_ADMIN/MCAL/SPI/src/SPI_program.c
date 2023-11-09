/*
 * SPI_register.h
 *
 *  Created on: Oct 30, 2023
 *      Author: AhmedAbogabl
 */

#include "../includes/SPI_interface.h"
#include "../includes/SPI_registers.h"
#include "../includes/SPI_config.h"

static void (*private_pCallBackSPI)(u8) = NULL;


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

	//Disable SPI Interrrupt
	CLR_BIT(SPI->SPCR,SPIE);
	if(copy_pu8_RXdata != NULL){
		while(1 == GET_BIT(SPI->SPSR,WCOL));
		SPI->SPDR = copy_u8TXdata;
		//Budy wait
		while(0 == GET_BIT(SPI->SPSR,SPIF));
	* copy_pu8_RXdata =  SPI->SPDR;
	}
}


void SPI_voidTransmitAsynchronous(u8 copy_u8TxData, void(*ptrToFun)(u8 copy_u8RxData)){
	if(ptrToFun != NULL)
	{
		//Enable SPI Interrrupt
		SET_BIT(SPI->SPCR,SPIE);
			//set call back
		private_pCallBackSPI = ptrToFun ;
		//check collision
		while(1 == GET_BIT(SPI->SPSR,WCOL));
				SPI->SPDR = copy_u8TxData;
	}
}


// ISR for timer0 output compare match
void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{
	if (private_pCallBackSPI != NULL) {
		private_pCallBackSPI(SPI->SPDR);
	}
}
