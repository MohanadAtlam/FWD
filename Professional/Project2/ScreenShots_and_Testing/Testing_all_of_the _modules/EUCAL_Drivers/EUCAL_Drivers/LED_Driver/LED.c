/*
 * LED.c
 *
 * Created: 12/6/2022 2:59:54 PM
 *  Author: Mohanad Magdy
 */ 
#include "STD_Types.h"
#include "BIT_MATH.h"

#include "../MCAL/DIO_Driver/DIO_interface.h"
#include "LED.h"

EN_LEDError_t LED_INIT(u8 LED_PORT, u8 LED_PIN)
{
	if (DIO_INIT(LED_PORT,LED_PIN,OUTPUT)==DIO_OK)
	{
		return LED_OK;
	}
	else
	{
		return LED_INIT_ERROR;
	}
}

EN_LEDError_t LED_ON(u8 LED_PORT, u8 LED_PIN)
{
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
	if (DIO_TogglePinValue(LED_PORT,LED_PIN)==DIO_OK)
	{
		return LED_OK;
	} 
	else
	{
		return LED_TOG_ERROR;
	}
}