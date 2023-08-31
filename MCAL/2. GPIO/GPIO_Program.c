

#include "GPIO_Interface.h"

void GPIO_PinConfig(SPinConfig_t *SPinConfigPoin)
{


	switch(SPinConfigPoin->Port)
	{
	case GPIO_PA:

		// Mode
		/*
		 *00: Input (reset state)
		 * 01 General purpose output mode
		 * 10: Alternate function mode
		 * 11: Analog mode */
		GPIOA -> GPIO_MODER   &=~ (0b11<<((SPinConfigPoin->Pin)*2));
		GPIOA -> GPIO_MODER   |=  (((SPinConfigPoin->PinMode)<<(SPinConfigPoin->Pin)*2));

		// LEVEL   // TODO USE GPIOA_BSRR

		if( SPinConfigPoin -> PinMode == OUTPUT_M )
		{
			if((SPinConfigPoin->Level) == PIN_HIGH)
				SET_BIT(GPIOA -> GPIO_ODR,SPinConfigPoin->Pin);
			else
				CLR_BIT(GPIOA -> GPIO_ODR,SPinConfigPoin->Pin);

		}else if (SPinConfigPoin -> PinMode == INPUT_M )
		{
			SPinConfigPoin -> Level = GET_BIT(GPIOA->GPIO_IDR ,SPinConfigPoin->Pin);
		}

		// Speed
		/*
		 * 00: Low speed
         * 01: Medium speed
         * 10: High speed
         * 11: Very high speed

		 */
		GPIOA -> GPIO_OSPEEDER  &=~ (0b11<<((SPinConfigPoin->Pin)*2));
		GPIOA -> GPIO_OSPEEDER  |=  (((SPinConfigPoin->PinOutSpeed)<<(SPinConfigPoin->Pin)*2));


		// PinOutType Push pull / Open drain
		CLR_BIT(GPIOA -> GPIO_OTYPER,SPinConfigPoin->Pin);

		// PULL UP/DOWN
		GPIOA -> GPIO_PUPDR  &=~ (0b11<<((SPinConfigPoin->Pin)*2));
		GPIOA -> GPIO_PUPDR  |=  (((SPinConfigPoin->PinInputType)<<(SPinConfigPoin->Pin)*2));


		/* Alternative Function Section */
		/* Check on The Pin to  choosing register High or Low*/
		/* If The Function Between Pin0 and Pin7 */
		if(SPinConfigPoin->Pin >= PIN0 && SPinConfigPoin->Pin <= PIN7)
		{
			/* -- Save Value of AF in GPIOA_AFRL -- */
			/* Restore bits wanted to 0000 with kepting other bits without any changes */
			GPIOA -> GPIO_AFRL   &=~ (0b1111<<((SPinConfigPoin->Pin)*4)); 
            /* Store 4 bits in The Reg AFRL */			
		    GPIOA -> GPIO_AFRL   |=  (((SPinConfigPoin -> ALT_FUN)<<(SPinConfigPoin->Pin)*4));

                  /* If The Function Between Pin8 and Pin15 */
		}else if (SPinConfigPoin->Pin >= PIN7 && SPinConfigPoin->Pin <= PIN15)
		{
			/* -- Save Value of AF in GPIOA_AFRL -- */
			/* Restore bits wanted to 0000 with kepting other bits without any changes */
			GPIOA -> GPIO_AFRH   &=~ (0b1111<<((SPinConfigPoin->Pin)*4)); 
            /* Store 4 bits in The Reg AFRH */			
		    GPIOA -> GPIO_AFRH   |=  (((SPinConfigPoin -> ALT_FUN)<<(SPinConfigPoin->Pin)*4));
		}
		break;

	case GPIO_PB:

			// Mode
			GPIOB -> GPIO_MODER   &=~ (0b11<<((SPinConfigPoin->Pin)*2));
			GPIOB -> GPIO_MODER   |=  (((SPinConfigPoin->PinMode)<<(SPinConfigPoin->Pin)*2));

			// LEVEL   // TODO USE GPIOB_BSRR

			if( SPinConfigPoin -> PinMode == OUTPUT_M )
			{
				if((SPinConfigPoin->Level) == PIN_HIGH)
					SET_BIT(GPIOB -> GPIO_ODR,SPinConfigPoin->Pin);
				else
					CLR_BIT(GPIOB -> GPIO_ODR,SPinConfigPoin->Pin);

			}else if (SPinConfigPoin -> PinMode == INPUT_M )
			{
				SPinConfigPoin -> Level = GET_BIT(GPIOB->GPIO_IDR ,SPinConfigPoin->Pin);
			}

			// Speed
			GPIOB -> GPIO_OSPEEDER  &=~ (0b11<<((SPinConfigPoin->Pin)*2));
			GPIOB -> GPIO_OSPEEDER  |=  (((SPinConfigPoin->PinOutSpeed)<<(SPinConfigPoin->Pin)*2));


			// PinOutType Push pull / Open drain
			CLR_BIT(GPIOB -> GPIO_OTYPER,SPinConfigPoin->Pin);

			// PULL UP/DOWN
			GPIOB -> GPIO_PUPDR  &=~ (0b11<<((SPinConfigPoin->Pin)*2));
			GPIOB -> GPIO_PUPDR  |=  (((SPinConfigPoin->PinInputType)<<(SPinConfigPoin->Pin)*2));


			/* Alternative Function Section */
			/* Check on The Pin to  choosing register High or Low*/
			/* If The Function Between Pin0 and Pin7 */
			if(SPinConfigPoin->Pin >= PIN0 && SPinConfigPoin->Pin <= PIN7)
			{
				/* -- Save Value of AF in GPIOA_AFRL -- */
				/* Restore bits wanted to 0000 with kepting other bits without any changes */
				GPIOB -> GPIO_AFRL   &=~ (0b1111<<((SPinConfigPoin->Pin)*4));
	            /* Store 4 bits in The Reg AFRL */
				GPIOB -> GPIO_AFRL   |=  (((SPinConfigPoin -> ALT_FUN)<<(SPinConfigPoin->Pin)*4));

	                  /* If The Function Between Pin8 and Pin15 */
			}else if (SPinConfigPoin->Pin >= PIN7 && SPinConfigPoin->Pin <= PIN15)
			{
				/* -- Save Value of AF in GPIOA_AFRL -- */
				/* Restore bits wanted to 0000 with kepting other bits without any changes */
				GPIOB -> GPIO_AFRH   &=~ (0b1111<<((SPinConfigPoin->Pin)*4));
	            /* Store 4 bits in The Reg AFRH */
				GPIOB -> GPIO_AFRH   |=  (((SPinConfigPoin -> ALT_FUN)<<(SPinConfigPoin->Pin)*4));
			}
			break;

	default:
        /* do nothing */
		break;
 	}


}



