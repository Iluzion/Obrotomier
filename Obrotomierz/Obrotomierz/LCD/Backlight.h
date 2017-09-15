/*
 * Backlight.h
 *
 * Created: 2017-09-11 01:03:22
 *  Author: cwur1081
 */ 


#ifndef BACKLIGHT_H_
#define BACKLIGHT_H_

#include <stdint.h>

#define	BL_Reg		OCR2

//	Initialize LCD Backlight adjust func
void Backlight_Init(void);
//	Change LCD Backlight Adjust
void Backlight_Adj(uint8_t Adjust);


#endif /* BACKLIGHT_H_ */