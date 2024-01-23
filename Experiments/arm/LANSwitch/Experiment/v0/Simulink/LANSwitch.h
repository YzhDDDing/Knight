#ifndef RTW_HEADER_LANSwitch_h_
#define RTW_HEADER_LANSwitch_h_
#ifndef LANSwitch_COMMON_INCLUDES_
#define LANSwitch_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include "LANSwitch_types.h"
#include <string.h>
#include "rt_defines.h"

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

typedef struct {
  int32_T OutportBufferForMSG;
  int32_T Switch;
  int32_T Switch_i;
  int32_T Switch_p;
} B_LANSwitch_T;

typedef struct {
  int32_T PortPool[256];
  int32_T PortPoolF[256];
} DW_LANSwitch_T;

typedef struct {
  const int32_T Constant;
  const int32_T Subtract1;
  const int32_T Subtract3;
  const int32_T Subtract1_m;
  const int32_T Subtract3_a;
} ConstB_LANSwitch_T;

struct tag_RTM_LANSwitch_T {
  const char_T * volatile errorStatus;
  B_LANSwitch_T *blockIO;
  DW_LANSwitch_T *dwork;
};

extern const ConstB_LANSwitch_T LANSwitch_ConstB;
extern void LANSwitch_initialize(RT_MODEL_LANSwitch_T *const LANSwitch_M,
  int32_T *LANSwitch_U_PortId, int32_T *LANSwitch_U_CMD, int32_T
  *LANSwitch_U_Arg1, int32_T *LANSwitch_U_Arg2, int32_T *LANSwitch_U_Arg3,
  int32_T *LANSwitch_Y_Result, int32_T *LANSwitch_Y_MSG);
extern void LANSwitch_step(RT_MODEL_LANSwitch_T *const LANSwitch_M, int32_T
  LANSwitch_U_PortId, int32_T LANSwitch_U_CMD, int32_T LANSwitch_U_Arg1, int32_T
  LANSwitch_U_Arg2, int32_T LANSwitch_U_Arg3, int32_T *LANSwitch_Y_Result,
  int32_T *LANSwitch_Y_MSG);
extern void LANSwitch_terminate(RT_MODEL_LANSwitch_T *const LANSwitch_M);

#endif

