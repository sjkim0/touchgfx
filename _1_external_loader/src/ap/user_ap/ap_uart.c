/*
 * ap_uart.c
 *
 *  Created on: Sep 5, 2024
 *      Author: ksj10
 */


#include "ap_uart.h"


#if DEF_AP_USE_UART == (1U)


extern DMA_HandleTypeDef hdma_lpuart1_rx;


typedef struct
{
	int rx_header;
	uint8_t rx_buffer[DEF_AP_UART_RX_BUFF_LENGTH];

	int tx_header;
	int tx_tail;
	uint8_t tx_buffer[DEF_AP_UART_TX_BUFF_LENGTH];

	int parse_header;
	int parse_tail;
	uint8_t parse_buffer[DEF_AP_UART_PARSE_BUFF_LENGTH];
}ApUart_t;


ApUart_t ap_uart_inst;


void apUartInit(void)
{
	HAL_UART_Receive_DMA(&hlpuart1, ap_uart_inst.rx_buffer, DEF_AP_UART_RX_BUFF_LENGTH);
}

void apUartLoop(void)
{
	uint32_t now_ndtr = 0;
	int now_rx_header = 0;

	now_ndtr = hdma_lpuart1_rx.Instance->CNDTR;
	now_rx_header = DEF_AP_UART_RX_BUFF_LENGTH - now_ndtr;

	while(now_rx_header != ap_uart_inst.rx_header)
	{
		ap_uart_inst.rx_header += 1;
		ap_uart_inst.rx_header %= DEF_AP_UART_RX_BUFF_LENGTH;
	}
}


#endif
