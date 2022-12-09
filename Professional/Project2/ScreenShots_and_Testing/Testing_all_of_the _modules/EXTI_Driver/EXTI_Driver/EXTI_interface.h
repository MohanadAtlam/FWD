/*
 * EXTI_interface.h
 *
 * Created: 12/8/2022 1:23:56 AM
 *  Author: Mohanad Magdy
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define EXTI_INT0		0

typedef enum EN_GIEError_t
{
	GIE_OK	
}EN_GIEError_t;

typedef enum EN_EXTIError_t
{
	EXTI_OK, SET_CALL_BACK_ERROR
}EN_EXTIError_t;

EN_GIEError_t GIE_Enable(void);

EN_GIEError_t GIE_Disable(void);

EN_EXTIError_t EXTI_Int0SenseControl(void);

EN_EXTIError_t EXTI_IntEnable(void);

EN_EXTIError_t EXTI_IntDisable(void);

EN_EXTIError_t EXTI_Int0SetCallBack(void(*Copy_pvInt0Func)(void));

#endif /* EXTI_INTERFACE_H_ */