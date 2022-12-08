/*
 * timer_interface.h
 *
 * Created: 12/6/2022 9:19:26 PM
 *  Author: Mohanad Magdy
 */ 


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

//TCCR0 bits i will use in the driver
#define WGM00		6
#define WGM01		3

#define CS02		2
#define CS01		1
#define CS00		0

//TIFR bits
#define TOV0		0	//Timer/Counter0 OVerflow Flag

//max time for each prescaler
#define NO_PRESCALER_MAXTIME			0.000256
#define PRESCALER_8_MAXTIME				0.002048
#define PRESCALER_64_MAXTIME			0.016384
#define PRESCALER_256_MAXTIME			0.065536
#define PRESCALER_1024_MAXTIME			0.262144


//Timer functions errors enum
typedef enum EN_DelayError_t
{
	DELAY_OK, DELAY_ERROR
}EN_DelayError_t; 

EN_DelayError_t TIMER0_DELAY(f64 time);

#endif /* TIMER_INTERFACE_H_ */