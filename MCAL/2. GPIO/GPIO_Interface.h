#ifndef    GPIO_INTERFACE_H_
#define    GPIO_INTERFACE_H_

#include "../COMM/Bit_Math.h"
#include "../COMM/Platform_Types.h"
#include "GPIO_Private.h"


typedef enum{
	GPIO_PA,
	GPIO_PB,
	GPIO_PC,
	GPIO_PD,
	GPIO_PE,
	GPIO_PH

}GPIO_PORTs_t;

typedef enum{
	PIN_LOW,
	PIN_HIGH
}PinLevel_t;

typedef enum {
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
}PINs_t;


typedef  enum{
	INPUT_M,
	OUTPUT_M,
	ALTERNATIVE_M,
	ANALOG_M,
}PinMode_t;


typedef enum 
{
	PUSH_PULL,
	OPEN_DRAIN
}PinOutType_t;


typedef enum {
	Low_Speed,
    Medium_Speed,
    High_Speed,
    Very_High_Speed
}PinOutSpeed_t;


typedef enum {
	No_pull_up_Down,
    Pull_up,
    Pull_down,
    Reserved
}PinInputType_t;


typedef enum{
	AF00,
	AF01,
	AF02,
	AF03,
	AF04,
	AF05,
	AF06,
	AF07,
	AF08,
	AF09,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15
}Alternative_Types_t;

typedef  struct
{
	PINs_t  Pin;
	GPIO_PORTs_t Port;
	PinMode_t  PinMode;
	PinLevel_t  Level;
	PinOutType_t PinOutType;
	PinOutSpeed_t  PinOutSpeed;
	PinInputType_t PinInputType;
	Alternative_Types_t ALT_FUN;
	
}SPinConfig_t;

void GPIO_PinConfig(SPinConfig_t *SPinConfigPoin);


#endif   /* GPIO_INTERFACE_H_ */
