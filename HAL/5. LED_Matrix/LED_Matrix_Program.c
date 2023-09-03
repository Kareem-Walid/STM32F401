/**********************************************************************************************************************
 *  FILE INFORMATION
 *  -----------------------------------------------------------------------------------------------------------------
 *        FILE NAME :  USART_Program.c
 *        FILE DATE :
 *        VERSION:   V1.0
 *        AUTHOR:   KAREEM WALID
 *        BRIEF EXPLANATION:
 *
 *
 *
 *
 *********************************************************************************************************************/


/* ==============================================================================
                    ##### LED Matrix Peripheral features #####
   ==============================================================================



  ==============================================================================
                     ##### How to use this driver #####
  ==============================================================================

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "LED_Matrix_Interface.h"


/*    ===============================================================================
              ##### Initialization and De-initialization functions #####
      =============================================================================== */

 /******************************************************************************
* \Syntax          :
* \Description     :
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : ReturnType  E_OK
*                                E_NOT_OK
*******************************************************************************/
void HLED_Matrix_Init(void)
{

	uint8_t i;


	// Call SysTick Timer
	STK_vInit();

	SPinConfig_t Pins[16] ;
	for (i=0;i<16;i++)
	{
		Pins[i].PinMode = OUTPUT_M;
		Pins[i].PinOutType = PUSH_PULL;
		Pins[i].PinOutSpeed = PINS_OUTPUT_SPEED;
	}

	// Call GPIO

	 MGPIO_vPinInit(LED_MATRIX_ROW_0, LED_MATRIX_ROWS_PORT , &Pins[0]);
	 MGPIO_vPinInit(LED_MATRIX_ROW_1, LED_MATRIX_ROWS_PORT , &Pins[1]);
	 MGPIO_vPinInit(LED_MATRIX_ROW_2, LED_MATRIX_ROWS_PORT , &Pins[2]);
	 MGPIO_vPinInit(LED_MATRIX_ROW_3, LED_MATRIX_ROWS_PORT , &Pins[3]);
	 MGPIO_vPinInit(LED_MATRIX_ROW_4, LED_MATRIX_ROWS_PORT , &Pins[4]);
	 MGPIO_vPinInit(LED_MATRIX_ROW_5, LED_MATRIX_ROWS_PORT , &Pins[5]);
	 MGPIO_vPinInit(LED_MATRIX_ROW_6, LED_MATRIX_ROWS_PORT , &Pins[6]);
	 MGPIO_vPinInit(LED_MATRIX_ROW_7, LED_MATRIX_ROWS_PORT , &Pins[7]);

	 MGPIO_vPinInit(LED_MATRIX_COLUMN_0, LED_MATRIX_COLUMNS_PORT , &Pins[8]);
	 MGPIO_vPinInit(LED_MATRIX_COLUMN_1 ,LED_MATRIX_COLUMNS_PORT , &Pins[9]);
	 MGPIO_vPinInit(LED_MATRIX_COLUMN_2, LED_MATRIX_COLUMNS_PORT , &Pins[10]);
	 MGPIO_vPinInit(LED_MATRIX_COLUMN_3, LED_MATRIX_COLUMNS_PORT , &Pins[11]);
	 MGPIO_vPinInit(LED_MATRIX_COLUMN_4, LED_MATRIX_COLUMNS_PORT , &Pins[12]);
	 MGPIO_vPinInit(LED_MATRIX_COLUMN_5, LED_MATRIX_COLUMNS_PORT , &Pins[13]);
	 MGPIO_vPinInit(LED_MATRIX_COLUMN_6, LED_MATRIX_COLUMNS_PORT , &Pins[14]);
	 MGPIO_vPinInit(LED_MATRIX_COLUMN_7, LED_MATRIX_COLUMNS_PORT , &Pins[14]);

}


/******************************************************************************
* \Syntax          :
* \Description     :
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : ReturnType  E_OK
*                                E_NOT_OK
*******************************************************************************/

void HLED_Matrix_DeInit(void)
{

}

/* ===============================================================================
                       ##### IO operation functions #####
   =============================================================================== */
void HLED_Matrix_Display(uint8_t* pARR)
{
	    uint8_t local_Counter = 0;

	    /*Enable All Columns */

	     MGPIO_vWritePin(LED_MATRIX_COLUMN_0, LED_MATRIX_COLUMNS_PORT ,PIN_LOW);
	   	 MGPIO_vWritePin(LED_MATRIX_COLUMN_1 ,LED_MATRIX_COLUMNS_PORT ,PIN_LOW);
	   	 MGPIO_vWritePin(LED_MATRIX_COLUMN_2, LED_MATRIX_COLUMNS_PORT ,PIN_LOW);
	   	 MGPIO_vWritePin(LED_MATRIX_COLUMN_3, LED_MATRIX_COLUMNS_PORT ,PIN_LOW);
	   	 MGPIO_vWritePin(LED_MATRIX_COLUMN_4, LED_MATRIX_COLUMNS_PORT ,PIN_LOW);
	   	 MGPIO_vWritePin(LED_MATRIX_COLUMN_5, LED_MATRIX_COLUMNS_PORT ,PIN_LOW);
	   	 MGPIO_vWritePin(LED_MATRIX_COLUMN_6, LED_MATRIX_COLUMNS_PORT ,PIN_LOW);
	   	 MGPIO_vWritePin(LED_MATRIX_COLUMN_7, LED_MATRIX_COLUMNS_PORT ,PIN_LOW);

		for (local_Counter=0;local_Counter<8;local_Counter++)
		{
			 MGPIO_vWritePin(LED_MATRIX_ROW_0 , LED_MATRIX_ROWS_PORT , GET_BIT(pARR[local_Counter],0));
		     MGPIO_vWritePin(LED_MATRIX_ROW_1 , LED_MATRIX_ROWS_PORT , GET_BIT(pARR[local_Counter],1));
		     MGPIO_vWritePin(LED_MATRIX_ROW_2 , LED_MATRIX_ROWS_PORT , GET_BIT(pARR[local_Counter],2));
		     MGPIO_vWritePin(LED_MATRIX_ROW_3 , LED_MATRIX_ROWS_PORT , GET_BIT(pARR[local_Counter],3));
		     MGPIO_vWritePin(LED_MATRIX_ROW_4 , LED_MATRIX_ROWS_PORT , GET_BIT(pARR[local_Counter],4));
		     MGPIO_vWritePin(LED_MATRIX_ROW_5 , LED_MATRIX_ROWS_PORT , GET_BIT(pARR[local_Counter],5));
		     MGPIO_vWritePin(LED_MATRIX_ROW_6 , LED_MATRIX_ROWS_PORT , GET_BIT(pARR[local_Counter],6));
		     MGPIO_vWritePin(LED_MATRIX_ROW_7 , LED_MATRIX_ROWS_PORT , GET_BIT(pARR[local_Counter],7));

			STK_vDelay_(_Delay_);
			CLR_Columns(local_Counter);


		}
}



/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

static void CLR_Columns(uint8_t Col_num)
{
	if(Col_num<8)
		{
		 	 MGPIO_vWritePin(Col_num, LED_MATRIX_COLUMNS_PORT ,PIN_HIGH);
		}
}

