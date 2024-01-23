#include "define.h"
struct system_1441_state system_1441_instance;
void system_1441_Init(struct system_1441_state* self) {
}
void system_1441_Update(struct system_1441_state* self, int FindP, int P1, int P2, int P3) {
    bool CompareTo_Constant_DefaultOutport1 = 0;
    bool CompareTo_Constant1_DefaultOutport1 = 0;
    bool CompareTo_Constant2_DefaultOutport1 = 0;
    int Constant_DefaultOutport1 = 0;
    int Constant1_DefaultOutport1 = 0;
    int Constant2_DefaultOutport1 = 0;
    int Constant3_DefaultOutport1 = 0;
    int * Data_StoreRead_DefaultOutport1 = &(PortPool_ArmIdPool[0]);
    int * Data_StoreRead2_DefaultOutport1 = &(PortPool1_ArmIdPoolF[0]);
    int For_Iterator_DefaultOutport1 = -1;
    float rate1_DefaultOutport1 = 0;
    float rate2_DefaultOutport1 = 0;
    bool Equal_DefaultOutport1 = 0;
    int Selector_DefaultOutport1 = 0;
    int Selector1_DefaultOutport1 = 0;
    int Switch2_DefaultOutport1 = 0;
    int Switch_DefaultOutport1 = 0;
    int Switch3_DefaultOutport1 = 0;
    int Assignment_DefaultOutport1[128] = {0};
    unsigned char Assignment_init = 0;
    int Switch4_DefaultOutport1 = 0;
    int Add2_DefaultOutport1[128] = {0};
    int Switch1_DefaultOutport1 = 0;
    int Assignment1_DefaultOutport1[128] = {0};
    unsigned char Assignment1_init = 0;
    int Product2_DefaultOutport1[128] = {0};
    int Add1_DefaultOutport1[128] = {0};
    int Product1_DefaultOutport1[128] = {0};
    for (int i = 0; i < 128; i++) {
        CompareTo_Constant_DefaultOutport1 = P1 == 6;
        CompareTo_Constant1_DefaultOutport1 = P2 == 7;
        CompareTo_Constant2_DefaultOutport1 = P3 == 8;
        Constant_DefaultOutport1 = 1;
        Constant1_DefaultOutport1 = 6;
        Constant2_DefaultOutport1 = 7;
        Constant3_DefaultOutport1 = 8;
        For_Iterator_DefaultOutport1++;
        rate1_DefaultOutport1 = 3;
        rate2_DefaultOutport1 = 3;
        Equal_DefaultOutport1 = FindP == For_Iterator_DefaultOutport1;
        Selector_DefaultOutport1 = Data_StoreRead_DefaultOutport1[For_Iterator_DefaultOutport1];
        Selector1_DefaultOutport1 = Data_StoreRead2_DefaultOutport1[For_Iterator_DefaultOutport1];
        if (CompareTo_Constant_DefaultOutport1 > 0) {
            Switch2_DefaultOutport1 = Constant1_DefaultOutport1;
        }
        else {
            Switch2_DefaultOutport1 = Constant_DefaultOutport1;
        }
        if (Equal_DefaultOutport1 > 0) {
            Switch_DefaultOutport1 = Constant_DefaultOutport1;
        }
        else {
            Switch_DefaultOutport1 = Selector_DefaultOutport1;
        }
        if (CompareTo_Constant1_DefaultOutport1 > 0) {
            Switch3_DefaultOutport1 = Constant2_DefaultOutport1;
        }
        else {
            Switch3_DefaultOutport1 = Switch2_DefaultOutport1;
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
        if (CompareTo_Constant2_DefaultOutport1 > 0) {
            Switch4_DefaultOutport1 = Constant3_DefaultOutport1;
        }
        else {
            Switch4_DefaultOutport1 = Switch3_DefaultOutport1;
        }
        __m128i Switch4_DefaultOutport1_Batch2 = _mm_set1_epi32(Switch4_DefaultOutport1);
        __m128 rate2_DefaultOutport1_Batch = _mm_set1_ps(rate2_DefaultOutport1);
        int batchIndex = 0;
        for (batchIndex = 0;batchIndex < 128;batchIndex += 4) {
            __m128i Assignment_DefaultOutport1_Batch = _mm_set_epi32((Assignment_DefaultOutport1 + batchIndex)[3], (Assignment_DefaultOutport1 + batchIndex)[2], (Assignment_DefaultOutport1 + batchIndex)[1], (Assignment_DefaultOutport1 + batchIndex)[0]);
            __m128i Add2_DefaultOutport1_Batch = {0};
            Add2_DefaultOutport1_Batch = _mm_add_epi32(Assignment_DefaultOutport1_Batch, Switch4_DefaultOutport1_Batch2);
            __m128i Product2_DefaultOutport1_Batch = {0};
            __m128i rate2_DefaultOutport1_BatchConvert = _mm_cvtps_epi32(rate2_DefaultOutport1_Batch);
            Product2_DefaultOutport1_Batch = _mm_mul_epi32(rate2_DefaultOutport1_BatchConvert, Add2_DefaultOutport1_Batch);
            (Product2_DefaultOutport1 + batchIndex)[0] = ((int*)&Product2_DefaultOutport1_Batch)[0];
            (Product2_DefaultOutport1 + batchIndex)[1] = ((int*)&Product2_DefaultOutport1_Batch)[1];
            (Product2_DefaultOutport1 + batchIndex)[2] = ((int*)&Product2_DefaultOutport1_Batch)[2];
            (Product2_DefaultOutport1 + batchIndex)[3] = ((int*)&Product2_DefaultOutport1_Batch)[3];
        }
        for (int Data_StoreWrite_i = 0;Data_StoreWrite_i < 128;Data_StoreWrite_i++) {
            PortPool_ArmIdPool[Data_StoreWrite_i] = Assignment_DefaultOutport1[Data_StoreWrite_i];
        }
        if (Equal_DefaultOutport1 > 0) {
            Switch1_DefaultOutport1 = Switch4_DefaultOutport1;
        }
        else {
            Switch1_DefaultOutport1 = Selector1_DefaultOutport1;
        }
        if (Assignment1_init == 0) {
            Assignment1_init = 1;
            int batchIndex1 = 0;
            for (batchIndex1 = 0;batchIndex1 < 128;batchIndex1 += 4) {
                __m128i Data_StoreRead2_DefaultOutport1_Batch = _mm_set_epi32((Data_StoreRead2_DefaultOutport1 + batchIndex1)[3], (Data_StoreRead2_DefaultOutport1 + batchIndex1)[2], (Data_StoreRead2_DefaultOutport1 + batchIndex1)[1], (Data_StoreRead2_DefaultOutport1 + batchIndex1)[0]);
                (Assignment1_DefaultOutport1 + batchIndex1)[0] = ((int*)&Data_StoreRead2_DefaultOutport1_Batch)[0];
                (Assignment1_DefaultOutport1 + batchIndex1)[1] = ((int*)&Data_StoreRead2_DefaultOutport1_Batch)[1];
                (Assignment1_DefaultOutport1 + batchIndex1)[2] = ((int*)&Data_StoreRead2_DefaultOutport1_Batch)[2];
                (Assignment1_DefaultOutport1 + batchIndex1)[3] = ((int*)&Data_StoreRead2_DefaultOutport1_Batch)[3];
            }
        }
        Assignment1_DefaultOutport1[For_Iterator_DefaultOutport1] = Switch1_DefaultOutport1;
        __m128i Switch4_DefaultOutport1_Batch = _mm_set1_epi32(Switch4_DefaultOutport1);
        __m128 rate1_DefaultOutport1_Batch = _mm_set1_ps(rate1_DefaultOutport1);
        int batchIndex1 = 0;
        for (batchIndex1 = 0;batchIndex1 < 128;batchIndex1 += 4) {
            __m128i Assignment1_DefaultOutport1_Batch = _mm_set_epi32((Assignment1_DefaultOutport1 + batchIndex1)[3], (Assignment1_DefaultOutport1 + batchIndex1)[2], (Assignment1_DefaultOutport1 + batchIndex1)[1], (Assignment1_DefaultOutport1 + batchIndex1)[0]);
            __m128i Add1_DefaultOutport1_Batch = {0};
            Add1_DefaultOutport1_Batch = _mm_add_epi32(Assignment1_DefaultOutport1_Batch, Switch4_DefaultOutport1_Batch);
            __m128i Product1_DefaultOutport1_Batch = {0};
            __m128i rate1_DefaultOutport1_BatchConvert = _mm_cvtps_epi32(rate1_DefaultOutport1_Batch);
            Product1_DefaultOutport1_Batch = _mm_mul_epi32(rate1_DefaultOutport1_BatchConvert, Add1_DefaultOutport1_Batch);
            (Product1_DefaultOutport1 + batchIndex1)[0] = ((int*)&Product1_DefaultOutport1_Batch)[0];
            (Product1_DefaultOutport1 + batchIndex1)[1] = ((int*)&Product1_DefaultOutport1_Batch)[1];
            (Product1_DefaultOutport1 + batchIndex1)[2] = ((int*)&Product1_DefaultOutport1_Batch)[2];
            (Product1_DefaultOutport1 + batchIndex1)[3] = ((int*)&Product1_DefaultOutport1_Batch)[3];
        }
        for (int Data_StoreWrite1_i = 0;Data_StoreWrite1_i < 128;Data_StoreWrite1_i++) {
            PortPool1_ArmIdPoolF[Data_StoreWrite1_i] = Assignment1_DefaultOutport1[Data_StoreWrite1_i];
        }
        for (int Data_StoreWrite2_i = 0;Data_StoreWrite2_i < 128;Data_StoreWrite2_i++) {
            angle_Angle[Data_StoreWrite2_i] = Product2_DefaultOutport1[Data_StoreWrite2_i];
        }
        for (int Data_StoreWrite3_i = 0;Data_StoreWrite3_i < 128;Data_StoreWrite3_i++) {
            angle1_AngleF[Data_StoreWrite3_i] = Product1_DefaultOutport1[Data_StoreWrite3_i];
        }
    }
}