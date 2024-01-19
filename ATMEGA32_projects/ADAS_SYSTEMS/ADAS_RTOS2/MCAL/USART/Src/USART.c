/*
 * USART.c
 *
 * Created: 10/28/2023 11:14:45 AM
 *  Author: ahmed radwan
 */ 

#include <util/delay.h>
#include "../../../SERVICES/Standard_Data_Types.h"
#include "../../../SERVICES/Bit_Wise_Operations.h"
#include "../../PORT/PORT.h"
#include "../Inc/USART_PRIV.h"
#include "../Inc/USART.h"
/* pointers to call back functions used with the usart ISR */
static CALL_BACK_FN_TYPE USART_RECIVE_CALL_BACK_FN_ISR=NULL;
static CALL_BACK_FN_TYPE USART_TRANSMIT_CALL_BACK_FN_ISR=NULL;
static CALL_BACK_FN_TYPE USART_DATAREG_EMPTY_CALL_BACK_FN_ISR=NULL;


static void USART_vidSetBaudrate(u32 Baudrate);
static void USART_vidSetInt(stUSART_CFG_T*usart);
static void USART_vidSetNoBits(stUSART_CFG_T*usart);
static void USART_vidSetStopBits(stUSART_CFG_T*usart);
static void USART_vidSetParityBits(stUSART_CFG_T*usart);




/**
 * @brief initialize the functionality of the UART
 * @param usart address of struct of the cfg of the usart
 * @return Error_st of the function
 *         (USART_EOK) : the function done successfully
 *         (USART_ENOK): the function has issue  
 *         (USART_NULLPTR): the function has NULL as parameter
 */
enuUSART_ERRORSTATUS_T USART_INT_FULL(stUSART_CFG_T*usart){
	enuUSART_ERRORSTATUS_T usatr_status=USART_EOK;
	if(NULL==usart)
	{
		usatr_status=USART_NULLPTR;
	}
	else
	{
		USART_vidSetBaudrate(usart->BaudRate);
		UCSRC_ACCCES();
		RX_MODE_ENABLE();
		TX_MODE_ENABLE();
		USART_vidSetParityBits(usart);
		USART_vidSetStopBits(usart);
		USART_vidSetNoBits(usart);
		USART_vidSetInt(usart);
		USART_ASYN_SLECT();
	}
	return usatr_status;
}

/**
 * @brief wait until receive occur 
 * @param usart address of struct of the cfg of the usart
 * @param usart address of variable will contain the received data of the cfg of the usart
 * @return Error_st of the function
 *         (USART_EOK) : the function done successfully
 *         (USART_ENOK): the function has issue  
 *         (USART_NULLPTR): the function has NULL as parameter
 */
enuUSART_ERRORSTATUS_T USART_vidRECIVE_Blokind(stUSART_CFG_T*usart,u16 *data)
{
	enuUSART_ERRORSTATUS_T usatr_status=USART_EOK;
	if(NULL==usart||NULL==data)
	{
		usatr_status=USART_NULLPTR;
	}
	else
	{
		u8 recivehelper=0;
		
		if(USART_9_bit_legn==usart->datalegnth)
		{
			while(!USART_Receive_Complete());
			recivehelper=UCSRB;
			*data=UDR;
			recivehelper=(recivehelper>>1)&0x01;
			*data|=(recivehelper<<8);
			
		}
		else
		{
			while(!USART_Receive_Complete());
			*data=UDR;
		}
	}
	return usatr_status;

}
/**
 * @brief wait until transmit occur 
 * @param usart address of struct of the cfg of the usart
 * @param usart value of variable will contain the  data need to transmit
 * @return Error_st of the function
 *         (USART_EOK) : the function done successfully
 *         (USART_ENOK): the function has issue  
 *         (USART_NULLPTR): the function has NULL as parameter
 */
enuUSART_ERRORSTATUS_T USART_vidTRANSMIT_Blokind(stUSART_CFG_T*usart,u16 data)
{
	enuUSART_ERRORSTATUS_T usatr_status=USART_EOK;
	if(NULL==usart||NULL==data)
	{
		usatr_status=USART_NULLPTR;
	}
	else
	{
		if(USART_9_bit_legn==usart->datalegnth)
		{
			while(!USART_Data_Register_Empty());
			UCSRB|=data>>8;
			UDR=(u8)data;
		}
		else
		{
			while(!USART_Data_Register_Empty());
			UDR=data;
		}
	}
	return usatr_status;
}
/**
 * @brief no wait until recive occur 
 * @param usart address of struct of the cfg of the usart
 * @param usart address of variable will contain the received data of the cfg of the usart
 * @return Error_st of the function
 *         (USART_EOK) : the function done successfully
 *         (USART_ENOK): the function has issue  
 *         (USART_NULLPTR): the function has NULL as parameter
 */
enuUSART_ERRORSTATUS_T USART_vidReadData_Non_Bloking(stUSART_CFG_T*usart,u16 *data)
{
	enuUSART_ERRORSTATUS_T usatr_status=USART_EOK;
	if(NULL==usart||NULL==data)
	{
		usatr_status=USART_NULLPTR;
	}
	else
	{
		u8 recivehelper=0;
		if(USART_9_bit_legn==usart->datalegnth)
		{
			recivehelper=UCSRB;
			*data=UDR;
			recivehelper=(recivehelper>>1)&0x01;
			*data|=(recivehelper<<8);
			
		}
		else
		{
			*data=UDR;
		}
	}
	return usatr_status;	
}
static void USART_vidSetBaudrate(u32 Baudrate)
{
	u32 locBudrateregval=(u32)F_CPU/(16*Baudrate)-1;
	//UBRRH_ACCCES();
	//UBRRH=Baudrate>>8;
	UBRRL=(u8)locBudrateregval;
	//SET_BAUD_RATE();
}

static void USART_vidSetInt(stUSART_CFG_T*usart)
{
	if (usart->EUSART_INT_When_Recive==USART_INT_ENABLE_CFG)
	{
		USART_RECIVE_CALL_BACK_FN_ISR=usart->Recive_ISR;
		RX_INT_ENABLE();
	}
	if (usart->EUSART_INT_When_Transmit==USART_INT_ENABLE_CFG)
	{
		USART_TRANSMIT_CALL_BACK_FN_ISR=usart->Transmit_ISR;
		TX_INT_ENABLE();
	}
	if(usart->EUSART_INT_When_DataRegEmpty==USART_INT_ENABLE_CFG)
	{
		USART_DATAREG_EMPTY_CALL_BACK_FN_ISR=usart->DataRegEmpty_ISR;
		EMPTY_INT_ENABLE();
	}
}


static void USART_vidSetNoBits(stUSART_CFG_T*usart)
{
	if(USART_9_bit_legn==usart->datalegnth)
	{
		slect_bit_no(0x03);
		SET_BIT(UCSRB,2);
	}
	else{
		CLR_BIT(UCSRB,2);
		slect_bit_no(usart->datalegnth);
	}
}

static void USART_vidSetStopBits(stUSART_CFG_T*usart)
{
	if(USART_one_stopBit_CFG==usart->stopbits)
	{
		Stop_1Bit_Select();
	}
	else if(USART_Two_stopBit_CFG==usart->stopbits)
	{
		Stop_2Bit_Select();
	}
}


static void USART_vidSetParityBits(stUSART_CFG_T*usart)
{
	if(USART_Even_Parity_CFG==usart->parity)
	{
		CLR_BIT(UCSRC,4);
		SET_BIT(UCSRC,5);
	}
	else if(USART_Odd_Parity_CFG==usart->parity)
	{
		SET_BIT(UCSRC,4);
		SET_BIT(UCSRC,5);
	}
	else
	{
		CLR_BIT(UCSRC,4);
		CLR_BIT(UCSRC,5);
	}
}


/******************vector table section*************************/

void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
	if(!(NULL==USART_RECIVE_CALL_BACK_FN_ISR))
	{
		USART_RECIVE_CALL_BACK_FN_ISR();
	}
	
}
void __vector_14(void) __attribute__((signal));
void __vector_14(void)
{
	if(!(NULL==USART_DATAREG_EMPTY_CALL_BACK_FN_ISR))
	{
		USART_DATAREG_EMPTY_CALL_BACK_FN_ISR();
	}	
}
void __vector_15(void) __attribute__((signal));
void __vector_15(void)
{
	if(!(NULL==USART_TRANSMIT_CALL_BACK_FN_ISR))
	{
		USART_TRANSMIT_CALL_BACK_FN_ISR();
	}	
}



/*
void USART_INT(void){
	SET_BAUD_RATE();
	RX_MODE_ENABLE();
	TX_MODE_ENABLE();
	UCSRC_ACCCES();
	Stop_Bit_Selec();
	slect_8bit();
	USART_ASYN_SLECT();
}*/