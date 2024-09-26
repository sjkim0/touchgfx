/*
 * ap_cache.c
 *
 *  Created on: Sep 26, 2024
 *      Author: ksj10
 */


#include "ap_cache.h"

#define DEF_TEST_CASE (100U)
#define DEF_TEST_ARR_LENGTH (1024)


uint32_t buffer[DEF_TEST_ARR_LENGTH];
uint32_t __attribute__((section(".ram3section")))cache_buff[DEF_TEST_ARR_LENGTH];  // Static buffer in ITCMRAM
uint32_t __attribute__((section(".ram3blockclearsection")))cache_buff_clear[DEF_TEST_ARR_LENGTH];  // Static buffer in ITCMRAM


void apCacheInit(void)
{
	// uint32_t *p_cache_buff = (volatile uint32_t *)0x00000000;
	uint32_t start, end_0, end_1, end_2, end_3;

    start = HAL_GetTick();

    for(int i = 0; i < DEF_TEST_CASE; i++)
    {
        for(int j = 0; j < DEF_TEST_ARR_LENGTH; j++)
        {
        	buffer[j] = j;
        }
    }

    end_1 = HAL_GetTick() - start;

    // enable cache buffer
    SCB_EnableDCache();
    SCB_EnableICache();
    start = HAL_GetTick();

    for(int i = 0; i < DEF_TEST_CASE; i++)
    {
        for(int j = 0; j < DEF_TEST_ARR_LENGTH; j++)
        {
        	cache_buff[j] = j;
        }
    }

    end_1 = HAL_GetTick() - start;

    start = HAL_GetTick();

    for(int i = 0; i < DEF_TEST_CASE; i++)
    {
        for(int j = 0; j < DEF_TEST_ARR_LENGTH; j++)
        {
        	cache_buff_clear[j] = j;
        }
    }

    end_1 = HAL_GetTick() - start;
}
