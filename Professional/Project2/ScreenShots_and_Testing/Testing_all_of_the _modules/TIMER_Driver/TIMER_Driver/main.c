/*
 * TIMER_Driver.c
 *
 * Created: 12/6/2022 9:18:04 PM
 * Author : Mohanad Magdy
 */ 

#include <avr/io.h>
#include "BIT_MATH.h"
#include "STD_Types.h"
#include "timer_interface.h"


int main(void)
{
    /* Replace with your application code */
	DDRA |=(1<<0);
    while (1) 
    {
		PORTA|=(1<<0);
		if (TIMER0_DELAY(1));
		
		PORTA&= ~(1<<0);
		if (TIMER0_DELAY(1));
    }
}

