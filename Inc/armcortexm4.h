/*
 * armcortexm4.h
 *
 *  Created on: Mar 25, 2024
 *      Author: yusuf
 */

#ifndef ARMCORTEXM4_H_
#define ARMCORTEXM4_H_

#include	<stdint.h>

#define		NVIC_ISER_BASEADDR		0xE000E100
#define		NVIC_ICER_BASEADDR		0xE000E180

typedef struct NVIC_ISER_RegDef_t{
	  uint32_t ISER0;
	  uint32_t ISER1;
	  uint32_t ISER2;
	  uint32_t ISER3;
	  uint32_t ISER4;
	  uint32_t ISER5;
	  uint32_t ISER6;
	  uint32_t ISER7;
}NVIC_ISER_RegDef_t;

typedef struct NVIC_ICER_RegDef_t{
	  uint32_t ICER0;
	  uint32_t ICER1;
	  uint32_t ICER2;
	  uint32_t ICER3;
	  uint32_t ICER4;
	  uint32_t ICER5;
	  uint32_t ICER6;
	  uint32_t ICER7;
}NVIC_ICER_RegDef_t;

#define		NVIC_ISER	((NVIC_ISER_RegDef_t*)NVIC_ISER_BASEADDR)
#define		NVIC_ICER	((NVIC_ICER_RegDef_t*)NVIC_ISER_BASEADDR)

void interruptEnable(uint8_t irqNo);
void interruptDisable(uint8_t irqNo);

#endif /* ARMCORTEXM4_H_ */

