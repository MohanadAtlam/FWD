/*
 * PEDESTRAIN_MODE.c
 *
 * Created: 12/8/2022 6:26:46 PM
 *  Author: Mohanad Magdy
 */ 
#include "../STD_Types.h"
#include "../BIT_MATH.h"
#include "../../ECUAL/LED_DRIVER/LED.h"
#include "../../MCAL/TIMER_DELAY/timer_interface.h"
#include "../../MCAL/DIO_DRIVER/DIO_interface.h"

#include "PEDESTRIAN_MODE.h"

void PEDESTRIAN_MODE(void)
{
	u8 pin_Value_GREEN,pin_Value_YELLOW,pin_Value_RED;
	
	if (LED_INIT(PEDESTRIAN_MODE_LEDS_PORT,GREEN_LED)==LED_OK&&LED_INIT(PEDESTRIAN_MODE_LEDS_PORT,YELLOW_LED)==LED_OK&&LED_INIT(PEDESTRIAN_MODE_LEDS_PORT,RED_LED)==LED_OK)
	{
		//Checking the values of all the normal mode pins
		if (DIO_GetPinValue(NORMAL_MODE_LEDS_PORT,GREEN_LED,&pin_Value_GREEN)==DIO_OK&&DIO_GetPinValue(NORMAL_MODE_LEDS_PORT,YELLOW_LED,&pin_Value_YELLOW)==DIO_OK&&DIO_GetPinValue(NORMAL_MODE_LEDS_PORT,RED_LED,&pin_Value_RED)==DIO_OK)
		{
			//if the red led in normal mode is on
			if (pin_Value_RED==1)
			{
				if (mode1()==PED_MODE_OK);
			}
			//if the green or yellow led is on
			else if (pin_Value_GREEN==1 || pin_Value_YELLOW==1)
			{
				if (mode2()==PED_MODE_OK);	
			}
		}
	} 
}

PED_MODES_Error mode1(void)
{
	u8 BlinksNo = 10;
	//writing logic 0 to the red led in normal mode
	if (LED_OFF(NORMAL_MODE_LEDS_PORT,RED_LED)==LED_OK)
	{
		//writing logic 1 to red led in normal mode and also green led in pedestrian mode for 5 secs
		if (LED_ON(NORMAL_MODE_LEDS_PORT,RED_LED)==LED_OK&&LED_ON(PEDESTRIAN_MODE_LEDS_PORT,GREEN_LED)==LED_OK&&TIMER0_DELAY(5)==DELAY_OK)
		{
			
			if (LED_OFF(NORMAL_MODE_LEDS_PORT,RED_LED)==LED_OK)
			{
				//looping to blink the leds manually 10 times each take 0.5 secs
				while(BlinksNo)
				{
					//Toggling the yellow leds (cars and pedestrian)
					if (LED_TOG(NORMAL_MODE_LEDS_PORT,YELLOW_LED)==LED_OK&&LED_TOG(PEDESTRIAN_MODE_LEDS_PORT,YELLOW_LED)==LED_OK)
					{
						if (TIMER0_DELAY(0.5)==DELAY_OK);
						//decreasing the blinks number
						BlinksNo--;
					}
					else
					{
						return PED_MODE1_ERROR;
					}
				}
				
				//closing all the leds
				if (LED_OFF(NORMAL_MODE_LEDS_PORT,GREEN_LED)==LED_OK&&LED_OFF(NORMAL_MODE_LEDS_PORT,YELLOW_LED)==LED_OK&&LED_OFF(NORMAL_MODE_LEDS_PORT,RED_LED)==LED_OK)
				{
					if (LED_OFF(PEDESTRIAN_MODE_LEDS_PORT,GREEN_LED)==LED_OK&&LED_OFF(PEDESTRIAN_MODE_LEDS_PORT,YELLOW_LED)==LED_OK&&LED_OFF(PEDESTRIAN_MODE_LEDS_PORT,RED_LED)==LED_OK)
					{
						//opening the green led for cars and red for pedestrian
						if (LED_ON(NORMAL_MODE_LEDS_PORT,GREEN_LED)==LED_OK&&LED_ON(PEDESTRIAN_MODE_LEDS_PORT,RED_LED)==LED_OK&&TIMER0_DELAY(2)==DELAY_OK)
						{
							//closing them then returning to the normal mode
							if (LED_OFF(NORMAL_MODE_LEDS_PORT,GREEN_LED)==LED_OK&&LED_OFF(PEDESTRIAN_MODE_LEDS_PORT,RED_LED)==LED_OK)
							{
								return PED_MODE_OK;
							}
						}
					}
				}
			}
		}
	}
	return PED_MODE1_ERROR; 	
}

PED_MODES_Error mode2(void)
{
	u8 BlinksNo = 10;
	//writing logic 0 to the green and yellow led in normal mode
	if (LED_OFF(NORMAL_MODE_LEDS_PORT,GREEN_LED)==LED_OK&&LED_OFF(NORMAL_MODE_LEDS_PORT,YELLOW_LED)==LED_OK)
	{
		//looping to blink the leds manually 10 times each take 0.5 secs
		while(BlinksNo)
		{
			//Toggling the yellow leds (cars and pedestrian)
			if (LED_TOG(NORMAL_MODE_LEDS_PORT,YELLOW_LED)==LED_OK&&LED_TOG(PEDESTRIAN_MODE_LEDS_PORT,YELLOW_LED)==LED_OK)
			{
				if (TIMER0_DELAY(0.5)==DELAY_OK);
				//decreasing the blinks number
				BlinksNo--;
			} 
			else
			{
				return PED_MODE2_ERROR;
			}
		}
		//returning the counter to its initial value again preparing it to enter the next loop
		BlinksNo=10;
		//closing the yellow leds
		if (LED_OFF(NORMAL_MODE_LEDS_PORT,YELLOW_LED)==LED_OK&&LED_OFF(PEDESTRIAN_MODE_LEDS_PORT,YELLOW_LED)==LED_OK)
		{
			//writing logic 1 to red led in normal mode and also green led in pedestrian mode for 5 secs
			if (LED_ON(NORMAL_MODE_LEDS_PORT,RED_LED)==LED_OK&&LED_ON(PEDESTRIAN_MODE_LEDS_PORT,GREEN_LED)==LED_OK&&TIMER0_DELAY(5)==DELAY_OK)
			{
				
				if (LED_OFF(NORMAL_MODE_LEDS_PORT,RED_LED)==LED_OK)
				{
					//looping to blink the leds manually 10 times each take 0.5 secs
					while(BlinksNo)
					{
						//Toggling the yellow leds (cars and pedestrian)
						if (LED_TOG(NORMAL_MODE_LEDS_PORT,YELLOW_LED)==LED_OK&&LED_TOG(PEDESTRIAN_MODE_LEDS_PORT,YELLOW_LED)==LED_OK)
						{
							if (TIMER0_DELAY(0.5)==DELAY_OK);
							//decreasing the blinks number
							BlinksNo--;
						}
						else
						{
							return PED_MODE2_ERROR;
						}
					}
					
					//closing all the leds
					if (LED_OFF(NORMAL_MODE_LEDS_PORT,GREEN_LED)==LED_OK&&LED_OFF(NORMAL_MODE_LEDS_PORT,YELLOW_LED)==LED_OK&&LED_OFF(NORMAL_MODE_LEDS_PORT,RED_LED)==LED_OK)
					{
						if (LED_OFF(PEDESTRIAN_MODE_LEDS_PORT,GREEN_LED)==LED_OK&&LED_OFF(PEDESTRIAN_MODE_LEDS_PORT,YELLOW_LED)==LED_OK&&LED_OFF(PEDESTRIAN_MODE_LEDS_PORT,RED_LED)==LED_OK)
						{
							//opening the green led for cars and red for pedestrian
							if (LED_ON(NORMAL_MODE_LEDS_PORT,GREEN_LED)==LED_OK&&LED_ON(PEDESTRIAN_MODE_LEDS_PORT,RED_LED)==LED_OK&&TIMER0_DELAY(2)==DELAY_OK)
							{
								//closing them then returning to the normal mode
								if (LED_OFF(NORMAL_MODE_LEDS_PORT,GREEN_LED)==LED_OK&&LED_OFF(PEDESTRIAN_MODE_LEDS_PORT,RED_LED)==LED_OK)
								{
									return PED_MODE_OK;
								}
							}
						}
					}
				}
			}
		}
	}
	return PED_MODE2_ERROR;
}