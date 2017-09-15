/*
 * Hardware.h
 *
 * Created: 2017-07-23 02:20:44
 *  Author: Miros³aw Pucka
 */ 


#ifndef HARDWARE_H_
#define HARDWARE_H_

#include <avr/io.h>

#define F_CPU 8000000UL 



#define		L_Sens_PORT	PORTA
#define		L_Sens_DDR	DDRA
#define		L_Sensor	PA0
// #define		PA1
// #define		PA2
// #define		PA3
// #define		PA4
// #define		PA5
// #define		PA6
// #define		PA7


#define		LCD_PORT	PORTB
#define		LCD_DDR		DDRB
#define		LCD_RS		PB0
#define		LCD_RW		PB1
#define		LCD_E		PB2
#define		LCD_D4		PB3
#define		LCD_D5		PB4	
#define		LCD_D6		PB5
#define		LCD_D7		PB6	
//#define		PB7		


// #define		PC0
// #define		PC1
// #define		PC2
#define		JTAG_TCK	PC2
#define		JTAG_TMS	PC3
#define		JTAG_TDO	PC4
#define		JTAG_TDI	PC5
// #define		PC6
// #define		PC7


#define		RX			PD0
#define		TX			PD1

#define		T_Sen_Port	PORTD
#define		T_Sen_DDR	DDRD
#define		T_Sensor	PD2	
	
// #define		PD3		
// #define		PD4		
// #define		PD5		

#define		S_In_Port	PORTD
#define		S_In_DDR	DDRD
#define		Signal_In	PD6	//	ICP1 

#define		LCD_BL_Port	PORTD
#define		LCD_BL_DDR	DDRD
#define		LCD_BL		PD7




#endif /* HARDWARE_H_ */