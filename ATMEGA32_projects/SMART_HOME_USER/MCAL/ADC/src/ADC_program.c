/*
 * ADC_program.c
 *
 * Created on: Oct 27, 2023
 * Author: AhmedAbogabl
 */

#include "../includes/ADC_interface.h"  // Include the ADC interface header file
#include <avr/io.h>         // Include AVR I/O definitions
#include "../../DIO/DIO_interface.h"
void ADC_Init(void) {
	// Set reference voltage to AVCC with external capacitor at AREF pin
#if ADC_AREF_MODE == ADC_AREF
	CLR_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);
#elif ADC_AREF_MODE == ADC_AVCC
	SET_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);
#elif ADC_AREF_MODE == ADC_INTERNAL_VREF_WITH_EXTERNAL_CAP_AT_AREF
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
#endif

//	ADMUX = (1 << REFS0);

#if 	ADC_RESULT_ADJUSTMENT_MODE ==ADC_LEFT_ADJUST_THE_RESULT
	SET_BIT(ADMUX,ADLAR);
#elif 	ADC_RESULT_ADJUSTMENT_MODE ==ADC_RIGHT_ADJUST_THE_RESULT
	CLR_BIT(ADMUX,ADLAR);
#endif


    // Enable the ADC and configure the ADC prescaler (clock division factor)

    // Set ADC prescaler
#if ADC_PRESCALER_MODE == ADC_PRESCALER_2
    //SET_BIT(ADCSRA,ADPS0);
    CLR_BIT(ADCSRA,ADPS1);
    CLR_BIT(ADCSRA,ADPS2);
#elif ADC_PRESCALER_MODE == ADC_PRESCALER_4
    CLR_BIT(ADCSRA,ADPS0);
    SET_BIT(ADCSRA,ADPS1);
    CLR_BIT(ADCSRA,ADPS2);
#elif ADC_PRESCALER_MODE == ADC_PRESCALER_8
    SET_BIT(ADCSRA,ADPS0);
    SET_BIT(ADCSRA,ADPS1);
    CLR_BIT(ADCSRA,ADPS2);
#elif ADC_PRESCALER_MODE == ADC_PRESCALER_16
    CLR_BIT(ADCSRA,ADPS0);
    CLR_BIT(ADCSRA,ADPS1);
    SET_BIT(ADCSRA,ADPS2);
#elif ADC_PRESCALER_MODE == ADC_PRESCALER_32
    SET_BIT(ADCSRA,ADPS0);
    CLR_BIT(ADCSRA,ADPS1);
    SET_BIT(ADCSRA,ADPS2);
#elif ADC_PRESCALER_MODE == ADC_PRESCALER_64
    CLR_BIT(ADCSRA,ADPS0);
    SET_BIT(ADCSRA,ADPS1);
    SET_BIT(ADCSRA,ADPS2);
#elif ADC_PRESCALER_MODE == ADC_PRESCALER_128
    SET_BIT(ADCSRA,ADPS0);
    SET_BIT(ADCSRA,ADPS1);
    SET_BIT(ADCSRA,ADPS2);
#endif

    // Enable the ADC
   	     SET_BIT(ADCSRA,ADEN);
    //    ADCSRA |= (1 << ADPS2) | (1 << ADPS1);
//	SFIOR = (0 << ADTS2) | (0 << ADTS1) | (0 << ADTS0);

}

u16 ADC_ReadChannel(u8 channel) {
	u16 result=0;
	// Select the ADC channel           0x00000111
                //    0x1111 1000
	ADMUX = (ADMUX & 0xF8) | (channel & 0x07);

    // Start the conversion
    SET_BIT(ADCSRA,ADSC);
   // ADCSRA |= (1 << ADSC);

    // Wait for the conversion to complete
    while (ADCSRA & (1 << ADSC));

#if ADC_RESULT_ADJUSTMENT_MODE == ADC_LEFT_ADJUST_THE_RESULT
    // Return the ADC result as a 16-bit value (combining ADCL and ADCH)
    result=(ADCL>>6);
    result|=(ADCH<<2);

//    result = (ADCH<<8) | ADCL;
//    result= (result>>6);
#elif ADC_RESULT_ADJUSTMENT_MODE == ADC_RIGHT_ADJUST_THE_RESULT
    // Return the ADC result as a 16-bit value (combining ADCL and ADCH)
  result = ADCL;
  result|=(ADCH << 8);
    // result = (ADCH<<8) | ADCL;
    #endif
    return result;
}
