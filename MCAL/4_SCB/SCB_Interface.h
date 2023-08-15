/*
 * SCB_Interface.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Kareem Walid
 */

#ifndef SCB_INTERFACE_H_
#define SCB_INTERFACE_H_

#include "Platform_Types.h"
#include "SCB_Config.h"


#define  SCB_BASE_ADDRESS   (0xE000ED00UL)
#define  SCB    ((SCB_Type*)SCB_BASE_ADDRESS)






#define   SCB_AIRCR_PRIGROUP_POS        8U
#define   SCB_AIRCR_PRIGROUP_MUSK   (7UL <<SCB_AIRCR_PRIGROUP_POS)


#define   SCB_AIRCR_VECTKEYSTATE_POS    16U
#define   SCB_AIRCR_VECTKEYSTATE_MUSK   (0xFFFFUL <<SCB_AIRCR_VECTKEYSTATE_POS)

// function
void SCB_SetPriorityGroubing(uint32_t copy_PriorityGropint);

// structure
typedef  struct
{
	volatile uint32_t CPUID;    /* CPUID base register  */
	volatile uint32_t ICSR;     /* Interrupt control and state register */
	volatile uint32_t VTOR;     /* Vector table offset register */
	volatile uint32_t AIRCR;    /* Application interrupt and reset control register */
	volatile uint32_t SCR;      /* System control register */
	volatile uint32_t CCR;      /* Configuration and control register */
	volatile uint32_t SHPR1;    /* System handler priority register 1 */
	volatile uint32_t SHPR2;    /* System handler priority register 2 */
	volatile uint32_t SHPR3;    /* System handler priority register 3 */
	volatile uint32_t SHCSR;    /* System handler control and state register */
	volatile uint32_t CFSR;     /* Configurable fault status register */
	volatile uint32_t HFSR;     /* Hard fault status register */
	volatile uint32_t MMAR;     /* Memory management fault address register */
	volatile uint32_t BFAR;     /* Bus fault address register */
	volatile uint32_t AFSR;     /* Auxiliary fault status register */


}SCB_Type;
#endif /* SCB_INTERFACE_H_ */
