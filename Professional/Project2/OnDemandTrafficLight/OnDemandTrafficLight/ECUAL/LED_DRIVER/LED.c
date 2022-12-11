/*
 * LED.c
 *
 * Created: 12/6/2022 2:59:54 PM
 *  Author: Mohanad Magdy
 */ 
#include "STD_Types.h"
#include "BIT_MATH.h"



#include "LED.h"

EN_LEDError_t LED_INIT(u8 LED_PORT, u8 LED_PIN)
{
	//initializing the led pin as an output pin 
	if (DIO_INIT(LED_PORT,LED_PIN,OUTPUT)==DIO_OK)
	{
		return LED_OK;
	}
	else
	{
		return LED_INIT_ERROR;
	}
}

EN_LEDError_t LED_ON(u8 LED_PORT, u8 LED_PIN)//used after the led initialization
{
	//putting a logic 1 on the led pin 
	if (DIO_SetPinValue(LED_PORT,LED_PIN,HIGH)==DIO_OK)
	{
		return LED_OK;
	}
	else
	{
		return LED_ON_ERROR;
	}
}

EN_LEDError_t LED_OFF(u8 LED_PORT, u8 LED_PIN)
{
	//putting a logic 0 on the led pin 
	if (DIO_SetPinValue(LED_PORT,LED_PIN,LOW)==DIO_OK)
	{
		return LED_OK;
	}
	else
	{
		return LED_ON_ERROR;
	}
}

EN_LEDError_t LED_TOG(u8 LED_PORT, u8 LED_PIN)
{
	//Toggeling the pin value
	if (DIO_TogglePinValue(LED_PORT,LED_PIN)==DIO_OK)
	{
		return LED_OK;
	} 
	else
	{
		return LED_TOG_ERROR;
	}
}

//time entered here not the total time for the blinking 
//but its the time taken to blink the led
EN_LEDError_t LED_BLINK(u8 LED_PORT, u8 LED_PIN, u32 NOM_OF_BLINKS, f64 time)
{
	//using while to make the led blink for the needed amount
	while (NOM_OF_BLINKS)
	{
		//toggling the led 
		if (LED_TOG(LED_PORT,LED_PIN)==LED_OK)
		{
			//delaying for the amount passed to the function
			if (TIMER0_DELAY(time)==DELAY_OK)
			{
				//decreasing the no of blinks 
				NOM_OF_BLINKS--;
			}
			else
			{
				return LED_BLINK_ERROR;
			}
		} 
		else
		{
			return LED_BLINK_ERROR;
		}
	}
	return LED_OK;
}