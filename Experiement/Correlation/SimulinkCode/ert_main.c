#include <stddef.h>
#include <stdio.h>
#include "Correlation.h"
#include <time.h>
#include <stdlib.h>

static RT_MODEL rtM_;
static RT_MODEL *const rtMPtr = &rtM_;
static DW rtDW;
static real32_T rtU_Inport[10];
static real32_T rtU_Inport1[240];
static real32_T rtY_Output[20];
void rt_OneStep(RT_MODEL *const rtM);
void rt_OneStep(RT_MODEL *const rtM)
{
  static boolean_T OverrunFlag = false;
  if (OverrunFlag) {
    rtmSetErrorStatus(rtM, "Overrun");
    return;
  }

  OverrunFlag = true;
  Correlation_step(rtM, rtU_Inport, rtU_Inport1, rtY_Output);
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
  Correlation_initialize(rtM, rtU_Inport, rtU_Inport1, rtY_Output);
  for(int i = 0; i < 240; i++)
    rtU_Inport1[i] = i;
  for(int i = 0; i < 10; i++)
    rtU_Inport[i] = i;
  for(int i = 0; i < testCount; i++) {
      Correlation_step(rtM, rtU_Inport, rtU_Inport1, rtY_Output);
  }
  if(testCount == 1) {
    for(int i = 0; i < 20; i++)
      printf("%f, ", rtY_Output[i]);
    printf("\n");
  }
  clock_t testEndTime = clock();
  long long testCostTime = (testEndTime - testStartTime);
  printf("run %d times, cost : %lld\n", testCount, testCostTime);
  return 0;
}
