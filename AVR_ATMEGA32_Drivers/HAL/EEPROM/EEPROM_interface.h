/*
 * EEPROM_interface.h
 *
 *  Created on: Oct 31, 2023
 *      Author: AhmedAbogabl
 */

#ifndef HAL_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EEPROM_EEPROM_INTERFACE_H_

/**
 * @brief Initialize EEPROM
 *
 * This function initializes the EEPROM (Electrically Erasable Programmable Read-Only Memory).
 * It configures the necessary parameters for communication.
 */
void EEPROM_voidInit(void);

/**
 * @brief Write a single byte to EEPROM at a specified address
 *
 * @param Copy_u16WordAddress: The word address to write the data to in the EEPROM
 * @param Copy_u8Data: The data byte to be written to the EEPROM
 */
void EEPROM_voidWriteByte(u16 Copy_u16WordAddress, u8 Copy_u8Data);

/**
 * @brief Read a single byte from the EEPROM at a specified address
 *
 * @param Copy_u16WordAddress: The word address to read the data from in the EEPROM
 * @param Copy_pu8RxData: Pointer to a location to store the read byte
 */
void EEPROM_voidReadByte(u16 Copy_u16WordAddress, u8* Copy_pu8RxData);

/**
 * @brief Write a page (multiple bytes) to the EEPROM
 *
 * @param Copy_u16WordAddress: The starting word address to write the array of data in the EEPROM
 * @param Copy_pu8Array: Pointer to an array of data bytes to be written
 * @param Copy_arraySize: The size of the array to be written
 */
void EEPROM_voidWritePage(u16 Copy_u16WordAddress, u8* Copy_pu8Array, u8 Copy_arraySize);

/**
 * @brief Read a page (multiple bytes) from the EEPROM
 *
 * @param Copy_u16WordAddress: The starting word address to read the array of data from the EEPROM
 * @param Copy_pu8RxData: Pointer to a location to store the read data
 * @param Copy_arraySize: The size of the array to be read
 */
void EEPROM_voidSequentialRead(u16 Copy_u16WordAddress, u8* Copy_pu8RxData, u8 Copy_arraySize);

#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
