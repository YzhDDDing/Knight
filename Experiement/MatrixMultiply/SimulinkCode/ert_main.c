#include <stddef.h>
#include <stdio.h>
#include <time.h>
#include "MatrixMultiply.h"
#include <stdlib.h>

static RT_MODEL_MatrixMultiply_T MatrixMultiply_M_;
static RT_MODEL_MatrixMultiply_T *const MatrixMultiply_MPtr = &MatrixMultiply_M_;
static B_MatrixMultiply_T MatrixMultiply_B;
static real_T MatrixMultiply_U_In2[256];
static real_T MatrixMultiply_U_In1[256];
static real_T MatrixMultiply_Y_Out1[16];
void rt_OneStep(RT_MODEL_MatrixMultiply_T *const MatrixMultiply_M);
void rt_OneStep(RT_MODEL_MatrixMultiply_T *const MatrixMultiply_M)
{
  static boolean_T OverrunFlag = false;
  if (OverrunFlag) {
    rtmSetErrorStatus(MatrixMultiply_M, "Overrun");
    return;
  }

  OverrunFlag = true;
  MatrixMultiply_step(MatrixMultiply_M, MatrixMultiply_U_In2, MatrixMultiply_U_In1, MatrixMultiply_Y_Out1);
  OverrunFlag = false;
}

int_T main(int_T argc, const char *argv[])
{
  RT_MODEL_MatrixMultiply_T *const MatrixMultiply_M = MatrixMultiply_MPtr;
  (void)(argc);
  (void)(argv);
  MatrixMultiply_M->blockIO = &MatrixMultiply_B;
  int testCount = (argc > 1 ? atoi(argv[1]) : 1);
  for (int i=0; i<256; i++)
  {
    MatrixMultiply_U_In2[i] = i;
    MatrixMultiply_U_In1[i] = i;
  }
  clock_t testStartTime = clock();
  for (int i = 0; i < testCount; i++) {
    MatrixMultiply_step(MatrixMultiply_M, MatrixMultiply_U_In2, MatrixMultiply_U_In1, MatrixMultiply_Y_Out1);
  }
  if(testCount == 1) {
    for(int i = 0; i < 16; i++) {
      printf("%lf, ", MatrixMultiply_Y_Out1[i]);
    }
    printf("\n");
  }
  clock_t testEndTime = clock();
  long long testCostTime = (testEndTime - testStartTime);
  printf("run %d times, cost : %lld\n", testCount, testCostTime);
  return 0;
}