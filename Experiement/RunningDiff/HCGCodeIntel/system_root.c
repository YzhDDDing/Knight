#include "define.h"
double Difference_PreviousValue;
struct system_root_state system_root_instance;

void system_root_Init(struct system_root_state *self) {
}

void system_root_Update(struct system_root_state *self, double In1[128],  double In2[128], double Out1[8]) {
    int batchIndex1;
    int batchIndex2;
    double Add_DefaultOutport1[128];
    double Difference_DefaultOutport1[128];
    double Selector_DefaultOutport1[8];
    Difference_DefaultOutport1[0] = In1[0] - Difference_PreviousValue;
    int Difference_i;
    for (Difference_i = 1; Difference_i + 3 < 128; Difference_i+=4) {
        __m256d Difference_a = _mm256_loadu_pd(&In1[Difference_i]);
        __m256d Difference_b = _mm256_loadu_pd(&In1[Difference_i - 1]);
        __m256d Difference_DefaultOutport1_Batch = _mm256_sub_pd(Difference_a, Difference_b);
        _mm256_storeu_pd(&Difference_DefaultOutport1[Difference_i], Difference_DefaultOutport1_Batch);
    }
    for (; Difference_i < 128; Difference_i++) {
        Difference_DefaultOutport1[Difference_i] = &In1[Difference_i] - &In1[Difference_i - 1];
    }
    Difference_PreviousValue = In1[127];
    for (batchIndex1 = 0; batchIndex1 < 128; batchIndex1+=4) {
        __m256d Difference_DefaultOutport1_Batch = _mm256_loadu_pd(&Difference_DefaultOutport1[batchIndex1]);
        __m256d In2_Batch = _mm256_loadu_pd(&In2[batchIndex1]);
        __m256d Add_DefaultOutport1_Batch = _mm256_add_pd(Difference_DefaultOutport1_Batch, In2_Batch);
        _mm256_storeu_pd(&Add_DefaultOutport1[batchIndex1], Add_DefaultOutport1_Batch);
    }
    Selector_DefaultOutport1[0] = Add_DefaultOutport1[1];
    Selector_DefaultOutport1[1] = Add_DefaultOutport1[16];
    Selector_DefaultOutport1[2] = Add_DefaultOutport1[33];
    Selector_DefaultOutport1[3] = Add_DefaultOutport1[45];
    Selector_DefaultOutport1[4] = Add_DefaultOutport1[71];
    Selector_DefaultOutport1[5] = Add_DefaultOutport1[86];
    Selector_DefaultOutport1[6] = Add_DefaultOutport1[103];
    Selector_DefaultOutport1[7] = Add_DefaultOutport1[122];
    for (batchIndex2 =0; batchIndex2 < 8; batchIndex2+=4) {
        __m256d Selector_DefaultOutport1_Batch = _mm256_loadu_pd(&Selector_DefaultOutport1[batchIndex2]);
        _mm256_storeu_pd(&Out1[batchIndex2], Selector_DefaultOutport1_Batch);
    }
}