/*
 * main.c

 *
 *  Created on: Oct 17, 2023
 *      Author: AhmedAbogabl
 */
// #define F_CPU 16000000UL

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/PORT/PORT.h"
#include "MCAL/PORT/PORT_cnf.h"
#include "MCAL/TIMERS/TIMER0/includes/TMR0_interface.h"
#include "MCAL/ADC/includes/ADC_interface.h"

#include <avr/delay.h>
#include "HAL/LCD/LCD.h"
#include "HAL/KEYPAD/KP_interface.h"

int main()
{
    // mcu pins configurations
    Port_Init(pin_cfg);
    // on kpinput
    LCD_Init();
    // output unit
    KP_Init();
  //  GI_voidEnable();
    // PWM out for led level
    TMR0_voidInit();
    TMR0_voidStart();
    // LDR input
    ADC_Init();

    u8 key = 'T';           // lcd
    u16 LDR_thredshold = 0; // ldr adc
    u16 ADC_readValue = 0, temp = 0;
    // tmr pwm
    u8 PWM_value = 0;
    LCD_PutString("I/P Threshold=");

    // TMR0_voidSetDutyCycleForPWM(90);
    while (1)
    {
        // IP_Thredshold();
        KP_GetKey(&key);

        if ((key != 'T') && (key >= '0') && (key <= '9'))
        {
            LCD_PutChar(key);

            if (LDR_thredshold == 0)
                LDR_thredshold = key - '0';
            else
                LDR_thredshold = LDR_thredshold * 10 + (key - '0');

            key = 'T';
        }
        if (key == '#')
            break;
    }

    LCD_CLR();
    LCD_PutString_at_X_Y("LDR threshold=", 2, 1);
    LCD_GoTo(3, 8);
    LCD_PutInt(LDR_thredshold);
    _delay_ms(2000);


    //ADC read value check thredshol
    while (1)
    {
    	//for stable LCD limit the update in case of noisey changes in range of 10
        while (temp / 10 == ADC_ReadChannel(ADC0) / 10);
        ADC_readValue = ADC_ReadChannel(ADC0);  //read adc
        temp = ADC_readValue;//keep current value for later check if changed that will limit working the lcd if not necessery

        //check threshold
        if (ADC_readValue >= LDR_thredshold)
        {//set led intensity based on the lighting around
            PWM_value = (u16)((ADC_readValue / 1024.0) * 100);
            TMR0_voidSetDutyCycleForPWM(PWM_value);
        }//shutdown the pwm if under limit
        else if (ADC_readValue < LDR_thredshold)
        {
            TMR0_voidSetDutyCycleForPWM(0);
        }
        //put the ADC value on the lcd
        LCD_CLR();
        LCD_PutString("LDR:");
        LCD_PutInt(ADC_readValue);
        _delay_ms(10);
    }

    return 0;
}
