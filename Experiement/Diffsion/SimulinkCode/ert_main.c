#include <stddef.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Diffsion.h"

static RT_MODEL_Diffsion_T Diffsion_M_;
static RT_MODEL_Diffsion_T *const Diffsion_MPtr = &Diffsion_M_;
static DW_Diffsion_T Diffsion_DW;
static int32_T Diffsion_Y_Outport[64];
void rt_OneStep(RT_MODEL_Diffsion_T *const Diffsion_M);
void rt_OneStep(RT_MODEL_Diffsion_T *const Diffsion_M)
{
  static boolean_T OverrunFlag = false;
  if (OverrunFlag) {
    rtmSetErrorStatus(Diffsion_M, "Overrun");
    return;
  }

  OverrunFlag = true;
  Diffsion_step(Diffsion_M, Diffsion_Y_Outport);
  OverrunFlag = false;
}

int_T main(int_T argc, const char *argv[])
{
  RT_MODEL_Diffsion_T *const Diffsion_M = Diffsion_MPtr;
  (void)(argc);
  (void)(argv);
  Diffsion_M->dwork = &Diffsion_DW;
  Diffsion_initialize(Diffsion_M, Diffsion_Y_Outport);
  for (int i = 0; i < 64; i++) {
    Diffsion_DW.A[i] = i;
    Diffsion_DW.B[i] = i;
  }
  int testCount = (argc > 1 ? atoi(argv[1]) : 1);
  clock_t testStartTime = clock();
  for (int i = 0; i < testCount; i++) {
    Diffsion_step(Diffsion_M, Diffsion_Y_Outport);
  }
  if(testCount == 1){
    for (int i = 0; i < 64 && testCount == 1; i++) {
      printf("%d, ", Diffsion_Y_Outport[i]);
    }
    printf("\n");
  }
  clock_t testEndTime = clock();
  long long testCostTime = (testEndTime - testStartTime);
  printf("run %d times, cost : %lld\n", testCount, testCostTime);
  return 0;
}
