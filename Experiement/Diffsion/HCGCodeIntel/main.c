#include "define.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int exec_Out1[64];
int main(int argc, char *argv[]) {
    int testCount = (argc > 1 ? atoi(argv[1]) : 1);
    for (int i = 0; i < 64; i++) {
        A_state[i] = i;
        B_state[i] = i;
    }
    clock_t testStartTime = clock();
    system_root_Init(&system_root_instance);
    for (int i = 0; i < testCount; i++) {
        system_root_Update(&system_root_instance, exec_Out1);
    }
    if(testCount == 1){
        for (int i = 0; i < 64; i++) {
            printf("%d, ", exec_Out1[i]);
        }
        printf("\n");
    }
    clock_t testEndTime = clock();
    long long testCostTime = (testEndTime - testStartTime);
    printf("run %d times, cost : %lld\n", testCount, testCostTime);
}