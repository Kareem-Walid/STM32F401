/*
 * SysTick_Private.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Kareem Walid
 */

#ifndef SYSTICK_DRIVER_SYSTICK_PRIVATE_H_
#define SYSTICK_DRIVER_SYSTICK_PRIVATE_H_






#define  SysTick_BASE_ADDRESS    (0xE000E010UL)
#define  SysTick                 ((SysTick_Types_t*)SysTick_BASE_ADDRESS)


#define NULL ((void*)0)

typedef void (* ptrFunction)(void);


#define  SysTick_Single_Interval_Mode  0
#define  SysTick_Peruidic_Interval_Mode  1

typedef enum
{
	ENABLE,
	TICKINT,
	CLKSOURCE,
	COUNTFLAG = 16

}STK_CTRL_Bits_t;

typedef struct{
	volatile uint32_t STK_CTRL;   /* SysTick control and status register */
	volatile uint32_t STK_LOAD;   /* SysTick reload value register */
	volatile uint32_t STK_VAL;    /* SysTick current value register */
	volatile uint32_t STK_CALIB;  /* SysTick calibration value register */

}SysTick_Types_t;

#endif /* SYSTICK_DRIVER_SYSTICK_PRIVATE_H_ */
