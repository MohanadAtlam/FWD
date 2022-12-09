/*
 * EXTI_register.h
 *
 * Created: 12/8/2022 1:24:17 AM
 *  Author: Mohanad Magdy
 */ 


#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

#define NULL			0

#define SREG			*((volatile u8*)0x5F)
#define SREG_I			7

#define GICR			*((volatile u8*)0x5B)
#define GICR_INT0		6

#define MCUCR			*((volatile u8*)0x55)
#define MCUCR_ISC01		1
#define MCUCR_ISC00		0




#endif /* EXTI_REGISTER_H_ */