
// includes
#include "NVIC_Interface.h"


void  NVIC_EnableIRQ(IRQn_Type   IRQn)
{
	if((uint32_t)IRQn >=0)
	{
		SET_BIT(NVIC->ISER[((uint32_t)IRQn)/32]  , (((uint32_t)IRQn) % 32) );
		// SET_BIT (NVIC->ISER[((uint32_t)IRQn) >> 5] , (((uint32_t)IRQn) & 0x1F))
	}
}
void  NVIC_DisableIRQ(IRQn_Type   IRQn)
{
	if((uint32_t)IRQn >=0)
	{
		SET_BIT(NVIC->ICER[((uint32_t)IRQn)/32]  , (((uint32_t)IRQn) % 32) );
		// SET_BIT (NVIC->ICER[((uint32_t)IRQn) >> 5] , (((uint32_t)IRQn) & 0x1F))
	}
}
void  NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
	if((uint32_t)IRQn >=0)
	{
		SET_BIT(NVIC->ISPR[((uint32_t)IRQn)/32]  , (((uint32_t)IRQn) % 32) );
		// SET_BIT (NVIC->ISER[((uint32_t)IRQn) >> 5] , (((uint32_t)IRQn) & 0x1F))
	}
}
void  NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
	if((uint32_t)IRQn >=0)
	{
		SET_BIT(NVIC->ICPR[((uint32_t)IRQn)/32]  , (((uint32_t)IRQn) % 32) );
		// SET_BIT (NVIC->ICPR[((uint32_t)IRQn) >> 5] , (((uint32_t)IRQn) & 0x1F))
	}
}
uint32_t NVIC_GetActive(IRQn_Type IRQn)
{     if((uint32_t)IRQn >=0)
      {
	    return GET_BIT(NVIC->IABR[((uint32_t)IRQn)/32] , (((uint32_t)IRQn) % 32));
      }
       return 0;
}

void NVIC_SetPrority(IRQn_Type IRQn,uint32_t Priority)
{
	if((uint32_t)IRQn >=0)
	{
		NVIC -> IPR[(uint32_t)IRQn] = (uint8_t)((Priority << (8 - NVIC_PRIO_BITS)) & (uint32_t)0xFF) ;
	}else{
       /* Nothing */
	}
}





