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
            for (batchIndex = 0;batchIndex < 128;batchIndex += 4) {
                __m128i Data_StoreRead1_DefaultOutport1_Batch = _mm_set_epi32((Data_StoreRead1_DefaultOutport1 + batchIndex)[3], (Data_StoreRead1_DefaultOutport1 + batchIndex)[2], (Data_StoreRead1_DefaultOutport1 + batchIndex)[1], (Data_StoreRead1_DefaultOutport1 + batchIndex)[0]);
                (Assignment1_DefaultOutport1 + batchIndex)[0] = ((int*)&Data_StoreRead1_DefaultOutport1_Batch)[0];
                (Assignment1_DefaultOutport1 + batchIndex)[1] = ((int*)&Data_StoreRead1_DefaultOutport1_Batch)[1];
                (Assignment1_DefaultOutport1 + batchIndex)[2] = ((int*)&Data_StoreRead1_DefaultOutport1_Batch)[2];
                (Assignment1_DefaultOutport1 + batchIndex)[3] = ((int*)&Data_StoreRead1_DefaultOutport1_Batch)[3];
            }
        }
        Assignment1_DefaultOutport1[For_Iterator_DefaultOutport1] = Switch1_DefaultOutport1;
        __m128i ArmId_Batch = _mm_set1_epi32(ArmId);
        __m128i delta_DefaultOutport1_Batch = _mm_set1_epi32(delta_DefaultOutport1);
        __m128i T_DefaultOutport1_Batch = _mm_set1_epi32(T_DefaultOutport1);
        __m128i key_DefaultOutport1_Batch = _mm_set1_epi32(key_DefaultOutport1);
        __m128i key1_DefaultOutport1_Batch = _mm_set1_epi32(key1_DefaultOutport1);
        int batchIndex = 0;
        for (batchIndex = 0;batchIndex < 128;batchIndex += 4) {
            __m128i Assignment_DefaultOutport1_Batch = _mm_set_epi32((Assignment_DefaultOutport1 + batchIndex)[3], (Assignment_DefaultOutport1 + batchIndex)[2], (Assignment_DefaultOutport1 + batchIndex)[1], (Assignment_DefaultOutport1 + batchIndex)[0]);
            __m128i Assignment1_DefaultOutport1_Batch = _mm_set_epi32((Assignment1_DefaultOutport1 + batchIndex)[3], (Assignment1_DefaultOutport1 + batchIndex)[2], (Assignment1_DefaultOutport1 + batchIndex)[1], (Assignment1_DefaultOutport1 + batchIndex)[0]);
            __m128i Add_DefaultOutport1_Batch = {0};
            Add_DefaultOutport1_Batch = _mm_add_epi32(ArmId_Batch, Assignment_DefaultOutport1_Batch);
            __m128i Add1_DefaultOutport1_Batch = {0};
            Add1_DefaultOutport1_Batch = _mm_add_epi32(Assignment1_DefaultOutport1_Batch, ArmId_Batch);
            __m128i Product_DefaultOutport1_Batch = {0};
            Product_DefaultOutport1_Batch = _mm_mul_epi32(delta_DefaultOutport1_Batch, Add_DefaultOutport1_Batch);
            __m128i Product1_DefaultOutport1_Batch = {0};
            Product1_DefaultOutport1_Batch = _mm_mul_epi32(Add1_DefaultOutport1_Batch, T_DefaultOutport1_Batch);
            __m128i Subtract_DefaultOutport1_Batch = {0};
            Subtract_DefaultOutport1_Batch = _mm_sub_epi32(Product_DefaultOutport1_Batch, key_DefaultOutport1_Batch);
            __m128i Subtract1_DefaultOutport1_Batch = {0};
            Subtract1_DefaultOutport1_Batch = _mm_sub_epi32(Product1_DefaultOutport1_Batch, key1_DefaultOutport1_Batch);
            (Subtract_DefaultOutport1 + batchIndex)[0] = ((int*)&Subtract_DefaultOutport1_Batch)[0];
            (Subtract_DefaultOutport1 + batchIndex)[1] = ((int*)&Subtract_DefaultOutport1_Batch)[1];
            (Subtract_DefaultOutport1 + batchIndex)[2] = ((int*)&Subtract_DefaultOutport1_Batch)[2];
            (Subtract_DefaultOutport1 + batchIndex)[3] = ((int*)&Subtract_DefaultOutport1_Batch)[3];
            (Subtract1_DefaultOutport1 + batchIndex)[0] = ((int*)&Subtract1_DefaultOutport1_Batch)[0];
            (Subtract1_DefaultOutport1 + batchIndex)[1] = ((int*)&Subtract1_DefaultOutport1_Batch)[1];
            (Subtract1_DefaultOutport1 + batchIndex)[2] = ((int*)&Subtract1_DefaultOutport1_Batch)[2];
            (Subtract1_DefaultOutport1 + batchIndex)[3] = ((int*)&Subtract1_DefaultOutport1_Batch)[3];
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