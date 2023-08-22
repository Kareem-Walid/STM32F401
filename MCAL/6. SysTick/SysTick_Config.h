/*
 * SysTick_Config.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Kareem Walid
 */

#ifndef SYSTICK_DRIVER_SYSTICK_CONFIG_H_
#define SYSTICK_DRIVER_SYSTICK_CONFIG_H_

/*
 * OPTION_1 == AHB/8
 * OPTION_2 == AHB
 */
#define CLOCK_AHB_DIV_1   0U
#define CLOCK_AHB_DIV_8   1U

#define     STK_CLOCK_SOURCE        CLOCK_AHB_DIV_1





#endif /* SYSTICK_DRIVER_SYSTICK_CONFIG_H_ */
