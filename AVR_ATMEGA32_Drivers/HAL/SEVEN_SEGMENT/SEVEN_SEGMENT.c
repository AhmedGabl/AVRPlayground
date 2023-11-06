/*
 * SEVEN_SEGMENT.c
 *
 * Created on: Oct 21, 2023
 * Author: AhmedAbogabl
 */

#include "SEVEN_SEGMENT.h"
#include <avr/io.h>
#include <util/delay.h> // Utilize _delay_ms from the util library

// Function to enable a specific seven-segment display segment
void SevenSeg_SegEnable(SegNumber seg) {
    // Disable all segments
    Dio_WriteChannel(SEG_1, 1);
    Dio_WriteChannel(SEG_2, 1);
    Dio_WriteChannel(SEG_3, 1);
    Dio_WriteChannel(SEG_4, 1);

    // Enable the specified segment
    switch (seg) {
        case SEG_1:
            Dio_WriteChannel(SEG_1, 0);
            break;
        case SEG_2:
            Dio_WriteChannel(SEG_2, 0);
            break;
        case SEG_3:
            Dio_WriteChannel(SEG_3, 0);
            break;
        case SEG_4:
            Dio_WriteChannel(SEG_4, 0);
            break;
    }
}

// Function to send four numbers to the four seven-segment displays
void SevenSeg_Send(u8 num1, u8 num2, u8 num3, u8 num4) {
    SevenSeg_SegEnable(SEG_1);
    SevenSeg_SendOneSeg(num1);
    _delay_ms(100);

    SevenSeg_SegEnable(SEG_2);
    SevenSeg_SendOneSeg(num2);
    _delay_ms(100);

    SevenSeg_SegEnable(SEG_3);
    SevenSeg_SendOneSeg(num3);
    _delay_ms(100);

    SevenSeg_SegEnable(SEG_4);
    SevenSeg_SendOneSeg(num4);
    _delay_ms(100);
}

// Function to send a single number to the current seven-segment display
void SevenSeg_SendOneSeg(u8 number) {
    Dio_WriteChannel(PB_0, GET_BIT(number, 0));
    Dio_WriteChannel(PB_1, GET_BIT(number, 1));
    Dio_WriteChannel(PB_2, GET_BIT(number, 2));
    Dio_WriteChannel(PB_4, GET_BIT(number, 3));
}
