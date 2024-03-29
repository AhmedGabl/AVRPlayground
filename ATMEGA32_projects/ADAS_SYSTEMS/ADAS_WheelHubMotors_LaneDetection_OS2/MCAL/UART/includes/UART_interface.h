/*
 * UART_interface.h
 *
 *  Created on: Oct 28, 2023
 *      Author: AhmedAbogabl
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "UART_config.h"
#include "UART_register.h"
#include "../../../utils/STD_TYPES.h"
#include "../../../utils/BIT_MATH.h"


void UART_Init(void);


void UART_Send(u8 data);
u8 UART_Receive(void);
u8 UART_ReceivePerodic(u8*pdata);

int UART_ReceiveNumber() ;
void UART_TransmitString(const char* str) ;



void UART_RX_InterruptEnable(void);
void UART_RX_InterruptDisable(void);
//
//void UART_TX_InterruptEnable(void);
//void UART_TX_InterruptDisable(void);

void UART_RX_SetCallBack(void (*LocalFptr)(u8));
//void UART_TX_SetCallBack(void (*LocalFptr)(void));

void UART_SendNoBlock(u8 data);
u8 UART_ReceiveNoBlock(void);


#endif /* UART_INTERFACE_H_ */
