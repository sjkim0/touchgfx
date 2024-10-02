/*
 * ap_spi.c
 *
 *  Created on: Oct 2, 2024
 *      Author: ksj10
 */


#include "ap_spi.h"
#include "ap_spi_def.h"


#if DEF_AP_SPI_USE


ap_spi_t ap_spi_inst;


static void _apSpiReadX(void);
static void _apSpiReadY(void);
static void _apReadyReadTouch(void);
static void _apCalulateTouch(void);
static void _apTouchISREnable(void);


void apSpiInit(void)
{
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_SET);
    delayWhile(10);
	ap_spi_inst.read_x_tx[0] = 0x90;  //  read xp, power always on
	ap_spi_inst.read_y_tx[0] = 0xD0;  //  read xp, power always on
}

void apSpiLoop(void)
{
    _apReadyReadTouch();
    _apCalulateTouch();
    _apTouchISREnable();
}

/*@ brief _apSpiReadX
 *  Send 8bit
 *  Receive 12bit
 */
static void _apSpiReadX(void)
{
    int index = ap_spi_inst.touch_count;

    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_RESET);
    delayWhile(1);
	HAL_SPI_Transmit(&hspi4, ap_spi_inst.read_x_tx, 1, 0xFF);
	delayWhile(1);
    HAL_SPI_Receive(&hspi4, ap_spi_inst.read_x_rx[index], 2, 0xFF);
    delayWhile(1);
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_SET);
}

static void _apSpiReadY(void)
{
    int index = ap_spi_inst.touch_count;

    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_RESET);
    delayWhile(1);
    HAL_SPI_Transmit(&hspi4, ap_spi_inst.read_y_tx, 1, 0xFF);
    delayWhile(1);
    HAL_SPI_Receive(&hspi4, ap_spi_inst.read_y_rx[index], 2, 0xFF);
    delayWhile(1);
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_SET);
}

static void _apReadyReadTouch(void)
{
    bool isTouchReadState = (ap_spi_inst.touch_called == true);
    isTouchReadState &= (ap_spi_inst.touch_calculating == false);

    if(isTouchReadState)
    {
        ap_spi_inst.isr_enable_tick = millis();
        ap_spi_inst.touch_calculating = true;
        ap_spi_inst.touch_calculate_done = false;
        ap_spi_inst.touch_count = 0;

        HAL_NVIC_DisableIRQ(EXTI3_IRQn);
    }
}

static void _apCalulateTouch(void)
{
    bool isCalculateState = (ap_spi_inst.touch_calculating == true);
    isCalculateState &= (ap_spi_inst.touch_calculate_done == false);

    if(isCalculateState)
    {
        if(millis() - ap_spi_inst.isr_enable_tick > DEF_READ_INTERVAL_MS)
        {
            ap_spi_inst.isr_enable_tick = millis();
            if(ap_spi_inst.touch_count >= DEF_TOUCH_COUNT_MAX)
            {
                /*@ Calculating Done*/
                ap_spi_inst.touch_count = 0;
                ap_spi_inst.touch_calculate_done = true;
            }
            else
            {
                _apSpiReadX();
                _apSpiReadY();
                ap_spi_inst.touch_count += 1;
            }
        }
    }
}

static void _apTouchISREnable(void)
{
    bool isCalculateDone = (ap_spi_inst.touch_calculate_done == true);
    isCalculateDone &= (ap_spi_inst.touch_calculating == true);

    if(isCalculateDone)
    {
        /* TODO: 1. Check ISR pin stable high
         *       2. Transmit touch axis data to operate
         */
        ap_spi_inst.touch_calculating = false;
        ap_spi_inst.touch_calculate_done = false;
        ap_spi_inst.touch_called = false;

        HAL_NVIC_EnableIRQ(EXTI3_IRQn);

        ap_spi_inst.test_count += 1;  // test
    }
}


#endif
