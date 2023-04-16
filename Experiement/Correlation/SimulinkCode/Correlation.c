#include "Correlation.h"
#include <string.h>
#include "rtwtypes.h"

#define RT_PI                          3.14159265358979323846
#define RT_PIF                         3.1415927F
#define RT_LN_10                       2.30258509299404568402
#define RT_LN_10F                      2.3025851F
#define RT_LOG10E                      0.43429448190325182765
#define RT_LOG10EF                     0.43429449F
#define RT_E                           2.7182818284590452354
#define RT_EF                          2.7182817F

#ifndef UNUSED_PARAMETER
#if defined(__LCC__)
#define UNUSED_PARAMETER(x)
#else

#define UNUSED_PARAMETER(x)            (void) (x)
#endif
#endif

void Correlation_step(RT_MODEL *const rtM, real32_T rtU_Inport[10], real32_T
                      rtU_Inport1[240], real32_T rtY_Output[20])
{
  int32_T i;
  int32_T j;
  int32_T out;
  real32_T rtb_Correlation[249];
  out = 0;
  for (i = 0; i < 249; i++) {
    int32_T jEnd;
    real32_T acc;
    if (i - 239 >= 0) {
      j = i - 239;
    } else {
      j = 0;
    }

    if (i <= 9) {
      jEnd = i;
    } else {
      jEnd = 9;
    }

    acc = rtU_Inport1[(j - i) + 239] * rtU_Inport[j];
    for (j++; j <= jEnd; j++) {
      acc += rtU_Inport1[(j - i) + 239] * rtU_Inport[j];
    }

    rtb_Correlation[out] = acc;
    out++;
  }

  memcpy(&rtY_Output[0], &rtb_Correlation[18], 20U * sizeof(real32_T));
  UNUSED_PARAMETER(rtM);
}

void Correlation_initialize(RT_MODEL *const rtM, real32_T rtU_Inport[10],
  real32_T rtU_Inport1[240], real32_T rtY_Output[20])
{
  DW *rtDW = rtM->dwork;
  rtmSetErrorStatus(rtM, (NULL));
  (void) memset((void *)rtDW, 0,
                sizeof(DW));
  (void)memset(&rtU_Inport[0], 0, 10U * sizeof(real32_T));
  (void)memset(&rtU_Inport1[0], 0, 240U * sizeof(real32_T));
  (void)memset(&rtY_Output[0], 0, 20U * sizeof(real32_T));
}
