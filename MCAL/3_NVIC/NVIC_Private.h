



// includes

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_


#include "Platform_Types.h"

// Macro declaration start
#define   NVIC_BASE_ADDRESS   (0xE000E100UL)
#define    NVIC       ((NVIC_REGs_t*)NVIC_BASE_ADDRESS)






typedef struct
{
	volatile uint32_t ISER[8U];   /*Interrupt Set-enable Registers*/
	uint32_t Reserved0[24U];
	volatile uint32_t ICER[8U]; /*Interrupt Clear-enable Registers*/
	uint32_t Reserved1[24U];
	volatile uint32_t ISPR[8U];  /*Interrupt Set-pending Registers*/
	uint32_t Reserved2[24U];
	volatile uint32_t ICPR[8U]; /*Interrupt Clear-pending Registers*/
	uint32_t Reserved3[24U];
	volatile uint32_t IABR[8U]; /*Interrupt Active Bit Registers*/
	uint32_t Reserved4[56U];
	volatile uint8_t IPR[240U] ;    /*Interrupt Priority Registers*/
	uint32_t Reserved5[644U];
	volatile uint32_t STIR;   /*Software Trigger Interrupt Register*/
}NVIC_REGs_t;



#endif

