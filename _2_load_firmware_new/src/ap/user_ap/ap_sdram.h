/*
 * ap_sdram.h
 *
 *  Created on: Sep 28, 2024
 *      Author: ksj10
 */

#ifndef AP_USER_AP_AP_SDRAM_H_
#define AP_USER_AP_AP_SDRAM_H_


#ifdef __cplusplus
extern "C" {
#endif


#include "ap_def.h"


#if DEF_AP_SDRAM_USE


void apSdramInit(void);
void apSdramLoop(void);


#endif


#ifdef __cplusplus
}
#endif


#endif /* AP_USER_AP_AP_SDRAM_H_ */
