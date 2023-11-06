/*
 * GI_interface.h
 *
 * Created on: Oct 22, 2023
 * Author: AhmedAbogabl
 */

#ifndef MCAL_GI_GI_INTERFACE_H_
#define MCAL_GI_GI_INTERFACE_H_

#include "GI_register.h" // Include the register definitions for the General Interrupts

#include "../../utils/BIT_MATH.h"
#include "../../utils/STD_TYPES.h"

// Function prototypes for global interrupt control
void GI_voidEnable(void);  // Function to enable global interrupts
void GI_voidDisable(void); // Function to disable global interrupts

#endif /* MCAL_GI_GI_INTERFACE_H_ */
