#include "define.h"
struct system_34_state system_34_instance;
void system_34_Init(struct system_34_state* self) {
}
void system_34_Update(struct system_34_state* self, int Inport[32], int Output[64]) {
    int Constant_DefaultOutport1;
    int Constant2_DefaultOutport1;
    int Constant3_DefaultOutport1;
    int For_Iterator_DefaultOutport1 = -1;
    int Selector_DefaultOutport1;
    int Assignment_DefaultOutport1[64];
    int Add_DefaultOutport1[64];
    int Product_DefaultOutport1[64];
    int Switch_DefaultOutport1[64];
    unsigned char Assignment_init = 0;
    int batchIndex;
    int batchIndex2;
    int batchIndex3;
    for (int i = 0; i < 32; i++) {
        Constant_DefaultOutport1 = 3;
        Constant2_DefaultOutport1 = 0;
        Constant3_DefaultOutport1 = 11;
        For_Iterator_DefaultOutport1++;
        Selector_DefaultOutport1 = Inport[For_Iterator_DefaultOutport1];
        if (For_Iterator_DefaultOutport1 == 0) {
            for (batchIndex = 0; batchIndex < 64; batchIndex+=4) {
                int32x4_t signal_state_Batch = vld1q_s32(&signal_state[batchIndex]);
                vst1q_s32(&Assignment_DefaultOutport1[batchIndex], signal_state_Batch);
            }
        }
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Selector_DefaultOutport1;
        int32x4_t Constant_DefaultOutport1_Batch = vdupq_n_s32(Constant_DefaultOutport1);
        int32x4_t Constant3_DefaultOutport1_Batch = vdupq_n_s32(Constant3_DefaultOutport1);
        int32x4_t Constant2_DefaultOutport1_Batch = vdupq_n_s32(Constant2_DefaultOutport1);
        
        int32x4_t Switch_Cmp = vdupq_n_s32(32);
        for (batchIndex2 = 0; batchIndex2 < 64; batchIndex2 += 4) {
            int32x4_t Assignment_DefaultOutport1_Batch = vld1q_s32(&Assignment_DefaultOutport1[batchIndex2]);
            int32x4_t Add_DefaultOutport1_Batch = vaddq_s32(Assignment_DefaultOutport1_Batch, Constant_DefaultOutport1_Batch);
            int32x4_t Product_DefaultOutport1_Batch = vmulq_s32(Add_DefaultOutport1_Batch, Constant3_DefaultOutport1_Batch);
            uint32x4_t Switch_DefaultOutport1_Mask = vcgtq_s32(Product_DefaultOutport1_Batch, Switch_Cmp);
            int32x4_t Switch_DefaultOutport1_Batch = vbslq_s32(Switch_DefaultOutport1_Mask, Product_DefaultOutport1_Batch, Constant2_DefaultOutport1_Batch);
            vst1q_s32(&Switch_DefaultOutport1[batchIndex2], Switch_DefaultOutport1_Batch);
        }
    }
    for(batchIndex3 = 0; batchIndex3 < 64; batchIndex3+=4) {
        int32x4_t Switch_DefaultOutport1_Batch = vld1q_s32(&Switch_DefaultOutport1[batchIndex3]);
        vst1q_s32(&Output[batchIndex3], Switch_DefaultOutport1_Batch);
    }
}