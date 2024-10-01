/*
 * ap_qspi.c
 *
 *  Created on: Sep 12, 2024
 *      Author: ksj10
 */


#include "ap_qspi.h"
#include "ap_switch.h"


#define DEF_AP_QSPI_WRITE_ENABLE 	 (0x06U)
#define DEF_AP_QSPI_WRITE_DISABLE 	 (0x04U)
#define DEF_AP_QSPI_VSR_WRITE_ENABLE (0x50U)
#define DEF_AP_QSPI_WRITE_DISABLE 	 (0x04U)
#define DEF_AP_QSPI_READ_STATUS_1 	 (0x05U)
#define DEF_AP_QSPI_WRITE_STATUS_1 	 (0x01U)
#define DEF_AP_QSPI_READ_STATUS_2 	 (0x35U)
#define DEF_AP_QSPI_WRITE_STATUS_2 	 (0x31U)
#define DEF_AP_QSPI_READ_STATUS_3 	 (0x15U)
#define DEF_AP_QSPI_WRITE_STATUS_3 	 (0x11U)
#define DEF_AP_QSPI_CHIP_ERASE_1 	 (0xC7U)
#define DEF_AP_QSPI_CHIP_ERASE_2 	 (0x60U)
#define DEF_AP_QSPI_CHIP_ERASE_4K 	 (0x20U)
#define DEF_AP_QSPI_CHIP_ERASE_32K 	 (0x52U)
#define DEF_AP_QSPI_CHIP_ERASE_64K 	 (0xD8U)
#define DEF_AP_QSPI_ERASE_SUSPEND 	 (0x75U)
#define DEF_AP_QSPI_ERASE_RESUME 	 (0x7AU)
#define DEF_AP_QSPI_POWER_DOWN 		 (0xB9U)
#define DEF_AP_QSPI_READ_PARA 		 (0xC0U)
#define DEF_AP_QSPI_ID 				 (0xABU)
#define DEF_AP_QSPI_DEVICE_ID 		 (0x90U)
#define DEF_AP_QSPI_JDEC_ID 		 (0x9FU)
#define DEF_AP_QSPI_ENABLE_RESET 	 (0x66U)
#define DEF_AP_QSPI_RESET_DEVICE 	 (0x99U)
#define DEF_AP_QSPI_FAST_READ 		 (0xEBU)
#define DEF_AP_QSPI_WRITE	 		 (0x32U)


extern OSPI_HandleTypeDef hospi1;


static uint8_t reg_state[3] = {0, };

ap_qspi_t ap_qspi_inst;



#define _QSPI_DEMO (0U)
#if _QSPI_DEMO == 1
static bool _writeDisable(void);
static bool _eraseAllchip(void);
#endif


void apQspiInit(void)
{
	if(switch_inst.pushed == true)
	{
		apQspiResetChip();
		apQspiEraseBulkchip();
		HAL_DeInit();
		HAL_MspDeInit();
	}
	apQspiReadState1();
	apQspiReadState2();
	apQspiReadState3();

	uint8_t test[100] = {0, };
	for(int i = 0; i < 100; i++)
	{
		test[i] = i;
	}
	apQspiWrite(test, 0, 100);

	apQspiMemMapStart();
}

void apQspiLoop(void)
{

}

bool apQspiReadState1(void)
{
	OSPI_RegularCmdTypeDef s_command;
	memset(&s_command, '\0', sizeof(s_command));

	/* Configure automatic polling mode to wait for memory ready */
	s_command.InstructionMode   = HAL_OSPI_INSTRUCTION_1_LINE;
	s_command.Instruction       = DEF_AP_QSPI_READ_STATUS_1; // READ_STATUS_REG_CMD
	s_command.AddressMode       = HAL_OSPI_ADDRESS_NONE;
	s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
	s_command.DataMode          = HAL_OSPI_DATA_1_LINE;
	s_command.NbData = 1;

	HAL_OSPI_Command(&hospi1, &s_command, 0xFFFF);
	HAL_OSPI_Receive(&hospi1, &reg_state[0], 0xFFFF);

	return true;
}

bool apQspiReadState2(void)
{
	OSPI_RegularCmdTypeDef s_command;
	memset(&s_command, '\0', sizeof(s_command));

	/* Configure automatic polling mode to wait for memory ready */
	s_command.InstructionMode   = HAL_OSPI_INSTRUCTION_1_LINE;
	s_command.Instruction       = DEF_AP_QSPI_READ_STATUS_2; // READ_STATUS_REG_CMD
	s_command.AddressMode       = HAL_OSPI_ADDRESS_NONE;
	s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
	s_command.DataMode          = HAL_OSPI_DATA_1_LINE;
	s_command.NbData = 1;

	HAL_OSPI_Command(&hospi1, &s_command, 0xFFFF);
	HAL_OSPI_Receive(&hospi1, &reg_state[1], 0xFFFF);

	return true;
}

bool apQspiReadState3(void)
{
	OSPI_RegularCmdTypeDef s_command;
	memset(&s_command, '\0', sizeof(s_command));

	/* Configure automatic polling mode to wait for memory ready */
	s_command.InstructionMode   = HAL_OSPI_INSTRUCTION_1_LINE;
	s_command.Instruction       = DEF_AP_QSPI_READ_STATUS_3; // READ_STATUS_REG_CMD
	s_command.AddressMode       = HAL_OSPI_ADDRESS_NONE;
	s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
	s_command.DataMode          = HAL_OSPI_DATA_1_LINE;
	s_command.NbData = 1;

	HAL_OSPI_Command(&hospi1, &s_command, 0xFFFF);
	HAL_OSPI_Receive(&hospi1, &reg_state[2], 0xFFFF);

	return true;
}

void apQspiGetStauts(uint8_t ret[])
{
	for(int i = 0; i < 3; i++)
	{
		ret[i] = reg_state[i];
	}
}

bool apQspiResetChip(void)
{
	OSPI_RegularCmdTypeDef cmd;

    memset((void *)&cmd, '\0', sizeof(cmd));
    cmd.Instruction = DEF_AP_QSPI_ENABLE_RESET;  // Write Enable command
    cmd.InstructionMode = HAL_OSPI_INSTRUCTION_1_LINE;
    cmd.AddressMode = HAL_OSPI_ADDRESS_NONE;  // No address required
    cmd.DataMode = HAL_OSPI_DATA_NONE;  // No data to be transmitted
    cmd.DummyCycles = 0;

    if (HAL_OSPI_Command(&hospi1, &cmd, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return false;
    }

	if(apQspiAutoPollingMemReady(&hospi1, HAL_OSPI_TIMEOUT_DEFAULT_VALUE * 1000) == false)
	{
		return false;
	}

    cmd.Instruction = DEF_AP_QSPI_RESET_DEVICE;  // Write Enable command

    if (HAL_OSPI_Command(&hospi1, &cmd, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return false;
    }

	if(apQspiAutoPollingMemReady(&hospi1, HAL_OSPI_TIMEOUT_DEFAULT_VALUE * 1000) == false)
	{
		return false;
	}

    return true;
}

bool apQspiWriteEnable(void)
{
	OSPI_RegularCmdTypeDef cmd = {0, };

	// busy check
    cmd.Instruction = DEF_AP_QSPI_READ_STATUS_1;  // Write Enable command
    cmd.InstructionMode = HAL_OSPI_INSTRUCTION_1_LINE;
    cmd.AddressMode = HAL_OSPI_ADDRESS_NONE;  // No address required
    cmd.DataMode = HAL_OSPI_DATA_NONE;  // No data to be transmitted
    cmd.DummyCycles = 0;
    if (HAL_OSPI_Command(&hospi1, &cmd, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return false;
    }
	if(apQspiAutoPollingMemReady(&hospi1, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) == false)
	{
		return false;
	}

	// write enable
    memset((void *)&cmd, '\0', sizeof(cmd));
    cmd.Instruction = DEF_AP_QSPI_WRITE_ENABLE;  // Write Enable command
    cmd.InstructionMode = HAL_OSPI_INSTRUCTION_1_LINE;
    cmd.AddressMode = HAL_OSPI_ADDRESS_NONE;  // No address required
    cmd.DataMode = HAL_OSPI_DATA_NONE;  // No data to be transmitted
    cmd.DummyCycles = 0;
    cmd.NbData = 1; // s_config status bytes size를 대체함
    if (HAL_OSPI_Command(&hospi1, &cmd, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return false;
    }

	if(apQspiAutoPollingWriteEnable(&hospi1, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) == false)
	{
		return false;
	}

    return true;
}

bool apQspiEraseBulkchip(void)
{
	apQspiWriteEnable();

	OSPI_RegularCmdTypeDef cmd = {0, };

    cmd.Instruction = DEF_AP_QSPI_CHIP_ERASE_1;  // Write Enable command
    cmd.InstructionMode = HAL_OSPI_INSTRUCTION_1_LINE;
    cmd.AddressMode = HAL_OSPI_ADDRESS_NONE;  // No address required
    cmd.DataMode = HAL_OSPI_DATA_NONE;  // No data to be transmitted
    cmd.DummyCycles = 0;

    if (HAL_OSPI_Command(&hospi1, &cmd, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return false;
    }

	while(true)
	{
		if(apQspiAutoPollingMemReady(&hospi1, HAL_OSPI_TIMEOUT_DEFAULT_VALUE * 1000) == true)
		{
			break;
		}
	}

    return true;
}

bool apQspiEraseSector(uint32_t address)
{
    OSPI_RegularCmdTypeDef cmd = {0, };

	apQspiWriteEnable();

	cmd.Instruction = DEF_AP_QSPI_CHIP_ERASE_4K; // chip erase
	cmd.InstructionMode = HAL_OSPI_INSTRUCTION_1_LINE;
	cmd.AddressMode = HAL_OSPI_ADDRESS_1_LINE;
	cmd.AddressSize = HAL_OSPI_ADDRESS_24_BITS;
	cmd.Address = address;
	cmd.DataMode = HAL_OSPI_DATA_NONE;  // Quad mode for data
	cmd.DummyCycles = 0;  /// fast read에 사용된다고함

	HAL_OSPI_Command(&hospi1, &cmd, HAL_OSPI_TIMEOUT_DEFAULT_VALUE);

	if(apQspiAutoPollingMemReady(&hospi1, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) == false)
	{
		return false;
	}

	return true;
}

/*
 * @ brief : check busy state only
 */

bool apQspiAutoPollingMemReady(OSPI_HandleTypeDef *hospi1, uint32_t Timeout)
{
	OSPI_RegularCmdTypeDef s_command = {0, };
	OSPI_AutoPollingTypeDef s_config = {0, };

	/* Configure automatic polling mode to wait for memory ready */
	s_command.InstructionMode = HAL_OSPI_INSTRUCTION_1_LINE;
	s_command.Instruction = DEF_AP_QSPI_READ_STATUS_1; // READ_STATUS_REG_CMD
	s_command.AddressMode = HAL_OSPI_ADDRESS_NONE;
	s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
	s_command.DataMode = HAL_OSPI_DATA_1_LINE;
	s_command.NbData = 1;  // s_config status bytes size를 대체함
	s_command.DummyCycles = 0;

	s_config.Match           = 0x00;
	s_config.Mask            = 0x01; // W25Q128FV_SR_WIP
	s_config.MatchMode       = HAL_OSPI_MATCH_MODE_AND;
	// s_config.StatusBytesSize = 1;
	s_config.Interval        = 0x10;
	s_config.AutomaticStop   = HAL_OSPI_AUTOMATIC_STOP_ENABLE;

    if (HAL_OSPI_Command(hospi1, &s_command, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return false;
    }
	if(HAL_OSPI_AutoPolling(hospi1, &s_config, Timeout) != HAL_OK)
	{
		return false;
	}
	return true;
}

bool apQspiAutoPollingWriteEnable(OSPI_HandleTypeDef *hospi1, uint32_t Timeout)
{
	OSPI_RegularCmdTypeDef s_command = {0, };
	OSPI_AutoPollingTypeDef s_config = {0, };

	/* Configure automatic polling mode to wait for memory ready */
	s_command.InstructionMode = HAL_OSPI_INSTRUCTION_1_LINE;
	s_command.Instruction = DEF_AP_QSPI_READ_STATUS_1; // READ_STATUS_REG_CMD
	s_command.AddressMode = HAL_OSPI_ADDRESS_NONE;
	s_command.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
	s_command.DataMode = HAL_OSPI_DATA_1_LINE;
	s_command.NbData = 1;  // s_config status bytes size를 대체함
	s_command.DummyCycles = 0;

	s_config.Match           = 0x02;
	s_config.Mask            = 0x02; // W25Q128FV_SR_WIP
	s_config.MatchMode       = HAL_OSPI_MATCH_MODE_AND;
	// s_config.StatusBytesSize = 1;
	s_config.Interval        = 0x10;
	s_config.AutomaticStop   = HAL_OSPI_AUTOMATIC_STOP_ENABLE;

    if (HAL_OSPI_Command(hospi1, &s_command, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return false;
    }
	if(HAL_OSPI_AutoPolling(hospi1, &s_config, Timeout) != HAL_OK)
	{
		return false;
	}
	return true;
}


bool apQspiMemMapStart(void)
{
	OSPI_RegularCmdTypeDef s_command = {0, };
    OSPI_MemoryMappedTypeDef cfg = {0, };


	/* Configure automatic polling mode to wait for memory ready */
	s_command.InstructionMode = HAL_OSPI_INSTRUCTION_1_LINE;
	s_command.Instruction = DEF_AP_QSPI_FAST_READ; // READ_STATUS_REG_CMD
	s_command.AddressMode = HAL_OSPI_ADDRESS_4_LINES;
	s_command.AddressSize = HAL_OSPI_ADDRESS_24_BITS;
	s_command.Address = 0;
	s_command.DataMode = HAL_OSPI_DATA_4_LINES;
	s_command.NbData = 0;
	s_command.DummyCycles = 6;

	if (HAL_OSPI_Command(&hospi1, &s_command, 0xFFFF) != HAL_OK)
	{
		return false;
	}
	cfg.TimeOutActivation = HAL_OSPI_TIMEOUT_COUNTER_DISABLE;

    if(HAL_OSPI_MemoryMapped(&hospi1, &cfg) != HAL_OK)
    {
        Error_Handler();
    }

    return true;
}

bool apQspiRead(uint8_t ret_buff[], uint32_t p_address, uint32_t length)
{
	if(length < DEF_READ_BUFF_LENGTH)
	{
		OSPI_RegularCmdTypeDef sCommand = {0};
		sCommand.InstructionMode = HAL_OSPI_INSTRUCTION_1_LINE;
		sCommand.Instruction = DEF_AP_QSPI_FAST_READ; // READ_STATUS_REG_CMD
		sCommand.AddressMode = HAL_OSPI_ADDRESS_4_LINES;
		sCommand.AddressSize = HAL_OSPI_ADDRESS_24_BITS;
		sCommand.Address = p_address;
		sCommand.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
		sCommand.DataMode = HAL_OSPI_DATA_4_LINES;
		sCommand.NbData = length;
		sCommand.DummyCycles = 6;

		if (HAL_OSPI_Command(&hospi1, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
		{
			return false;
		}

		if (HAL_OSPI_Receive(&hospi1, ret_buff, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
		{
			return false;
		}
	}
    return true;
}

bool apQspiWrite(uint8_t buff[], uint32_t p_address, uint32_t length)
{
	OSPI_RegularCmdTypeDef s_command = {0, };

	if((length < DEF_READ_BUFF_LENGTH) && (length > 0))
	{
		apQspiWriteEnable();

		/* Configure automatic polling mode to wait for memory ready */
		s_command.InstructionMode = HAL_OSPI_INSTRUCTION_1_LINE;
		s_command.Instruction = DEF_AP_QSPI_WRITE; // READ_STATUS_REG_CMD
		s_command.AddressMode = HAL_OSPI_ADDRESS_1_LINE;
		s_command.AddressSize = HAL_OSPI_ADDRESS_24_BITS;
		s_command.Address = p_address;
		s_command.DataMode = HAL_OSPI_DATA_4_LINES;
		s_command.NbData = length;

		if (HAL_OSPI_Command(&hospi1, &s_command, HAL_OSPI_TIMEOUT_COUNTER_DISABLE) != HAL_OK)
		{
			return false;
		}

		HAL_OSPI_Transmit(&hospi1, buff, HAL_OSPI_TIMEOUT_DEFAULT_VALUE);

		if(apQspiAutoPollingMemReady(&hospi1, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) == false)
		{
			return false;
		}
	}
    return true;
}
#if _QSPI_DEMO == 1


 bool _eraseBlock32Kb(uint32_t address)
{
	_writeEnable();

	QSPI_CommandTypeDef cmd;

	memset((void *)&cmd, '\0', sizeof(cmd));
	cmd.Instruction = 0x52; // chip erase
	cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
	cmd.AddressMode = QSPI_ADDRESS_1_LINE;
	cmd.Address = address;
	cmd.DataMode = QSPI_DATA_NONE;  // Quad mode for data
	cmd.DummyCycles = 0;  /// fast read에 사용된다고함

	HAL_QSPI_Command(&hqspi, &cmd, HAL_QSPI_TIMEOUT_DEFAULT_VALUE);

	if(_autoPollingMemReady(&hqspi, HAL_QSPI_TIMEOUT_DEFAULT_VALUE) == false)
	{
		return false;
	}

	return true;
}

 bool _writeDisable(void)
{
    QSPI_CommandTypeDef cmd;

    // Step 1: Write Enable (0x06)
    memset((void *)&cmd, '\0', sizeof(cmd));
    cmd.Instruction = DEF_AP_QSPI_WRITE_DISABLE;  // Write Enable command
    cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    cmd.AddressMode = QSPI_ADDRESS_NONE;  // No address required
    cmd.DataMode = QSPI_DATA_NONE;  // No data to be transmitted
    cmd.DummyCycles = 0;

    if (HAL_QSPI_Command(&hqspi, &cmd, HAL_QSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return false;
    }

	if(_autoPollingMemReady(&hqspi, HAL_QSPI_TIMEOUT_DEFAULT_VALUE) == false)
	{
		return false;
	}

    return true;
}

 bool _eraseAllchip(void)
{
	_writeEnable();

	QSPI_CommandTypeDef cmd;

	memset((void *)&cmd, '\0', sizeof(cmd));
	cmd.Instruction = DEF_AP_QSPI_CHIP_ERASE_2; // chip erase
	cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
	cmd.AddressMode = QSPI_ADDRESS_NONE;
	cmd.DataMode = QSPI_DATA_NONE;  // Quad mode for data
	cmd.DummyCycles = 0;  /// fast read에 사용된다고함

	HAL_QSPI_Command(&hqspi, &cmd, HAL_QSPI_TIMEOUT_DEFAULT_VALUE);

	if(_autoPollingMemReady(&hqspi, HAL_QSPI_TIMEOUT_DEFAULT_VALUE) == false)
	{
		return false;
	}

    return true;
}


 bool _eraseBlock64Kb(uint32_t address)
{
	_writeEnable();

	QSPI_CommandTypeDef cmd;

	memset((void *)&cmd, '\0', sizeof(cmd));
	cmd.Instruction = 0xD8; // chip erase
	cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
	cmd.AddressMode = QSPI_ADDRESS_1_LINE;
	cmd.Address = address;
	cmd.DataMode = QSPI_DATA_NONE;  // Quad mode for data
	cmd.DummyCycles = 0;  /// fast read에 사용된다고함

	HAL_QSPI_Command(&hqspi, &cmd, HAL_QSPI_TIMEOUT_DEFAULT_VALUE);

	if(_autoPollingMemReady(&hqspi, HAL_QSPI_TIMEOUT_DEFAULT_VALUE) == false)
	{
		return false;
	}

	return true;
}
#endif


