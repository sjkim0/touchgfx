/*
 * ap_cache.c
 *
 *  Created on: Sep 26, 2024
 *      Author: ksj10
 */


#include "ap_cache.h"

#define DEF_TEST_CASE (100U)
#define DEF_TEST_ARR_LENGTH (1024)


#if DEF_AP_CACHE_USE == (1U)

uint8_t __attribute__((section(".ram3section")))cache_buff[DEF_TEST_ARR_LENGTH];  // Static buffer in ITCMRAM
uint8_t __attribute__((section(".ram3blockclearsection")))cache_buff_clear[DEF_TEST_ARR_LENGTH];  // Static buffer in ITCMRAM


void apCacheInit(void)
{
	memset(cache_buff_clear, '\0', sizeof(cache_buff_clear));
	memset(cache_buff_clear, '\0', sizeof(cache_buff));
}

#endif
