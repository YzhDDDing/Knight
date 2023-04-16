#include "MatrixMultiply.h"
#include "rtwtypes.h"
#include <string.h>

void MatrixMultiply_step(RT_MODEL_MatrixMultiply_T *const MatrixMultiply_M, real_T MatrixMultiply_U_In2[256], real_T MatrixMultiply_U_In1[256], real_T MatrixMultiply_Y_Out1[16])
{
  B_MatrixMultiply_T *MatrixMultiply_B = MatrixMultiply_M->blockIO;
  int32_T MatrixMultiply_i_tmp;
  int32_T colIdx;
  int32_T i;
  int32_T yIdx;
  for (yIdx = 0; yIdx < 16; yIdx++) {
    for (colIdx = 0; colIdx < 16; colIdx++) {
      int32_T MatrixMultiply_i_tmp_0;
      MatrixMultiply_i_tmp = yIdx << 4;
      MatrixMultiply_i_tmp_0 = colIdx + MatrixMultiply_i_tmp;
      MatrixMultiply_B->MatrixMultiply_i[MatrixMultiply_i_tmp_0] = 0.0;
      for (i = 0; i < 16; i++) {
        MatrixMultiply_B->MatrixMultiply_i[MatrixMultiply_i_tmp_0] += MatrixMultiply_U_In2[(i << 4) + colIdx] * MatrixMultiply_U_In1[MatrixMultiply_i_tmp + i];
      }
    }
  }

  yIdx = 0;
  for (colIdx = 0; colIdx < 4; colIdx++) {
    MatrixMultiply_i_tmp = (colIdx + 12) << 4;
    MatrixMultiply_Y_Out1[yIdx] = MatrixMultiply_B->MatrixMultiply_i[MatrixMultiply_i_tmp + 12];
    MatrixMultiply_Y_Out1[yIdx + 1] = MatrixMultiply_B->MatrixMultiply_i[MatrixMultiply_i_tmp + 13];
    MatrixMultiply_Y_Out1[yIdx + 2] = MatrixMultiply_B->MatrixMultiply_i[MatrixMultiply_i_tmp + 14];
    MatrixMultiply_Y_Out1[yIdx + 3] = MatrixMultiply_B->MatrixMultiply_i[MatrixMultiply_i_tmp + 15];
    yIdx += 4;
  }
}

void MatrixMultiply_initialize(RT_MODEL_MatrixMultiply_T *const MatrixMultiply_M, real_T MatrixMultiply_U_In2[256], real_T MatrixMultiply_U_In1[256], real_T MatrixMultiply_Y_Out1[16])
{
  B_MatrixMultiply_T *MatrixMultiply_B = MatrixMultiply_M->blockIO;
  (void) memset(((void *) MatrixMultiply_B), 0,
                sizeof(B_MatrixMultiply_T));
  (void)memset(&MatrixMultiply_U_In2[0], 0, sizeof(real_T) << 8U);
  (void)memset(&MatrixMultiply_U_In1[0], 0, sizeof(real_T) << 8U);
  (void)memset(&MatrixMultiply_Y_Out1[0], 0, sizeof(real_T) << 4U);
}

void MatrixMultiply_terminate(RT_MODEL_MatrixMultiply_T *const MatrixMultiply_M)
{
  UNUSED_PARAMETER(MatrixMultiply_M);
}
