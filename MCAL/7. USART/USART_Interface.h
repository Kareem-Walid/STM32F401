

/* FILE GARD */
#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../COMM/Bit_Math.h"
#include "../COMM/Platform_Types.h"
#include "../RCC_Driver/RCC_Interface.h"
#include "../GPIO_Driver/GPIO_Interface.h"
#include "USART_Private.h"
#include "USART_Config.h"


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
// TODO : Description of functions
void MUSART_vInit(void);
void MUSART_vSendData(uint8_t* DataTrans,uint8_t Copy_lenght);
void MUSART_vReciveData(uint8_t* DataRecive);



#endif  /* USART_INTERFACE_H_  */
/**********************************************************************************************************************
 *  END OF FILE: USART_Interface.h
 *********************************************************************************************************************/
