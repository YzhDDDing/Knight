#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "RunningDifference.h"

static RT_MODEL rtM_;
static RT_MODEL *const rtMPtr = &rtM_;
static DW rtDW;
static real_T rtU_In1[128];
static real_T rtU_In2[128];
static real_T rtY_Out1[8];
void rt_OneStep(RT_MODEL *const rtM);
void rt_OneStep(RT_MODEL *const rtM)
{
  static boolean_T OverrunFlag = false;
  if (OverrunFlag) {
    rtmSetErrorStatus(rtM, "Overrun");
    return;
  }

  OverrunFlag = true;
  RunningDifference_step(rtM, rtU_In1, rtU_In2, rtY_Out1);
  OverrunFlag = false;
}

int_T main(int_T argc, const char *argv[])
{
  RT_MODEL *const rtM = rtMPtr;
  (void)(argc);
  (void)(argv);
  int testCount = (argc > 1 ? atoi(argv[1]) : 1);
  clock_t testStartTime = clock();
  rtM->dwork = &rtDW;
  RunningDifference_initialize(rtM, rtU_In1, rtU_In2, rtY_Out1);
  for (int i = 0; i < 128; i++) {
    rtU_In1[i] = i*2;
    rtU_In2[i] = i*3;
  }
  for (int i = 0; i < testCount; i++) {
    RunningDifference_step(rtM, rtU_In1, rtU_In2, rtY_Out1);
  }
  if(testCount == 1) {
    for(int i = 0; i < 8; i++) {
      printf("%lf, ", rtY_Out1[i]);
    }
    printf("\n");
  }
  clock_t testEndTime = clock();
  long long testCostTime = (testEndTime - testStartTime);
  printf("run %d times, cost : %lld\n", testCount, testCostTime);
  return 0;
}
