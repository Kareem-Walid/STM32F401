/**********************************************************************************************************************
 *  FILE INFORMATION
 *  -----------------------------------------------------------------------------------------------------------------
 *        FILE NAME :  LED_Mtrix_Config.h
 *        FILE DATE :
 *        VERSION:   V1.0
 *        AUTHOR:   KAREEM WALID
 *        BRIEF EXPLANATION:
 *
 *********************************************************************************************************************/
 /* FILE GUARD */
#ifndef LED_MATRIX_CONFIG_H_
#define LED_MATRIX_CONFIG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define _Delay_  10000


#define PINS_OUTPUT_SPEED       Very_High_Speed



#define LED_MATRIX_ROWS_PORT     GPIOB
#define LED_MATRIX_ROW_0         PIN0
#define LED_MATRIX_ROW_1         PIN1
#define LED_MATRIX_ROW_2         PIN2
#define LED_MATRIX_ROW_3         PIN3
#define LED_MATRIX_ROW_4         PIN4
#define LED_MATRIX_ROW_5         PIN5
#define LED_MATRIX_ROW_6         PIN6
#define LED_MATRIX_ROW_7         PIN7

#define LED_MATRIX_COLUMNS_PORT       GPIOA
#define LED_MATRIX_COLUMN_0         PIN0
#define LED_MATRIX_COLUMN_1         PIN1
#define LED_MATRIX_COLUMN_2         PIN2
#define LED_MATRIX_COLUMN_3         PIN3
#define LED_MATRIX_COLUMN_4         PIN4
#define LED_MATRIX_COLUMN_5         PIN5
#define LED_MATRIX_COLUMN_6         PIN6
#define LED_MATRIX_COLUMN_7         PIN7




#endif /* LED_MATRIX_CONFIG_H_ */
/**********************************************************************************************************************
 *  END OF FILE: LED_Matrix_Config.h
 *********************************************************************************************************************/
