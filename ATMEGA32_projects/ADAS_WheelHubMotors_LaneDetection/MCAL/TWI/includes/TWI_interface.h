/*
 * TWI_interface.h
 *
 *  Created on: Oct 31, 2023
 *      Author: AhmedAbogabl
 */

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

#include "../../../utils/STD_TYPES.h"

/* I2C Master Operations */

/**
 * @brief Initialize I2C Master with a provided address.
 *
 * @param Copy_u8Add: I2C Master address to be set.
 */
void TWI_voidInitMaster(u8 Copy_u8Add);

/**
 * @brief Send the Start condition in I2C communication.
 */
void TWI_voidSendStartCondition(void);

/**
 * @brief Send a repeated Start condition in I2C communication.
 */
void TWI_voidSendRepStartCondition(void);

/**
 * @brief Send the Stop condition in I2C communication.
 */
void TWI_voidSendStopCondition(void);

/**
 * @brief Send the slave address in Write mode in I2C communication.
 *
 * @param Copy_u8Add: Slave address to write.
 */
void TWI_voidSendSlaveAddWithWrite(u8 Copy_u8Add);

/**
 * @brief Send the slave address in Read mode in I2C communication.
 *
 * @param Copy_u8Add: Slave address to read.
 */
void TWI_voidSendSlaveAddWithRead(u8 Copy_u8Add);

/**
 * @brief Write a data byte by the I2C Master.
 *
 * @param Copy_u8TxData: Data byte to be transmitted.
 */
void TWI_voidWriteMasterDataByte(u8 Copy_u8TxData);




/**
 * @brief Read a data byte by the I2C Master with ACK.
 *
 * @param Copy_pu8RxData: Pointer to store the received byte.
 */
void TWI_voidReadMasterDataByte_With_ACK(u8* Copy_pu8RxData);

/**
 * @brief Read a data byte by the I2C Master with NACK.
 *
 * @param Copy_pu8RxData: Pointer to store the received byte.
 */
void TWI_voidReadMasterDataByte_With_NACK(u8* Copy_pu8RxData);

#endif /* TWI_INTERFACE_H_ */
