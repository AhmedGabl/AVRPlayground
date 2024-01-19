/*
 * ADAS_APP.h
 * Description: Header file for the ADAS application.
 * Author: AhmedAbogabl
 * Created on: Dec 12, 2023
 */

#ifndef ADAS_APP_H_
#define ADAS_APP_H_

// Lane Correction Sensors (Line Followers)
#define L_S PA_0
#define R_S PA_1

// Constants for obstacle detection sensors
#define FRONT_SENSOR PA0
#define BACK_SENSOR  PA1
#define LEFT_SENSOR  PA2
#define RIGHT_SENSOR PA3

// Application-specific constants
#define APP_AUXILARY_FUN_STATE              0x36
#define APP_VEHICLE_ACCESS_INFO_REQUEST     0xDD
#define APP_VEHICLE_UNLOCKED                0xD1
#define APP_VEHICLE_LOCKED                  0xD2
#define APP_SPI_ACK                         0xEE
#define APP_MOTORS_CONTROL_REQUEST          0xBB
#define APP_VEHICLE_MOVE_FORWARD            0x57
#define APP_VEHICLE_MOVE_BACKWARD           0x53
#define APP_VEHICLE_STEER_RIGHT             0x44
#define APP_VEHICLE_STEER_LEFT              0x41
#define APP_VEHICLE_STOP                    0x50

// Constants for readability
#define NOT_YET 1
#define DONE    0
#define TRUE    1
#define FALSE   0
#define LOCKED  1
#define UNLOCKED 0

// External global shared variables
extern u8 VEHICLE_state;
extern u8 ButtonState;
extern u8 VehicleAccess;
extern u8 BT_read_vlaue;
extern u8 FunctionToACtivate;
extern u8 Functoin_Type;

/*
 * Function prototypes
 */

// BLUETOOTH FUNCTION
void BT(u8 Rxdata);

// MOTOR CONTROL FUNCTION
void WHM(void);

// Initialization function
void HW_init(void);

// Additional functions (commented out)
//void LED5(void);  // Test LEDs
//void LED4(void);
//void LED6(void);
//void AutoPark(void);  // Autopark functionality
//void Delay_ms(u32 Copy_u32Time);

#endif /* ADAS_APP_H_ */