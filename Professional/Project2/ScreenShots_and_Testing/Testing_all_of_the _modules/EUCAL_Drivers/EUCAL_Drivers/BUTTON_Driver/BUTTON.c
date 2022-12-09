/*
 * BUTTON.c
 *
 * Created: 12/6/2022 3:38:48 PM
 *  Author: Mohanad Magdy
 */ 
#include "STD_Types.h"
#include "BIT_MATH.h"

#include "../MCAL/DIO_Driver/DIO_interface.h"
#include "BUTTON.h"


EN_BUTTONError_t BUTTON_INIT(u8 BUTTON_PORT, u8 BUTTON_PIN, u8 BUTTON_INIT_STATE)
{
	//calling the initialization DIO function and initializing the pin to input
	if (DIO_INIT(BUTTON_PORT,BUTTON_PIN,INPUT)==DIO_OK)
	{
		//then putting the state of the pin either pulled up or floating
		if (DIO_SetPinValue(BUTTON_PORT,BUTTON_PIN,BUTTON_INIT_STATE)==DIO_OK)
		{
			return BUTTON_OK;
		} 
		else
		{
			return BUTTON_INIT_ERROR;
		}
	} 
	else
	{
		return BUTTON_INIT_ERROR;
	}
}

EN_BUTTONError_t BUTTON_READ(u8 BUTTON_PORT, u8 BUTTON_PIN, u8 *BUTTON_VALUE)
{
	//calling the dio get pin value to get the current state of the button
	if (DIO_GetPinValue(BUTTON_PORT,BUTTON_PIN,BUTTON_VALUE)==DIO_OK)
	{
		return BUTTON_OK;
	} 
	else
	{
		return BUTTON_READ_ERROR;
	}
}