/*
 * ADAS_APP.h
 *
 *  Created on: Dec 12, 2023
 *      Author: AhmedAbogabl
 */

#ifndef ADAS_APP_H_
#define ADAS_APP_H_

//LANE CORRECTION SENSORS (lINE FOLLOWERS )
#define L_S PA_0
#define R_S PA_1

/**  	BLUETOOTH ECU    **/
#define  APP_VEHICLE_ACCESS_INFO_REQUEST        	0xDD
#define  APP_VEHICLE_UNLOCKED		              	0xD1
#define  APP_VEHICLE_LOCKED                   		0xD2

#define  APP_MOTORS_CONTROL_REQUEST 				0xBB
#define  APP_VEHICLE_MOVE_FORWARD                   0x57
#define  APP_VEHICLE_MOVE_BACKWARD                  0x53
#define  APP_VEHICLE_STEER_RIGHT                    0x44
#define	 APP_VEHICLE_STEER_LEFT	                    0x41
#define  APP_VEHICLE_STOP                           0x50


//for readability
#define NOT_YET 1
#define DONE 0

#define TRUE 1
#define FALSE 0

#define LOCKED 1
#define UNLOCKED 0

/*
 * exernal global shared variables
 */

extern u8 VEHICLE_state;
extern u8 ButtonState;
extern u8 VehicleAccess;
extern u8 BT_read_vlaue;

/*
 * Functions prototypes*********************************************************************************************
 */

void BT(u8 Rxdata); // BLUETOOTH FUNCTON
void WHM(void);      // MOTOR CONTROL FUNCTION
void HW_init(void);

#endif /* ADAS_APP_H_ */
