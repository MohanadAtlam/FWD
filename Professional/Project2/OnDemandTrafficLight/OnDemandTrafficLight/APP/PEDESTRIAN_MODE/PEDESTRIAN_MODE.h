/*
 * PEDESTRIAN_MODE.h
 *
 * Created: 12/8/2022 6:27:04 PM
 *  Author: Mohanad Magdy
 */ 


#ifndef PEDESTRIAN_MODE_H_
#define PEDESTRIAN_MODE_H_
#include "../../ECUAL/LED_DRIVER/LED.h"
//defining the leds ports
#define PEDESTRIAN_MODE_LEDS_PORT		1 //in the dio driver the ports are A->0	B->1	C-> 2		D->3

#define NORMAL_MODE_LEDS_PORT		0 //in the dio driver the ports are A->0	B->1	C-> 2		D->3

//defining the pins
#define GREEN_LED					0
#define YELLOW_LED					1
#define RED_LED						2

typedef enum PED_MODES_Error
{
	PED_MODE_OK,PED_MODE1_ERROR,PED_MODE2_ERROR
}PED_MODES_Error;

void PEDESTRIAN_MODE(void);

PED_MODES_Error mode1(void);//mode 1 is when the red cars led is on 
PED_MODES_Error mode2(void);//mode 2 is when the green is on or yellow is blinking



#endif /* PEDESTRIAN_MODE_H_ */