/*
 * EXTI_Driver.c
 *
 * Created: 12/8/2022 1:02:27 AM
 * Author : Mohanad Magdy
 */ 
#include "STD_Types.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"

#include <avr/io.h>
#define F_CPU	1000000U
#include "util/delay.h"
void led_on();

int main(void)
{
	//enable the interrupt
	if(GIE_Enable()==GIE_OK);
	if(EXTI_IntEnable()==EXTI_OK);
	if(EXTI_Int0SenseControl()==EXTI_OK);
	//Passing the function that will be called of the interrupt happened
	if(EXTI_Int0SetCallBack(led_on)==EXTI_OK);
    DDRB |= (1<<0);
	
	while (1) 
    {
		PORTB |= (1<<0);
		_delay_ms(1000);
		PORTB &= ~(1<<0);
		_delay_ms(1000);
    }
}

void led_on()
{
	DDRA |= (1<<0);
	PORTA |= (1<<0);
	_delay_ms(3000);
	PORTA &= ~(1<<0);
}

