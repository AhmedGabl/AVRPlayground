/*
 * SPI_register.h
 *
 *  Created on: Oct 30, 2023
 *      Author: AhmedAbogabl
 */

#include "../includes/SPI_interface.h"
#include "../includes/SPI_registers.h"
#include "../includes/SPI_config.h"

// Function pointer to store the callback function for asynchronous SPI communication
static void (*private_pCallBackSPI)(u8) = NULL;

// Function to initialize the SPI module
void SPI_voidInit(void){

    // Select master or slave based on SPI_MODE configuration
    #if SPI_MODE == SPI_MASTER
        SET_BIT(SPI->SPCR, MSTR);

        // Set frequency to 1 MHz (only master selects the clock)
        SET_BIT(SPI->SPCR, SPR0);
        CLR_BIT(SPI->SPCR, SPR1);
        CLR_BIT(SPI->SPSR, SPI2X);

    #elif SPI_MODE == SPI_SLAVE
        CLR_BIT(SPI->SPCR, MSTR);
    #endif

    // Select LSB first
    SET_BIT(SPI->SPCR, DORD);

    // Select clock polarity (CPOL) falling edge, and clock phase (CPHA) rising edge sample
    SET_BIT(SPI->SPCR, CPOL);
    SET_BIT(SPI->SPCR, CPHA);

    // Enable SPI
    SET_BIT(SPI->SPCR, SPE);
}

// Function to transmit and receive data synchronously
void SPI_voidTransceive(u8 copy_u8TXdata, u8* copy_pu8_RXdata){

    if(copy_pu8_RXdata != NULL){
        // Wait for the write collision flag to be clear
        while(1 == GET_BIT(SPI->SPSR, WCOL));

        // Send data
        SPI->SPDR = copy_u8TXdata;

        // Wait for the SPIF flag to be set (data received)
        while(0 == GET_BIT(SPI->SPSR, SPIF));

        // Read received data
        *copy_pu8_RXdata =  SPI->SPDR;
    }
}

// Function to transmit data asynchronously with a callback function
void SPI_voidTransmitAsynchronous(u8 copy_u8TxData, void(*ptrToFun)(u8 copy_u8RxData)){
    if(ptrToFun != NULL)
    {
        // Enable SPI Interrupt
        SET_BIT(SPI->SPCR, SPIE);

        // Set the callback function
        private_pCallBackSPI = ptrToFun ;

        // Check for collision
        while(1 == GET_BIT(SPI->SPSR, WCOL));

        // Send data
        SPI->SPDR = copy_u8TxData;
    }
}

// ISR (Interrupt Service Routine) for SPI communication
void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{
    // Check if the callback function is assigned
    if (private_pCallBackSPI != NULL) {
        // Call the callback function with the received data
        private_pCallBackSPI(SPI->SPDR);
    }
}
