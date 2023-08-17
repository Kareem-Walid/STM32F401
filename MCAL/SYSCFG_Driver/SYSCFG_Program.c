/*
 * SYSCFG_Program.c
 *
 *  Created on: Aug 17, 2023
 *      Author: Kareem Walid
 */


#include "SYSCFG_Interface.h"



void  SYSCFG_EXTI(void)
{
	SYSCFG -> SYSCFG_EXTICR1 = 0;
}
