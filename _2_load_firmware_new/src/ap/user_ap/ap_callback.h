/*
 * ap_callback.h
 *
 *  Created on: Oct 2, 2024
 *      Author: ksj10
 */

#ifndef AP_USER_AP_AP_CALLBACK_H_
#define AP_USER_AP_AP_CALLBACK_H_


#ifdef __cplusplus
extern "C" {
#endif


#if DEF_AP_CALLBACK_USE


#include "ap_def.h"


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);


#endif


#ifdef __cplusplus
}
#endif


#endif /* AP_USER_AP_AP_CALLBACK_H_ */
