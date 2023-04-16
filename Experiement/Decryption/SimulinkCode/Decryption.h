#ifndef RTW_HEADER_Decryption_h_
#define RTW_HEADER_Decryption_h_
#ifndef Decryption_COMMON_INCLUDES_
#define Decryption_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include <stddef.h>

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

typedef struct tag_RTM RT_MODEL;
struct tag_RTM {
  const char_T * volatile errorStatus;
};

extern void Decryption_initialize(RT_MODEL *const rtM, int32_T rtU_In1[256],
  int32_T rtU_In2[512], int32_T *rtU_In3, int32_T rtY_Output[16]);
extern void Decryption_step(RT_MODEL *const rtM, int32_T rtU_In1[256], int32_T
  rtU_In2[512], int32_T rtU_In3, int32_T rtY_Output[16]);

#endif

