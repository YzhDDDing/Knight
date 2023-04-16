#include "Decryption.h"
#include "rtwtypes.h"
#include <string.h>

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

void Decryption_step(RT_MODEL *const rtM, int32_T rtU_In1[256], int32_T rtU_In2
                     [512], int32_T rtU_In3, int32_T rtY_Output[16])
{
  int32_T rtb_Add[256];
  int32_T i;
  for (i = 0; i < 256; i++) {
    rtb_Add[i] = rtU_In2[i + rtU_In3] + rtU_In1[i];
  }

  rtY_Output[0] = rtb_Add[1];
  rtY_Output[1] = rtb_Add[16];
  rtY_Output[2] = rtb_Add[33];
  rtY_Output[3] = rtb_Add[45];
  rtY_Output[4] = rtb_Add[71];
  rtY_Output[5] = rtb_Add[86];
  rtY_Output[6] = rtb_Add[103];
  rtY_Output[7] = rtb_Add[122];
  rtY_Output[8] = rtb_Add[130];
  rtY_Output[9] = rtb_Add[139];
  rtY_Output[10] = rtb_Add[154];
  rtY_Output[11] = rtb_Add[176];
  rtY_Output[12] = rtb_Add[195];
  rtY_Output[13] = rtb_Add[211];
  rtY_Output[14] = rtb_Add[231];
  rtY_Output[15] = rtb_Add[252];
  UNUSED_PARAMETER(rtM);
}

void Decryption_initialize(RT_MODEL *const rtM, int32_T rtU_In1[256], int32_T
  rtU_In2[512], int32_T *rtU_In3, int32_T rtY_Output[16])
{
  rtmSetErrorStatus(rtM, (NULL));
  (void)memset(&rtU_In1[0], 0, sizeof(int32_T) << 8U);
  (void)memset(&rtU_In2[0], 0, sizeof(int32_T) << 9U);
  *rtU_In3 = 0;
  (void)memset(&rtY_Output[0], 0, sizeof(int32_T) << 4U);
  UNUSED_PARAMETER(rtM);
}
