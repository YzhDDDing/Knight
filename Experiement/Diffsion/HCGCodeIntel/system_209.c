#include "define.h"
struct system_209_state system_209_instance;
void system_209_Init(struct system_209_state* self) {
}
void system_209_Update(struct system_209_state* self, int Output[64]) {
    int Constant1_DefaultOutport = 11;
    int Constant2_DefaultOutport = 5;
    int Constant3_DefaultOutport = 3;
    int Constant4_DefaultOutport = 0;
    int Assignment_DefaultOutport1[64];
    int Selector_DefaultOutport1[64];
    int Selector1_DefaultOutport1[64];
    int Productor1_DefaultOutport1[64];
    int Add_DefaultOutport1[64];
    int Add1_DefaultOutport1[64];
    int Productor2_DefaultOutport1[64];
    int Productor3_DefaultOutport1[64];
    int Switch_DefaultOutport1[64];
    unsigned char Assignment_init = 0;
    int For_Iterator_DefaultOutport1 = -1;
    int batchIndex1;
    int batchIndex2;
    int batchIndex3;
    for (int i = 0; i < 64; i++) {
        For_Iterator_DefaultOutport1++;
        if (Assignment_init == 0) {
            Assignment_init = 1;
            for (batchIndex1 = 0; batchIndex1 < 64; batchIndex1 += 8) {
                __m256i A_batch = _mm256_loadu_si256((__m256i*)&A_state[batchIndex1]);
                _mm256_storeu_si256((__m256i*)&Assignment_DefaultOutport1[batchIndex1], A_batch);
            }
        }
        Selector_DefaultOutport1[For_Iterator_DefaultOutport1] = A_state[For_Iterator_DefaultOutport1];
        Selector1_DefaultOutport1[For_Iterator_DefaultOutport1] = B_state[For_Iterator_DefaultOutport1];
        Productor1_DefaultOutport1[For_Iterator_DefaultOutport1] = Selector_DefaultOutport1[For_Iterator_DefaultOutport1] * Constant2_DefaultOutport;
        Add_DefaultOutport1[For_Iterator_DefaultOutport1] = Constant1_DefaultOutport + Selector1_DefaultOutport1[For_Iterator_DefaultOutport1] - Productor1_DefaultOutport1[For_Iterator_DefaultOutport1];
        Productor2_DefaultOutport1[For_Iterator_DefaultOutport1] = Add_DefaultOutport1[For_Iterator_DefaultOutport1] * Selector1_DefaultOutport1[For_Iterator_DefaultOutport1];
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Productor2_DefaultOutport1[For_Iterator_DefaultOutport1];
        __m256i const3_vec = _mm256_set1_epi32(Constant3_DefaultOutport);
        __m256i const4_vec = _mm256_set1_epi32(Constant4_DefaultOutport);
        for (batchIndex2 = 0; batchIndex2 < 64; batchIndex2 += 8) {
            __m256i assignment_vec = _mm256_loadu_si256((__m256i*)&(Assignment_DefaultOutport1[batchIndex2]));
            __m256i add1_vec = _mm256_add_epi32(assignment_vec, const3_vec);
            _mm256_storeu_si256((__m256i*)&(Add1_DefaultOutport1[batchIndex2]), add1_vec);
            __m256i productor3_vec = _mm256_mullo_epi32(add1_vec, const3_vec);
            __m256i mask = _mm256_cmpgt_epi32(productor3_vec, const4_vec);
            __m256i switch_vec = _mm256_blendv_epi8(const4_vec, productor3_vec, mask);
            _mm256_storeu_si256((__m256i*)&(Switch_DefaultOutport1[batchIndex2]), switch_vec);
        }
    }
    for(batchIndex3 = 0; batchIndex3 < 64; batchIndex3 += 8) {
        __m256i Switch_DefaultOutport1_batch = _mm256_loadu_si256((__m256i*)&Switch_DefaultOutport1[batchIndex3]);
        _mm256_storeu_si256((__m256i*)&Output[batchIndex3], Switch_DefaultOutport1_batch);
    }
}