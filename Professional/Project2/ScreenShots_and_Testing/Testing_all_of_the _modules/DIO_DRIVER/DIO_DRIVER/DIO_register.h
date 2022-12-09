/*
 * DIO_register.h
 *
 * Created: 12/5/2022 4:01:19 PM
 *  Author: Mohanad Magdy
 */ 


#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

//Port A registers
#define DDRA		 *((volatile u8*)0x3a)
#define PORTA        *((volatile u8*)0x3b)
#define PINA         *((volatile u8*)0x39)

//Port B registers
#define DDRB		 *((volatile u8*)0x37)
#define PORTB        *((volatile u8*)0x38)
#define PINB         *((volatile u8*)0x36)

//Port C registers
#define DDRC		 *((volatile u8*)0x34)
#define PORTC        *((volatile u8*)0x35)
#define PINC         *((volatile u8*)0x33)

//Port D registers
#define DDRD		 *((volatile u8*)0x31)
#define PORTD        *((volatile u8*)0x32)
#define PIND         *((volatile u8*)0x30)



#endif /* DIO_REGISTER_H_ */