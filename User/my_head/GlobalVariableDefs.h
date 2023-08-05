#ifndef __GlobalVariableDefs_H__
#define __GlobalVariableDefs_H__

#include "Include.h"

/***************************************************************************
*            Variables Definition
***************************************************************************/
struct IsrVarsStruct
{
//int16     _i16AdVdcDis;
//int16	  _i16VdcSet;
//int16	  _i16AdVdcSam0;        
//int16     _i16AdVdcSam1;         
////longunion _lVdcDisUse; 
////longunion _lVdcUse;
//int16     _i16VdcErr0;           
//int16 	  _i16VdcErr1;  
//int16     _i16VdcLoopK3;     
//int16     _i16VdcLoopK4;          
//int16     _i16AdIdcDis;
//int16     _i16AdIdc;
////longunion _lIdcDisUse;
//Uint16    _u16IsrTimer;    
//Uint16    u16Flag_S00_T11;
//int32		l32SR_DC_FED_AHEAD;
//float32	  f32Vin;
//float32	  f32Vo;
//float32	  f32Vin_Vo;
//float32	  f32SRDelay;
//int32		l32SR_DC_FED_DELAY;
//int16		i16SROnDelay;
//int16		i16SROffDelay;
//int16	  i16AdVpfc0;
//int16	  i16AdVpfc1;
//int16     i16VpfcSet;
//Uint16    _i16PFCQuickLoopForce;
//Uint16    _u16VpfcPara;//in use
//int16 	_i16VpfcFilterK2;
//longunion _lVpfcFilterK1;
//longunion _lVpfcUse;
//float32     f32AcAVolt;
//float32     f32AcBVolt;
//float32     f32AcCVolt;
////-------------offset=0060H------------------------		
//Uint16    _u16160usTimer;
//Uint16	  _u16MainRly_160usTimer;
//Uint16    _u16SoftStartEndTimer;//count for dc soft start end
//int16     _i16AdAcMax;//in use
//Uint16    _u16PfcQuickLoop;//in use
//Uint16    _u16QuickAcLimt;
//Uint16	  _u16ADU1Temp;
//Uint16	  _u16ADDCTemp;
//Uint16	  _u16ADPFCTemp;
//longunion _lU1Temp;
//longunion _lPFCTemp;
////--------------offset=0070H------------------------
//longunion _lVBATUse;
//longunion l32IdcBatDisUse;
//int16     _i16AdVBATSam0;
//int16     i16AdIdcBatDis;
//int16     i16AdIdcBat;
//Uint16    u16RelayA;
//Uint16    u16RelayC;
//Uint16    u16RelayCCloseflag;
//Uint16    u16RelayACloseflag;
//Uint16    u16DBSoftStart;
//INT16   i16CurD;
//INT16   i16CurQ;
//INT16   i16CurDRef;
//INT16   i16CurQRef;
//int16     _reservePFCISR;
int16       i16AcAVolt;
int16       i16AcBVolt;
int16       i16AcCVolt;
//UINT16          u16RelayATimer;
//UINT16          u16RelayCTimer;
float32   f32PfcACurr;
float32   f32PfcBCurr;
float32   f32PfcCCurr;


//INT32           LQ10AcABVoltRmsTmpUse1;
//INT32           LQ10AcABVoltRmsTmpUse2;
//INT32           LQ10AcABVoltRmsUse;
//UINT16      u16AcABVoltUse;
//UINT16      u16AcABVoltUse1;
//UINT16      u16AcABVoltRmsUse;
//UINT16      u16VacAMax;

//INT32           LQ10AcBCVoltRmsTmpUse1;
//INT32           LQ10AcBCVoltRmsTmpUse2;
//INT32           LQ10AcBCVoltRmsUse;
//UINT16      u16AcBCVoltUse;
//UINT16      u16AcBCVoltUse1;
//UINT16      u16AcBCVoltRmsUse;
//UINT16      u16VacBMax;

//INT32           LQ10AcCAVoltRmsTmpUse1;
//INT32           LQ10AcCAVoltRmsTmpUse2;
//INT32           LQ10AcCAVoltRmsUse;
//UINT16      u16AcCAVoltUse;
//UINT16      u16AcCAVoltUse1;
//UINT16      u16AcCAVoltRmsUse;
//UINT16      u16VacCMax;

//INT32       LQ24AcFiltK2;
//float32     f32VrefMag;

};   




#endif /* __GlobalVariableDefs_H__ */
