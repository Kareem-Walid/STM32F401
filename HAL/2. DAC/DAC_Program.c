/*
 * DAC_Program.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Kareem Walid
 */

#include "DAC_Interface.h"


SPinConfig_t P0,P1,P2,P3,P4,P5,P6,P7;

void MDAC_vInit(void)
{


	/*  Init GPIO 8 PINS */

	/* GPIO CONFIG */

	P0.Pin = MDAC_PIN0;    P0.Port = _PORT;     P0.PinMode = OUTPUT_M;
	P1.Pin = MDAC_PIN1;    P1.Port = _PORT;     P1.PinMode = OUTPUT_M;
	P2.Pin = MDAC_PIN2;    P2.Port = _PORT;     P2.PinMode = OUTPUT_M;
	P3.Pin = MDAC_PIN3;    P3.Port = _PORT;     P3.PinMode = OUTPUT_M;
	P4.Pin = MDAC_PIN4;    P4.Port = _PORT;     P4.PinMode = OUTPUT_M;
	P5.Pin = MDAC_PIN5;    P5.Port = _PORT;     P5.PinMode = OUTPUT_M;
	P6.Pin = MDAC_PIN6;    P6.Port = _PORT;     P6.PinMode = OUTPUT_M;
	P7.Pin = MDAC_PIN7;    P7.Port = _PORT;     P7.PinMode = OUTPUT_M;

	// TODO MAKE ALL PINS IN VERY HIGH SPEED OUTPUT

	GPIO_PinConfig(&P0);
	GPIO_PinConfig(&P1);
	GPIO_PinConfig(&P2);
	GPIO_PinConfig(&P3);
	GPIO_PinConfig(&P4);
	GPIO_PinConfig(&P5);
	GPIO_PinConfig(&P6);
	GPIO_PinConfig(&P7);


	// -----------------------------

	/* SysTick Inint */
	STK_vInit();




}





static void MDAC_vCallBack(void)
{
	uint32_t Local_Counter = 0;


	P0.Level = GET_BIT(MDAC_SONG_ARRAY[Local_Counter],0);
	P1.Level = GET_BIT(MDAC_SONG_ARRAY[Local_Counter],1);
	P2.Level = GET_BIT(MDAC_SONG_ARRAY[Local_Counter],2);
	P3.Level = GET_BIT(MDAC_SONG_ARRAY[Local_Counter],3);
	P4.Level = GET_BIT(MDAC_SONG_ARRAY[Local_Counter],4);
	P5.Level = GET_BIT(MDAC_SONG_ARRAY[Local_Counter],5);
	P6.Level = GET_BIT(MDAC_SONG_ARRAY[Local_Counter],6);
	P7.Level = GET_BIT(MDAC_SONG_ARRAY[Local_Counter],7);


	Local_Counter ++;
	if(Local_Counter == MU_raw_len)
	{
		Local_Counter = 0;
	}else
	{

	}
}



void MDAC_vPlay(void)
{

	STK_PeruidicInterval(250,MDAC_vCallBack);
}



