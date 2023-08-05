#include "TIM.h"

TIM_TimeBaseInitType TIM_TimeBaseStructure;
uint16_t TimerPeriod   = 0;
uint16_t Channel1Pulse = 0, Channel2Pulse = 0, Channel3Pulse = 0, Channel4Pulse = 0;
OCInitType TIM_OCInitStructure;

void TIM_Intial(TIM_Module* TIMx)
{
		//RCC
	 /* TIM3 clock enable */
    RCC_EnableAPB1PeriphClk(RCC_APB1_PERIPH_TIM3, ENABLE);

    /* GPIOA and GPIOB clock enable */
    RCC_EnableAPB2PeriphClk(
        RCC_APB2_PERIPH_GPIOA | RCC_APB2_PERIPH_GPIOB | RCC_APB2_PERIPH_GPIOC | RCC_APB2_PERIPH_AFIO, ENABLE);
			/* TIM1, GPIOA, GPIOB, GPIOE and AFIO clocks enable */
    RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOA | RCC_APB2_PERIPH_GPIOB | RCC_APB2_PERIPH_GPIOC 
																| RCC_APB2_PERIPH_TIM1
                                | RCC_APB2_PERIPH_GPIOD | RCC_APB2_PERIPH_GPIOE
                                | RCC_APB2_PERIPH_AFIO, ENABLE);
	
    /* TIMx Configuration ---------------------------------------------------
    Generate 7 PWM signals with 4 different duty cycles:
    TIM1CLK = SystemCoreClock, Prescaler = 0, TIM1 counter clock = SystemCoreClock
    SystemCoreClock is set to 72 MHz for Low-density, Medium-density, High-density
    and Connectivity line devices and to 24 MHz for Low-Density Value line and
    Medium-Density Value line devices

    The objective is to generate 7 PWM signal at 17.57 KHz:
     - TIMx_Period = (SystemCoreClock / 17570) - 1
    The channel 1 and channel 1N duty cycle is set to 50%
    The channel 2 and channel 2N duty cycle is set to 37.5%
    The channel 3 and channel 3N duty cycle is set to 25%
    The channel 4 duty cycle is set to 12.5%
    The Timer pulse is calculated as follows:
     - ChannelxPulse = DutyCycle * (TIM1_Period - 1) / 100
    ----------------------------------------------------------------------- */
    /* Compute the value to be set in AR regiter to generate signal frequency at 17.57 Khz */
    TimerPeriod = 100; 	//(SystemCoreClock / 17570 ) - 1;
    /* Compute CCDAT1 value to generate a duty cycle at 50% for channel 1 and 1N */
    Channel1Pulse = 2;	//(uint16_t)(((uint32_t)5 * (TimerPeriod - 1)) / 10);
    /* Compute CCDAT2 value to generate a duty cycle at 37.5%  for channel 2 and 2N */
    Channel2Pulse = 1;		//(uint16_t)(((uint32_t)375 * (TimerPeriod - 1)) / 1000);
    /* Compute CCDAT3 value to generate a duty cycle at 25%  for channel 3 and 3N */
    Channel3Pulse = 0;		//(uint16_t)(((uint32_t)25 * (TimerPeriod - 1)) / 100);
    /* Compute CCDAT4 value to generate a duty cycle at 12.5%  for channel 4 */
    Channel4Pulse = 10;		//(uint16_t)(((uint32_t)125 * (TimerPeriod - 1)) / 1000);

    /* Time Base configuration */
    TIM_TimeBaseStructure.Prescaler = 72-1;						// 72MHz
    TIM_TimeBaseStructure.CntMode   = TIM_CNT_MODE_CENTER_ALIGN3;
    TIM_TimeBaseStructure.Period    = TimerPeriod;
    TIM_TimeBaseStructure.ClkDiv    = 0;
    TIM_TimeBaseStructure.RepetCnt  = 0;

    TIM_InitTimeBase(TIMx, &TIM_TimeBaseStructure);

    /* Channel 1, 2,3 and 4 Configuration in PWM mode */
    TIM_OCInitStructure.OcMode       = TIM_OCMODE_PWM2;
    TIM_OCInitStructure.OutputState  = TIM_OUTPUT_STATE_ENABLE;
    TIM_OCInitStructure.OutputNState = TIM_OUTPUT_NSTATE_ENABLE;
    TIM_OCInitStructure.Pulse        = Channel1Pulse;
    TIM_OCInitStructure.OcPolarity   = TIM_OC_POLARITY_HIGH;
    TIM_OCInitStructure.OcNPolarity  = TIM_OCN_POLARITY_HIGH;
    TIM_OCInitStructure.OcIdleState  = TIM_OC_IDLE_STATE_SET;
    TIM_OCInitStructure.OcNIdleState = TIM_OC_IDLE_STATE_RESET;
    TIM_InitOc1(TIMx, &TIM_OCInitStructure);

    TIM_OCInitStructure.Pulse = Channel3Pulse;
    TIM_InitOc3(TIMx, &TIM_OCInitStructure);
    TIM_OCInitStructure.Pulse = Channel4Pulse;
    TIM_InitOc4(TIMx, &TIM_OCInitStructure);

    // TIM_OCInitStructure.OutputNState = TIM_OUTPUT_NSTATE_DISABLE;
    TIM_OCInitStructure.Pulse = Channel2Pulse;
    TIM_InitOc2(TIMx, &TIM_OCInitStructure);
		
		// Dead-time
		TIM_BDTRInitType TIM_BDTRInitStruct;
		TIM_InitBkdtStruct(&TIM_BDTRInitStruct);
		TIM_BDTRInitStruct.DeadTime = 0x14;				//
		TIM_ConfigBkdt(TIMx,&TIM_BDTRInitStruct);
		
		//NVIC
		NVIC_InitType NVIC_InitStructure; 

		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
    NVIC_InitStructure.NVIC_IRQChannel                   = TIM1_UP_IRQn;    
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;   
    NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0;   
    NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;    
    NVIC_Init(&NVIC_InitStructure);

		TIM_ConfigInt(TIMx, TIM_INT_UPDATE, ENABLE); 
    /* TIM1 counter enable */
    TIM_Enable(TIMx, ENABLE);
		
		//TIM1->CTRL1 |= 1<<7; 
    /* TIM1 Main Output Enable */
		
    TIM_EnableCtrlPwmOutputs(TIMx, ENABLE);
		
	/*PA8  TIM1 CH1
    PA9  TIM1 CH2
    PA10 TIM1 CH3
    PB13 TIM1 CH1N
    PB14 TIM1 CH2N
    PB15 TIM1 CH3N
    PA11 TIM1 CH4
	*/
		GPIO_InitType GPIO_InitStructure;

    /* GPIOA Configuration: Channel 1, 2 and 3 as alternate function push-pull */
    GPIO_InitStructure.Pin        = GPIO_PIN_6 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);

    /* GPIOB Configuration: Channel 1N, 2N and 3N as alternate function push-pull */
    GPIO_InitStructure.Pin = GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
    GPIO_InitPeripheral(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.Pin = GPIO_PIN_11;

    GPIO_InitPeripheral(GPIOA, &GPIO_InitStructure);
}












//TIM2   Control 
void TIM2_RCC_Configuration(void)
{     
	RCC_ConfigPclk1(RCC_HCLK_DIV1);          	   
	RCC_EnableAPB1PeriphClk(RCC_APB1_PERIPH_TIM2, ENABLE);  
 	
}
void TIM2_NVIC_Configuration(void)
{		
    NVIC_InitType NVIC_InitStructure; 

		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);		// 0 1 2 3 4
	
    NVIC_InitStructure.NVIC_IRQChannel                   = TIM2_IRQn;    
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   
    NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0;   
    NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;    
    NVIC_Init(&NVIC_InitStructure);
	
}
void TIM2_TIM_Init(u16 arr, u16 psc)
{	
		TIM_TimeBaseInitType TIM_TimeBaseStructure;

    TIM2_RCC_Configuration();
    TIM2_NVIC_Configuration();

    /* Time base configuration */    
    TIM_TimeBaseStructure.Period    = arr;    
    TIM_TimeBaseStructure.Prescaler = psc;    
    TIM_TimeBaseStructure.ClkDiv    = 0;    
    TIM_TimeBaseStructure.CntMode   = TIM_CNT_MODE_UP;    
    TIM_InitTimeBase(TIM2, &TIM_TimeBaseStructure);        	 
    TIM_ConfigInt(TIM2, TIM_INT_UPDATE, ENABLE);     		   
    TIM_Enable(TIM2, ENABLE);     
	
}
