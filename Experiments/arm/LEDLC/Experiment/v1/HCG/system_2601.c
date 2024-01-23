#include "define.h"
struct system_2601_state system_2601_instance;
void system_2601_Init(struct system_2601_state* self) {
}
void system_2601_Update(struct system_2601_state* self) {
    int Data_StoreRead_DefaultOutport1 = 0;
    int * Data_StoreRead1_DefaultOutport1 = &(Data_StoreMemory6_Satisfied[0]);
    int For_Iterator_DefaultOutport1 = -1;
    float delta_DefaultOutport1 = 0;
    bool CompareTo_Constant1_DefaultOutport1 = 0;
    int Selector_DefaultOutport1 = 0;
    int Assignment_DefaultOutport1[64] = {0};
    unsigned char Assignment_init = 0;
    bool CompareTo_Constant_DefaultOutport1 = 0;
    bool AND_DefaultOutport1 = 0;
    int Add_DefaultOutport1[64] = {0};
    int Product_DefaultOutport1[64] = {0};
    int Switch_DefaultOutport1 = 0;
    int Switch1_DefaultOutport1[64] = {0};
    for (int i = 0; i < 64; i++) {
        Data_StoreRead_DefaultOutport1 = Data_StoreMemory2_Index;
        For_Iterator_DefaultOutport1++;
        delta_DefaultOutport1 = 2;
        CompareTo_Constant1_DefaultOutport1 = Data_StoreRead_DefaultOutport1 == -1;
        Selector_DefaultOutport1 = Data_StoreRead1_DefaultOutport1[For_Iterator_DefaultOutport1];
        if (Assignment_init == 0) {
            Assignment_init = 1;
            int batchIndex = 0;
            for (batchIndex = 0;batchIndex < 64;batchIndex += 4) {
                int32x4_t Data_StoreRead1_DefaultOutport1_Batch = vld1q_s32(Data_StoreRead1_DefaultOutport1 + batchIndex);
                vst1q_s32(Assignment_DefaultOutport1 + batchIndex, Data_StoreRead1_DefaultOutport1_Batch);
            }
        }
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Selector_DefaultOutport1;
        CompareTo_Constant_DefaultOutport1 = Selector_DefaultOutport1 == 0;
        AND_DefaultOutport1 = (CompareTo_Constant1_DefaultOutport1 && CompareTo_Constant_DefaultOutport1);
        int32x4_t Data_StoreRead_DefaultOutport1_Batch = vdupq_n_s32(Data_StoreRead_DefaultOutport1);
        float32x4_t delta_DefaultOutport1_Batch = vdupq_n_f32(delta_DefaultOutport1);
        int batchIndex = 0;
        for (batchIndex = 0;batchIndex < 64;batchIndex += 4) {
            int32x4_t Assignment_DefaultOutport1_Batch = vld1q_s32(Assignment_DefaultOutport1 + batchIndex);
            int32x4_t Add_DefaultOutport1_Batch = {0};
            Add_DefaultOutport1_Batch = vaddq_s32(Assignment_DefaultOutport1_Batch, Data_StoreRead_DefaultOutport1_Batch);
            int32x4_t Product_DefaultOutport1_Batch = {0};
            int32x4_t delta_DefaultOutport1_BatchConvert = vcvtq_s32_f32(delta_DefaultOutport1_Batch);
            Product_DefaultOutport1_Batch = vmulq_s32(Add_DefaultOutport1_Batch, delta_DefaultOutport1_BatchConvert);
            vst1q_s32(Product_DefaultOutport1 + batchIndex, Product_DefaultOutport1_Batch);
        }
        if (AND_DefaultOutport1 != 0) {
            Switch_DefaultOutport1 = For_Iterator_DefaultOutport1;
        }
        else {
            Switch_DefaultOutport1 = Data_StoreRead_DefaultOutport1;
        }
        Data_StoreMemory2_Index = Switch_DefaultOutport1;
        for (int Switch1_i = 0;Switch1_i < 64;Switch1_i++) {
            if (Assignment_DefaultOutport1[Switch1_i] > 144) {
                Switch1_DefaultOutport1[Switch1_i] = Assignment_DefaultOutport1[Switch1_i];
            }
            else {
                Switch1_DefaultOutport1[Switch1_i] = Product_DefaultOutport1[Switch1_i];
            }
        }
        for (int Data_StoreWrite2_i = 0;Data_StoreWrite2_i < 64;Data_StoreWrite2_i++) {
            Data_StoreMemory9_Sat_o[Data_StoreWrite2_i] = Switch1_DefaultOutport1[Data_StoreWrite2_i];
        }
    }
}