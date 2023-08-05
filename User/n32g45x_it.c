/*************************** **************************************************
 * Copyright (c) 2019, Nations Technologies Inc.
 *
 * All rights reserved.
 * ****************************************************************************
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Nations' name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY NATIONS "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL NATIONS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ****************************************************************************/

/**
 * @file n32g45x_it.c
 * @author Nations
 * @version v1.0.0
 *
 * @copyright Copyright (c) 2019, Nations Technologies Inc. All rights reserved.
 */
#include "n32g45x_it.h"
#include "n32g45x.h"

#include "Include.h"
/** @addtogroup N32G45X_StdPeriph_Template
 * @{
 */

extern __IO uint32_t CurrDataCounterEnd;

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/
uint8_t i = 0;
uint16_t ii = 0;
uint16_t div = 0;
uint16_t cnt = 0;
float SINX;
float COSX;
//float32 Theta[200] = {0.00000,0.03142,0.06283,0.09425,0.12566,0.15708,0.18850,0.21991,0.25133,0.28274,0.31416,0.34558,0.37699,0.40841,0.43982,0.47124,0.50265,0.53407,0.56549,0.59690,0.62832,0.65973,0.69115,0.72257,0.75398,0.78540,0.81681,0.84823,0.87965,0.91106,0.94248,0.97389,1.00531,1.03673,1.06814,1.09956,1.13097,1.16239,1.19381,1.22522,1.25664,1.28805,1.31947,1.35088,1.38230,1.41372,1.44513,1.47655,1.50796,1.53938,1.57080,1.60221,1.63363,1.66504,1.69646,1.72788,1.75929,1.79071,1.82212,1.85354,1.88496,1.91637,1.94779,1.97920,2.01062,2.04204,2.07345,2.10487,2.13628,2.16770,2.19911,2.23053,2.26195,2.29336,2.32478,2.35619,2.38761,2.41903,2.45044,2.48186,2.51327,2.54469,2.57611,2.60752,2.63894,2.67035,2.70177,2.73319,2.76460,2.79602,2.82743,2.85885,2.89027,2.92168,2.95310,2.98451,3.01593,3.04734,3.07876,3.11018,3.14159,3.17301,3.20442,3.23584,3.26726,3.29867,3.33009,3.36150,3.39292,3.42434,3.45575,3.48717,3.51858,3.55000,3.58142,3.61283,3.64425,3.67566,3.70708,3.73850,3.76991,3.80133,3.83274,3.86416,3.89557,3.92699,3.95841,3.98982,4.02124,4.05265,4.08407,4.11549,4.14690,4.17832,4.20973,4.24115,4.27257,4.30398,4.33540,4.36681,4.39823,4.42965,4.46106,4.49248,4.52389,4.55531,4.58673,4.61814,4.64956,4.68097,4.71239,4.74380,4.77522,4.80664,4.83805,4.86947,4.90088,4.93230,4.96372,4.99513,5.02655,5.05796,5.08938,5.12080,5.15221,5.18363,5.21504,5.24646,5.27788,5.30929,5.34071,5.37212,5.40354,5.43496,5.46637,5.49779,5.52920,5.56062,5.59203,5.62345,5.65487,5.68628,5.71770,5.74911,5.78053,5.81195,5.84336,5.87478,5.90619,5.93761,5.96903,6.00044,6.03186,6.06327,6.09469,6.12611,6.15752,6.18894,6.22035,6.25177};
float32 Theta400[400] = {0.00000,0.01571,0.03142,0.04712,0.06283,0.07854,0.09425,0.10996,0.12566,0.14137,0.15708,0.17279,0.18850,0.20420,0.21991,0.23562,0.25133,0.26704,0.28274,0.29845,0.31416,0.32987,0.34558,0.36128,0.37699,0.39270,0.40841,0.42412,0.43982,0.45553,0.47124,0.48695,0.50265,0.51836,0.53407,0.54978,0.56549,0.58119,0.59690,0.61261,0.62832,0.64403,0.65973,0.67544,0.69115,0.70686,0.72257,0.73827,0.75398,0.76969,0.78540,0.80111,0.81681,0.83252,0.84823,0.86394,0.87965,0.89535,0.91106,0.92677,0.94248,0.95819,0.97389,0.98960,1.00531,1.02102,1.03673,1.05243,1.06814,1.08385,1.09956,1.11527,1.13097,1.14668,1.16239,1.17810,1.19381,1.20951,1.22522,1.24093,1.25664,1.27235,1.28805,1.30376,1.31947,1.33518,1.35088,1.36659,1.38230,1.39801,1.41372,1.42942,1.44513,1.46084,1.47655,1.49226,1.50796,1.52367,1.53938,1.55509,1.57080,1.58650,1.60221,1.61792,1.63363,1.64934,1.66504,1.68075,1.69646,1.71217,1.72788,1.74358,1.75929,1.77500,1.79071,1.80642,1.82212,1.83783,1.85354,1.86925,1.88496,1.90066,1.91637,1.93208,1.94779,1.96350,1.97920,1.99491,2.01062,2.02633,2.04204,2.05774,2.07345,2.08916,2.10487,2.12058,2.13628,2.15199,2.16770,2.18341,2.19911,2.21482,2.23053,2.24624,2.26195,2.27765,2.29336,2.30907,2.32478,2.34049,2.35619,2.37190,2.38761,2.40332,2.41903,2.43473,2.45044,2.46615,2.48186,2.49757,2.51327,2.52898,2.54469,2.56040,2.57611,2.59181,2.60752,2.62323,2.63894,2.65465,2.67035,2.68606,2.70177,2.71748,2.73319,2.74889,2.76460,2.78031,2.79602,2.81173,2.82743,2.84314,2.85885,2.87456,2.89027,2.90597,2.92168,2.93739,2.95310,2.96881,2.98451,3.00022,3.01593,3.03164,3.04734,3.06305,3.07876,3.09447,3.11018,3.12588,3.14159,3.15730,3.17301,3.18872,3.20442,3.22013,3.23584,3.25155,3.26726,3.28296,3.29867,3.31438,3.33009,3.34580,3.36150,3.37721,3.39292,3.40863,3.42434,3.44004,3.45575,3.47146,3.48717,3.50288,3.51858,3.53429,3.55000,3.56571,3.58142,3.59712,3.61283,3.62854,3.64425,3.65996,3.67566,3.69137,3.70708,3.72279,3.73850,3.75420,3.76991,3.78562,3.80133,3.81704,3.83274,3.84845,3.86416,3.87987,3.89557,3.91128,3.92699,3.94270,3.95841,3.97411,3.98982,4.00553,4.02124,4.03695,4.05265,4.06836,4.08407,4.09978,4.11549,4.13119,4.14690,4.16261,4.17832,4.19403,4.20973,4.22544,4.24115,4.25686,4.27257,4.28827,4.30398,4.31969,4.33540,4.35111,4.36681,4.38252,4.39823,4.41394,4.42965,4.44535,4.46106,4.47677,4.49248,4.50819,4.52389,4.53960,4.55531,4.57102,4.58673,4.60243,4.61814,4.63385,4.64956,4.66527,4.68097,4.69668,4.71239,4.72810,4.74380,4.75951,4.77522,4.79093,4.80664,4.82234,4.83805,4.85376,4.86947,4.88518,4.90088,4.91659,4.93230,4.94801,4.96372,4.97942,4.99513,5.01084,5.02655,5.04226,5.05796,5.07367,5.08938,5.10509,5.12080,5.13650,5.15221,5.16792,5.18363,5.19934,5.21504,5.23075,5.24646,5.26217,5.27788,5.29358,5.30929,5.32500,5.34071,5.35642,5.37212,5.38783,5.40354,5.41925,5.43496,5.45066,5.46637,5.48208,5.49779,5.51350,5.52920,5.54491,5.56062,5.57633,5.59203,5.60774,5.62345,5.63916,5.65487,5.67057,5.68628,5.70199,5.71770,5.73341,5.74911,5.76482,5.78053,5.79624,5.81195,5.82765,5.84336,5.85907,5.87478,5.89049,5.90619,5.92190,5.93761,5.95332,5.96903,5.98473,6.00044,6.01615,6.03186,6.04757,6.06327,6.07898,6.09469,6.11040,6.12611,6.14181,6.15752,6.17323,6.18894,6.20465,6.22035,6.23606,6.25177,6.26748};

void TIM1_UP_IRQHandler(void)
{    
		if(TIM1->STS&0X0001)
		{		
				
//				TIM1->CCDAT1 = ii;
//				TIM1->CCDAT2 = 100-ii;
//				TIM1->CCDAT3 = i+1;
			
				if(i) GPIO_SetBits(GPIOC, GPIO_PIN_13);
				else GPIO_ResetBits(GPIOC, GPIO_PIN_13);
				i = 1-i;
//				if(ii >= 100)
//					ii = 0;
//				else
//					ii++;
				ABC_DQ_Data.f32D = 1;
				ABC_DQ_Data.f32Q = 0;
				Theta_data.f32Theta = Theta400[cnt];
				Theta_data.f32Sin_Theta = sinf(Theta_data.f32Theta);
				Theta_data.f32Cos_Theta = cosf(Theta_data.f32Theta);

				//iPark_DQ2AlphaBeta(&ABC_DQ_Data,Theta_data.f32Sin_Theta,Theta_data.f32Cos_Theta);
			//				ABC_DQ_Data.2;
			
				Udq2SVPWM(&ABC_DQ_Data,&Theta_data,0,&Tabc);
				SVPWM2Duty(&Tabc);

				if(ii < 400)
				{
					UART_Buffer[ii] = Tabc.Ta*100;
					ii++;
				}

//			cnt = 0;
//			TIM1->CCDAT1 = 100;		//change duty
//			TIM1->CCDAT1 = 50;

			if(cnt >= 399)	//199
			{
				cnt = 0;
			}
			else
			{
				cnt++;
			}
				

		}
		TIM1->STS &= ~(1<<0);	//clear
}
/**
 * @brief  This function handles NMI exception.
 */
void NMI_Handler(void)
{
}

/**
 * @brief  This function handles Hard Fault exception.
 */
void HardFault_Handler(void)
{
    /* Go to infinite loop when Hard Fault exception occurs */
    while (1)
    {
    }
}

/**
 * @brief  This function handles Memory Manage exception.
 */
void MemManage_Handler(void)
{
    /* Go to infinite loop when Memory Manage exception occurs */
    while (1)
    {
    }
}

/**
 * @brief  This function handles Bus Fault exception.
 */
void BusFault_Handler(void)
{
    /* Go to infinite loop when Bus Fault exception occurs */
    while (1)
    {
    }
}

/**
 * @brief  This function handles Usage Fault exception.
 */
void UsageFault_Handler(void)
{
    /* Go to infinite loop when Usage Fault exception occurs */
    while (1)
    {
    }
}

/**
 * @brief  This function handles SVCall exception.
 */
void SVC_Handler(void)
{
}

/**
 * @brief  This function handles Debug Monitor exception.
 */
void DebugMon_Handler(void)
{
}

/**
 * @brief  This function handles SysTick Handler.
 */
void SysTick_Handler(void)
{
}

/**
 * @brief  This function handles DMA interrupt request defined in main.h .
 */
void DMA_IRQ_HANDLER(void)
{
}

/******************************************************************************/
/*                 N32G45X Peripherals Interrupt Handlers                     */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_n32g45x.s).                                                 */
/******************************************************************************/

/**
 * @brief  This function handles PPP interrupt request.
 */
/*void PPP_IRQHandler(void)
{
}*/

/**
 * @}
 */
