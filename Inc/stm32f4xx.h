#include 	<stdint.h>


#define		BOOL	uint8_t

/*Base addresses of Busses*/
#define		APB1_BASEADDR			0x40000000
#define		APB2_BASEADDR			0x40010000
#define		AHB1_BASEADDR			0x40020000
#define		AHB2_BASEADDR			0x50050000
#define		AHB3_BASEADDR			0x60000000


/* Base addresses of peripherals which contains in the APB1 Bus */
#define		TIM2_BASEADDR							APB1_BASEADDR
#define		TIM3_BASEADDR							(APB1_BASEADDR+0x400)
#define		TIM4_BASEADDR							(APB1_BASEADDR+0x800)
#define		TIM5_BASEADDR							(APB1_BASEADDR+0xC00)
#define		TIM6_BASEADDR							(APB1_BASEADDR+0x1000)
#define		TIM7_BASEADDR							(APB1_BASEADDR+0x1400)
#define		TIM12_BASEADDR							(APB1_BASEADDR+0x1800)
#define		TIM13_BASEADDR							(APB1_BASEADDR+0x1C00)
#define		TIM14_BASEADDR							(APB1_BASEADDR+0x2000)
#define		RTC_BKPRegisters_BASEADDR				(APB1_BASEADDR+0x2800)
#define		WWDG_BASEADDR							(APB1_BASEADDR+0x2C00)
#define		IWDG_BASEADDR							(APB1_BASEADDR+0x3000)
#define		I2S2ext_BASEADDR						(APB1_BASEADDR+0x3400)
#define		SPI2_I2S2_BASEADDR						(APB1_BASEADDR+0x3800)
#define		SPI3_I2S3_BASEADDR						(APB1_BASEADDR+0x3C00)
#define		I2S3ext_BASEADDR						(APB1_BASEADDR+0x4000)
#define		USART2_BASEADDR							(APB1_BASEADDR+0x4400)
#define		USART3_BASEADDR							(APB1_BASEADDR+0x4800)
#define		UART4_BASEADDR							(APB1_BASEADDR+0x4C00)
#define		UART5_BASEADDR							(APB1_BASEADDR+0x5000)
#define		I2C1_BASEADDR							(APB1_BASEADDR+0x5400)
#define		I2C2_BASEADDR							(APB1_BASEADDR+0x5800)
#define		I2C3_BASEADDR							(APB1_BASEADDR+0x5C00)
#define		CAN1_BASEADDR							(APB1_BASEADDR+0x6400)
#define		CAN2_BASEADDR							(APB1_BASEADDR+0x6800)
#define		PWR_BASEADDR							(APB1_BASEADDR+0x7000)
#define		DAC_BASEADDR							(APB1_BASEADDR+0x7400)


/* Base addresses of peripherals which contains in the APB2 Bus */
#define		TIM1_BASEADDR							APB2_BASEADDR
#define		TIM8_BASEADDR							(APB2_BASEADDR+0x400)
#define		USART1_BASEADDR							(APB2_BASEADDR+0x1000)
#define		USART6_BASEADDR							(APB2_BASEADDR+0x1400)
#define		ADC1_ADC2_ADC3_BASEADDR					(APB2_BASEADDR+0x2000)
#define		SDIO_BASEADDR							(APB2_BASEADDR+0x2C00)
#define		SPI1_BASEADDR							(APB2_BASEADDR+0x3000)
#define		SYSCFG_BASEADDR							(APB2_BASEADDR+0x3800)
#define		EXTI_BASEADDR							(APB2_BASEADDR+0x3C00)
#define		TIM9_BASEADDR							(APB2_BASEADDR+0x4000)
#define		TIM10_BASEADDR							(APB2_BASEADDR+0x4400)
#define		TIM11_BASEADDR							(APB2_BASEADDR+0x4800)


/* Base addresses of peripherals which contains in the AHB1 Bus */
#define		GPIOA_BASEADDR						AHB1_BASEADDR
#define		GPIOB_BASEADDR						(AHB1_BASEADDR+0x400)
#define		GPIOC_BASEADDR						(AHB1_BASEADDR+0x800)
#define		GPIOD_BASEADDR						(AHB1_BASEADDR+0xC00)
#define		GPIOE_BASEADDR						(AHB1_BASEADDR+0x1000)
#define		GPIOF_BASEADDR						(AHB1_BASEADDR+0x1400)
#define		GPIOG_BASEADDR						(AHB1_BASEADDR+0x1800)
#define		GPIOH_BASEADDR						(AHB1_BASEADDR+0x1C00)
#define		GPIOI_BASEADDR						(AHB1_BASEADDR+0x2000)
#define		CRC_BASEADDR						(AHB1_BASEADDR+0x3000)
#define		RCC_BASEADDR						(AHB1_BASEADDR+0x3800)
#define		FLASH_INTERFACE_REG_BASEADDR		(AHB1_BASEADDR+0x3C00)
#define		BKPSRAM_BASEADDR					(AHB1_BASEADDR+0x4000)
#define		DMA1_BASEADDR						(AHB1_BASEADDR+0x6000)
#define		DMA2_BASEADDR						(AHB1_BASEADDR+0x6400)
#define		ETHERNET_MAC_BASEADDR				(AHB1_BASEADDR+0x8000)
#define		USB_OTG_HS_BASEADDR					(AHB1_BASEADDR+0x20000)
#define		USB_OTG_FS_BASEADDR					(AHB1_BASEADDR+0xFFE0000)


/* Base addresses of peripherals which contains in the AHB2 Bus */


#define		DCMI_BASEADDR						AHB2_BASEADDR
#define		RNG_BASEADDR						(AHB2_BASEADDR+0x10800)

/* Base addresses of peripherals which contains in the AHB3 Bus */


#define		FSMC_bank_1_BASEADDR						AHB3_BASEADDR
#define		FSMC_bank_2_BASEADDR						(AHB3_BASEADDR+0x10000000)
#define		FSMC_bank_3_BASEADDR						(AHB3_BASEADDR+0x20000000)
#define		FSMC_bank_4_BASEADDR						(AHB3_BASEADDR+0x30000000)
#define		FSMC_CONTROL_REG_BASEADDR					(AHB3_BASEADDR+0x40000000)


typedef struct GPIO_RegDef_t{
	volatile uint32_t GPIOx_MODER;
	volatile uint32_t GPIOx_OTYPER;
	volatile uint32_t GPIOx_OSPEEDR;
	volatile uint32_t GPIOx_PUPDR;
	volatile uint32_t GPIOx_IDR;
	volatile uint32_t GPIOx_ODR;
	volatile uint32_t GPIOx_BSRR;
	volatile uint32_t GPIOx_LCKR;
	volatile uint32_t GPIOx_AFR[2];
}GPIO_RegDef_t;


typedef struct RCC_RegDef_t{
	volatile uint32_t CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR;
	volatile uint32_t AHB3RSTR;
	volatile uint32_t RESERVE;
	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t RESERVE2[2];
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
	volatile uint32_t AHB3ENR;
	volatile uint32_t RESERVE3;
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t RESERVE4[2];
	volatile uint32_t AHB1LPENR;
	volatile uint32_t AHB2LPENR;
	volatile uint32_t AHB3LPENR;
	volatile uint32_t RESERVE5;
	volatile uint32_t APB1LPENR;
	volatile uint32_t APB2LPENR;
	volatile uint32_t RESERVE6[2];
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t RESERVE7[2];
	volatile uint32_t SSCGR;
	volatile uint32_t PLLI2SCFGR;
}RCC_RegDef_t;

typedef struct SYSCFG_RegDef_t{
	volatile uint32_t MEMRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR[4];
	volatile uint32_t CMPCR;
}SYSCFG_RegDef_t;

typedef struct EXTI_RegDef_t{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_RegDef_t;

#define		SYSCFG					((SYSCFG_RegDef_t*)SYSCFG_BASEADDR	)
#define 	EXTI					((EXTI_RegDef_t*)EXTI_BASEADDR)
#define 	RCC						((RCC_RegDef_t*)RCC_BASEADDR)

#define		GPIOA					((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define		GPIOB					((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define		GPIOC					((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define		GPIOD					((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define		GPIOE					((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define		GPIOF					((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define		GPIOG					((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define		GPIOH					((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define		GPIOI					((GPIO_RegDef_t*)GPIOI_BASEADDR)


#define		GPIOA_CLCK_EN()			(RCC->AHB1ENR |=(1<<0))
#define		GPIOB_CLCK_EN()			(RCC->AHB1ENR |=(1<<1))
#define		GPIOC_CLCK_EN()			(RCC->AHB1ENR |=(1<<2))
#define		GPIOD_CLCK_EN()			(RCC->AHB1ENR |=(1<<3))
#define		GPIOE_CLCK_EN()			(RCC->AHB1ENR |=(1<<4))
#define		GPIOF_CLCK_EN()			(RCC->AHB1ENR |=(1<<5))
#define		GPIOG_CLCK_EN()			(RCC->AHB1ENR |=(1<<6))
#define		GPIOH_CLCK_EN()			(RCC->AHB1ENR |=(1<<7))
#define		GPIOI_CLCK_EN()			(RCC->AHB1ENR |=(1<<8))



