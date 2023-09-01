/**********************************************************************************************************************
 *  FILE INFORMATION
 *  -----------------------------------------------------------------------------------------------------------------
 *        FILE NAME : GPIO_Private.h
 *        FILE DATE : 8/8/2023
 *        VERSION:   V2.0
 *        AUTHOR:   KAREEM WALID
 *        BRIEF EXPLANATION: This File Contain all Private Hardware
 *
 *
 *********************************************************************************************************************/

 /* FILE GUARD */
#ifndef    GPIO_PRIVATE_H_
#define    GPIO_PRIVATE_H_




/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

  /* GPTO Base Addresses for STM32F401xx */
#define     GPIOA_BASE_ADDRESS    0x40020000UL    
#define     GPIOB_BASE_ADDRESS    0x40020400UL  
#define     GPIOC_BASE_ADDRESS    0x40020800UL
#define     GPIOD_BASE_ADDRESS    0x40020C00UL 
#define     GPIOE_BASE_ADDRESS    0x40021000UL 
#define     GPIOH_BASE_ADDRESS    0x40021C00UL


/* Pointers for each GPIO Registers */
/* This Pointers used to access any register for any GPIO  */
/* This Addresses Dependent on Microcontroller */
#define  pGPIOA    ((GPIO_REGs_t*)GPIOA_BASE_ADDRESS)
#define  pGPIOB    ((GPIO_REGs_t*)GPIOB_BASE_ADDRESS)
#define  pGPIOC    ((GPIO_REGs_t*)GPIOC_BASE_ADDRESS)
#define  pGPIOD    ((GPIO_REGs_t*)GPIOD_BASE_ADDRESS)
#define  pGPIOE    ((GPIO_REGs_t*)GPIOE_BASE_ADDRESS)
#define  pGPIOH    ((GPIO_REGs_t*)GPIOH_BASE_ADDRESS)



/**********************************************************************************************************************
 *  GLOBAL STRUCTURES
 *********************************************************************************************************************/
/* This Structure Contains All Registers for GPIO Peripheral  */
typedef  struct
{
	volatile uint32_t    GPIO_MODER;     /* 1- OFFSET = 0x00 GPIO Port Mode Reg                */
	volatile uint32_t    GPIO_OTYPER;    /* 2- OFFSET = 0x04 GPIO Port Output TYPE Reg         */
	volatile uint32_t    GPIO_OSPEEDER;  /* 3- OFFSET = 0x08 GPIO Port Output SPEED Reg        */
	volatile uint32_t    GPIO_PUPDR;     /* 4- OFFSET = 0x0C GPIO Port pull-up/pull-down Reg   */
	volatile uint32_t    GPIO_IDR;       /* 5- OFFSET = 0x10 GPIO port Input Data Reg          */
	volatile uint32_t    GPIO_ODR;       /* 6- OFFSET = 0x14 GPIO port Output Data Reg         */
	volatile uint32_t    GPIO_BSRR;      /* 7- OFFSET = 0x18 GPIO Bit Set/Reset Reg            */
	volatile uint32_t    GPIO_LCKR;      /* 8- OFFSET = 0x1C GPIO port config lock Reg         */
	volatile uint32_t    GPIO_AFRL;      /* 9- OFFSET = 0x20 GPIO alternate function low Reg   */
	volatile uint32_t    GPIO_AFRH;      /* 10- OFFSET = 0x24 GPIO alternate function High Reg */
}GPIO_REGs_t;




#endif   /* GPIO_PRIVATE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: GPIO_Private.h
 *********************************************************************************************************************/
