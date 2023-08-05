#ifndef __PLL_H__
#define __PLL_H__

#include "Include.h"

void DSOGI_PLL_Init(DSOGI_PLL* DsogiPLL);
void DSOGI_PLL_Process(DSOGI_PLL* DsogiPLL,TABC_DQ_STRUCT* VarAC_Volt);

#endif /* __PLL_H__ */

