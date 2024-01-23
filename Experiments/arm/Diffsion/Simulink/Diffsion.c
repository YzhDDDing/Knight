#include "Diffsion.h"
#include <string.h>
#include "rtwtypes.h"

void Diffsion_step(RT_MODEL_Diffsion_T *const Diffsion_M, int32_T
                   Diffsion_U_Inport, int32_T Diffsion_Y_Outport[32])
{
  DW_Diffsion_T *Diffsion_DW = Diffsion_M->dwork;
  int32_T rtb_Assignment[32];
  int32_T i;
  int32_T s4_iter;
  for (s4_iter = 0; s4_iter < 32; s4_iter++) {
    if (s4_iter == 0) {
      memcpy(&rtb_Assignment[0], &Diffsion_DW->Di_m1[0], sizeof(int32_T) << 5U);
    }

    rtb_Assignment[s4_iter] = ((Diffsion_DW->Di_m2[s4_iter] - Diffsion_DW->
      Di_m1[s4_iter] * 5) + 11) * Diffsion_DW->Di_m2[s4_iter];
    for (i = 0; i < 32; i++) {
      int32_T Switch;
      Switch = ((rtb_Assignment[i] + Diffsion_U_Inport) + 3) * 3;
      if (Switch <= 0) {
        Switch = 0;
      }

      Diffsion_Y_Outport[i] = Switch;
    }
  }
}

void Diffsion_initialize(RT_MODEL_Diffsion_T *const Diffsion_M, int32_T
  *Diffsion_U_Inport, int32_T Diffsion_Y_Outport[32])
{
  DW_Diffsion_T *Diffsion_DW = Diffsion_M->dwork;
  (void) memset((void *)Diffsion_DW, 0,
                sizeof(DW_Diffsion_T));
  *Diffsion_U_Inport = 0;
  (void)memset(&Diffsion_Y_Outport[0], 0, sizeof(int32_T) << 5U);
}

void Diffsion_terminate(RT_MODEL_Diffsion_T *const Diffsion_M)
{
  UNUSED_PARAMETER(Diffsion_M);
}
