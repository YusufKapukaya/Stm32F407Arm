#include "stm32f4xx.h"
#include <stdint.h>

#define		GPIO_PIN_SET			1
#define		GPIO_PIN_RESET			0

#define		GPIO_PORT_SET			0xFFFF
#define		GPIO_PORT_RESET			0x0000


#define		GPIO_MODE_INPUT			0
#define		GPIO_MODE_OUTPUT		1
#define		GPIO_MODE_ALTERNATE		2
#define		GPIO_MODE_ANALOG		3

#define		GPIO_OTYPE_PP			0
#define		GPIO_OTYPE_OD			1

#define		GPIO_OSPEEDR_LOW		0
#define		GPIO_OSPEEDR_MEDIUM		1
#define		GPIO_OSPEEDR_HIGHSPEED	2
#define		GPIO_OSPEEDR_VERYHIGH	3

#define		GPIO_PUPDR_NOPUPD		0
#define		GPIO_PUPDR_PUPD			1
#define		GPIO_PUPDR_PU			2
#define		GPIO_PUPDR_PD			3

typedef enum GPIO_PinNo_t{
	GPIO_Pin_0, GPIO_Pin_1, GPIO_Pin_2, GPIO_Pin_3, GPIO_Pin_4, GPIO_Pin_5, GPIO_Pin_6, GPIO_Pin_7,
	GPIO_Pin_8, GPIO_Pin_9, GPIO_Pin_10, GPIO_Pin_11, GPIO_Pin_12, GPIO_Pin_13, GPIO_Pin_14, GPIO_Pin_15
}GPIO_PinNo_e;

typedef enum GPIO_Leds_t{
	LED_GREEN=12,LED_ORANGE,LED_RED,LED_BLUE
}GPIO_Leds_e;

typedef struct {
	uint32_t gpio_mode;
	uint32_t gpio_otyper;
	uint32_t gpio_ospeedr;
	uint32_t gpio_pupdr;
	uint32_t gpio_alternatemode;
	uint32_t gpio_pinno;
}GPIO_PinConfig_t;

typedef struct GPIO_Handle_t{
	GPIO_RegDef_t* pGPIOx;
	GPIO_PinConfig_t gpio_pinconfig;
}GPIO_Handle_t;

void gpioWritePin(GPIO_RegDef_t* pGPIOx, GPIO_PinNo_e pinNo, BOOL val);
void gpioWritePort(GPIO_RegDef_t* pGPIOx, uint16_t val);
void gpioTogglePin(GPIO_RegDef_t* pGPIOx, uint8_t pinNo);
BOOL gpioReadPin(const GPIO_RegDef_t* pGPIOx, uint16_t pinNo);
uint16_t gpioReadPort(const GPIO_RegDef_t* pGPIOx);
void gpio_init(GPIO_Handle_t * pGpioHandle);
