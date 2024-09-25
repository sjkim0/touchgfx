	/*
 * ap_qspi.h
 *
 *  Created on: Sep 12, 2024
 *      Author: ksj10
 */

#ifndef AP_USER_AP_AP_QSPI_H_
#define AP_USER_AP_AP_QSPI_H_



#include "ap_def.h"


#define DEF_TX_BUFF_LENGTH   (256U)
#define DEF_READ_BUFF_LENGTH (512U)


typedef struct
{
	uint8_t read_buff[DEF_READ_BUFF_LENGTH];
	uint8_t transmit_buff[DEF_TX_BUFF_LENGTH];
}ap_qspi_t;


bool apQspiReadState1(void);
bool apQspiReadState2(void);
bool apQspiReadState3(void);

void apQspiGetStauts(uint8_t ret[]);

bool apQspiResetChip(void);
bool apQspiWriteEnable(void);
bool apQspiAutoPollingMemReady(OSPI_HandleTypeDef *hospi1, uint32_t Timeout);
bool apQspiAutoPollingWriteEnable(OSPI_HandleTypeDef *hospi1, uint32_t Timeout);
bool apQspiMemMapStart(void);
bool apQspiEraseBulkchip(void);
bool apQspiEraseSector(uint32_t address);
bool apQspiRead(uint8_t ret_buff[], uint32_t p_address, uint32_t length);
bool apQspiWrite(uint8_t buff[], uint32_t p_address, uint32_t length);

void apQspiInit(void);
void apQspiLoop(void);


#endif /* AP_USER_AP_AP_QSPI_H_ */
