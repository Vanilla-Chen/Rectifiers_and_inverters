#ifndef __UART_H__
#define __UART_H__

#include "Include.h"

void UART_Init(void);
void UART_SentData(USART_Module* USARTxx, uint16_t Data);
#endif /* __UART_H__ */


