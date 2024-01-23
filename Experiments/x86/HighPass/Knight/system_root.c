#include "define.h"
struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self) {
    system_5_Init(&system_5_instance);
}
void system_root_Update(struct system_root_state* self, float signal1[32], float signal2[32], float signal3[32], float signal_o1[32], float signal_o2[32], float signal_o3[32]) {
    float HighPass_signal_o1[32] = {0};
    float HighPass_signal_o2[32] = {0};
    float HighPass_signal_o3[32] = {0};
    system_5_Update(&system_5_instance, signal1, signal2, signal3, HighPass_signal_o1, HighPass_signal_o2, HighPass_signal_o3);
    int batchIndex;
    for (batchIndex = 0; batchIndex < 32; batchIndex++) {
        signal_o1[batchIndex] = HighPass_signal_o1[batchIndex];
    }
    int batchIndex1;
    for (batchIndex1 = 0; batchIndex1 < 32; batchIndex1++) {
        signal_o2[batchIndex1] = HighPass_signal_o2[batchIndex1];
    }
    int batchIndex2;
    for (batchIndex2 = 0; batchIndex2 < 32; batchIndex2++) {
        signal_o3[batchIndex2] = HighPass_signal_o3[batchIndex2];
    }
}