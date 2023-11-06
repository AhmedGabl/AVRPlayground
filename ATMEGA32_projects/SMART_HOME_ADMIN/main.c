/*
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


void ADD_user(){

	u8 user[4];

	UART_TransmitString("\r\n Enter user id (1-20):");

	user[0] =(u8)UART_Receive();

	UART_TransmitString("\r\n Enter user password(****):");

	user[1] =(u8)UART_Receive();
	user[2] = (u8)UART_Receive();
	user[3] = (u8)UART_Receive();

//	if(USERS[user[0]] != NULL)
	USERS[user[0]] =ids_index;

	EEPROM_voidWritePage(0x00+(ids_index*4),user,4);
	ids_index++;//decrement in delete
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
//		EEPROM_voidWritePage(0x00+USERS[user[0]]*4,user,4);
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
u8 INDEX=0;

void check_user(void)
{
	u8 fetch_UserPW[3];
	EEPROM_voidSequentialRead((0x00+(USERS[RX_USER[0]]*4)+1),fetch_UserPW,3);
	Lcd_PutChar(fetch_UserPW[0]);
	Lcd_PutChar(fetch_UserPW[1]);
	Lcd_PutChar(fetch_UserPW[2]);
	//ched user id in eeprom
if(USERS[RX_USER[0]] != 99)
{	Lcd_PutChar('D');

Lcd_PutChar(RX_USER[0]);
Lcd_PutChar(RX_USER[2]);
Lcd_PutChar(RX_USER[3]);

Lcd_PutChar('D');

Lcd_PutChar(fetch_UserPW[0]);
Lcd_PutChar(fetch_UserPW[1]);
Lcd_PutChar(fetch_UserPW[2]);

Lcd_PutChar('F');

	if( (RX_USER[1] == fetch_UserPW[0]) && (RX_USER[2]==fetch_UserPW[1])&&(RX_USER[3]==fetch_UserPW[2]) )
	{Lcd_PutChar('T');
		SRVM_voidOn(0);

	UART_TransmitString("USER ID :");
	UART_Send(RX_USER[0]);
	UART_TransmitString("GOT ACCESS");
	_delay_ms(1000);
	SRVM_voidOn(90);
	SRVM_voidOff();
	}
		//Dio_FlipChannel(PA_5);
}	//check user pw in eeprom
}

void get_user(u8 copy_u8RxData){
//	Lcd_PutInt(copy_u8RxData);
//	Dio_FlipChannel(PA_5);
	//Dio_WriteChannel(PA_5,STD_HIGH);

	if(INDEX==0){
		RX_USER[0] = copy_u8RxData ;//data
Lcd_PutInt(RX_USER[0]);
Lcd_PutInt(copy_u8RxData);
Lcd_PutChar('F');

		INDEX++;
	}
	else if (INDEX ==1) {
		Lcd_PutInt(RX_USER[1]);
	//	Lcd_PutInt(copy_u8RxData);
//		Lcd_PutChar('F');
		RX_USER[1]=copy_u8RxData;
		INDEX++;
	}
	else if (INDEX ==2) {
		Lcd_PutInt(RX_USER[2]);
	//	Lcd_PutInt(copy_u8RxData);
	//	Lcd_PutChar('F');
		RX_USER[2]=copy_u8RxData;
		INDEX++;
	}

	else if (INDEX == 3) {
		Lcd_PutInt(RX_USER[3]);
	//	Lcd_PutInt(copy_u8RxData);
	//	Lcd_PutChar('F');
		RX_USER[3] = copy_u8RxData;
		INDEX=0;
//		check_user();
	}


}


void RunForUsers(void)
{
//	UART_TransmitString("");
	while(1)
	{
		_delay_ms(100);
		SPI_voidTransmitAsynchronous(2,get_user);
	}
}

int main(){
	u8 access=0;
	u8 trials =0;
	u16 admin=0;
    u8	Users_Pick=0;


    Port_Init(pin_cfg);Lcd_Init();
    UART_Init();
	SPI_voidInit();
	EEPROM_voidInit();
	Dio_WriteChannel(PA_5,STD_LOW);
	GI_voidEnable();

	while(1)
	{   Lcd_PutString("lets start:");
	//	UART_TransmitString("\033[2J");
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
		exit(1);
	}

	UART_TransmitString("\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n");
	RunForUsers();

	return 0;
}
