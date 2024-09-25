/*
 * ap.c
 *
 *  Created on: Sep 5, 2024
 *      Author: ksj10
 */


#include "ap.h"


typedef struct
{
	uint8_t abc;
	uint32_t bca;
	char str[4];
	float gg;
}STR;

STR _str, _str2;


void apInit(void)
{
}

void apMain(void)
{
	while(true)
	{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
		delay(100);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
		delay(100);
	}
}
