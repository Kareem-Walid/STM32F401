/*
 * Status_Types.h
 *
 *  Created on: Sep 5, 2023
 *      Author: Kareem Walid
 */

#ifndef COMM_STATUS_TYPES_H_
#define COMM_STATUS_TYPES_H_


#define NULL  ((void * )0)


typedef   enum{

	H_OK      = 0x0U,
	H_ERROR   = 0x1U,
	H_BUSY    = 0x2U,
	H_TIMEOUT = 0x3U,

}Status_Types_t;


typedef enum{
	H_RESET = 0,
	H_SET = 1
}Bit_Status_t;

#endif /* COMM_STATUS_TYPES_H_ */
