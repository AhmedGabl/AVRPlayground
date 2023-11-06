/*
 * EEPROM_program.c
 *
 *  Created on: Oct 31, 2023
 *      Author: AhmedAbogabl
 */

#include "../../utils/BIT_MATH.h"
#include "../../utils/STD_TYPES.h"

#include "../../MCAL/TWI/includes/TWI_interface.h"
#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "util/delay.h"

void EEPROM_voidInit(void) {
    // Initialize the I2C (TWI) as a master with a specified slave address
    TWI_voidInitMaster(255);
}

void EEPROM_voidWriteByte(u16 Copy_u16WordAddress, u8 Copy_u8Data) {
    u8 local_u8Address = (Copy_u16WordAddress >> 8) | EEPROM_FIXED_ADDRESS;
    TWI_voidSendStartCondition();  // Send Start Condition
    TWI_voidSendSlaveAddWithWrite(local_u8Address);  // Send Slave Address with Write Operation
    TWI_voidWriteMasterDataByte((u8)Copy_u16WordAddress);  // Write Data Byte by Master for Word Address
    TWI_voidWriteMasterDataByte(Copy_u8Data);  // Write the data byte to EEPROM
    TWI_voidSendStopCondition();  // Send Stop Condition
    _delay_ms(5);  // Delay for EEPROM write cycle completion
}

void EEPROM_voidWritePage(u16 Copy_u16WordAddress, u8 *Copy_pu8Array, u8 Copy_arraySize) {
    u8 i = 0;
    u8 local_u8Address = (Copy_u16WordAddress >> 8) | EEPROM_FIXED_ADDRESS;  // Calculate the actual EEPROM address

    TWI_voidSendStartCondition();  // Send Start Condition
    TWI_voidSendSlaveAddWithWrite(local_u8Address);  // Send Slave Address with Write Operation

    TWI_voidWriteMasterDataByte((u8)Copy_u16WordAddress);  // Write Data Byte by Master for Word Address

    for (i = 0; i < Copy_arraySize; i++) {
        TWI_voidWriteMasterDataByte(Copy_pu8Array[i]);  // Write Data Byte by Master in a Loop
    }

    TWI_voidSendStopCondition();  // Send Stop Condition
    _delay_ms(5);  // Delay for EEPROM write cycle completion
}

void EEPROM_voidReadByte(u16 Copy_u16WordAddress, u8 *Copy_pu8RxData) {
    if (Copy_pu8RxData != NULL) {
        u8 local_u8Address = (Copy_u16WordAddress >> 8) | EEPROM_FIXED_ADDRESS;  // Calculate the actual EEPROM address
        TWI_voidSendStartCondition();  // Send Start Condition
        TWI_voidSendSlaveAddWithWrite(local_u8Address);  // Send Slave Address with Write Operation
        TWI_voidWriteMasterDataByte((u8)Copy_u16WordAddress);  // Write Data Byte by Master for Word Address
        TWI_voidSendRepStartCondition();  // Send Repeated Start Condition
        TWI_voidSendSlaveAddWithRead(local_u8Address);  // Send Slave Address with Read Operation
        TWI_voidReadMasterDataByte_With_NACK(Copy_pu8RxData);  // Read Data Byte by Master with NACK
        TWI_voidSendStopCondition();  // Send Stop Condition
        _delay_ms(5);  // Delay for EEPROM read cycle completion
    }
}

void EEPROM_voidSequentialRead(u16 Copy_u16WordAddress, u8 *Copy_pu8RxData, u8 Copy_arraySize) {
    if (Copy_pu8RxData != NULL) {
        u8 i = 0;
        u8 local_u8Address = (Copy_u16WordAddress >> 8) | EEPROM_FIXED_ADDRESS;  // Calculate the actual EEPROM address
        TWI_voidSendStartCondition();  // Send Start Condition
        TWI_voidSendSlaveAddWithWrite(local_u8Address);  // Send Slave Address with Write Operation
        TWI_voidWriteMasterDataByte((u8)Copy_u16WordAddress);  // Write Data Byte by Master for Word Address
        TWI_voidSendRepStartCondition();  // Send Repeated Start Condition
        TWI_voidSendSlaveAddWithRead(local_u8Address);  // Send Slave Address with Read Operation
        for (i = 0; i < Copy_arraySize - 1; i++) {
            TWI_voidReadMasterDataByte_With_ACK(Copy_pu8RxData + i);  // Read Data Byte by Master with ACK
        }
        TWI_voidReadMasterDataByte_With_NACK(&Copy_pu8RxData[Copy_arraySize - 1]);  // Read Data Byte by Master with NACK
        TWI_voidSendStopCondition();  // Send Stop Condition
        _delay_ms(5);  // Delay for EEPROM read cycle completion
    }
}
