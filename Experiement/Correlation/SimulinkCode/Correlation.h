#ifndef RTW_HEADER_Correlation_h_
#define RTW_HEADER_Correlation_h_
#ifndef Correlation_COMMON_INCLUDES_
#define Correlation_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include <stddef.h>
#include <string.h>

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

typedef struct tag_RTM RT_MODEL;
typedef struct {
  real32_T Correlation_DWORK1[10];
} DW;

struct tag_RTM {
  const char_T * volatile errorStatus;
  DW *dwork;
};

extern void Correlation_initialize(RT_MODEL *const rtM, real32_T rtU_Inport[10],
  real32_T rtU_Inport1[240], real32_T rtY_Output[20]);
extern void Correlation_step(RT_MODEL *const rtM, real32_T rtU_Inport[10],
  real32_T rtU_Inport1[240], real32_T rtY_Output[20]);

#endif

