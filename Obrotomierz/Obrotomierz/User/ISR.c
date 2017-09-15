/*
 * ISR.c
 *
 * Created: 2017-09-10 02:29:41
 *  Author: cwur1081
 */ 

#include "Hardware.h"
#include <stdint.h>
#include <stdbool.h>
#include <avr/interrupt.h>

extern uint8_t	IC_OVF_Counter;
extern uint16_t	Timer_Value_Stop;
extern bool		IC_Measure_req;
extern bool		RPM_Compute_req;

ISR(TIMER1_CAPT_vect)	{
	
	Timer_Value_Stop	= ICR1;
	IC_Measure_req		= true;
}

ISR(TIMER1_OVF_vect)	{
	
	IC_OVF_Counter++;
	if (5 == IC_OVF_Counter)	{
		IC_Measure_req	= true;
		RPM_Compute_req	= true;
		}
}

ISR(TIMER2_OVF_vect)	{
	
	LCD_BL_Port	&=	~(1<<LCD_BL);		// LCD backlight LED off
}