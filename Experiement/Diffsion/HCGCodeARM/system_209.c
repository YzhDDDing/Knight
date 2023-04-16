#include "define.h"
struct system_209_state system_209_instance;
void system_209_Init(struct system_209_state* self) {
}
void system_209_Update(struct system_209_state* self, int Output[64]) {
    int Constant1_DefaultOutport = 11;
    int Constant2_DefaultOutport = 5;
    int Constant3_DefaultOutport = 3;
    int Constant4_DefaultOutport = 0;
    int Assignment_DefaultOutport1[64];
    int Selector_DefaultOutport1[64];
    int Selector1_DefaultOutport1[64];
    int Productor1_DefaultOutport1[64];
    int Add_DefaultOutport1[64];
    int Add1_DefaultOutport1[64];
    int Productor2_DefaultOutport1[64];
    int Productor3_DefaultOutport1[64];
    int Switch_DefaultOutport1[64];
    unsigned char Assignment_init = 0;
    int For_Iterator_DefaultOutport1 = -1;
    int batchIndex1;
    int batchIndex2;
    int batchIndex3;
    for (int i = 0; i < 64; i++) {
        For_Iterator_DefaultOutport1++;
        if (Assignment_init == 0) {
            Assignment_init = 1;
            for (batchIndex1 = 0; batchIndex1 < 64; batchIndex1+=4) {
                int32x4_t A_batch = vld1q_s32(&A_state[batchIndex1]);
                vst1q_s32(&Assignment_DefaultOutport1[batchIndex1], A_batch);
            }
        }
        Selector_DefaultOutport1[For_Iterator_DefaultOutport1] = A_state[For_Iterator_DefaultOutport1];
        Selector1_DefaultOutport1[For_Iterator_DefaultOutport1] = B_state[For_Iterator_DefaultOutport1];
        Productor1_DefaultOutport1[For_Iterator_DefaultOutport1] = Selector_DefaultOutport1[For_Iterator_DefaultOutport1] * Constant2_DefaultOutport;
        Add_DefaultOutport1[For_Iterator_DefaultOutport1] = Constant1_DefaultOutport + Selector1_DefaultOutport1[For_Iterator_DefaultOutport1] - Productor1_DefaultOutport1[For_Iterator_DefaultOutport1];
        Productor2_DefaultOutport1[For_Iterator_DefaultOutport1] = Add_DefaultOutport1[For_Iterator_DefaultOutport1] * Selector1_DefaultOutport1[For_Iterator_DefaultOutport1];
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Productor2_DefaultOutport1[For_Iterator_DefaultOutport1];
        int32x4_t Constant3_DefaultOutport_Batch = vdupq_n_s32(Constant3_DefaultOutport);
        int32x4_t Constant4_DefaultOutport_Batch = vdupq_n_s32(Constant4_DefaultOutport);
        int32x4_t zero_vec = vdupq_n_s32(0);
        for (int batchIndex2 = 0; batchIndex2 < 64; batchIndex2 += 4) {
            int32x4_t Assignment_DefaultOutport1_batch = vld1q_s32(&Assignment_DefaultOutport1[batchIndex2]);
            int32x4_t Add1_DefaultOutport1_Batch = vaddq_s32(Assignment_DefaultOutport1_batch, Constant3_DefaultOutport_Batch);
            int32x4_t Productor3_DefaultOutport1_Batch = vmulq_s32(Add1_DefaultOutport1_Batch, Constant3_DefaultOutport_Batch);
            uint32x4_t Switch_DefaultOutport1_Mask = vcgtq_s32(Productor3_DefaultOutport1_Batch, zero_vec);
            int32x4_t Switch_DefaultOutport1_Batch = vbslq_s32(Switch_DefaultOutport1_Mask, Productor3_DefaultOutport1_Batch, Constant4_DefaultOutport_Batch);
            vst1q_s32(&Switch_DefaultOutport1[batchIndex2], Switch_DefaultOutport1_Batch);
        }
    }
    for(batchIndex3 = 0; batchIndex3 < 64; batchIndex3+=4) {
        int32x4_t Switch_DefaultOutport1_Batch = vld1q_s32(&Switch_DefaultOutport1[batchIndex3]);
        vst1q_s32(&Output[batchIndex3], Switch_DefaultOutport1_Batch);
    }
}