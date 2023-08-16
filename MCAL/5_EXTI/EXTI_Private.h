/*
 * EXTI_Private.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Kareem Walid
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define   EXTI_BASE_ADDRESS     0x40010400
#define   EXTI        ((EXTI_Type_t*)EXTI_BASE_ADDRESS)


typedef struct {
	volatile uint32_t EXTI_IMR;   /* Interrupt mask register */
	volatile uint32_t EXTI_EMR;   /* Event mask register */
	volatile uint32_t EXTI_RTSR;  /* Rising trigger selection register*/
	volatile uint32_t EXTI_FTSR;  /* Falling trigger selection register */
	volatile uint32_t EXTI_SWIER; /* Software interrupt event register*/
	volatile uint32_t EXTI_PR;     /* Pending register */
}EXTI_Type_t;


#endif /* EXTI_PRIVATE_H_ */
