#include "UART.h"


#define _USART2_COM_
#ifdef _USART2_COM_
#define USARTx          USART2
#define USARTx_GPIO     GPIOA
#define USARTx_CLK      RCC_APB1_PERIPH_USART2
#define USARTx_GPIO_CLK RCC_APB2_PERIPH_GPIOA
#define USARTx_RxPin    GPIO_PIN_3
#define USARTx_TxPin    GPIO_PIN_2

#define GPIO_APBxClkCmd  RCC_EnableAPB2PeriphClk
#define USART_APBxClkCmd RCC_EnableAPB1PeriphClk
#endif
void UART_Init(void)
{
		GPIO_InitType GPIO_InitStructure;
		USART_InitType USART_InitStructure;
	    /* Enable GPIO clock */
    GPIO_APBxClkCmd(USARTx_GPIO_CLK | RCC_APB2_PERIPH_AFIO, ENABLE);
    /* Enable USARTy and USARTz Clock */
    USART_APBxClkCmd(USARTx_CLK, ENABLE);
		//GPIO_InitType GPIO_InitStructure;

    /* Configure USARTx Tx as alternate function push-pull */
    GPIO_InitStructure.Pin        = USARTx_TxPin;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
    GPIO_InitPeripheral(USARTx_GPIO, &GPIO_InitStructure);

    /* Configure USARTx Rx as input floating */
    GPIO_InitStructure.Pin       = USARTx_RxPin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitPeripheral(USARTx_GPIO, &GPIO_InitStructure);

	/* USARTy and USARTz configuration ------------------------------------------------------*/
    USART_InitStructure.BaudRate            = 1152000;
    USART_InitStructure.WordLength          = USART_WL_8B;
    USART_InitStructure.StopBits            = USART_STPB_1;
    USART_InitStructure.Parity              = USART_PE_NO;
    USART_InitStructure.HardwareFlowControl = USART_HFCTRL_NONE;
    USART_InitStructure.Mode                = USART_MODE_RX | USART_MODE_TX;

    /* Configure USARTx */
    USART_Init(USARTx, &USART_InitStructure);
    /* Enable the USARTx */
    USART_Enable(USARTx, ENABLE);
	}

void UART_SentData(USART_Module* USARTxx, uint16_t Data)
{
	if(USART_STS_TXDE)
	{
		__NOP();
		__NOP();
		//USART_SendData(USART2,0xAA);
		USARTxx->DAT = (Data & (uint16_t)0x01FF);
	}
}










