#ifndef RTW_HEADER_HighPass_h_
#define RTW_HEADER_HighPass_h_
#ifndef HighPass_COMMON_INCLUDES_
#define HighPass_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

typedef struct tag_RTM RT_MODEL;
typedef struct {
  real_T S1[32];
  real_T S2[32];
  real_T S3[32];
} DW;

struct tag_RTM {
  const char_T * volatile errorStatus;
  DW *dwork;
};

extern void HighPass_initialize(RT_MODEL *const rtM);
extern void HighPass_step(RT_MODEL *const rtM, real_T rtU_signal1[32], real_T
  rtU_signal2[32], real_T rtU_signal3[32], real_T rtY_signal_o1[32], real_T
  rtY_signal_o2[32], real_T rtY_signal_o3[32]);

#endif

