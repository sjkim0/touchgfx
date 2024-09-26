/*
 * ap_uart.c
 *
 *  Created on: Sep 5, 2024
 *      Author: ksj10
 */


#include "ap_uart.h"


#if DEF_AP_UART_USE == (1U)


extern DMA_HandleTypeDef hdma_usart1_rx;


typedef struct
{
	int rx_tail;
	int rx_header;
	uint8_t rx_buffer[DEF_AP_UART_RX_BUFF_LENGTH];

	int tx_header;
	int tx_tail;
	uint8_t tx_buffer[DEF_AP_UART_TX_BUFF_LENGTH];
	bool tx_done;
	uint8_t transiver[DEF_AP_UART_TRANSIVER_LENGTH];

	int parse_header;
	int parse_tail;
	uint8_t parse_buffer[DEF_AP_UART_PARSE_BUFF_LENGTH];

	bool error_called;
}ApUart_t;


ApUart_t ap_uart_inst;


void apUartInit(void)
{
	ap_uart_inst.tx_done = true;

	HAL_UART_Receive_DMA(&huart1, ap_uart_inst.rx_buffer, DEF_AP_UART_RX_BUFF_LENGTH);
}

void apUartLoop(void)
{
	uint32_t now_ndtr = 0;
	int now_rx_header = 0;

	if(ap_uart_inst.error_called == true)
	{
		ap_uart_inst.error_called = false;
		HAL_UART_DMAStop(&huart1);
		MX_USART1_UART_Init();
		apUartInit();
	}

	now_ndtr = ((DMA_Stream_TypeDef *)hdma_usart1_rx.Instance)->NDTR;
	now_rx_header = DEF_AP_UART_RX_BUFF_LENGTH - now_ndtr;

	while(now_rx_header != ap_uart_inst.rx_header)
	{
		ap_uart_inst.rx_header += 1;
		ap_uart_inst.rx_header %= DEF_AP_UART_RX_BUFF_LENGTH;
	}
	if(ap_uart_inst.rx_header != ap_uart_inst.rx_tail)
	{
		while(ap_uart_inst.rx_header != ap_uart_inst.rx_tail)
		{
			// echo write
			ap_uart_inst.tx_buffer[ap_uart_inst.tx_header] = ap_uart_inst.rx_buffer[ap_uart_inst.rx_tail];
			ap_uart_inst.tx_header += 1;
			ap_uart_inst.tx_header %= DEF_AP_UART_TX_BUFF_LENGTH;

			ap_uart_inst.rx_tail += 1;
			ap_uart_inst.rx_tail %= DEF_AP_UART_RX_BUFF_LENGTH;
		}
	}
	if(ap_uart_inst.tx_done == true && (ap_uart_inst.tx_header != ap_uart_inst.tx_tail))
	{
		int length = (ap_uart_inst.tx_header + DEF_AP_UART_TX_BUFF_LENGTH - ap_uart_inst.tx_tail) % DEF_AP_UART_TX_BUFF_LENGTH;
		if(length > DEF_AP_UART_TRANSIVER_LENGTH)
		{
			length = DEF_AP_UART_TRANSIVER_LENGTH;
		}
		for(int i = 0; i < length; i++)
		{
			ap_uart_inst.transiver[i] = ap_uart_inst.tx_buffer[ap_uart_inst.tx_tail];
			ap_uart_inst.tx_tail += 1;
			ap_uart_inst.tx_tail %= DEF_AP_UART_TX_BUFF_LENGTH;
		}
		HAL_UART_Transmit_DMA(&huart1, ap_uart_inst.transiver, length);
	}
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	if(ap_uart_inst.tx_header == ap_uart_inst.tx_tail)
	{
		ap_uart_inst.tx_done = true;
	}
	else
	{
		int length = (ap_uart_inst.tx_header + DEF_AP_UART_TX_BUFF_LENGTH - ap_uart_inst.tx_tail) % DEF_AP_UART_TX_BUFF_LENGTH;
		if(length > DEF_AP_UART_TRANSIVER_LENGTH)
		{
			length = DEF_AP_UART_TRANSIVER_LENGTH;
		}
		for(int i = 0; i < length; i++)
		{
			ap_uart_inst.transiver[i] = ap_uart_inst.tx_buffer[ap_uart_inst.tx_tail];
			ap_uart_inst.tx_tail += 1;
			ap_uart_inst.tx_tail %= DEF_AP_UART_TX_BUFF_LENGTH;
		}
		HAL_UART_Transmit_DMA(&huart1, ap_uart_inst.transiver, length);
	}
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
	ap_uart_inst.error_called = true;
}

#endif
