/*
 * STP_Program.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Kareem Walid
 */


#include "STP_Interface.h"
static SPinConfig_t pShClk,pSData,pLTClk;

void MSTP_vInit(void)
{
    /* Enable RCC */
	RCC_vInitSysClk();
	RCC_vEnablePeripheral(AHB1,PORT_EN);

	/* Enable GPIO */
	pShClk.Pin = MSTP_SHIFT_CLK_PIN;
	pShClk.Port = STP_PORT ;
	pShClk.PinMode = OUTPUT_M;
	GPIO_PinConfig(&pShClk);

	pSData.Pin =  MSTP_SDATA_PIN ;
	pSData.Port = STP_PORT;
	pSData.PinMode = OUTPUT_M;
	GPIO_PinConfig(&pSData);

	pLTClk.Pin = MSTP_LATCH_CLK_PIN;
	pLTClk.Port = STP_PORT;
	pLTClk.PinMode = OUTPUT_M;
	GPIO_PinConfig(&pLTClk);

	/* This Pint for Enable Output --- You can connect it by ground all time
	 * P3.Pin = MSTP_OUTEN_PIN;
	 * P3.Port = STP_PORT;
	 * P3.PinMode = OUTPUT_M;
	 * P3.Level = PIN_HIGH;
	 * GPIO_PinConfig(&P3);
     */

    /* Init SysTick */
	STK_vInit();

}

static void Send_Pulse(void)
{
	pShClk.Level = PIN_HIGH;
	GPIO_PinConfig(&pShClk);
	STK_vDelay_(Pulse_Width);   // Pluse Width
	pShClk.Level = PIN_LOW;
	GPIO_PinConfig(&pShClk);
}


void MSTP_vDisplayData(uint8_t  Data)
{
	uint8_t i;

	/* Send LOW on Latch Clock*/
	pLTClk.Level = PIN_LOW;
	GPIO_PinConfig(&pLTClk);

	for(i=0;i<=7;i++)
	{
		/* Send Data on Data Series Pin*/
		pSData.Level = GET_BIT(Data,i);
		GPIO_PinConfig(&pSData);

		/*Send Pules on Shift Clock*/
		Send_Pulse();
	}

	/* Send High on Latch Clock*/
	pLTClk.Level = PIN_HIGH;
	GPIO_PinConfig(&pLTClk);


	/* Send Low to OutPut Enable (This Pin Optional)
	 * P3.Level = PIN_LOW;
	 * GPIO_PinConfig(&P3);
     */

}


