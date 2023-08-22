/*
 * DAC_Interface.h
 *
 *  Created on: Aug 21, 2023
 *      Author: Kareem Walid
 */

#ifndef DAC_DRIVER_DAC_INTERFACE_H_
#define DAC_DRIVER_DAC_INTERFACE_H_

#include "../GPIO_Driver/GPIO_Interface.h"
#include "../SysTick_Driver/SysTick_Interface.h"
#include "song.h"
#include "DAC_Config.h"





// Function
void MDAC_vInit(void);
void MDAC_vPlay(void);

#endif /* DAC_DRIVER_DAC_INTERFACE_H_ */
