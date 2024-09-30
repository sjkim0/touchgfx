/*
 * ap.h
 *
 *  Created on: Sep 5, 2024
 *      Author: ksj10
 */

#ifndef AP_AP_H_
#define AP_AP_H_


#ifdef __cplusplus
extern "C" {
#endif


#include "ap_def.h"
#include "ap_uart.h"
#include "ap_qspi.h"
#include "ap_switch.h"
#include "ap_custom_loader.h"


void apInit(void);
void apMain(void);


#ifdef __cplusplus
}
#endif


#endif /* AP_AP_H_ */
