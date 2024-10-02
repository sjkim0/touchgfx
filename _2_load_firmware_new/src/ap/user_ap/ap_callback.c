/*
 * ap_callback.c
 *
 *  Created on: Oct 2, 2024
 *      Author: ksj10
 */


#include "ap_callback.h"
#include "ap_spi_def.h"



void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if(GPIO_Pin == GPIO_PIN_3)
    {
        if(ap_spi_inst.touch_called == false)
        {
            ap_spi_inst.touch_called = true;
        }
    }
}
