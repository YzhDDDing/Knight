#ifndef RTW_HEADER_Diffsion_h_
#define RTW_HEADER_Diffsion_h_
#ifndef Diffsion_COMMON_INCLUDES_
#define Diffsion_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include "Diffsion_types.h"
#include <string.h>
#include "rt_defines.h"

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

typedef struct {
  int32_T Di_m1[32];
  int32_T Di_m2[32];
} DW_Diffsion_T;

struct tag_RTM_Diffsion_T {
  const char_T * volatile errorStatus;
  DW_Diffsion_T *dwork;
};

extern void Diffsion_initialize(RT_MODEL_Diffsion_T *const Diffsion_M, int32_T
  *Diffsion_U_Inport, int32_T Diffsion_Y_Outport[32]);
extern void Diffsion_step(RT_MODEL_Diffsion_T *const Diffsion_M, int32_T
  Diffsion_U_Inport, int32_T Diffsion_Y_Outport[32]);
extern void Diffsion_terminate(RT_MODEL_Diffsion_T *const Diffsion_M);

#endif

