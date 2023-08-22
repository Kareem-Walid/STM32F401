#ifndef    GPIO_PRIVATE_H_
#define    GPIO_PRIVATE_H_

#include "../COMM/Platform_Types.h"
#include "../COMM/Bit_Math.h"

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
	volatile uint32_t    GPIO_MODER;     /* 1- GPIO Port Mode Reg              OFFSET = 0x00 */
	volatile uint32_t    GPIO_OTYPER;    /* 2- GPIO Port Output TYPE Reg       OFFSET = 0x04 */
	volatile uint32_t    GPIO_OSPEEDER;  /* 3- GPIO Port Output SPEED Reg      OFFSET = 0x08 */
	volatile uint32_t    GPIO_PUPDR;     /* 4- GPIO Port pull-up/pull-down Reg OFFSET = 0x0C */
	volatile uint32_t    GPIO_IDR;       /* 5- GPIO port Input Data Reg        OFFSET = 0x10 */
	volatile uint32_t    GPIO_ODR;       /* 6- GPIO port Output Data Reg       OFFSET = 0x14 */
	volatile uint32_t    GPIO_BSRR;      /* 7- GPIO Bit Set/Reset Reg          OFFSET = 0x18 */
	volatile uint32_t    GPIO_LCKR;      /* 8- GPIO Port Input Data Reg        OFFSET = 0x10 */
	volatile uint32_t    GPIO_AFRL;      /* 10-GPIO Port Input Data Reg        OFFSET = 0x10 */
}GPIO_REGs_t;




#endif   /* GPIO_PRIVATE_H_ */
      
