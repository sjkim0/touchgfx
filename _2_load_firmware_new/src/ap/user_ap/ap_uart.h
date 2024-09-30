/*
 * ap_uart.h
 *
 *  Created on: Sep 5, 2024
 *      Author: ksj10
 */

#ifndef AP_USER_AP_AP_UART_H_
#define AP_USER_AP_AP_UART_H_


#ifdef __cplusplus
extern "C" {
#endif


#include "ap_def.h"


#if DEF_AP_UART_USE


#define DEF_AP_UART_RX_BUFF_LENGTH    (256U)
#define DEF_AP_UART_TX_BUFF_LENGTH    (256U)
#define DEF_AP_UART_PARSE_BUFF_LENGTH (256U)
#define DEF_AP_UART_TRANSIVER_LENGTH  (256U)


void apUartInit(void);
void apUartLoop(void);


#endif


#ifdef __cplusplus
}
#endif


#endif /* AP_USER_AP_AP_UART_H_ */
