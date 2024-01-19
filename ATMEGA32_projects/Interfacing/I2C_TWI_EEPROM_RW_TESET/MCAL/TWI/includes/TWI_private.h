/*
 * TWI_private.h
 *
 *  Created on: Oct 31, 2023
 *      Author: AhmedAbogabl
 */

#ifndef MCAL_TWI_INCLUDES_TWI_PRIVATE_H_
#define MCAL_TWI_INCLUDES_TWI_PRIVATE_H_

// Control and Status Register Bits
#define TWI_STATUS_VALUE                 (TWSR & 0xF8)  // Extracting the status bits

// I2C Status codes
#define TWI_START_CONDITION_ACK          0x08  // Start condition has been transmitted
#define TWI_REPEATED_START_CONDITION_ACK 0x10  // Repeated start condition has been transmitted
#define TWI_SLAVE_ADDRESS_WRITE_ACK      0x18  // SLA+W has been transmitted, ACK received
#define TWI_SLAVE_ADDRESS_READ_ACK       0x40  // SLA+R has been transmitted, ACK received
#define TWI_MASTER_DATA_TRANSMIT_ACK     0x28  // Data byte has been transmitted in master transmitter mode, ACK received
#define TWI_MASTER_DATA_RECIEVE_ACK      0x50  // Data byte has been received in master receiver mode, ACK transmitted
#define TWI_MASTER_DATA_RECIEVE_NACK     0x58  // Data byte has been received in master receiver mode, NACK transmitted

#endif /* MCAL_TWI_INCLUDES_TWI_PRIVATE_H_ */
