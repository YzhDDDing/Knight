#ifndef RTW_HEADER_RoboticArmController_h_
#define RTW_HEADER_RoboticArmController_h_
#ifndef RoboticArmController_COMMON_INCLUDES_
#define RoboticArmController_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include "RoboticArmController_types.h"
#include <string.h>
#include "rt_defines.h"

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

typedef struct {
  int32_T OutportBufferForB;
  int32_T OutportBufferForB_k;
  int32_T OutportBufferForB_ky;
  int32_T Switch;
  int32_T Switch_i;
  int32_T Switch_l;
  int32_T Switch_p;
} B_RoboticArmController_T;

typedef struct {
  int32_T ArmIdPool[128];
  int32_T ArmIdPoolF[128];
} DW_RoboticArmController_T;

typedef struct {
  const int32_T Constant;
  const int32_T Constant_g;
  const int32_T Constant_l;
} ConstB_RoboticArmController_T;

struct tag_RTM_RoboticArmController_T {
  const char_T * volatile errorStatus;
  B_RoboticArmController_T *blockIO;
  DW_RoboticArmController_T *dwork;
};

extern const ConstB_RoboticArmController_T RoboticArmController_ConstB;
extern void RoboticArmController_initialize(RT_MODEL_RoboticArmController_T *
  const RoboticArmController_M, int32_T *RoboticArmController_U_ArmId, int32_T
  *RoboticArmController_U_Op, int32_T *RoboticArmController_U_P1, int32_T
  *RoboticArmController_U_P2, int32_T *RoboticArmController_U_P3, int32_T
  *RoboticArmController_Y_Res, int32_T *RoboticArmController_Y_B);
extern void RoboticArmController_step(RT_MODEL_RoboticArmController_T *const
  RoboticArmController_M, int32_T RoboticArmController_U_ArmId, int32_T
  RoboticArmController_U_Op, int32_T RoboticArmController_U_P1, int32_T
  RoboticArmController_U_P2, int32_T RoboticArmController_U_P3, int32_T
  *RoboticArmController_Y_Res, int32_T *RoboticArmController_Y_B);
extern void RoboticArmController_terminate(RT_MODEL_RoboticArmController_T *
  const RoboticArmController_M);

#endif

