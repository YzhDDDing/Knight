#include "Diffsion.h"
#include <string.h>
#include "rtwtypes.h"

void Diffsion_step(RT_MODEL_Diffsion_T *const Diffsion_M, int32_T
                   Diffsion_Y_Outport[64])
{
  DW_Diffsion_T *Diffsion_DW = Diffsion_M->dwork;
  int32_T rtb_Assignment[64];
  int32_T i;
  int32_T s1_iter;
  for (s1_iter = 0; s1_iter < 64; s1_iter++) {
    if (s1_iter == 0) {
      memcpy(&rtb_Assignment[0], &Diffsion_DW->A[0], sizeof(int32_T) << 6U);
    }

    rtb_Assignment[s1_iter] = ((Diffsion_DW->B[s1_iter] - Diffsion_DW->A[s1_iter]
      * 5) + 11) * Diffsion_DW->B[s1_iter];
    for (i = 0; i < 64; i++) {
      Diffsion_Y_Outport[i] = (rtb_Assignment[i] + 3) * 3;
      if (Diffsion_Y_Outport[i] <= 0) {
        Diffsion_Y_Outport[i] = 0;
      }
    }
  }
}

void Diffsion_initialize(RT_MODEL_Diffsion_T *const Diffsion_M, int32_T
  Diffsion_Y_Outport[64])
{
  DW_Diffsion_T *Diffsion_DW = Diffsion_M->dwork;
  (void) memset((void *)Diffsion_DW, 0,
                sizeof(DW_Diffsion_T));
  (void)memset(&Diffsion_Y_Outport[0], 0, sizeof(int32_T) << 6U);
}

void Diffsion_terminate(RT_MODEL_Diffsion_T *const Diffsion_M)
{
  UNUSED_PARAMETER(Diffsion_M);
}
