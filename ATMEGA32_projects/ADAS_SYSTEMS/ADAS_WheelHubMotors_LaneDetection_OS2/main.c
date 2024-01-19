/*
 * main.c
 * Description: automotive ecu resposible for whm bluetooth control and some auculery functions
 * Author: AhmedAbogabl
 * Created on: Oct 17, 2023
 */

#include "utils/BIT_MATH.h"
#include "utils/STD_TYPES.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/PORT/PORT.h"
#include "MCAL/GI/GI_interface.h"

#include "HAL/BLUETOOTH/BT_interface.h"//uart
#include "HAL/WHM/WHM_interface.h"//tmr0

#include "ADAS_APP.h"
#include "OS/OS_interface.h"


/*
 * *****************************************************************************************
 */

//LANE CORRECTION SENSORS (lINE FOLLOWERS )
#define L_S PC_0
#define R_S PC_1

// Constants for obstacle detection sensors
#define FRONT_SENSOR PA0
#define BACK_SENSOR  PA1
#define LEFT_SENSOR  PA2
#define RIGHT_SENSOR PA3


#define WHMPr (2) // MOTOR CONTROL FUNCTION PRIORITY

/*
 * Functions prototypes*********************************************************************************************
 */


void BT(u8 Rxdata); // BLUETOOTH FUNCTON
void WHM(void);      // MOTOR CONTROL FUNCTION
void HW_init(void);

//test leds
void LED5(void){Dio_FlipChannel(PA_5);}
void LED4(void){Dio_FlipChannel(PA_4);}
void LED6(void){Dio_FlipChannel(PA_6);}

//autopark functionality
void AutoPark(void);
void Delay_ms(u32 Copy_u32Time);

/*
 * ** Global Variable *********************************************************************************************************
 * */
//general control
u8 VEHICLE_state = LOCKED;

u8 ButtonState = 1;
u8 Lane_Asses = 0;
u8 BT_read_vlaue = 0;


//Spi communication  managemnt
u8 Spi_ResponseOnceFlag = NOT_YET;
u8 Spi_Request = NULL;
u8 VehicleAccess = FALSE;

/***********************************************************************************************************************
 *
 */

void Spi_Router(u8 Copy_u8RxData)
{           // UART_TransmitString("inside SPI_ROUTER \r\n");

	static u8 GIVE_CONTROL = FALSE ;

	if(Copy_u8RxData == APP_VEHICLE_ACCESS_INFO_REQUEST )
	{//UART_TransmitString("inside SPI_ROUTER    1\r\n");

		if(VehicleAccess == TRUE)
		Spi_Request = APP_VEHICLE_UNLOCKED;
		Spi_ResponseOnceFlag = NOT_YET;
	}
	else if(Copy_u8RxData == APP_MOTORS_CONTROL_REQUEST)
	{//UART_TransmitString("inside SPI_ROUTER    2\r\n");

     	 GIVE_CONTROL = TRUE;
  	   	 Spi_ResponseOnceFlag = NOT_YET;
  	   	 Spi_Request= 0xEE;
	}
	else if (GIVE_CONTROL == TRUE)
	{//UART_TransmitString("inside SPI_ROUTER    3\r\n");

		BT_read_vlaue = Copy_u8RxData;
		ButtonState = 0;
		GIVE_CONTROL = FALSE;
		Spi_ResponseOnceFlag = NOT_YET;
	}
	else
	{
	//	UART_TransmitString("inside SPI_ROUTER    4\r\n");
		Spi_ResponseOnceFlag = NOT_YET;
	}
}

int main(void) {
	HW_init();

	while (1) {
        WHM();
        if(Spi_ResponseOnceFlag == NOT_YET)
        {
           // UART_TransmitString("inside SPI \r\n");
        	SPI_voidTransmitAsynchronous(Spi_Request,Spi_Router);
        	Spi_Request = NULL;
        	Spi_ResponseOnceFlag = DONE;
        }
    }
    return 0;
}

void HW_init(void) {
    Port_Init(pin_cfg);
   // ADC_Init(); //pin 0 and 1  if needed for autopark

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

void WHM(void) {
   static  u8 speed = 60;
    /* if the Push Button is Pressed */
    if (ButtonState == 0) {
        Lane_Asses = 0;
        //	BT_read_vlaue = BT_read_vlaue + '0' ;
        switch (BT_read_vlaue) {
        // speed dir options
        case 'W':
            LED4();
            MOTOR_voidOn(SPEED_MOTOR, MOTOR_CW);
            UART_TransmitString("inside W \r\n");
            ButtonState = 1;
            break;
        case 'S':
            LED5();
            MOTOR_voidOn(SPEED_MOTOR, MOTOR_CCW);
            UART_TransmitString("inside S \r\n");
            ButtonState = 1;
            break;
        // steering direction optinos
        case 'D':
            UART_TransmitString("inside D \r\n");
            LED6();
            MOTOR_voidOn(STEERING_MOTOR, MOTOR_CW);
            ButtonState = 1;
            break;
        case 'A':
            UART_TransmitString("inside A \r\n");
            LED6();
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
        case 'K':
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
        LaneAssist(speed);
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

void AutoPark(void) {
    // Set default speed
    MOTOR_voidOn(SPEED_MOTOR, MOTOR_CW);
   // MOTOR_voidControlSpeed(SPEED_MOTOR, 10);

    // Move forward until obstacle is detected in front
    while (ADC_ReadChannel(FRONT_SENSOR) < 100) {
        // Continue moving forward until obstacle is detected
        MOTOR_voidOn(STEERING_MOTOR, MOTOR_CW);
    }

    // Stop and delay for a while
    MOTOR_voidOff(STEERING_MOTOR);
    MOTOR_voidOff(SPEED_MOTOR);
    Delay_ms(1000);

    // Turn right until it's clear
    MOTOR_voidOn(STEERING_MOTOR, MOTOR_CCW);
    Delay_ms(1000);

    // Move backward until obstacle is detected at the back
    MOTOR_voidOn(SPEED_MOTOR, MOTOR_CCW);
    while (ADC_ReadChannel(BACK_SENSOR) < 100) {
        // Continue moving backward until obstacle is detected
        MOTOR_voidOn(STEERING_MOTOR, MOTOR_CCW);
    }

    // Stop and delay for a while
    MOTOR_voidOff(STEERING_MOTOR);
    MOTOR_voidOff(SPEED_MOTOR);
    Delay_ms(1000);

    // Turn left until it's clear
    MOTOR_voidOn(STEERING_MOTOR, MOTOR_CW);
    Delay_ms(1000);

    // Stop and drop steering
    MOTOR_voidOff(STEERING_MOTOR);
    MOTOR_voidOff(SPEED_MOTOR);
}

void Delay_ms(u32 Copy_u32Time) {
    for (u32 i = 0; i < Copy_u32Time; i++) {
        for (u16 j = 0; j < 1200; j++) {
            // Adjust this loop for the desired delay
        }
    }
}