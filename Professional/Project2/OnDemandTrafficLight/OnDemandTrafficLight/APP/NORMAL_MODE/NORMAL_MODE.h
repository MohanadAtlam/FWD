/*
 * NORMAL_MODE.h
 *
 * Created: 12/8/2022 3:37:42 PM
 *  Author: Mohanad Magdy
 */ 


#ifndef NORMAL_MODE_H_
#define NORMAL_MODE_H_

//defining the led port and the pin used in the normal mode
#define NORMAL_MODE_LEDS_PORT		0 //in the dio driver the ports are A->0	B->1	C-> 2		D->3
#define GREEN_LED					0
#define YELLOW_LED					1
#define RED_LED						2

void NORMAL_MODE(void);



#endif /* NORMAL_MODE_H_ */