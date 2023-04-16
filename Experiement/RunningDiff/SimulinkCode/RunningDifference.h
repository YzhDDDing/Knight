#ifndef RTW_HEADER_RunningDifference_h_
#define RTW_HEADER_RunningDifference_h_
#ifndef RunningDifference_COMMON_INCLUDES_
#define RunningDifference_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include <string.h>

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

typedef struct tag_RTM RT_MODEL;
typedef struct {
  real_T Difference_PreviousValue;
  int32_T Difference_HIGHDIMS;
} DW;

struct tag_RTM {
  const char_T * volatile errorStatus;
  DW *dwork;
};

extern void RunningDifference_initialize(RT_MODEL *const rtM, real_T rtU_In1[128],
  real_T rtU_In2[128], real_T rtY_Out1[8]);
extern void RunningDifference_step(RT_MODEL *const rtM, real_T rtU_In1[128],
  real_T rtU_In2[128], real_T rtY_Out1[8]);

#endif

