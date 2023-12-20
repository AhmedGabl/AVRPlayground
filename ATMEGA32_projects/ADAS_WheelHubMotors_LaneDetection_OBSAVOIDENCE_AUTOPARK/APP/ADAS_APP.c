/*
 * ADAS_APP.c
 *
 *  Created on: Dec 13, 2023
 *      Author: AhmedAbogabl
 */



#include "../utils/BIT_MATH.h"
#include "../utils/STD_TYPES.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/PORT/PORT.h"
#include "../MCAL/GI/GI_interface.h"

#include "../HAL/BLUETOOTH/BT_interface.h"//uart
#include "../HAL/WHM/WHM_interface.h"//tmr0

#include "ADAS_APP.h"




/*
 * ** Global Variable *********************************************************************************************************
 * */
//general control
u8 VEHICLE_state = LOCKED;

u8 ButtonState = 1;
u8 Lane_Asses = 0;
u8 BT_read_vlaue = 0;

u8 VehicleAccess = FALSE;


//guard  obstacle avoidence
u8 OBS_Right_Active_State = FALSE;
u8 OBS_LEFT_Active_State = FALSE;

void HW_init(void) {
    Port_Init(pin_cfg);
    BT_Init(BT);
    MOTOR_voidInit();
    GI_voidEnable();
    SPI_voidInit();
    //pull up
    Dio_WriteChannel(PC_0, STD_HIGH);
    Dio_WriteChannel(PC_1, STD_HIGH);
}

void BT(u8 Rxdata) {
    /*Change the State **/
    BT_read_vlaue = Rxdata;
    if((BT_read_vlaue == 'U') && (VEHICLE_state == LOCKED))
    {
    	VehicleAccess = TRUE;
    	BT_CTL_Options();
    }
    else
    {
    	ButtonState = 0;
    }
}

AutoPark();

Avoid_ToRight();

Avoid_ToLeft();


void WHM(void) {
   static  u8 speed = 60;
    /* if the Push Button is Pressed */
    if (ButtonState == 0) {
        Lane_Asses = 0;
        //	BT_read_vlaue = BT_read_vlaue + '0' ;
        switch (BT_read_vlaue) {
        // speed dir options
        case 'W':
          //  LED4();
            MOTOR_voidOn(SPEED_MOTOR, MOTOR_CW);
            UART_TransmitString("inside W \r\n");
            ButtonState = 1;
            break;
        case 'S':
        //    LED5();
            MOTOR_voidOn(SPEED_MOTOR, MOTOR_CCW);
            UART_TransmitString("inside S \r\n");
            ButtonState = 1;
            break;
        // steering direction optinos
        case 'D':
            UART_TransmitString("inside D \r\n");
       //     LED6();
            MOTOR_voidOn(STEERING_MOTOR, MOTOR_CW);
            ButtonState = 1;
            break;
        case 'A':
            UART_TransmitString("inside A \r\n");
         //   LED6();
            MOTOR_voidOn(STEERING_MOTOR, MOTOR_CCW);
            ButtonState = 1;
            break;
        // stop speed
        case 'P':
            MOTOR_voidOff(SPEED_MOTOR);
            UART_TransmitString("inside p \r\n");
            ButtonState = 1;
            break;
        // stopsteering
        case 'K'://direct
            MOTOR_voidOff(STEERING_MOTOR);
            UART_TransmitString("inside k \r\n");
            ButtonState = 1;
            break;
        // lane assistence option
        case 'L':
            Lane_Asses = 1;
            ButtonState = 1;
            UART_TransmitString("inside L \r\n");
            break;

            /*/
            * ARABI FUNCTIONS
            */

            ///autopark
        case 'I':
        	UART_TransmitString("inside Q \r\n");
        	AutoPark();
        	ButtonState = 1;
            break;

        case 'O':
        	UART_TransmitString("inside O \r\n");
        	OBS_Right_Active_State = TRUE ;
        	Lane_Asses = 1;

        	//Avoid_ToRight();
             ButtonState = 1;
            break;
        case 'Q':
            UART_TransmitString("inside Q \r\n");
            OBS_LEFT_Active_State =TRUE;
            Lane_Asses =1;
//            Avoid_ToLeft();
            ButtonState = 1;
            break;
        default:
            if ((BT_read_vlaue >= '0') && (BT_read_vlaue <= '9')) {
                speed = (BT_read_vlaue - '0') * 10;
                if((speed < 60) && (speed != 0)) speed = 60 ;
                MOTOR_voidControlSpeed(SPEED_MOTOR, speed);
            } else {
                MOTOR_voidOff(STEERING_MOTOR);
                MOTOR_voidOff(SPEED_MOTOR);
            }
            ButtonState = 1;
            UART_TransmitString("inside default \r\n");
            break;
        }
    } else if (Lane_Asses == 1)
    {
    	LaneAssist(speed);
    	   if(OBS_LEFT_Active_State == TRUE)
    	   {

    		   //check ULTRASONIC read as before
    		   if(){
    		   //if passed thredshold do action in fun
    		   Avoid_ToLeft();
    		   OBS_LEFT_Active_State = FALSE ;
    		   }
    	   }
    	   else if (OBS_Right_Active_State ==TRUE)
    	   {
    		   //check ULTRASONIC read as before
    		   if(){
    		   //if passed thredshold do action in fun
    		   Avoid_ToRight();
    		   OBS_Right_Active_State = FALSE ;

    		   }
    	   }
    }

}



void LaneAssist(u8 Copy_u8NormalSpeed) {
    // set default speed
    UART_TransmitString("inside Lane assistant \r\n");

    //	while (1)
    {
        // if Right Sensor and Left Sensor are at White color then it will call forword function
        if ((Dio_ReadChannel(R_S) == 1) && (Dio_ReadChannel(L_S) == 1)) {
            // forward
            UART_TransmitString("inside motor 1  \r\n");
            MOTOR_voidOn(SPEED_MOTOR, MOTOR_CW);
            MOTOR_voidOff(STEERING_MOTOR);
            MOTOR_voidControlSpeed(SPEED_MOTOR, Copy_u8NormalSpeed);
        }

        // if Right Sensor is Black and Left Sensor is White then it will call turn Right function
        if ((Dio_ReadChannel(R_S) == 0) && (Dio_ReadChannel(L_S) == 1)) {
            // turnRight
            UART_TransmitString("inside motor 2  \r\n");
    //        MOTOR_voidControlSpeed(SPEED_MOTOR, 10);
            MOTOR_voidOn(STEERING_MOTOR, MOTOR_CCW);
        }
        // if Right Sensor is White and Left Sensor is Black then it will call turn Left function
        if ((Dio_ReadChannel(R_S) == 1) && (Dio_ReadChannel(L_S) == 0)) {
            // turnLeft
            UART_TransmitString("inside motor 3  \r\n");
      //      MOTOR_voidControlSpeed(SPEED_MOTOR, 10);
            MOTOR_voidOn(STEERING_MOTOR, MOTOR_CW);
        }
        // if Right Sensor and Left Sensor are at Black color then it will call Stop function
        if ((Dio_ReadChannel(R_S) == 0) && (Dio_ReadChannel(L_S) == 0)) {
            // Stop
            UART_TransmitString("inside motor 4  \r\n");
            MOTOR_voidOff(STEERING_MOTOR);
            MOTOR_voidOff(SPEED_MOTOR);
        }
    }
}
