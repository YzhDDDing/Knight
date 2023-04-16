#include "define.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
double exec_In1[128];
double exec_In2[128];
double exec_Out1[8];
int main(int argc, char *argv[]) {
    int testCount = (argc > 1 ? atoi(argv[1]) : 1);
    clock_t testStartTime = clock();
    system_root_Init(&system_root_instance);
    for (int i = 0; i < 128; i++) {
        exec_In1[i] = i*2;
        exec_In2[i] = i*3;
    }
    for (int i = 0; i < testCount; i++) {
        system_root_Update(&system_root_instance, exec_In1, exec_In2, exec_Out1);
    }
    if(testCount == 1) {
        for(int i = 0; i < 8; i++) {
            printf("%lf, ", exec_Out1[i]);
        }
        printf("\n");
    }
    clock_t testEndTime = clock();
    long long testCostTime = (testEndTime - testStartTime);
    printf("run %d times, cost : %lld\n", testCount, testCostTime);
}