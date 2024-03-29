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
	UBRRL= (1000000/(2*((BAUDRATE))))-1;

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



void UART_TransmitString(const char* str) {
    // Iterate over each character in the string until the null terminator is reached
    for (u8 i = 0; str[i] != '\0'; i++) {
    	UART_Send(str[i]); // Transmit each character
    }
}


// Function to receive a number over UART, terminated by '\r' (Enter key)
int UART_ReceiveNumber() {
    char rxBuffer[20];  // A buffer to store received characters
    int rxIndex = 0;    // Index for the buffer
    char receivedChar;
    u8 endOfNumber = 0;

    // Read characters until Enter ('\r') is received
    while (!endOfNumber) {
        while (!GET_BIT(UCSRA, 7));  // Wait for a character to be received
        receivedChar = UDR;          // Read the received character

        if (receivedChar == '\r' || receivedChar == '\n') {
            // If Enter key is received, mark the end of the number
            endOfNumber = 1;
        } else {
            // Store the character in the buffer
            rxBuffer[rxIndex] = receivedChar;
            rxIndex++;

            // Check if the buffer is full (adjust the buffer size as needed)
            if (rxIndex >= sizeof(rxBuffer)) {
                rxIndex = sizeof(rxBuffer) - 1;
            }
        }
    }

    // Null-terminate the string in the buffer
    rxBuffer[rxIndex] = '\0';

    // Convert the received string to an integer
    int receivedNumber = atoi(rxBuffer);

    return receivedNumber;
}


/*
 * interrupt
 */

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
	if (UART_RX_Fptr != NULL)
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
