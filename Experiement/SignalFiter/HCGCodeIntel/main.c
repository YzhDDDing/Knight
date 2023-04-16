#include "define.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int exec_Inport[32];
int exec_Output[64];
int main(int argc, char *argv[]) {
    int testCount = (argc > 1 ? atoi(argv[1]) : 1);
    clock_t testStartTime = clock();
    system_root_Init(&system_root_instance);
    for (int i =0; i<32; i++) {
        exec_Inport[i] = i * 3;
    }
    for (int i = 0; i<64; i++) {
        signal_state[i] = i;
    }
    for (int i = 0; i < testCount; i++) {
        system_root_Update(&system_root_instance, exec_Inport, exec_Output);
    }
    if(testCount == 1) {
        for (int i = 0; i < 64; i++) {
          printf("%d, ", exec_Output[i]);
        }
        printf("\n");
    }
    clock_t testEndTime = clock();
    long long testCostTime = (testEndTime - testStartTime);
    printf("run %d times, cost : %lld\n", testCount, testCostTime);
    return 0;
}