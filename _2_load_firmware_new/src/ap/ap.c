/*
 * ap.c
 *
 *  Created on: Sep 5, 2024
 *      Author: ksj10
 */


#include "ap.h"


void apInit(void)
{
//	apCacheInit();
//	apTimInit();
	apSdramInit();
	apUartInit();
	LCD_Init();

	while(true)
	{

	}
//	MX_TouchGFX_Init();
//	while (1)
//	{
//		MX_TouchGFX_Process();
//	}
}

void apMain(void)
{
	while(true)
	{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
		delay(100);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
		delay(100);

		apUartLoop();
	}
}
