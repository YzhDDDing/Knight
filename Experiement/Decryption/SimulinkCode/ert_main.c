#include <stddef.h>
#include <stdio.h>
#include "Decryption.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

static RT_MODEL rtM_;
static RT_MODEL *const rtMPtr = &rtM_;
static int32_T rtU_In1[256];
static int32_T rtU_In2[512];
static int32_T rtU_In3;
static int32_T rtY_Output[16];
void rt_OneStep(RT_MODEL *const rtM);
void rt_OneStep(RT_MODEL *const rtM)
{
  static boolean_T OverrunFlag = false;
  if (OverrunFlag) {
    rtmSetErrorStatus(rtM, "Overrun");
    return;
  }

  OverrunFlag = true;
  Decryption_step(rtM, rtU_In1, rtU_In2, rtU_In3, rtY_Output);
  OverrunFlag = false;
}

int_T main(int_T argc, const char *argv[])
{
  RT_MODEL *const rtM = rtMPtr;
  (void)(argc);
  (void)(argv);
  int testCount = (argc > 1 ? atoi(argv[1]) : 1);
  clock_t testStartTime = clock();
  Decryption_initialize(rtM, rtU_In1, rtU_In2, &rtU_In3, rtY_Output);
  for(int i = 0; i < 256; i++) {
    rtU_In1[i] = i;
  }
  for(int i = 0; i < 512; i++) {
    rtU_In2[i] = i;
  }
  for(int i = 0; i < testCount; i++) {
      Decryption_step(rtM, rtU_In1, rtU_In2, rtU_In3, rtY_Output);
  }
  if(testCount == 1) {
    for(int i = 0; i < 16; i++) {
      printf("%d, ", rtY_Output[i]);
    }
    printf("\n");
  }
  clock_t testEndTime = clock();
  long long testCostTime = (testEndTime - testStartTime);
  printf("run %d times, cost : %lld\n", testCount, testCostTime);
  return 0;
}
