#ifndef __CONTROL_H__
#define __CONTROL_H__

#include "Include.h"

void SinCos_Calc(float32 Theta,float32* Sinx,float32* Cosx);
void Udq2SVPWM(TABC_DQ_STRUCT *ABC_DQ_Data,EPLL* Theta_data,float32 Udc,SVPWM* Tabc);
void SVPWM2Duty(SVPWM* Tabc);


#endif /* __CONTROL_H__ */
