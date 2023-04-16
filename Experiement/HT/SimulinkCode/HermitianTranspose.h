#ifndef RTW_HEADER_HermitianTranspose_h_
#define RTW_HEADER_HermitianTranspose_h_
#ifndef HermitianTranspose_COMMON_INCLUDES_
#define HermitianTranspose_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include "HermitianTranspose_types.h"
#include <string.h>
#include "rt_defines.h"

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

typedef struct {
  real_T MathFunction[256];
} B_HermitianTranspose_T;

struct tag_RTM_HermitianTranspose_T {
  const char_T * volatile errorStatus;
  B_HermitianTranspose_T *blockIO;
};

extern void HermitianTranspose_initialize(RT_MODEL_HermitianTranspose_T *const HermitianTranspose_M, real_T HermitianTranspose_U_In2[256], real_T HermitianTranspose_Y_Out1[64]);
extern void HermitianTranspose_step(RT_MODEL_HermitianTranspose_T *const HermitianTranspose_M, real_T HermitianTranspose_U_In2[256], real_T HermitianTranspose_Y_Out1[64]);
extern void HermitianTranspose_terminate(RT_MODEL_HermitianTranspose_T *const HermitianTranspose_M);

#endif

