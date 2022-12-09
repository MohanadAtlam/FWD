/*
 * timer_register.h
 *
 * Created: 12/6/2022 9:19:47 PM
 *  Author: Mohanad Magdy
 */ 


#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

//Timer 0
#define TCCR0		*((volatile u8*)0x53) //Timer/Counter Control Register
#define TCNT0		*((volatile u8*)0x52) //Timer/Counter Register
#define TIFR		*((volatile u8*)0x58) //Timer/Counter Interrupt Flag




#endif /* TIMER_REGISTER_H_ */