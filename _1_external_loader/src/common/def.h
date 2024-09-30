/*
 * def.h
 *
 *  Created on: Sep 5, 2024
 *      Author: ksj10
 */

#ifndef COMMON_DEF_H_
#define COMMON_DEF_H_


#ifdef __cplusplus
extern "C" {
#endif


#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"


#define LE_Pin GPIO_PIN_9
#define LE_GPIO_Port GPIOA
#define CS_Pin GPIO_PIN_6
#define CS_GPIO_Port GPIOB


#ifdef __cplusplus
}
#endif

#endif /* COMMON_DEF_H_ */
