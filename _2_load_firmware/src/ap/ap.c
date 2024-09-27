/*
 * ap.c
 *
 *  Created on: Sep 5, 2024
 *      Author: ksj10
 */


#include "ap.h"


void apInit(void)
{
	// apCacheInit();
	apTimInit();
	apUartInit();
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
