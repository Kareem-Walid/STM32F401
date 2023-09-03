/**********************************************************************************************************************

 *  FILE DECLR_TWO_BITSCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  BIT_MATH.H
 *         Module:  -
 *         Description:  <Write File DESCRIPTION here>
 * 
 *********************************************************************************************************************/
#ifndef BIT_MATH_H_
#define BIT_MATH_H_


/* One Bit Masking */
#define SET_BIT(REG,BIT)    (REG |= (1UL<<BIT))
#define CLR_BIT(REG,BIT)    (REG &= (~(1UL<<BIT)))
#define TOG_BIT(REG,BIT)    (REG ^= (1UL<<BIT))
#define GET_BIT(REG,BIT)    ((REG&(1UL<<BIT))>>BIT)

/* Two Bits Masking */
/*
#define LOAD_TWO_BIT(REG,FIRST_BIT,TWO_DIGIT)     (REG |=  (TWO_DIGIT<< FIRST_BIT % 8 )*4)
#define CLR_TWO_BIT(REG,FIRST_BIT)                (REG &=~ (0b11<< FIRST_BIT % 8 )*4)
*/

#endif  /* BIT_MATH_H_ */
/**********************************************************************************************************************
 *  END OF FILE: Bit_Math.h
 *********************************************************************************************************************/
