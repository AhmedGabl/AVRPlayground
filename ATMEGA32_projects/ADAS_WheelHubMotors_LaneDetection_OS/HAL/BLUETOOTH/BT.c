/*
 * BT.c
 *
 *  Created on: Nov 20, 2023
 *      Author: AhmedAbogabl
 */

#include "../../MCAL/UART/includes/UART_interface.h"

void BT_Init(void) {
	UART_Init();
	UART_TransmitString("Ready\r\n");
	UART_TransmitString(" W  FORWARD\r\n");
	UART_TransmitString(" S  REVERSE\r\n");
	UART_TransmitString(" A  LEFT\r\n");
	UART_TransmitString(" D  RIGHT\r\n");
	UART_TransmitString(" 1  LANE ASSISTANT\r\n");
}

void BT_Send(u8 data) {
	UART_Send(data);
}

u8 BT_Receive(void) {
	u8 dummy = UART_Receive();
//	UART_Send(dummy);
	return dummy;
}
//
//u8 BT_ReceivePerodic(u8 * pdata)
//{
//
//}

u32 BT_ReceiveNumber() {
	return UART_ReceiveNumber();
}

void BT_TransmitString(const char* str) {
	UART_TransmitString(str);
}
