/**********************************************************************************************************************
 *  FILE INFORMATION
 *  -----------------------------------------------------------------------------------------------------------------
 *        FILE NAME :  DMA_Program.c
 *        FILE DATE :
 *        VERSION:   V1.0
 *        AUTHOR:   KAREEM WALID
 *        BRIEF EXPLANATION:
 *
 *
 *
 *
 *********************************************************************************************************************/





/* ==============================================================================
                    ##### DMA Peripheral features #####
   ==============================================================================



  ==============================================================================
                     ##### How to use this driver #####
  ==============================================================================








 **********************************************************************************************************************
 *  INCLUDES
 ******************************************************************************************************************** */
#include "DMA_Interface.h"


/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/* ===============================================================================
              ##### Initialization and De-initialization functions #####
   =============================================================================== */


/******************************************************************************
* \Syntax          :
* \Description     :
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : ReturnType  E_OK
*                                E_NOT_OK
*******************************************************************************/
// for V1 void HDMA2_vInit(uint8_t Stream_Number ,uint8_t Priority,uint8_t Mode, uint8_t Data_Size)
#define     Stream_Number   3
void HDMA2_vInit(void)
{
	/*----------- RCC Enable --------------- */
	/* DMA1 and DMA2 are in AHB1 Bus */
	RCC_vEnablePeripheral(AHB1,22);  // DMA2

	/* ----------------- Make Sure that DMA Stream is Disable -------------------- */
	/* Because if its Enable meant its transfer data and i can't make any changes  */
	CLR_BIT(DMA2 -> DMA_STREAM[Stream_Number].DMA_SxCR,0);

	/*----------------------- CHANEL ---------------------------*/
	/* Select Channel */

	/*-------------------- Data Transfered ------------------*/
	/* Configure Total Items Can be Transfered  */

	/*-------------------- Peripheral Address ------------------*/
	/* Select the peripheral port register address in DMA_SxPAR */

	/*-------------------- Memory Address ------------------*/
	/* Select the peripheral port register address in DMA_SxPAR */

	/*---------------------- Priority --------------- */
	/* Select Priority Level
	 * Options:
	 * 00: Low
     * 01: Medium
     * 10: High
     * 11: Very high */
    // For V1 of my Driver i will make priority constant at Medium Level
	SET_BIT(DMA2 -> DMA_STREAM[Stream_Number].DMA_SxCR , PL0);
	CLR_BIT(DMA2 -> DMA_STREAM[Stream_Number].DMA_SxCR , PL1);


	/* ------------------- CIRCULAR MODE ----------------- */
	/*FOR V1 Make it constant */
    SET_BIT(DMA2 -> DMA_STREAM[Stream_Number].DMA_SxCR , CIRC);


	/* ------------------------ MODE ----------------- */
	/*SELECT MODE OPTIONS:
	 *  00: Peripheral-to-memory
}    *  01: Memory-to-peripheral
     *  10: Memory-to-memory
     *  11: reserved
	 */

	 // For V1 of my Driver i will make MODE Constant M2M
	CLR_BIT(DMA2 -> DMA_STREAM[Stream_Number].DMA_SxCR , DIR0);
	SET_BIT(DMA2 -> DMA_STREAM[Stream_Number].DMA_SxCR , DIR1);

	  /* ------------------Disable Direct Mode --------------- */
	CLR_BIT(DMA2 -> DMA_STREAM[Stream_Number].DMA_SxFCR , DMDIS);

	 /*----------------- Buffer Size ------------------------ */
	SET_BIT(DMA2 -> DMA_STREAM[Stream_Number].DMA_SxCR , FS0);
	SET_BIT(DMA2 -> DMA_STREAM[Stream_Number].DMA_SxCR , FS1);
	CLR_BIT(DMA2 -> DMA_STREAM[Stream_Number].DMA_SxCR , FS2);
	/*--------------------- SRC AND DIS ----------------------*/
     /* Peripheral address pointer is incremented after each data transfer */
	 SET_BIT(DMA2 -> DMA_STREAM[Stream_Number].DMA_SxCR , PINC);
	 /*  Memory address pointer is incremented after each data transfer */
	 SET_BIT(DMA2 -> DMA_STREAM[Stream_Number].DMA_SxCR , MINC);



	/* -------------------- ENABLE Interrupt ------------------ */
	/* Last Step Enable DMA2 */
	SET_BIT(DMA2 -> DMA_STREAM[Stream_Number].DMA_SxCR,TCIE);
}



/* ===============================================================================
                    ##### IO operation functions #####
   =============================================================================== */
/**********************************************************************************************************************
 *  END OF FILE:  DMA_Program.c
 *********************************************************************************************************************/

