#ifndef __Include_H__
#define __Include_H__

#include "n32g45x.h"
#include "math.h"


typedef short             	int16;
typedef long            		int32;
typedef long long						int64;
typedef unsigned short    	Uint16;
typedef unsigned long   		Uint32;
typedef unsigned long long	Uint64;
typedef float           		float32;
typedef long double     		float64;

typedef unsigned short			UINT16;
typedef short								INT16;
typedef long        				INT32;
typedef unsigned long   		UINT32;
typedef float           		FLOAT32;
typedef long double     		FLOAT64;


typedef struct
{
    float32 f32phA;   // Phase A Voltage or Current etc.
    float32 f32phB;   // Phase B Voltage or Current etc.
    float32 f32phC;   // Phase C Voltage or Current etc.
    float32 f32Beta;  // Phase Q Stationary Voltage or Current etc.
    float32 f32Alpha;  // Phase D Stationary Voltage or Current etc.
    float32 f32Q;  // Phase Q Rotating Voltage or Current etc.
    float32 f32D;  // Phase D Rotating Voltage or Current etc.
}TABC_DQ_STRUCT;

typedef struct 
{
//	float32  f32Ku1;			// for Amplitude. Ku1 = k1* del_ts. time constant=2/K1
//	float32  f32Ku2;			// Ku2
//	float32  f32Ku3;			// Ku3
//	float32  f32Verr;			// Error
//	float32  f32Vamp_Est;   	// Estimate Amplitude
//	float32  f32W_CONST;		// Center Grid frequency: rad/s
//	float32  f32deltaW_Est;   			// Input: Feedback input
	float32  f32Theta;   		// Output: PID output
//	float32  f32Theta_pu;		//
//	float32  f32Theta_Active;		// Theta for Sin
//	float32  f32Theta_Act_pu;		//
	float32  f32Sin_Theta;		// sin value for ePLL
	float32  f32Cos_Theta;		// cos value for ePLL
//	float32  f32Tcal ;			// PLL calculation frequency
//	int16	i16Vac_ADC;
//	int16	i16Vac_Est;
//	Uint16	u16ErrCnt;
}EPLL;
typedef struct 
{
	float32  	f32Theta;
	float32  	f32Sin_Theta;
	float32  	f32Cos_Theta;
	//SOGI
	float32		f32Alpha;			//D	0
	float32 	f32Beta;			//Q 90
	float32 	f32Beta_tmp;	//Q integral 
	float32 	w0;				//Q 90
	//PARK
	float32		f32D;			//D	0
	float32 	f32Q;			//Q 90
	//PID
	float32		KI_tmp;		//PID Integral para
	
}
DSOGI_PLL;
typedef struct 
{
	float32 Ta;
	float32 Tb;
	float32 Tc;
}SVPWM;


#include "UART.h"
#include "TIM.h"
#include "ADC.h"
#include "Control.h"
#include "Transform.h"
#include "PLL.h"

extern TABC_DQ_STRUCT 	ABC_DQ_Data;
extern EPLL 						Theta_data;
extern SVPWM 					Tabc;
extern uint16_t UART_Buffer[400];
extern uint16_t ii;
#endif /* __Include_H__ */
