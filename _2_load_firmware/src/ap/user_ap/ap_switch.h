/*
 * ap_switch.h
 *
 *  Created on: Sep 19, 2024
 *      Author: ksj10
 */

#ifndef AP_USER_AP_AP_SWITCH_H_
#define AP_USER_AP_AP_SWITCH_H_


#include "ap_def.h"


typedef struct
{
	int pushed_history;
	bool pushed;
}ap_switch_t;


extern ap_switch_t switch_inst;


void apSwitchInit(void);
void apSwitchLoop(void);


#endif /* AP_USER_AP_AP_SWITCH_H_ */
