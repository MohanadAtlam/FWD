/*
 * EUCAL_Drivers.c
 *
 * Created: 12/6/2022 2:53:56 PM
 * Author : Mohanad Magdy
 */ 
#include "LED_Driver/STD_Types.h"
#include "LED_Driver/LED.h"
#include "BUTTON_Driver/BUTTON.h"

#define F_CPU 1000000U

#include <util/delay.h>

#define LED_PORT		0
#define LED_PIN			0
#define HIGH			1
#define LOW				0

#define BUTTON_PORT		1
#define BUTTON_PIN		0
#define PULLED_UP		1
#define	FLOATING		0

int main(void)
{
	u8 ButtonValue;
	if (LED_INIT(LED_PORT,LED_PIN)==LED_OK && BUTTON_INIT(BUTTON_PORT,BUTTON_PIN,PULLED_UP)==BUTTON_OK)
	{
		while (1)
		{	
			
			if (BUTTON_READ(BUTTON_PORT,BUTTON_PIN,&ButtonValue)==BUTTON_OK)
			{
				if (ButtonValue==LOW)
				{
					if (LED_ON(LED_PORT,LED_PIN)==LED_OK)
					{
						_delay_ms(1000);
					}
					if (LED_OFF(LED_PORT,LED_PIN)==LED_OK)
					{
						_delay_ms(1000);
					}
				}
			}
			
		}
	}
}

