/*
 * Timers.c
 *
 * Created: 2017-09-09 23:56:21
 *  Author: cwur1081
 */ 

#include <avr/io.h>

void Timer1_Config (void)	{
	
	TCCR1B	=	(1<<ICNC1)	|	(1<<ICES1)	|	(1<<CS11);	// Input Noise Canceler, Input Capture, Prescaller 8 (1 us)
	TIMSK	=	(1<<TICIE1) |	(1<<TOIE1);					// Enable OVF and Input Capture interrupt
}

void Timer2_Config (void)	{
	

	TCCR2	=	(1<<WGM21)	|	(1<<WGM20)	|	(1<<COM21)
			|	(1<<CS21)	|	(1<<CS20);					//	Fast PWM, Normal operation OC2, Prescaler 32 (4 us)
	TIMSK	=	(1<<TOIE1);									// Enable OVF Interrupt
}