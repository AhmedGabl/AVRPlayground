/*
 * EXTI_register.h
 *
 * Created on: Oct 22, 2023
 * Author: AhmedAbogabl
 */

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

// General Interrupt Control Register (GICR)
#define GICR *((volatile unsigned char *)0x5B)

// Bit positions for external interrupts
#define INT1 7  // External Interrupt 1
#define INT0 6  // External Interrupt 0
#define INT2 5  // External Interrupt 2

// General Interrupt Flag Register (GIFR)
#define GIFR *((volatile unsigned char *)0x5A)

// Bit positions for external interrupt flags
#define INTF1 7  // External Interrupt 1 Flag
#define INTF0 6  // External Interrupt 0 Flag
#define INTF2 5  // External Interrupt 2 Flag

// MCU Control Register (MCUCR)
#define MCUCR *((volatile unsigned char *)0x55)

// Bit positions for interrupt sense control for INT0 and INT1
#define ISC00 0  // INT0 Sense Control Bit 0
#define ISC01 1  // INT0 Sense Control Bit 1
#define ISC10 2  // INT1 Sense Control Bit 0
#define ISC11 3  // INT1 Sense Control Bit 1

// MCU Control and Status Register (MCUCSR)
#define MCUCSR *((volatile unsigned char *)0x54)

// Bit position for interrupt sense control for INT2
#define ISC2 6  // INT2 Sense Control

#endif /* MCAL_EXTI_EXTI_REGISTER_H_ */
