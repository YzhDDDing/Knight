#include "define.h"
struct system_833_state system_833_instance;
void system_833_Init(struct system_833_state* self) {
}
void system_833_Update(struct system_833_state* self, int PortId, int FindE) {
    int Con_Value_DefaultOutport1 = 0;
    int Con_Value1_DefaultOutport1 = 0;
    int Constant_DefaultOutport1 = 0;
    int * Data_StoreRead_DefaultOutport1 = &(PortPool_PortPool[0]);
    int * Data_StoreRead1_DefaultOutport1 = &(PortPool1_PortPoolF[0]);
    int For_Iterator_DefaultOutport1 = -1;
    int T_DefaultOutport1 = 0;
    float T1_DefaultOutport1 = 0;
    int key_DefaultOutport1 = 0;
    float key1_DefaultOutport1 = 0;
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
        Constant_DefaultOutport1 = 1;
        For_Iterator_DefaultOutport1++;
        T_DefaultOutport1 = 11;
        T1_DefaultOutport1 = 5;
        key_DefaultOutport1 = 1004;
        key1_DefaultOutport1 = 1003;
        Equal_DefaultOutport1 = FindE == For_Iterator_DefaultOutport1;
        Selector_DefaultOutport1 = Data_StoreRead_DefaultOutport1[For_Iterator_DefaultOutport1];
        Selector1_DefaultOutport1 = Data_StoreRead1_DefaultOutport1[For_Iterator_DefaultOutport1];
        Subtract1_DefaultOutport1 = T_DefaultOutport1 - Con_Value_DefaultOutport1;
        Subtract3_DefaultOutport1 = T1_DefaultOutport1 - Con_Value1_DefaultOutport1;
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
        __m128i Con_Value_DefaultOutport1_Batch = _mm_set1_epi32(Con_Value_DefaultOutport1);
        __m128i Con_Value1_DefaultOutport1_Batch = _mm_set1_epi32(Con_Value1_DefaultOutport1);
        __m128i Subtract1_DefaultOutport1_Batch = _mm_set1_epi32(Subtract1_DefaultOutport1);
        __m128i Subtract3_DefaultOutport1_Batch = _mm_set1_epi32(Subtract3_DefaultOutport1);
        __m128i T_DefaultOutport1_Batch = _mm_set1_epi32(T_DefaultOutport1);
        __m128 T1_DefaultOutport1_Batch = _mm_set1_ps(T1_DefaultOutport1);
        __m128i key_DefaultOutport1_Batch = _mm_set1_epi32(key_DefaultOutport1);
        __m128 key1_DefaultOutport1_Batch = _mm_set1_ps(key1_DefaultOutport1);
        int batchIndex = 0;
        for (batchIndex = 0;batchIndex < 256;batchIndex += 4) {
            __m128i Assignment_DefaultOutport1_Batch = _mm_set_epi32((Assignment_DefaultOutport1 + batchIndex)[3], (Assignment_DefaultOutport1 + batchIndex)[2], (Assignment_DefaultOutport1 + batchIndex)[1], (Assignment_DefaultOutport1 + batchIndex)[0]);
            __m128i Assignment1_DefaultOutport1_Batch = _mm_set_epi32((Assignment1_DefaultOutport1 + batchIndex)[3], (Assignment1_DefaultOutport1 + batchIndex)[2], (Assignment1_DefaultOutport1 + batchIndex)[1], (Assignment1_DefaultOutport1 + batchIndex)[0]);
            __m128i Add_DefaultOutport1_Batch = {0};
            Add_DefaultOutport1_Batch = _mm_add_epi32(Con_Value_DefaultOutport1_Batch, Assignment_DefaultOutport1_Batch);
            __m128i Add1_DefaultOutport1_Batch = {0};
            Add1_DefaultOutport1_Batch = _mm_add_epi32(Assignment1_DefaultOutport1_Batch, Con_Value1_DefaultOutport1_Batch);
            __m128i Product1_DefaultOutport1_Batch = {0};
            Product1_DefaultOutport1_Batch = _mm_mul_epi32(Subtract1_DefaultOutport1_Batch, Assignment_DefaultOutport1_Batch);
            __m128i Product3_DefaultOutport1_Batch = {0};
            Product3_DefaultOutport1_Batch = _mm_mul_epi32(Subtract3_DefaultOutport1_Batch, Assignment1_DefaultOutport1_Batch);
            __m128i Product_DefaultOutport1_Batch = {0};
            Product_DefaultOutport1_Batch = _mm_mul_epi32(T_DefaultOutport1_Batch, Add_DefaultOutport1_Batch);
            __m128i Product2_DefaultOutport1_Batch = {0};
            __m128i T1_DefaultOutport1_BatchConvert = _mm_cvtps_epi32(T1_DefaultOutport1_Batch);
            Product2_DefaultOutport1_Batch = _mm_mul_epi32(Add1_DefaultOutport1_Batch, T1_DefaultOutport1_BatchConvert);
            __m128i Subtract_DefaultOutport1_Batch = {0};
            Subtract_DefaultOutport1_Batch = _mm_sub_epi32(Product_DefaultOutport1_Batch, key_DefaultOutport1_Batch);
            __m128i Subtract2_DefaultOutport1_Batch = {0};
            __m128i key1_DefaultOutport1_BatchConvert = _mm_cvtps_epi32(key1_DefaultOutport1_Batch);
            Subtract2_DefaultOutport1_Batch = _mm_sub_epi32(Product2_DefaultOutport1_Batch, key1_DefaultOutport1_BatchConvert);
            (Product1_DefaultOutport1 + batchIndex)[0] = ((int*)&Product1_DefaultOutport1_Batch)[0];
            (Product1_DefaultOutport1 + batchIndex)[1] = ((int*)&Product1_DefaultOutport1_Batch)[1];
            (Product1_DefaultOutport1 + batchIndex)[2] = ((int*)&Product1_DefaultOutport1_Batch)[2];
            (Product1_DefaultOutport1 + batchIndex)[3] = ((int*)&Product1_DefaultOutport1_Batch)[3];
            (Product3_DefaultOutport1 + batchIndex)[0] = ((int*)&Product3_DefaultOutport1_Batch)[0];
            (Product3_DefaultOutport1 + batchIndex)[1] = ((int*)&Product3_DefaultOutport1_Batch)[1];
            (Product3_DefaultOutport1 + batchIndex)[2] = ((int*)&Product3_DefaultOutport1_Batch)[2];
            (Product3_DefaultOutport1 + batchIndex)[3] = ((int*)&Product3_DefaultOutport1_Batch)[3];
            (Subtract_DefaultOutport1 + batchIndex)[0] = ((int*)&Subtract_DefaultOutport1_Batch)[0];
            (Subtract_DefaultOutport1 + batchIndex)[1] = ((int*)&Subtract_DefaultOutport1_Batch)[1];
            (Subtract_DefaultOutport1 + batchIndex)[2] = ((int*)&Subtract_DefaultOutport1_Batch)[2];
            (Subtract_DefaultOutport1 + batchIndex)[3] = ((int*)&Subtract_DefaultOutport1_Batch)[3];
            (Subtract2_DefaultOutport1 + batchIndex)[0] = ((int*)&Subtract2_DefaultOutport1_Batch)[0];
            (Subtract2_DefaultOutport1 + batchIndex)[1] = ((int*)&Subtract2_DefaultOutport1_Batch)[1];
            (Subtract2_DefaultOutport1 + batchIndex)[2] = ((int*)&Subtract2_DefaultOutport1_Batch)[2];
            (Subtract2_DefaultOutport1 + batchIndex)[3] = ((int*)&Subtract2_DefaultOutport1_Batch)[3];
        }
        for (int Data_StoreWrite_i = 0;Data_StoreWrite_i < 256;Data_StoreWrite_i++) {
            PortPool_PortPool[Data_StoreWrite_i] = Assignment_DefaultOutport1[Data_StoreWrite_i];
        }
        for (int Data_StoreWrite1_i = 0;Data_StoreWrite1_i < 256;Data_StoreWrite1_i++) {
            PortPool1_PortPoolF[Data_StoreWrite1_i] = Assignment1_DefaultOutport1[Data_StoreWrite1_i];
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
        for (int Data_StoreWrite2_i = 0;Data_StoreWrite2_i < 256;Data_StoreWrite2_i++) {
            PortPool2_PortConfound[Data_StoreWrite2_i] = Switch2_DefaultOutport1[Data_StoreWrite2_i];
        }
        for (int Data_StoreWrite3_i = 0;Data_StoreWrite3_i < 256;Data_StoreWrite3_i++) {
            PortPool3_PortConfoundF[Data_StoreWrite3_i] = Switch3_DefaultOutport1[Data_StoreWrite3_i];
        }
    }
}