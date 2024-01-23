#include "define.h"
struct system_833_state system_833_instance;
void system_833_Init(struct system_833_state* self) {
}
void system_833_Update(struct system_833_state* self, int PortId, int FindE) {
    int Constant_DefaultOutport1 = 0;
    int * Data_StoreRead_DefaultOutport1 = &(SenserIdData_SenserIdData[0]);
    int * Data_StoreRead1_DefaultOutport1 = &(SenserIdUsed_SenserIdUsed[0]);
    int For_Iterator_DefaultOutport1 = -1;
    int con_value_DefaultOutport1 = 0;
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
        Constant_DefaultOutport1 = 1;
        For_Iterator_DefaultOutport1++;
        con_value_DefaultOutport1 = 4;
        key_DefaultOutport1 = 4;
        log_DefaultOutport1 = 30001;
        Equal_DefaultOutport1 = FindE == For_Iterator_DefaultOutport1;
        Selector_DefaultOutport1 = Data_StoreRead_DefaultOutport1[For_Iterator_DefaultOutport1];
        Selector1_DefaultOutport1 = Data_StoreRead1_DefaultOutport1[For_Iterator_DefaultOutport1];
        if (Equal_DefaultOutport1 > 0) {
            Switch_DefaultOutport1 = PortId;
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
                __m128i Data_StoreRead_DefaultOutport1_Batch = _mm_set_epi32((Data_StoreRead_DefaultOutport1 + batchIndex)[3], (Data_StoreRead_DefaultOutport1 + batchIndex)[2], (Data_StoreRead_DefaultOutport1 + batchIndex)[1], (Data_StoreRead_DefaultOutport1 + batchIndex)[0]);
                (Assignment_DefaultOutport1 + batchIndex)[0] = ((int*)&Data_StoreRead_DefaultOutport1_Batch)[0];
                (Assignment_DefaultOutport1 + batchIndex)[1] = ((int*)&Data_StoreRead_DefaultOutport1_Batch)[1];
                (Assignment_DefaultOutport1 + batchIndex)[2] = ((int*)&Data_StoreRead_DefaultOutport1_Batch)[2];
                (Assignment_DefaultOutport1 + batchIndex)[3] = ((int*)&Data_StoreRead_DefaultOutport1_Batch)[3];
            }
        }
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Switch_DefaultOutport1;
        if (Assignment1_init == 0) {
            Assignment1_init = 1;
            int batchIndex = 0;
            for (batchIndex = 0;batchIndex < 256;batchIndex += 4) {
                __m128i Data_StoreRead1_DefaultOutport1_Batch = _mm_set_epi32((Data_StoreRead1_DefaultOutport1 + batchIndex)[3], (Data_StoreRead1_DefaultOutport1 + batchIndex)[2], (Data_StoreRead1_DefaultOutport1 + batchIndex)[1], (Data_StoreRead1_DefaultOutport1 + batchIndex)[0]);
                (Assignment1_DefaultOutport1 + batchIndex)[0] = ((int*)&Data_StoreRead1_DefaultOutport1_Batch)[0];
                (Assignment1_DefaultOutport1 + batchIndex)[1] = ((int*)&Data_StoreRead1_DefaultOutport1_Batch)[1];
                (Assignment1_DefaultOutport1 + batchIndex)[2] = ((int*)&Data_StoreRead1_DefaultOutport1_Batch)[2];
                (Assignment1_DefaultOutport1 + batchIndex)[3] = ((int*)&Data_StoreRead1_DefaultOutport1_Batch)[3];
            }
        }
        Assignment1_DefaultOutport1[For_Iterator_DefaultOutport1] = Switch1_DefaultOutport1;
        __m128i PortId_Batch = _mm_set1_epi32(PortId);
        __m128i key_DefaultOutport1_Batch = _mm_set1_epi32(key_DefaultOutport1);
        __m128i FindE_Batch = _mm_set1_epi32(FindE);
        __m128i log_DefaultOutport1_Batch = _mm_set1_epi32(log_DefaultOutport1);
        __m128i con_value_DefaultOutport1_Batch = _mm_set1_epi32(con_value_DefaultOutport1);
        int batchIndex;
        for (batchIndex = 0; batchIndex < 256; batchIndex++) {
            Add_DefaultOutport1[batchIndex] = PortId + Assignment_DefaultOutport1[batchIndex];
        }
        int batchIndex1;
        for (batchIndex1 = 0; batchIndex1 < 256; batchIndex1++) {
            Add1_DefaultOutport1[batchIndex1] = Assignment1_DefaultOutport1[batchIndex1] + PortId;
        }
        for (int Data_StoreWrite_i = 0;Data_StoreWrite_i < 256;Data_StoreWrite_i++) {
            SenserIdData_SenserIdData[Data_StoreWrite_i] = Assignment_DefaultOutport1[Data_StoreWrite_i];
        }
        for (int Data_StoreWrite1_i = 0;Data_StoreWrite1_i < 256;Data_StoreWrite1_i++) {
            SenserIdUsed_SenserIdUsed[Data_StoreWrite1_i] = Assignment1_DefaultOutport1[Data_StoreWrite1_i];
        }
        int batchIndex2;
        for (batchIndex2 = 0; batchIndex2 < 256; batchIndex2++) {
            Product_DefaultOutport1[batchIndex2] = key_DefaultOutport1 * Add_DefaultOutport1[batchIndex2];
        }
        int batchIndex3;
        for (batchIndex3 = 0; batchIndex3 < 256; batchIndex3++) {
            Subtract1_DefaultOutport1[batchIndex3] = Add1_DefaultOutport1[batchIndex3] - FindE;
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
        for (int Data_StoreWrite2_i = 0;Data_StoreWrite2_i < 256;Data_StoreWrite2_i++) {
            SenserIdUsed1_SenserUsedLog[Data_StoreWrite2_i] = Switch3_DefaultOutport1[Data_StoreWrite2_i];
        }
        for (int Data_StoreWrite3_i = 0;Data_StoreWrite3_i < 256;Data_StoreWrite3_i++) {
            SenserIdData1_SenserIdConfound[Data_StoreWrite3_i] = Switch2_DefaultOutport1[Data_StoreWrite3_i];
        }
    }
}