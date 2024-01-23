#include "define.h"
struct system_247_state system_247_instance;
void system_247_Init(struct system_247_state* self) {
}
void system_247_Update(struct system_247_state* self, int Output[32]) {
    int Constant_DefaultOutport1 = 0;
    int Constant1_DefaultOutport1 = 0;
    int Constant2_DefaultOutport1 = 0;
    int Constant3_DefaultOutport1 = 0;
    int * Data_StoreRead_DefaultOutport1 = &(Data_StoreMemory_Di_s1[0]);
    int * Data_StoreRead1_DefaultOutport1 = &(Data_StoreMemory1_Di_s2[0]);
    int For_Iterator_DefaultOutport1 = -1;
    int Selector_DefaultOutport1 = 0;
    int Selector1_DefaultOutport1 = 0;
    int Product_DefaultOutport1 = 0;
    int Add1_DefaultOutport1 = 0;
    int Add1_BatchTempVar = 0;
    int Product1_DefaultOutport1 = 0;
    int Assignment_DefaultOutport1[32] = {0};
    unsigned char Assignment_init = 0;
    int Add_DefaultOutport1[32] = {0};
    int Product2_DefaultOutport1[32] = {0};
    int Switch_DefaultOutport1[32] = {0};
    for (int i = 0; i < 32; i++) {
        Constant_DefaultOutport1 = 3;
        Constant1_DefaultOutport1 = 11;
        Constant2_DefaultOutport1 = 5;
        Constant3_DefaultOutport1 = 0;
        For_Iterator_DefaultOutport1++;
        Selector_DefaultOutport1 = Data_StoreRead_DefaultOutport1[For_Iterator_DefaultOutport1];
        Selector1_DefaultOutport1 = Data_StoreRead1_DefaultOutport1[For_Iterator_DefaultOutport1];
        Product_DefaultOutport1 = Selector_DefaultOutport1 * Constant2_DefaultOutport1;
        Add1_DefaultOutport1 = Selector1_DefaultOutport1 + Constant1_DefaultOutport1 - Product_DefaultOutport1;
        Product1_DefaultOutport1 = Add1_DefaultOutport1 * Selector1_DefaultOutport1;
        if (Assignment_init == 0) {
            Assignment_init = 1;
            int batchIndex = 0;
            for (batchIndex = 0;batchIndex < 32;batchIndex += 4) {
                int32x4_t Data_StoreRead_DefaultOutport1_Batch = vld1q_s32(Data_StoreRead_DefaultOutport1 + batchIndex);
                vst1q_s32(Assignment_DefaultOutport1 + batchIndex, Data_StoreRead_DefaultOutport1_Batch);
            }
        }
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Product1_DefaultOutport1;
        int32x4_t Constant_DefaultOutport1_Batch = vdupq_n_s32(Constant_DefaultOutport1);
        int batchIndex = 0;
        for (batchIndex = 0;batchIndex < 32;batchIndex += 4) {
            int32x4_t Assignment_DefaultOutport1_Batch = vld1q_s32(Assignment_DefaultOutport1 + batchIndex);
            int32x4_t Add_DefaultOutport1_Batch = {0};
            Add_DefaultOutport1_Batch = vaddq_s32(Assignment_DefaultOutport1_Batch, Constant_DefaultOutport1_Batch);
            int32x4_t Product2_DefaultOutport1_Batch = {0};
            Product2_DefaultOutport1_Batch = vmulq_s32(Add_DefaultOutport1_Batch, Constant_DefaultOutport1_Batch);
            vst1q_s32(Product2_DefaultOutport1 + batchIndex, Product2_DefaultOutport1_Batch);
        }
        for (int Switch_i = 0;Switch_i < 32;Switch_i++) {
            if (Product2_DefaultOutport1[Switch_i] > 0) {
                Switch_DefaultOutport1[Switch_i] = Product2_DefaultOutport1[Switch_i];
            }
            else {
                Switch_DefaultOutport1[Switch_i] = Constant3_DefaultOutport1;
            }
        }
    }
    int batchIndex = 0;
    for (batchIndex = 0;batchIndex < 32;batchIndex += 4) {
        int32x4_t Switch_DefaultOutport1_Batch = vld1q_s32(Switch_DefaultOutport1 + batchIndex);
        vst1q_s32(Output + batchIndex, Switch_DefaultOutport1_Batch);
    }
}