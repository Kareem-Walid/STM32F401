
#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_


#include "Bit_Math.h"
#include "NVIC_Private.h"
#include "NVIC_Config.h"
#include "SCB_Interface.h"


typedef enum{
	Reset = -25,
	NMI= -24,
	HardFault= -23,
	MemManage= -22,
	BusFault =  -21,
	UsageFault = -20,
	SVCall = -5,
	bug_Monito = -4,
	PendSV = -2,
	Systick = -1,
	WWDG = 0,
	EXTI16_PVD,
	EXTI21_TAMP_STAMP,
	EXTI22_RTC_WKUP,
	FLASH,
	RCC,
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	DMA1_Stream0,
	DMA1_Stream1,
	DMA1_Stream2,
	DMA1_Stream3
}IRQn_Type;



// APIs
void  NVIC_EnableIRQ(IRQn_Type   IRQn);
void  NVIC_DisableIRQ(IRQn_Type   IRQn);
void  NVIC_SetPendingIRQ(IRQn_Type   IRQn);
void  NVIC_ClearPendingIRQ(IRQn_Type   IRQn);
uint32_t NVIC_GetActive(IRQn_Type   IRQn);
void NVIC_GetPrority(IRQn_Type IRQn,uint32_t Priority);

#endif
