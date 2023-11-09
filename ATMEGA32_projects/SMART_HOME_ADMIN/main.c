/*
 * main.c

 *
 *  Created on: Oct 17, 2023
 *      Author: AhmedAbogabl
 */
// #define F_CPU 16000000UL

#include <avr/delay.h>

#include "HAL/EEPROM/EEPROM_interface.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/PORT/PORT.h"
#include "MCAL/SPI/includes/SPI_interface.h"
#include "MCAL/GI/GI_interface.h"
#include "MCAL/UART/includes/UART_interface.h"
#include "HAL/LCD/LCD.h"
#include "HAL/SRVM/SRVM_interface.h"

// admin predefined password
#define ADMIN_PW 1234
#define EEPROM_ID_FIRST_ADDR 0x00

// alert system pins
#define BUZZ PA_5
#define RED_LED PA_4
#define FeedBack PA_6

// used for admin options
static u8 USERS[10];
u8 ids_index = 0;

// Admin options
void ADD_user();
void EDIT_user();
void DELETE_user();
void Handle_user(u8 Users_Pick);

//////////////////////////////////////SPI

// used for spi comm users handling

// recieved user id and passsword
u8 RX_USER[4];
// indexes indicates number of stored users to avoid overwriting users
static u8 INDEX = 0;
// indicates number of trials for 1 user
u8 userTrials = 0;
// in case if wrong login if 3 trials over this flag cleared
u8 tryAgain_flag = 0;

void Noaction(u8 data){}
void check_user(void)
{
    u8 fetch_UserPW[3];
    EEPROM_voidSequentialRead((EEPROM_ID_FIRST_ADDR + (USERS[RX_USER[0]] * 4) + 1), fetch_UserPW, 3);
    _delay_ms(50);

    if (USERS[RX_USER[0]] != 99)
    {
        if ((RX_USER[1] + '0' == fetch_UserPW[0]) && (RX_USER[2] + '0' == fetch_UserPW[1]) && (RX_USER[3] + '0' == fetch_UserPW[2]))
        {
            SRVM_voidOn(0);

            UART_TransmitString("\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n");
            UART_TransmitString("USER ID : ");
            UART_Send(RX_USER[0] + '0');
            UART_TransmitString("\r\n GOT ACCESS");
            UART_TransmitString("\r\n DOOR OPEN FOR 5 SECONDS");

       //     _delay_ms(100);
            SPI_voidTransieve(1, &userTrials);
            //SPI_voidTransmitAsynchronous(1,Noaction);
            _delay_ms(5000);
            SRVM_voidOn(90);
            UART_TransmitString("\r\n\r\n");

            tryAgain_flag = 0;
            userTrials = 0;
        }
        else
        {
            tryAgain_flag = 1;

            _delay_ms(100);
            SPI_voidTransieve(2, &userTrials);
//            SPI_voidTransmitAsynchronous(2,Noaction);
            _delay_ms(300);
            UART_TransmitString("\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n");
            UART_TransmitString("\r\n USER ID : ");
            UART_Send(RX_USER[0] + '0');
            UART_TransmitString("\r\n ACCESS DENIED");

            Lcd_PutChar(userTrials + '0');
            if (userTrials == 3)
                tryAgain_flag = 0;
        }
    }
}

void get_user(u8 copy_u8RxData)
{
    switch (INDEX)
    {
    case 0:
        RX_USER[0] = copy_u8RxData; // data
        INDEX++;
        break;
    case 1:
        RX_USER[1] = copy_u8RxData; // data
        INDEX++;
        break;
    case 2:
        RX_USER[2] = copy_u8RxData; // data
        INDEX++;
        break;
    case 3:
        RX_USER[3] = copy_u8RxData; // data
        INDEX = 0;
        check_user();
        break;
    default:
        break;
    }
}

void RunForUsers(void)
{
    UART_TransmitString("\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n");
    UART_TransmitString("WAITTING FOR USER'S PASSWORD");

    while (0 == Dio_ReadChannel(FeedBack));
    u8 Digits = 0;
    while (Digits < 4)
    {
        _delay_ms(100);
        SPI_voidTransmitAsynchronous(3, get_user);
        Digits++;
    }
    Digits = 0;
}

int main()
{
    u8 access = 0;
    u8 trials = 0;
    u16 admin = 0;
    u8 Users_Pick = 0;

    Port_Init(pin_cfg);
    Lcd_Init();
    UART_Init();
    SPI_voidInit();
    EEPROM_voidInit();
    GI_voidEnable();

    while (1)
    {
        UART_TransmitString("ENTER PASSWORD:");
        admin = UART_ReceiveNumber();

        if (admin == ADMIN_PW)
        {
            access = 1;
            break;
        }
        else
        {
            access = 0;
        }
        if (trials == 3)
        {
            access = 0;
            break;
        }
        trials++;
    }

    if (1 == access)
    {
        while (1)
        {   UART_TransmitString("\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n");
            UART_TransmitString("\r\n 1 FOR ADDING NEW USER:\r\n");
            UART_TransmitString(" 2 FOR DELETING A USER:\r\n");
            UART_TransmitString(" 3 FOR EDITING A USER \r\n");
            UART_TransmitString(" 4 ACCEPT USERS\r\n");

            if (tryAgain_flag == 1)
            {
                RunForUsers();
            }
            else
            {
                Users_Pick = UART_ReceiveNumber();
                Handle_user(Users_Pick);
            }
        }
    }

    else
    {
        UART_TransmitString("CLS\r\n");
        UART_TransmitString("\r\n OUT OF TRIALS :\r\n");
        UART_TransmitString("\r\n SYSTEM LOCKED :\r\n");

        Dio_WriteChannel(BUZZ, STD_HIGH);
        Dio_WriteChannel(RED_LED, STD_HIGH);
        exit(1);
    }

    // UART_TransmitString("\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n");
    // RunForUsers();

    return 0;
}

void ADD_user()
{
    u8 user[4];
    u16 pw_rx = 0;
    u8 data;

    UART_TransmitString("\r\n Enter user id (0-9):");

    // Assuming the Bluetooth module sends each digit separately
    while (1)
    {
        data = UART_Receive(); // Receive data from Bluetooth module

        if (data != '\n' && data != '\r')
        {
            user[0] = data;
            // Lcd_PutChar(user[0]);
            break;
        }
    }

    UART_TransmitString("\r\n Enter user password (***):");

    // Receive password digits
    for (u8 i = 1; i < 4; ++i)
    {
        while (1)
        {
            data = UART_Receive(); // Receive data from Bluetooth module

            if (data != '\n' && data != '\r')
            {
                user[i] = data;
                pw_rx = (pw_rx * 10) + (data - '0'); // Convert received digits to a number
                break;
            }
        }
    }

    USERS[user[0]] = ids_index;

    // Store the user ID and password in EEPROM
    EEPROM_voidWritePage(EEPROM_ID_FIRST_ADDR + (ids_index * 4), user, 4);
    ids_index++; // Increment index for the next user
}

void EDIT_user()
{
    u8 user[4];
    UART_TransmitString("\r\n Enter user id to edit (1-20):");
    user[0] = (u8)UART_Receive();
    UART_TransmitString("\r\n Enter NEW password(****):");
    user[1] = (u8)UART_Receive();
    user[2] = (u8)UART_Receive();
    user[3] = (u8)UART_Receive();

    EEPROM_voidWritePage(EEPROM_ID_FIRST_ADDR + (USERS[user[0]] * 4), user, 4);
}

void DELETE_user()
{
    u8 user[4];
    UART_TransmitString("\r\n Enter user id to delete (1-20):");
    user[0] = (u8)UART_Receive();
    USERS[user[0]] = 99;
}

void Handle_user(u8 Users_Pick)
{
    switch (Users_Pick)
    {
    case 1:
        ADD_user();
        break;
    case 2:
        DELETE_user();
        break;
    case 3:
        EDIT_user();
        break;
    case 4:
        RunForUsers();
        break;
    default:
        break;
    }
}
