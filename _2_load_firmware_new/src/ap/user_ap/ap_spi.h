/*
 * ap_spi.h
 *
 *  Created on: Oct 2, 2024
 *      Author: ksj10
 */

#ifndef AP_USER_AP_AP_SPI_H_
#define AP_USER_AP_AP_SPI_H_


#ifdef __cplusplus
extern "C" {
#endif


#include "ap_def.h"


#if DEF_AP_SPI_USE


void apSpiInit(void);
void apSpiLoop(void);


#endif


#ifdef __cplusplus
}
#endif


#endif /* AP_USER_AP_AP_SPI_H_ */
