#include "define.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
float exec_Inport[10];
float exec_Inport1[240];
float exec_Outport[20];
int main(int argc, char *argv[]) {
    int testCount = (argc > 1 ? atoi(argv[1]) : 1);
    clock_t testStartTime = clock();
    system_root_Init(&system_root_instance);
    for(int i = 0; i < 240; i++) {
        exec_Inport1[i] = i;
    }
    for(int i = 0; i < 10; i++) {
        exec_Inport[i] = i;
    }
    for (int i = 0; i < testCount; i++) {
        system_root_Update(&system_root_instance, exec_Inport, exec_Inport1, exec_Outport);
    }
    if(testCount == 1) {
        for(int i = 0; i < 20; i++) {
            printf("%f, ", exec_Outport[i]);
        }
        printf("\n");
    }
    clock_t testEndTime = clock();
    long long testCostTime = (testEndTime - testStartTime);
    printf("run %d times, cost : %lld\n", testCount, testCostTime);
}