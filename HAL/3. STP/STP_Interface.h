/*
 * STP_Interface.h
 *
 *  Created on: Aug 21, 2023
 *      Author: Kareem Walid
 */

#ifndef STP_DRIVER_STP_INTERFACE_H_
#define STP_DRIVER_STP_INTERFACE_H_

#include "../RCC_Driver/RCC_Interface.h"
#include "../GPIO_Driver/GPIO_Interface.h"
#include "../SysTick_Driver/SysTick_Interface.h"

#include "STP_Config.h"





// STP Functions

void MSTP_vInit(void);
void MSTP_vDisplayData(uint8_t  Data);

#endif /* STP_DRIVER_STP_INTERFACE_H_ */
