/*

 * SCB_Program.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Kareem Walid
 */


#include "SCB_Interface.h"


void SCB_SetPriorityGroubing(uint32_t copy_PriorityGropint)
{
	uint32_t VECTKEY  = 0x5FA;   //TODO make this line global

	uint32_t  Reg_Value=0;
	uint32_t PriorityGroupTemp =( (uint32_t)copy_PriorityGropint & (uint32_t)0x7);
	// CLE Specific bits i will change it
	Reg_Value = SCB -> AIRCR;
	Reg_Value &= ~(SCB_AIRCR_VECTKEYSTATE_MUSK |SCB_AIRCR_VECTKEYSTATE_MUSK);

	Reg_Value = (Reg_Value |(VECTKEY<<SCB_AIRCR_VECTKEYSTATE_POS) |
			    (PriorityGroupTemp<<SCB_AIRCR_PRIGROUP_POS));

	SCB -> AIRCR = Reg_Value;
}

