#include "GPIO_Interface.h"



void GPIO_PinConfig(SPinConfig_t *SPinConfigPoin)
{


	switch(SPinConfigPoin->Port)
	{
	case GPIO_PA:

		// Mode
		GPIOA -> GPIO_MODER   &=~ (0b11<<((SPinConfigPoin->Pin)*2));
		GPIOA -> GPIO_MODER   |=  (((SPinConfigPoin->PinMode)<<(SPinConfigPoin->Pin)*2));

		// LEVEL   // TODO USE GPIOA_BSRR


		if(GET_BIT((GPIOA -> GPIO_MODER),(SPinConfigPoin->Pin)*2) == OUTPUT_M )
		{
			if((SPinConfigPoin->Level) == PIN_HIGH)
				SET_BIT(GPIOA -> GPIO_ODR,SPinConfigPoin->Pin);
			else
				CLR_BIT(GPIOA -> GPIO_ODR,SPinConfigPoin->Pin);

		}
		else if (GET_BIT((GPIOA -> GPIO_MODER),(SPinConfigPoin->Pin)*2) == INPUT_M )
		{
			SPinConfigPoin-> Level = GET_BIT(GPIOA->GPIO_IDR ,SPinConfigPoin->Pin);
		}

		// Speed
		GPIOA -> GPIO_OSPEEDER  &=~ (0b11<<((SPinConfigPoin->Pin)*2));
		GPIOA -> GPIO_OSPEEDER  |=  (((SPinConfigPoin->PinOutSpeed)<<(SPinConfigPoin->Pin)*2));


		// PinOutType Push pull / Open drain
		CLR_BIT(GPIOA -> GPIO_OTYPER,SPinConfigPoin->Pin);

		// PULL UP/DOWN
		GPIOA -> GPIO_PUPDR  &=~ (0b11<<((SPinConfigPoin->Pin)*2));
		GPIOA -> GPIO_PUPDR  |=  (((SPinConfigPoin->PinPullUpDown)<<(SPinConfigPoin->Pin)*2));


		break;

	}

}



