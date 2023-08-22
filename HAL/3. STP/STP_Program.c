/*
 * STP_Program.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Kareem Walid
 */


#include "STP_Interface.h"

SPinConfig_t P0,P1,P2,P3;

void MSTP_vInit(void)
{
    /* Enable RCC */
	RCC_vInitSysClk();
	RCC_vEnablePeripheral(AHB1,GPIOAEN);

	/* Enable GPIO */
	P0.Pin = MSTP_SDATA_PIN;
	P0.Port = STP_PORT;
	P0.PinMode = OUTPUT_M;
	GPIO_PinConfig(&P0);

	P1.Pin = MSTP_SHIFT_CLK_PIN;
	P1.Port = STP_PORT;
	P1.PinMode = OUTPUT_M;
	GPIO_PinConfig(&P1);

	P2.Pin = MSTP_LATCH_CLK_PIN;
	P2.Port = STP_PORT;
	P2.PinMode = OUTPUT_M;
	GPIO_PinConfig(&P2);

	P3.Pin = MSTP_OUTEN_PIN;
	P3.Port = STP_PORT;
	P3.PinMode = OUTPUT_M;
	P3.Level = PIN_HIGH;
	GPIO_PinConfig(&P3);

    /* Init SysTick */
	STK_vInit();

}

static void Send_Pulse(uint32_t Pulse_Width)
{
	P0.Level = PIN_HIGH;
	GPIO_PinConfig(&P0);
	STK_vDelay_(Pulse_Width);   // Pluse Width
	P0.Level = PIN_LOW;
	GPIO_PinConfig(&P0);
}
void MSTP_vDisplayData(uint8_t  Data)
{
	uint8_t i;
	for(i=0;i<8;i++)
	{
		/* Send Data on Data Series Pin*/
		P1.Level = GET_BIT(Data,i);
		GPIO_PinConfig(&P1);

		/*Send Pules*/
		Send_Pulse(8);
	}

	/*Send High on Latch Clock*/
	P2.Level = PIN_HIGH;
	GPIO_PinConfig(&P2);

	/*Send Low to OutPut Enable */
	P3.Level = PIN_LOW;
	GPIO_PinConfig(&P3);


}


