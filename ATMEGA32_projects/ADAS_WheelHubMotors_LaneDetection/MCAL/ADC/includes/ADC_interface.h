/*
 * ADC_interface.h
 *
 * Created on: Oct 27, 2023
 * Author: AhmedAbogabl
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "../../../utils/BIT_MATH.h"  // Include a bit manipulation library
#include "../../../utils/STD_TYPES.h"  // Include standard data type definitions
#include "../includes/ADC_register.h"
#include "../includes/ADC_config.h"

typedef enum{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7
}ADC_SingleEndedChannelSelect;


// Function to initialize the ADC module
void ADC_Init(void);

// Function to read an analog channel and return the ADC result
u16 ADC_ReadChannel(u8 channel);

#endif /* ADC_INTERFACE_H_ */
