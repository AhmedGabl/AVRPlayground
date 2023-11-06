/*
 * GI__program.c
 *
 * Created on: Oct 22, 2023
 * Author: AhmedAbogabl
 */

#include "GI_interface.h" // Include the interface for global interrupt control
#include "GI_register.h"  // Include the register definitions for global interrupt control
#include "../../utils/BIT_MATH.h" // Include bit manipulation macros
#include "../../utils/STD_TYPES.h"  // Include standard data types

// Function to enable global interrupts
void GI_voidEnable(void)
{
    SET_BIT(SREG, GLE); // Set the Global Interrupt Enable (GIE) bit in the Status Register (SREG)
}

// Function to disable global interrupts
void GI_voidDisable(void)
{
    CLR_BIT(SREG, GLE); // Clear the Global Interrupt Enable (GIE) bit in the Status Register (SREG)
}
