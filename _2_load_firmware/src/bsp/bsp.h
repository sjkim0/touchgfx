/*
 * bsp.h
 *
 *  Created on: Sep 5, 2024
 *      Author: ksj10
 */

#ifndef BSP_BSP_H_
#define BSP_BSP_H_


#include "stm32h7xx_hal.h"


void bspInit(void);
void delay(uint32_t tick);
void delayWhile(uint32_t tick);
uint32_t millis(void);

void Error_Handler(void);


#endif /* BSP_BSP_H_ */
