/*
 * ap_tim.c
 *
 *  Created on: Sep 27, 2024
 *      Author: ksj10
 */


#include "ap_tim.h"


#if DEF_AP_TIM_USE


void apTimInit(void)
{
	HAL_TIM_Base_Init(&htim6);
	HAL_TIM_Base_Start(&htim6);
}

void apTimLoop(void)
{

}


#endif
