#ifndef RTW_HEADER_MatrixMultiply_h_
#define RTW_HEADER_MatrixMultiply_h_
#ifndef MatrixMultiply_COMMON_INCLUDES_
#define MatrixMultiply_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include "MatrixMultiply_types.h"
#include <string.h>
#include "rt_defines.h"

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

typedef struct {
  real_T MatrixMultiply_i[256];
} B_MatrixMultiply_T;

struct tag_RTM_MatrixMultiply_T {
  const char_T * volatile errorStatus;
  B_MatrixMultiply_T *blockIO;
};

extern void MatrixMultiply_initialize(RT_MODEL_MatrixMultiply_T *const MatrixMultiply_M, real_T MatrixMultiply_U_In2[256], real_T MatrixMultiply_U_In1[256], real_T MatrixMultiply_Y_Out1[16]);
extern void MatrixMultiply_step(RT_MODEL_MatrixMultiply_T *const MatrixMultiply_M, real_T MatrixMultiply_U_In2[256], real_T MatrixMultiply_U_In1[256], real_T MatrixMultiply_Y_Out1[16]);
extern void MatrixMultiply_terminate(RT_MODEL_MatrixMultiply_T *const MatrixMultiply_M);

#endif

