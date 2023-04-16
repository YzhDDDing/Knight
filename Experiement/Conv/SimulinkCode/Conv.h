#ifndef RTW_HEADER_Conv_h_
#define RTW_HEADER_Conv_h_
#ifndef Conv_COMMON_INCLUDES_
#define Conv_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include "Conv_types.h"
#include "rt_defines.h"
#include <stddef.h>
#include <string.h>

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

typedef struct {
  real32_T Convolution_DWORK1[150];
} DW_Conv_T;

struct tag_RTM_Conv_T {
  const char_T * volatile errorStatus;
  DW_Conv_T *dwork;
};

extern void Conv_initialize(RT_MODEL_Conv_T *const Conv_M, real32_T
  Conv_U_Inport2[150], real32_T Conv_U_Inport3[10], real32_T Conv_Y_Outport[20]);
extern void Conv_step(RT_MODEL_Conv_T *const Conv_M, real32_T Conv_U_Inport2[150],
                      real32_T Conv_U_Inport3[10], real32_T Conv_Y_Outport[20]);
extern void Conv_terminate(RT_MODEL_Conv_T *const Conv_M);

#endif

