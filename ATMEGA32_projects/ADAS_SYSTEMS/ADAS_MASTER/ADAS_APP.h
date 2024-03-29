/*
 * ADAS_APP.h
 *
 *  Created on: Dec 12, 2023
 *      Author: AhmedAbogabl
 */

#ifndef ADAS_APP_H_
#define ADAS_APP_H_

/**  	BLUETOOTH ECU    **/
#define  APP_VEHICLE_ACCESS_INFO_REQUEST        	0xDD
#define  APP_VEHICLE_UNLOCKED		              	0xD1
#define  APP_VEHICLE_LOCKED                   		0xD2


//#define  APP_BLUETOOTH_INPUT_REQUEST                0x99
//#define  APP_BLUETOOTH_NO_INPUT                     0x50
//#define  APP_MOTORS_CONTROL_REQUEST 				0xBB
//#define  APP_LANE_ASSISTANCE_FEATURE_REQUEST		0x4C


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


#endif /* ADAS_APP_H_ */
