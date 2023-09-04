/**********************************************************************************************************************
 *  FILE INFORMATION
 *  -----------------------------------------------------------------------------------------------------------------
 *        FILE NAME :
 *        FILE DATE :
 *        VERSION:   V1.0
 *        AUTHOR:   KAREEM WALID
 *        BRIEF EXPLANATION:
 *
 *********************************************************************************************************************/

 /* FILE GUARD */
#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define   DMA1_BASE_ADDRESS    (0x40026000UL)
#define   DMA2_BASE_ADDRESS    (0x40026400UL)

#define   DMA1       ((DMA_Types_t*)DMA1_BASE_ADDRESS)
#define   DMA2       ((DMA_Types_t*)DMA2_BASE_ADDRESS)
/**********************************************************************************************************************
 *  GLOBAL STRUCTURES
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL STRUCTURES
 *********************************************************************************************************************/
/* This Structure Contains All the Registers that common between Streams */
typedef struct {
	volatile uint32_t DMA_SxCR;     /* OFFSET=0x10 + 0x18 X Stream Number(0..7) DMA stream x configuration register */
	volatile uint32_t DMA_SxNDTR;   /* OFFSET 0x DMA stream x number of data register */
	volatile uint32_t DMA_SxPAR;    /* OFFSET 0x DMA stream x peripheral address register */
	volatile uint32_t DMA_SxM0AR;   /* OFFSET 0x DMA stream x memory 0 address register */
	volatile uint32_t DMA_SxM1AR;   /* OFFSET 0x DMA stream x memory 1 address register */
	volatile uint32_t DMA_SxFCR;    /* OFFSET 0x DMA stream x FIFO control register */
}DMA_Stream_Types_t;


/* This Structure Contains all Registers for DMA Peripheral */
typedef  struct {
	/*This two Registers are Read Only, Constant to Protect them from fatal errors  */
	const volatile uint32_t   DMA_LISR;           /* OFFSET= 0x00 DMA low interrupt status register    */
	const volatile uint32_t   DMA_HISR;           /* OFFSET= 0x04 DMA high interrupt status register   */
	      volatile uint32_t   DMA_LIFCR;          /* OFFSET= 0x08 DMA low interrupt flag clear register */
	      volatile uint32_t   DMA_HIFCR;          /* OFFSET= 0x0C DMA high interrupt flag clear register */
	      volatile DMA_Stream_Types_t  DMA_STREAM[8];      /* Array of 8 elements every element consists of 6 registers for every Stream */
}DMA_Types_t;




#endif  /* DMA_PRIVATE_H_ */

/**********************************************************************************************************************
 *  END OF FILE:  DMA_Private.h
 *********************************************************************************************************************/

