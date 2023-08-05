#include "Include.h"
void delay(int time)
{
	while(time--);
}
TABC_DQ_STRUCT 	ABC_DQ_Data;
EPLL 						Theta_data;
SVPWM 					Tabc;

uint16_t UART_Buffer[400] = {0};
uint16_t iii = 0;
int main(void)
{
	
	GPIO_InitType GPIO_InitStructure;
	
	RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOC, ENABLE);
	
	//GPIO_InitStruct(&GPIO_InitStructure);
	GPIO_InitStructure.Pin = GPIO_PIN_13;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitPeripheral(GPIOC, &GPIO_InitStructure);
	
	//Timer4_Init((1000-1),(144-1));
	//TIM2_TIM_Init((1000-1),(144-1));	//72M/72/100 = 10k
	TIM_Intial(TIM1);
	UART_Init();
	
	
	while(ii != 400);

	while(1)
	{	
		for(iii = 0;iii < 400; iii++)
		{
			UART_SentData(USART2,UART_Buffer[iii]);
		}

//		Udq2SVPWM(&ABC_DQ_Data,&Theta_data,0,&Tabc);
//		GPIOC->PBSC = GPIO_PIN_13;	//set
//		Udq2SVPWM(&ABC_DQ_Data,&Theta_data,0,&Tabc);
//		GPIOC->PBC = GPIO_PIN_13;		//reset
		
	}
}



