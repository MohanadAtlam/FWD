/*
 * timer.c
 *
 * Created: 12/6/2022 9:19:06 PM
 *  Author: Mohanad Magdy
 */ 
#include "STD_Types.h"
#include "BIT_MATH.h"

#include "timer_interface.h"
#include "timer_register.h"

EN_DelayError_t TIMER0_DELAY(f64 time)
{
	u32 No_Of_OverFlows;
	//1.Comparing the input time to maximum time for each prescaler
	if(time<NO_PRESCALER_MAXTIME)
	{
		//2.Choosing the normal mode
		
		TCCR0=0x00;
		
		//3.Setting the initial value in TCNT register
		
		TCNT0=(u32)((NO_PRESCALER_MAXTIME-time)/0.000001);
		
		//4.Setting the prescaler to no prescaler and start the timer
		
		SET_BIT(TCCR0,CS00);
		
		//5.waiting for the flag to be up
		
		while((TIFR&(1<<0)) == 0);
		
		//6.Writing a logic one to the flag to return it to 0
		
		SET_BIT(TIFR,TOV0);
		
		//7.Stop the timer
		
		//TCCR0=0x00;
		
		return DELAY_OK;
	}
	else if(time<PRESCALER_8_MAXTIME)
	{
		//2.Choosing the normal mode
		
		TCCR0=0x00;
		
		//3.Setting the initial value in TCNT register
		
		TCNT0=(u32)((PRESCALER_8_MAXTIME-time)/0.000008);
		
		//4.Setting the prescaler to 8 prescaler and start the timer
		
		SET_BIT(TCCR0,CS01);
		
		//5.waiting for the flag to be up
		
		while((TIFR&(1<<0)) == 0);
		
		//6.Writing a logic one to the flag to return it to 0
		
		SET_BIT(TIFR,TOV0);
		
		//7.Stop the timer
		
		//TCCR0=0x00;
		
		return DELAY_OK;
	}
	else if(time<PRESCALER_64_MAXTIME)
	{
		//2.Choosing the normal mode
	
		TCCR0=0x00;
		
		//3.Setting the initial value in TCNT register
		
		TCNT0=(u32)((PRESCALER_64_MAXTIME-time)/0.000064);
		
		//4.Setting the prescaler to 64 prescaler and start the timer
		
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		
		//5.waiting for the flag to be up
		
		while((TIFR&(1<<0)) == 0);
		
		//6.Writing a logic one to the flag to return it to 0
		
		SET_BIT(TIFR,TOV0);
		
		//7.Stop the timer
		
		//TCCR0=0x00;

		return DELAY_OK;
	}
	else if(time<PRESCALER_256_MAXTIME)
	{
		//2.Choosing the normal mode
	
		TCCR0=0x00;
		
		//3.Setting the initial value in TCNT register
		
		TCNT0=(u32)((PRESCALER_256_MAXTIME-time)/0.000256);
		
		//4.Setting the prescaler to 256 prescaler and start the timer
		
		SET_BIT(TCCR0,CS02);
		
		//5.waiting for the flag to be up
		
		while((TIFR&(1<<0)) == 0);
		
		//6.Writing a logic one to the flag to return it to 0
		
		SET_BIT(TIFR,TOV0);
		
		//7.Stop the timer
		
		//TCCR0=0x00;

		return DELAY_OK;
	}
	else if(time<PRESCALER_1024_MAXTIME)
	{
		//2.Choosing the normal mode
		
		TCCR0=0x00;
		
		//3.Setting the initial value in TCNT register
		
		TCNT0=(u32)((PRESCALER_1024_MAXTIME-time)/0.001024);
		
		//4.Setting the prescaler to 1024 prescaler and start the timer
		
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS02);
		
		//5.waiting for the flag to be up
		
		while((TIFR&(1<<0)) == 0);
		
		//6.Writing a logic one to the flag to return it to 0
		
		SET_BIT(TIFR,TOV0);
		
		//7.Stop the timer
		
		//TCCR0=0x00;

		return DELAY_OK;		
	}
	else if(time>PRESCALER_1024_MAXTIME)
	{
		//2.Counting number of over flows
		
		No_Of_OverFlows=(time/PRESCALER_1024_MAXTIME)+1;
		
		while (No_Of_OverFlows)
		{
			//3.Choosing the normal mode
					
			TCCR0=0x00;
			
			//4.Setting the initial value in TCNT register
		
			TCNT0=(u32)(256-((time/0.001024)/(time/PRESCALER_1024_MAXTIME)));
		
			//5.Setting the prescaler to 1024 prescaler and start the timer
		
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS02);
		
			//6.waiting for the flag to be up
		
			while((TIFR&(1<<0)) == 0);
		
			//7.Writing a logic one to the flag to return it to 0
		
			SET_BIT(TIFR,TOV0);
			
			//8.Decreasing the variable of number of over flows
			
			No_Of_OverFlows--;
		}
		
		//8.Stop the timer
		
		//TCCR0=0x00;

		return DELAY_OK;		
	}
	else
	{
		return DELAY_ERROR;
	}
	return DELAY_ERROR;
}