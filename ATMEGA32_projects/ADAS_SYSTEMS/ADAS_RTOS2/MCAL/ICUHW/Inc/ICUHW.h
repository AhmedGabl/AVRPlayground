/*
 * ICUHW.h
 *
 * Created: 10/28/2023 3:40:12 AM
 *  Author: ahmed radwan
 */ 


#ifndef ICUHW_H_
#define ICUHW_H_



#define ICU_NOISE_CANCELER_ACTIVATE()          SET_BIT(TCCR1B,7)
#define ICU_NOISE_CANCELER_DEACTIVATE()        CLR_BIT(TCCR1B,7)

#define ICU_DETECT_FALING_EDGE()               CLR_BIT(TCCR1B,6)
#define ICU_DETECT_RISING_EDGE()               SET_BIT(TCCR1B,6)

#define SET_PRESCALER(PRESCALER)			   (TCCR1B|=PRESCALER)

void ICUHW_voidEnable(void);
void ICUHW_voidDisable(void);
void ICUHW_u8Get_period(f32* totalperiod);
void ICUHW_u8Get_dutycycle(f32* duty);
void ICUHW_u8Get_On_period(f32* onperiod);


#endif /* ICUHW_H_ */