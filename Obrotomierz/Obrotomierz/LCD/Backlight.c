/*
 * Backlight.c
 *
 * Created: 2017-09-11 01:02:10
 *  Author: cwur1081
 */ 

#include "Backlight.h"
#include "Timers.h"
#include "Hardware.h"


void Backlight_Init(void)	{
	
	Timer2_Config();					//	Config PWM timer
	LCD_BL_DDR	|=	(1<<LCD_BL);		//	Config LCD backlight pin as output
	Backlight_Adj(70);					//	Set LCD backlight intense to 70%
}

void Backlight_Adj(uint8_t Adjust)	{
	
	BL_Reg		=	255 / Adjust;		//	Change LCD backlight intense from percent to timer value
}
