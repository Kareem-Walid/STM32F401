/*
 * SevSeg_Program.c
 *
 *  Created on: Aug 22, 2023
 *      Author: Kareem Walid
 */

#include "SevSeg_Interface.h"



void SevSeg_vInit(void)
{
	MSTP_vInit();
}


void SevSeg_vDisplay(uint8_t Num)
{
	const uint8_t  Num_Array[10] = {0b11111100,0b00001100,0b10110110,0b10011110,0b01001110,
			0b11011010,0b11111010,0b10001100,0b11111110,0b11011110};
	if(Num <=9)
	{

		MSTP_vDisplayData(Num_Array[Num]);

	}else{
		/* Do Nothing */
	}
}




