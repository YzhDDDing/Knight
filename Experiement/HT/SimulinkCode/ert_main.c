#include <stddef.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "HermitianTranspose.h"

static RT_MODEL_HermitianTranspose_T HermitianTranspose_M_;
static RT_MODEL_HermitianTranspose_T *const HermitianTranspose_MPtr = &HermitianTranspose_M_;
static B_HermitianTranspose_T HermitianTranspose_B;
static real_T HermitianTranspose_U_In2[256];
static real_T HermitianTranspose_Y_Out1[64];
void rt_OneStep(RT_MODEL_HermitianTranspose_T *const HermitianTranspose_M);
void rt_OneStep(RT_MODEL_HermitianTranspose_T *const HermitianTranspose_M)
{
  static boolean_T OverrunFlag = false;
  if (OverrunFlag) {
    rtmSetErrorStatus(HermitianTranspose_M, "Overrun");
    return;
  }

  OverrunFlag = true;
  HermitianTranspose_step(HermitianTranspose_M, HermitianTranspose_U_In2, HermitianTranspose_Y_Out1);
  OverrunFlag = false;
}

int_T main(int_T argc, const char *argv[])
{
  RT_MODEL_HermitianTranspose_T *const HermitianTranspose_M = HermitianTranspose_MPtr;
  (void)(argc);
  (void)(argv);
  HermitianTranspose_M->blockIO = &HermitianTranspose_B;
  HermitianTranspose_initialize(HermitianTranspose_M, HermitianTranspose_U_In2, HermitianTranspose_Y_Out1);
  int testCount = (argc > 1 ? atoi(argv[1]) : 1);
  clock_t testStartTime = clock();
  for(int i = 0; i < 256; i++)
    HermitianTranspose_U_In2[i] = i;
  for (int i = 0; i < testCount; i++) {
      HermitianTranspose_step(HermitianTranspose_M, HermitianTranspose_U_In2, HermitianTranspose_Y_Out1);
  }
  if(testCount == 1)
  {
    for(int i = 0; i < 64; i++)
      printf("%lf, ", HermitianTranspose_Y_Out1[i]);
    printf("\n");
  }
  clock_t testEndTime = clock();
  long long testCostTime = (testEndTime - testStartTime);
  printf("run %d times, cost : %lld\n", testCount, testCostTime);
  return 0;
}
