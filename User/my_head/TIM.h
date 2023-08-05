


#ifndef __TIM_H__
#define __TIM_H__

#include "Include.h"

void TIM2_RCC_Configuration(void);
void TIM2_NVIC_Configuration(void);
void TIM2_TIM_Init(u16 arr, u16 psc);
void TIM_Intial(TIM_Module* TIMx);
#endif /* __TIM_H__ */
