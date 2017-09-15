/*
 * Compute_RPM.c
 *
 * Created: 2017-09-11 01:40:05
 *  Author: cwur1081
 */ 

#include <stdint.h>
#include <stdbool.h>
#include <float.h>
#include "Compute RPM.h"

extern bool			IC_Measure_req;
extern bool			RPM_Compute_req;
uint16_t			RPM_Array[RPM_Array_Size];
volatile uint8_t	RPM_Array_Pointer	= RPM_Array_Size;
volatile uint16_t	Timer_Value_Start	= 0;
volatile uint16_t	Timer_Value_Stop	= 0;
volatile uint8_t	IC_OVF_Counter		= 0;

void Measure_RPM (void)	{
	
	uint32_t Period	= 0;
	if (IC_OVF_Counter)	{
		Period		= Timer_Value_Stop + 0xFFFF * IC_OVF_Counter - Timer_Value_Start;	//	Wylicz okres uwzgledniajac przepelnienia licznika
	} 	else	{
		Period		= Timer_Value_Stop - Timer_Value_Start;	//	Wylicz czas od ostatniego impulsu
	}
	IC_Measure_req		= false;
	Timer_Value_Start	= Timer_Value_Stop;					//	Zaktualizuj stan timera do kolejnego pomiaru
	double RPM			= 120.0 / Period;					//	Przelicz okres pomiedzy zaplonem w us na obr/60 us
	RPM					= RPM * 1000000.0;					//	Przelicz obr/60 us na obr/min
	uint16_t result		= (int) RPM;
	Array_Fill(result)
}

void Array_Fill	(uint16_t RPM_Value)	{
	
	RPM_Array[RPM_Array_Pointer]	= RPM_Value;
	RPM_Array_Pointer --;
	if (0 == RPM_Array_Pointer)	{
		RPM_Array_Pointer			= RPM_Array_Size;
		RPM_Compute_req				= true;
	}
}

uint16_t Compute_RPM(void)	{
	
	RPM_Compute_req			= false;
	uint32_t Array_Sum		= 0;
	for (uint8_t pointer = 0; pointer < RPM_Array_Size; pointer ++)	{
		Array_Sum			+= RPM_Array[pointer];
	}
	uint16_t result			= Array_Sum / RPM_Array_Size;
	return result;
}