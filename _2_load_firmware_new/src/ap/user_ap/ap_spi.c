/*
 * ap_spi.c
 *
 *  Created on: Oct 2, 2024
 *      Author: ksj10
 */


#include "ap_spi.h"
#include "ap_spi_def.h"


ap_spi_t ap_spi_inst;


static void _apSpiReadX(void);
static void _apSpiReadY(void);


void apSpiInit(void)
{
	ap_spi_inst.read_x_tx[0] = 0x93;  //  read xp, power always on
	ap_spi_inst.read_y_tx[0] = 0xD3;  //  read xp, power always on
}

void apSpiLoop(void)
{
	if(ap_spi_inst.touch_called == true)
	{

	}
}


/*@ brief _apSpiReadX
 *  Send 8bit
 *  Receive 12bit
 */
static void _apSpiReadX(void)
{
	HAL_SPI_Transmit(&hspi4, ap_spi_inst.read_x_tx, 1, 0xFF);
}

static void _apSpiReadY(void)
{

}
