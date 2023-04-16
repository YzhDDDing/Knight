#include "define.h"
struct system_34_state system_34_instance;
void system_34_Init(struct system_34_state* self) {
}
void system_34_Update(struct system_34_state* self, int Inport[32], int Output[64]) {
    int Constant_DefaultOutport1;
    int Constant2_DefaultOutport1;
    int Constant3_DefaultOutport1;
    int For_Iterator_DefaultOutport1 = -1;
    int Selector_DefaultOutport1;
    int Assignment_DefaultOutport1[64];
    int Add_DefaultOutport1[64];
    int Product_DefaultOutport1[64];
    int Switch_DefaultOutport1[64];
    unsigned char Assignment_init = 0;
    int batchIndex;
    int batchIndex2;
    int batchIndex3;
    for (int i = 0; i < 32; i++) {
        Constant_DefaultOutport1 = 3;
        Constant2_DefaultOutport1 = 0;
        Constant3_DefaultOutport1 = 11;
        For_Iterator_DefaultOutport1++;
        Selector_DefaultOutport1 = Inport[For_Iterator_DefaultOutport1];
        if (For_Iterator_DefaultOutport1 == 0) {
            for (batchIndex = 0; batchIndex < 64; batchIndex+=8) {
                __m256i signal_state_Batch = _mm256_loadu_si256((__m256i*)&signal_state[batchIndex]);
                _mm256_storeu_si256((__m256i*)&Assignment_DefaultOutport1[batchIndex], signal_state_Batch);
            }
        }
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Selector_DefaultOutport1;
        __m256i Constant_DefaultOutport1_Batch = _mm256_set1_epi32(Constant_DefaultOutport1);
        __m256i Constant3_DefaultOutport1_Batch = _mm256_set1_epi32(Constant3_DefaultOutport1);
        __m256i Constant2_DefaultOutport1_Batch = _mm256_set1_epi32(Constant2_DefaultOutport1);
        
        __m256i Switch_Cmp = _mm256_set1_epi32(32);
        for (batchIndex2 = 0; batchIndex2 < 64; batchIndex2 += 8) {
            __m256i Assignment_DefaultOutport1_Batch = _mm256_loadu_si256((__m256i*)&Assignment_DefaultOutport1[batchIndex2]);
            __m256i Add_DefaultOutport1_Batch = _mm256_add_epi32(Assignment_DefaultOutport1_Batch, Constant_DefaultOutport1_Batch);
            __m256i Product_DefaultOutport1_Batch = _mm256_mullo_epi32(Add_DefaultOutport1_Batch, Constant3_DefaultOutport1_Batch);
            __m256i Switch_DefaultOutport1_Mask = _mm256_cmpgt_epi32(Product_DefaultOutport1_Batch, Switch_Cmp);
            __m256i Switch_DefaultOutport1_Batch = _mm256_blendv_epi8(Constant2_DefaultOutport1_Batch, Product_DefaultOutport1_Batch, Switch_DefaultOutport1_Mask);
            _mm256_storeu_si256((__m256i*)&Switch_DefaultOutport1[batchIndex2], Switch_DefaultOutport1_Batch);
        }
    }
    for(batchIndex3 = 0; batchIndex3 < 64; batchIndex3+=8) {
        __m256i Switch_DefaultOutport1_Batch = _mm256_loadu_si256((__m256i*)&Switch_DefaultOutport1[batchIndex3]);
        _mm256_storeu_si256((__m256i*)&Output[batchIndex3], Switch_DefaultOutport1_Batch);
    }
}