#include <stddef.h>
#include <stdio.h>
#include "Conv.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

static RT_MODEL_Conv_T Conv_M_;
static RT_MODEL_Conv_T *const Conv_MPtr = &Conv_M_;
static DW_Conv_T Conv_DW;
static real32_T Conv_U_Inport2[150];
static real32_T Conv_U_Inport3[10];
static real32_T Conv_Y_Outport[50];
void rt_OneStep(RT_MODEL_Conv_T *const Conv_M);
void rt_OneStep(RT_MODEL_Conv_T *const Conv_M)
{
  static boolean_T OverrunFlag = false;
  if (OverrunFlag) {
    rtmSetErrorStatus(Conv_M, "Overrun");
    return;
  }

  OverrunFlag = true;
  Conv_step(Conv_M, Conv_U_Inport2, Conv_U_Inport3, Conv_Y_Outport);
  OverrunFlag = false;
}

int_T main(int_T argc, const char *argv[])
{
  RT_MODEL_Conv_T *const Conv_M = Conv_MPtr;
  (void)(argc);
  (void)(argv);
  int testCount = (argc > 1 ? atoi(argv[1]) : 1);
  clock_t testStartTime = clock();
  Conv_M->dwork = &Conv_DW;
  Conv_initialize(Conv_M, Conv_U_Inport2, Conv_U_Inport3, Conv_Y_Outport);
  for(int i = 0; i < 150; i++) {
    Conv_U_Inport2[i] = i;
  }
  for(int i = 0; i < 10; i++) {
    Conv_U_Inport3[i] = i;
  }
  for(int i = 0; i < testCount; i++) {
      Conv_step(Conv_M, Conv_U_Inport2, Conv_U_Inport3, Conv_Y_Outport);
  }
  if(testCount == 1) {
    for(int i = 0; i < 20; i++)
      printf("%f, ", Conv_Y_Outport[i]);
    printf("\n");
  }
  clock_t testEndTime = clock();
  long long testCostTime = (testEndTime - testStartTime);
  printf("run %d times, cost : %lld\n", testCount, testCostTime);
  return 0;
}
