/*
 * DIO_interface.h
 *
 * Created: 12/5/2022 4:02:11 PM
 *  Author: Mohanad Magdy
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

//Pin Values
#define DIO_u8PIN_HIGH            1
#define DIO_u8PIN_LOW             0

//Port Values
#define DIO_PORT_HIGH             0xff
#define DIO_PORT_LOW              0

//Ports
#define DIO_u8PORTA               0
#define DIO_u8PORTB               1
#define DIO_u8PORTC               2
#define DIO_u8PORTD               3

//Pins numbers
#define DIO_u8PIN0                0
#define DIO_u8PIN1                1
#define DIO_u8PIN2                2
#define DIO_u8PIN3                3
#define DIO_u8PIN4                4
#define DIO_u8PIN5                5
#define DIO_u8PIN6                6
#define DIO_u8PIN7                7

//Another defines
#define OUTPUT					  1
#define INPUT					  0
#define PULLED_UP				  1
#define PULLED_DOWN				  0
#define HIGH					  1
#define LOW						  0

//Error state enum
typedef enum EN_DIOError_t
{
	DIO_OK, INIT_ERROR, SET_PIN_ERROR, TOG_PIN_ERROR, SET_PORT_ERROR, GET_PIN_ERROR
}EN_DIOError_t;

EN_DIOError_t DIO_INIT(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Dir); //function to initialize the pin Direction

EN_DIOError_t DIO_SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value); //function to set the pin value either on or off

EN_DIOError_t DIO_TogglePinValue(u8 Copy_u8Port , u8 Copy_u8Pin); //function to toggle the pin

EN_DIOError_t DIO_SetPortValue(u8 Copy_u8Port , u8 Copy_u8Value); //function to set the value of the all pins in the port

EN_DIOError_t DIO_GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 *Copy_u8Value); //function to read the value of the pin




#endif /* DIO_INTERFACE_H_ */