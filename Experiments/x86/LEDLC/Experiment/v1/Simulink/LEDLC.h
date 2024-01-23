#ifndef RTW_HEADER_LEDLC_h_
#define RTW_HEADER_LEDLC_h_
#ifndef LEDLC_COMMON_INCLUDES_
#define LEDLC_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include "LEDLC_types.h"
#include <string.h>
#include "rt_defines.h"

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

typedef struct {
  int32_T Merge;
  int32_T Switch;
} B_LEDLC_T;

typedef struct {
  real32_T Data[64];
  int32_T Error;
  int32_T Init;
  int32_T Terminate;
  int32_T Satisfied[64];
  int32_T State;
} DW_LEDLC_T;

struct tag_RTM_LEDLC_T {
  const char_T * volatile errorStatus;
  B_LEDLC_T *blockIO;
  DW_LEDLC_T *dwork;
};

extern void LEDLC_initialize(RT_MODEL_LEDLC_T *const LEDLC_M, real32_T
  *LEDLC_U_t, int32_T *LEDLC_Y_Output);
extern void LEDLC_step(RT_MODEL_LEDLC_T *const LEDLC_M, real32_T LEDLC_U_t,
  int32_T *LEDLC_Y_Output);
extern void LEDLC_terminate(RT_MODEL_LEDLC_T *const LEDLC_M);

#endif

