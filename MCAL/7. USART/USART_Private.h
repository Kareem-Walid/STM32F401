

/* FILE GUARD */
#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define  USART1_BASE_ADDRESS  (0x40011000)
#define  USART1        ((USART_Types_t*)USART1_BASE_ADDRESS)

/**********************************************************************************************************************
 *  GLOBAL ENUMs
 *********************************************************************************************************************/

/* 1. USART_SR BITs*/
typedef  enum {
	PE,
	FE,
	NF,
	ORE,
	IDLE,
	RXNE,
	TC,
	TXE,
	LBD,
	CTS
}USART_SR_Types_t;


/* 2. USART_CR1 BITs */
typedef  enum {

	SBK,
    RWU,
	RE,
	TE,
	IDLEIE,
	RXNEIE,
	TCIE,
	TXEIE,
	PEIE,
	PS,
	PCE,
	WAKE,
	M,
	UE,
	Reserved2,
	OVER8

}USART_CR1_Types_t;


/* 3. USART_CR2 BITs */
typedef  enum {
	LBDL = 5,
	LBDIE,
	Res,
	LBCL,
	CPHA,
	CPOL,
	CLKEN,
	STOP0,
	STOP1,
	LINEN
}USART_CR2_Types_t;

/* 4. USART_CR3 BITs */
typedef  enum {
	EIE,
	IREN,
	IRLP,
	HDSEL,
	NACK,
	SCEN,
	DMAR,
	DMAT,
	RTSE,
    CTSE,
	CTSIE,
	ONEBIT
}USART_CR3_Types_t;

/**********************************************************************************************************************
 *  GLOBAL STRUCTURES
 *********************************************************************************************************************/

typedef struct 
{
	volatile uint32_t USART_SR;
	volatile uint32_t USART_DR;
	volatile uint32_t USART_BRR;
	volatile uint32_t USART_CR1;
	volatile uint32_t USART_CR2;
	volatile uint32_t USART_CR3;
	volatile uint32_t USART_GTPR;

}USART_Types_t;


#endif  /* USART_PRIVATE_H_ */
/**********************************************************************************************************************
 *  END OF FILE: USART_Private.h
 *********************************************************************************************************************/
