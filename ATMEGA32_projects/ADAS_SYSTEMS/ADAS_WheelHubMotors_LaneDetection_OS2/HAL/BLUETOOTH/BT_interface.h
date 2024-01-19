/*
 * BT.h
 *
 *  Created on: Nov 20, 2023
 *      Author: AhmedAbogabl
 */

#ifndef HAL_BLUETOOTH_BT_INTERFACE_H_
#define HAL_BLUETOOTH_BT_INTERFACE_H_

#include "../../utils/STD_TYPES.h"

void BT_Init(void (*LocalFptr)(u8));

void BT_Send(u8 data);

u8 BT_Receive(void);

u8 BT_ReceivePerodic(u8*pdata);

u32 BT_ReceiveNumber();

void BT_TransmitString(const char* str) ;

#endif /* HAL_BLUETOOTH_BT_INTERFACE_H_ */
