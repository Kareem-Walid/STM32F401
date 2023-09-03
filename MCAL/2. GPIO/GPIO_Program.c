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
              ##### Initialization and De-initialization functions #####
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
void MGPIO_vPinInit(GPIO_PINs_t Pin , GPIO_PORTs_t Port , SPinConfig_t *pSPinConfig)
{

	/* Initialize  RCC Clock */

	RCC_vInitSysClk();
	/*Switch on Ports GPIOA , GPIOB , GPIOC , GPIOD , GPIOE or GPIOH */
	switch(Port)
	{
	    /* --------------------------------------------------------------------- */
		/* ------------------- GPIOA Port ---------------------------------------*/
	case GPIOA:
		/* Before Load Any Data We must to Enable Clock For Port  */
		/* Enable Clock For Port A that be connected on AHB1 Bus */
		RCC_vEnablePeripheral(AHB1,GPIOAEN);
		/* -------------- SET MODE ------------------- */
		/* MODE Options:
		 * 00: Input (reset state)
		 * 01: General purpose output mode
		 * 10: Alternate function mode
		 * 11: Analog mode
		 */

		/* CLEAR TWO PINS SPECIFIC  */
		pGPIOA -> GPIO_MODER   &=~ (0b11<<(Pin*2));
		/* SET TWO PINS SPECIFIC WITH MODE */
		pGPIOA -> GPIO_MODER   |=  (((pSPinConfig->PinMode)<<(Pin*2)));
		/* ----------------------------------------------------- */
		/* -------------- SET PIN OUTPUT TYPE ------------------- */
		/* OUTPUT TYPE Options:
		 * 0: Output push-pull (reset state)
		 * 1: Output open-drain
		 */
		/* CLEAR TWO PINS SPECIFIC  */
		CLR_BIT(pGPIOA -> GPIO_OTYPER,Pin);
		if(pSPinConfig ->PinOutType == OPEN_DRAIN)
		{
			SET_BIT(pGPIOA -> GPIO_OTYPER,Pin);
		}

		/* ----------------------------------------------------- */
		/* -------------- SET OUTPUT SPEED --------------------- */
		/* SPEED Options:
		 * 00: Low speed
		 * 01: Medium speed
		 * 10: High speed
		 * 11: Very high speed
		 */

		/* CLEAR TWO PINS SPECIFIC  */
		pGPIOA -> GPIO_OSPEEDER  &=~ (0b11<<((Pin)*2));
		/* SET TWO PINS SPECIFIC WITH SPEED */
		pGPIOA -> GPIO_OSPEEDER  |=  (((pSPinConfig->PinOutSpeed)<<(Pin)*2));
		/* ----------------------------------------------------- */
		/* -------------- SET PIN INPUT TYPE ------------------- */
		/* INPUT TYPE Options:
		 * 00: No pull-up, pull-down
		 * 01: Pull-up
		 * 10: Pull-down
		 * 11: Reserved
		 */
		/* CLEAR TWO PINS SPECIFIC  */
		pGPIOA -> GPIO_PUPDR  &=~ (0b11<<((Pin)*2));
		/* SET TWO PINS SPECIFIC WITH SPEED */
		pGPIOA -> GPIO_PUPDR  |=  (((pSPinConfig->PinInputType)<<(Pin)*2));

		/* ------------------------------------------------------ */
		/*-----------  Alternative Function Section ------------- */


		/* Check on The Pin to  choosing register High or Low*/
		/* If The Function Between Pin0 and Pin7 */
		if(Pin >= PIN0 && Pin <= PIN7)
		{
			/* -- Save Value of AF in GPIOA_AFRL -- */
			/* Restore bits wanted to 0000 with kepting other bits without any changes */
			pGPIOA -> GPIO_AFRL   &=~ (0b1111<<((Pin)*4));
            /* Store 4 bits in The Reg AFRL */
		    pGPIOA -> GPIO_AFRL   |=  (((pSPinConfig -> ALT_FUN)<<(Pin)*4));

                  /* If The Function Between Pin8 and Pin15 */
		}else if (Pin >= PIN7 && Pin <= PIN15)
		{
			/* -- Save Value of AF in GPIOA_AFRL -- */
			/* Restore bits wanted to 0000 with kepting other bits without any changes */
			pGPIOA -> GPIO_AFRH   &=~ (0b1111<<((Pin % 8)*4));
            /* Store 4 bits in The Register AFRH */
		    pGPIOA -> GPIO_AFRH   |=  (((pSPinConfig -> ALT_FUN)<<(Pin % 8)*4));
		}
		break;
		
	    /* --------------------------------------------------------------------- */
		/* ------------------- GPIOB Port ---------------------------------------*/
	case GPIOB:
			/* Before Load Any Data We must to Enable Clock For Port  */
			/* Enable Clock For Port A that be connected on AHB1 Bus */
			RCC_vEnablePeripheral(AHB1,GPIOBEN);
			/* -------------- SET MODE ------------------- */
			/* MODE Options:
			 * 00: Input (reset state)
			 * 01: General purpose output mode
			 * 10: Alternate function mode
			 * 11: Analog mode
			 */

			/* CLEAR TWO PINS SPECIFIC  */
			pGPIOB -> GPIO_MODER   &=~ (0b11<<(Pin*2));
			/* SET TWO PINS SPECIFIC WITH MODE */
			pGPIOB -> GPIO_MODER   |=  (((pSPinConfig->PinMode)<<(Pin*2)));
			/* ----------------------------------------------------- */
			/* -------------- SET PIN OUTPUT TYPE ------------------- */
			/* OUTPUT TYPE Options:
			 * 0: Output push-pull (reset state)
			 * 1: Output open-drain
			 */
			/* CLEAR TWO PINS SPECIFIC  */
			CLR_BIT(pGPIOB -> GPIO_OTYPER,Pin);
			if(pSPinConfig ->PinOutType == OPEN_DRAIN)
			{
				SET_BIT(pGPIOB -> GPIO_OTYPER,Pin);
			}

			/* ----------------------------------------------------- */
			/* -------------- SET OUTPUT SPEED --------------------- */
			/* SPEED Options:
			 * 00: Low speed
			 * 01: Medium speed
			 * 10: High speed
			 * 11: Very high speed
			 */

			/* CLEAR TWO PINS SPECIFIC  */
			pGPIOB -> GPIO_OSPEEDER  &=~ (0b11<<((Pin)*2));
			/* SET TWO PINS SPECIFIC WITH SPEED */
			pGPIOB -> GPIO_OSPEEDER  |=  (((pSPinConfig->PinOutSpeed)<<(Pin)*2));
			/* ----------------------------------------------------- */
			/* -------------- SET PIN INPUT TYPE ------------------- */
			/* INPUT TYPE Options:
			 * 00: No pull-up, pull-down
			 * 01: Pull-up
			 * 10: Pull-down
			 * 11: Reserved
			 */
			/* CLEAR TWO PINS SPECIFIC  */
			pGPIOB -> GPIO_PUPDR  &=~ (0b11<<((Pin)*2));
			/* SET TWO PINS SPECIFIC WITH SPEED */
			pGPIOB -> GPIO_PUPDR  |=  (((pSPinConfig->PinInputType)<<(Pin)*2));

			/* ------------------------------------------------------ */
			/*-----------  Alternative Function Section ------------- */


			/* Check on The Pin to  choosing register High or Low*/
			/* If The Function Between Pin0 and Pin7 */
			if(Pin >= PIN0 && Pin <= PIN7)
			{
				/* -- Save Value of AF in GPIOA_AFRL -- */
				/* Restore bits wanted to 0000 with kepting other bits without any changes */
				pGPIOB -> GPIO_AFRL   &=~ (0b1111<<((Pin)*4));
	            /* Store 4 bits in The Reg AFRL */
			    pGPIOB -> GPIO_AFRL   |=  (((pSPinConfig -> ALT_FUN)<<(Pin)*4));

	                  /* If The Function Between Pin8 and Pin15 */
			}else if (Pin >= PIN7 && Pin <= PIN15)
			{
				/* -- Save Value of AF in GPIOA_AFRL -- */
				/* Restore bits wanted to 0000 with kepting other bits without any changes */
				pGPIOB -> GPIO_AFRH   &=~ (0b1111<<((Pin % 8)*4));
	            /* Store 4 bits in The Register AFRH */
			    pGPIOB -> GPIO_AFRH   |=  (((pSPinConfig -> ALT_FUN)<<(Pin % 8)*4));
			}
			break;
			 /* --------------------------------------------------------------------- */
			/* ------------------- GPIOC Port ---------------------------------------*/

	case GPIOC:
			/* Before Load Any Data We must to Enable Clock For Port  */
			/* Enable Clock For Port A that be connected on AHB1 Bus */
			RCC_vEnablePeripheral(AHB1,GPIOCEN);
			/* -------------- SET MODE ------------------- */
			/* MODE Options:
			 * 00: Input (reset state)
			 * 01: General purpose output mode
			 * 10: Alternate function mode
			 * 11: Analog mode
			 */

			/* CLEAR TWO PINS SPECIFIC  */
			pGPIOC -> GPIO_MODER   &=~ (0b11<<(Pin*2));
			/* SET TWO PINS SPECIFIC WITH MODE */
			pGPIOC -> GPIO_MODER   |=  (((pSPinConfig->PinMode)<<(Pin*2)));
			/* ----------------------------------------------------- */
			/* -------------- SET PIN OUTPUT TYPE ------------------- */
			/* OUTPUT TYPE Options:
			 * 0: Output push-pull (reset state)
			 * 1: Output open-drain
			 */
			/* CLEAR TWO PINS SPECIFIC  */
			CLR_BIT(pGPIOC -> GPIO_OTYPER,Pin);
			if(pSPinConfig ->PinOutType == OPEN_DRAIN)
			{
				SET_BIT(pGPIOC -> GPIO_OTYPER,Pin);
			}

			/* ----------------------------------------------------- */
			/* -------------- SET OUTPUT SPEED --------------------- */
			/* SPEED Options:
			 * 00: Low speed
			 * 01: Medium speed
			 * 10: High speed
			 * 11: Very high speed
			 */

			/* CLEAR TWO PINS SPECIFIC  */
			pGPIOC -> GPIO_OSPEEDER  &=~ (0b11<<((Pin)*2));
			/* SET TWO PINS SPECIFIC WITH SPEED */
			pGPIOC -> GPIO_OSPEEDER  |=  (((pSPinConfig->PinOutSpeed)<<(Pin)*2));
			/* ----------------------------------------------------- */
			/* -------------- SET PIN INPUT TYPE ------------------- */
			/* INPUT TYPE Options:
			 * 00: No pull-up, pull-down
			 * 01: Pull-up
			 * 10: Pull-down
			 * 11: Reserved
			 */
			/* CLEAR TWO PINS SPECIFIC  */
			pGPIOC -> GPIO_PUPDR  &=~ (0b11<<((Pin)*2));
			/* SET TWO PINS SPECIFIC WITH SPEED */
			pGPIOC -> GPIO_PUPDR  |=  (((pSPinConfig->PinInputType)<<(Pin)*2));

			/* ------------------------------------------------------ */
			/*-----------  Alternative Function Section ------------- */


			/* Check on The Pin to  choosing register High or Low*/
			/* If The Function Between Pin0 and Pin7 */
			if(Pin >= PIN0 && Pin <= PIN7)
			{
				/* -- Save Value of AF in GPIOA_AFRL -- */
				/* Restore bits wanted to 0000 with kepting other bits without any changes */
				pGPIOC -> GPIO_AFRL   &=~ (0b1111<<((Pin)*4));
	            /* Store 4 bits in The Reg AFRL */
			    pGPIOC -> GPIO_AFRL   |=  (((pSPinConfig -> ALT_FUN)<<(Pin)*4));

	                  /* If The Function Between Pin8 and Pin15 */
			}else if (Pin >= PIN7 && Pin <= PIN15)
			{
				/* -- Save Value of AF in GPIOA_AFRL -- */
				/* Restore bits wanted to 0000 with kepting other bits without any changes */
				pGPIOC -> GPIO_AFRH   &=~ (0b1111<<((Pin % 8)*4));
	            /* Store 4 bits in The Register AFRH */
			    pGPIOC -> GPIO_AFRH   |=  (((pSPinConfig -> ALT_FUN)<<(Pin % 8)*4));
			}
			break;
			 /* --------------------------------------------------------------------- */
			 /* ------------------- GPIOD Port ---------------------------------------*/
	case GPIOD:
			/* Before Load Any Data We must to Enable Clock For Port  */
			/* Enable Clock For Port A that be connected on AHB1 Bus */
			RCC_vEnablePeripheral(AHB1,GPIODEN);
			/* -------------- SET MODE ------------------- */
			/* MODE Options:
			 * 00: Input (reset state)
			 * 01: General purpose output mode
			 * 10: Alternate function mode
			 * 11: Analog mode
			 */

			/* CLEAR TWO PINS SPECIFIC  */
			pGPIOD -> GPIO_MODER   &=~ (0b11<<(Pin*2));
			/* SET TWO PINS SPECIFIC WITH MODE */
			pGPIOD -> GPIO_MODER   |=  (((pSPinConfig->PinMode)<<(Pin*2)));
			/* ----------------------------------------------------- */
			/* -------------- SET PIN OUTPUT TYPE ------------------- */
			/* OUTPUT TYPE Options:
			 * 0: Output push-pull (reset state)
			 * 1: Output open-drain
			 */
			/* CLEAR TWO PINS SPECIFIC  */
			CLR_BIT(pGPIOD -> GPIO_OTYPER,Pin);
			if(pSPinConfig ->PinOutType == OPEN_DRAIN)
			{
				SET_BIT(pGPIOD -> GPIO_OTYPER,Pin);
			}

			/* ----------------------------------------------------- */
			/* -------------- SET OUTPUT SPEED --------------------- */
			/* SPEED Options:
			 * 00: Low speed
			 * 01: Medium speed
			 * 10: High speed
			 * 11: Very high speed
			 */

			/* CLEAR TWO PINS SPECIFIC  */
			pGPIOD -> GPIO_OSPEEDER  &=~ (0b11<<((Pin)*2));
			/* SET TWO PINS SPECIFIC WITH SPEED */
			pGPIOD -> GPIO_OSPEEDER  |=  (((pSPinConfig->PinOutSpeed)<<(Pin)*2));
			/* ----------------------------------------------------- */
			/* -------------- SET PIN INPUT TYPE ------------------- */
			/* INPUT TYPE Options:
			 * 00: No pull-up, pull-down
			 * 01: Pull-up
			 * 10: Pull-down
			 * 11: Reserved
			 */
			/* CLEAR TWO PINS SPECIFIC  */
			pGPIOD -> GPIO_PUPDR  &=~ (0b11<<((Pin)*2));
			/* SET TWO PINS SPECIFIC WITH SPEED */
			pGPIOD -> GPIO_PUPDR  |=  (((pSPinConfig->PinInputType)<<(Pin)*2));

			/* ------------------------------------------------------ */
			/*-----------  Alternative Function Section ------------- */


			/* Check on The Pin to  choosing register High or Low*/
			/* If The Function Between Pin0 and Pin7 */
			if(Pin >= PIN0 && Pin <= PIN7)
			{
				/* -- Save Value of AF in GPIOA_AFRL -- */
				/* Restore bits wanted to 0000 with kepting other bits without any changes */
				pGPIOD -> GPIO_AFRL   &=~ (0b1111<<((Pin)*4));
	            /* Store 4 bits in The Reg AFRL */
			    pGPIOD -> GPIO_AFRL   |=  (((pSPinConfig -> ALT_FUN)<<(Pin)*4));

	                  /* If The Function Between Pin8 and Pin15 */
			}else if (Pin >= PIN7 && Pin <= PIN15)
			{
				/* -- Save Value of AF in GPIOA_AFRL -- */
				/* Restore bits wanted to 0000 with kepting other bits without any changes */
				pGPIOD -> GPIO_AFRH   &=~ (0b1111<<((Pin % 8)*4));
	            /* Store 4 bits in The Register AFRH */
			    pGPIOD -> GPIO_AFRH   |=  (((pSPinConfig -> ALT_FUN)<<(Pin % 8)*4));
			}
			break;
			 /* --------------------------------------------------------------------- */
			 /* ------------------- GPIOE Port ---------------------------------------*/
	case GPIOE:
			/* Before Load Any Data We must to Enable Clock For Port  */
			/* Enable Clock For Port A that be connected on AHB1 Bus */
			RCC_vEnablePeripheral(AHB1,GPIOEEN);
			/* -------------- SET MODE ------------------- */
			/* MODE Options:
			 * 00: Input (reset state)
			 * 01: General purpose output mode
			 * 10: Alternate function mode
			 * 11: Analog mode
			 */

			/* CLEAR TWO PINS SPECIFIC  */
			pGPIOE -> GPIO_MODER   &=~ (0b11<<(Pin*2));
			/* SET TWO PINS SPECIFIC WITH MODE */
			pGPIOE -> GPIO_MODER   |=  (((pSPinConfig->PinMode)<<(Pin*2)));
			/* ----------------------------------------------------- */
			/* -------------- SET PIN OUTPUT TYPE ------------------- */
			/* OUTPUT TYPE Options:
			 * 0: Output push-pull (reset state)
			 * 1: Output open-drain
			 */
			/* CLEAR TWO PINS SPECIFIC  */
			CLR_BIT(pGPIOE -> GPIO_OTYPER,Pin);
			if(pSPinConfig ->PinOutType == OPEN_DRAIN)
			{
				SET_BIT(pGPIOE -> GPIO_OTYPER,Pin);
			}

			/* ----------------------------------------------------- */
			/* -------------- SET OUTPUT SPEED --------------------- */
			/* SPEED Options:
			 * 00: Low speed
			 * 01: Medium speed
			 * 10: High speed
			 * 11: Very high speed
			 */

			/* CLEAR TWO PINS SPECIFIC  */
			pGPIOE -> GPIO_OSPEEDER  &=~ (0b11<<((Pin)*2));
			/* SET TWO PINS SPECIFIC WITH SPEED */
			pGPIOE -> GPIO_OSPEEDER  |=  (((pSPinConfig->PinOutSpeed)<<(Pin)*2));
			/* ----------------------------------------------------- */
			/* -------------- SET PIN INPUT TYPE ------------------- */
			/* INPUT TYPE Options:
			 * 00: No pull-up, pull-down
			 * 01: Pull-up
			 * 10: Pull-down
			 * 11: Reserved
			 */
			/* CLEAR TWO PINS SPECIFIC  */
			pGPIOE -> GPIO_PUPDR  &=~ (0b11<<((Pin)*2));
			/* SET TWO PINS SPECIFIC WITH SPEED */
			pGPIOE -> GPIO_PUPDR  |=  (((pSPinConfig->PinInputType)<<(Pin)*2));

			/* ------------------------------------------------------ */
			/*-----------  Alternative Function Section ------------- */


			/* Check on The Pin to  choosing register High or Low*/
			/* If The Function Between Pin0 and Pin7 */
			if(Pin >= PIN0 && Pin <= PIN7)
			{
				/* -- Save Value of AF in GPIOA_AFRL -- */
				/* Restore bits wanted to 0000 with kepting other bits without any changes */
				pGPIOE -> GPIO_AFRL   &=~ (0b1111<<((Pin)*4));
	            /* Store 4 bits in The Reg AFRL */
			    pGPIOE -> GPIO_AFRL   |=  (((pSPinConfig -> ALT_FUN)<<(Pin)*4));

	                  /* If The Function Between Pin8 and Pin15 */
			}else if (Pin >= PIN7 && Pin <= PIN15)
			{
				/* -- Save Value of AF in GPIOA_AFRL -- */
				/* Restore bits wanted to 0000 with kepting other bits without any changes */
				pGPIOE -> GPIO_AFRH   &=~ (0b1111<<((Pin % 8)*4));
	            /* Store 4 bits in The Register AFRH */
			    pGPIOE -> GPIO_AFRH   |=  (((pSPinConfig -> ALT_FUN)<<(Pin % 8)*4));
			}
			break;
			 /* --------------------------------------------------------------------- */
			 /* ------------------- GPIOH Port ---------------------------------------*/
	case GPIOH:
			/* Before Load Any Data We must to Enable Clock For Port  */
			/* Enable Clock For Port A that be connected on AHB1 Bus */
			RCC_vEnablePeripheral(AHB1,GPIOHEN);
			/* -------------- SET MODE ------------------- */
			/* MODE Options:
			 * 00: Input (reset state)
			 * 01: General purpose output mode
			 * 10: Alternate function mode
			 * 11: Analog mode
			 */

			/* CLEAR TWO PINS SPECIFIC  */
			pGPIOH -> GPIO_MODER   &=~ (0b11<<(Pin*2));
			/* SET TWO PINS SPECIFIC WITH MODE */
			pGPIOH -> GPIO_MODER   |=  (((pSPinConfig->PinMode)<<(Pin*2)));
			/* ----------------------------------------------------- */
			/* -------------- SET PIN OUTPUT TYPE ------------------- */
			/* OUTPUT TYPE Options:
			 * 0: Output push-pull (reset state)
			 * 1: Output open-drain
			 */
			/* CLEAR TWO PINS SPECIFIC  */
			CLR_BIT(pGPIOH -> GPIO_OTYPER,Pin);
			if(pSPinConfig ->PinOutType == OPEN_DRAIN)
			{
				SET_BIT(pGPIOH -> GPIO_OTYPER,Pin);
			}

			/* ----------------------------------------------------- */
			/* -------------- SET OUTPUT SPEED --------------------- */
			/* SPEED Options:
			 * 00: Low speed
			 * 01: Medium speed
			 * 10: High speed
			 * 11: Very high speed
			 */

			/* CLEAR TWO PINS SPECIFIC  */
			pGPIOH -> GPIO_OSPEEDER  &=~ (0b11<<((Pin)*2));
			/* SET TWO PINS SPECIFIC WITH SPEED */
			pGPIOH -> GPIO_OSPEEDER  |=  (((pSPinConfig->PinOutSpeed)<<(Pin)*2));
			/* ----------------------------------------------------- */
			/* -------------- SET PIN INPUT TYPE ------------------- */
			/* INPUT TYPE Options:
			 * 00: No pull-up, pull-down
			 * 01: Pull-up
			 * 10: Pull-down
			 * 11: Reserved
			 */
			/* CLEAR TWO PINS SPECIFIC  */
			pGPIOH -> GPIO_PUPDR  &=~ (0b11<<((Pin)*2));
			/* SET TWO PINS SPECIFIC WITH SPEED */
			pGPIOH -> GPIO_PUPDR  |=  (((pSPinConfig->PinInputType)<<(Pin)*2));

			/* ------------------------------------------------------ */
			/*-----------  Alternative Function Section ------------- */


			/* Check on The Pin to  choosing register High or Low*/
			/* If The Function Between Pin0 and Pin7 */
			if(Pin >= PIN0 && Pin <= PIN7)
			{
				/* -- Save Value of AF in GPIOA_AFRL -- */
				/* Restore bits wanted to 0000 with kepting other bits without any changes */
				pGPIOH -> GPIO_AFRL   &=~ (0b1111<<((Pin)*4));
	            /* Store 4 bits in The Reg AFRL */
			    pGPIOH -> GPIO_AFRL   |=  (((pSPinConfig -> ALT_FUN)<<(Pin)*4));

	                  /* If The Function Between Pin8 and Pin15 */
			}else if (Pin >= PIN7 && Pin <= PIN15)
			{
				/* -- Save Value of AF in GPIOA_AFRL -- */
				/* Restore bits wanted to 0000 with kepting other bits without any changes */
				pGPIOH -> GPIO_AFRH   &=~ (0b1111<<((Pin % 8)*4));
	            /* Store 4 bits in The Register AFRH */
			    pGPIOH -> GPIO_AFRH   |=  (((pSPinConfig -> ALT_FUN)<<(Pin % 8)*4));
			}
			break;

			 /* --------------------------------------------------------------------- */

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
void MGPIO_vPinDeInit(GPIO_PORTs_t Port ,GPIO_PINs_t Pin, SPinConfig_t *SPinConfigPoin)
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
void MGPIO_vWritePin(GPIO_PINs_t Pin,GPIO_PORTs_t Port,GPIO_PIN_STATUS_t Level)
{
	/* Switch on Ports GPIOA , GPIOB , GPIOC , GPIOD , GPIOE or GPIOH */
	switch(Port)
	{
	/* ------------------------- */
	/* ----- PORTA ------------ */
	case GPIOA:
		if(Level == PIN_HIGH){SET_BIT(pGPIOA->GPIO_ODR,Pin);}
		else{CLR_BIT(pGPIOA->GPIO_ODR,Pin);}
		break;

		/* ------------------------- */
		/* ----- PORTB ------------ */
	case GPIOB:
		if(Level == PIN_HIGH){SET_BIT(pGPIOB->GPIO_ODR,Pin);}
		else{CLR_BIT(pGPIOB->GPIO_ODR,Pin);}
		break;

		/* ------------------------- */
		/* ----- PORTC ------------ */
	case GPIOC:
		if(Level == PIN_HIGH){SET_BIT(pGPIOC->GPIO_ODR,Pin);}
		else{CLR_BIT(pGPIOC->GPIO_ODR,Pin);}
		break;

		/* ------------------------- */
		/* ----- PORTD ------------ */
	case GPIOD:
		if(Level == PIN_HIGH){ SET_BIT(pGPIOD->GPIO_ODR,Pin);}
		else{CLR_BIT(pGPIOD->GPIO_ODR,Pin);}
		break;

		/* ------------------------- */
		/* ----- PORTE ------------ */
	case GPIOE:
		if(Level == PIN_HIGH){ SET_BIT(pGPIOE->GPIO_ODR,Pin);}
		else{CLR_BIT(pGPIOE->GPIO_ODR,Pin);}
		break;
		/* ------------------------- */
		/* ----- PORTH ------------ */
	case GPIOH:
		if(Level == PIN_HIGH){SET_BIT(pGPIOH->GPIO_ODR,Pin);}
		else{CLR_BIT(pGPIOH->GPIO_ODR,Pin);}
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
void MGPIO_vTogglePin(GPIO_PINs_t Pin , GPIO_PORTs_t Port)
{
	switch(Port)
	{
	/* ------------------------- */
	/* ----- PORTA ------------ */
	case GPIOA:
		TOG_BIT(pGPIOA->GPIO_ODR,Pin);
		break;

		/* ------------------------- */
		/* ----- PORTB ------------ */
	case GPIOB:
		TOG_BIT(pGPIOB->GPIO_ODR,Pin);
		break;

		/* ------------------------- */
		/* ----- PORTC ------------ */
	case GPIOC:
		TOG_BIT(pGPIOC->GPIO_ODR,Pin);
		break;

		/* ------------------------- */
		/* ----- PORTD ------------ */
	case GPIOD:
		TOG_BIT(pGPIOD->GPIO_ODR,Pin);
		break;

		/* ------------------------- */
		/* ----- PORTE ------------ */
	case GPIOE:
		TOG_BIT(pGPIOE->GPIO_ODR,Pin);
		break;

		/* ------------------------- */
		/* ----- PORTH ------------ */
	case GPIOH:
		TOG_BIT(pGPIOH->GPIO_ODR,Pin);
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
GPIO_PIN_STATUS_t  MGPIO_PIN_STATUS_ReadPin(GPIO_PINs_t Pin, GPIO_PORTs_t Port)
{

	GPIO_PIN_STATUS_t Level;
	switch(Port)
	{
	/* ------------------------- */
	/* ----- PORTA ------------ */
	case GPIOA:
		Level = GET_BIT(pGPIOA->GPIO_IDR,Pin);
		break;

		/* ------------------------- */
		/* ----- PORTB ------------ */
	case GPIOB:
		Level = GET_BIT(pGPIOB->GPIO_IDR,Pin);
		break;

		/* ------------------------- */
		/* ----- PORTC ------------ */
	case GPIOC:
		Level = GET_BIT(pGPIOC->GPIO_IDR,Pin);
		break;

		/* ------------------------- */
		/* ----- PORTD ------------ */
	case GPIOD:
		Level = GET_BIT(pGPIOD->GPIO_IDR,Pin);
		break;

		/* ------------------------- */
		/* ----- PORTE ------------ */
	case GPIOE:
		Level = GET_BIT(pGPIOE->GPIO_IDR,Pin);
		break;


		/* ------------------------- */
		/* ----- PORTH ------------ */
	case GPIOH:
		Level = GET_BIT(pGPIOH->GPIO_IDR,Pin);
		break;


	}

	return Level;
}


/**********************************************************************************************************************
 *  END OF FILE: GPIO_Program.c
 *********************************************************************************************************************/

