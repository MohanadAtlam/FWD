/*
 * APP.h
 *
 * Created: 12/8/2022 3:15:41 PM
 *  Author: Mohanad Magdy
 */ 


#ifndef APP_H_
#define APP_H_

#include "NORMAL_MODE/NORMAL_MODE.h"
#include "PEDESTRIAN_MODE/PEDESTRIAN_MODE.h"


#include "../ECUAL/BUTTON_DRIVER/BUTTON.h"

#define INT_BUTTON_PORT			3
#define INT0_PIN				2

#define LOW						0
#define HIGH					1

void APP(void);



#endif /* APP_H_ */