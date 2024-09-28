/*
 * ap.h
 *
 *  Created on: Sep 5, 2024
 *      Author: ksj10
 */

#ifndef AP_AP_H_
#define AP_AP_H_


#include "ap_def.h"
#include "ap_uart.h"
#include "ap_switch.h"
#include "ap_cache.h"
#include "ap_tim.h"
#include "ap_sdram.h"


void apInit(void);
void apMain(void);


#endif /* AP_AP_H_ */
