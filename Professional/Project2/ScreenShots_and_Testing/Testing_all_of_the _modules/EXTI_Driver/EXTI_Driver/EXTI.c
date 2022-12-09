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


void (*EXTI_pvInt0PtrFunc)(void)=NULL;


EN_GIEError_t GIE_Enable(void)
{
	SET_BIT(SREG,SREG_I);
	return GIE_OK;
}


EN_GIEError_t GIE_Disable(void)
{
	CLR_BIT(SREG,SREG_I);
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
	SET_BIT(GICR,GICR_INT0);
	
	return EXTI_OK;
}

EN_EXTIError_t EXTI_IntDisable(void)
{
	CLR_BIT(GICR,GICR_INT0);
	
	return EXTI_OK;
}

EN_EXTIError_t EXTI_Int0SetCallBack(void(*Copy_pvInt0Func)(void))
{
	if(Copy_pvInt0Func != 0)
	{
		EXTI_pvInt0PtrFunc=Copy_pvInt0Func;
		return EXTI_OK;
	}
	return SET_CALL_BACK_ERROR;
}

void __vector_1(void)  __attribute__((signal));
void __vector_1(void)
{
	if (EXTI_pvInt0PtrFunc != NULL)
	{
		EXTI_pvInt0PtrFunc();
	}
}