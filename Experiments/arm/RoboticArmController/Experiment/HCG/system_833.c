#include "define.h"
struct system_833_state system_833_instance;
void system_833_Init(struct system_833_state* self) {
}
void system_833_Update(struct system_833_state* self, int ArmId, int FindE) {
    int Constant_DefaultOutport1 = 0;
    int * Data_StoreRead_DefaultOutport1 = &(PortPool_ArmIdPool[0]);
    int * Data_StoreRead1_DefaultOutport1 = &(PortPool1_ArmIdPoolF[0]);
    int For_Iterator_DefaultOutport1 = -1;
    int T_DefaultOutport1 = 0;
    int delta_DefaultOutport1 = 0;
    int key_DefaultOutport1 = 0;
    int key1_DefaultOutport1 = 0;
    bool Equal_DefaultOutport1 = 0;
    int Selector_DefaultOutport1 = 0;
    int Selector1_DefaultOutport1 = 0;
    int Switch_DefaultOutport1 = 0;
    int Switch1_DefaultOutport1 = 0;
    int Assignment_DefaultOutport1[128] = {0};
    unsigned char Assignment_init = 0;
    int Assignment1_DefaultOutport1[128] = {0};
    unsigned char Assignment1_init = 0;
    int Add_DefaultOutport1[128] = {0};
    int Add1_DefaultOutport1[128] = {0};
    int Product_DefaultOutport1[128] = {0};
    int Product1_DefaultOutport1[128] = {0};
    int Subtract_DefaultOutport1[128] = {0};
    int Subtract1_DefaultOutport1[128] = {0};
    for (int i = 0; i < 128; i++) {
        Constant_DefaultOutport1 = 1;
        For_Iterator_DefaultOutport1++;
        T_DefaultOutport1 = 4;
        delta_DefaultOutport1 = 3;
        key_DefaultOutport1 = 201;
        key1_DefaultOutport1 = 201;
        Equal_DefaultOutport1 = FindE == For_Iterator_DefaultOutport1;
        Selector_DefaultOutport1 = Data_StoreRead_DefaultOutport1[For_Iterator_DefaultOutport1];
        Selector1_DefaultOutport1 = Data_StoreRead1_DefaultOutport1[For_Iterator_DefaultOutport1];
        if (Equal_DefaultOutport1 > 0) {
            Switch_DefaultOutport1 = ArmId;
        }
        else {
            Switch_DefaultOutport1 = Selector_DefaultOutport1;
        }
        if (Equal_DefaultOutport1 > 0) {
            Switch1_DefaultOutport1 = Constant_DefaultOutport1;
        }
        else {
            Switch1_DefaultOutport1 = Selector1_DefaultOutport1;
        }
        if (Assignment_init == 0) {
            Assignment_init = 1;
            int batchIndex = 0;
            for (batchIndex = 0;batchIndex < 128;batchIndex += 4) {
                int32x4_t Data_StoreRead_DefaultOutport1_Batch = vld1q_s32(Data_StoreRead_DefaultOutport1 + batchIndex);
                vst1q_s32(Assignment_DefaultOutport1 + batchIndex, Data_StoreRead_DefaultOutport1_Batch);
            }
        }
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Switch_DefaultOutport1;
        if (Assignment1_init == 0) {
            Assignment1_init = 1;
            int batchIndex = 0;
            for (batchIndex = 0;batchIndex < 128;batchIndex += 4) {
                int32x4_t Data_StoreRead1_DefaultOutport1_Batch = vld1q_s32(Data_StoreRead1_DefaultOutport1 + batchIndex);
                vst1q_s32(Assignment1_DefaultOutport1 + batchIndex, Data_StoreRead1_DefaultOutport1_Batch);
            }
        }
        Assignment1_DefaultOutport1[For_Iterator_DefaultOutport1] = Switch1_DefaultOutport1;
        int32x4_t ArmId_Batch = vdupq_n_s32(ArmId);
        int32x4_t delta_DefaultOutport1_Batch = vdupq_n_s32(delta_DefaultOutport1);
        int32x4_t T_DefaultOutport1_Batch = vdupq_n_s32(T_DefaultOutport1);
        int32x4_t key_DefaultOutport1_Batch = vdupq_n_s32(key_DefaultOutport1);
        int32x4_t key1_DefaultOutport1_Batch = vdupq_n_s32(key1_DefaultOutport1);
        int batchIndex = 0;
        for (batchIndex = 0;batchIndex < 128;batchIndex += 4) {
            int32x4_t Assignment_DefaultOutport1_Batch = vld1q_s32(Assignment_DefaultOutport1 + batchIndex);
            int32x4_t Assignment1_DefaultOutport1_Batch = vld1q_s32(Assignment1_DefaultOutport1 + batchIndex);
            int32x4_t Add_DefaultOutport1_Batch = {0};
            Add_DefaultOutport1_Batch = vaddq_s32(ArmId_Batch, Assignment_DefaultOutport1_Batch);
            int32x4_t Add1_DefaultOutport1_Batch = {0};
            Add1_DefaultOutport1_Batch = vaddq_s32(Assignment1_DefaultOutport1_Batch, ArmId_Batch);
            int32x4_t Product_DefaultOutport1_Batch = {0};
            Product_DefaultOutport1_Batch = vmulq_s32(delta_DefaultOutport1_Batch, Add_DefaultOutport1_Batch);
            int32x4_t Product1_DefaultOutport1_Batch = {0};
            Product1_DefaultOutport1_Batch = vmulq_s32(Add1_DefaultOutport1_Batch, T_DefaultOutport1_Batch);
            int32x4_t Subtract_DefaultOutport1_Batch = {0};
            Subtract_DefaultOutport1_Batch = vsubq_s32(Product_DefaultOutport1_Batch, key_DefaultOutport1_Batch);
            int32x4_t Subtract1_DefaultOutport1_Batch = {0};
            Subtract1_DefaultOutport1_Batch = vsubq_s32(Product1_DefaultOutport1_Batch, key1_DefaultOutport1_Batch);
            vst1q_s32(Subtract_DefaultOutport1 + batchIndex, Subtract_DefaultOutport1_Batch);
            vst1q_s32(Subtract1_DefaultOutport1 + batchIndex, Subtract1_DefaultOutport1_Batch);
        }
        for (int Data_StoreWrite_i = 0;Data_StoreWrite_i < 128;Data_StoreWrite_i++) {
            PortPool_ArmIdPool[Data_StoreWrite_i] = Assignment_DefaultOutport1[Data_StoreWrite_i];
        }
        for (int Data_StoreWrite1_i = 0;Data_StoreWrite1_i < 128;Data_StoreWrite1_i++) {
            PortPool1_ArmIdPoolF[Data_StoreWrite1_i] = Assignment1_DefaultOutport1[Data_StoreWrite1_i];
        }
        for (int Data_StoreWrite2_i = 0;Data_StoreWrite2_i < 128;Data_StoreWrite2_i++) {
            PortPool2_ArmIdPool_C[Data_StoreWrite2_i] = Subtract_DefaultOutport1[Data_StoreWrite2_i];
        }
        for (int Data_StoreWrite3_i = 0;Data_StoreWrite3_i < 128;Data_StoreWrite3_i++) {
            PortPool3_ArmIdPoolF_C[Data_StoreWrite3_i] = Subtract1_DefaultOutport1[Data_StoreWrite3_i];
        }
    }
}