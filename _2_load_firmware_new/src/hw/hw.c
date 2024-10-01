/*
 * hw.c
 *
 *  Created on: Sep 5, 2024
 *      Author: ksj10
 */


#include "hw.h"


void hwInit(void)
{
    SCB->VTOR = 0x90000000;
	bspInit();

	MX_GPIO_Init();
	MX_DMA_Init();
	MX_USART1_UART_Init();
	MX_TIM6_Init();
	MX_FMC_Init();
    MX_DMA2D_Init();
    MX_LTDC_Init();
    MX_TIM16_Init();
    MX_CRC_Init();
}
