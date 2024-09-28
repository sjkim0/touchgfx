/*
 * ap_sdram.c
 *
 *  Created on: Sep 28, 2024
 *      Author: ksj10
 */


#include "ap_sdram.h"
#include "ap_sdram_def.h"


#if DEF_AP_SDRAM_USE


typedef struct
{
	volatile uint32_t *p_addr;
}ap_sdram_t;


ap_sdram_t ap_sdram_inst;


static void _SdRamInit(SDRAM_HandleTypeDef sdramHandle, uint32_t RefreshCount);


void apSdramInit(void)
{
	_SdRamInit(hsdram1, DEF_REFRESH_COUNT);
	ap_sdram_inst.p_addr = (volatile uint32_t *)DEF_FMC_SDRAM_BK_1_SR_1_MEM_ADDR;
}

void apSdramLoop(void)
{

}


static void _SdRamInit(SDRAM_HandleTypeDef sdramHandle, uint32_t RefreshCount)
{
	FMC_SDRAM_CommandTypeDef Command = {0, };
	__IO uint32_t tmpmrd = 0;

	/* Step 1: Configure a clock configuration enable command */
	Command.CommandMode            = FMC_SDRAM_CMD_CLK_ENABLE;
	Command.CommandTarget          = FMC_SDRAM_CMD_TARGET_BANK1;
	Command.AutoRefreshNumber      = 1;
	Command.ModeRegisterDefinition = 0;

	/* Send the command */
	HAL_SDRAM_SendCommand(&sdramHandle, &Command, DEF_SDRAM_TIMEOUT);

	/* Step 2: Insert 100 us minimum delay */
	/* Inserted delay is equal to 1 ms due to systick time base unit (ms) */
	HAL_Delay(1);

	/* Step 3: Configure a PALL (precharge all) command */
	Command.CommandMode            = FMC_SDRAM_CMD_PALL;
	Command.CommandTarget          = FMC_SDRAM_CMD_TARGET_BANK1;
	Command.AutoRefreshNumber      = 1;
	Command.ModeRegisterDefinition = 0;

	/* Send the command */
	HAL_SDRAM_SendCommand(&sdramHandle, &Command, DEF_SDRAM_TIMEOUT);

	/* Step 4: Configure an Auto Refresh command */
	Command.CommandMode            = FMC_SDRAM_CMD_AUTOREFRESH_MODE;
	Command.CommandTarget          = FMC_SDRAM_CMD_TARGET_BANK1;
	Command.AutoRefreshNumber      = 8;
	Command.ModeRegisterDefinition = 0;

	/* Send the command */
	HAL_SDRAM_SendCommand(&sdramHandle, &Command, DEF_SDRAM_TIMEOUT);

	/* Step 5: Program the external memory mode register */
	tmpmrd = (uint32_t)DEF_SDRAM_MODEREG_BURST_LENGTH_1 |\
	                   DEF_SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL |\
                       DEF_SDRAM_MODEREG_CAS_LATENCY_2 |\
                       DEF_SDRAM_MODEREG_OPERATING_MODE_STANDARD |\
                       DEF_SDRAM_MODEREG_WRITEBURST_MODE_SINGLE;

	Command.CommandMode            = FMC_SDRAM_CMD_LOAD_MODE;
	Command.CommandTarget          = FMC_SDRAM_CMD_TARGET_BANK1;
	Command.AutoRefreshNumber      = 1;
	Command.ModeRegisterDefinition = tmpmrd;

	/* Send the command */
	HAL_SDRAM_SendCommand(&sdramHandle, &Command, DEF_SDRAM_TIMEOUT);

	/* Step 6: Set the refresh rate counter */
	/* Set the device refresh rate */
	HAL_SDRAM_ProgramRefreshRate(&sdramHandle, RefreshCount);
}


#endif
