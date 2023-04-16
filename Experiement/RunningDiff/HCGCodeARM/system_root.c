#include "define.h"
double Difference_PreviousValue;
struct system_root_state system_root_instance;

void system_root_Init(struct system_root_state* self) {
}
void system_root_Update(struct system_root_state* self, double In1[128], double In2[128], double Out1[8]) {
    int batchIndex1;
    int batchIndex2;
    double Add_DefaultOutport1[128];
    double Difference_DefaultOutport1[128];
    double Selector_DefaultOutport1[8];
    Difference_DefaultOutport1[0] = In1[0] - Difference_PreviousValue;
    int Difference_i;
    for (Difference_i = 1; Difference_i + 1 < 128; Difference_i+=2) {
        float64x2_t Difference_a = vld1q_f64(&In1[Difference_i]);
        float64x2_t Difference_b = vld1q_f64(&In1[Difference_i - 1]);
        float64x2_t Difference_DefaultOutport1_Batch = vsubq_f64(Difference_a, Difference_b);
        vst1q_f64(&Difference_DefaultOutport1[Difference_i], Difference_DefaultOutport1_Batch);
    }
    Difference_DefaultOutport1[127] = In1[127] - In1[126];
    Difference_PreviousValue = In1[127];
    for (batchIndex1 = 0; batchIndex1 < 128; batchIndex1+=2) {
        float64x2_t Difference_DefaultOutport1_Batch = vld1q_f64(&Difference_DefaultOutport1[batchIndex1]);
        float64x2_t In2_Batch = vld1q_f64(&In2[batchIndex1]);
        float64x2_t Add_DefaultOutport1_Batch = vaddq_f64(Difference_DefaultOutport1_Batch, In2_Batch);
        vst1q_f64(&Add_DefaultOutport1[batchIndex1], Add_DefaultOutport1_Batch);
    }
    Selector_DefaultOutport1[0] = Add_DefaultOutport1[1];
    Selector_DefaultOutport1[1] = Add_DefaultOutport1[16];
    Selector_DefaultOutport1[2] = Add_DefaultOutport1[33];
    Selector_DefaultOutport1[3] = Add_DefaultOutport1[45];
    Selector_DefaultOutport1[4] = Add_DefaultOutport1[71];
    Selector_DefaultOutport1[5] = Add_DefaultOutport1[86];
    Selector_DefaultOutport1[6] = Add_DefaultOutport1[103];
    Selector_DefaultOutport1[7] = Add_DefaultOutport1[122];
    for (batchIndex2 = 0; batchIndex2 < 8; batchIndex2+=2) {
        float64x2_t Selector_DefaultOutport1_Batch = vld1q_f64(&Selector_DefaultOutport1[batchIndex2]);
        vst1q_f64(&Out1[batchIndex2], Selector_DefaultOutport1_Batch);
    }
}