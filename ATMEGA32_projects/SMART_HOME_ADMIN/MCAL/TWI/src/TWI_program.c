/*
 * TWI_program.c
 *
 *  Created on: Oct 31, 2023
 *      Author: AhmedAbogabl
 */

#include "../includes/TWI_config.h"
#include "../includes/TWI_interface.h"
#include "../includes/TWI_private.h"
#include "../includes/TWI_registers.h"
#include "../../../utils/STD_TYPES.h"
#include "../../../utils/BIT_MATH.h"

// Initialize I2C Master with provided address
void TWI_voidInitMaster(u8 Copy_u8Add) {
    if ((128 > Copy_u8Add) && (0 < Copy_u8Add)) {
        TWAR = (Copy_u8Add << 1);
    }
        // Set frequency > 400kHz, set prescaler
        TWBR = 12;
        CLR_BIT(TWSR, TWPS0);
        CLR_BIT(TWSR, TWPS1);

        // Enable ACKs for I2C response and generate internal status code
   //     SET_BIT(TWCR, TWEA);
        // Enable I2C
        SET_BIT(TWCR, TWEN);
}

// Send Start Condition
void TWI_voidSendStartCondition(void) {
    // Start condition
    SET_BIT(TWCR, TWSTA);
    // Clear flag
    SET_BIT(TWCR, TWINT);
    // Busy wait for the flag
    while (0 == GET_BIT(TWCR, TWINT));
    // Check for ACK == Start Condition ACK
    while (TWI_STATUS_VALUE != TWI_START_CONDITION_ACK);
}

// Send Repeated Start Condition
void TWI_voidSendRepStartCondition(void) {
    // Start condition
    SET_BIT(TWCR, TWSTA);
    // Clear flag
    SET_BIT(TWCR, TWINT);
    // Busy wait for the flag
    while (0 == GET_BIT(TWCR, TWINT));
    // Check for ACK == Repeated Start Condition ACK
    while (TWI_STATUS_VALUE != TWI_REPEATED_START_CONDITION_ACK);
}

// Send Stop Condition
void TWI_voidSendStopCondition(void) {
    // Request stop condition
    SET_BIT(TWCR, TWSTO);
    // Clear flag to start the current job
    SET_BIT(TWCR, TWINT);
}

// Send Slave Address with Write Operation
void TWI_voidSendSlaveAddWithWrite(u8 Copy_u8Add) {
    if (128 > Copy_u8Add) {
        TWDR = Copy_u8Add << 1;
        // Select write operation
        CLR_BIT(TWDR, 0);

        // Clear start condition
        CLR_BIT(TWCR, TWSTA);
        // Clear flag
        SET_BIT(TWCR, TWINT);
        // Busy wait for the flag
        while (0 == GET_BIT(TWCR, TWINT));
        // Check for ACK == Slave Address Write ACK
        while (TWI_STATUS_VALUE != TWI_SLAVE_ADDRESS_WRITE_ACK);
    }
}

// Send Slave Address with Read Operation
void TWI_voidSendSlaveAddWithRead(u8 Copy_u8Add) {
    if (128 > Copy_u8Add) {
        TWDR = Copy_u8Add << 1;
        // Select read operation
        SET_BIT(TWDR, 0);

        // Clear start condition
        CLR_BIT(TWCR, TWSTA);
        // Clear flag
        SET_BIT(TWCR, TWINT);
        // Busy wait for the flag
        while (0 == GET_BIT(TWCR, TWINT));
        // Check for ACK == Slave Address Read ACK
        while (TWI_STATUS_VALUE != TWI_SLAVE_ADDRESS_READ_ACK);
    }
}

// Write Data Byte by Master
void TWI_voidWriteMasterDataByte(u8 Copy_u8TxData) {
    TWDR = Copy_u8TxData;

    // Set interrupt flag
    SET_BIT(TWCR, TWINT);
    // Busy wait for the flag
    while (0 == GET_BIT(TWCR, TWINT));
    // Check for ACK == Master Data Transmit ACK
    while (TWI_STATUS_VALUE != TWI_MASTER_DATA_TRANSMIT_ACK);
}

// Read Data Byte by Master with ACK
void TWI_voidReadMasterDataByte_With_ACK(u8* Copy_pu8RxData) {
    if (Copy_pu8RxData != NULL) {
        // Set interrupt flag
        SET_BIT(TWCR, TWINT);
        SET_BIT(TWCR, TWEA);  // Set NACK

        // Busy wait for the flag
        while (0 == GET_BIT(TWCR, TWINT));
        // Check for ACK == Master Data Receive ACK
        while (TWI_STATUS_VALUE != TWI_MASTER_DATA_RECIEVE_ACK);

        *Copy_pu8RxData = TWDR;
    }
}

// Read Data Byte by Master with NACK
void TWI_voidReadMasterDataByte_With_NACK(u8* Copy_pu8RxData) {
    if (Copy_pu8RxData != NULL) {
        // Set interrupt flag
        SET_BIT(TWCR, TWINT);
       //
        CLR_BIT(TWCR, TWEA);  // Set NACK
        // Busy wait for the flag
        while (0 == GET_BIT(TWCR, TWINT));
        // Check for NACK == Master Data Receive NACK
        while (TWI_STATUS_VALUE != TWI_MASTER_DATA_RECIEVE_NACK);

        *Copy_pu8RxData = TWDR;
    }
}
