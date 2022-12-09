/*
 * DIO.c
 *
 * Created: 12/5/2022 4:00:50 PM
 *  Author: Mohanad Magdy
 */ 
#include "STD_Types.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_register.h"

EN_DIOError_t DIO_INIT(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Dir)
{
	//checking the Direction passed to the function
	if (Copy_u8Dir == INPUT)
	{
		//switching to get the port passed to the function
		switch ( Copy_u8Port )
		{
			//clearing the DDRX bit to make the direction of the bit as input
			case DIO_u8PORTA : CLR_BIT(DDRA,Copy_u8Pin);
			break;
			case DIO_u8PORTB : CLR_BIT(DDRB,Copy_u8Pin);
			break;
			case DIO_u8PORTC : CLR_BIT(DDRC,Copy_u8Pin);
			break;
			case DIO_u8PORTD : CLR_BIT(DDRD,Copy_u8Pin);
			break;
		}
		return DIO_OK;
	}
	else if (Copy_u8Dir == OUTPUT)
	{
		switch ( Copy_u8Port )
		{
			//same as the previous switch but here we set the bit
			case DIO_u8PORTA : SET_BIT(DDRA,Copy_u8Pin);
			break;
			case DIO_u8PORTB : SET_BIT(DDRB,Copy_u8Pin);
			break;
			case DIO_u8PORTC : SET_BIT(DDRC,Copy_u8Pin);
			break;
			case DIO_u8PORTD : SET_BIT(DDRD,Copy_u8Pin);
			break;
		}
		return DIO_OK;
	}
	else
	{
		//error handling
		return INIT_ERROR;
	}	
}

EN_DIOError_t DIO_SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{
	//checking the value passed to the function
		if (Copy_u8Value == DIO_u8PIN_LOW)
		{
			//switching to get the port passed to the function
			switch ( Copy_u8Port )
			{
				//clearing the bit 
				case DIO_u8PORTA : CLR_BIT(PORTA,Copy_u8Pin);
				break;
				case DIO_u8PORTB : CLR_BIT(PORTB,Copy_u8Pin);
				break;
				case DIO_u8PORTC : CLR_BIT(PORTC,Copy_u8Pin);
				break;
				case DIO_u8PORTD : CLR_BIT(PORTD,Copy_u8Pin);
				break;
			}
			return DIO_OK;
		}
		else if (Copy_u8Value == DIO_u8PIN_HIGH)
		{
			switch ( Copy_u8Port )
			{
				//same as the previous switch but here we set the bit
				case DIO_u8PORTA : SET_BIT(PORTA,Copy_u8Pin);
				break;
				case DIO_u8PORTB : SET_BIT(PORTB,Copy_u8Pin);
				break;
				case DIO_u8PORTC : SET_BIT(PORTC,Copy_u8Pin);
				break;
				case DIO_u8PORTD : SET_BIT(PORTD,Copy_u8Pin);
				break;
			}
			return DIO_OK;
		}
		else
		{
			//error handling
			return SET_PIN_ERROR;
		}
}

EN_DIOError_t DIO_TogglePinValue(u8 Copy_u8Port , u8 Copy_u8Pin)
{
			switch ( Copy_u8Port )
			{
				//toggeling the bit
				case DIO_u8PORTA : TOG_BIT(PORTA,Copy_u8Pin);
				break;
				case DIO_u8PORTB : TOG_BIT(PORTB,Copy_u8Pin);
				break;
				case DIO_u8PORTC : TOG_BIT(PORTC,Copy_u8Pin);
				break;
				case DIO_u8PORTD : TOG_BIT(PORTD,Copy_u8Pin);
				break;
				default:
				//error handling
				return TOG_PIN_ERROR;
				break;
			}
			return DIO_OK;
}

EN_DIOError_t DIO_SetPortValue(u8 Copy_u8Port , u8 Copy_u8Value)
{
	//switching to know the port
		switch ( Copy_u8Port )
		{
			//setting or clearing all the port pins
			case DIO_u8PORTA : PORTA = Copy_u8Value;
			break;
			case DIO_u8PORTB : PORTB = Copy_u8Value;
			break;
			case DIO_u8PORTC : PORTC = Copy_u8Value;
			break;
			case DIO_u8PORTD : PORTD = Copy_u8Value;
			break;
			default:
			//error handling
			return SET_PORT_ERROR;
			break;
		}
		return DIO_OK;
}

EN_DIOError_t DIO_GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 *Copy_u8Value)
{
		u8 Local_u8PinValue ;

		switch ( Copy_u8Port )
		{
			//getting the pin value
			case DIO_u8PORTA : Local_u8PinValue = GET_BIT(PINA,Copy_u8Pin);
			break;
			case DIO_u8PORTB : Local_u8PinValue = GET_BIT(PINB,Copy_u8Pin);
			break;
			case DIO_u8PORTC : Local_u8PinValue = GET_BIT(PINC,Copy_u8Pin);
			break;
			case DIO_u8PORTD : Local_u8PinValue = GET_BIT(PIND,Copy_u8Pin);
			break;
			default:
			//error handling
			return GET_PIN_ERROR;
		}
		//then passing it to the pointer
		*Copy_u8Value = Local_u8PinValue;

		return DIO_OK;
}