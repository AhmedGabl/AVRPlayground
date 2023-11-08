/*ND
 * main.c

 *
 *  Created on: Oct 17, 2023
 *      Author: AhmedAbogabl
 */
//#define F_CPU 16000000UL
#include <avr/delay.h>

#include "HAL/EEPROM/EEPROM_interface.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/PORT/PORT.h"
#include "MCAL/SPI/includes/SPI_interface.h"
#include "MCAL/GI/GI_interface.h"
#include "MCAL/UART/includes/UART_interface.h"
#include "HAL/LCD/LCD.h"
#include "HAL/SRVM/SRVM_interface.h"

#define ADMIN_PW 1234
#define EEPROM_ID_START 0x00
#define EEPROM_PW_START 0x01

static u8 USERS[10];

u8 ids_index=0;
//u8 pws_index=0;


void ADD_user() {
    u8 user[4];
    u16 pw_rx = 0;
    u8 data;

    UART_TransmitString("\r\n Enter user id (0-9):");

    // Assuming the Bluetooth module sends each digit separately
    while (1) {
        data = UART_Receive(); // Receive data from Bluetooth module

        if (data != '\n' && data != '\r') {
            user[0] = data;
           // Lcd_PutChar(user[0]);
            break;
        }
    }

    UART_TransmitString("\r\n Enter user password (***):");

    // Receive password digits
    for (u8 i = 1; i < 4; ++i) {
        while (1) {
            data = UART_Receive(); // Receive data from Bluetooth module

            if (data != '\n' && data != '\r') {
                user[i] = data;
                pw_rx = (pw_rx * 10) + (data - '0'); // Convert received digits to a number
          //      Lcd_PutChar(user[ i]);
                break;
            }
        }
    }

    USERS[user[0]] = ids_index;

    // Store the user ID and password in EEPROM
    EEPROM_voidWritePage(0x00 + (ids_index * 4), user, 4);
    ids_index++; // Increment index for the next user
}



void EDIT_user(){
u8 user[4];
	UART_TransmitString("\r\n Enter user id to edit (1-20):");
	user[0] =(u8)UART_Receive();
	UART_TransmitString("\r\n Enter NEW password(****):");
	user[1] =(u8)UART_Receive();
	user[2] = (u8)UART_Receive();
	user[3] = (u8)UART_Receive();

	EEPROM_voidWritePage(0x00+(USERS[user[0]]*4),user,4);
}

void DELETE_user(){
	    u8 user[4];
	    UART_TransmitString("\r\n Enter user id to delete (1-20):");
		user[0] =(u8)UART_Receive();
		USERS[user[0]] = 99;
}


void Handle_user(u8 Users_Pick)
{
switch (Users_Pick) {
	case 1:
		ADD_user();
		break;
	case 2:
		DELETE_user();
		break;
	case 3:
		EDIT_user();
		break;
	default:
		break;
}
}



//////////////////////////////////////SPI
u8 RX_USER[4];
static u8 INDEX=0;

void check_user(void)
{
	u8 fetch_UserPW[3];
	EEPROM_voidSequentialRead((0x00+(USERS[RX_USER[0]]*4)+1),fetch_UserPW,3);
	_delay_ms(50);
if(USERS[RX_USER[0]] != 99)
{

//Lcd_PutChar('D');
//
//Lcd_PutInt(RX_USER[1]);
//Lcd_PutInt(RX_USER[2]);
//Lcd_PutInt(RX_USER[3]);
//
//Lcd_PutChar('D');
//
//Lcd_PutChar(fetch_UserPW[0]);
//Lcd_PutChar(fetch_UserPW[1]);
//Lcd_PutChar(fetch_UserPW[2]);

//Lcd_PutChar('F');

	if( (RX_USER[1]+'0' == fetch_UserPW[0]) && (RX_USER[2]+'0'==fetch_UserPW[1])&&(RX_USER[3]+'0'==fetch_UserPW[2]) )
	{Lcd_PutString("GOT HERE");

	//	Lcd_PutChar('T');
	SRVM_voidOn(0);
	UART_TransmitString("USER ID : ");
	UART_Send(RX_USER[0]+'0');
	UART_TransmitString("\r\n GOT ACCESS");
	_delay_ms(5000);
	SRVM_voidOn(90);
	}

}
}


void get_user(u8 copy_u8RxData){
switch (INDEX) {
	case 0:
		RX_USER[0] = copy_u8RxData ;//data
		INDEX++;
		break;
	case 1:
		RX_USER[1] = copy_u8RxData ;//data
		INDEX++;
		break;
	case 2:
		RX_USER[2] = copy_u8RxData ;//data
		INDEX++;
		break;
	case 3:
		RX_USER[3] = copy_u8RxData ;//data
		INDEX++;
		check_user();
		break;
	default:
		break;
}
}


void RunForUsers(void)
{
	while(1)
	{
		_delay_ms(200);
	SPI_voidTransmitAsynchronous(2,get_user);
	}
}

int main(){
	u8 access=0;
	u8 trials =0;
	u16 admin=0;
    u8	Users_Pick=0;


    Port_Init(pin_cfg);

    Lcd_Init();
    UART_Init();
	SPI_voidInit();
	EEPROM_voidInit();
	//Dio_WriteChannel(PA_5,STD_LOW);
	GI_voidEnable();

	while(1)
	{
		UART_TransmitString("ENTER PASSWORD:");
		admin = UART_ReceiveNumber();

		if(admin == ADMIN_PW)
			{
			access =1;
			break;
			}

		else
		{
			access=0;
		}

		if(trials == 3)
		{
			access=0;
			break;
		}
		trials++;
	}

	if(access==1){
		while(1){
		//	Lcd_PutString("here to check :");
		//handle admin functionality
		UART_TransmitString("\r\n 1 FOR ADDING NEW USER:\r\n");
		UART_TransmitString(" 2 FOR DELETING A USER:\r\n");
		UART_TransmitString(" 3 FOR EDITING A USER \r\n");
		UART_TransmitString(" 4 DONE SETTING USERS\r\n");
		Users_Pick= UART_ReceiveNumber();
		if(Users_Pick == 4)
		{
			break;
		}
		Handle_user(Users_Pick);

		//SPI_voidTransmitAsynchronous(2,get_user);
		}
	}

	else {
		UART_TransmitString("CLS\r\n");
		UART_TransmitString("\r\n OUT OF TRIALS :\r\n");
		UART_TransmitString("\r\n SYSTEM LOCKED :\r\n");

		Dio_WriteChannel(PA_4,STD_HIGH);
		exit(1);
	}

//	UART_TransmitString("\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n");
	RunForUsers();
//	INDEX =0;

//	}
	return 0;
}
