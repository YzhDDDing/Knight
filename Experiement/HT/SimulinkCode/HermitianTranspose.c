#include "HermitianTranspose.h"
#include <string.h>
#include "rtwtypes.h"

void HermitianTranspose_step(RT_MODEL_HermitianTranspose_T *const HermitianTranspose_M, real_T HermitianTranspose_U_In2[256], real_T HermitianTranspose_Y_Out1[64])
{
  B_HermitianTranspose_T *HermitianTranspose_B = HermitianTranspose_M->blockIO;
  int32_T colIdx;
  int32_T yIdx;
  for (yIdx = 0; yIdx < 16; yIdx++) {
    for (colIdx = 0; colIdx < 16; colIdx++) {
      HermitianTranspose_B->MathFunction[colIdx + (yIdx << 4)] = HermitianTranspose_U_In2[(colIdx << 4) + yIdx];
    }
  }

  yIdx = 0;
  for (colIdx = 0; colIdx < 8; colIdx++) {
    memcpy(&HermitianTranspose_Y_Out1[yIdx], &HermitianTranspose_B->MathFunction[colIdx << 4], sizeof(real_T) << 3U);
    yIdx += 8;
  }
}

void HermitianTranspose_initialize(RT_MODEL_HermitianTranspose_T *const HermitianTranspose_M, real_T HermitianTranspose_U_In2[256], real_T HermitianTranspose_Y_Out1[64])
{
  B_HermitianTranspose_T *HermitianTranspose_B = HermitianTranspose_M->blockIO;
  (void) memset(((void *) HermitianTranspose_B), 0,
                sizeof(B_HermitianTranspose_T));
  (void)memset(&HermitianTranspose_U_In2[0], 0, sizeof(real_T) << 8U);
  (void)memset(&HermitianTranspose_Y_Out1[0], 0, sizeof(real_T) << 6U);
}

void HermitianTranspose_terminate(RT_MODEL_HermitianTranspose_T *const HermitianTranspose_M)
{
  UNUSED_PARAMETER(HermitianTranspose_M);
}
