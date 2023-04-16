#include "SingalFiltering.h"
#include <string.h>
#include "rtwtypes.h"

void SingalFiltering_step(RT_MODEL_SingalFiltering_T *const SingalFiltering_M,
  int32_T SingalFiltering_U_Inport[32], int32_T SingalFiltering_Y_Output[64])
{
  DW_SingalFiltering_T *SingalFiltering_DW = SingalFiltering_M->dwork;
  int32_T rtb_Assignment[64];
  int32_T i;
  int32_T s1_iter;
  for (s1_iter = 0; s1_iter < 32; s1_iter++) {
    if (s1_iter == 0) {
      memcpy(&rtb_Assignment[0], &SingalFiltering_DW->signal[0], sizeof(int32_T)
             << 6U);
    }

    rtb_Assignment[s1_iter] = SingalFiltering_U_Inport[s1_iter];
    for (i = 0; i < 64; i++) {
      SingalFiltering_Y_Output[i] = (rtb_Assignment[i] + 3) * 11;
      if (SingalFiltering_Y_Output[i] <= 32) {
        SingalFiltering_Y_Output[i] = 0;
      }
    }
  }
}

void SingalFiltering_initialize(RT_MODEL_SingalFiltering_T *const
  SingalFiltering_M, int32_T SingalFiltering_U_Inport[32], int32_T
  SingalFiltering_Y_Output[64])
{
  DW_SingalFiltering_T *SingalFiltering_DW = SingalFiltering_M->dwork;
  (void) memset((void *)SingalFiltering_DW, 0,
                sizeof(DW_SingalFiltering_T));
  (void)memset(&SingalFiltering_U_Inport[0], 0, sizeof(int32_T) << 5U);
  (void)memset(&SingalFiltering_Y_Output[0], 0, sizeof(int32_T) << 6U);

  {
    int32_T i;
    for (i = 0; i < 64; i++) {
      SingalFiltering_DW->signal[i] = 2;
    }
  }
}

void SingalFiltering_terminate(RT_MODEL_SingalFiltering_T *const
  SingalFiltering_M)
{
  UNUSED_PARAMETER(SingalFiltering_M);
}
