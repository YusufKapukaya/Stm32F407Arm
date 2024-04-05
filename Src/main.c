

#include <stdint.h>
#include <stdlib.h>
#include "gpio.h"
#include "armcortexm4.h"

#define 	GPIO_ARRAY_SIZE		4
#define 	BUTTON_ARRAY_SIZE	4
#define		NO_ALTERNATE_FUNC	0
	int counter;
#define		TURN_ON				1
#define		TURN_OFF			0
int main(void)
{
	/*
	 * RCC->AHB1ENR |=(1U<<2);			//Clock enabled of GPIOC
	RCC->AHB1ENR |=(1U<<3);			//Clock enabled of GPIOD



	//for GPIOC
	GPIOC->GPIOx_MODER &=~(1U<<10);		//MODER 5 INPUT 00
	GPIOC->GPIOx_MODER &=~(1U<<11);

	GPIOC->GPIOx_MODER &=~(1U<<12);		//MODER 6 INPUT 00
	GPIOC->GPIOx_MODER &=~(1U<<13);

	GPIOC->GPIOx_MODER &=~(1U<<14);		//MODER 7 INPUT 00
	GPIOC->GPIOx_MODER &=~(1U<<15);

	GPIOC->GPIOx_MODER &=~(1U<<16);		//MODER 8 INPUT 00
	GPIOC->GPIOx_MODER &=~(1U<<17);


	//for GPIOD OUTPUT

	GPIOD->GPIOx_MODER &=~(1U<<25);		//MODER 12 OUTPUT 01
	GPIOD->GPIOx_MODER |=(1U<<24);

	GPIOD->GPIOx_MODER &=~(1U<<27);		//MODER 13 OUTPUT 01
	GPIOD->GPIOx_MODER |=(1U<<26);

	GPIOD->GPIOx_MODER &=~(1U<<29);		//MODER 14 OUTPUT 01
	GPIOD->GPIOx_MODER |=(1U<<28);

	GPIOD->GPIOx_MODER &=~(1U<<31);		//MODER 15 OUTPUT 01
	GPIOD->GPIOx_MODER |=(1U<<30);

	 (RCC->APB2ENR |=(1U<<14))			//Clock enabled of SYSCFG
	 *
	 *
	 */

	//for GPIOC iNPUT
	/*GPIO_Handle_t button5={GPIOC,{GPIO_MODE_INPUT,GPIO_OTYPE_PP,GPIO_OSPEEDR_MEDIUM,GPIO_PUPDR_NOPUPD,NO_ALTERNATE_FUNC,GPIO_Pin_5}};
	GPIO_Handle_t button6={GPIOC,{GPIO_MODE_INPUT,GPIO_OTYPE_PP,GPIO_OSPEEDR_MEDIUM,GPIO_PUPDR_NOPUPD,NO_ALTERNATE_FUNC,GPIO_Pin_6}};
	GPIO_Handle_t button7={GPIOC,{GPIO_MODE_INPUT,GPIO_OTYPE_PP,GPIO_OSPEEDR_MEDIUM,GPIO_PUPDR_NOPUPD,NO_ALTERNATE_FUNC,GPIO_Pin_7}};
	GPIO_Handle_t button8={GPIOC,{GPIO_MODE_INPUT,GPIO_OTYPE_PP,GPIO_OSPEEDR_MEDIUM,GPIO_PUPDR_NOPUPD,NO_ALTERNATE_FUNC,GPIO_Pin_8}};

	GPIO_Handle_t *pButtonArry[BUTTON_ARRAY_SIZE]={&button5,&button6,&button7,&button8};

	for(int i=0;i<BUTTON_ARRAY_SIZE;i++)
	gpio_init(pButtonArry[i]);

	GPIO_Handle_t op_green={GPIOD,{GPIO_MODE_OUTPUT,GPIO_OTYPE_PP,GPIO_OSPEEDR_MEDIUM,GPIO_PUPDR_NOPUPD,NO_ALTERNATE_FUNC,LED_GREEN}};
	GPIO_Handle_t op_orange={GPIOD,{GPIO_MODE_OUTPUT,GPIO_OTYPE_PP,GPIO_OSPEEDR_MEDIUM,GPIO_PUPDR_NOPUPD,NO_ALTERNATE_FUNC,LED_ORANGE}};
	GPIO_Handle_t op_red={GPIOD,{GPIO_MODE_OUTPUT,GPIO_OTYPE_PP,GPIO_OSPEEDR_MEDIUM,GPIO_PUPDR_NOPUPD,NO_ALTERNATE_FUNC,LED_RED}};
	GPIO_Handle_t op_blue={GPIOD,{GPIO_MODE_OUTPUT,GPIO_OTYPE_PP,GPIO_OSPEEDR_MEDIUM,GPIO_PUPDR_NOPUPD,NO_ALTERNATE_FUNC,LED_BLUE}};

	GPIO_Handle_t *pLedArry[GPIO_ARRAY_SIZE]={&op_green,&op_orange,&op_red,&op_blue};
	for(int i=0;i<GPIO_ARRAY_SIZE;i++)
		gpio_init(pLedArry[i]);
	*/
	counter=0;
	RCC->AHB1ENR |=(1U<<2);			//Clock enabled of GPIOC
	RCC->AHB1ENR |=(1U<<3);			//Clock enabled of GPIOD
	GPIOC->GPIOx_MODER &=~(1U<<10);		//MODER 5 INPUT 00
	GPIOC->GPIOx_MODER &=~(1U<<11);

	GPIOC->GPIOx_MODER &=~(1U<<12);		//MODER 6 INPUT 00
	GPIOC->GPIOx_MODER &=~(1U<<13);

	GPIOC->GPIOx_MODER &=~(1U<<14);		//MODER 7 INPUT 00
	GPIOC->GPIOx_MODER &=~(1U<<15);

	GPIOC->GPIOx_MODER &=~(1U<<16);		//MODER 8 INPUT 00
	GPIOC->GPIOx_MODER &=~(1U<<17);
	//for GPIOD OUTPUT
	/*
	 */
	GPIOD->GPIOx_MODER &=~(1U<<25);		//MODER 12 OUTPUT 01
	GPIOD->GPIOx_MODER |=(1U<<24);

	GPIOD->GPIOx_MODER &=~(1U<<27);		//MODER 13 OUTPUT 01
	GPIOD->GPIOx_MODER |=(1U<<26);

	GPIOD->GPIOx_MODER &=~(1U<<29);		//MODER 14 OUTPUT 01
	GPIOD->GPIOx_MODER |=(1U<<28);

	GPIOD->GPIOx_MODER &=~(1U<<31);		//MODER 15 OUTPUT 01
	GPIOD->GPIOx_MODER |=(1U<<30);
	RCC->APB2ENR |=(1U<<14);				//Clock enabled of SYSCFG

	//EXTI 5 port C Interrupt
	SYSCFG->EXTICR[1]&=~(1<<4);
	SYSCFG->EXTICR[1]|=(1<<5);
	SYSCFG->EXTICR[1]&=~(1<<6);
	SYSCFG->EXTICR[1]&=~(1<<7);

	EXTI->RTSR |=(1U<<5);
	EXTI->IMR |=(1U<<5);

	//EXTI 6 port C Interrupt
	SYSCFG->EXTICR[1]&=~(1<<8);
	SYSCFG->EXTICR[1]|=(1<<9);
	SYSCFG->EXTICR[1]&=~(1<<10);
	SYSCFG->EXTICR[1]&=~(1<<11);

	EXTI->RTSR |=(1U<<6);
	EXTI->IMR |=(1U<<6);

	//EXTI 7 port C Interrupt
	SYSCFG->EXTICR[1]&=~(1<<12);
	SYSCFG->EXTICR[1]|=(1<<13);
	SYSCFG->EXTICR[1]&=~(1<<14);
	SYSCFG->EXTICR[1]&=~(1<<15);

	EXTI->RTSR |=(1U<<7);
	EXTI->IMR |=(1U<<7);

	//EXTI 8 port C Interrupt
	SYSCFG->EXTICR[2]&=~(1<<0);
	SYSCFG->EXTICR[2]|=(1<<1);
	SYSCFG->EXTICR[2]&=~(1<<2);
	SYSCFG->EXTICR[2]&=~(1<<3);

	EXTI->RTSR |=(1U<<8);
	EXTI->IMR |=(1U<<8);

	//23 IRQ Number	 30 settable EXTI9_5
	NVIC_ISER->ISER0 |=(1U<<23);

  	while(1)
	{
  		;
	}
}


void EXTI9_5_IRQHandler ()
{

	if(EXTI->PR & (1U<<5)){
    	if(counter%2){
    	gpioWritePin(GPIOD,LED_GREEN,TURN_ON);
    	gpioWritePin(GPIOD,LED_ORANGE,TURN_OFF);
     	 //GPIOD->GPIOx_ODR |=(1U<<12);
     	 //GPIOD->GPIOx_ODR &=~(1U<<13);
    	}
    	else{
       	gpioWritePin(GPIOD,LED_GREEN,TURN_OFF);
       	gpioWritePin(GPIOD,LED_ORANGE,TURN_ON);
    	 //GPIOD->GPIOx_ODR |=(1U<<13);
    	 //GPIOD->GPIOx_ODR &=~(1U<<12);
    	}
    	EXTI->PR |= (1U<<5);
    	counter++;
	}else if(EXTI->PR & (1U<<6)){
    	if(counter%2){
        gpioWritePin(GPIOD,LED_RED,TURN_ON);
        gpioWritePin(GPIOD,LED_BLUE,TURN_OFF);
     	 //GPIOD->GPIOx_ODR |=(1U<<14);
     	 //GPIOD->GPIOx_ODR &=~(1U<<15);
    	}
    	else{
    	gpioWritePin(GPIOD,LED_RED,TURN_OFF);
    	gpioWritePin(GPIOD,LED_BLUE,TURN_ON);
    	 //GPIOD->GPIOx_ODR |=(1U<<15);
    	 //GPIOD->GPIOx_ODR &=~(1U<<14);
    	}
    	EXTI->PR |= (1U<<6);

	}else if(EXTI->PR & (1U<<7)){
    	if(counter%2){
        gpioWritePin(GPIOD,LED_GREEN,TURN_OFF);
    	}
    	else{
    	gpioWritePin(GPIOD,LED_ORANGE,TURN_OFF);
    	}
    	EXTI->PR |= (1U<<7);
	}else if(EXTI->PR & (1U<<8)){
    	if(counter%2){
    	gpioWritePin(GPIOD,LED_RED,TURN_OFF);
    	}
    	else{
    	gpioWritePin(GPIOD,LED_BLUE,TURN_OFF);
    	}
    	EXTI->PR |= (1U<<8);
	}

}

void EXTI0_IRQHandler(){

	if(EXTI->PR &(1U<<0))
	{
		gpioTogglePin(GPIOD,LED_BLUE);
		EXTI->PR |=(1U<<0);
	}
}

