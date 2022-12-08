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
	EXTI_OK, EXTI_INIT_ERROR
}EN_EXTIError_t;

EN_EXTIError_t EXTI_INIT(void); //function to initialize the interrupt at int0

EN_GIEError_t GIE_Enable(void); //function to enable the general interrupt

EN_EXTIError_t EXTI_Int0SenseControl(void); //function to set the type of the sense control to the interrupt

EN_EXTIError_t EXTI_IntEnable(void); //function to enable the interrupt

void EXTI_Int0SetCallBack(void(*Copy_pvInt0Func)(void)); //function to pass a function to work when the interrupt happen 

#endif /* EXTI_INTERFACE_H_ */