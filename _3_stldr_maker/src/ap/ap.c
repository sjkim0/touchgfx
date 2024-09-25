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
//	apSwitchInit();
//	apQspiInit();
	apCustomLoaderInit();
}

void apMain(void)
{
	while(true)
	{
	}
}
