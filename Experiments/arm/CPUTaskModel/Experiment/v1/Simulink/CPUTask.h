#ifndef RTW_HEADER_CPUTask_h_
#define RTW_HEADER_CPUTask_h_
#ifndef CPUTask_COMMON_INCLUDES_
#define CPUTask_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include "CPUTask_types.h"
#include <string.h>
#include "rt_defines.h"

typedef struct {
  int32_T A[16];
  int8_T Aflag[16];
  int8_T Init;
} DW_CPUTask_T;

typedef struct {
  int32_T op;
  int32_T taskId;
  int32_T para;
} ExtU_CPUTask_T;

typedef struct {
  int32_T res;
  int32_T out;
} ExtY_CPUTask_T;

struct tag_RTM_CPUTask_T {
  DW_CPUTask_T *dwork;
};

extern void CPUTask_initialize(RT_MODEL_CPUTask_T *const CPUTask_M,
  ExtU_CPUTask_T *CPUTask_U, ExtY_CPUTask_T *CPUTask_Y);
extern void CPUTask_step(RT_MODEL_CPUTask_T *const CPUTask_M, ExtU_CPUTask_T
  *CPUTask_U, ExtY_CPUTask_T *CPUTask_Y);
extern void CPUTask_terminate(RT_MODEL_CPUTask_T *const CPUTask_M);

#endif

