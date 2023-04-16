#include "define.h"
struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self) {
}
void system_root_Update(struct system_root_state* self, float Inport2[150], float Inport3[10], float Outport[20]) {
    float Convolution_DefaultOutport1[159];
    float * Selector_DefaultOutport1 = &(Convolution_DefaultOutport1[19]);
    conv_1d_f32_normal(150, Inport2, 10, Inport3, Convolution_DefaultOutport1);
    int batchIndex;
    for (batchIndex = 0; batchIndex < 20; batchIndex++) {
        Outport[batchIndex] = Selector_DefaultOutport1[batchIndex];
    }
}