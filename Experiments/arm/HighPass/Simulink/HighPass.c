#include "HighPass.h"
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

void HighPass_step(RT_MODEL *const rtM, real_T rtU_signal1[32], real_T
                   rtU_signal2[32], real_T rtU_signal3[32], real_T
                   rtY_signal_o1[32], real_T rtY_signal_o2[32], real_T
                   rtY_signal_o3[32])
{
  DW *rtDW = rtM->dwork;
  real_T rtb_Assignment[32];
  real_T rtb_Product[32];
  real_T rtb_Product_o[32];
  int32_T i;
  int32_T s6_iter;
  for (s6_iter = 0; s6_iter < 32; s6_iter++) {
    real_T rtb_Product_a;
    if (s6_iter == 0) {
      memcpy(&rtb_Product_o[0], &rtDW->S1[0], sizeof(real_T) << 5U);
    }

    rtb_Product_o[s6_iter] = rtU_signal1[s6_iter] + 1.9500000476837158;
    if (s6_iter == 0) {
      memcpy(&rtb_Product[0], &rtDW->S2[0], sizeof(real_T) << 5U);
    }

    for (i = 0; i < 32; i++) {
      rtb_Product_a = (rtb_Product_o[i] + 3.0) * 1.9500000476837158;
      if (rtb_Product_a > 17.13) {
        rtY_signal_o1[i] = rtb_Product_a / 1.9500000476837158;
      } else {
        rtY_signal_o1[i] = rtb_Product_a;
      }
    }

    rtb_Product[s6_iter] = ((rtU_signal2[s6_iter] + 2.1500000953674316) +
      rtDW->S2[s6_iter]) * 3.0;
    if (s6_iter == 0) {
      memcpy(&rtb_Assignment[0], &rtDW->S3[0], sizeof(real_T) << 5U);
    }

    for (i = 0; i < 32; i++) {
      rtb_Product_a = (rtb_Product[i] + 4.3) * 2.1500000953674316;
      if (rtb_Product_a > 17.13) {
        rtY_signal_o2[i] = rtb_Product_a / 2.1500000953674316;
      } else {
        rtY_signal_o2[i] = rtb_Product_a;
      }
    }

    rtb_Assignment[s6_iter] = ((rtU_signal3[s6_iter] + 3.0) + rtDW->S3[s6_iter])
      * 3.0;
    for (i = 0; i < 32; i++) {
      rtb_Product_a = (rtb_Assignment[i] + 3.1) * 3.0;
      if (rtb_Product_a > 17.13) {
        rtY_signal_o3[i] = rtb_Product_a / 3.0;
      } else {
        rtY_signal_o3[i] = rtb_Product_a;
      }
    }
  }
}

void HighPass_initialize(RT_MODEL *const rtM)
{
  UNUSED_PARAMETER(rtM);
}
