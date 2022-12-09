/*
 * DIO_DRIVER.c
 *
 * Created: 12/9/2022 2:52:39 PM
 * Author : Mohanad magdy
 */ 

#include "STD_Types.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"


int main(void)
{
	//initializing the pin0 in port A as output pin
    if(DIO_INIT(DIO_u8PORTA,DIO_u8PIN0,OUTPUT)==DIO_OK)
	{
		//setting its value to high
		if (DIO_SetPinValue(DIO_u8PORTA,DIO_u8PIN0,HIGH)==DIO_OK);
	}
	//initializing the pin0 in port B as output pin
    if(DIO_INIT(DIO_u8PORTB,DIO_u8PIN0,OUTPUT)==DIO_OK)
    {
		//setting its value to LOW
	    if (DIO_SetPinValue(DIO_u8PORTB,DIO_u8PIN0,LOW)==DIO_OK);
    }	
	//initializing the pin0 in port C as input pin
	if (DIO_INIT(DIO_u8PORTC,DIO_u8PIN0,INPUT)==DIO_OK)
	{
		//toggling its value
		if(DIO_TogglePinValue(DIO_u8PORTC,DIO_u8PIN0)==DIO_OK);
	}
}

