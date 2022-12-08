/*
 * EXTI.c
 *
 * Created: 12/8/2022 1:23:34 AM
 *  Author: Mohanad Magdy
 */ 
#include "STD_Types.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_register.h"

//pointer to function to pass to it the function needed to work when the interrupt happen
void (*EXTI_pvInt0PtrFunc)(void)=NULL;


EN_GIEError_t GIE_Enable(void)
{
	//enabling the general interrupt 
	SET_BIT(SREG,SREG_I);
	return GIE_OK;
}

EN_EXTIError_t EXTI_Int0SenseControl(void)
{
	/*Set INT sense control to Rising edge*/
	SET_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);
	
	return EXTI_OK;
}

EN_EXTIError_t EXTI_IntEnable(void)
{
	//Enabling the external interrupt at int0
	SET_BIT(GICR,GICR_INT0);
	
	return EXTI_OK;
}

EN_EXTIError_t EXTI_INIT(void)
{
	//enable the general interrupt
	if (GIE_Enable()==GIE_OK)
	{
		//setting the sense control to rising edge
		if (EXTI_Int0SenseControl()==EXTI_OK)
		{
			//enabling the int0
			if (EXTI_IntEnable()==EXTI_OK)
			{
				return EXTI_OK;
			} 
			else
			{
				return EXTI_INIT_ERROR;
			}
		} 
		else
		{
			return EXTI_INIT_ERROR;
		}
	} 
	else
	{
		return EXTI_INIT_ERROR;
	}
	
}


void EXTI_Int0SetCallBack(void(*Copy_pvInt0Func)(void))
{
	//checking if the pointer to the function is null or not
	if(Copy_pvInt0Func != 0)
	{
		//passing the passed function to the pointer to function which will work when the interrupt happen
		EXTI_pvInt0PtrFunc=Copy_pvInt0Func;
	}
}

void __vector_1(void)  __attribute__((signal));
void __vector_1(void)
{
	if (EXTI_pvInt0PtrFunc != NULL)
	{
		EXTI_pvInt0PtrFunc();
	}
}