/*
 * Temperature.c
 *
 * Created: 2017-09-04 08:56:03
 *  Author: cwur1081
 */ 

#include "Hardware.h"
#include "temperature.h"
#include "ds18s20.h"

void T_Sensor_Init(void)
{
	TSDS18x20 DS18x20;
	TSDS18x20 *pDS18x20 = &DS18x20;
	if (DS18x20_Init(pDS18x20,&T_Sen_Port,T_Sensor))	{
		// B£¥d
	}	else	{
	// Set DS18B20 resolution to 9 bits.
	DS18x20_SetResolution(pDS18x20,CONF_RES_9b);
	DS18x20_WriteScratchpad(pDS18x20);
	}
}

void T_Measure(void)
{	
	TSDS18x20 DS18x20;
	TSDS18x20 *pDS18x20 = &DS18x20;
	//char buffer[10];
	// Initiate a temperature conversion and get the temperature reading
	if (DS18x20_MeasureTemperature(pDS18x20))	{
		//dtostrf(DS18x20_TemperatureValue(pDS18x20),9,4,buffer);
	}	else	{
		// B£¥D SUMY KONTROLNEJ
	}
}
	