#include "define.h"
struct system_869_state system_869_instance;
void system_869_Init(struct system_869_state* self) {
}
void system_869_Update(struct system_869_state* self, int FindP) {
    int Con_Value_DefaultOutport1 = 0;
    int Con_Value1_DefaultOutport1 = 0;
    int Constant_DefaultOutport1 = 0;
    int * Data_StoreRead_DefaultOutport1 = &(PortPool_PortPool[0]);
    int * Data_StoreRead2_DefaultOutport1 = &(PortPool1_PortPoolF[0]);
    int For_Iterator_DefaultOutport1 = -1;
    int T_DefaultOutport1 = 0;
    int T1_DefaultOutport1 = 0;
    int key_DefaultOutport1 = 0;
    int key1_DefaultOutport1 = 0;
    bool Equal_DefaultOutport1 = 0;
    int Selector_DefaultOutport1 = 0;
    int Selector1_DefaultOutport1 = 0;
    int Subtract1_DefaultOutport1 = 0;
    int Subtract3_DefaultOutport1 = 0;
    int Switch_DefaultOutport1 = 0;
    int Switch1_DefaultOutport1 = 0;
    int Assignment_DefaultOutport1[256] = {0};
    unsigned char Assignment_init = 0;
    int Assignment1_DefaultOutport1[256] = {0};
    unsigned char Assignment1_init = 0;
    int Add_DefaultOutport1[256] = {0};
    int Add1_DefaultOutport1[256] = {0};
    int Product1_DefaultOutport1[256] = {0};
    int Product3_DefaultOutport1[256] = {0};
    int Product_DefaultOutport1[256] = {0};
    int Product2_DefaultOutport1[256] = {0};
    int Subtract_DefaultOutport1[256] = {0};
    int Subtract2_DefaultOutport1[256] = {0};
    int Switch2_DefaultOutport1[256] = {0};
    int Switch3_DefaultOutport1[256] = {0};
    for (int i = 0; i < 256; i++) {
        Con_Value_DefaultOutport1 = 7;
        Con_Value1_DefaultOutport1 = 9;
        Constant_DefaultOutport1 = 0;
        For_Iterator_DefaultOutport1++;
        T_DefaultOutport1 = 11;
        T1_DefaultOutport1 = 5;
        key_DefaultOutport1 = 1004;
        key1_DefaultOutport1 = 1003;
        Equal_DefaultOutport1 = FindP == For_Iterator_DefaultOutport1;
        Selector_DefaultOutport1 = Data_StoreRead_DefaultOutport1[For_Iterator_DefaultOutport1];
        Selector1_DefaultOutport1 = Data_StoreRead2_DefaultOutport1[For_Iterator_DefaultOutport1];
        Subtract1_DefaultOutport1 = T_DefaultOutport1 - Con_Value_DefaultOutport1;
        Subtract3_DefaultOutport1 = T1_DefaultOutport1 - Con_Value1_DefaultOutport1;
        if (Equal_DefaultOutport1 > 0) {
            Switch_DefaultOutport1 = Constant_DefaultOutport1;
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
            for (batchIndex = 0;batchIndex < 256;batchIndex += 4) {
                int32x4_t Data_StoreRead_DefaultOutport1_Batch = vld1q_s32(Data_StoreRead_DefaultOutport1 + batchIndex);
                vst1q_s32(Assignment_DefaultOutport1 + batchIndex, Data_StoreRead_DefaultOutport1_Batch);
            }
        }
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Switch_DefaultOutport1;
        if (Assignment1_init == 0) {
            Assignment1_init = 1;
            int batchIndex = 0;
            for (batchIndex = 0;batchIndex < 256;batchIndex += 4) {
                int32x4_t Data_StoreRead2_DefaultOutport1_Batch = vld1q_s32(Data_StoreRead2_DefaultOutport1 + batchIndex);
                vst1q_s32(Assignment1_DefaultOutport1 + batchIndex, Data_StoreRead2_DefaultOutport1_Batch);
            }
        }
        Assignment1_DefaultOutport1[For_Iterator_DefaultOutport1] = Switch1_DefaultOutport1;
        int32x4_t Con_Value_DefaultOutport1_Batch = vdupq_n_s32(Con_Value_DefaultOutport1);
        int32x4_t Con_Value1_DefaultOutport1_Batch = vdupq_n_s32(Con_Value1_DefaultOutport1);
        int32x4_t Subtract1_DefaultOutport1_Batch = vdupq_n_s32(Subtract1_DefaultOutport1);
        int32x4_t Subtract3_DefaultOutport1_Batch = vdupq_n_s32(Subtract3_DefaultOutport1);
        int32x4_t T_DefaultOutport1_Batch = vdupq_n_s32(T_DefaultOutport1);
        int32x4_t T1_DefaultOutport1_Batch = vdupq_n_s32(T1_DefaultOutport1);
        int32x4_t key_DefaultOutport1_Batch = vdupq_n_s32(key_DefaultOutport1);
        int32x4_t key1_DefaultOutport1_Batch = vdupq_n_s32(key1_DefaultOutport1);
        int batchIndex = 0;
        for (batchIndex = 0;batchIndex < 256;batchIndex += 4) {
            int32x4_t Assignment_DefaultOutport1_Batch = vld1q_s32(Assignment_DefaultOutport1 + batchIndex);
            int32x4_t Assignment1_DefaultOutport1_Batch = vld1q_s32(Assignment1_DefaultOutport1 + batchIndex);
            int32x4_t Add_DefaultOutport1_Batch = {0};
            Add_DefaultOutport1_Batch = vaddq_s32(Con_Value_DefaultOutport1_Batch, Assignment_DefaultOutport1_Batch);
            int32x4_t Add1_DefaultOutport1_Batch = {0};
            Add1_DefaultOutport1_Batch = vaddq_s32(Assignment1_DefaultOutport1_Batch, Con_Value1_DefaultOutport1_Batch);
            int32x4_t Product1_DefaultOutport1_Batch = {0};
            Product1_DefaultOutport1_Batch = vmulq_s32(Subtract1_DefaultOutport1_Batch, Assignment_DefaultOutport1_Batch);
            int32x4_t Product3_DefaultOutport1_Batch = {0};
            Product3_DefaultOutport1_Batch = vmulq_s32(Subtract3_DefaultOutport1_Batch, Assignment1_DefaultOutport1_Batch);
            int32x4_t Product_DefaultOutport1_Batch = {0};
            Product_DefaultOutport1_Batch = vmulq_s32(T_DefaultOutport1_Batch, Add_DefaultOutport1_Batch);
            int32x4_t Product2_DefaultOutport1_Batch = {0};
            Product2_DefaultOutport1_Batch = vmulq_s32(Add1_DefaultOutport1_Batch, T1_DefaultOutport1_Batch);
            int32x4_t Subtract_DefaultOutport1_Batch = {0};
            Subtract_DefaultOutport1_Batch = vsubq_s32(Product_DefaultOutport1_Batch, key_DefaultOutport1_Batch);
            int32x4_t Subtract2_DefaultOutport1_Batch = {0};
            Subtract2_DefaultOutport1_Batch = vsubq_s32(Product2_DefaultOutport1_Batch, key1_DefaultOutport1_Batch);
            vst1q_s32(Product1_DefaultOutport1 + batchIndex, Product1_DefaultOutport1_Batch);
            vst1q_s32(Product3_DefaultOutport1 + batchIndex, Product3_DefaultOutport1_Batch);
            vst1q_s32(Subtract_DefaultOutport1 + batchIndex, Subtract_DefaultOutport1_Batch);
            vst1q_s32(Subtract2_DefaultOutport1 + batchIndex, Subtract2_DefaultOutport1_Batch);
        }
        for (int Data_StoreWrite2_i = 0;Data_StoreWrite2_i < 256;Data_StoreWrite2_i++) {
            PortPool_PortPool[Data_StoreWrite2_i] = Assignment_DefaultOutport1[Data_StoreWrite2_i];
        }
        for (int Data_StoreWrite3_i = 0;Data_StoreWrite3_i < 256;Data_StoreWrite3_i++) {
            PortPool1_PortPoolF[Data_StoreWrite3_i] = Assignment1_DefaultOutport1[Data_StoreWrite3_i];
        }
        for (int Switch2_i = 0;Switch2_i < 256;Switch2_i++) {
            if (Subtract_DefaultOutport1[Switch2_i] > 1000) {
                Switch2_DefaultOutport1[Switch2_i] = Product1_DefaultOutport1[Switch2_i];
            }
            else {
                Switch2_DefaultOutport1[Switch2_i] = Assignment_DefaultOutport1[Switch2_i];
            }
        }
        for (int Switch3_i = 0;Switch3_i < 256;Switch3_i++) {
            if (Subtract2_DefaultOutport1[Switch3_i] > 1000) {
                Switch3_DefaultOutport1[Switch3_i] = Product3_DefaultOutport1[Switch3_i];
            }
            else {
                Switch3_DefaultOutport1[Switch3_i] = Assignment1_DefaultOutport1[Switch3_i];
            }
        }
        for (int Data_StoreWrite4_i = 0;Data_StoreWrite4_i < 256;Data_StoreWrite4_i++) {
            PortPool2_PortConfound[Data_StoreWrite4_i] = Switch2_DefaultOutport1[Data_StoreWrite4_i];
        }
        for (int Data_StoreWrite5_i = 0;Data_StoreWrite5_i < 256;Data_StoreWrite5_i++) {
            PortPool3_PortConfoundF[Data_StoreWrite5_i] = Switch3_DefaultOutport1[Data_StoreWrite5_i];
        }
    }
}