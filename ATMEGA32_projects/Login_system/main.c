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
#include "MCAL/TIMERS/TIMER1/includes/TMR1_interface.h"

#include <avr/delay.h>
#include "HAL/LCD/LCD.h"
#include "HAL/KEYPAD/KP_interface.h"

#define PASSWORD 1234

#define LED PB_3
#define BUZ PC_6



int main()
{
    u16 in_pass = 0; // ldr adc
    u8 key = 'T',i = 0, access = 0;

    // mcu pins configurations
    Port_Init(pin_cfg);
    LCD_Init(); // on kpinput
    KP_Init();  // output unit

//while(1)
{
    LCD_PutString("I/P PASSWORD:");
    while (1)
    {
        // get password
        KP_GetKey(&key);
        if ((key != 'T') && (key >= '0') && (key <= '9'))
        {
            LCD_PutChar(key);

            if (in_pass == 0)
                in_pass = key - '0';
            else
                in_pass = in_pass * 10 + (key - '0');

            key = 'T';
        }
        // check password
        if (key == '#')
        {
            i++;
            if (in_pass == PASSWORD)
            {
                access = 1;
                break;
            }
            else
            {
                in_pass = 0;
                LCD_CLR();
                LCD_PutString("Left ");
                LCD_PutInt(3-i);
                LCD_PutString(" trial");
                _delay_ms(1000);
                LCD_CLR();
                LCD_PutString("I/P PASSWORD:");
                if (i == 3)break;
            }
        }
    }

if (access == 1)
{

	SRVM_voidOn(180);

	for(i=5;i>0;i--){
	_delay_ms(1000);
	LCD_CLR();

	LCD_PutString("WELCOME IN");
	LCD_GoTo(2,1);
	LCD_PutString("closes");
	LCD_GoTo(3,1);
	LCD_PutString("in:");
	LCD_PutInt(i);
	}
	SRVM_voidOn(90);
_delay_ms(100);
	//SRVM_voidOff();
	LCD_CLR();
}

else
{
	LCD_CLR();
	LCD_PutString_at_X_Y("SYSTEM LOCKED", 1, 1);
	Dio_WriteChannel(LED, STD_HIGH);
	Dio_WriteChannel(BUZ, STD_HIGH);
	_delay_ms(1000);
	Dio_WriteChannel(BUZ, STD_LOW);
	//LCD_CLR();
}
//_delay_ms(5000);
//in_pass=0;
//i = 0;
//access = 0;
//LCD_CLR();
}

return 0;
}
