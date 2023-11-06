/*
 * SPI_register.h
 *
 *  Created on: Oct 30, 2023
 *      Author: AhmedAbogabl
 */

#include "../includes/SPI_interface.h"


void SPI_voidInit_Master_SLAVE(void){

	#if SPI_MODE == SPI_MASTER
	SET_BIT(SPCR,MSTR);
	#elif SPI_MODE == SPI_SLAVE
	CLR_BIT(SPCR,MSTR);
	#endif
	SET_BIT(SPCR,SPE);

}


void SPI_voidTranceive(u8 TX_data , u8* RX_data){
	SPDR = TX_data;
	while(!GET_BIT(SPSR,SPIF));
	* RX_data =  SPDR;
}
