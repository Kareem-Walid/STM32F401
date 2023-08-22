/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  RCC_Private.h
 *         Module:  -
 *         Author: Kareem Walid 
 *         Description:    
 *  
 *********************************************************************************************************************/
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_



#include "../COMM/PLATFORM_TYPES.h"



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define   PERIPHERALS_BASE_ADDRESS       0x40000000UL
#define   AHP1_PERIPHERALS_BASE_ADDRESS  (PERIPHERALS_BASE_ADDRESS + 0x00020000UL )
#define   RCC_BASE_ADDRESS               (AHP1_PERIPHERALS_BASE_ADDRESS + 0x3800UL)
#define   RCC_RegPoiner                  ((RCC_REGs_t*)RCC_BASE_ADDRESS)

 #define   RCC_PLLCFGR_i            RCC_BASE_ADDRESS + 0x04
 #define   PLL_ConfigPointer       ((RCC_PLLCFGR_BITs_t*)RCC_PLLCFGR_i)


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum{
	AHB1,
	AHB2,
	APB1,
	APB2
}BusID_t;

typedef  enum{
	SW0,
	SW1,
	SWS0,
	SWS1
}RCC_CFGR_BITs_t;


typedef enum{
	HSION,
	HSIRDY,
	HSITRIM0 = 3,
	HSITRIM1,
	HSITRIM2,
	HSITRIM3,
	HSITRIM4,
	HSICAL0,
	HSICAL1,
	HSICAL2,
	HSICAL3,
	HSICAL4,
	HSICAL5,
	HSICAL6,
	HSICAL7,
	HSEON,
	HSERDY,
	HSEBYP,
	CSSON,
	PLLON = 24 ,
	PLLRDY,
	PLLI2SON,
	PLLI2SRDY
}RCC_CR_BITs_t;


typedef enum {
	GPIOAEN,
	GPIOBEN,
	GPIOCEN,
	GPIODEN,
	GPIOEEN,
	GPIOHEN = 7 ,
	CRCRST  = 12,
	DMA1RST = 21,
	DMA2RST
}RCC_AHB1ENR_BITs_t;


typedef struct {
	uint32_t PLLM: 6;
	uint32_t PLLN: 9;
	uint32_t Reserved1 :1;
	uint32_t PLLP:2;
	uint32_t Reserved2 :4;
	uint32_t PLLSRC:1;
	uint32_t Reserved3 :1;
	uint32_t PLLQ:4;
	uint32_t Reserved4:4;
}RCC_PLLCFGR_BITs_t;

typedef  struct {

	volatile uint32_t  RCC_CR;          /* RCC Clock Control Register         OFFSET = 0x00 */
	volatile uint32_t  RCC_PLLCFGR;     /* RCC PLL Configuration Register     OFFSET = 0X04 */
	volatile uint32_t  RCC_CFGR;        /* RCC Clock Configuration Register   OFFSET = 0X08 */
	volatile uint32_t  RCC_CIR;         /* RCC Clock Interrupt Register       OFFSET = 0X0C */
	volatile uint32_t  RCC_AHB1RSTR;    /* RCC AHB1 Peripheral Reset Register OFFSET = 0X10 */
	volatile uint32_t  RCC_AHB2RSTR;    /* RCC AHB2 Peripheral Reset Register OFFSET = 0X14 */
	volatile uint32_t  Reserved1;       /* Reserved                           OFFSET = 0X18 */
	volatile uint32_t  Reserved2;       /* Reserved                           OFFSET = 0X1C */
	volatile uint32_t  RCC_APB1RSTR;
	volatile uint32_t  RCC_APB2RSTR;
	volatile uint32_t  Reserved3;
	volatile uint32_t  Reserved4;
	volatile uint32_t  RCC_AHB1ENR;
	volatile uint32_t  RCC_AHB2ENR;
	volatile uint32_t  Reserved5;
	volatile uint32_t  Reserved6;
	volatile uint32_t  RCC_APB1ENR;
	volatile uint32_t  RCC_APB2ENR;
	volatile uint32_t  Reserved7;
	volatile uint32_t  Reserved8;
	volatile uint32_t  RCC_AHB1LPENR;
	volatile uint32_t  RCC_AHB2LPENR;
	volatile uint32_t  Reserved9;
	volatile uint32_t  Reserved10;
	volatile uint32_t  RCC_APB1LPENR;
	volatile uint32_t  RCC_APB2LPENR;
	volatile uint32_t  Reserved11;
	volatile uint32_t  Reserved12;
	volatile uint32_t  RCC_BDCR;
	volatile uint32_t  RCC_CSR;
	volatile uint32_t  Reserved13;
	volatile uint32_t  Reserved14;
	volatile uint32_t  RCC_SSCGR;
	volatile uint32_t  RCC_PLLI2SCFGR;
	volatile uint32_t  Reserved15;
	volatile uint32_t  RCC_DCKCFGR;

}RCC_REGs_t;



#endif  /* RCC_PRIVATE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: RCC_Private.h
 *********************************************************************************************************************/
