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
    float exec_signal1[32];
    float exec_signal2[32];
    float exec_signal3[32];
    float exec_signal_o1[48];
    float exec_signal_o2[48];
    float exec_signal_o3[48];
    for (int i = 0; i < 32; i++)
    {
        exec_signal1[i] = i;
        exec_signal2[i] = i;
        exec_signal3[i] = i;
    }
    for (int i = 0; i < testCount; i++)
    {
        system_root_Update(&system_root_instance, exec_signal1, exec_signal2, exec_signal3, exec_signal_o1,
                           exec_signal_o2, exec_signal_o3);
    }
    clock_t testEndTime = clock();
    long long testCostTime = (testEndTime - testStartTime);
    printf("run %d times, cost : %lld\n", testCount, testCostTime);
    // printf("%f", exec_signal_o1[0]);
    return 0;
}