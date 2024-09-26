/*
 * ap_custom_loader.c
 *
 *  Created on: Sep 23, 2024
 *      Author: ksj10
 */


#include "ap_custom_loader.h"
#include "ap_qspi.h"


#define WRITE_ENABLE_CMD 0x06
#define READ_STATUS_REG_CMD 0x05
#define WRITE_STATUS_REG_CMD 0x01
#define SECTOR_ERASE_CMD 0x20
#define CHIP_ERASE_CMD 0xC7
#define QUAD_IN_FAST_PROG_CMD 0x38
#define READ_CONFIGURATION_REG_CMD 0x15
#define QUAD_READ_IO_CMD 0xEC
#define QUAD_OUT_FAST_READ_CMD 0x6B
#define QPI_ENABLE_CMD 0x35
#define DUMMY_CLOCK_CYCLES_READ_QUAD 10
#define RESET_ENABLE_CMD 0x66
#define RESET_EXECUTE_CMD 0x99
#define DISABLE_QIP_MODE 0xf5


#define SECTORS_COUNT 1

static uint8_t QSPI_WriteEnable(void);
static uint8_t QSPI_AutoPollingMemReady(void);
static uint8_t QSPI_Configuration(void);
static uint8_t QSPI_ResetChip(void);


uint8_t buffer_test[MEMORY_SECTOR_SIZE];
uint8_t buffer_test_comp[MEMORY_SECTOR_SIZE];


void apCustomLoaderInit(void)
{
  	CSP_QUADSPI_Init();

  	if (CSP_QSPI_EnableMemoryMappedMode() != HAL_OK)
  	{
  		while(1); //breakpoint - error detected
  	}

	bool jump = true;
	if(jump == true)
	{
	    __set_MSP(*(volatile uint32_t*)0x90000000);
	    uint32_t jump_address = *(volatile uint32_t*)0x90000004;
		void (*pJump)(void);
		pJump = (void (*)(void))jump_address;
		pJump();
	}
}

/* QUADSPI init function */
uint8_t CSP_QUADSPI_Init(void)
{
	//prepare QSPI peripheral for ST-Link Utility operations
	if (HAL_OSPI_DeInit(&hospi1) != HAL_OK)
	{
		return HAL_ERROR;
	}

	MX_OCTOSPI1_Init();

	if(QSPI_ResetChip() != HAL_OK)
	{
		return HAL_ERROR;
	}

	if(QSPI_AutoPollingMemReady() != HAL_OK)
	{
		return HAL_ERROR;
	}

	if(QSPI_WriteEnable() != HAL_OK)
	{
		return HAL_ERROR;
	}

	if(QSPI_Configuration() != HAL_OK)
	{
		return HAL_ERROR;
	}

	return HAL_OK;
}

uint8_t CSP_QSPI_Erase_Chip(void)
{
	if(apQspiEraseBulkchip() == true)
	{
		return HAL_OK;
	}
	return HAL_ERROR;
}

uint8_t QSPI_AutoPollingMemReady(void)
{
	if(apQspiAutoPollingMemReady(&hospi1, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) == true)
	{
		return HAL_OK;
	}
	return HAL_ERROR;
}

static uint8_t QSPI_WriteEnable(void)
{
	if(apQspiWriteEnable() == true)
	{
		return HAL_OK;
	}
	return HAL_ERROR;
}
/*Enable quad mode and set dummy cycles count*/
uint8_t QSPI_Configuration(void)
{
	//@ example code에는 quad mode를 enable하나 생략하였다.
	HAL_StatusTypeDef ret = HAL_OK;

	uint8_t test_buffer[4] = { 0 };

	if(apQspiReadState1() == false)
	{
		ret = HAL_ERROR;
	}
	if(apQspiReadState2() == false)
	{
		ret = HAL_ERROR;
	}
	if(apQspiReadState3() == false)
	{
		ret = HAL_ERROR;
	}

	apQspiGetStauts(test_buffer);

	return ret;
}

uint8_t CSP_QSPI_EraseSector(uint32_t EraseStartAddress, uint32_t EraseEndAddress)
{
	EraseStartAddress = EraseStartAddress - EraseStartAddress % MEMORY_SECTOR_SIZE;

	while (EraseEndAddress >= EraseStartAddress)
	{
		apQspiEraseSector((EraseStartAddress & 0x0FFFFFFF));
		EraseStartAddress += MEMORY_SECTOR_SIZE;
	}

	return HAL_OK;
}

uint8_t CSP_QSPI_WriteMemory(uint8_t* buffer, uint32_t address, uint32_t buffer_size)
{
	uint32_t end_addr, current_size, current_addr;

	current_addr = 0;

	while (current_addr <= address)
	{
		current_addr += MEMORY_PAGE_SIZE;
	}
	current_size = current_addr - address;

	/* Check if the size of the data is less than the remaining place in the page */
	if (current_size > buffer_size)
	{
		current_size = buffer_size;
	}

	/* Initialize the adress variables */
	current_addr = address;
	end_addr = address + buffer_size;

	/* Perform the write page by page */
	do
	{
		if(current_size == 0)
		{
			break;
		}
		apQspiWrite(buffer, current_addr, current_size);

		/* Update the address and size variables for next page programming */
		current_addr += current_size;
		buffer += current_size;
		current_size = ((current_addr + MEMORY_PAGE_SIZE) > end_addr) ? (end_addr - current_addr) : MEMORY_PAGE_SIZE;
	}
	while (current_addr <= end_addr);

	return HAL_OK;
}

uint8_t CSP_QSPI_EnableMemoryMappedMode(void)
{
	if(apQspiMemMapStart() == true)
	{
		return HAL_OK;
	}
	return HAL_ERROR;
}

uint8_t QSPI_ResetChip()
{
	if(apQspiResetChip() == true)
	{
		return HAL_OK;
	}
	return HAL_ERROR;
}
