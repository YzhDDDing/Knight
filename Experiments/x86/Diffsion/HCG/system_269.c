#include "define.h"
struct system_269_state system_269_instance;
void system_269_Init(struct system_269_state* self) {
}
void system_269_Update(struct system_269_state* self, float Inport, int Output[32]) {
    int Constant_DefaultOutport1;
    int Constant1_DefaultOutport1;
    int Constant2_DefaultOutport1;
    int Constant3_DefaultOutport1;
    int * Data_StoreRead_DefaultOutport1 = &(Data_StoreMemory2_Di_m1[0]);
    int * Data_StoreRead1_DefaultOutport1 = &(Data_StoreMemory3_Di_m2[0]);
    int For_Iterator_DefaultOutport1 = -1;
    int Selector_DefaultOutport1;
    int Selector1_DefaultOutport1;
    int Product_DefaultOutport1;
    int Add1_DefaultOutport1;
    int Add1_BatchTempVar;
    int Product1_DefaultOutport1;
    int Assignment_DefaultOutport1[32];
    unsigned char Assignment_init = 0;
    int Add_DefaultOutport1[32];
    int Add_BatchTempVar[32];
    int Product2_DefaultOutport1[32];
    int Switch_DefaultOutport1[32];
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
            int batchIndex;
            for (batchIndex = 0;batchIndex < 32;batchIndex += 4) {
                __m128i Data_StoreRead_DefaultOutport1_Batch = _mm_set_epi32((Data_StoreRead_DefaultOutport1 + batchIndex)[3], (Data_StoreRead_DefaultOutport1 + batchIndex)[2], (Data_StoreRead_DefaultOutport1 + batchIndex)[1], (Data_StoreRead_DefaultOutport1 + batchIndex)[0]);
                (Assignment_DefaultOutport1 + batchIndex)[0] = ((int*)&Data_StoreRead_DefaultOutport1_Batch)[0];
                (Assignment_DefaultOutport1 + batchIndex)[1] = ((int*)&Data_StoreRead_DefaultOutport1_Batch)[1];
                (Assignment_DefaultOutport1 + batchIndex)[2] = ((int*)&Data_StoreRead_DefaultOutport1_Batch)[2];
                (Assignment_DefaultOutport1 + batchIndex)[3] = ((int*)&Data_StoreRead_DefaultOutport1_Batch)[3];
            }
        }
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Product1_DefaultOutport1;
        __m128 Inport_Batch = _mm_set1_ps(Inport);
        __m128i Constant_DefaultOutport1_Batch = _mm_set1_epi32(Constant_DefaultOutport1);
        int batchIndex;
        for (batchIndex = 0;batchIndex < 32;batchIndex += 4) {
            __m128i Assignment_DefaultOutport1_Batch = _mm_set_epi32((Assignment_DefaultOutport1 + batchIndex)[3], (Assignment_DefaultOutport1 + batchIndex)[2], (Assignment_DefaultOutport1 + batchIndex)[1], (Assignment_DefaultOutport1 + batchIndex)[0]);
            __m128i Add_BatchTempVar_Batch;
            __m128i Inport_BatchConvert = _mm_cvtps_epi32(Inport_Batch);
            Add_BatchTempVar_Batch = _mm_add_epi32(Inport_BatchConvert, Assignment_DefaultOutport1_Batch);
            __m128i Add_DefaultOutport1_Batch;
            Add_DefaultOutport1_Batch = _mm_add_epi32(Add_BatchTempVar_Batch, Constant_DefaultOutport1_Batch);
            __m128i Product2_DefaultOutport1_Batch;
            Product2_DefaultOutport1_Batch = _mm_mul_epi32(Add_DefaultOutport1_Batch, Constant_DefaultOutport1_Batch);
            (Product2_DefaultOutport1 + batchIndex)[0] = ((int*)&Product2_DefaultOutport1_Batch)[0];
            (Product2_DefaultOutport1 + batchIndex)[1] = ((int*)&Product2_DefaultOutport1_Batch)[1];
            (Product2_DefaultOutport1 + batchIndex)[2] = ((int*)&Product2_DefaultOutport1_Batch)[2];
            (Product2_DefaultOutport1 + batchIndex)[3] = ((int*)&Product2_DefaultOutport1_Batch)[3];
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
    int batchIndex;
    for (batchIndex = 0;batchIndex < 32;batchIndex += 4) {
        __m128i Switch_DefaultOutport1_Batch = _mm_set_epi32((Switch_DefaultOutport1 + batchIndex)[3], (Switch_DefaultOutport1 + batchIndex)[2], (Switch_DefaultOutport1 + batchIndex)[1], (Switch_DefaultOutport1 + batchIndex)[0]);
        (Output + batchIndex)[0] = ((int*)&Switch_DefaultOutport1_Batch)[0];
        (Output + batchIndex)[1] = ((int*)&Switch_DefaultOutport1_Batch)[1];
        (Output + batchIndex)[2] = ((int*)&Switch_DefaultOutport1_Batch)[2];
        (Output + batchIndex)[3] = ((int*)&Switch_DefaultOutport1_Batch)[3];
    }
}