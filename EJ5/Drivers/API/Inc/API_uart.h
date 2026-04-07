/*
 * API_uart.h
 *
 *  Created on: Apr 2, 2026
 *      Author: rberr
 */

#ifndef API_INC_API_UART_H_
#define API_INC_API_UART_H_
#include "stm32f4xx_hal.h"
#include <stdbool.h>
#include <stdint.h>
#include "stm32f4xx_hal_uart.h"

typedef bool bool_t;

bool_t uartInit(void);
void uartSendString(uint8_t * pstring);
void uartSendStringSize(uint8_t * pstring, uint16_t size);
void uartReceiveStringSize(uint8_t * pstring, uint16_t size);



#endif /* API_INC_API_UART_H_ */
