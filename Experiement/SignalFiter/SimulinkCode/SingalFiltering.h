#ifndef RTW_HEADER_SingalFiltering_h_
#define RTW_HEADER_SingalFiltering_h_
#ifndef SingalFiltering_COMMON_INCLUDES_
#define SingalFiltering_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include "SingalFiltering_types.h"
#include <string.h>
#include "rt_defines.h"

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

typedef struct {
  int32_T signal[64];
} DW_SingalFiltering_T;

struct tag_RTM_SingalFiltering_T {
  const char_T * volatile errorStatus;
  DW_SingalFiltering_T *dwork;
};

extern void SingalFiltering_initialize(RT_MODEL_SingalFiltering_T *const
  SingalFiltering_M, int32_T SingalFiltering_U_Inport[32], int32_T
  SingalFiltering_Y_Output[64]);
extern void SingalFiltering_step(RT_MODEL_SingalFiltering_T *const
  SingalFiltering_M, int32_T SingalFiltering_U_Inport[32], int32_T
  SingalFiltering_Y_Output[64]);
extern void SingalFiltering_terminate(RT_MODEL_SingalFiltering_T *const
  SingalFiltering_M);

#endif

