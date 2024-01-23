#include "define.h"
struct system_869_state system_869_instance;
void system_869_Init(struct system_869_state* self) {
}
void system_869_Update(struct system_869_state* self, int FindId) {
    int Constant_DefaultOutport1 = 0;
    int * Data_StoreRead_DefaultOutport1 = &(SenserIdData_SenserIdData[0]);
    int * Data_StoreRead2_DefaultOutport1 = &(SenserIdUsed_SenserIdUsed[0]);
    int For_Iterator_DefaultOutport1 = -1;
    int con_value_DefaultOutport1 = 0;
    int delta_DefaultOutport1 = 0;
    int key_DefaultOutport1 = 0;
    int log_DefaultOutport1 = 0;
    bool Equal_DefaultOutport1 = 0;
    int Selector_DefaultOutport1 = 0;
    int Selector1_DefaultOutport1 = 0;
    int Switch_DefaultOutport1 = 0;
    int Switch1_DefaultOutport1 = 0;
    int Assignment_DefaultOutport1[256] = {0};
    unsigned char Assignment_init = 0;
    int Assignment1_DefaultOutport1[256] = {0};
    unsigned char Assignment1_init = 0;
    int Add_DefaultOutport1[256] = {0};
    int Add1_DefaultOutport1[256] = {0};
    int Product_DefaultOutport1[256] = {0};
    int Subtract1_DefaultOutport1[256] = {0};
    int Mod_DefaultOutport1[256] = {0};
    int Subtract_DefaultOutport1[256] = {0};
    int Switch2_DefaultOutport1[256] = {0};
    int Switch3_DefaultOutport1[256] = {0};
    for (int i = 0; i < 256; i++) {
        Constant_DefaultOutport1 = 0;
        For_Iterator_DefaultOutport1++;
        con_value_DefaultOutport1 = 4;
        delta_DefaultOutport1 = 10;
        key_DefaultOutport1 = 4;
        log_DefaultOutport1 = 30001;
        Equal_DefaultOutport1 = FindId == For_Iterator_DefaultOutport1;
        Selector_DefaultOutport1 = Data_StoreRead_DefaultOutport1[For_Iterator_DefaultOutport1];
        Selector1_DefaultOutport1 = Data_StoreRead2_DefaultOutport1[For_Iterator_DefaultOutport1];
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
        int32x4_t FindId_Batch = vdupq_n_s32(FindId);
        int32x4_t key_DefaultOutport1_Batch = vdupq_n_s32(key_DefaultOutport1);
        int32x4_t delta_DefaultOutport1_Batch = vdupq_n_s32(delta_DefaultOutport1);
        int32x4_t log_DefaultOutport1_Batch = vdupq_n_s32(log_DefaultOutport1);
        int32x4_t con_value_DefaultOutport1_Batch = vdupq_n_s32(con_value_DefaultOutport1);
        int batchIndex;
        for (batchIndex = 0; batchIndex < 256; batchIndex++) {
            Add_DefaultOutport1[batchIndex] = FindId + Assignment_DefaultOutport1[batchIndex];
        }
        int batchIndex1;
        for (batchIndex1 = 0; batchIndex1 < 256; batchIndex1++) {
            Add1_DefaultOutport1[batchIndex1] = Assignment1_DefaultOutport1[batchIndex1] + FindId;
        }
        for (int Data_StoreWrite2_i = 0;Data_StoreWrite2_i < 256;Data_StoreWrite2_i++) {
            SenserIdData_SenserIdData[Data_StoreWrite2_i] = Assignment_DefaultOutport1[Data_StoreWrite2_i];
        }
        for (int Data_StoreWrite3_i = 0;Data_StoreWrite3_i < 256;Data_StoreWrite3_i++) {
            SenserIdUsed_SenserIdUsed[Data_StoreWrite3_i] = Assignment1_DefaultOutport1[Data_StoreWrite3_i];
        }
        int batchIndex2;
        for (batchIndex2 = 0; batchIndex2 < 256; batchIndex2++) {
            Product_DefaultOutport1[batchIndex2] = key_DefaultOutport1 * Add_DefaultOutport1[batchIndex2];
        }
        int batchIndex3;
        for (batchIndex3 = 0; batchIndex3 < 256; batchIndex3++) {
            Subtract1_DefaultOutport1[batchIndex3] = Add1_DefaultOutport1[batchIndex3] - delta_DefaultOutport1;
        }
        int batchIndex4;
        for (batchIndex4 = 0; batchIndex4 < 256; batchIndex4++) {
            Mod_DefaultOutport1[batchIndex4] = Subtract1_DefaultOutport1[batchIndex4] % log_DefaultOutport1;
        }
        int batchIndex5;
        for (batchIndex5 = 0; batchIndex5 < 256; batchIndex5++) {
            Subtract_DefaultOutport1[batchIndex5] = Product_DefaultOutport1[batchIndex5] - con_value_DefaultOutport1;
        }
        for (int Switch2_i = 0;Switch2_i < 256;Switch2_i++) {
            if (Subtract_DefaultOutport1[Switch2_i] > 10001) {
                Switch2_DefaultOutport1[Switch2_i] = Subtract_DefaultOutport1[Switch2_i];
            }
            else {
                Switch2_DefaultOutport1[Switch2_i] = Assignment_DefaultOutport1[Switch2_i];
            }
        }
        for (int Switch3_i = 0;Switch3_i < 256;Switch3_i++) {
            if (Subtract1_DefaultOutport1[Switch3_i] > 30001) {
                Switch3_DefaultOutport1[Switch3_i] = Mod_DefaultOutport1[Switch3_i];
            }
            else {
                Switch3_DefaultOutport1[Switch3_i] = Subtract1_DefaultOutport1[Switch3_i];
            }
        }
        for (int Data_StoreWrite4_i = 0;Data_StoreWrite4_i < 256;Data_StoreWrite4_i++) {
            SenserIdUsed1_SenserUsedLog[Data_StoreWrite4_i] = Switch3_DefaultOutport1[Data_StoreWrite4_i];
        }
        for (int Data_StoreWrite5_i = 0;Data_StoreWrite5_i < 256;Data_StoreWrite5_i++) {
            SenserIdData1_SenserIdConfound[Data_StoreWrite5_i] = Switch2_DefaultOutport1[Data_StoreWrite5_i];
        }
    }
}