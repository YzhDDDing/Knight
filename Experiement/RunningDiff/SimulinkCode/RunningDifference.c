#include "RunningDifference.h"
#include "rtwtypes.h"
#include <string.h>

void RunningDifference_step(RT_MODEL *const rtM, real_T rtU_In1[128], real_T
  rtU_In2[128], real_T rtY_Out1[8])
{
  DW *rtDW = rtM->dwork;
  real_T rtb_Add[128];
  int32_T idxin2Var;
  int32_T idxinVar;
  int32_T idxoutVar;
  int32_T kVar;
  idxinVar = 0;
  idxoutVar = 1;
  idxin2Var = 2;
  rtb_Add[0] = rtU_In1[0] - rtDW->Difference_PreviousValue;
  for (kVar = 0; kVar < 127; kVar++) {
    rtb_Add[idxoutVar] = rtU_In1[idxin2Var - 1] - rtU_In1[idxinVar];
    idxoutVar++;
    idxinVar++;
    idxin2Var++;
  }

  rtDW->Difference_PreviousValue = rtU_In1[idxinVar];
  for (idxinVar = 0; idxinVar < 128; idxinVar++) {
    rtb_Add[idxinVar] += rtU_In2[idxinVar];
  }

  rtY_Out1[0] = rtb_Add[1];
  rtY_Out1[1] = rtb_Add[16];
  rtY_Out1[2] = rtb_Add[33];
  rtY_Out1[3] = rtb_Add[45];
  rtY_Out1[4] = rtb_Add[71];
  rtY_Out1[5] = rtb_Add[86];
  rtY_Out1[6] = rtb_Add[103];
  rtY_Out1[7] = rtb_Add[122];
}

void RunningDifference_initialize(RT_MODEL *const rtM, real_T rtU_In1[128],
  real_T rtU_In2[128], real_T rtY_Out1[8])
{
  DW *rtDW = rtM->dwork;
  (void) memset((void *)rtDW, 0,
                sizeof(DW));
  (void)memset(&rtU_In1[0], 0, sizeof(real_T) << 7U);
  (void)memset(&rtU_In2[0], 0, sizeof(real_T) << 7U);
  (void)memset(&rtY_Out1[0], 0, sizeof(real_T) << 3U);
}
