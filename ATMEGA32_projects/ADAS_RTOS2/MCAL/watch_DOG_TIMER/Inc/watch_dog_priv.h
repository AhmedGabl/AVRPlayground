/*
 * watch_dog_priv.h
 *
 * Created: 10/27/2023 11:16:16 AM
 *  Author: ahmed radwan
 */ 


#ifndef WATCH_DOG_PRIV_H_
#define WATCH_DOG_PRIV_H_

#define MCUCSR (*((volatile ptr_u8)0x55))
#define WDTCR  (*((volatile ptr_u8)0x41))


#endif /* WATCH_DOG_PRIV_H_ */