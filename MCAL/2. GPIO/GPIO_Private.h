#ifndef    GPIO_PRIVATE_H_
#define    GPIO_PRIVATE_H_

// #include "Platform_Types.h"
// #include "Bit_Math.h"

typedef unsigned long          uint32_t;


#define     GPIOA_BASE_ADDRESS    0x40020000UL    
#define     GPIOB_BASE_ADDRESS    0x40020400UL  
#define     GPIOC_BASE_ADDRESS    0x40020800UL
#define     GPIOD_BASE_ADDRESS    0x40020C00UL 
#define     GPIOE_BASE_ADDRESS    0x40021000UL 
#define     GPIOH_BASE_ADDRESS    0x40021C00UL



#define  GPIOA    ((GPIO_REGs_t*)GPIOA_BASE_ADDRESS)
#define  GPIOB    ((GPIO_REGs_t*)GPIOA_BASE_ADDRESS)
#define  GPIOC    ((GPIO_REGs_t*)GPIOA_BASE_ADDRESS)
#define  GPIOD    ((GPIO_REGs_t*)GPIOA_BASE_ADDRESS)
#define  GPIOE    ((GPIO_REGs_t*)GPIOA_BASE_ADDRESS)
#define  GPIOH    ((GPIO_REGs_t*)GPIOA_BASE_ADDRESS)



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

