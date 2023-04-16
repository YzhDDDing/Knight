#include "define.h"
struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self) {
}
void system_root_Update(struct system_root_state* self, float Inport[10], float Inport1[240], float Outport[20]) {
    float Corre_DefaultOutport1[249];
    float * Selector_DefaultOutport1 = &(Corre_DefaultOutport1[18]);
    corre_f32_ARM(240, Inport1, 10, Inport, Corre_DefaultOutport1);
    int batchIndex;
    for (batchIndex = 0; batchIndex + 3 < 20; batchIndex+=4) {
        float32x4_t Selector_DefaultOutport1_Batch = vld1q_f32(&Selector_DefaultOutport1[batchIndex]);
        vst1q_f32(&Outport[batchIndex], Selector_DefaultOutport1_Batch);
    }
    for (; batchIndex < 20; batchIndex+=4) {
        Outport[batchIndex] = Selector_DefaultOutport1[batchIndex];
    }
}