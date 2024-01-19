/*
 * BT.c
 *
 *  Created on: Nov 20, 2023
 *      Author: AhmedAbogabl
 */

#include "../../MCAL/UART/includes/UART_interface.h"

void BT_Init(void (*LocalFptr)(u8)) {
	UART_Init();
	UART_TransmitString("U To Unlock\r\n");
	UART_RX_InterruptEnable();
	UART_RX_SetCallBack(LocalFptr);

}

void BT_CTL_Options(void)
{
	UART_TransmitString("Ready\r\n");
	UART_TransmitString(" 0-10  SPEED CONTROL\r\n");
	UART_TransmitString(" W  FORWARD\r\n");
	UART_TransmitString(" S  REVERSE\r\n");

	UART_TransmitString(" A  LEFT\r\n");
	UART_TransmitString(" D  RIGHT\r\n");
	UART_TransmitString(" K  DIRECT\r\n");

	UART_TransmitString(" P  BRAKE\r\n");

	UART_TransmitString("\r\nAuxiliary functions\r\n");
	UART_TransmitString(" L  LANE ASSISTANT\r\n");
	UART_TransmitString(" O  Obstacle avoidance\r\n");
	UART_TransmitString(" I  AUTO PARK\r\n");
}
//
//void BT_Send(u8 data) {
//	UART_Send(data);
//}
//
//u8 BT_Receive(void) {
//	u8 dummy = UART_Receive();
////	UART_Send(dummy);
//	return dummy;
//}
//
//u32 BT_ReceiveNumber() {
//	return UART_ReceiveNumber();
//}
//
//void BT_TransmitString(const char* str) {
//	UART_TransmitString(str);
//}