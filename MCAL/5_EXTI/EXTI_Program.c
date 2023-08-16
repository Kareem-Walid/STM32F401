/*
 * EXTI_Program.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Kareem Walid
 */


#include "EXTI_Interface.h"

#define  NULL ((void*)0)
typedef  void(*fptr)(void);

static fptr Global_pArr[12] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

/* This Function will Make The Interrupt Makable (hidden)
 * Parameter in : EXTI ID
 */
void MEXTI_vMaskEXTI(IRQn_Type_t IRQn)
{
	/*
	 * 0: Interrupt request from line x is masked
	 * 1: Interrupt request from line x is not masked
	 */
	if(IRQn <= 18 || IRQn == 21 || IRQn == 22)
	{
		CLR_BIT(EXTI->EXTI_IMR,IRQn);
	}else
	{
		/* Error*/
	}
}


/* This Function will Make The Interrupt non Makable (hidden)
 * Parameter in : EXTI ID
 */
void MEXTI_vUnMaskEXTI(IRQn_Type_t IRQn)
{
	/*
	 * 0: Interrupt request from line x is masked
	 * 1: Interrupt request from line x is not masked
	 */
	if(IRQn <= 18 || IRQn == 21 || IRQn == 22)
	{
		SET_BIT(EXTI->EXTI_IMR,IRQn);
	}else
	{
		/* Error*/
	}
}


void MEXTI_vMaskEvent(IRQn_Type_t IRQn)
{
	/*
	 * 0: Event request from line x is masked
	 * 1: Event request from line x is not masked
	 */
	if(IRQn <= 18 || IRQn == 21 || IRQn == 22)
	{
		CLR_BIT(EXTI->EXTI_EMR,IRQn);
	}else
	{
		/* Error*/
	}
}
void MEXTI_vUnMaskEvent(IRQn_Type_t IRQn)
{
	/*
	 * 0: Event request from line x is masked
	 * 1: Event request from line x is not masked
	 */
	if(IRQn <= 18 || IRQn == 21 || IRQn == 22)
	{
		SET_BIT(EXTI->EXTI_EMR,IRQn);
	}else
	{
		/* Error*/
	}
}


void MEXTI_vSelectTrigger(IRQn_Type_t IRQn, TRIGGER_STATE_t copyTriggerState)
{
	if(IRQn <= 18 || IRQn == 21 || IRQn == 22)
	{
		switch(copyTriggerState)
		{
		case RISING_EDGE:
			SET_BIT(EXTI->EXTI_RTSR,IRQn);
			CLR_BIT(EXTI->EXTI_FTSR,IRQn);
			break;
		case FALLING_EDGE:
			SET_BIT(EXTI->EXTI_FTSR,IRQn);
			CLR_BIT(EXTI->EXTI_RTSR,IRQn);
			break;
		case ON_CHANGE:
			SET_BIT(EXTI->EXTI_RTSR,IRQn);
			SET_BIT(EXTI->EXTI_FTSR,IRQn);
			break;
		default:
			// Make Error
			break;
		}
	}else
	{
		/* Error*/
	}
}

void MEXTI_vSWInterrupt(IRQn_Type_t IRQn)
{
	if(IRQn <= 18 || IRQn == 21 || IRQn == 22)
	{
		SET_BIT(EXTI->EXTI_SWIER ,IRQn);
	}else
	{
		/* Error*/
	}
}

void MEXTI_vCLR_PR(IRQn_Type_t IRQn)
{
	if(IRQn <= 18 || IRQn == 21 || IRQn == 22)
	{
		SET_BIT(EXTI->EXTI_PR ,IRQn);
	}else
	{
		/* Error*/
	}
}


void MEXTI_SetCallbackFun(IRQn_Type_t IRQn,void(*copy_pfcallback)(void))
{
	if(IRQn <= 18 || IRQn == 21 || IRQn == 22)
	{
		if(IRQn<=4)
		{

			Global_pArr[IRQn] = copy_pfcallback;
		}
		else if (IRQn>= 5 && IRQn<= 9)
		{
			Global_pArr[5] = copy_pfcallback;
		}
		else if (IRQn>= 10 && IRQn<= 15)
		{
			Global_pArr[6] = copy_pfcallback;
		}
		else if (IRQn == 16)
		{
			Global_pArr[7] = copy_pfcallback;
		}
		else if (IRQn == 17)
		{
			Global_pArr[8] = copy_pfcallback;
		}
		else if (IRQn == 18)
		{
			Global_pArr[9] = copy_pfcallback;
		}
		else if (IRQn ==21)
		{
			Global_pArr[10] = copy_pfcallback;
		}
		else if (IRQn ==22)
		{
			Global_pArr[11] = copy_pfcallback;
		}

	}
}
