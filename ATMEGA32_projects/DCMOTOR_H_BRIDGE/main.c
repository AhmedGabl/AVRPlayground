/*
 * main.c
 * Description: Control a DC motor using H-Bridge through TIMER0 for speed control
 * Author: AhmedAbogabl
 * Date: Oct 17, 2023
 */

#include "MCAL/PORT/PORT.h"
#include <util/delay.h>
#include "MCAL/TIMERS/TIMER0/includes/TMR0_interface.h"
#include "HAL/DC_MOTOR_H_BRIDGE/DCM_interface.h"

int main() {
    Port_Init(pin_cfg);
    TMR0_voidInit();

    u8 speed = 0;
    while (1) {
        // Rotate the motor in Counter Clockwise (CCW) direction
        DCM_voidOn(DCM_CCW);
        // Increase speed gradually up to 100
        while (speed <= 100) {
            DCM_voidControlSpeed(speed); // Control the motor speed
            _delay_ms(50);               // Delay
            speed++;                     // Increment speed
        }

        speed = 0; // Reset speed
        _delay_ms(200);

        // Rotate the motor in Clockwise (CW) direction
        DCM_voidOn(DCM_CW);

        // Increase speed gradually up to 100
        while (speed <= 100) {
            DCM_voidControlSpeed(speed); // Control the motor speed
            _delay_ms(50);
            speed++;                     // Increment speed
        }

        // Turn off the motor and wait for 3 seconds
        _delay_ms(50);
        DCM_voidOff();   // Turn off the motor
        _delay_ms(3000); // Delay for 3 seconds
        speed = 0;       // Reset speed
    }

    return 0;
}
