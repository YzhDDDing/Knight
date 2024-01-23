#ifndef RTW_HEADER_HybridFilter_h_
#define RTW_HEADER_HybridFilter_h_
#ifndef HybridFilter_COMMON_INCLUDES_
#define HybridFilter_COMMON_INCLUDES_
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
  real_T S1[32];
  real_T S2[32];
  real_T S3[32];
} DW;

struct tag_RTM {
  const char_T * volatile errorStatus;
  DW *dwork;
};

extern void HybridFilter_initialize(RT_MODEL *const rtM, real_T rtU_signal1[32],
  real_T rtU_signal2[32], real_T rtU_signal3[32], real_T rtY_signal_h1[32],
  real_T rtY_signal_h2[32], real_T rtY_signal_h3[32], real_T rtY_signal_l1[32],
  real_T rtY_signal_l2[32], real_T rtY_signal_l3[32]);
extern void HybridFilter_step(RT_MODEL *const rtM, real_T rtU_signal1[32],
  real_T rtU_signal2[32], real_T rtU_signal3[32], real_T rtY_signal_h1[32],
  real_T rtY_signal_h2[32], real_T rtY_signal_h3[32], real_T rtY_signal_l1[32],
  real_T rtY_signal_l2[32], real_T rtY_signal_l3[32]);

#endif

