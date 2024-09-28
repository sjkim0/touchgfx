/*
 * ap_tim.h
 *
 *  Created on: Sep 27, 2024
 *      Author: ksj10
 */

#ifndef AP_USER_AP_AP_TIM_H_
#define AP_USER_AP_AP_TIM_H_


#include "ap_def.h"


#if DEF_AP_TIM_USE


void apTimInit(void);
void apTimLoop(void);


#endif


#endif /* AP_USER_AP_AP_TIM_H_ */
