#include "define.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int exec_In1[256];
int exec_In2[512];
int exec_In3;
int exec_Output[16];
int main(int argc, char *argv[]) {
    int testCount = (argc > 1 ? atoi(argv[1]) : 1);
    clock_t testStartTime = clock();
    system_root_Init(&system_root_instance);
    for(int i = 0; i < 256; i++) {
        exec_In1[i] = i;
    }
    for(int i = 0; i < 512; i++) {
        exec_In2[i] = i;
    }
    for (int i = 0; i < testCount; i++) {
        system_root_Update(&system_root_instance, exec_In1, exec_In2, exec_In3, exec_Output);
    }
    if(testCount == 1) {
        for(int i = 0; i < 16; i++) {
            printf("%d, ", exec_Output[i]);
        }
        printf("\n");
    }
    clock_t testEndTime = clock();
    long long testCostTime = (testEndTime - testStartTime);
    printf("run %d times, cost : %lld\n", testCount, testCostTime);
}