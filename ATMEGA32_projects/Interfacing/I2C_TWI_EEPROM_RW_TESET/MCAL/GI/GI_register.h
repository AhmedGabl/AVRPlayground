/*
 * GI_register.h
 *
 * Created on: Oct 22, 2023
 * Author: AhmedAbogabl
 */

#ifndef MCAL_GI_GI_REGISTER_H_
#define MCAL_GI_GI_REGISTER_H_

// Define the General Interrupt Control Register (SREG) and its bit number for enabling global interrupts
#define SREG *((volatile unsigned char *)0x5F) // Define SREG at memory address 0x5F
#define GLE 7 // Define the bit number for the Global Interrupt Enable (GIE) bit

#endif /* MCAL_GI_GI_REGISTER_H_ */
