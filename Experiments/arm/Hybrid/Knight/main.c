#include "define.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv[])
{
    int testCount = (argc > 1 ? atoi(argv[1]) : 1);
    size_t len;
    system_root_Init(&system_root_instance);
    clock_t testStartTime = clock();
    double exec_signal1[32];
    double exec_signal2[32];
    double exec_signal3[32];
    double exec_signal_h1[32];
    double exec_signal_h2[32];
    double exec_signal_h3[32];
    double exec_signal_l1[32];
    double exec_signal_l2[32];
    double exec_signal_l3[32];
    for (int i = 0; i < 32; i++)
    {
        exec_signal1[i] = i;
        exec_signal2[i] = i;
        exec_signal3[i] = i;
    }
    for (int i = 0; i < testCount; i++)
    {
        system_root_Update(&system_root_instance, exec_signal1, exec_signal2, exec_signal3, exec_signal_h1,
                           exec_signal_h2, exec_signal_h3, exec_signal_l1, exec_signal_l2, exec_signal_l3);
    }
    clock_t testEndTime = clock();
    long long testCostTime = (testEndTime - testStartTime);
    printf("run %d times, cost : %lld\n", testCount, testCostTime);
    // printf("exec_signal_l1: %f", exec_signal_l1[0]);
    return 0;
}