/**********************************************************************************************************************
 *  FILE INFORMATION
 *  -----------------------------------------------------------------------------------------------------------------
 *        FILE NAME :  FLASH_Private.h
 *        FILE DATE :  5/9/2023
 *        VERSION:   V1.0
 *        AUTHOR:   KAREEM WALID
 *        BRIEF EXPLANATION:
 *
 *********************************************************************************************************************/

 /* FILE GUARD */
#ifndef FLASH_PRIVATE_H_
#define FLASH_PRIVATE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define FLAH_BASE_ADDRESS   (0x40023C00)
#define  FLASH ((FLASH_Types_t *)FLAH_BASE_ADDRESS)

#define     FLASH_KEYR_KEY1   (0x45670123)
#define     FLASH_KEYR_KEY2   (0xCDEF89AB)

#define     FLASH_OPTKEYR_OPTKEY1     (0x08192A3B)
#define     FLASH_OPTKEYR_OPTKEY2     (0x4C5D6E7F)

#define   FLASH_SNB_MASK    120
#define    __IO   volatile


/**********************************************************************************************************************
 *  GLOBAL STRUCTURES
 *********************************************************************************************************************/
/* Registers Structure */

typedef struct {
	__IO uint32_t FLASH_ACR;           /* OFFSET= 0x00 Flash access control register */
	__IO uint32_t FLASH_KEYR;          /* OFFSET= 0x04 Flash key register            */
	__IO uint32_t FLASH_OPTKEYR;       /* OFFSET= 0x08 Flash option key register     */
	__IO uint32_t FLASH_SR;            /* OFFSET= 0x0C Flash status register         */
	__IO uint32_t FLASH_CR;            /* OFFSET= 0x10 Flash control register        */
	__IO uint32_t FLASH_OPTCR;         /* OFFSET= 0x14 Flash option control register */
}FLASH_Types_t;



#endif  /* FLASH_PRIVATE_H_ */

/**********************************************************************************************************************
 *  END OF FILE:   FLASH_Private.h
 *********************************************************************************************************************/
