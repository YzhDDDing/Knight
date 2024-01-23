#include "define.h"
struct system_123_state system_123_instance;
void system_123_Init(struct system_123_state* self) {
    system_18_Init(&system_18_instance);
    system_22_Init(&system_22_instance);
    system_26_Init(&system_26_instance);
}
void system_123_Update(struct system_123_state* self, double signal1[32], double signal2[32], double signal3[32], double signal_h1[32], double signal_h2[32], double signal_h3[32]) {
    double HighPass_S1_signal_h1[32] = {0};
    double HighPass_S2_signal_h2[32] = {0};
    double HighPass_S3_signal_o3[32] = {0};
    system_18_Update(&system_18_instance, signal1, HighPass_S1_signal_h1);
    system_22_Update(&system_22_instance, signal2, HighPass_S2_signal_h2);
    system_26_Update(&system_26_instance, signal3, HighPass_S3_signal_o3);
    int batchIndex;
    for (batchIndex = 0; batchIndex < 32; batchIndex++) {
        signal_h1[batchIndex] = HighPass_S1_signal_h1[batchIndex];
    }
    int batchIndex1;
    for (batchIndex1 = 0; batchIndex1 < 32; batchIndex1++) {
        signal_h2[batchIndex1] = HighPass_S2_signal_h2[batchIndex1];
    }
    int batchIndex2;
    for (batchIndex2 = 0; batchIndex2 < 32; batchIndex2++) {
        signal_h3[batchIndex2] = HighPass_S3_signal_o3[batchIndex2];
    }
}