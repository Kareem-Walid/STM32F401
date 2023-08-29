/**********************************************************************************************************************
 *  FILE INFORMATION
 *  -----------------------------------------------------------------------------------------------------------------
 *        FILE NAME :  USART_Program.c
 *        FILE DATE :
 *        VERSION:   V1.0
 *        AUTHOR:   KAREEM WALID
 *        BRIEF EXPLANATION:
 *        This File Contains all Functions Related on USART Peripheral
 *
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "USART_Interface.h"

#include  "../SysTick_Driver/SysTick_Interface.h"



/******************************************************************************
 * \Syntax          : void MUSART_vInit(void)
 * \Description     : This function responsible on Initialize USART Peripheral
 *
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Non-Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *
 *******************************************************************************/

void MUSART_vInit(void)
{
	/* Initialize Local Variables */
	float64_t Local_USART_DIV = 0;
	float64_t LoDIV_Fraction = 0;
	uint32_t  LoDIV_Mantissa = 0;


	/* --- START OF RCC Configuration ---  */

	/* Initialize RCC Clock */
	RCC_vInitSysClk();

	/* Initialize Clock for USART1 Connected on APB2 */
	RCC_vEnablePeripheral(APB2,USART1EN);

	/* Initialize Clock for GPIOA  Connected on AHB1 */
	RCC_vEnablePeripheral(AHB1,GPIOAEN);

	/* --- END OF RCC Configuration ---  */



	/* --- START OF GPIOA Configuration ---  */

	/* Configure Tx Pin in PortA PIN9 */
	SPinConfig_t Pin9_Tx;
	Pin9_Tx.Pin = PIN9;
	Pin9_Tx.Port = GPIO_PA;
	Pin9_Tx.PinMode = ALTERNATIVE_M;   /* Set Pin As Alternative Function */
	Pin9_Tx.ALT_FUN = AF07;
	Pin9_Tx.PinOutType = PUSH_PULL;    /* This from Data Sheet*/
	GPIO_PinConfig(&Pin9_Tx);

	/* Configure Rx Pin in PortA PIN9 */
	SPinConfig_t Pin10_Rx;
	Pin10_Rx.Pin = PIN10;
	Pin10_Rx.Port = GPIO_PA;
	Pin10_Rx.PinMode = ALTERNATIVE_M;   /* Set Pin As Alternative Function */
	Pin10_Rx.ALT_FUN = AF07;
	Pin10_Rx.PinOutType = PUSH_PULL;    /* This from Data Sheet*/
	GPIO_PinConfig(&Pin10_Rx);          /* Send Structure to the Function in GPIO Driver */

	/* --- END OF GPIOA Configuration ---  */



	/* --- START OF USART Configuration ---  */

	/* Calculate Equations */
	/* Constant Equation from USART DataSheet*/
	Local_USART_DIV = (((float64_t)USART_CLK)/(8 *(USART_BOUT_RATE)*(2 - GET_BIT(USART1-> USART_CR1, OVER8))));

	/* Save Mantissa only on Local Variable */
	LoDIV_Mantissa =  (uint32_t) Local_USART_DIV;

	/* Save Fraction only on Local Variable */
	LoDIV_Fraction =  (Local_USART_DIV - LoDIV_Mantissa);


	/* Checking on The Special Case */
	if(LoDIV_Fraction >= 0.97)
	{
		/* Increase Mantissa by 1 and make fraction = 0*/
		LoDIV_Mantissa ++;
		LoDIV_Fraction = 0.00;
	}else{
		/* Constant Equation form Data sheet*/
		LoDIV_Fraction = LoDIV_Fraction * 16 ;
	}

	/* Round the Fraction Number to the Nearest Number */
	/* Check First if the number also */
	if(LoDIV_Fraction != 0.00 && (LoDIV_Fraction - (uint32_t)LoDIV_Fraction >= 0.5))
	{
		LoDIV_Fraction = (uint32_t)LoDIV_Fraction ;
		LoDIV_Fraction ++;
	}else if (LoDIV_Fraction != 0.00 && (LoDIV_Fraction - (uint32_t)LoDIV_Fraction < 0.5)){
		LoDIV_Fraction = (uint32_t)LoDIV_Fraction ;
		LoDIV_Fraction --;
	}



	/* Store Value of Mantissa and Fraction in USART_BRR */

	/* Clear the Previous value first */
	// USART1 -> USART_BRR  = 0 ;
	/* Store Value in Register */
	USART1 -> USART_BRR= ((LoDIV_Mantissa << 4 )| (uint32_t)LoDIV_Fraction);


	/* Configure the Data Length */

#if   USART_DATA_LENGTH == DATA_SIZE_8
	CLR_BIT( USART1 -> USART_CR1,M);
#elif USART_DATA_LENGTH == DATA_SIZE_9
	SET_BIT( USART1 -> USART_CR1,M);
#endif

	/* ***** Last Step Enable USART ****** */
	SET_BIT( USART1 -> USART_CR1,UE);
	SET_BIT( USART1 -> USART_CR1,TE); // last changes
	SET_BIT( USART1 -> USART_CR1,RE);  // last changes

	/* --- END OF USART Configuration ---  */
}






/******************************************************************************
 * \Syntax          : void MUSART_vSendData(uint8_t* DataTrans,uint8_t Copy_lenght)
 * \Description     : This function responsible on Sending Data by USART
 *
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Non-Reentrant
 * \Parameters (in) : uint8_t* DataTrans , uint8_t Copy_lenght
 * \Parameters (out): None
 * \Return value:   : None
 *
 *******************************************************************************/

void MUSART_vSendData(uint8_t* DataTrans)
{
	uint8_t  Local_Counter = 0;

	/* We will Send Data through  USART_DR Register */
    /* Looping on Every Element of Array */
	while(Local_Counter != '/0')
	{

	/* Load Data from Array Index to USART_DR Register */
	USART1 -> USART_DR = DataTrans[Local_Counter];

	/* Wait Until Data Transmitted */
	while(GET_BIT(USART1 -> USART_SR,TXE) == 0 );

	/* Increase Counter to Next Element of Array */
	Local_Counter ++;
    STK_vDelay_(8000000);

	}

	/* Clear Flag */

}



/******************************************************************************
 * \Syntax          : void MUSART_vReciveData(uint8_t* DataRecive)
 * \Description     : This function responsible on Receiving Data by USART
 *
 * \Sync\Async      : synchronous
 * \Reentrancy      : Non-Reentrant
 * \Parameters (in) : uint8_t* DataRecive
 * \Parameters (out): None
 * \Return value:   : None
 *
 *******************************************************************************/

void MUSART_vReciveData(uint8_t* DataRecive)
{
	/* We will Receive Data through  USART_DR Register */

	/* Wait Until Data Received by rising bit RXNE by 1 */
	while(GET_BIT(USART1 -> USART_DR,RXNE) == 0 );

	/* Load Data in Location by using Pointer Dereference */
	*DataRecive = USART1 -> USART_DR;

}

