/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef   RCC_INTERFACE_H_
#define   RCC_INTERFACE_H_

#include "BIT_MATH.h"
#include "RCC_Private.h"
#include "RCC_Config.h"



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void  RCC_vInitSysClk(void);
void  RCC_vEnablePeripheral(uint8_t Copy_uint8_t_BusID,uint8_t Copy_PeripheralID);
void  RCC_vDisablePeripheral(uint8_t Copy_uint8_t_BusID, uint8_t Copy_PeripheralID );

 
#endif  /* RCC_INTERFACE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/