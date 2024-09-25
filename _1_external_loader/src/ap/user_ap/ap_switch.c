/*
 * ap_switch.c
 *
 *  Created on: Sep 19, 2024
 *      Author: ksj10
 */


#include "ap_switch.h"


ap_switch_t switch_inst;


static bool isPushed(void);


void apSwitchInit(void)
{
	uint32_t tick = millis();

	while(true)
	{
		if(millis() - tick > 1)
		{
			if(millis() - tick > 100)
			{
				break;
			}
			if(isPushed() == true)
			{
				if(switch_inst.pushed_history > 10)
				{
					switch_inst.pushed = true;
					break;
				}
				switch_inst.pushed_history += 1;
			}
			else
			{
				switch_inst.pushed_history = 0;
			}
		}
	}
}

void apSwitchLoop(void)
{
	if(switch_inst.pushed == false)
	{
	}
}

static bool isPushed(void)
{
	if(HAL_GPIO_ReadPin(GPIOH, GPIO_PIN_4) == GPIO_PIN_RESET)
	{
		return true;
	}

	return false;
}
