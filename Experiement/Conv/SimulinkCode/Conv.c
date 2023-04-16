#include "Conv.h"
#include <string.h>
#include "rtwtypes.h"

void Conv_step(RT_MODEL_Conv_T *const Conv_M, real32_T Conv_U_Inport2[150],
               real32_T Conv_U_Inport3[10], real32_T Conv_Y_Outport[20])
{
  int32_T i;
  int32_T j;
  int32_T jEnd;
  int32_T out;
  real32_T rtb_Convolution[159];
  real32_T acc;
  out = 0;
  for (i = 0; i < 159; i++) {
    if (i - 149 >= 0) {
      j = i - 149;
    } else {
      j = 0;
    }

    if (i <= 9) {
      jEnd = i;
    } else {
      jEnd = 9;
    }

    acc = Conv_U_Inport2[i - j] * Conv_U_Inport3[j];
    for (j++; j <= jEnd; j++) {
      acc += Conv_U_Inport2[i - j] * Conv_U_Inport3[j];
    }

    rtb_Convolution[out] = acc;
    out++;
  }

  memcpy(&Conv_Y_Outport[0], &rtb_Convolution[19], 20U * sizeof(real32_T));
  UNUSED_PARAMETER(Conv_M);
}

void Conv_initialize(RT_MODEL_Conv_T *const Conv_M, real32_T Conv_U_Inport2[150],
                     real32_T Conv_U_Inport3[10], real32_T Conv_Y_Outport[20])
{
  DW_Conv_T *Conv_DW = Conv_M->dwork;
  rtmSetErrorStatus(Conv_M, (NULL));
  (void) memset((void *)Conv_DW, 0,
                sizeof(DW_Conv_T));
  (void)memset(&Conv_U_Inport2[0], 0, 150U * sizeof(real32_T));
  (void)memset(&Conv_U_Inport3[0], 0, 10U * sizeof(real32_T));
  (void)memset(&Conv_Y_Outport[0], 0, 20U * sizeof(real32_T));
}

void Conv_terminate(RT_MODEL_Conv_T *const Conv_M)
{
  UNUSED_PARAMETER(Conv_M);
}
