/*
 * ADAS_APP.c
 * Description: Source file for the ADAS application.
 * Author: AhmedAbogabl
 * Created on: Dec 13, 2023
 */

#include "../utils/BIT_MATH.h"
#include "../utils/STD_TYPES.h"
#include "util/delay.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/PORT/PORT.h"
#include "../MCAL/GI/GI_interface.h"

#include "../HAL/BLUETOOTH/BT_interface.h"  // UART
#include "../HAL/WHM/WHM_interface.h"      // Timer 0

#include "ADAS_APP.h"

/*
 * Global Variables
 */
u8 VEHICLE_state = LOCKED;

u8 ButtonState = 1;
u8 Lane_Asses = 0;
u8 BT_read_vlaue = 0;

u8 VehicleAccess = FALSE;

/*
 * Function: HW_init
 * Description: Initialize hardware components.
 */
void HW_init(void) {
    Port_Init(pin_cfg);
   // ADC_Init(); // Pin 0 and 1 if needed for autopark

    BT_Init(BT);
    MOTOR_voidInit();

    GI_voidEnable();
    SPI_voidInit();

    // Pull-up configuration
    Dio_WriteChannel(PC_0, STD_HIGH);
    Dio_WriteChannel(PC_1, STD_HIGH);
}

u8 FunctionToACtivate = FALSE;
u8 Functoin_Type = 0;

/*
 * Function: BT
 * Description: Bluetooth function handling received data.
 */
void BT(u8 Rxdata) {
    BT_read_vlaue = Rxdata;
    if((BT_read_vlaue == 'U') && (VEHICLE_state == LOCKED)) {
        VehicleAccess = TRUE;
        BT_CTL_Options();
    } else if((BT_read_vlaue == 'O') || (BT_read_vlaue == 'I')) {
        Functoin_Type = BT_read_vlaue;
        if(BT_read_vlaue == 'O') {
            UART_TransmitString("Obstacle Avoidance Activated\r\n");
        } else if(BT_read_vlaue == 'I') {
            UART_TransmitString("Auto Parking Activated\r\n");
        } else {
            // Handle other cases if needed
        }
        FunctionToACtivate = TRUE;
    } else {
        ButtonState = 0;
    }
}

/*
 * Function: WHM
 * Description: Main control logic for the automotive ECU.
 */
void WHM(void) {
    static u8 speed = 60;

    if (ButtonState == 0) {
        Lane_Asses = 0;

        switch (BT_read_vlaue) {
            case 'W':
                MOTOR_voidOn(SPEED_MOTOR, MOTOR_CW);
                MOTOR_voidControlSpeed(SPEED_MOTOR, speed);
                ButtonState = 1;
                break;
            case 'S':
                MOTOR_voidOn(SPEED_MOTOR, MOTOR_CCW);
                MOTOR_voidControlSpeed(SPEED_MOTOR, speed);
                ButtonState = 1;
                break;
            case 'D':
                MOTOR_voidOn(STEERING_MOTOR, MOTOR_CW);
                ButtonState = 1;
                break;
            case 'A':
                MOTOR_voidOn(STEERING_MOTOR, MOTOR_CCW);
                ButtonState = 1;
                break;
            case 'P':
                MOTOR_voidOff(SPEED_MOTOR);
                ButtonState = 1;
                break;
            case 'K':
                MOTOR_voidOff(STEERING_MOTOR);
                ButtonState = 1;
                break;
            case 'L':
                Lane_Asses = 1;
                ButtonState = 1;
                UART_TransmitString("Lane assistant Activated\r\n");
                break;
            default:
                if ((BT_read_vlaue >= '0') && (BT_read_vlaue <= '9')) {
                    speed = (BT_read_vlaue - '0') * 10;
                    MOTOR_voidControlSpeed(SPEED_MOTOR, speed);
                } else {
                    // Handle other cases if needed
                }
                ButtonState = 1;
                break;
        }
    } else if (Lane_Asses == 1) {
        LaneAssist(speed);
    }
}

/*
 * Function: LaneAssist
 * Description: Implement Lane Assist logic based on sensor inputs.
 */
void LaneAssist(u8 Copy_u8NormalSpeed) {
    if ((Dio_ReadChannel(R_S) == 0) && (Dio_ReadChannel(L_S) == 0)) {
        MOTOR_voidOn(SPEED_MOTOR, MOTOR_CW);
        MOTOR_voidOff(STEERING_MOTOR);
        MOTOR_voidControlSpeed(SPEED_MOTOR, Copy_u8NormalSpeed);
    } else if ((Dio_ReadChannel(R_S) == 0) && (Dio_ReadChannel(L_S) == 1)) {
        MOTOR_voidOn(STEERING_MOTOR, MOTOR_CCW);
    } else if ((Dio_ReadChannel(R_S) == 1) && (Dio_ReadChannel(L_S) == 0)) {
        MOTOR_voidOn(STEERING_MOTOR, MOTOR_CW);
    } else if ((Dio_ReadChannel(R_S) == 1) && (Dio_ReadChannel(L_S) == 1)) {
        MOTOR_voidOff(STEERING_MOTOR);
        MOTOR_voidOff(SPEED_MOTOR);
    }
}
