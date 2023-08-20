/*
 * SysTick_Interface.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Kareem Walid
 */

#ifndef SYSTICK_DRIVER_SYSTICK_INTERFACE_H_
#define SYSTICK_DRIVER_SYSTICK_INTERFACE_H_

#include "../COMM/Platform_Types.h"
#include "../COMM/Bit_Math.h"
#include "SysTick_Private.h"
#include "SysTick_Config.h"





// Function
void STK_vInit(void);
void STK_vDisable(void);
void STK_vEnableINT(void);
void STK_vDisableINT(void);


void STK_vDelay_US(uint32_t Delay);
void STK_vDelay_MS(uint32_t Delay);


uint32_t STK_uint32GET_ElapsedTime(void);
uint32_t STK_uint32GET_RemainingTime(void);
void STK_vResetCounting(void);
#endif /* SYSTICK_DRIVER_SYSTICK_INTERFACE_H_ */
