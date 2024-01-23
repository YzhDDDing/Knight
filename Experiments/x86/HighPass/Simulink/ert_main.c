#include "HighPass.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static RT_MODEL rtM_;
static RT_MODEL *const rtMPtr = &rtM_;
static DW rtDW;
static real_T rtU_signal1[32];
static real_T rtU_signal2[32];
static real_T rtU_signal3[32];
static real_T rtY_signal_o1[32];
static real_T rtY_signal_o2[32];
static real_T rtY_signal_o3[32];
void rt_OneStep(RT_MODEL *const rtM);
void rt_OneStep(RT_MODEL *const rtM)
{
    static boolean_T OverrunFlag = false;
    if (OverrunFlag)
    {
        rtmSetErrorStatus(rtM, "Overrun");
        return;
    }
    OverrunFlag = true;
    HighPass_step(rtM, rtU_signal1, rtU_signal2, rtU_signal3, rtY_signal_o1, rtY_signal_o2, rtY_signal_o3);
    OverrunFlag = false;
}

int_T main(int_T argc, const char *argv[])
{
    RT_MODEL *const rtM = rtMPtr;
    (void)(argc);
    (void)(argv);
    rtM->dwork = &rtDW;
    HighPass_initialize(rtM);
    int testCount = (argc > 1 ? atoi(argv[1]) : 1);

    clock_t testStartTime = clock();
    for (int i = 0; i < 32; i++)
    {
        rtU_signal1[i] = i;
        rtU_signal2[i] = i;
        rtU_signal3[i] = i;
    }
    for (int i = 0; i < testCount; i++)
    {
        HighPass_step(rtM, rtU_signal1, rtU_signal2, rtU_signal3, rtY_signal_o1, rtY_signal_o2, rtY_signal_o3);
    }
    clock_t testEndTime = clock();
    long long testCostTime = (testEndTime - testStartTime);
    printf("run %d times, cost : %lld\n", testCount, testCostTime);
    // printf("%f", rtY_signal_o1[0]);
    return 0;
}