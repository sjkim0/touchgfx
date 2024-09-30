/*
 * ap_custom_loader.h
 *
 *  Created on: Sep 23, 2024
 *      Author: ksj10
 */

#ifndef AP_USER_AP_AP_CUSTOM_LOADER_H_
#define AP_USER_AP_AP_CUSTOM_LOADER_H_


#ifdef __cplusplus
extern "C" {
#endif


#include "ap_def.h"


#define MEMORY_FLASH_SIZE				0x1000000 /* 512 MBits => 16MBytes */
#define MEMORY_BLOCK_SIZE				0x10000   /* 1024 sectors of 64KBytes */
#define MEMORY_SECTOR_SIZE				0x1000    /* 16384 subsectors of 4kBytes */
#define MEMORY_PAGE_SIZE				0x100     /* 262144 pages of 256 bytes */


uint8_t CSP_QUADSPI_Init(void);
uint8_t CSP_QSPI_EraseSector(uint32_t EraseStartAddress ,uint32_t EraseEndAddress);
uint8_t CSP_QSPI_WriteMemory(uint8_t* buffer, uint32_t address, uint32_t buffer_size);
uint8_t CSP_QSPI_EnableMemoryMappedMode(void);
uint8_t CSP_QSPI_Erase_Chip (void);


void apCustomLoaderInit(void);


#ifdef __cplusplus
}
#endif


#endif /* AP_USER_AP_AP_CUSTOM_LOADER_H_ */
