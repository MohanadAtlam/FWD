/*
 * LED.h
 *
 * Created: 12/6/2022 3:00:17 PM
 *  Author: Mohanad Magdy
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO_DRIVER/DIO_interface.h"
#include "../../MCAL/TIMER_DELAY/timer_interface.h"
typedef enum EN_LEDError_t
{
	LED_OK, LED_INIT_ERROR, LED_ON_ERROR, LED_OFF_ERROR, LED_TOG_ERROR, LED_BLINK_ERROR	
}EN_LEDError_t;

EN_LEDError_t LED_INIT(u8 LED_PORT, u8 LED_PIN);//initialization of the led pin to an output

EN_LEDError_t LED_ON(u8 LED_PORT, u8 LED_PIN);//writing 1 to the led pin

EN_LEDError_t LED_OFF(u8 LED_PORT, u8 LED_PIN);//writing 0 to the led pin

EN_LEDError_t LED_TOG(u8 LED_PORT, u8 LED_PIN);//toggling the led pin

EN_LEDError_t LED_BLINK(u8 LED_PORT, u8 LED_PIN, u32 NOM_OF_BLINKS, f64 time);//blink the led

#endif /* LED_H_ */