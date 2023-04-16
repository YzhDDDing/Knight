#include "define.h"
struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self) {
}
void system_root_Update(struct system_root_state* self, int In1[256], int In2[512], int In3, int Output[16]) {
    int* Selector1_DefaultOutport1 = In2 + In3;
    int Add_DefaultOutport1[256];
    int Selector_DefaultOutport1[16];
    int batchIndex;
    for (batchIndex = 0; batchIndex < 256; batchIndex+=4) {
        int32x4_t In1_Batch = vld1q_s32(&In1[batchIndex]);
        int32x4_t Selector1_DefaultOutport1_Batch = vld1q_s32(&Selector1_DefaultOutport1[batchIndex]);
        int32x4_t Add_DefaultOutport1_Batch = vaddq_s32(In1_Batch, Selector1_DefaultOutport1_Batch);
        vst1q_s32(&Add_DefaultOutport1[batchIndex], Add_DefaultOutport1_Batch);
    }
    Selector_DefaultOutport1[0] = Add_DefaultOutport1[1];
    Selector_DefaultOutport1[1] = Add_DefaultOutport1[16];
    Selector_DefaultOutport1[2] = Add_DefaultOutport1[33];
    Selector_DefaultOutport1[3] = Add_DefaultOutport1[45];
    Selector_DefaultOutport1[4] = Add_DefaultOutport1[71];
    Selector_DefaultOutport1[5] = Add_DefaultOutport1[86];
    Selector_DefaultOutport1[6] = Add_DefaultOutport1[103];
    Selector_DefaultOutport1[7] = Add_DefaultOutport1[122];
    Selector_DefaultOutport1[8] = Add_DefaultOutport1[130];
    Selector_DefaultOutport1[9] = Add_DefaultOutport1[139];
    Selector_DefaultOutport1[10] = Add_DefaultOutport1[154];
    Selector_DefaultOutport1[11] = Add_DefaultOutport1[176];
    Selector_DefaultOutport1[12] = Add_DefaultOutport1[195];
    Selector_DefaultOutport1[13] = Add_DefaultOutport1[211];
    Selector_DefaultOutport1[14] = Add_DefaultOutport1[231];
    Selector_DefaultOutport1[15] = Add_DefaultOutport1[252];
    int batchIndex2;
    for (batchIndex2 = 0; batchIndex2 < 16; batchIndex2+=4) {
        int32x4_t Selector_DefaultOutport1_Batch = vld1q_s32(&Selector_DefaultOutport1[batchIndex2]);
        vst1q_s32(&Output[batchIndex2], Selector_DefaultOutport1_Batch);
    }
}