/*
 * Obrotomierz.c
 *
 * Created: 2017-07-23 01:09:24
 *  Author: cwur1081
 */ 

#include "Hardware.h"
#include "ds18s20.h"
#include "HD44780.h"
#include "temperature.h"
#include "Compute RPM.h"
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <avr/interrupt.h>

//	GLOBAL VARIABLES
uint8_t		Measure_Refresh_Timer	= 0;
bool		IC_Measure_req			= false;
bool		RPM_Compute_req			= false;



int main(void)
{
	uint16_t RPM_Value;
	
	LCD_Initalize();
	T_Sensor_Init();
	sei();				//Enable Global Interrupt
	
	LCD_GoTo(0,0);
	LCD_WriteText(" Witaj");
	_delay_ms(500);
	LCD_Clear();
	LCD_GoTo(0,0);
	
	
    while(1)
    {
		if (RPM_Compute_req)
		{
			RPM_Compute_req	=	false;
			RPM_Value		= Compute_RPM();
		}
    }
}