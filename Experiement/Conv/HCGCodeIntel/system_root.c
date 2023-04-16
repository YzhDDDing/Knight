#include "define.h"
struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self) {
}
void system_root_Update(struct system_root_state* self, float Inport2[150], float Inport3[10], float Outport[20]) {
    float Convolution_DefaultOutport1[159];
    float * Selector_DefaultOutport1 = &(Convolution_DefaultOutport1[19]);
    conv_1d_f32_Intel(150, Inport2, 10, Inport3, Convolution_DefaultOutport1);
    int batchIndex;
    for (batchIndex = 0; batchIndex + 7 < 20; batchIndex+=8) {
        __m256 Selector_DefaultOutport1_batch = _mm256_loadu_ps(&Selector_DefaultOutport1[batchIndex]);
        _mm256_storeu_ps(&Outport[batchIndex], Selector_DefaultOutport1_batch);
    }
    for (; batchIndex < 20; batchIndex++) {
        Outport[batchIndex] = Selector_DefaultOutport1[batchIndex];
    }
}