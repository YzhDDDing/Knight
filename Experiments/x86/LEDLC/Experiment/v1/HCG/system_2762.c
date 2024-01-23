#include "define.h"
struct system_2762_state system_2762_instance;
void system_2762_Init(struct system_2762_state* self) {
}
void system_2762_Update(struct system_2762_state* self) {
    int Constant_DefaultOutport1 = 0;
    float Constant1_DefaultOutport1 = 0;
    float Constant2_DefaultOutport1 = 0;
    int Constant3_DefaultOutport1 = 0;
    int Constant4_DefaultOutport1 = 0;
    float * Data_StoreRead_DefaultOutport1 = &(Data_StoreMemory_Data[0]);
    int Data_StoreRead1_DefaultOutport1 = 0;
    int * Data_StoreRead2_DefaultOutport1 = &(Data_StoreMemory6_Satisfied[0]);
    int For_Iterator_DefaultOutport1 = -1;
    float T_DefaultOutport1 = 0;
    int delta_DefaultOutport1 = 0;
    int Add_Constant1_DefaultOutport1 = 0;
    float Selector_DefaultOutport1 = 0;
    int Switch_DefaultOutport1 = 0;
    float Selector1_DefaultOutport1 = 0;
    float Add_DefaultOutport1 = 0;
    float Gain_DefaultOutport1 = 0;
    bool RelationalOperator_DefaultOutport1 = 0;
    bool RelationalOperator1_DefaultOutport1 = 0;
    bool AND_DefaultOutport1 = 0;
    int Switch1_DefaultOutport1 = 0;
    int Switch2_DefaultOutport1 = 0;
    int Assignment_DefaultOutport1[64] = {0};
    unsigned char Assignment_init = 0;
    int Add1_DefaultOutport1[64] = {0};
    int Product_DefaultOutport1[64] = {0};
    int Switch3_DefaultOutport1[64] = {0};
    for (int i = 0; i < 64; i++) {
        Constant_DefaultOutport1 = 0;
        Constant1_DefaultOutport1 = 18.4;
        Constant2_DefaultOutport1 = 1.2;
        Constant3_DefaultOutport1 = 1;
        Constant4_DefaultOutport1 = 0;
        Data_StoreRead1_DefaultOutport1 = Data_StoreMemory4_Terminate;
        For_Iterator_DefaultOutport1++;
        T_DefaultOutport1 = 2;
        delta_DefaultOutport1 = 2;
        Add_Constant1_DefaultOutport1 = For_Iterator_DefaultOutport1 + -1;
        Selector_DefaultOutport1 = Data_StoreRead_DefaultOutport1[For_Iterator_DefaultOutport1];
        if (For_Iterator_DefaultOutport1 != 0) {
            Switch_DefaultOutport1 = Add_Constant1_DefaultOutport1;
        }
        else {
            Switch_DefaultOutport1 = For_Iterator_DefaultOutport1;
        }
        Selector1_DefaultOutport1 = Data_StoreRead_DefaultOutport1[Switch_DefaultOutport1];
        Add_DefaultOutport1 = Selector_DefaultOutport1 + Selector1_DefaultOutport1;
        Gain_DefaultOutport1 = 2.34 * Add_DefaultOutport1;
        RelationalOperator_DefaultOutport1 = Gain_DefaultOutport1 <= Constant1_DefaultOutport1;
        RelationalOperator1_DefaultOutport1 = Gain_DefaultOutport1 >= Constant2_DefaultOutport1;
        AND_DefaultOutport1 = (RelationalOperator_DefaultOutport1 && RelationalOperator1_DefaultOutport1);
        if (AND_DefaultOutport1 > 0) {
            Switch1_DefaultOutport1 = Data_StoreRead1_DefaultOutport1;
        }
        else {
            Switch1_DefaultOutport1 = Constant_DefaultOutport1;
        }
        if (AND_DefaultOutport1 > 0) {
            Switch2_DefaultOutport1 = Constant3_DefaultOutport1;
        }
        else {
            Switch2_DefaultOutport1 = Constant4_DefaultOutport1;
        }
        if (Assignment_init == 0) {
            Assignment_init = 1;
            int batchIndex = 0;
            for (batchIndex = 0;batchIndex < 64;batchIndex += 4) {
                __m128i Data_StoreRead2_DefaultOutport1_Batch = _mm_set_epi32((Data_StoreRead2_DefaultOutport1 + batchIndex)[3], (Data_StoreRead2_DefaultOutport1 + batchIndex)[2], (Data_StoreRead2_DefaultOutport1 + batchIndex)[1], (Data_StoreRead2_DefaultOutport1 + batchIndex)[0]);
                (Assignment_DefaultOutport1 + batchIndex)[0] = ((int*)&Data_StoreRead2_DefaultOutport1_Batch)[0];
                (Assignment_DefaultOutport1 + batchIndex)[1] = ((int*)&Data_StoreRead2_DefaultOutport1_Batch)[1];
                (Assignment_DefaultOutport1 + batchIndex)[2] = ((int*)&Data_StoreRead2_DefaultOutport1_Batch)[2];
                (Assignment_DefaultOutport1 + batchIndex)[3] = ((int*)&Data_StoreRead2_DefaultOutport1_Batch)[3];
            }
        }
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Switch2_DefaultOutport1;
        Data_StoreMemory4_Terminate = Switch1_DefaultOutport1;
        __m128 T_DefaultOutport1_Batch = _mm_set1_ps(T_DefaultOutport1);
        __m128i delta_DefaultOutport1_Batch = _mm_set1_epi32(delta_DefaultOutport1);
        int batchIndex = 0;
        for (batchIndex = 0;batchIndex < 64;batchIndex += 4) {
            __m128i Assignment_DefaultOutport1_Batch = _mm_set_epi32((Assignment_DefaultOutport1 + batchIndex)[3], (Assignment_DefaultOutport1 + batchIndex)[2], (Assignment_DefaultOutport1 + batchIndex)[1], (Assignment_DefaultOutport1 + batchIndex)[0]);
            __m128i Add1_DefaultOutport1_Batch = {0};
            __m128i T_DefaultOutport1_BatchConvert = _mm_cvtps_epi32(T_DefaultOutport1_Batch);
            Add1_DefaultOutport1_Batch = _mm_add_epi32(Assignment_DefaultOutport1_Batch, T_DefaultOutport1_BatchConvert);
            __m128i Product_DefaultOutport1_Batch = {0};
            Product_DefaultOutport1_Batch = _mm_mul_epi32(Add1_DefaultOutport1_Batch, delta_DefaultOutport1_Batch);
            (Product_DefaultOutport1 + batchIndex)[0] = ((int*)&Product_DefaultOutport1_Batch)[0];
            (Product_DefaultOutport1 + batchIndex)[1] = ((int*)&Product_DefaultOutport1_Batch)[1];
            (Product_DefaultOutport1 + batchIndex)[2] = ((int*)&Product_DefaultOutport1_Batch)[2];
            (Product_DefaultOutport1 + batchIndex)[3] = ((int*)&Product_DefaultOutport1_Batch)[3];
        }
        for (int Data_StoreWrite1_i = 0;Data_StoreWrite1_i < 64;Data_StoreWrite1_i++) {
            Data_StoreMemory6_Satisfied[Data_StoreWrite1_i] = Assignment_DefaultOutport1[Data_StoreWrite1_i];
        }
        for (int Switch3_i = 0;Switch3_i < 64;Switch3_i++) {
            if (Assignment_DefaultOutport1[Switch3_i] > 144) {
                Switch3_DefaultOutport1[Switch3_i] = Assignment_DefaultOutport1[Switch3_i];
            }
            else {
                Switch3_DefaultOutport1[Switch3_i] = Product_DefaultOutport1[Switch3_i];
            }
        }
        for (int Data_StoreWrite2_i = 0;Data_StoreWrite2_i < 64;Data_StoreWrite2_i++) {
            Data_StoreMemory9_Sat_o[Data_StoreWrite2_i] = Switch3_DefaultOutport1[Data_StoreWrite2_i];
        }
    }
}