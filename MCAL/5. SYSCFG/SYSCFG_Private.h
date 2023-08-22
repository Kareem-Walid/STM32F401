/*
 * SYSCFG_Private.h
 *
 *  Created on: Aug 17, 2023
 *      Author: Kareem Walid
 */

#ifndef SYSCFG_DRIVER_SYSCFG_PRIVATE_H_
#define SYSCFG_DRIVER_SYSCFG_PRIVATE_H_




#define SYSCFG_BASE_ADDRESS    0x40013800
#define SYSCFG      ((SYSCFG_Types_t*)SYSCFG_BASE_ADDRESS)



















typedef  struct
{
	volatile uint32_t SYSCFG_MEMRMP;
	volatile uint32_t YSCFG_PMC;
	volatile uint32_t SYSCFG_EXTICR1;
	volatile uint32_t SYSCFG_EXTICR2;
	volatile uint32_t SYSCFG_EXTICR3;
	volatile uint32_t SYSCFG_EXTICR4;
	volatile uint32_t SYSCFG_CMPCR;
}SYSCFG_Types_t;

#endif /* SYSCFG_DRIVER_SYSCFG_PRIVATE_H_ */
