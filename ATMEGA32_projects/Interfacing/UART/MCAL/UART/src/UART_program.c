/*
 * UART_program.c
 *
 *  Created on: Oct 28, 2023
 *      Author: AhmedAbogabl
 */


#include "../includes/UART_interface.h"


//#define NULL '\0'
static void(*UART_RX_Fptr)(u8 RXdata)=NULL;
//static void(*UART_TX_Fptr)(void)=NULL;


void UART_Init(void)
{
	//baud rate 9600
	UBRRL= (1000000/((BAUDRATE)))-1;

	//normal speed
	CLR_BIT(UCSRA,U2X);


	//frame (stop ,data ,parity) 1 STOP NO PARITY 8 DATA

	// ENABLE RX TX
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
}

void UART_Send(u8 data)
{
	while(!GET_BIT(UCSRA,UDRE));
	UDR=data;
}

void UART_SendNoBlock(u8 data)
{
	UDR=data;
}

u8 UART_ReceiveNoBlock(void)
{
	return UDR;
}




u8 UART_Receive(void)
{
	while(!GET_BIT(UCSRA,RXC));
	return UDR;
}


u8 UART_ReceivePerodic(u8*pdata)
{
	if (GET_BIT(UCSRA,RXC))
	{

		*pdata=UDR;
		return 1;
	}
	return 0;
}



void UART_RX_InterruptEnable(void)
{
	SET_BIT(UCSRB,RXCIE);
}

void UART_RX_InterruptDisable(void)
{
	CLR_BIT(UCSRB,RXCIE);
}

//
//void UART_TX_InterruptEnable(void)
//{
//	SET_BIT(UCSRB,TXCIE);
//}
//
//void UART_TX_InterruptDisable(void)
//{
//	CLR_BIT(UCSRB,TXCIE);
//}

void UART_RX_SetCallBack(void (*LocalFptr)(u8))
{
	UART_RX_Fptr = LocalFptr;
}
//
//void UART_TX_SetCallBack(void (*LocalFptr)(void))
//{
//	UART_TX_Fptr = LocalFptr;
//}


void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
	if (UART_RX_Fptr!=NULL)
	{
		UART_RX_Fptr(UDR);
	}
}
//
//void __vector_15(void) __attribute__((signal));
//void __vector_15(void)
//{
//	if (UART_TX_Fptr!=NULL)
//	{
//		UART_TX_Fptr();
//	}
//}
