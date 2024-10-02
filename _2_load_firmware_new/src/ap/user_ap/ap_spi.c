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
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_SET);
	ap_spi_inst.read_x_tx[0] = 0x93;  //  read xp, power always on
	ap_spi_inst.read_y_tx[0] = 0xD3;  //  read xp, power always on
}

void apSpiLoop(void)
{
	if(ap_spi_inst.touch_called == true)
	{
	    HAL_NVIC_DisableIRQ(EXTI3_IRQn);
	    _apSpiReadX();
	    _apSpiReadY();
        ap_spi_inst.touch_called = false;
	    HAL_NVIC_EnableIRQ(EXTI3_IRQn);
	}
}


/*@ brief _apSpiReadX
 *  Send 8bit
 *  Receive 12bit
 */
static void _apSpiReadX(void)
{
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi4, ap_spi_inst.read_x_tx, 1, 0xFF);
    HAL_SPI_Receive(&hspi4, ap_spi_inst.read_x_rx, 2, 0xFF);
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_SET);
}

static void _apSpiReadY(void)
{
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi4, ap_spi_inst.read_y_tx, 1, 0xFF);
    HAL_SPI_Receive(&hspi4, ap_spi_inst.read_y_rx, 2, 0xFF);
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_SET);
}



void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    ap_spi_inst.touch_calling = true;
    if(ap_spi_inst.touch_called == false)
    {
        ap_spi_inst.touch_called = true;
    }
}
