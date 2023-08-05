#include "PLL.h"

#define Fs 10000		//Control cycle 10K
#define Kd 1				//
#define KI 1				//
//DSOGI_PLL
void DSOGI_PLL_Init(DSOGI_PLL* DsogiPLL)
{
	
}
void DSOGI_PLL_Process(DSOGI_PLL* DsogiPLL,TABC_DQ_STRUCT* VarAC_Volt)
{
	/*SOGI*/
	
	//0.707  -> k 0.5-1
	//Integral
	//0.0001 ->(1/Fs)Control cycle 
	DsogiPLL->f32Alpha += ((VarAC_Volt->f32Alpha - DsogiPLL->f32Alpha)*0.707F - DsogiPLL->f32Beta)
												*DsogiPLL->w0*0.0001F;

	DsogiPLL->f32Beta_tmp += DsogiPLL->f32Alpha*0.0001F;
	DsogiPLL->f32Beta = DsogiPLL->f32Beta_tmp*DsogiPLL->f32Theta;
	
	/*PARK*/
	DsogiPLL->f32D = DsogiPLL->f32Alpha* DsogiPLL->f32Cos_Theta + 
									 DsogiPLL->f32Beta * DsogiPLL->f32Sin_Theta;
	DsogiPLL->f32Q = DsogiPLL->f32Beta * DsogiPLL->f32Cos_Theta - 
									 DsogiPLL->f32Alpha* DsogiPLL->f32Sin_Theta;
	/*PID*/
	DsogiPLL->KI_tmp += DsogiPLL->f32Q;
	DsogiPLL->w0 = (DsogiPLL->f32Q*Kd + DsogiPLL->KI_tmp*KI) + 100*3.1415926F;
	
	DsogiPLL->f32Theta += DsogiPLL->w0 - 100*3.1415926F;	//(ToDo 
	while(DsogiPLL->f32Theta > 2*3.1415926)
	{
		DsogiPLL->f32Theta -= 2*3.1415926;
	}
	DsogiPLL->f32Sin_Theta = sin(DsogiPLL->f32Theta);
	DsogiPLL->f32Cos_Theta = cos(DsogiPLL->f32Theta);
}

