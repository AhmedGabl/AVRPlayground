/*
 * SPI.c
 *
 * Created: 10/29/2023 9:21:52 AM
 *  Author: ahmed radwan
 */ 
#include "../../../SERVICES/Standard_Data_Types.h"
#include "../../../SERVICES/Bit_Wise_Operations.h"
#include <util/delay.h>

#include "../../PORT/PORT.h"
#include "../../DIO/DIO.h"
#include "../Inc/SPI_PRIV.h"
#include "../Inc/SPI_CFG.h"
#include "../Inc/SPI.h"


u8* SPI_INT_READ_REG=0;
static CALL_BACK_FN_TYPE SPI_CALL_BACK_FN_ISR=NULL;
SPI_enuError_T spi_INT(SPI_st_T*SPI)
{
	SPI_FREQ(SPI->freq_cfg);
	switch(SPI->dataorder)
	{
		case SPI_MSB_FIRST_CFG :
			SPI_MSB_FIRST();
		    break;
		case SPI_LSB_FIRST_CFG:
			SPI_LSB_FIRST();
			break;
		default:
		   break;	
	}
		switch(SPI->mode_s)
		{		
			case SPI_SLAVE_MODE :
				SPI_SLAVE_MODE_SLECT();	
			    Port_enuSetpinDirection(PIN_B6_ID_14,PIN_MODE_OUTPUT);//MISO 
				Port_enuSetpinMode(PIN_B4_ID_12,PIN_CFG_MODE_INPUT_PULLUP);//ss
				break;
			case SPI_MASTER_MODE:
				Port_enuSetpinDirection(PIN_B5_ID_13,PIN_MODE_OUTPUT);//MOSI 
				Port_enuSetpinMode(PIN_B4_ID_12,PIN_MODE_OUTPUT_HIGH);//ss
				Port_enuSetpinDirection(PIN_B7_ID_15,PIN_MODE_OUTPUT);//SCK
				SPI_MASTER_MODE_SLECT()	;
				break;
			default:
			 break;
		}
		switch (SPI->CLK_polarity)
		{
			case SPI_CLOCK_IDEL_LOW :
				SPI_CLOCK_IDLE_LOW();
				break;
			case SPI_CLOCK_IDEL_HIGH :
				SPI_CLOCK_IDLE_HIGH();
				break;
			default:
				break;
		}
		switch(SPI->CLK_phase)	
		{			
			case SPI_CLOCK_SAMPLE_LEADING :
				SPI_CLOCK_LEADING_SAMPLE();
				break;
			case SPI_CLOCK_SAMPLE_TRAILING:
				SPI_CLOCK_TRAILING_SAMPLE();
				break;
			default:
			break;
		}
		if(SPI->SPI_interrupt_cfg==SPI_INT_EN_CFG)
		{
			 SPI_INT_ENABLE();
			 if(SPI->SPI_CALL_BACK!=NULL)
			 {
				 SPI_CALL_BACK_FN_ISR=SPI->SPI_CALL_BACK;
			 }
			 
		}
		SPI_ENABLE();

}
SPI_enuError_T spi_transmit(SPI_st_T*SPI,u8 data)
{
	Dio_enuWriteChannel(PIN_B4_ID_12,PIN_MODE_OUTPUT_LOW);
	SPDR = data;
	while (!SPI_INT_FLAG_STATUS());
	Dio_enuWriteChannel(PIN_B4_ID_12,PIN_MODE_OUTPUT_HIGH);
}
SPI_enuError_T spi_Recive_bolling(SPI_st_T*SPI,u8*rdata){
	
	while (!SPI_INT_FLAG_STATUS());
	*rdata=SPDR;
	
}
SPI_enuError_T spi_SendRecive(u8 data,u8* recived)
{
	Dio_enuWriteChannel(PIN_B4_ID_12,PIN_MODE_OUTPUT_LOW);
	_delay_ms(10);
	SPDR = data;
	while (!SPI_INT_FLAG_STATUS());
	_delay_ms(10);
	*recived=SPDR;
	//Dio_enuWriteChannel(PIN_B4_ID_12,PIN_MODE_OUTPUT_HIGH);
}
SPI_enuError_T spi_SendRecive_ASYNC(u8 data,u8* recived)
{
	Dio_enuWriteChannel(PIN_B4_ID_12,PIN_MODE_OUTPUT_LOW);
	SPI_INT_READ_REG=recived;
	SPDR = data;
}
SPI_enuError_T spi_Recive_ASYNC(u8* recived)
{
	SPI_INT_READ_REG=recived;
}
SPI_enuError_T spi_Update_Recive(u8 data,u8* recived)
{ 
	
	
	while (!SPI_INT_FLAG_STATUS());
	_delay_ms(10);
	*recived=SPDR;
	_delay_ms(10);
	SPDR = data;
	
}
void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{
	if(SPI_INT_READ_REG!=NULL)
	{
		*SPI_INT_READ_REG=SPDR;
	}
	else
	{
		
	}
}