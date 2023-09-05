

/**********************************************************************************************************************
 *  FILE INFORMATION
 *  -----------------------------------------------------------------------------------------------------------------
 *        FILE NAME :  USART_Program.c
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
                    ##### ...... Peripheral features #####
   ==============================================================================



  ==============================================================================
                     ##### How to use this driver #####
  ==============================================================================



   ===============================================================================
              ##### Initialization and de-initialization functions #####
   ===============================================================================



  ==============================================================================
                       ##### IO operation functions #####
 ===============================================================================

 **********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "FLASH_Interface.h"

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
Status_Types_t  MFLASH_LOCK(void)
{
	/* Declare and Initialize Local Variable for Storing the Status of the function */
	Status_Types_t   Local_MFLASH_LOCK_STATUS = H_OK;

	/*------------ Set the lock bit -------*/
	/* we will check on LOCK bit(31) for FLASH_CR
	 * Options:
	 *  0: cleared by hardware after detecting the unlock sequence.
	 *  1: his bit indicates that the FLASH_CR register is locked
	 *   */
	SET_BIT(FLASH -> FLASH_CR , 31 );
	/* Check if the bit Set Successfully or not */
	if(GET_BIT(FLASH -> FLASH_CR , 31 ) == 0 ){
		Local_MFLASH_LOCK_STATUS = H_ERROR;
	}else{
		/* Do Nothing*/
	}
	return Local_MFLASH_LOCK_STATUS;
}


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
Status_Types_t MFLASH_StatusTypesUnLOCK(void)
{
	/* Declare and Initialize Local Variable for Storing the Status of the function */
	Status_Types_t   MFLASH_UnLOCK_STATUS = H_OK;

	/*------- Enter Key to Allow Accessing ---------- */
	/* Key Number 1 */
	FLASH -> FLASH_KEYR =  FLASH_OPTKEYR_OPTKEY1;
	/* Key Number 2 */
	FLASH -> FLASH_KEYR =  FLASH_OPTKEYR_OPTKEY2;

	/*------------ Check the status of Accessing  -------*/
	/* we will check on LOCK bit(31) for FLASH_CR
	 * Options:
	 *  0: cleared by hardware after detecting the unlock sequence.
	 *  1: his bit indicates that the FLASH_CR register is locked
	 *   */

	if ( GET_BIT(FLASH -> FLASH_CR , 31 ) == 1 )
	{
		MFLASH_UnLOCK_STATUS = H_ERROR;
	}else{
		/* Do Nothing */
	}

	return MFLASH_UnLOCK_STATUS ;
}


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

Status_Types_t MFLASH_StatusTypes_EraseSector(uint8_t Sector_Number )
{

	/* Declare and Initialize Local Variable for Storing the Status of the function */
	Status_Types_t   MFLASH_EraseSector_STATUS = H_ERROR;




	if(Sector_Number <= FLASH_SECTOR_5 ){

		/*----------- Assembly ----------------*/
		/*Disable Interrupt */
		__asm volatile("CPSID i":::"memory");
		/* __enable_irq(); */ /* Use This Instruction instead of assembly */
		/*-------------------------------------*/


		/* ------ Unlock Flash To Allow Operation----------- */
		MFLASH_StatusTypesUnLOCK();

		/* ---------- Wait -------------- */
		/* BSY Bit in FLASH_CR Register
		 * This bit indicates that a Flash memory operation is in progress.
		 * 0: no Flash memory operation ongoing.
		 * 1: Flash memory operation ongoing.
		 */
		while(GET_BIT(FLASH -> FLASH_SR , BSY ) == 1 );

		/*------- Enable Sector Erase --------------*/
		/* SER Bit in FLASH_SR Register
		 */
		SET_BIT(FLASH -> FLASH_CR ,SER);
		/*---------- Disable Mass Erase ------------- */
		CLR_BIT(FLASH -> FLASH_CR ,MER);

		/*----------- Configure Sector Number -------------------*/
		MODIFY_REG(FLASH -> FLASH_CR,Sector_Number << 3 , FLASH_SNB_MASK );

		/*-------------- Program Size -------------------*/
		/* We can Configure Program Size from PSIZE0 AND PSIZE1 Bits in FLASH_CR Register
		 * 00 program x8
		 * 01 program x16
		 * 10 program x32
		 * 11 program x64
		 */
		// Note: as V1 we will make it constant x32
		CLR_BIT(FLASH -> FLASH_CR ,PSIZE0);
		SET_BIT(FLASH -> FLASH_CR ,PSIZE1);

		/* --------------- CLEAR FLAG ----------------- */
		CLR_BIT(FLASH -> FLASH_SR ,WRPERR);
		CLR_BIT(FLASH -> FLASH_SR ,PGAERR);
		CLR_BIT(FLASH -> FLASH_SR ,PGPERR);
		CLR_BIT(FLASH -> FLASH_SR ,PGSERR);
		CLR_BIT(FLASH -> FLASH_SR ,RDERR);

		/*---------------- Staring Operation -----------------*/
		SET_BIT(FLASH -> FLASH_CR ,STRT);

		/* ---------- Wait -------------- */
		/* BSY Bit in FLASH_CR Register
		 * This bit indicates that a Flash memory operation is in progress.
		 * 0: no Flash memory operation ongoing.
		 * 1: Flash memory operation ongoing.
		 */
		while(GET_BIT(FLASH -> FLASH_SR , BSY ) == H_SET);

		/*-------------- Flash Lock -------------------- */
		MFLASH_LOCK();
	}
	else{
		MFLASH_EraseSector_STATUS = H_ERROR;
	}


	/*----------- Assembly ----------------*/
	/*Enable Interrupt */
	__asm volatile("CPSIE i":::"memory");
	/*-------------------------------------*/

	return MFLASH_EraseSector_STATUS;
}


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
Status_Types_t MFLASH_StatusTypes_Write(uint32_t Copy_Address_Number,uint32_t* Address_Data,uint32_t Copy_Length)
{
	/* ****************************************************************** */
	/*--------------------------- Local Variables -------------------------*/
	/* Declare and Initialize Local Variable for Storing the Status of the function */
	Status_Types_t   MFLASH_Write_STATUS = H_ERROR;
	/* Loop Counter */
	uint32_t Local_Counter;
	/* ****************************************************************** */

	/* Validation Step */
	if(Address_Data != NULL)
	{
		/*----------- Assembly ----------------*/
		/*Disable Interrupt */
		__asm volatile("CPSID i":::"memory");
		/* __enable_irq(); */ /* Use This Instruction instead of assembly */
		/*-------------------------------------*/
		/* ------ Unlock Flash To Allow Operatopn ----------- */
		MFLASH_StatusTypesUnLOCK();
		/* ---------- Wait -------------- */
		/* BSY Bit in FLASH_CR Register
		 * This bit indicates that a Flash memory operation is in progress.
		 * 0: no Flash memory operation ongoing.
		 * 1: Flash memory operation ongoing.
		 */
		while(GET_BIT(FLASH -> FLASH_SR , BSY ) == 1 );

		/*------- Enable Sector Erase --------------*/
		/* SER Bit in FLASH_SR Register
		 */
		SET_BIT(FLASH -> FLASH_CR ,SER);

		/*---------- Disable Mass Erase ------------- */
		CLR_BIT(FLASH -> FLASH_CR ,MER);

		/*----------- Enable Program Mode ---------------- */
		/* Flash programming activated. */
		SET_BIT(FLASH -> FLASH_CR ,PG);

		/*-------------- Program Size -------------------*/
		/* We can Configure Program Size from PSIZE0 AND PSIZE1 Bits in FLASH_CR Register
		 * 00 program x8
		 * 01 program x16
		 * 10 program x32
		 * 11 program x64
		 */
		// Note: as V1 we will make it constant x32
		CLR_BIT(FLASH -> FLASH_CR ,PSIZE0);
		SET_BIT(FLASH -> FLASH_CR ,PSIZE1);

		/*--------------------- Store Data -------------------------*/
		for(Local_Counter =0; Local_Counter < Copy_Length;Local_Counter++)
		{
			(*((uint32_t*) Copy_Address_Number + Local_Counter)) = Address_Data[Local_Counter];
		}


		/*----------- Assembly ----------------*/
		/*Enable Interrupt */
		__asm volatile("CPSIE i":::"memory");
		/*-------------------------------------*/

	}
	return MFLASH_Write_STATUS;

}


/**********************************************************************************************************************
 *  END OF FILE:
 *********************************************************************************************************************/
