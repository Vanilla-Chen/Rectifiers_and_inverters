#include "Control.h"

void SinCos_Calc(float32 Theta,float32* Sinx,float32* Cosx)
{
	*Sinx = sinf(Theta);
	*Cosx = cosf(Theta);
}
void Udq2Uab(TABC_DQ_STRUCT* ABC_DQ_Data,EPLL* Theta_data)
{
	iPark_DQ2AlphaBeta(ABC_DQ_Data,
										Theta_data->f32Sin_Theta,
										Theta_data->f32Cos_Theta);
}

//9.458us
void Udq2SVPWM(TABC_DQ_STRUCT* ABC_DQ_Data,EPLL* Theta_data,float32 Udc,SVPWM* Tabc)
{
		Udq2Uab(ABC_DQ_Data,Theta_data);
	
		//Uab2SVPWM
		float32 Add1;
		float32 Add2;
	
		//float32 tmpA;
		float32 tmpB;
		float32 tmpC;
	
//		ABC_DQ_Data->f32Alpha;
//		ABC_DQ_Data->f32Beta;
		
		Add1 = 0.5F * ABC_DQ_Data->f32Alpha;				//			1/2 * a
		Add2 = 0.866025388F * ABC_DQ_Data->f32Beta;	//sqrt(3)/2 * b
		
		//abc
		//tmpA = ABC_DQ_Data->f32Alpha;;
		tmpB = Add2 - Add1;
		tmpC = - Add2 - Add1;
		
		Add2 = (fmaxf(fmaxf(ABC_DQ_Data->f32Alpha,tmpB),tmpC) + 
					 fminf(fminf(ABC_DQ_Data->f32Alpha,tmpB),tmpC)) 
					 * -0.5F;					
		//(ToDo Tabc-Limit
//		Tabc->Ta = ((ABC_DQ_Data->f32Alpha + Add2) * 1.15470053) / 2.0F + 0.5F;	//
//		Tabc->Tb = ((tmpB + Add2) * 1.15470053) / 2.0F + 0.5F;
//		Tabc->Tc = ((tmpC + Add2) * 1.15470053) / 2.0F + 0.5F;
		
		Tabc->Ta = ((ABC_DQ_Data->f32Alpha + Add2) * 0.5773502691) + 0.5F;	//
		Tabc->Tb = ((tmpB + Add2) * 0.5773502691) + 0.5F;
		Tabc->Tc = ((tmpC + Add2) * 0.5773502691) + 0.5F;
		//0.5773502691
		//Tabc 0-1
}

void SVPWM2Duty(SVPWM* Tabc)
{
//		static uint16_t i = 0;
//		
//		TIM1->CCDAT1 = i;
//		TIM1->CCDAT2 = 100-i;
//		TIM1->CCDAT3 = 50;
//		
//		if(i >= 100)
//			i = 0;
//		else
//			i++;
	
		TIM1->CCDAT1 = (uint8_t)((Tabc->Ta)*100.0f);
		TIM1->CCDAT2 = (uint8_t)((Tabc->Tb)*100.0f);
		TIM1->CCDAT3 = (uint8_t)((Tabc->Tc)*100.0f);
	
//	TIM1->CCDAT1 = 100;
//	TIM1->CCDAT2 = 99;
//	TIM1->CCDAT3 = 98;

}
