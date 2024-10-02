/*
 * ap_spi_def.h
 *
 *  Created on: Oct 2, 2024
 *      Author: ksj10
 */

#ifndef AP_USER_AP_AP_SPI_DEF_H_
#define AP_USER_AP_AP_SPI_DEF_H_


#ifdef __cplusplus
extern "C" {
#endif


#include "ap_def.h"


typedef struct
{
	bool touch_called;
	uint8_t read_x_tx[1];
	uint8_t read_x_rx[2];
	uint8_t read_y_tx[1];
	uint8_t read_y_rx[2];
}ap_spi_t;


extern ap_spi_t ap_spi_inst;


#ifdef __cplusplus
}
#endif


#endif /* AP_USER_AP_AP_SPI_DEF_H_ */
