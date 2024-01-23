#include "HybridFilter.h"
#include <string.h>
#include "rtwtypes.h"

void HybridFilter_step(RT_MODEL *const rtM, real_T rtU_signal1[32], real_T
  rtU_signal2[32], real_T rtU_signal3[32], real_T rtY_signal_h1[32], real_T
  rtY_signal_h2[32], real_T rtY_signal_h3[32], real_T rtY_signal_l1[32], real_T
  rtY_signal_l2[32], real_T rtY_signal_l3[32])
{
  DW *rtDW = rtM->dwork;
  real_T rtb_Assignment[32];
  real_T rtb_Assignment_d[32];
  real_T rtb_Assignment_n[32];
  real_T rtb_Product[32];
  real_T rtb_Product_d[32];
  real_T rtb_Product_l[32];
  int32_T i;
  int32_T s8_iter;
  for (s8_iter = 0; s8_iter < 32; s8_iter++) {
    real_T rtb_Divide_d;
    if (s8_iter == 0) {
      memcpy(&rtb_Assignment_n[0], &rtDW->S1[0], sizeof(real_T) << 5U);
    }

    rtb_Assignment_n[s8_iter] = rtU_signal1[s8_iter] + 1.9500000476837158;
    if (s8_iter == 0) {
      memcpy(&rtb_Product_d[0], &rtDW->S2[0], sizeof(real_T) << 5U);
    }

    for (i = 0; i < 32; i++) {
      rtb_Divide_d = (rtb_Assignment_n[i] + 3.0) * 1.9500000476837158;
      if (rtb_Divide_d > 17.13) {
        rtY_signal_h1[i] = rtb_Divide_d / 1.9500000476837158;
      } else {
        rtY_signal_h1[i] = rtb_Divide_d;
      }
    }

    rtb_Product_d[s8_iter] = rtU_signal2[s8_iter] + 2.1500000953674316;
    if (s8_iter == 0) {
      memcpy(&rtb_Product_l[0], &rtDW->S3[0], sizeof(real_T) << 5U);
    }

    for (i = 0; i < 32; i++) {
      rtb_Divide_d = (rtb_Product_d[i] + 4.3) * 2.1500000953674316;
      if (rtb_Divide_d > 17.13) {
        rtY_signal_h2[i] = rtb_Divide_d / 2.1500000953674316;
      } else {
        rtY_signal_h2[i] = rtb_Divide_d;
      }
    }

    rtb_Product_l[s8_iter] = rtU_signal3[s8_iter] + 3.0;
    if (s8_iter == 0) {
      memcpy(&rtb_Product[0], &rtDW->S1[0], sizeof(real_T) << 5U);
    }

    for (i = 0; i < 32; i++) {
      rtb_Divide_d = (rtb_Product_l[i] + 3.1) * 3.0;
      if (rtb_Divide_d > 17.13) {
        rtY_signal_h3[i] = rtb_Divide_d / 3.0;
      } else {
        rtY_signal_h3[i] = rtb_Divide_d;
      }
    }

    rtb_Product[s8_iter] = rtU_signal1[s8_iter] + 1.5499999523162842;
    if (s8_iter == 0) {
      memcpy(&rtb_Assignment_d[0], &rtDW->S2[0], sizeof(real_T) << 5U);
    }

    for (i = 0; i < 32; i++) {
      rtb_Divide_d = (rtb_Product[i] + 3.0) * 1.5499999523162842;
      if (rtb_Divide_d > 17.13) {
        rtY_signal_l1[i] = rtb_Divide_d;
      } else {
        rtY_signal_l1[i] = rtb_Divide_d * 1.5499999523162842;
      }
    }

    rtb_Assignment_d[s8_iter] = rtU_signal2[s8_iter] + 3.130000114440918;
    if (s8_iter == 0) {
      memcpy(&rtb_Assignment[0], &rtDW->S3[0], sizeof(real_T) << 5U);
    }

    for (i = 0; i < 32; i++) {
      rtb_Divide_d = (rtb_Assignment_d[i] + 4.3) * 3.130000114440918;
      if (rtb_Divide_d > 17.13) {
        rtY_signal_l2[i] = rtb_Divide_d;
      } else {
        rtY_signal_l2[i] = rtb_Divide_d * 3.130000114440918;
      }
    }

    rtb_Assignment[s8_iter] = (rtU_signal3[s8_iter] + 2.7799999713897705) *
      rtDW->S3[s8_iter];
    for (i = 0; i < 32; i++) {
      rtb_Divide_d = (rtb_Assignment[i] + 3.1) * 2.6;
      if (rtb_Divide_d > 17.13) {
        rtY_signal_l3[i] = rtb_Divide_d;
      } else {
        rtY_signal_l3[i] = rtb_Divide_d * 2.6;
      }
    }
  }
}

void HybridFilter_initialize(RT_MODEL *const rtM, real_T rtU_signal1[32], real_T
  rtU_signal2[32], real_T rtU_signal3[32], real_T rtY_signal_h1[32], real_T
  rtY_signal_h2[32], real_T rtY_signal_h3[32], real_T rtY_signal_l1[32], real_T
  rtY_signal_l2[32], real_T rtY_signal_l3[32])
{
  DW *rtDW = rtM->dwork;
  (void) memset((void *)rtDW, 0,
                sizeof(DW));
  (void)memset(&rtU_signal1[0], 0, sizeof(real_T) << 5U);
  (void)memset(&rtU_signal2[0], 0, sizeof(real_T) << 5U);
  (void)memset(&rtU_signal3[0], 0, sizeof(real_T) << 5U);
  (void)memset(&rtY_signal_h1[0], 0, sizeof(real_T) << 5U);
  (void)memset(&rtY_signal_h2[0], 0, sizeof(real_T) << 5U);
  (void)memset(&rtY_signal_h3[0], 0, sizeof(real_T) << 5U);
  (void)memset(&rtY_signal_l1[0], 0, sizeof(real_T) << 5U);
  (void)memset(&rtY_signal_l2[0], 0, sizeof(real_T) << 5U);
  (void)memset(&rtY_signal_l3[0], 0, sizeof(real_T) << 5U);
}
