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
		if((GPIOA -> GPIO_MODER) == OUTPUT_M )
		{
			if((SPinConfigPoin->Level) == PIN_HIGH)
				SET_BIT(GPIOA -> GPIO_ODR,SPinConfigPoin->Pin);
			else
				CLR_BIT(GPIOA -> GPIO_ODR,SPinConfigPoin->Pin);
		}else if ((GPIOA -> GPIO_MODER) == INPUT_M )
		{
			SPinConfigPoin->Level = GPIOA->GPIO_IDR;
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



