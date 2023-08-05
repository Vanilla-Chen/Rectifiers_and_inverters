#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include "Include.h"






void Clark_ABC2AlphaBeta(TABC_DQ_STRUCT *ABC_DQ_Data);//Clark
void Park_AlphaBeta2DQ(TABC_DQ_STRUCT *ABC_DQ_Data, float32 SINx, float32 COSx);//Park
void iPark_DQ2AlphaBeta(TABC_DQ_STRUCT *ABC_DQ_Data, float32 SINx, float32 COSx);//iPark




#endif /* __TRANSFORM_H__ */
