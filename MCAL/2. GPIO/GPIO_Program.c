/**********************************************************************************************************************
 *  FILE INFORMATION
 *  -----------------------------------------------------------------------------------------------------------------
 *        FILE NAME :  GPIO_Program.c
 *        FILE DATE :  10/8/2023
 *        VERSION:   V2.0
 *        AUTHOR:   KAREEM WALID
 *        BRIEF EXPLANATION:
 *
 **********************************************************************************************************************

   ==============================================================================
                    ##### GPIO Peripheral Features #####
   ==============================================================================



  ==============================================================================
                     ##### How To Use This Driver #####
  ==============================================================================




/* *********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "GPIO_Interface.h"


/* ===============================================================================
              ##### Initialization and de-initialization functions #####
   =============================================================================== */

/******************************************************************************
 * \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
 * \Description     : Describe this service
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : parameterName   Parameter Describtion
 * \Parameters (out): None
 * \Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
void MGPIO_vPinInit(GPIO_PORTs_t Port ,GPIO_PINs_t Pin ,SPinConfig_t *pSPinConfig)
{

	/*Switch on Ports GPIOA , GPIOB , GPIOC , GPIOD , GPIOE or GPIOH */
	switch(Port)
	{
	case GPIOA:

		/* -------------- SET MODE ------------------- */
		/* MODE Options:
		 * 00: Input (reset state)
		 * 01: General purpose output mode
		 * 10: Alternate function mode
		 * 11: Analog mode
		 */

		/* CLEAR TWO PINS SPECIFIC  */
		CLR_TWO_BIT(pGPIOA -> GPIO_MODER,Pin);
		/* SET TWO PINS SPECIFIC WITH MODE */
		SET_TWO_BIT(pGPIOA -> GPIO_MODER,Pin,pSPinConfig->PinMode);
		/* ----------------------------------------------------- */
		/* -------------- SET PIN OUTPUT TYPE ------------------- */
		/* OUTPUT TYPE Options:
		 * 0: Output push-pull (reset state)
		 * 1: Output open-drain
		 */


		/* ----------------------------------------------------- */
		/* -------------- SET OUTPUT SPEED --------------------- */
		/* SPEED Options:
		 * 00: Low speed
		 * 01: Medium speed
		 * 10: High speed
		 * 11: Very high speed
		 */

		/* CLEAR TWO PINS SPECIFIC  */
		CLR_TWO_BIT(pGPIOA -> GPIO_OSPEEDER,Pin);
		/* SET TWO PINS SPECIFIC WITH SPEED */
		SET_TWO_BIT(pGPIOA -> GPIO_OSPEEDER,Pin,pSPinConfig->PinOutSpeed);
		/* ----------------------------------------------------- */
		/* -------------- SET PIN INPUT TYPE ------------------- */
		/* INPUT TYPE Options:
		 * 00: No pull-up, pull-down
		 * 01: Pull-up
		 * 10: Pull-down
		 * 11: Reserved
		 */
		/* CLEAR TWO PINS SPECIFIC  */
		CLR_TWO_BIT(pGPIOA -> GPIO_PUPDR,Pin);
		/* SET TWO PINS SPECIFIC WITH SPEED */
		SET_TWO_BIT(pGPIOA -> GPIO_PUPDR,Pin,pSPinConfig->PinInputType);
		/* ----------------------------------------------------- */
		break;



	case GPIOB:

		break;

	case GPIOC:

		break;

	case GPIOD:
		break;

	case GPIOE:
		break;

	case GPIOH:
		break;
	}

}

/******************************************************************************
 * \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
 * \Description     : Describe this service
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : parameterName   Parameter Describtion
 * \Parameters (out): None
 * \Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
void MGPIO_vPinDeInit(GPIO_PORTs_t Port , SPinConfig_t *SPinConfigPoin)
{

}

/* ===============================================================================
                     ##### IO operation functions #####
     =============================================================================== */

/******************************************************************************
 * \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
 * \Description     : Describe this service
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : parameterName   Parameter Describtion
 * \Parameters (out): None
 * \Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
void MGPIO_vWritePin(GPIO_PORTs_t Port ,GPIO_PINs_t Pin,GPIO_PIN_STATUS_t Level)
{


}

/******************************************************************************
 * \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
 * \Description     : Describe this service
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : parameterName   Parameter Describtion
 * \Parameters (out): None
 * \Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
void MGPIO_vTogglePin(GPIO_PORTs_t Port,GPIO_PINs_t Pin)
{


}

/******************************************************************************
 * \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
 * \Description     : Describe this service
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : parameterName   Parameter Describtion
 * \Parameters (out): None
 * \Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
GPIO_PINs_t  MGPIO_vReadPin(GPIO_PORTs_t Port,GPIO_PINs_t Pin)
{

	return 0;
}

/**********************************************************************************************************************
 *  END OF FILE: GPIO_Program.c
 *********************************************************************************************************************/

