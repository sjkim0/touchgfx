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
	apSpiInit();
	apSdramInit();
	apUartInit();
	LCD_Init();

	MX_TouchGFX_Init();
}

void apMain(void)
{
	while(true)
	{
		MX_TouchGFX_Process();
	}
}
