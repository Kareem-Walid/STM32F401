/*
 * SysTick_Program.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Kareem Walid
 */


#include "SysTick_Interface.h"

void STK_vInit(void)
{
#if  CLOCK_SOURCE == OPTION_1
	CLR_BIT(SysTick->STK_CTRL,CLKSOURCE);
#elif CLOCK_SOURCE == OPTION_2
	SET_BIT(SysTick->STK_CTRL,CLKSOURCE);
#endif
	SysTick-> STK_LOAD= 0;
	SysTick->	STK_VAL= 0;
	SET_BIT(SysTick->STK_CTRL, 0);   // Last step Enable SysTick


}

void STK_vDisable(void)
{
	CLR_BIT(SysTick->STK_CTRL,0);
}
void STK_vEnableINT(void)
{
	SET_BIT( SysTick->STK_CTRL,TICKINT);

}
void STK_vDisableINT(void)
{
	CLR_BIT(SysTick->STK_CTRL,TICKINT);

}


void STK_vDelay_US(uint32_t Delay)
{
#if  CLOCK_SOURCE == OPTION_1    // AHB/8

#elif CLOCK_SOURCE == OPTION_2  // AHB
	SysTick-> STK_LOAD = Delay / 0.125;
#endif
}
void STK_vDelay_MS(uint32_t Delay)
{
#if  CLOCK_SOURCE == OPTION_1    // AHB/8

#elif CLOCK_SOURCE == OPTION_2  // AHB
	SysTick-> STK_LOAD = Delay / 0.000125;
#endif
}


uint32_t STK_uint32GET_ElapsedTime(void)
{
	return (SysTick-> STK_LOAD - SysTick-> STK_VAL);
}
uint32_t STK_uint32GET_RemainingTime(void)
{
	return (SysTick-> STK_VAL);
}
void STK_vResetCounting(void)
{
	SysTick->STK_VAL = 25;  // randome number
}

