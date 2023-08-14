#ifndef    GPIO_INTERFACE_H_
#define    GPIO_INTERFACE_H_

#include "GPIO_Private.h"
#include "Bit_Math.h"

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
}PinPullUpDown_t;




typedef  struct
{
	PINs_t  Pin;
	GPIO_PORTs_t Port;
	PinLevel_t  Level;
	PinMode_t   PinMode;
	PinOutType_t PinOutType;
	PinOutSpeed_t  PinOutSpeed;
	PinPullUpDown_t PinPullUpDown;
	
}SPinConfig_t;

void GPIO_PinConfig(SPinConfig_t *SPinConfigPoin);


#endif   /* GPIO_INTERFACE_H_ */
