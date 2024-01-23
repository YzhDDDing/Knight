#include "define.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float exec_Inport;
int exec_Outport[32];
int main(int argc, char *argv[])
{
    int testCount = (argc > 1 ? atoi(argv[1]) : 1);
    system_root_Init(&system_root_instance);
    clock_t testStartTime = clock();
    for (int i = 0; i < testCount; i++)
    {
        system_root_Update(&system_root_instance, exec_Inport, exec_Outport);
    }
    clock_t testEndTime = clock();
    long long testCostTime = (testEndTime - testStartTime);
    printf("run %d times, cost : %lld\n", testCount, testCostTime);
    return 0;
}