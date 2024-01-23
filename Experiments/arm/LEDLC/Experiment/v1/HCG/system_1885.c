#include "define.h"
struct system_1885_state system_1885_instance;
void system_1885_Init(struct system_1885_state* self) {
}
void system_1885_Update(struct system_1885_state* self) {
    int Constant1_DefaultOutport1 = 0;
    float Constant2_DefaultOutport1 = 0;
    float * Data_StoreRead_DefaultOutport1 = &(Data_StoreMemory_Data[0]);
    int * Data_StoreRead1_DefaultOutport1 = &(Data_StoreMemory6_Satisfied[0]);
    int For_Iterator_DefaultOutport1 = -1;
    float delta_DefaultOutport1 = 0;
    int shift_DefaultOutport1 = 0;
    float Assignment_DefaultOutport1[64] = {0};
    unsigned char Assignment_init = 0;
    int Assignment1_DefaultOutport1[64] = {0};
    unsigned char Assignment1_init = 0;
    float Add_DefaultOutport1[64] = {0};
    int Add1_DefaultOutport1[64] = {0};
    for (int i = 0; i < 64; i++) {
        Constant1_DefaultOutport1 = 0;
        Constant2_DefaultOutport1 = 0;
        For_Iterator_DefaultOutport1++;
        delta_DefaultOutport1 = 15;
        shift_DefaultOutport1 = 15;
        if (Assignment_init == 0) {
            Assignment_init = 1;
            int batchIndex = 0;
            for (batchIndex = 0;batchIndex < 64;batchIndex += 4) {
                float32x4_t Data_StoreRead_DefaultOutport1_Batch = vld1q_f32(Data_StoreRead_DefaultOutport1 + batchIndex);
                vst1q_f32(Assignment_DefaultOutport1 + batchIndex, Data_StoreRead_DefaultOutport1_Batch);
            }
        }
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Constant2_DefaultOutport1;
        if (Assignment1_init == 0) {
            Assignment1_init = 1;
            int batchIndex = 0;
            for (batchIndex = 0;batchIndex < 64;batchIndex += 4) {
                int32x4_t Data_StoreRead1_DefaultOutport1_Batch = vld1q_s32(Data_StoreRead1_DefaultOutport1 + batchIndex);
                vst1q_s32(Assignment1_DefaultOutport1 + batchIndex, Data_StoreRead1_DefaultOutport1_Batch);
            }
        }
        Assignment1_DefaultOutport1[For_Iterator_DefaultOutport1] = Constant1_DefaultOutport1;
        float32x4_t delta_DefaultOutport1_Batch = vdupq_n_f32(delta_DefaultOutport1);
        int32x4_t shift_DefaultOutport1_Batch = vdupq_n_s32(shift_DefaultOutport1);
        int batchIndex = 0;
        for (batchIndex = 0;batchIndex < 64;batchIndex += 4) {
            float32x4_t Assignment_DefaultOutport1_Batch = vld1q_f32(Assignment_DefaultOutport1 + batchIndex);
            int32x4_t Assignment1_DefaultOutport1_Batch = vld1q_s32(Assignment1_DefaultOutport1 + batchIndex);
            float32x4_t Add_DefaultOutport1_Batch = {0};
            Add_DefaultOutport1_Batch = vaddq_f32(delta_DefaultOutport1_Batch, Assignment_DefaultOutport1_Batch);
            int32x4_t Add1_DefaultOutport1_Batch = {0};
            Add1_DefaultOutport1_Batch = vaddq_s32(Assignment1_DefaultOutport1_Batch, shift_DefaultOutport1_Batch);
            vst1q_f32(Add_DefaultOutport1 + batchIndex, Add_DefaultOutport1_Batch);
            vst1q_s32(Add1_DefaultOutport1 + batchIndex, Add1_DefaultOutport1_Batch);
        }
        for (int Data_StoreWrite_i = 0;Data_StoreWrite_i < 64;Data_StoreWrite_i++) {
            Data_StoreMemory_Data[Data_StoreWrite_i] = Assignment_DefaultOutport1[Data_StoreWrite_i];
        }
        for (int Data_StoreWrite1_i = 0;Data_StoreWrite1_i < 64;Data_StoreWrite1_i++) {
            Data_StoreMemory6_Satisfied[Data_StoreWrite1_i] = Assignment1_DefaultOutport1[Data_StoreWrite1_i];
        }
        for (int Data_StoreWrite2_i = 0;Data_StoreWrite2_i < 64;Data_StoreWrite2_i++) {
            Data_StoreMemory8_Data_o[Data_StoreWrite2_i] = Add_DefaultOutport1[Data_StoreWrite2_i];
        }
        for (int Data_StoreWrite3_i = 0;Data_StoreWrite3_i < 64;Data_StoreWrite3_i++) {
            Data_StoreMemory9_Sat_o[Data_StoreWrite3_i] = Add1_DefaultOutport1[Data_StoreWrite3_i];
        }
    }
}