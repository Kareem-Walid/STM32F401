





/**********************************************************************************************************************
 *  FILE INFORMATION
 *  -----------------------------------------------------------------------------------------------------------------
 *        FILE NAME :  FLASH_Interface.h
 *        FILE DATE :  5/9/2023
 *        VERSION:   V1.0
 *        AUTHOR:   KAREEM WALID
 *        BRIEF EXPLANATION:
 *
 *********************************************************************************************************************/

 /* FILE GUARD */
#ifndef FLASH_INTERFACE_H_
#define FLASH_INTERFACE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../COMM/Bit_Math.h"
#include "../COMM/Status_Types.h"
#include "../COMM/Platform_Types.h"
#include "FLASH_Private.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* Sectors that we can access in STM32F401xx*/
 #define FLASH_SECTOR_0    0U
 #define FLASH_SECTOR_1    1U
 #define FLASH_SECTOR_2    2U
 #define FLASH_SECTOR_3    3U
 #define FLASH_SECTOR_4    4U
 #define FLASH_SECTOR_5    5U

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL Enumeration AND STRUCTURES
 *********************************************************************************************************************/
/*----------------------------------------------*/
/*---------------- FLASH_SR Bits ---------------*/
typedef enum{
	EOP,
	OPERR,
	WRPERR = 4,
	PGAERR,
	PGPERR,
	PGSERR,
	RDERR,
	BSY = 16,

}FLASH_SR_Types_t;



/*----------------------------------------------*/
/*----------------- FLASH_CR Bits --------------*/
typedef enum{
	PG,
	SER,
	MER,
	SNB0,
	SNB1,
	SNB2,
	PSIZE0 = 8 ,
	PSIZE1,
	STRT =16,
	EOPIE = 24,
	ERRIE ,
	LOCK = 31,
}FLASH_CR_Types_t;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
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

#endif  /* FLASH_INTERFACE_H_ */

/**********************************************************************************************************************
 *  END OF FILE:
 *********************************************************************************************************************/
