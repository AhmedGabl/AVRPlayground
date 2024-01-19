/*
 * HICU_interface.h
 *
 *  Created on: Nov 13, 2023
 *      Author: AhmedAbogabl
 */

#ifndef MCAL_HICU_INCLUDES_HICU_INTERFACE_H_
#define MCAL_HICU_INCLUDES_HICU_INTERFACE_H_

#include "../../../utils/STD_TYPES.h"


#define ICU_FALLING_EDGE 1
#define ICU_RISING_EDGE 2

#define ICU_STARTING_EDGE ICU_FALLING_EDGE

void ICU_voidInit(void);
void ICU_voidStart(void);

void ICU_voidGetDutyCycle(u8* copy_pu8Duty);

void ICU_voidGetFrequency(u32* copy_pu32Frequency_hz);

#endif /* MCAL_HICU_INCLUDES_HICU_INTERFACE_H_ */
