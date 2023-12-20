/*
 * Standard_Data_Types.h
 *
 * Created: 10/20/2023 9:03:28 PM
 *  Author: ahmed radwan
 */ 


#ifndef STANDARD_DATA_TYPES_H_
#define STANDARD_DATA_TYPES_H_

typedef unsigned char        u8;
typedef unsigned short       u16;
typedef unsigned long        u32;


typedef signed char          s8;
typedef signed short         s16;
typedef signed long          s32;

typedef float				  f32;
typedef double				  f64;
typedef unsigned char*        ptr_u8;
typedef unsigned short*       ptr_u16;
typedef unsigned long*        ptr_u32;


typedef signed char*          ptr_s8;
typedef signed short*         ptr_s16;
typedef signed long*          ptr_s32;

#define ZERO_INIT 0

#define NULL ((void*)0)
#define CONC(B7,B6,B5,B4,B3,B2,B1,B0)                   CONC_HELPER(B7,B6,B5,B4,B3,B2,B1,B0)
#define CONC_HELPER(B7,B6,B5,B4,B3,B2,B1,B0)           (0b##B7##B6##B5##B4##B3##B2##B1##B0)

#define F_CPU 16000000UL

typedef  void (*CALL_BACK_FN_TYPE)(void);


#endif /* STANDARD_DATA_TYPES_H_ */