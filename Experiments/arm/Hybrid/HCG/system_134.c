#include "define.h"
struct system_134_state system_134_instance;
void system_134_Init(struct system_134_state* self) {
    system_139_Init(&system_139_instance);
    system_155_Init(&system_155_instance);
    system_171_Init(&system_171_instance);
}
void system_134_Update(struct system_134_state* self, double signal1[32], double signal2[32], double signal3[32], double signal_l1[32], double signal_l2[32], double signal_l3[32]) {
    double LowPass_S1_signal_l1[32] = {0};
    double LowPass_S2_signal_l2[32] = {0};
    double LowPass_S3_signal_l3[32] = {0};
    system_139_Update(&system_139_instance, signal1, LowPass_S1_signal_l1);
    system_155_Update(&system_155_instance, signal2, LowPass_S2_signal_l2);
    system_171_Update(&system_171_instance, signal3, LowPass_S3_signal_l3);
    int batchIndex;
    for (batchIndex = 0; batchIndex < 32; batchIndex++) {
        signal_l1[batchIndex] = LowPass_S1_signal_l1[batchIndex];
    }
    int batchIndex1;
    for (batchIndex1 = 0; batchIndex1 < 32; batchIndex1++) {
        signal_l2[batchIndex1] = LowPass_S2_signal_l2[batchIndex1];
    }
    int batchIndex2;
    for (batchIndex2 = 0; batchIndex2 < 32; batchIndex2++) {
        signal_l3[batchIndex2] = LowPass_S3_signal_l3[batchIndex2];
    }
}