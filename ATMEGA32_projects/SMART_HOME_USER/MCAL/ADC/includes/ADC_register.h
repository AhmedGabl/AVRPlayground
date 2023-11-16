/*
 * ADC_register.h
 *
 * Created on: Oct 27, 2023
 * Author: AhmedAbogabl
 */

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

// ADC Multiplexer Selection Register (ADMUX) - Address 0x27
#define ADMUX   *((volatile unsigned char *)0x27)

#define REFS1  7   // Reference Voltage Selection Bit 1
#define REFS0  6   // Reference Voltage Selection Bit 0
#define ADLAR  5   // ADC Left Adjust Result
#define MUX4   4   // Analog Channel Selection Bit 4
#define MUX3   3   // Analog Channel Selection Bit 3
#define MUX2   2   // Analog Channel Selection Bit 2
#define MUX1   1   // Analog Channel Selection Bit 1
#define MUX0   0   // Analog Channel Selection Bit 0

// ADC Control and Status Register A (ADCSRA) - Address 0x26
#define ADCSRA   *((volatile unsigned char *)0x26)

#define ADEN    7   // ADC Enable
#define ADSC    6   // ADC Start Conversion
#define ADATE   5   // ADC Auto Trigger Enable
#define ADIF    4   // ADC Interrupt Flag
#define ADIE    3   // ADC Interrupt Enable
#define ADPS2   2   // ADC Prescaler Bit 2
#define ADPS1   1   // ADC Prescaler Bit 1
#define ADPS0   0   // ADC Prescaler Bit 0

// ADC Data Register High (ADCH) - Address 0x25
#define ADCH   *((volatile unsigned char *)0x25)
// ADC Data Register Low (ADCL) - Address 0x24
#define ADCL   *((volatile unsigned char *)0x24)

#endif /* ADC_REGISTER_H_ */

