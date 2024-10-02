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


#define DEF_TOUCH_COUNT_MAX  (5U)
#define DEF_READ_INTERVAL_MS (20U)


typedef struct
{
    uint32_t test_count;
    uint32_t isr_enable_tick;
	bool touch_called;
	bool touch_calculating;
    bool touch_calculate_done;
	int touch_count; // touch count max -> DEF_TOUCH_COUNT_MAX
    bool touch_calling;
	uint8_t read_x_tx[1];
	uint8_t read_x_rx[DEF_TOUCH_COUNT_MAX][2];
	uint8_t read_y_tx[1];
	uint8_t read_y_rx[DEF_TOUCH_COUNT_MAX][2];
}ap_spi_t;


extern ap_spi_t ap_spi_inst;


#ifdef __cplusplus
}
#endif


#endif /* AP_USER_AP_AP_SPI_DEF_H_ */
