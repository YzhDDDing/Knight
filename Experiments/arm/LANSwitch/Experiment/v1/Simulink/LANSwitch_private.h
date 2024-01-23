#ifndef RTW_HEADER_LANSwitch_private_h_
#define RTW_HEADER_LANSwitch_private_h_
#include "rtwtypes.h"
#include "LANSwitch_types.h"
#include "LANSwitch.h"

extern void LANSwitch_Error(int32_T *rty_Result, int32_T *rty_MSG);
extern void LANSwitch_FindPortInPool(int32_T rtu_PortId, int32_T *rty_Out1,
  int32_T *rtd_Found_P_e, const int32_T rtd_PortPool[256], const int32_T
  rtd_PortPoolF[256], int32_T rtp_POOL_SIZE);
extern void LANSwitch_Err(int32_T *rty_Result);

#endif

