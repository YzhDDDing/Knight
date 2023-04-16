#include <stddef.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "SingalFiltering.h"

static RT_MODEL_SingalFiltering_T SingalFiltering_M_;
static RT_MODEL_SingalFiltering_T *const SingalFiltering_MPtr =
  &SingalFiltering_M_;
static DW_SingalFiltering_T SingalFiltering_DW;
static int32_T SingalFiltering_U_Inport[32];
static int32_T SingalFiltering_Y_Output[64];
void rt_OneStep(RT_MODEL_SingalFiltering_T *const SingalFiltering_M);
void rt_OneStep(RT_MODEL_SingalFiltering_T *const SingalFiltering_M)
{
  static boolean_T OverrunFlag = false;
  if (OverrunFlag) {
    rtmSetErrorStatus(SingalFiltering_M, "Overrun");
    return;
  }

  OverrunFlag = true;
  SingalFiltering_step(SingalFiltering_M, SingalFiltering_U_Inport,
                       SingalFiltering_Y_Output);
  OverrunFlag = false;
}

int_T main(int_T argc, const char *argv[])
{
  RT_MODEL_SingalFiltering_T *const SingalFiltering_M = SingalFiltering_MPtr;
  (void)(argc);
  (void)(argv);
  SingalFiltering_M->dwork = &SingalFiltering_DW;
  SingalFiltering_initialize(SingalFiltering_M, SingalFiltering_U_Inport, SingalFiltering_Y_Output);
  for (int i =0; i<32; i++) {
    SingalFiltering_U_Inport[i] = i * 3;
  }
  for (int i = 0; i<64; i++) {
    SingalFiltering_DW.signal[i] = i;
  }
  int testCount = (argc > 1 ? atoi(argv[1]) : 1);
  clock_t testStartTime = clock();
  for(int i = 0; i < testCount; i++) {
    SingalFiltering_step(SingalFiltering_M, SingalFiltering_U_Inport,
                    SingalFiltering_Y_Output);
  }
  if(testCount == 1) {
    for (int i =0 ;i < 64; i++) {
      printf("%d, ", SingalFiltering_Y_Output[i]);
    }
    printf("\n");
  }
  clock_t testEndTime = clock();
  long long testCostTime = (testEndTime - testStartTime);
  printf("run %d times, cost : %lld\n", testCount, testCostTime);
  return 0;
}
