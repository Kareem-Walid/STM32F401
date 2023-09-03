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
#include "../SysTick_Driver/SysTick_Config.h"
#include "../SysTick_Driver/SysTick_Private.h"





// Function
void STK_vInit(void);
void STK_vDisable(void);



void STK_vDelay_(uint32_t Delay);

void STK_SingleInterval(uint32_t Ticks , ptrFunction *CallBack);
void STK_PeruidicInterval(uint32_t Ticks , ptrFunction *CallBack);


uint32_t STK_uint32GET_RemainingTime(void);
uint32_t STK_uint32GET_ElapsedTime(void);


#endif /* SYSTICK_DRIVER_SYSTICK_INTERFACE_H_ */
