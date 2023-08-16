/*
 * EXTI_Interface.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Kareem Walid
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#include "Platform_Types.h"
#include "Bit_Math.h"
#include "EXTI_Private.h"

typedef enum {
	EXTI0 = 6,
	EXTI1 = 7,
	EXTI2 = 8,
	EXTI3 = 9,
	EXTI4 = 10,
	EXTI9_5  = 23,
	EXTI15_10  = 40,
	EXTI16 = 1,
	EXTI17  = 41,
	EXTI18  = 42,
	EXTI21 = 2,
	EXTI22 = 3
}IRQn_Type_t;
typedef enum{
	RISING_EDGE,
	FALLING_EDGE,
	ON_CHANGE,
}TRIGGER_STATE_t;

// function

/* This Function will Make The Interrupt Makable (hidden)
 * Parameter in : EXTI ID
 */

void MEXTI_vMaskEXTI(IRQn_Type_t  IRQn);


/* This Function will NonMake The Interrupt Makable (hidden)
 * Parameter in : EXTI ID
 */
void MEXTI_vUnMaskEXTI(IRQn_Type_t   IRQn);


void MEXTI_vMaskEvent(IRQn_Type_t   IRQn);
void MEXTI_vUnMaskEvent(IRQn_Type_t   IRQn);



void MEXTI_vSelectTrigger(IRQn_Type_t  IRQn , TRIGGER_STATE_t copyTriggerState);

void MEXTI_vSWInterrupt(IRQn_Type_t IRQn);

void MEXTI_vCLR_PR(IRQn_Type_t  IRQn);
void MEXTI_SetCallbackFun(IRQn_Type_t IRQn,void(*PtrFun)(void));

#endif /* EXTI_INTERFACE_H_ */
