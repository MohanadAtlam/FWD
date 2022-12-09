/*
 * LED.h
 *
 * Created: 12/6/2022 3:00:17 PM
 *  Author: Mohanad Magdy
 */ 


#ifndef LED_H_
#define LED_H_


typedef enum EN_LEDError_t
{
	LED_OK, LED_INIT_ERROR, LED_ON_ERROR, LED_OFF_ERROR, LED_TOG_ERROR	
}EN_LEDError_t;

EN_LEDError_t LED_INIT(u8 LED_PORT, u8 LED_PIN);

EN_LEDError_t LED_ON(u8 LED_PORT, u8 LED_PIN);

EN_LEDError_t LED_OFF(u8 LED_PORT, u8 LED_PIN);

EN_LEDError_t LED_TOG(u8 LED_PORT, u8 LED_PIN);

#endif /* LED_H_ */