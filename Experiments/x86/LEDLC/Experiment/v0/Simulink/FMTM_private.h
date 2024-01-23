#ifndef RTW_HEADER_FMTM_private_h_
#define RTW_HEADER_FMTM_private_h_
#include "rtwtypes.h"
#include "FMTM_types.h"
#include "FMTM.h"

extern int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator);
extern void FMTM_Error(int32_T *rty_Res, int32_T *rty_R);
extern void FMTM_FindSenserId(int32_T rtu_SenserId, int32_T *rty_Out1, int32_T
  *rtd_FoundId_o, const int32_T rtd_SenserIdData[256], const int32_T
  rtd_SenserIdUsed[256], int32_T rtp_POOL_SIZE);

#endif

