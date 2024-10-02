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
	    int a = 0;
	    if(a == 2)
	    {
	        break;
	    }
	}
	MX_TouchGFX_Init();
}

void apMain(void)
{
	while(true)
	{
		MX_TouchGFX_Process();
	}
}
