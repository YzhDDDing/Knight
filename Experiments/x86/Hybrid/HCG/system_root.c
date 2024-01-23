#include "define.h"
struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self) {
    system_5_Init(&system_5_instance);
}
void system_root_Update(struct system_root_state* self, double signal1[32], double signal2[32], double signal3[32], double signal_h1[32], double signal_h2[32], double signal_h3[32], double signal_l1[32], double signal_l2[32], double signal_l3[32]) {
    double HybridFilter_signal_h1[32] = {0};
    double HybridFilter_signal_h2[32] = {0};
    double HybridFilter_signal_h3[32] = {0};
    double HybridFilter_signal_l1[32] = {0};
    double HybridFilter_signal_l2[32] = {0};
    double HybridFilter_signal_l3[32] = {0};
    system_5_Update(&system_5_instance, signal1, signal2, signal3, HybridFilter_signal_h1, HybridFilter_signal_h2, HybridFilter_signal_h3, HybridFilter_signal_l1, HybridFilter_signal_l2, HybridFilter_signal_l3);
    int batchIndex;
    for (batchIndex = 0; batchIndex < 32; batchIndex++) {
        signal_h1[batchIndex] = HybridFilter_signal_h1[batchIndex];
    }
    int batchIndex1;
    for (batchIndex1 = 0; batchIndex1 < 32; batchIndex1++) {
        signal_h2[batchIndex1] = HybridFilter_signal_h2[batchIndex1];
    }
    int batchIndex2;
    for (batchIndex2 = 0; batchIndex2 < 32; batchIndex2++) {
        signal_h3[batchIndex2] = HybridFilter_signal_h3[batchIndex2];
    }
    int batchIndex3;
    for (batchIndex3 = 0; batchIndex3 < 32; batchIndex3++) {
        signal_l1[batchIndex3] = HybridFilter_signal_l1[batchIndex3];
    }
    int batchIndex4;
    for (batchIndex4 = 0; batchIndex4 < 32; batchIndex4++) {
        signal_l2[batchIndex4] = HybridFilter_signal_l2[batchIndex4];
    }
    int batchIndex5;
    for (batchIndex5 = 0; batchIndex5 < 32; batchIndex5++) {
        signal_l3[batchIndex5] = HybridFilter_signal_l3[batchIndex5];
    }
}