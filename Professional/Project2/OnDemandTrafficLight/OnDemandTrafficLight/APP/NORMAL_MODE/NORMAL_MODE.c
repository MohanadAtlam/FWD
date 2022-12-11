/*
 * NORMAL_MODE.c
 *
 * Created: 12/8/2022 3:38:03 PM
 *  Author: Mohanad Magdy
 */
#include "../STD_Types.h" 
#include "../BIT_MATH.h"



#include "NORMAL_MODE.h"

void NORMAL_MODE(void)
{
	//initializing all the led pins to output pins
	if (LED_INIT(NORMAL_MODE_LEDS_PORT,GREEN_LED)==LED_OK&&LED_INIT(NORMAL_MODE_LEDS_PORT,YELLOW_LED)==LED_OK&&LED_INIT(NORMAL_MODE_LEDS_PORT,RED_LED)==LED_OK)
	{
		//writing a logic 1 on the green led and delaying for 5 secs 
		if (LED_ON(NORMAL_MODE_LEDS_PORT,GREEN_LED)==LED_OK&&TIMER0_DELAY(5)==DELAY_OK)
		{
			//blinking the yellow led 10 times each time delayed for 0.5 seconds and writing logic 0 to the green led
			if (LED_OFF(NORMAL_MODE_LEDS_PORT,GREEN_LED)==LED_OK&&LED_BLINK(NORMAL_MODE_LEDS_PORT,YELLOW_LED,10,0.5)==LED_OK)
			{
				//and for the last step writing logic 1 to the red led for 5 secs and writing logic 0 to yellow led
				if (LED_OFF(NORMAL_MODE_LEDS_PORT,YELLOW_LED)==LED_OK&&LED_ON(NORMAL_MODE_LEDS_PORT,RED_LED)==LED_OK&&TIMER0_DELAY(5)==DELAY_OK)
				{
					//writing a 0 logic to all the pins to prepare for the next loop of this function in the app.c
					if (LED_OFF(NORMAL_MODE_LEDS_PORT,GREEN_LED)==LED_OK&&LED_OFF(NORMAL_MODE_LEDS_PORT,YELLOW_LED)==LED_OK&&LED_OFF(NORMAL_MODE_LEDS_PORT,RED_LED)==LED_OK);
				}
			}
		}
	}
}