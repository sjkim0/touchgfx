/*
 * ap_uart.h
 *
 *  Created on: Sep 5, 2024
 *      Author: ksj10
 */

#ifndef AP_USER_AP_AP_UART_H_
#define AP_USER_AP_AP_UART_H_


#include "ap_def.h"


#if DEF_AP_UART_USE


#define DEF_AP_UART_RX_BUFF_LENGTH    (256U)
#define DEF_AP_UART_TX_BUFF_LENGTH    (256U)
#define DEF_AP_UART_PARSE_BUFF_LENGTH (256U)
#define DEF_AP_UART_TRANSIVER_LENGTH  (8U)


void apUartInit(void);
void apUartLoop(void);


#endif


#endif /* AP_USER_AP_AP_UART_H_ */
