/*
 * CFile1.c
 *
 * Created: 10/21/2023 1:14:38 AM
 *  Author: ahmed radwan
 */ 
// .h format
/***************************************** macros section ***********************************/


/*********************************** macros section end ***********************************/


/*********************************** user defined data types section ***********************************/


/*********************************** user defined data types section end ***********************************/



/****************************** function prototypes section***********************************************/


/****************************** function prototypes section end*******************************************/




// this contain all tests copy  the required section and un define it define


/*********************************************port & dio drivers test ****************************************************/

// #define F_CPU 16000000UL
// #include <util/delay.h>
// #include "SERVICES/Standard_Data_Types.h"

// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// 
// int main(void)
// {
// 	volatile u8 debug1=0;
// 	volatile u8 debug2=0;
// 	Port_vidInit();
// 	Dio_enuWriteChannel(10,DIO_PIN_HIGH);
// 	Dio_enuFlipChannel(10);
// 	Dio_enuWritePort(1,0xff);
// 	Dio_enuWritePort(1,0x00);
// 	_delay_ms(3000);
// 	while (1)
// 	{
// 		debug1++;
// 		for(u8 i=0;i<=31;i++)
// 		{
// 			Dio_enuWriteChannel(i,DIO_PIN_HIGH);
// 			_delay_ms(500);
// 		}
// 		debug1++;
// 		for(u8 i=0;i<31;i++)
// 		{
// 			Dio_enuFlipChannel(i);
// 		_delay_ms(500);		}
// 		debug1++;
// 		for(u8 i=0;i<=3;i++)
// 		{
// 			Dio_enuWritePort(i,0xff);
// 			_delay_ms(1000);
// 		}
// 		debug1++;
// 		for(u8 i=0;i<=3;i++)
// 		{
// 			Dio_enuWritePort(i,0x0f);
// 			_delay_ms(1000);
// 		}
// 		Dio_enuReadChannel(DIO_D7_ID_31,&debug1);
// 		Dio_enuReadPort(2,&debug2);
// 
// 		
// 	}
// }
// 
/*********************************************port & dio drivers test end ****************************************************/

/*********************************************push button drivers test ****************************************************/

/*
 * AVR_DRIVERS.c
 *
 * Created: 10/20/2023 8:33:11 PM
 * Author : ahmed radwan
 */ 
// #define F_CPU 16000000UL
// #include <avr/io.h>
// #include <util/delay.h>
// #include "SERVICES/Standard_Data_Types.h"

// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// #include "HAL/BUTTON/BUTTON.h"
// #include "HAL/7_SEGMENT/7_SEGMENT.h"
// 
// 
// int main(void)
// {
// 	 volatile u8 debug1=0;
// 	 volatile u8 debug2=0;
// 	Button_tst button1={.button_pin_id=DIO_B2_ID_10,.conection=BUTTON_PULL_DOWN};
// 	Button_tst button2={.button_pin_id=DIO_C4_ID_20,.conection=BUTTON_PULL_UP};
//     /* Replace with your application code */
// 	Port_vidInit();
// 	Button_enuInit(&button1);
// 	Button_enuInit(&button2);
// 
//     while (1) 
//     {   
// 			Button_enuRead(&button1,&debug1);
// 			Button_enuRead(&button2,&debug2);
// 			_delay_ms(500);
//     }
// }

/*********************************************push button drivers test end ****************************************************/



/*********************************************seven segment drivers test ****************************************************/


/*
 * AVR_DRIVERS.c
 *
 * Created: 10/20/2023 8:33:11 PM
 * Author : ahmed radwan
 */ 
// #define F_CPU 16000000UL
// #include <avr/io.h>
// #include <util/delay.h>
// #include "SERVICES/Standard_Data_Types.h"

// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// #include "HAL/BUTTON/BUTTON.h"
// #include "HAL/7_SEGMENT/7_SEGMENT.h"
// 
// Button_tst button1={.button_pin_id=DIO_B2_ID_10,.conection=BUTTON_PULL_DOWN};
// Button_tst button2={.button_pin_id=DIO_C4_ID_20,.conection=BUTTON_PULL_UP};
// SevenSegment_tst display1={.Segment_PIN1=DIO_D1_ID_25,
// 						   .Segment_PIN2=DIO_D2_ID_26,
// 						   .Segment_PIN3=DIO_D3_ID_27,
// 						   .Segment_PIN4=DIO_D4_ID_28};
// int main(void)
// {  
// 	u8 debug1=0;
// 
//     /* Replace with your application code */
// 	Port_vidInit();
// 	Button_enuInit(&button1);
// 	Button_enuInit(&button2);
// 	SevenSegment_INIT(&display1);
// 
//     while (1) 
//     {   
// 			SevenSegment_write(&display1,debug1++);
// 			_delay_ms(500);
//     }
// }



/*********************************************seven segment drivers test end ****************************************************/





/*********************************************seven segment  counter test ****************************************************/



/*
 * AVR_DRIVERS.c
 *
 * Created: 10/20/2023 8:33:11 PM
 * Author : ahmed radwan
//  */ 
// #define F_CPU 16000000UL
// #include <util/delay.h>
// #include "SERVICES/Standard_Data_Types.h"

// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// #include "HAL/BUTTON/BUTTON.h"
// #include "HAL/7_SEGMENT/7_SEGMENT.h"
// #include "HAL/LCD/LCD.h"
// #include "MCAL/GIE/GIE.h"

// 

// #define DELAY_POV_VAL 15

// void SevenSegment_Swaper(void);

// 

// u8 display_value1=0;

// u8 display_value2=0;

// u8 display_value3=0;

// u8 display_value4=0;


// Button_tst count_plus={.button_pin_id=DIO_D7_ID_31,.conection=BUTTON_PULL_UP};

// Button_tst count_minus={.button_pin_id=DIO_D6_ID_30,.conection=BUTTON_PULL_UP};

// Button_tst reset={.button_pin_id=DIO_D5_ID_29,.conection=BUTTON_PULL_UP};

//Button_tenuState	count_plus_state=BUTTON_NOT_PRESSED;
//Button_tenuState	count_minus_state=BUTTON_NOT_PRESSED;
//Button_tenuState	reset_state=BUTTON_NOT_PRESSED;



// SevenSegment_tst display1={.Segment_PIN1=DIO_B0_ID_8,


// 	.Segment_PIN2=DIO_B1_ID_9,


// 	.Segment_PIN3=DIO_B2_ID_10,


// .Segment_PIN4=DIO_B4_ID_12};



// SevenSegment4pins_tst active_pins={.Segment1_active=DIO_A3_ID_3,


// 	.Segment2_active=DIO_A2_ID_2,


// 	.Segment3_active=DIO_B5_ID_13,


// .Segment4_active=DIO_B6_ID_14};
//u32 counter=0;

// int main(void)


// {

// 	Port_vidInit();

// 	Button_enuInit(&count_plus);

// 	Button_enuInit(&count_minus);

// 	Button_enuInit(&reset);

// 	SevenSegment_INIT(&display1);


// 	while (1)


// 	{


// 
//		SevenSegment_Swaper();

// 		Button_enuRead(&count_plus,&count_plus_state);

// 		Button_enuRead(&count_minus,&count_minus_state);

// 		Button_enuRead(&reset,&reset_state);

// 		if(reset_state==BUTTON_PRESSED||counter>=9999)

// 		{

// 			counter=0;

// 			

// 			display_value1=counter%10;

// 			display_value2=(counter/10)%10;

// 			display_value3=(counter/100)%10;

// 			display_value4=(counter/1000)%10;

// 		}

// 		else if(count_minus_state==BUTTON_PRESSED&&counter!=0)

// 		{

// 			counter--;

// 			display_value1=counter%10;

// 			display_value2=(counter/10)%10;

// 			display_value3=(counter/100)%10;

// 			display_value4=(counter/1000)%10;

// 			SevenSegment_Swaper();

// 			_delay_ms(50);

// 		}

// 		else if(count_plus_state==BUTTON_PRESSED)

// 		{

// 			counter++;

// 			display_value1=counter%10;

// 			display_value2=(counter/10)%10;

// 			display_value3=(counter/100)%10;

// 			display_value4=(counter/1000)%10;

// 			SevenSegment_Swaper();

// 			_delay_ms(50);

// 			

// 		}

// 		

// 	}


// }


// 


// void SevenSegment_Swaper(void){



// 	Dio_enuWriteChannel(active_pins.Segment2_active,1);

// 	Dio_enuWriteChannel(active_pins.Segment3_active,1);

// 	Dio_enuWriteChannel(active_pins.Segment4_active,1);
 //   SevenSegment_write(&display1,display_value1);

// 	Dio_enuWriteChannel(active_pins.Segment1_active,0);

// 	_delay_ms(DELAY_POV_VAL);


// 	Dio_enuWriteChannel(active_pins.Segment1_active,1);

// 	Dio_enuWriteChannel(active_pins.Segment3_active,1);

// 	Dio_enuWriteChannel(active_pins.Segment4_active,1);
	//SevenSegment_write(&display1,display_value2);
//	Dio_enuWriteChannel(active_pins.Segment2_active,0);

// 	_delay_ms(DELAY_POV_VAL);

// 
//	Dio_enuWriteChannel(active_pins.Segment4_active,1);

// 	Dio_enuWriteChannel(active_pins.Segment1_active,1);

// 	Dio_enuWriteChannel(active_pins.Segment2_active,1);
//	SevenSegment_write(&display1,display_value3);

// 	Dio_enuWriteChannel(active_pins.Segment3_active,0);

// 	_delay_ms(DELAY_POV_VAL);



// 	Dio_enuWriteChannel(active_pins.Segment1_active,1);

// 	Dio_enuWriteChannel(active_pins.Segment2_active,1);

// 	Dio_enuWriteChannel(active_pins.Segment3_active,1);
//	SevenSegment_write(&display1,display_value4);

// 	Dio_enuWriteChannel(active_pins.Segment4_active,0);

// 	_delay_ms(DELAY_POV_VAL);

// }

/*********************************************seven segment  counter test end ****************************************************/


/*********************************************seven segment  stop watch ****************************************************/
/*
 * AVR_DRIVERS.c
 *
 * Created: 10/20/2023 8:33:11 PM
 * Author : ahmed radwan
 */ 
// #define F_CPU 16000000UL
// #include <util/delay.h>
// #include "SERVICES/Standard_Data_Types.h"
// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// #include "HAL/BUTTON/BUTTON.h"
// #include "HAL/7_SEGMENT/7_SEGMENT.h"
// #include "HAL/LCD/LCD.h"
// #include "MCAL/GIE/GIE.h"

// 

// #define DELAY_POV_VAL 15

// 

// u8 display_value1=0;

// u8 display_value2=0;

// u8 display_value3=0;

// u8 display_value4=0;


// Button_tst start={.button_pin_id=DIO_D7_ID_31,.conection=BUTTON_PULL_UP};

// Button_tst stop={.button_pin_id=DIO_D6_ID_30,.conection=BUTTON_PULL_UP};

// Button_tst reset={.button_pin_id=DIO_D5_ID_29,.conection=BUTTON_PULL_UP};

//Button_tenuState	start_state=BUTTON_NOT_PRESSED;
//Button_tenuState	stop_state=BUTTON_NOT_PRESSED;
//Button_tenuState	reset_state=BUTTON_NOT_PRESSED;



// SevenSegment_tst display1={.Segment_PIN1=DIO_B0_ID_8,


// 	.Segment_PIN2=DIO_B1_ID_9,


// 	.Segment_PIN3=DIO_B2_ID_10,


// .Segment_PIN4=DIO_B4_ID_12};



// SevenSegment4pins_tst active_pins={.Segment1_active=DIO_A3_ID_3,


// 	.Segment2_active=DIO_A2_ID_2,


// 	.Segment3_active=DIO_B5_ID_13,


// .Segment4_active=DIO_B6_ID_14};
//u32 counter=0;

// int main(void)


// {

// 	Port_vidInit();

// 	Button_enuInit(&start);

// 	Button_enuInit(&stop);

// 	Button_enuInit(&reset);

// 	SevenSegment_INIT(&display1);
//	u8 stp_watch_flag=0;


// 	while (1)


// 	{


// 
//		SevenSegment_Swaper();

// 		Button_enuRead(&start,&start_state);

// 		Button_enuRead(&stop,&stop_state);

// 		Button_enuRead(&reset,&reset_state);

// 		if(reset_state==BUTTON_PRESSED||counter==9999)

// 		{

// 			counter=0;

// 			stp_watch_flag=0;

// 			display_value1=counter%10;

// 			display_value2=(counter/10)%10;

// 			display_value3=(counter/100)%10;

// 			display_value4=(counter/1000)%10;

// 		}

// 		else if(stop_state==BUTTON_PRESSED)

// 		{

// 			stp_watch_flag=0;

// 			

// 		}

// 		else if(start_state==BUTTON_PRESSED)

// 		{

// 			stp_watch_flag=1;

// 			

// 		}

// 		if(stp_watch_flag)

// 		{

// 			display_value1=counter%10;

// 			display_value2=(counter/10)%10;

// 			display_value3=(counter/100)%10;

// 			display_value4=(counter/1000)%10;

// 			counter++;

// 		}

// 		

// 


// 	}


// }


// 


// void SevenSegment_Swaper(void){



// 	Dio_enuWriteChannel(active_pins.Segment2_active,1);

// 	Dio_enuWriteChannel(active_pins.Segment3_active,1);

// 	Dio_enuWriteChannel(active_pins.Segment4_active,1);
//   SevenSegment_write(&display1,display_value1);

// 	Dio_enuWriteChannel(active_pins.Segment1_active,0);

// 	_delay_ms(DELAY_POV_VAL);


// 	Dio_enuWriteChannel(active_pins.Segment1_active,1);

// 	Dio_enuWriteChannel(active_pins.Segment3_active,1);

// 	Dio_enuWriteChannel(active_pins.Segment4_active,1);
//	SevenSegment_write(&display1,display_value2);
//	Dio_enuWriteChannel(active_pins.Segment2_active,0);

// 	_delay_ms(DELAY_POV_VAL);

// 
//	Dio_enuWriteChannel(active_pins.Segment4_active,1);

// 	Dio_enuWriteChannel(active_pins.Segment1_active,1);

// 	Dio_enuWriteChannel(active_pins.Segment2_active,1);
//	SevenSegment_write(&display1,display_value3);

// 	Dio_enuWriteChannel(active_pins.Segment3_active,0);

// 	_delay_ms(DELAY_POV_VAL);



// 	Dio_enuWriteChannel(active_pins.Segment1_active,1);

// 	Dio_enuWriteChannel(active_pins.Segment2_active,1);

// 	Dio_enuWriteChannel(active_pins.Segment3_active,1);
//	SevenSegment_write(&display1,display_value4);

// 	Dio_enuWriteChannel(active_pins.Segment4_active,0);

// 	_delay_ms(DELAY_POV_VAL);

// }

/*********************************************seven segment  stop watch end ****************************************************/


/****************************************** lcd 8 bit mode test *******************************************/
/*
 * AVR_DRIVERS.c
 *
 * Created: 10/20/2023 8:33:11 PM
 * Author : ahmed radwan
 */ 
// #define F_CPU 16000000UL
// #include <avr/io.h>
// #include <util/delay.h>
// #include "SERVICES/Standard_Data_Types.h"

// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// #include "HAL/BUTTON/BUTTON.h"
// #include "HAL/7_SEGMENT/7_SEGMENT.h"
// #include "HAL/LCD/LCD.h"
// u8 hamada[] = {

// 	0b01110,

// 	0b01010,

// 	0b01110,

// 	0b00100,

// 	0b11111,

// 	0b10101,

// 	0b01010,

// 	0b11011

// };
// 
// LCD_8BIT_ST lcd={.lcd_pins[0]=PIN_B0_ID_8,
// 				 .lcd_pins[1]=PIN_B1_ID_9,
// 				 .lcd_pins[2]=PIN_B2_ID_10,
// 				 .lcd_pins[3]=PIN_B3_ID_11,
// 				 .lcd_pins[4]=PIN_B4_ID_12,
// 				 .lcd_pins[5]=PIN_B5_ID_13,
// 				 .lcd_pins[6]=PIN_B6_ID_14,
// 				 .lcd_pins[7]=PIN_B7_ID_15,
// 				 .lcd_pin_rs=PIN_A6_ID_6,
// 				 .lcd_pin_e=PIN_A7_ID_7};
// int main(void)
// {  
// 	Port_vidInit();
// 	LCD_vidInit_8bit(&lcd);
// 	
// 	LCD_vidDisplayChar_8bit(&lcd,'a');
// 	LCD_vidDisplayNumber_8bit(&lcd,1234);
// 	LCD_vidDisplayString_8bit(&lcd,"msamsa");
// 	LCD_vidGotoXY_8bit(&lcd,2,0);
// 	LCD_vidDisplayString_8bit(&lcd,"msamsa");
// 	LCD_vidDisplayString_8bit(&lcd,"msamsa");
// 	LCD_vidGotoXY_8bit(&lcd,3,0);
// 	LCD_vidDisplayString_8bit(&lcd,"msamsa");
// 	LCD_vidDisplayString_8bit(&lcd,"msamsa");
// 	LCD_vidGotoXY_8bit(&lcd,4,0);
// 	LCD_vidDisplayString_8bit(&lcd,"msamsa");
// 	LCD_vidDisplayString_8bit(&lcd,"msamsa");
// 	LCD_vidCraetCustomChar_8bit(&lcd,hamada,1);
// 	LCD_vidDisplayChar_8bit(&lcd,1);
// 	LCD_vidGotoXY_8bit(&lcd,2,0);
// 	LCD_vidDisplayChar_8bit(&lcd,'*');
// 
//     while (1) 
//     {   
// 
//     }
// }
// 

/****************************************** lcd 8 bit mode test end *******************************************/



/****************************************** lcd 4 bit mode test *******************************************/


/*
 * AVR_DRIVERS.c
 *
 * Created: 10/20/2023 8:33:11 PM
 * Author : ahmed radwan
 */ 
// #define F_CPU 16000000UL
// #include <avr/io.h>
// #include <util/delay.h>
// #include "SERVICES/Standard_Data_Types.h"

// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// #include "HAL/BUTTON/BUTTON.h"
// #include "HAL/7_SEGMENT/7_SEGMENT.h"
// #include "HAL/LCD/LCD.h"
// u8 hamada[] = {

// 	0b01110,

// 	0b01010,

// 	0b01110,

// 	0b00100,

// 	0b11111,

// 	0b10101,

// 	0b01010,

// 	0b11011

// };
// 
// LCD_4BIT_ST lcd={.lcd_pins[0]=PIN_B0_ID_8,
// 				 .lcd_pins[1]=PIN_B1_ID_9,
// 				 .lcd_pins[2]=PIN_B2_ID_10,
// 				 .lcd_pins[3]=PIN_B4_ID_12,
// 				 .lcd_pin_rs=PIN_A3_ID_3,
// 				 .lcd_pin_e=PIN_A2_ID_2};
// int main(void)
// {  
// 	Port_vidInit();
// 	LCD_vidInit_4bit(&lcd);
// 	
// 	LCD_vidDisplayChar_4bit(&lcd,'a');
// 	LCD_vidDisplayNumber_4bit(&lcd,1234);
// 	LCD_vidDisplayString_4bit(&lcd,"msamsa");
// 	LCD_vidGotoXY_4bit(&lcd,2,0);
// 	LCD_vidDisplayString_4bit(&lcd,"msamsa");
// 	LCD_vidDisplayString_4bit(&lcd,"msamsa");
// 	LCD_vidGotoXY_4bit(&lcd,3,0);
// 	LCD_vidDisplayString_4bit(&lcd,"msamsa");
// 	LCD_vidDisplayString_4bit(&lcd,"msamsa");
// 	LCD_vidGotoXY_4bit(&lcd,4,0);
// 	LCD_vidDisplayString_4bit(&lcd,"msamsa");
// 	LCD_vidDisplayString_4bit(&lcd,"msamsa");
// 	LCD_vidCraetCustomChar_4bit(&lcd,hamada,1);
// 	LCD_vidDisplayChar_4bit(&lcd,1);
// 	LCD_vidGotoXY_4bit(&lcd,2,0);
// 	LCD_vidDisplayChar_4bit(&lcd,'*');
// 
//     while (1) 
//     {   
// 
//     }
// }
// 



/****************************************** lcd 4 bit mode test end *******************************************/


/***************************************** GIE TEST ******************************************/
/*
 * AVR_DRIVERS.c
 *
 * Created: 10/20/2023 8:33:11 PM
 * Author : ahmed radwan
 */ 
// #define F_CPU 16000000UL
// #include <avr/io.h>
// #include <util/delay.h>
// #include "SERVICES/Standard_Data_Types.h"

// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// #include "HAL/BUTTON/BUTTON.h"
// #include "HAL/7_SEGMENT/7_SEGMENT.h"
// #include "HAL/LCD/LCD.h"
// #include "MCAL/GIE/GIE.h"
// u8 test_var=9;
// int main(void)
// {  
// 	Port_vidInit();
// 	LCD_vidInit_4bit(&lcd);
// 
// 	test_var=GIE_Get_Status();
// 	GIE_INIT();
// 	test_var=GIE_Get_Status();
// 	GIE_Disable();
// 	test_var=GIE_Get_Status();
// 	GIE_Enable();
// 	test_var=GIE_Get_Status(); 
// 	++test_var;
//     while (1) 
//     {   
// 		++test_var;
//     }
// }
// 
/***************************************** GIE TEST END ******************************************/




/**************************************** ADC voltameter with EXINT *************************************************/

/*
 * AVR_DRIVERS.c
 *
 * Created: 10/20/2023 8:33:11 PM
 * Author : ahmed radwan
 */ 

// #define F_CPU 16000000UL
// #include <util/delay.h>
// #include "SERVICES/Standard_Data_Types.h"
// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// #include "HAL/LCD/LCD.h"
// #include "MCAL/GIE/GIE.h"
// #include "MCAL/EXTI/EXTI.h"
// #include "MCAL/ADC/ADC.h"
// volatile u8 flag=0;
// void isr(void)
// {
// 	if(flag==0)
// 	{
// 		flag=1;
// 	}
// 	else if(flag==1)
// 	{
// 		flag=0;
// 	}
// }
// u16 test_var=9;
// f32 volt_print=0;
// LCD_4BIT_ST lcd={.lcd_pins[0]=PIN_B0_ID_8,

// 	.lcd_pins[1]=PIN_B1_ID_9,

// 	.lcd_pins[2]=PIN_B2_ID_10,

// 	.lcd_pins[3]=PIN_B4_ID_12,

// 	.lcd_pin_rs=PIN_A3_ID_3,

// .lcd_pin_e=PIN_A2_ID_2};
// 
// int main(void)
// {
// 	Port_vidInit();
// 	LCD_vidInit_4bit(&lcd);
// 	GIE_INIT();
// 	EXI_INT(EXTI_INT0,EXTI_MODE_FALING_EDGE,isr);
// 	LCD_vidDisplayString_4bit(&lcd,"VOLT:");
// 	LCD_vidGotoXY_4bit(&lcd,1,6);
// 
// 	ADC_INIT();
// 
//     while (1)
//     {
// 		ADC_GET_CONV_BOOLING(ADC1,&test_var);
// 		volt_print=(f32)test_var*5/1024;
// 		LCD_vidGotoXY_4bit(&lcd,1,5);
// 		if(flag==1)
// 		{
// 			LCD_vidDisplayFloatNumber_4bit(&lcd,volt_print);//v
// 			LCD_vidDisplayString_4bit(&lcd,"v   ");
// 		}
// 		else if(flag==0)
// 		{
// 			LCD_vidDisplayNumber_4bit(&lcd,volt_print*1000);//mv
// 			LCD_vidDisplayString_4bit(&lcd,"mv  ");
// 		}
// 		else{}
// 
//     }
///**************************************** ADC voltameter with EXINT end *************************************************/




/**************************************** ADC volume task *************************************************/
/*
 * AVR_DRIVERS.c
 *
 * Created: 10/20/2023 8:33:11 PM
 * Author : ahmed radwan
 */ 
// #define F_CPU 16000000UL
// #include <util/delay.h>
// #include "SERVICES/Standard_Data_Types.h"

// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// #include "HAL/BUTTON/BUTTON.h"
// #include "HAL/7_SEGMENT/7_SEGMENT.h"
// #include "HAL/LCD/LCD.h"
// #include "MCAL/GIE/GIE.h"
// #include "MCAL/EXTI/EXTI.h"
// #include "MCAL/ADC/ADC.h"
// 
// u16 ADC_val=9;
// f32 volt_print=0;
// LCD_4BIT_ST lcd={.lcd_pins[0]=PIN_B0_ID_8,

// 	.lcd_pins[1]=PIN_B1_ID_9,

// 	.lcd_pins[2]=PIN_B2_ID_10,

// 	.lcd_pins[3]=PIN_B4_ID_12,

// 	.lcd_pin_rs=PIN_A3_ID_3,

// .lcd_pin_e=PIN_A2_ID_2};
// 
// u8 volume1[] = {

// 	0b00000,

// 	0b00000,

// 	0b00000,

// 	0b00000,

// 	0b00000,

// 	0b11111,

// 	0b11111,

// 	0b11111

// };
// u8 volume2[] = {

// 	0b00000,

// 	0b00000,

// 	0b00000,

// 	0b11111,

// 	0b11111,

// 	0b11111,

// 	0b11111,

// 	0b11111

// };
// u8 volume3[] = {

// 	0b11111,

// 	0b11111,

// 	0b11111,

// 	0b11111,

// 	0b11111,

// 	0b11111,

// 	0b11111,

// 	0b11111

// };

// 
// int main(void)
// {  
// 	LCD_vidInit_4bit(&lcd);
// 	LCD_vidCraetCustomChar_4bit(&lcd,volume1,1);
// 	LCD_vidCraetCustomChar_4bit(&lcd,volume2,2);
// 	LCD_vidCraetCustomChar_4bit(&lcd,volume3,3);
// 	
// 
// 	LCD_vidDisplayString_4bit(&lcd,"VOLUME:");
// 	LCD_vidGotoXY_4bit(&lcd,1,8);
// 	
// 	ADC_INIT();
// 	
//     while (1) 
//     {
// 		ADC_GET_CONV_BOOLING(ADC1,&ADC_val);
// 		 if(ADC_val<100)
// 		{
// 			LCD_vidGotoXY_4bit(&lcd,1,8);
// 			LCD_vidDisplayChar_4bit(&lcd,'X');
// 			LCD_vidDisplayChar_4bit(&lcd,' ');
// 			LCD_vidDisplayChar_4bit(&lcd,' ');
// 
// 		}
// 		else if(ADC_val>100&&ADC_val<400)
// 		{
// 			LCD_vidGotoXY_4bit(&lcd,1,8);
// 			LCD_vidDisplayChar_4bit(&lcd,1);
// 			LCD_vidDisplayChar_4bit(&lcd,' ');
// 			LCD_vidDisplayChar_4bit(&lcd,' ');
// 
// 		}
// 		else if(ADC_val>400&&ADC_val<700)
// 		{
// 			LCD_vidGotoXY_4bit(&lcd,1,8);
// 			LCD_vidDisplayChar_4bit(&lcd,1);
// 			LCD_vidDisplayChar_4bit(&lcd,2);
// 			LCD_vidDisplayChar_4bit(&lcd,' ');
// 		}	
// 		else if(ADC_val>700)
// 		{
// 			LCD_vidGotoXY_4bit(&lcd,1,8);
// 			LCD_vidDisplayChar_4bit(&lcd,1);
// 			LCD_vidDisplayChar_4bit(&lcd,2);
// 			LCD_vidDisplayChar_4bit(&lcd,3);
// 		}
// 		else{}
// 				
//     }
// }
// 
/**************************************** ADC volume task end *************************************************/



/*************************************************** counter lcd EXTI ****************************************/
//#define F_CPU 16000000UL
// #include <util/delay.h>
// #include "SERVICES/Standard_Data_Types.h"
// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// #include "HAL/BUTTON/BUTTON.h"
// #include "HAL/7_SEGMENT/7_SEGMENT.h"
// #include "HAL/LCD/LCD_COMANDS.h"
// #include "HAL/LCD/LCD.h"
// #include "MCAL/GIE/GIE.h"
// #include "MCAL/EXTI/EXTI.h"

// volatile u32 counter=0;
// volatile u8 flag=0;
// void isr1(void)
// {
// 	EXTI_INT0_Interrupt_Disable();
// 	if(counter!=0)
// 	{
// 		counter--;
// 	}
// 	_delay_ms(1000);
// 	flag=1;
// 	EXTI_INT0_Interrupt_Flag_clear();
// 	EXTI_INT0_Interrupt_Enable();


// }

// void isr2(void)
// {
// 	EXTI_INT1_Interrupt_Disable();
// 	counter++;
// 	_delay_ms(1000);
// 	flag=1;
// 	EXTI_INT1_Interrupt_Flag_clear();
// 	EXTI_INT1_Interrupt_Enable();
// }


// LCD_4BIT_ST lcd={.lcd_pins[0]=PIN_B0_ID_8,
// 				 .lcd_pins[1]=PIN_B1_ID_9,
// 				 .lcd_pins[2]=PIN_B2_ID_10,
// 				 .lcd_pins[3]=PIN_B4_ID_12,
// 				 .lcd_pin_rs=PIN_A3_ID_3,
// 				 .lcd_pin_e=PIN_A2_ID_2};

// int main(void)
// {
// 	Port_vidInit();
// 	GIE_INIT();
// 	LCD_vidInit_4bit(&lcd);
// 	//LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
// 	LCD_vidDisplayString_4bit(&lcd,"counter:");
// 	EXI_INT(EXTI_INT0,EXTI_MODE_FALING_EDGE,isr1);
// 	EXI_INT(EXTI_INT1,EXTI_MODE_FALING_EDGE,isr2);
// 	while (1)
// 	{
//  		if(counter>=9999)
// 		{
// 			counter=0;
// 		}
// 		if(flag==1)
// 		{
// 			LCD_vidGotoXY_4bit(&lcd,1,9);
// 			LCD_vidDisplayString_4bit(&lcd,"    ");
//  			LCD_vidGotoXY_4bit(&lcd,1,9);
// 			LCD_vidDisplayNumber_4bit(&lcd,counter);
// 			_delay_ms(500);
// 			flag=0;
// 		}

// 	}

// }

/*****************************************************counter lcd EXTI end **********************************/


/*****************************************************************/
/*
//  * AVR_DRIVERS.c
//  *
//  * Created: 10/20/2023 8:33:11 PM
//  * Author : ahmed radwan
//  */
// #define F_CPU 16000000UL
// #include <util/delay.h>

// #include "HAL/7_SEGMENT/7_SEGMENT.h"
// #include "HAL/BUTTON/BUTTON.h"
// #include "HAL/KEY_PAD/KEY_PAD.h"
// #include "HAL/LCD/LCD.h"
// #include "HAL/LCD/LCD_COMANDS.h"
// #include "MCAL/DIO/DIO.h"
// #include "MCAL/EXTI/EXTI.h"
// #include "MCAL/GIE/GIE.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/TIMER0/TIMER0.h"
// #include "SERVICES/Bit_Wise_Operations.h"
// #include "SERVICES/Standard_Data_Types.h"


// void over_Flow_ISR(void);
// volatile u8 SECONDS = 0;

// LCD_4BIT_ST lcd = {.lcd_pins[0] = PIN_B0_ID_8,
//                    .lcd_pins[1] = PIN_B1_ID_9,
//                    .lcd_pins[2] = PIN_B2_ID_10,
//                    .lcd_pins[3] = PIN_B4_ID_12,
//                    .lcd_pin_rs = PIN_A3_ID_3,
//                    .lcd_pin_e = PIN_A2_ID_2};

// KEY_PAD_ST keypad = {
//     .key_pad_rows_pins[0] = DIO_C5_ID_21,
//     .key_pad_rows_pins[1] = DIO_C4_ID_20,
//     .key_pad_rows_pins[2] = DIO_C3_ID_19,
//     .key_pad_rows_pins[3] = DIO_C2_ID_18,
//     .key_pad_col_pins[0] = DIO_D7_ID_31,
//     .key_pad_col_pins[1] = DIO_D6_ID_30,
//     .key_pad_col_pins[2] = DIO_D5_ID_29,
//     .key_pad_col_pins[3] = DIO_D3_ID_27,
// };
// u8 keypad_value = '@';
// u8 key_status = KEY_NOT_PRESSED;
// int main(void) {
//   Port_vidInit();
//   GIE_INIT();
//   LCD_vidInit_4bit(&lcd);
//   // LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);

//   key_pad_Init(&keypad);
//   TIMER0_INT();
//   TIMER0_SET_OVRRFLOW_CALLBACK(over_Flow_ISR);
//   while (1) {
//   }
// }
// void over_Flow_ISR(void) {
//   SECONDS++;
//   if (SECONDS == 15) {
//     SECONDS = 0;
//     key_status = key_pad_Get_value(&keypad, &keypad_value);
//     if (KEY_PRESSED == key_status) {
//       LCD_vidDisplayChar_4bit(&lcd, keypad_value);
//     }
//   }
// }
/*****************************************************************/
/**********************************7amada task  *******************************/


/*
* AVR_DRIVERS.c
*
* Created: 10/20/2023 8:33:11 PM
* Author : ahmed radwan
*/
// #define F_CPU 16000000UL
// #include <util/delay.h>
// #include "SERVICES/Standard_Data_Types.h"
// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// #include "HAL/BUTTON/BUTTON.h"
// #include "HAL/7_SEGMENT/7_SEGMENT.h"
// #include "HAL/LCD/LCD_COMANDS.h"
// #include "HAL/LCD/LCD.h"
// #include "MCAL/GIE/GIE.h"
// #include "MCAL/EXTI/EXTI.h"
// #include "MCAL/TIMER0/TIMER0.h"
// #include "HAL/KEY_PAD/KEY_PAD.h"

// u8 *line="____________________";
// u8 hamada[] = {
// 	0B01110,
// 	0B01110,
// 	0B11111,
// 	0B10101,
// 	0B00100,
// 	0B01110,
// 	0B11011,
// 	0B00000
// };

// LCD_4BIT_ST lcd={.lcd_pins[0]=PIN_B0_ID_8,
// 	.lcd_pins[1]=PIN_B1_ID_9,
// 	.lcd_pins[2]=PIN_B2_ID_10,
// 	.lcd_pins[3]=PIN_B4_ID_12,
// 	.lcd_pin_rs=PIN_A3_ID_3,
// .lcd_pin_e=PIN_A2_ID_2};

// int main(void)
// {

// 	Port_vidInit();
// 	GIE_INIT();
// 	LCD_vidInit_4bit(&lcd);
// 	LCD_vidCraetCustomChar_4bit(&lcd,hamada,1);
// 	LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
// 	LCD_vidDisplayString_4bit(&lcd,line);
// 	LCD_vidGotoXY_4bit(&lcd,2,0);
// 	LCD_vidDisplayString_4bit(&lcd,line);
// 	LCD_vidGotoXY_4bit(&lcd,3,0);
// 	LCD_vidDisplayString_4bit(&lcd,line);
// 	LCD_vidGotoXY_4bit(&lcd,4,0);
// 	LCD_vidDisplayString_4bit(&lcd,line);
// 	LCD_vidGotoXY_4bit(&lcd,1,0);
// 	LCD_vidDisplayChar_4bit(&lcd,1);
// 	while (1)
// 	{

// 		//LCD_vidDisplayChar_4bit(&lcd,keypad_value);
// 		//1s
// 		for(u8 row=1;row<=4;row++)
// 		{

// 			for(u8 col=0;col<=18;col++)
// 			{
// 				LCD_vidGotoXY_4bit(&lcd,row,col);
// 				LCD_vidDisplayChar_4bit(&lcd,'_');
// 				LCD_vidDisplayChar_4bit(&lcd,1);
// 				_delay_ms(100);
// 			}
// 			LCD_vidGotoXY_4bit(&lcd,row,19);
// 			LCD_vidDisplayChar_4bit(&lcd,'_');
// 		}//1e
// 		//2s
// 		LCD_vidGotoXY_4bit(&lcd,1,10);
// 		LCD_vidDisplayChar_4bit(&lcd,' ');
// 		for(u8 row=1;row<=4;row++)
// 		{

// 			for(u8 col=0;col<=18;col++)
// 			{
// 				if(row==1&&col==10)
// 				{
// 					LCD_vidGotoXY_4bit(&lcd,row,col);
// 					LCD_vidDisplayChar_4bit(&lcd,' ');
// 					row=2;
// 				}
// 				else
// 				{
// 					LCD_vidGotoXY_4bit(&lcd,row,col);
// 					LCD_vidDisplayChar_4bit(&lcd,'_');
// 					LCD_vidDisplayChar_4bit(&lcd,1);
// 					_delay_ms(100);
// 				}
// 			}
// 			LCD_vidGotoXY_4bit(&lcd,row,19);
// 			LCD_vidDisplayChar_4bit(&lcd,'_');
// 		}//2e
// 		//3
// 		LCD_vidGotoXY_4bit(&lcd,1,10);
// 		LCD_vidDisplayChar_4bit(&lcd,'_');
// 		LCD_vidGotoXY_4bit(&lcd,3,10);
// 		LCD_vidDisplayChar_4bit(&lcd,' ');
// 		LCD_vidGotoXY_4bit(&lcd,4,10);
// 		LCD_vidDisplayChar_4bit(&lcd,'/');
// 		LCD_vidGotoXY_4bit(&lcd,4,1);
// 		u8 row=4;
// 		for(u8 col=0;col<=18;col++)
// 		{

// 			if(col==10)
// 			{
// 				LCD_vidGotoXY_4bit(&lcd,4,10);
// 				LCD_vidDisplayChar_4bit(&lcd,'_');
// 				LCD_vidGotoXY_4bit(&lcd,3,10);
// 				LCD_vidDisplayChar_4bit(&lcd,1);
// 				row=3;
// 				LCD_vidGotoXY_4bit(&lcd,3,10);
// 				LCD_vidDisplayChar_4bit(&lcd,' ');

// 			}
// 			else
// 			{
// 				LCD_vidGotoXY_4bit(&lcd,row,col);
// 				LCD_vidDisplayChar_4bit(&lcd,'_');
// 				LCD_vidDisplayChar_4bit(&lcd,1);
// 				_delay_ms(100);
// 			}
// 		}
// 		LCD_vidGotoXY_4bit(&lcd,3,19);
// 		LCD_vidDisplayChar_4bit(&lcd,'_');
// 		LCD_vidGotoXY_4bit(&lcd,3,10);
// 		LCD_vidDisplayChar_4bit(&lcd,'|');
// 		for(u8 finalcol=0;finalcol<10;finalcol++)
// 		{
// 			LCD_vidGotoXY_4bit(&lcd,3,finalcol);
// 			LCD_vidDisplayChar_4bit(&lcd,'_');
// 			LCD_vidDisplayChar_4bit(&lcd,1);
// 			_delay_ms(100);
// 		}
// 		break;

// 	}
// 	LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
// 	LCD_vidGotoXY_4bit(&lcd,2,6);
// 	LCD_vidDisplayString_4bit(&lcd,"GAME OVER");

// }
/**********************************7amada task end *******************************/






/**********************************calculator task  *******************************/
/*
 * AVR_DRIVERS.c
 *
 * Created: 10/20/2023 8:33:11 PM
 * Author : ahmed radwan
 */
// #define F_CPU 16000000UL
// #include <util/delay.h>
// #include "SERVICES/Standard_Data_Types.h"
// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// #include "HAL/BUTTON/BUTTON.h"
// #include "HAL/7_SEGMENT/7_SEGMENT.h"
// #include "HAL/LCD/LCD_COMANDS.h"
// #include "HAL/LCD/LCD.h"
// #include "MCAL/GIE/GIE.h"
// #include "MCAL/EXTI/EXTI.h"
// #include "MCAL/TIMER0/TIMER0.h"
// #include "HAL/KEY_PAD/KEY_PAD.h"
// 
// 
// void over_Flow_ISR(void);
// void math_error_display(void);
// void clculate(void);
// void clculate2(void);
// f32 result=0;
// volatile u8 SECONDS = 0;
// 
// LCD_4BIT_ST lcd = {.lcd_pins[0] = PIN_B0_ID_8,
//                    .lcd_pins[1] = PIN_B1_ID_9,
//                    .lcd_pins[2] = PIN_B2_ID_10,
//                    .lcd_pins[3] = PIN_B4_ID_12,
//                    .lcd_pin_rs = PIN_A3_ID_3,
//                    .lcd_pin_e = PIN_A2_ID_2};
// 
// KEY_PAD_ST keypad = {
//     .key_pad_rows_pins[0] = DIO_C5_ID_21,
//     .key_pad_rows_pins[1] = DIO_C4_ID_20,
//     .key_pad_rows_pins[2] = DIO_C3_ID_19,
//     .key_pad_rows_pins[3] = DIO_C2_ID_18,
//     .key_pad_col_pins[0] = DIO_D7_ID_31,
//     .key_pad_col_pins[1] = DIO_D6_ID_30,
//     .key_pad_col_pins[2] = DIO_D5_ID_29,
//     .key_pad_col_pins[3] = DIO_D3_ID_27,
// };
// u8 keypad_value = '@';
// u8 key_status = KEY_NOT_PRESSED;
// u8 counter=0;
// u32 inputs[20];
// u8 force_clear=1;
// int main(void) {
//   Port_vidInit();
//   GIE_INIT();
//   LCD_vidInit_4bit(&lcd);
//   LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
//   key_pad_Init(&keypad);
//   TIMER0_INT();
//   TIMER0_SET_OVRRFLOW_CALLBACK(over_Flow_ISR);
//   while (1) {
// 	  if (KEY_PRESSED == key_status) {
// 		  switch(keypad_value){
// 		  case 'c':
// 			key_status=KEY_NOT_PRESSED;
// 			LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
// 			LCD_vidSendcommand_4bit(&lcd,LCD_CURSOR_HOME);
// 			counter=0;
// 			for (u8 i=0;i<counter;i++)
// 			{
// 				inputs[i]=0;
// 			}
// 			force_clear=1;
// 			break;
// 		  case'=':
// 		   if (force_clear)
// 		   {
// 				key_status=KEY_NOT_PRESSED;
// 				force_clear=0;
// 				clculate2();
// 		   }
// 		    break;
// 		  default:
// 			key_status=KEY_NOT_PRESSED;
// 			inputs[counter]=keypad_value;
// 			counter++;
// 			if(counter>=20)
// 			{
// 				LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
// 				LCD_vidGotoXY_4bit(&lcd,2,5);
// 				LCD_vidDisplayString_4bit(&lcd,"maximum range");
// 			}
// 			break;
// 		  }
// ;
// 	  }
//   }
// }
// 
// 
// void math_error_display(void)
// {
// 	LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
// 	LCD_vidGotoXY_4bit(&lcd,2,5);
// 	LCD_vidDisplayString_4bit(&lcd,"math error");
// }
// 
// 
// 
// void clculate2(void){
// 	f32 f_operand=0;
// 	f32 s_operand=0;
// 	u8 operatorr=0;
// 	u8 indecator=1;
// 	s8 sign_helper1=1;
// 	s8 sign_helper2=1;
// 	f32 result=0;
// 	u8 firstsign_lock=0;
// 	u8 secondsign_lock=1;
// 	if(inputs[0]=='/'||inputs[0]=='*')
// 	{
// 		 math_error_display();
// 		return ;
// 	}
// 	for(u8 local_counter=0;local_counter<counter;local_counter++)
// 	{
// 		if(inputs[local_counter]>='0'&&inputs[local_counter]<='9'&&indecator==1)
// 		{
// 			f_operand=f_operand*10+inputs[local_counter]%48;//take first operand
// 			firstsign_lock=1;
// 			//indecator=2;
// 		}
// 		else if(inputs[local_counter]>='0'&&inputs[local_counter]<='9'&&indecator==3)
// 		{
// 			s_operand=s_operand*10+inputs[local_counter]%48;
// 		}
// 
// 		else if(indecator==1&&inputs[local_counter]=='-'&&firstsign_lock==0)
// 		{
// 			sign_helper1=-1;
// 			firstsign_lock=1;
// 		}
// 		else if(indecator==3&&inputs[local_counter]=='-')
// 		{
// 			sign_helper2=-1;
// 		}
// 		else if(indecator==1&&operatorr==0)
// 		{
// 			indecator=3;// ready to take second operand
// 			operatorr=inputs[local_counter];
// 		}
// 
// 	}
// 	 f_operand*=sign_helper1;
// 	 s_operand*=sign_helper2;
// 	switch(operatorr)
// 	{
// 		case '+':
// 			result=(f32)f_operand+s_operand;
// 			break;
// 		case '-':
// 			result=(f32)f_operand-s_operand;
// 			break;
// 		case '/':
// 			if(s_operand==0)
// 			{
// 				math_error_display();
// 				return ;
// 				break;
// 			}
// 			result=(f32)f_operand/s_operand;
// 			break;
// 		case '*':
// 			result=(f32)f_operand*s_operand;
// 			break;
// 	}
// 	if(result<0)
// 	{
// 		LCD_vidDisplayChar_4bit(&lcd,'-');
// 		result=result*-1;
// 	}
// 	LCD_vidDisplayFloatNumber_4bit(&lcd,result);
// 	return ;
// }
/*
void clculate(void){
	f32 f_operand=0;
	f32 s_operand=0;
	f32 result=0;
	u8 operator=0;
	u8 indecator=1;
	s8 sign_helper=-1;
	if(inputs[0]=='/'||inputs[0]=='*')
	{
		math_error_display();
		return ;
	}
	for(u8 local_counter=0;local_counter<counter;local_counter++)
	{
		if(inputs[local_counter]>='0'&&inputs[local_counter]<='9'&&indecator==1)
		{
			f_operand=f_operand*10+inputs[local_counter]%48;//take first operand
		}
		else if(inputs[local_counter]>='0'&&inputs[local_counter]<='9'&&indecator==2)
		{
			s_operand=s_operand*10+inputs[local_counter]%48;
		}
		else
		{
			indecator=2;// ready to take second operand
			operator=inputs[local_counter];
		}
	}
	switch(operator)
	{
		case '+':
		result=(f32)f_operand+s_operand;
		break;
		case '-':
		result=(f32)f_operand-s_operand;
		break;
		case '/':
		if(s_operand==0)
		{
			math_error_display();
			break;
		}
		result=(f32)f_operand/s_operand;
		break;
		case '*':
		result=(f32)f_operand*s_operand;
		break;
	}
	if(result<0)
	{
		LCD_vidDisplayChar_4bit(&lcd,'-');
		result=result*-1;
	}
	LCD_vidDisplayFloatNumber_4bit(&lcd,result);
	return ;
}
void over_Flow_ISR(void) {
	SECONDS++;// get the keypad by timer isr
	if (SECONDS == 15) {
		SECONDS = 0;
		key_status = key_pad_Get_value(&keypad, &keypad_value);
		if (KEY_PRESSED == key_status) {
			LCD_vidDisplayChar_4bit(&lcd, keypad_value);
		}
	}
}
*/
/**********************************calculator task end *******************************/

/**wdt**/


// int main(void)
// {
//	Port_vidInit();
//	GIE_INIT();
//	watch_dog_init();
//	u8 st =55;
//	while (1)
//	{
//		for(u8 i=0;i<250;i++)
//		{
//			st++;
//		}
//	}
//	return 0;
//}


	   /****************TRANSMIT********************/
/*
u8 str_ptr[]= {'u','a','r','t',' ','t','a','s','k'};
u8 var;
u8 i=0;
			   
int main(void)
{
  Port_vidInit();
  LCD_vidInit_4bit(&lcd);
  GIE_INIT();
  USART_INT();
  while (1)
  {
		while(i<=8)
		{
				 // USART_TRANSMIT_SYNC(&str_ptr[i]);
				  i++;
		}

  }
  return 0;
}
*/
/*
///////////////////////RECIVER
u8 str_ptr[9]= {};
u8 var;
u8 i=0;

int main(void)
{
	Port_vidInit();
	LCD_vidInit_4bit(&lcd);
	GIE_INIT();
	USART_INT();
	while (1)
	{
		
		USART_RECIVE_SYNC(&str_ptr[i]);
		i++;
		if(i==9)
		{
			LCD_vidDisplayString_4bit(&lcd,str_ptr);
			
		}
	}
	return 0;
}*/









/*******************************  spi        **********************************/
/*
 * AVR_DRIVERS.c
 *
 * Created: 10/20/2023 8:33:11 PM
 * Author : ahmed radwan
 */
/*
#include "SERVICES/Standard_Data_Types.h"
#include <util/delay.h>
#include "SERVICES/Bit_Wise_Operations.h"
#include "MCAL/PORT/PORT.h"
#include "MCAL/DIO/DIO.h"
#include "HAL/BUTTON/BUTTON.h"
#include "HAL/7_SEGMENT/7_SEGMENT.h"
#include "HAL/LCD/LCD_COMANDS.h"
#include "HAL/LCD/LCD.h"
#include "MCAL/GIE/GIE.h"
#include "MCAL/EXTI/EXTI.h"
#include "MCAL/TIMER0/TIMER0.h"
#include "HAL/KEY_PAD/KEY_PAD.h"
#include "MCAL/watch_DOG_TIMER/watch_dog.h"
#include "MCAL/ICUSW/ICUSW.h"
#include "MCAL/USART/USART.h"
#include "MCAL/SPI/Inc/SPI.h"
#include "MCAL/SPI/Inc/SPI_PRIV.h"


LCD_4BIT_ST lcd = {.lcd_pins[0] = PIN_B0_ID_8,
				   .lcd_pins[1] = PIN_B1_ID_9,
				   .lcd_pins[2] = PIN_B2_ID_10,
				   .lcd_pins[3] = PIN_B3_ID_11,
				   .lcd_pin_rs = PIN_A3_ID_3,
				   .lcd_pin_e = PIN_A2_ID_2};
				   
 SPI_st_T spi1master={
	 .CLK_phase=SPI_CLOCK_SAMPLE_LEADING,
	 .CLK_polarity=SPI_CLOCK_IDEL_HIGH,
	 .dataorder=SPI_LSB_FIRST_CFG,
	 .freq_cfg=SPI_FOSC_DIV_128,
	 .mode_s=SPI_MASTER_MODE,
	 .SPI_interrupt_cfg=SPI_INT_DIS_CFG
 };
  SPI_st_T spi1slave={
	  .CLK_phase=SPI_CLOCK_SAMPLE_LEADING,
	  .CLK_polarity=SPI_CLOCK_IDEL_HIGH,
	  .dataorder=SPI_LSB_FIRST_CFG,
	  .freq_cfg=SPI_FOSC_DIV_128,
	  .mode_s=SPI_SLAVE_MODE,
	  .SPI_interrupt_cfg=SPI_INT_DIS_CFG
  };
  
  
  u8 ch=0;
  u8 transmit_read;
  u8 reciver_read;
  
  u8* str1="Ahmed";
  u8* str2="Abdo1";
  
   u8* ch2='1';
   u8* ch1='1';
  
	*/   
	   /****************reciver********************/
/*

int main(void)
{
  Port_vidInit();
  LCD_vidInit_4bit(&lcd);
  GIE_INIT();
  spi_INT(&spi1slave);
  //spi_Recive_ASYNC(&ch);
  while (1)
  {

		  spi_Update_Recive('a',&ch);
		  LCD_vidDisplayChar_4bit(&lcd,ch);
  }
  return 0;
}*/
	   /****************TRANSMIT********************/
 /*
 int main(void)
 {
   Port_vidInit();
   LCD_vidInit_4bit(&lcd);
   GIE_INIT();
   spi_INT(&spi1master);
   while (1)
   {
			_delay_ms(50);
		   spi_SendRecive('8',&ch1);
		   LCD_vidDisplayChar_4bit(&lcd,ch1);
		   _delay_ms(100);
		  
   }
   return 0;
 
 }*/
 
 
 /*******************************  spi  end      **********************************/
 
 
  /*
int main(void)
{
  Port_vidInit();
  LCD_vidInit_4bit(&lcd);
  GIE_INIT();
  spi_INT(&spi1master);

  while (1)
  {
	spi_transmit(&spi1master,'g');
	_delay_ms(200);
  }
  return 0;
}*/
/*
int main(void)
{
	Port_vidInit();
	LCD_vidInit_4bit(&lcd);
	GIE_INIT();
	spi_INT(&spi1slave);
	spi_Recive_ASYNC(&Main_state);
	while (1)
	{
		LCD_vidDisplayChar_4bit(&lcd,Main_state);
		_delay_ms(200);

	}
	return 0;
}*/
/*************************smart home project *************************/

/*
 * AVR_DRIVERS.c
 *
 * Created: 10/20/2023 8:33:11 PM
 * Author : ahmed radwan
 */
/*
#include "SERVICES/Standard_Data_Types.h"
#include <util/delay.h>
#include "SERVICES/Bit_Wise_Operations.h"
#include "MCAL/PORT/PORT.h"
#include "MCAL/DIO/DIO.h"
#include "HAL/BUTTON/BUTTON.h"
#include "HAL/7_SEGMENT/7_SEGMENT.h"
#include "HAL/LCD/LCD_COMANDS.h"
#include "HAL/LCD/LCD.h"
#include "MCAL/GIE/GIE.h"
#include "MCAL/EXTI/EXTI.h"
#include "MCAL/TIMER0/TIMER0.h"
#include "HAL/KEY_PAD/KEY_PAD.h"
#include "MCAL/watch_DOG_TIMER/watch_dog.h"
#include "MCAL/ICUSW/ICUSW.h"
#include "MCAL/USART/USART.h"
#include "MCAL/SPI/Inc/SPI.h"
#include "MCAL/SPI/Inc/SPI_PRIV.h"

void Start_display(void);
void Room_display(void);
void Room1_fn(void);
void Room2_fn(void);
void Room3_fn(void);

LCD_4BIT_ST lcd = {.lcd_pins[0] = PIN_B0_ID_8,
				   .lcd_pins[1] = PIN_B1_ID_9,
				   .lcd_pins[2] = PIN_B2_ID_10,
				   .lcd_pins[3] = PIN_B3_ID_11,
				   .lcd_pin_rs = PIN_A3_ID_3,
				   .lcd_pin_e = PIN_A2_ID_2};
 SPI_st_T spi1slave={
	  .CLK_phase=SPI_CLOCK_SAMPLE_LEADING,
	  .CLK_polarity=SPI_CLOCK_IDEL_HIGH,
	  .dataorder=SPI_LSB_FIRST_CFG,
	  .freq_cfg=SPI_FOSC_DIV_128,
	  .mode_s=SPI_SLAVE_MODE,
	  .SPI_interrupt_cfg=SPI_INT_EN_CFG
  };
SPI_st_T spi1master={
	   .CLK_phase=SPI_CLOCK_SAMPLE_LEADING,
	   .CLK_polarity=SPI_CLOCK_IDEL_HIGH,
	   .dataorder=SPI_LSB_FIRST_CFG,
	   .freq_cfg=SPI_FOSC_DIV_128,
	   .mode_s=SPI_MASTER_MODE,
	   .SPI_interrupt_cfg=SPI_INT_DIS_CFG
  };
  u8 Main_state='9';
  u8 USART_state=0;
  u8 USART_Roomstate=0;
  u8 isr_int0_flag=0;
  u8 alarmstate=0;
  u8 closestate=0;
  

void EXTI0_ISR (void);

int main(void)
{
	Port_vidInit();
	LCD_vidInit_4bit(&lcd);
	GIE_INIT();
	USART_INT();
	spi_INT(&spi1slave);
	spi_Recive_ASYNC(&Main_state);
	EXI_INT(EXTI_INT0,EXTI_MODE_FALING_EDGE,EXTI0_ISR);
	//USART_vidRECIVE_Blokind(&USART_state);
	//LCD_vidDisplayChar_4bit(&lcd,Main_state);
	while (1)
	{
		if(0==isr_int0_flag)
		{
			switch (Main_state)
			{
				case'A'://open state
					Start_display();
					USART_vidRECIVE_Blokind(&USART_state);
					if(USART_state!=0)
					{
						switch(USART_state)
						{
						 case '1':
							Room1_fn();
							break;
						 case '2':
							Room2_fn();
							 break;
						 case '3':
							Room3_fn();
							 break;
						 default:
						 
						  break;
						}
						USART_state=0;
					}
					
				  break;
				case 'B'://alarm state
				    if(alarmstate==0)
					{
						LCD_vidDisplayString_4bit(&lcd,"alarm state");
						Dio_enuWriteChannel (DIO_D6_ID_30,DIO_PIN_HIGH);
						alarmstate=1;
					}
					break;
				case 'C':// close the home "ideal state"
				    if(closestate==0)
					{
						LCD_vidDisplayString_4bit(&lcd,"close state");
						closestate=1;
					}
					break;
			}
		}
	}
	return 0;
}

//LCD_vidDisplayString_4bit(&lcd,);
//LCD_vidGotoXY_4bit(&lcd,);

void Start_display(void)
{
	LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
	LCD_vidDisplayString_4bit(&lcd," Welcome to the home ");
	_delay_ms(300);
	LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
	LCD_vidGotoXY_4bit(&lcd,1,0);
	LCD_vidDisplayString_4bit(&lcd," CHOSE Room: ");
	LCD_vidGotoXY_4bit(&lcd,2,0);
	LCD_vidDisplayString_4bit(&lcd,"1)Room1: ");
	LCD_vidGotoXY_4bit(&lcd,3,0);
	LCD_vidDisplayString_4bit(&lcd,"2)Room2: ");
	LCD_vidGotoXY_4bit(&lcd,4,0);
	LCD_vidDisplayString_4bit(&lcd,"3)Room3: ");
}
void Room_display(void)
{
		LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
		LCD_vidGotoXY_4bit(&lcd,1,0);
		LCD_vidDisplayString_4bit(&lcd," CHOSE option: ");
		LCD_vidGotoXY_4bit(&lcd,2,0);
		LCD_vidDisplayString_4bit(&lcd,"1)light: ");
		LCD_vidGotoXY_4bit(&lcd,3,0);
		LCD_vidDisplayString_4bit(&lcd,"2)AiR cond: ");
}
void Room1_fn(void)
{
	Room_display();
	USART_vidRECIVE_Blokind(&USART_Roomstate);
	LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
	LCD_vidGotoXY_4bit(&lcd,1,0);
	if(USART_Roomstate=='1')
	{
	 Dio_enuFlipChannel(DIO_C2_ID_18);
	 LCD_vidDisplayString_4bit(&lcd,"air cond done ");
	 _delay_ms(200);
	
	}
	else if(USART_Roomstate=='2')
	{
	 Dio_enuFlipChannel(DIO_C3_ID_19);
	 LCD_vidDisplayString_4bit(&lcd,"light done ");
	 _delay_ms(200);
	}
	else
	{
		LCD_vidDisplayString_4bit(&lcd,"wrong choise ");
		_delay_ms(200);
	}
	USART_Roomstate=0;
}
void Room2_fn(void)
{
	Room_display();
	USART_vidRECIVE_Blokind(&USART_Roomstate);
	LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
	LCD_vidGotoXY_4bit(&lcd,1,0);
	if(USART_Roomstate=='1')
	{
		Dio_enuFlipChannel(DIO_C4_ID_20);
		LCD_vidDisplayString_4bit(&lcd,"air cond done ");
		_delay_ms(200);
		
	}
	else if(USART_Roomstate=='2')
	{
		Dio_enuFlipChannel(DIO_C5_ID_21);
		LCD_vidDisplayString_4bit(&lcd,"light done ");
		_delay_ms(200);
	}
	USART_Roomstate=0;
}
void Room3_fn(void)
{
	Room_display();
	USART_vidRECIVE_Blokind(&USART_Roomstate);
	LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
	LCD_vidGotoXY_4bit(&lcd,1,0);
	if(USART_Roomstate=='1')
	{
		Dio_enuFlipChannel(DIO_C6_ID_22);
		LCD_vidDisplayString_4bit(&lcd,"air cond done ");
		_delay_ms(200);
		
	}
	else if(USART_Roomstate=='2')
	{
		Dio_enuFlipChannel(DIO_C7_ID_23);
		LCD_vidDisplayString_4bit(&lcd,"light done ");
		_delay_ms(200);
	}
	USART_Roomstate=0;
}
void EXTI0_ISR (void)
{
		LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
		LCD_vidGotoXY_4bit(&lcd,1,0);

		Dio_enuWriteChannel (DIO_C2_ID_18,DIO_PIN_LOW);
		Dio_enuWriteChannel (DIO_C3_ID_19,DIO_PIN_LOW);
		Dio_enuWriteChannel (DIO_C4_ID_20,DIO_PIN_LOW);
		Dio_enuWriteChannel (DIO_C5_ID_21,DIO_PIN_LOW);
		Dio_enuWriteChannel (DIO_C6_ID_22,DIO_PIN_LOW);
		Dio_enuWriteChannel (DIO_C7_ID_23,DIO_PIN_LOW);
		if(0==isr_int0_flag)
		{
			Dio_enuWriteChannel (DIO_D5_ID_29,DIO_PIN_HIGH);
			Dio_enuWriteChannel (DIO_D6_ID_30,DIO_PIN_HIGH);
			isr_int0_flag=1;
		}
		else
		{
			Dio_enuWriteChannel (DIO_D5_ID_29,DIO_PIN_LOW);
			Dio_enuWriteChannel (DIO_D6_ID_30,DIO_PIN_LOW);
			isr_int0_flag=0;
		}
		
}*/
/**************************************** I2C start ****************************************************/
// /*
//  * AVR_DRIVERS.c
//  *
//  * Created: 10/20/2023 8:33:11 PM
//  * Author : ahmed radwan
//  */
//
// #include "SERVICES/Standard_Data_Types.h"
// #include <util/delay.h>
// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// #include "HAL/BUTTON/BUTTON.h"
// #include "HAL/7_SEGMENT/7_SEGMENT.h"
// #include "HAL/LCD/LCD_COMANDS.h"
// #include "HAL/LCD/LCD.h"
// #include "MCAL/GIE/GIE.h"
// #include "MCAL/EXTI/EXTI.h"
// #include "MCAL/TIMER0/TIMER0.h"
// #include "HAL/KEY_PAD/KEY_PAD.h"
// #include "MCAL/watch_DOG_TIMER/watch_dog.h"
// #include "MCAL/ICUSW/ICUSW.h"
// #include "MCAL/USART/USART.h"
// #include "MCAL/SPI/Inc/SPI.h"
// #include "MCAL/I2C/Inc/I2c.h"
//
//
//
// LCD_4BIT_ST lcd = {.lcd_pins[0] = PIN_B0_ID_8,
// 				   .lcd_pins[1] = PIN_B1_ID_9,
// 				   .lcd_pins[2] = PIN_B2_ID_10,
// 				   .lcd_pins[3] = PIN_B3_ID_11,
// 				   .lcd_pin_rs = PIN_A3_ID_3,
// 				   .lcd_pin_e = PIN_A2_ID_2};
//
// I2C_stCFG_t I2C_Master={.I2C_Mode=I2C_MASTER,
// 						.I2C_INTERRUPT_cfg=I2C_INTERUPT_DISABLE,
// 						.I2C_Slave_Adress=0x88,
// 						.I2C_clock_FREQ_TWBR_value=12,
// 						.I2C_PRESCALR_CFG=I2C_Prescaler_1};
//
// u8 read_data;
//
// int main(void)
// {
// 	Port_vidInit();
// 	LCD_vidInit_4bit(&lcd);
// 	GIE_INIT();
// 	I2C_Init(&I2C_Master);
//
// 	while (1)
// 	{
// 		I2C_SEND_FULL_FRAME_WRITE(0x77,0x55);
// 		_delay_ms(1000);
// 		I2C_SEND_FULL_FRAME_READ(0x0A,&read_data);
// 		_delay_ms(1000);
// 		I2C_SEND_FULL_FRAME_READ_NACK(0x0A,&read_data);
//
// 		_delay_ms(1000);
// 	}
// 	return 0;
// }
/**************************************************** I2C END *********************************************************/
/**************************************************** FULL USART *********************************************************/
// /*
//  * AVR_DRIVERS.c
//  *
//  * Created: 10/20/2023 8:33:11 PM
//  * Author : ahmed radwan
//  */
//
// #include "SERVICES/Standard_Data_Types.h"
// #include <util/delay.h>
// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// #include "HAL/BUTTON/BUTTON.h"
// #include "HAL/7_SEGMENT/7_SEGMENT.h"
// #include "HAL/LCD/LCD_COMANDS.h"
// #include "HAL/LCD/LCD.h"
// #include "MCAL/GIE/GIE.h"
// #include "MCAL/EXTI/EXTI.h"
// #include "MCAL/TIMER0/TIMER0.h"
// #include "HAL/KEY_PAD/KEY_PAD.h"
// #include "MCAL/watch_DOG_TIMER/watch_dog.h"
// #include "MCAL/ICUSW/ICUSW.h"
// #include "MCAL/USART/USART.h"
// #include "MCAL/SPI/Inc/SPI.h"
// #include "MCAL/I2C/Inc/I2c.h"
//
//
//
// LCD_4BIT_ST lcd = {.lcd_pins[0] = PIN_B0_ID_8,
// 				   .lcd_pins[1] = PIN_B1_ID_9,
// 				   .lcd_pins[2] = PIN_B2_ID_10,
// 				   .lcd_pins[3] = PIN_B3_ID_11,
// 				   .lcd_pin_rs = PIN_A3_ID_3,
// 				   .lcd_pin_e = PIN_A2_ID_2};
//
// void recive_ISR_MAIN(void);
// stUSART_CFG_T usart={
// 	.BaudRate=9600,
// 	.datalegnth=USART_8_bit_legn,
// 	.stopbits=USART_Two_stopBit_CFG,
// 	.parity=USART_ParityDISABLE_CFG,
// 	.EUSART_INT_When_Recive=USART_INT_ENABLE_CFG,
// 	.EUSART_INT_When_Transmit=USART_INT_DISABLE_CFG,
// 	.EUSART_INT_When_DataRegEmpty=USART_INT_DISABLE_CFG,
// 	.Recive_ISR=recive_ISR_MAIN
// };
// 	u16 data;
// int main(void)
// {
// 	Port_vidInit();
// 	LCD_vidInit_4bit(&lcd);
// 	GIE_INIT();
// 	USART_INT_FULL(&usart);
// 	//USART_INT();
//
// 	while (1)
// 	{
// 		//USART_vidRECIVE_Blokind(&usart,&data);
// 		//LCD_vidDisplayChar_4bit(&lcd,data);
// 		//USART_vidTRANSMIT_Blokind(&usart,'\r');
// 	}
// 	return 0;
// }
// void recive_ISR_MAIN(void)
// {   USART_vidReadData_Non_Bloking(&usart,&data);
// 	LCD_vidDisplayChar_4bit(&lcd,data);
// 	USART_vidTRANSMIT_Blokind(&usart,'\r');
// }
/**************************************************** FULL USART END *****************************************************/

/**************************************************** TIMER PWM *****************************************************/

//
// #include "SERVICES/Standard_Data_Types.h"
// #include <util/delay.h>
// #include "SERVICES/Bit_Wise_Operations.h"
// #include "MCAL/PORT/PORT.h"
// #include "MCAL/DIO/DIO.h"
// #include "HAL/BUTTON/Inc/BUTTON.h"
// #include "HAL/7_SEGMENT/Inc/7_SEGMENT.h"
// #include "HAL/LCD/Inc/LCD_COMANDS.h"
// #include "HAL/LCD/Inc/LCD.h"
// #include "MCAL/GIE/Inc/GIE.h"
// #include "MCAL/EXTI/EXTI.h"
// #include "MCAL/TIMER0/Inc/TIMER0.h"
// #include "HAL/KEY_PAD/Inc/KEY_PAD.h"
// #include "MCAL/watch_DOG_TIMER/Inc/watch_dog.h"
// #include "MCAL/ICUSW/Inc/ICUSW.h"
// #include "MCAL/USART/Inc/USART.h"
// #include "MCAL/SPI/Inc/SPI.h"
// #include "MCAL/I2C/Inc/I2c.h"
//
//
//
// LCD_4BIT_ST lcd = {.lcd_pins[0] = PIN_B0_ID_8,
// 				   .lcd_pins[1] = PIN_B1_ID_9,
// 				   .lcd_pins[2] = PIN_B2_ID_10,
// 				   .lcd_pins[3] = PIN_B3_ID_11,
// 				   .lcd_pin_rs = PIN_A3_ID_3,
// 				   .lcd_pin_e = PIN_A2_ID_2};
//
// int main(void)
// {
// 	Port_vidInit();
// 	LCD_vidInit_4bit(&lcd);
// 	GIE_INIT();
// 	TIMER0_INT();
// 	while (1)
// 	{
// 		for (u8 i=0;i<=100;)
// 		{
// 			TIMER0_PWM_SET_DUTYCYCLE(i);
// 			_delay_ms(200);
// 			i+=10;
// 		}
//
// 	}
// 	return 0;
// }


/**************************************************** TIMER PWM END ************************************************/
/*adc new test*/
/*
 * AVR_DRIVERS.c
 *
 * Created: 10/20/2023 8:33:11 PM
 * Author : ahmed radwan
 */

//#include "SERVICES/Standard_Data_Types.h"
//#include <util/delay.h>
//#include "SERVICES/Bit_Wise_Operations.h"
//#include "MCAL/PORT/PORT.h"
//#include "MCAL/DIO/DIO.h"
//#include "HAL/BUTTON/Inc/BUTTON.h"
//#include "HAL/7_SEGMENT/Inc/7_SEGMENT.h"
//#include "HAL/LCD/Inc/LCD_COMANDS.h"
//#include "HAL/LCD/Inc/LCD.h"
//#include "MCAL/GIE/Inc/GIE.h"
//#include "MCAL/EXTI/EXTI.h"
//#include "MCAL/ADC/Inc/ADC.h"
//#include "MCAL/TIMER0/Inc/TIMER0.h"
//#include "HAL/KEY_PAD/Inc/KEY_PAD.h"
//#include "MCAL/watch_DOG_TIMER/Inc/watch_dog.h"
//#include "MCAL/ICUSW/Inc/ICUSW.h"
//#include "MCAL/USART/Inc/USART.h"
//#include "MCAL/SPI/Inc/SPI.h"
//#include "MCAL/I2C/Inc/I2c.h"
//
//
//
//LCD_4BIT_ST lcd = {.lcd_pins[0] = PIN_B0_ID_8,
//				   .lcd_pins[1] = PIN_B1_ID_9,
//				   .lcd_pins[2] = PIN_B2_ID_10,
//				   .lcd_pins[3] = PIN_B3_ID_11,
//				   .lcd_pin_rs = PIN_A3_ID_3,
//				   .lcd_pin_e = PIN_A2_ID_2};
//				   
//stADC_cfg_t adc={.Interrupt=ADC_INT_DISABLE,
//				 .ADCprescaler=ADC_PRESCALER_DIV_ON_128,
//				 .ADCvolt_refrance=AVCC
//				 };
//u16 ADC_READ=0;
//					
//int main(void)
//{
//	Port_vidInit();
//	LCD_vidInit_4bit(&lcd);
//	GIE_INIT();
//	ADC_INIT(&adc);
//	while (1)
//	{
//		ADC_GET_CONV_BOOLING(0,&ADC_READ);
//		LCD_vidDisplayNumber_4bit(&lcd,ADC_READ);
//		_delay_ms(1000);
//		LCD_vidSendcommand_4bit(&lcd,LCD_CLEAR_DISPLAY);
//		
//	}
//	return 0;
//}
