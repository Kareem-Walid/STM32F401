

#include "../RCC_Driver/RCC_Interface.h"



void  RCC_vInitSysClk(void)
{

#if    RCC_CLK_SRC  == HSI
	SET_BIT(RCC_RegPoiner -> RCC_CR,HSION);
	CLR_BIT(RCC_RegPoiner -> RCC_CFGR,SW0);
	CLR_BIT(RCC_RegPoiner -> RCC_CFGR,SW1);
	while(GET_BIT(RCC_RegPoiner -> RCC_CR,HSIRDY) == 0);


#elif  RCC_CLK_SRC  == HSE
	SET_BIT(RCC_RegPoiner -> RCC_CR , HSEON);
	SET_BIT(RCC_RegPoiner -> RCC_CFGR , SW0);
	CLR_BIT(RCC_RegPoiner -> RCC_CFGR ,SW1);
#elif  RCC_CLK_SRC  == PLL
	PLL_ConfigPointer -> PLLM = 10;
	PLL_ConfigPointer -> PLLN = 210;
	PLL_ConfigPointer -> PLLP = 4;

	SET_BIT(RCC_RegPoiner -> RCC_PLLCFGR , 22);   // TODO
	SET_BIT(RCC_RegPoiner -> RCC_CR, PLLON);
	SET_BIT(RCC_RegPoiner -> RCC_CFGR, SW1);
	CLR_BIT(RCC_RegPoiner -> RCC_CFGR, SW0);



#else
	// #error " Configuration Parameter is not Supported "
#endif

}

void RCC_vEnablePeripheral(uint8_t Copy_uint8_t_BusID, uint8_t Copy_PeripheralID )
{
	if((Copy_uint8_t_BusID > 3 ) || (Copy_PeripheralID > 31))
	{
		// Nothing
	}
	else
	{
		switch(Copy_uint8_t_BusID)
		{
		case AHB1:
			SET_BIT(RCC_RegPoiner -> RCC_AHB1ENR ,Copy_PeripheralID);
			break;

		case AHB2:
			if(Copy_PeripheralID == 7)
			{
				SET_BIT(RCC_RegPoiner -> RCC_AHB2ENR ,Copy_PeripheralID);
			}
			break;

		case APB1:
			SET_BIT(RCC_RegPoiner -> RCC_APB1ENR ,Copy_PeripheralID);
			break;

		case APB2:
			SET_BIT(RCC_RegPoiner -> RCC_APB2ENR ,Copy_PeripheralID);
			break;

		}

	}
}


void RCC_vDisablePeripheral(uint8_t Copy_uint8_t_BusID, uint8_t Copy_PeripheralID )
{
	if((Copy_uint8_t_BusID > 3 ) || (Copy_PeripheralID > 31))
	{
		// Nothing
	}
	else
	{
		switch(Copy_uint8_t_BusID)
		{
		case AHB1:
			CLR_BIT(RCC_RegPoiner -> RCC_AHB1ENR ,Copy_PeripheralID);
			break;

		case AHB2:
			if(Copy_PeripheralID == 7)
			{
				CLR_BIT(RCC_RegPoiner -> RCC_AHB2ENR ,Copy_PeripheralID);
			}
			break;

		case APB1:
			CLR_BIT(RCC_RegPoiner -> RCC_APB1ENR ,Copy_PeripheralID);
			break;

		case APB2:
			CLR_BIT(RCC_RegPoiner -> RCC_APB2ENR ,Copy_PeripheralID);
			break;

		}

	}
}
