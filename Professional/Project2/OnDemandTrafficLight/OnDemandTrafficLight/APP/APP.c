
/*
 * APP.c
 *
 * Created: 12/8/2022 3:15:26 PM
 *  Author: Mohanad Magdy
 */ 
#include "BIT_MATH.h"
#include "STD_Types.h"
#include "APP.h"

#include "NORMAL_MODE/NORMAL_MODE.h"
#include "PEDESTRIAN_MODE/PEDESTRIAN_MODE.h"


#include "../MCAL/EXTI_DRIVER/EXTI_interface.h"
#include "../ECUAL/BUTTON_DRIVER/BUTTON.h"

void APP(void)
{
	if (EXTI_INIT()==EXTI_OK)
	{
		EXTI_Int0SetCallBack(PEDESTRIAN_MODE);
		if(BUTTON_INIT(INT_BUTTON_PORT,INT0_PIN,LOW)==BUTTON_OK)
		{
			while(1)
			{
				NORMAL_MODE();
			}
		}
	}
}


