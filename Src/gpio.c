/*
 * gpio.c
 *
 *  Created on: Mar 11, 2024
 *      Author: yusuf
 */


#include "gpio.h"
static void gpio_clock_enable(GPIO_RegDef_t* pGPIOx)
{
	if(pGPIOx==GPIOA)
		GPIOA_CLCK_EN();
	else if(pGPIOx==GPIOB)
		GPIOB_CLCK_EN();
	else if(pGPIOx==GPIOC)
		GPIOC_CLCK_EN();
	else if(pGPIOx==GPIOD)
		GPIOD_CLCK_EN();
	else if(pGPIOx==GPIOE)
		GPIOE_CLCK_EN();
	else if(pGPIOx==GPIOF)
		GPIOF_CLCK_EN();
	else if(pGPIOx==GPIOG)
		GPIOG_CLCK_EN();
	else if(pGPIOx==GPIOH)
		GPIOH_CLCK_EN();
	else if(pGPIOx==GPIOI)
		GPIOI_CLCK_EN();
}

void gpioWritePin(GPIO_RegDef_t* pGPIOx, GPIO_PinNo_e pinNo, BOOL val)
{
	if(val==GPIO_PIN_SET)
	{
		pGPIOx->GPIOx_ODR |=(1<<pinNo);
	}else{
		pGPIOx->GPIOx_ODR &=~(1<<pinNo);
	}
}
void gpioWritePort(GPIO_RegDef_t* pGPIOx, uint16_t val)
{
	pGPIOx->GPIOx_ODR=val;
}

BOOL gpioReadPin(const GPIO_RegDef_t* pGPIOx, uint16_t pinNo)
{
	uint16_t val = !(!(pGPIOx->GPIOx_IDR & (1<<pinNo)));
	return val;
}

uint16_t gpioReadPort(const GPIO_RegDef_t* pGPIOx)
{
	return (uint16_t)pGPIOx->GPIOx_IDR;
}


void gpioTogglePin(GPIO_RegDef_t* pGPIOx, uint8_t pinNo)
{
	pGPIOx->GPIOx_ODR ^= (1<<pinNo);
}


void gpio_init(GPIO_Handle_t * pGpioHandle)
{
	/*
	 * which port because enable clock line
	 * mode
	 * speed
	 * pupd
	 * otype
	 * alternate mode
	 * */
	//port
	gpio_clock_enable(pGpioHandle->pGPIOx);

	//mode
	uint32_t mode=pGpioHandle->gpio_pinconfig.gpio_mode<<(2*pGpioHandle->gpio_pinconfig.gpio_pinno);
	pGpioHandle->pGPIOx->GPIOx_PUPDR |= mode;

	//speed
	uint32_t speed=pGpioHandle->gpio_pinconfig.gpio_ospeedr<<(2*pGpioHandle->gpio_pinconfig.gpio_pinno);
	pGpioHandle->pGPIOx->GPIOx_PUPDR |= speed;

	//pupd
	uint32_t pupd=pGpioHandle->gpio_pinconfig.gpio_pupdr<<(2*pGpioHandle->gpio_pinconfig.gpio_pinno);
	pGpioHandle->pGPIOx->GPIOx_PUPDR |= pupd;

	 //otype
	 uint32_t otype=pGpioHandle->gpio_pinconfig.gpio_otyper<<pGpioHandle->gpio_pinconfig.gpio_pinno;
	 pGpioHandle->pGPIOx->GPIOx_OTYPER |= otype;
}
