#include "define.h"
struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self) {
}
void system_root_Update(struct system_root_state* self, float Inport[10], float Inport1[240], float Outport[20]) {
    float Corre_DefaultOutport1[249];
    float * Selector_DefaultOutport1 = &(Corre_DefaultOutport1[18]);
    corre_f32_Intel(240, Inport1, 10, Inport, Corre_DefaultOutport1);
    int batchIndex;
    for (batchIndex = 0; batchIndex + 7 < 20; batchIndex+=8) {
        __m256 Selector_DefaultOutport1_batch = _mm256_loadu_ps(&Selector_DefaultOutport1[batchIndex]);
        _mm256_storeu_ps(&Outport[batchIndex], Selector_DefaultOutport1_batch);
    }
    for (; batchIndex < 20; batchIndex++) {
        Outport[batchIndex] = Selector_DefaultOutport1[batchIndex];
    }
}