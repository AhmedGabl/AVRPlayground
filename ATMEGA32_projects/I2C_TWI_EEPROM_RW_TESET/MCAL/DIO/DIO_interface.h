/*
 * DIO.h
 *
 * Created on: Oct 20, 2023
 * Author: AhmedAbogabl
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

#include "../../utils/BIT_MATH.h"
#include "../../utils/STD_TYPES.h"
#include <avr/io.h>

// Enumeration for the possible levels of a digital signal (Low or High)
typedef enum {
    STD_LOW,
    STD_HIGH
} Dio_LevelType;

// Enumeration for the available port types (A, B, C, D)
typedef enum {
    Dio_PORTA,
    Dio_PORTB,
    Dio_PORTC,
    Dio_PORTD
} Dio_PortType;

// Enumeration for individual channel/pin names for all available ports
typedef enum {
    PA_0, PA_1, PA_2, PA_3, PA_4, PA_5, PA_6, PA_7,
    PB_0, PB_1, PB_2, PB_3, PB_4, PB_5, PB_6, PB_7,
    PC_0, PC_1, PC_2, PC_3, PC_4, PC_5, PC_6, PC_7,
    PD_0, PD_1, PD_2, PD_3, PD_4, PD_5, PD_6, PD_7
} Dio_ChannelType;

// Structure to represent a group of channels with an offset and mask
typedef struct {
    u8 offset;
    u8 mask;
    Dio_PortType port;
} Dio_ChannelGroupType;

// Type definition for a port level (Note: Inherits the size of the largest port)
typedef u8 Dio_PortLevelType;


// Function prototypes
void Dio_WriteChannel(u8 ChannelId, Dio_LevelType Level);

void Dio_WritePort(Dio_PortType Portx, u8 data);

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

// Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr); // You may implement this function as needed.

#endif
