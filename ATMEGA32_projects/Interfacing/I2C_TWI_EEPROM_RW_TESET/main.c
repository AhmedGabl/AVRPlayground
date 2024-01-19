/*
 * main.c
 *
 *  Created on: Oct 17, 2023
 *      Author: AhmedAbogabl
 */

// Include necessary header files
#include <avr/delay.h>
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/PORT/PORT.h"
#include "MCAL/SPI/includes/SPI_interface.h"
#include "MCAL/GI/GI_interface.h"
#include "MCAL/TWI/includes/TWI_interface.h"
#include "HAL/EEPROM/EEPROM_interface.h"
#include "HAL/LCD/LCD.h"
#include "string.h"

#define main1 main

int main1() {
    // Initialize ports and LCD
    Port_Init(pin_cfg);
    LCD_Init();
    EEPROM_voidInit();

    // Define variables
    u16 localcal_data;
    char name[] = { '1', '2', '3', '4', '5' };
    char name2[5];
    char na = 'N';

    // Write data to an EEPROM page
    EEPROM_voidWritePage(0x50, name, 5); // Write '12345' to EEPROM address 0x50

    // Display the content of the EEPROM on an LCD
    LCD_PutString("Read second byte: ");
    EEPROM_voidReadByte(0x50 + 1, &na); // Read the second byte at address 0x51
    LCD_PutChar(na);

    LCD_GoTo(2, 1);
    LCD_PutString("Read Page: ");
    EEPROM_voidSequentialRead(0x50, name2, 5); // Read a page of data starting at address 0x50
    name2[4] = '\0'; // Null-terminate the string
    LCD_PutString(name2);

    // Main loop
    while (1) {
        // Your main program logic can go here
    }

    return 0;
}
