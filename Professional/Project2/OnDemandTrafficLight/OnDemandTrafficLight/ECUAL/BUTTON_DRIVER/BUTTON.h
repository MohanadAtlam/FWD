/*
 * BUTTON.h
 *
 * Created: 12/6/2022 3:38:36 PM
 *  Author: Mohanad Magdy
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_


#include "../../MCAL/DIO_DRIVER/DIO_interface.h"
#include "../../MCAL/EXTI_DRIVER/EXTI_interface.h"

typedef enum EN_BUTTONError_t
{
	BUTTON_OK, BUTTON_INIT_ERROR, BUTTON_READ_ERROR
}EN_BUTTONError_t;

//function to initialize the button and put its initial state (pulled up / floating)
EN_BUTTONError_t BUTTON_INIT(u8 BUTTON_PORT, u8 BUTTON_PIN, u8 BUTTON_INIT_STATE); 

//function to read the button current state
EN_BUTTONError_t BUTTON_READ(u8 BUTTON_PORT, u8 BUTTON_PIN, u8 *BUTTON_VALUE);

#endif /* BUTTON_H_ */