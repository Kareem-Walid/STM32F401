/**********************************************************************************************************************
 *  FILE INFORMATION
 *  -----------------------------------------------------------------------------------------------------------------
 *        FILE NAME :  GPIO_Interface.h
 *        FILE DATE :  8/8/2023
 *        VERSION:   V1.0
 *        AUTHOR:   KAREEM WALID
 *        BRIEF EXPLANATION:

 *
 *********************************************************************************************************************/

 /* FILE GUARD */
#ifndef    GPIO_INTERFACE_H_
#define    GPIO_INTERFACE_H_


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../COMM/Bit_Math.h"
#include "../COMM/Platform_Types.h"
#include "../GPIO_Driver/GPIO_Private.h"
#include "../RCC_Driver/RCC_Interface.h"


/**********************************************************************************************************************
 *  GLOBAL ENUMs
 *********************************************************************************************************************/

/* -------------------------------------------- */
/* GPIO Ports for STM32F401xx */
typedef enum{
	GPIOA,
	GPIOB,
	GPIOC,
	GPIOD,
	GPIOE,
	GPIOH

}GPIO_PORTs_t;

/* ------------------------------------------------ */
/*Pin Status */
typedef enum{
	PIN_LOW,
	PIN_HIGH
}GPIO_PIN_STATUS_t;


/* ------------------------------------------------ */
/* GPIO PINS */
typedef enum {
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
}GPIO_PINs_t;

/* ------------------------------------------------------------ */
/* PIN MODE */
typedef  enum{
	INPUT_M,
	OUTPUT_M,
	ALTERNATIVE_M,
	ANALOG_M,
}PinMode_t;

/* ------------------------------------------------------------ */
/* PIN OUTPUT MODE */
typedef enum 
{
	PUSH_PULL,
	OPEN_DRAIN
}PinOutType_t;

/* ------------------------------------------------------------ */
/* PIN OUTPUT SPEED */
typedef enum {
	Low_Speed,
    Medium_Speed,
    High_Speed,
    Very_High_Speed
}PinOutSpeed_t;

/* ------------------------------------------------------------ */
/*PIN INPUT MODE */
typedef enum {
	No_pull_up_Down,
    Pull_up,
    Pull_down,
    Reserved
}PinInputType_t;

/* ------------------------------------------------------------ */
/* Pin AF Modes */
typedef enum{
	AF00,
	AF01,
	AF02,
	AF03,
	AF04,
	AF05,
	AF06,
	AF07,
	AF08,
	AF09,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15
}Alternative_Types_t;
/* ------------------------------------------------------------ */

/**********************************************************************************************************************
 *  GLOBAL STRUCTURES
 *********************************************************************************************************************/
/* This Struct Contain All Configuration For Any Pin */
typedef  struct
{
	PinMode_t  PinMode;
	PinOutType_t PinOutType;
	PinOutSpeed_t  PinOutSpeed;
	PinInputType_t PinInputType;
	Alternative_Types_t ALT_FUN;
	
}SPinConfig_t;


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void MGPIO_vPinInit(GPIO_PINs_t Pin , GPIO_PORTs_t Port , SPinConfig_t *pSPinConfig);
* \Description     : This Function Init GPIO Hardware By Enable RCC Then Enable GPIO that connected on AHB1 Bus
*                    then Init Pin Selected from Pin Configuration Structure
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) :  Pin, Port , Structure of Pin Configuration
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void MGPIO_vPinInit(GPIO_PINs_t Pin , GPIO_PORTs_t Port , SPinConfig_t *pSPinConfig);


/******************************************************************************
* \Syntax          :void MGPIO_vWritePin(GPIO_PINs_t Pin,GPIO_PORTs_t Port,GPIO_PIN_STATUS_t Level)
* \Description     :This Function Used when we want to write on any pin high or low
*                     by sending the pin port value
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) :  Pin, Port , Output Selected on the pin
* \Parameters (out): None
* \Return value:   :None
*******************************************************************************/
void MGPIO_vWritePin(GPIO_PINs_t Pin,GPIO_PORTs_t Port,GPIO_PIN_STATUS_t Level);
/******************************************************************************
* \Syntax          : void MGPIO_vTogglePin(GPIO_PINs_t Pin , GPIO_PORTs_t Port)
* \Description     : This Function is very simple it can toggle any Pin for high to low and low to high
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) :  Pin, Port
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void MGPIO_vTogglePin(GPIO_PINs_t Pin , GPIO_PORTs_t Port);
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : Pin ,Port
* \Parameters (out): GPIO_PIN_STATUS_t (High or LOW )
* \Return value:   : None
*******************************************************************************/
GPIO_PIN_STATUS_t  MGPIO_PIN_STATUS_ReadPin(GPIO_PINs_t Pin,GPIO_PORTs_t Port);


#endif   /* GPIO_INTERFACE_H_ */


/**********************************************************************************************************************
 *  END OF FILE: GPIO_Interface.h
 *********************************************************************************************************************/
