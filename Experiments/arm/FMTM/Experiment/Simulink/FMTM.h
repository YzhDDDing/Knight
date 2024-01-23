#ifndef RTW_HEADER_FMTM_h_
#define RTW_HEADER_FMTM_h_
#ifndef FMTM_COMMON_INCLUDES_
#define FMTM_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include "FMTM_types.h"
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
  int32_T Merge1;
  int32_T OutportBufferForR;
  int32_T Switch_l;
  int32_T Switch_p;
} B_FMTM_T;

typedef struct {
  int32_T SenserIdData[256];
  int32_T SenserIdUsed[256];
} DW_FMTM_T;

typedef struct {
  const int32_T Constant;
} ConstB_FMTM_T;

struct tag_RTM_FMTM_T {
  const char_T * volatile errorStatus;
  B_FMTM_T *blockIO;
  DW_FMTM_T *dwork;
};

extern const ConstB_FMTM_T FMTM_ConstB;
extern void FMTM_initialize(RT_MODEL_FMTM_T *const FMTM_M, int32_T
  *FMTM_U_SenserId, int32_T *FMTM_U_Opcode, int32_T *FMTM_U_TValue, int32_T
  *FMTM_Y_Res, int32_T *FMTM_Y_R);
extern void FMTM_step(RT_MODEL_FMTM_T *const FMTM_M, int32_T FMTM_U_SenserId,
                      int32_T FMTM_U_Opcode, int32_T FMTM_U_TValue, int32_T
                      *FMTM_Y_Res, int32_T *FMTM_Y_R);
extern void FMTM_terminate(RT_MODEL_FMTM_T *const FMTM_M);

#endif

