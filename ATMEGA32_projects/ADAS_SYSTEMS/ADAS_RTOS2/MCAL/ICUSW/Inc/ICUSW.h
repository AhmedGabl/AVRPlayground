/*
 * ICUSW.h
 *
 * Created: 10/27/2023 12:44:51 PM
 *  Author: ahmed radwan
 */ 


#ifndef ICUSW_H_
#define ICUSW_H_



void ICUSW_voidEnable(void);
void ICUSW_voidDisable(void);
void ICUSW_u8Get_period(f32* totalperiod);
void ICUSW_u8Get_dutycycle(f32* duty);
void ICUSW_u8Get_On_period(f32* onperiod);


#endif /* ICUSW_H_ */