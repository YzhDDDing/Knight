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
                __m128 Data_StoreRead_DefaultOutport1_Batch = _mm_load_ps(Data_StoreRead_DefaultOutport1 + batchIndex);
                _mm_store_ps(Assignment_DefaultOutport1 + batchIndex, Data_StoreRead_DefaultOutport1_Batch);
            }
        }
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Constant2_DefaultOutport1;
        if (Assignment1_init == 0) {
            Assignment1_init = 1;
            int batchIndex = 0;
            for (batchIndex = 0;batchIndex < 64;batchIndex += 4) {
                __m128i Data_StoreRead1_DefaultOutport1_Batch = _mm_set_epi32((Data_StoreRead1_DefaultOutport1 + batchIndex)[3], (Data_StoreRead1_DefaultOutport1 + batchIndex)[2], (Data_StoreRead1_DefaultOutport1 + batchIndex)[1], (Data_StoreRead1_DefaultOutport1 + batchIndex)[0]);
                (Assignment1_DefaultOutport1 + batchIndex)[0] = ((int*)&Data_StoreRead1_DefaultOutport1_Batch)[0];
                (Assignment1_DefaultOutport1 + batchIndex)[1] = ((int*)&Data_StoreRead1_DefaultOutport1_Batch)[1];
                (Assignment1_DefaultOutport1 + batchIndex)[2] = ((int*)&Data_StoreRead1_DefaultOutport1_Batch)[2];
                (Assignment1_DefaultOutport1 + batchIndex)[3] = ((int*)&Data_StoreRead1_DefaultOutport1_Batch)[3];
            }
        }
        Assignment1_DefaultOutport1[For_Iterator_DefaultOutport1] = Constant1_DefaultOutport1;
        __m128 delta_DefaultOutport1_Batch = _mm_set1_ps(delta_DefaultOutport1);
        __m128i shift_DefaultOutport1_Batch = _mm_set1_epi32(shift_DefaultOutport1);
        int batchIndex = 0;
        for (batchIndex = 0;batchIndex < 64;batchIndex += 4) {
            __m128 Assignment_DefaultOutport1_Batch = _mm_load_ps(Assignment_DefaultOutport1 + batchIndex);
            __m128i Assignment1_DefaultOutport1_Batch = _mm_set_epi32((Assignment1_DefaultOutport1 + batchIndex)[3], (Assignment1_DefaultOutport1 + batchIndex)[2], (Assignment1_DefaultOutport1 + batchIndex)[1], (Assignment1_DefaultOutport1 + batchIndex)[0]);
            __m128 Add_DefaultOutport1_Batch = {0};
            Add_DefaultOutport1_Batch = _mm_add_ps(delta_DefaultOutport1_Batch, Assignment_DefaultOutport1_Batch);
            __m128i Add1_DefaultOutport1_Batch = {0};
            Add1_DefaultOutport1_Batch = _mm_add_epi32(Assignment1_DefaultOutport1_Batch, shift_DefaultOutport1_Batch);
            _mm_store_ps(Add_DefaultOutport1 + batchIndex, Add_DefaultOutport1_Batch);
            (Add1_DefaultOutport1 + batchIndex)[0] = ((int*)&Add1_DefaultOutport1_Batch)[0];
            (Add1_DefaultOutport1 + batchIndex)[1] = ((int*)&Add1_DefaultOutport1_Batch)[1];
            (Add1_DefaultOutport1 + batchIndex)[2] = ((int*)&Add1_DefaultOutport1_Batch)[2];
            (Add1_DefaultOutport1 + batchIndex)[3] = ((int*)&Add1_DefaultOutport1_Batch)[3];
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