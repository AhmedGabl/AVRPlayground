/*
 * UART_register.h
 *
 *  Created on: Oct 28, 2023
 *      Author: AhmedAbogabl
 */

#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_
// Define your own registers and bits
#define UBRRL  (*(volatile unsigned char*) 0x29)
//#define UBRRH  (*(volatile unsigned char*) 0xC5)
#define UCSRA  (*(volatile unsigned char*) 0x2B)
#define UCSRB  (*(volatile unsigned char*) 0x2A)
#define UCSRC  (*(volatile unsigned char*) 0x40)
#define UDR    (*(volatile unsigned char*) 0x2C)

// UCSRA bits
#define RXC    7  // Receive Complete
#define TXC    6  // Transmit Complete
#define UDRE   5  // USART Data Register Empty
#define FE     4  // Frame Error
#define DOR    3  // Data OverRun
#define PE     2  // Parity Error
#define U2X    1  // Double the USART Transmission Speed
#define MPCM   0  // Multi-processor Communication Mode

// UCSRB bits
#define RXCIE  7  // RX Complete Interrupt Enable
#define TXCIE  6  // TX Complete Interrupt Enable
#define UDRIE  5  // USART Data Register Empty Interrupt Enable
#define RXEN   4  // Receiver Enable
#define TXEN   3  // Transmitter Enable
#define UCSZ2  2  // Character Size
#define RXB8   1  // Receive Data Bit 8
#define TXB8   0  // Transmit Data Bit 8

// UCSRC bits
#define URSEL  7  // Register Select
#define UMSEL  6  // USART Mode Select
#define UPM1   5  // Parity Mode Bit 1
#define UPM0   4  // Parity Mode Bit 0
#define USBS   3  // Stop Bit Select
#define UCSZ1  2  // Character Size
#define UCSZ0  1  // Character Size
#define UCPOL  0  // Clock Polarity


#endif /* UART_REGISTER_H_ */
