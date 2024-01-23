#include "HybridFilter.h"
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
static real_T rtY_signal_h1[32];
static real_T rtY_signal_h2[32];
static real_T rtY_signal_h3[32];
static real_T rtY_signal_l1[32];
static real_T rtY_signal_l2[32];
static real_T rtY_signal_l3[32];
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
    HybridFilter_step(rtM, rtU_signal1, rtU_signal2, rtU_signal3, rtY_signal_h1, rtY_signal_h2, rtY_signal_h3,
                      rtY_signal_l1, rtY_signal_l2, rtY_signal_l3);
    OverrunFlag = false;
}

int_T main(int_T argc, const char *argv[])
{
    RT_MODEL *const rtM = rtMPtr;
    (void)(argc);
    (void)(argv);
    rtM->dwork = &rtDW;
    HybridFilter_initialize(rtM, rtU_signal1, rtU_signal2, rtU_signal3, rtY_signal_h1, rtY_signal_h2, rtY_signal_h3,
                            rtY_signal_l1, rtY_signal_l2, rtY_signal_l3);
    int testCount = (argc > 1 ? atoi(argv[1]) : 1);
    size_t len;
    clock_t testStartTime = clock();
    for (int i = 0; i < 32; i++)
    {
        rtU_signal1[i] = i;
        rtU_signal2[i] = i;
        rtU_signal3[i] = i;
    }
    for (int i = 0; i < testCount; i++)
    {
        HybridFilter_step(rtM, rtU_signal1, rtU_signal2, rtU_signal3, rtY_signal_h1, rtY_signal_h2, rtY_signal_h3,
                          rtY_signal_l1, rtY_signal_l2, rtY_signal_l3);
    }
    clock_t testEndTime = clock();
    long long testCostTime = (testEndTime - testStartTime);
    printf("run %d times, cost : %lld\n", testCount, testCostTime);
    return 0;
}
