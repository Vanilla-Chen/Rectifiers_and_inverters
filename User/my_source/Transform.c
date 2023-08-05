#include <Transform.h>






void Clark_ABC2AlphaBeta(TABC_DQ_STRUCT *ABC_DQ_Data)//Clark
{
    ABC_DQ_Data->f32Alpha = (ABC_DQ_Data->f32phA * 2.0f - ABC_DQ_Data->f32phB - ABC_DQ_Data->f32phC) / 3.0f;
    ABC_DQ_Data->f32Beta = (ABC_DQ_Data->f32phB - ABC_DQ_Data->f32phC) / 1.7320508f;
}

void Park_AlphaBeta2DQ(TABC_DQ_STRUCT *ABC_DQ_Data, float32 SINx, float32 COSx)//Park
{
    ABC_DQ_Data->f32D = ABC_DQ_Data->f32Alpha * COSx + ABC_DQ_Data->f32Beta * SINx;
    ABC_DQ_Data->f32Q = ABC_DQ_Data->f32Beta * COSx - ABC_DQ_Data->f32Alpha * SINx;
}

void iPark_DQ2AlphaBeta(TABC_DQ_STRUCT *ABC_DQ_Data, float32 SINx, float32 COSx)//iPark
{
    ABC_DQ_Data->f32Alpha = ABC_DQ_Data->f32D * COSx - ABC_DQ_Data->f32Q * SINx;
    ABC_DQ_Data->f32Beta  = ABC_DQ_Data->f32D * SINx + ABC_DQ_Data->f32Q * COSx;
}
