#include "define.h"
#include <string.h>
#include <stdio.h>
struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self) {
}
void system_root_Update(struct system_root_state* self, double In2[256], double In1[256], double Out1[16]) {
    int batchIndex1;
    int batchIndex2;
    int MatrixMultiply_tempVar2;
    double MatrixMultiply_out[256];
    size_t MatrixMultiply_i, MatrixMultiply_j, MatrixMultiply_k;
    for (MatrixMultiply_i = 1; MatrixMultiply_i < 16; ++MatrixMultiply_i) {
        for (MatrixMultiply_j = 0; MatrixMultiply_j < MatrixMultiply_i; ++MatrixMultiply_j) {
            double t = In1[MatrixMultiply_j*16+MatrixMultiply_i];
            In1[MatrixMultiply_j*16+MatrixMultiply_i] = In1[MatrixMultiply_i*16+MatrixMultiply_j];
            In1[MatrixMultiply_i*16+MatrixMultiply_j] = t;
        }
    }
    for (MatrixMultiply_i = 0; MatrixMultiply_i < 16; ++MatrixMultiply_i) {
        for (MatrixMultiply_j = 0; MatrixMultiply_j < 16; ++MatrixMultiply_j) {
            float64x2_t MatrixMultiply_tempVar1_Batch = vdupq_n_f64(0);
            for (MatrixMultiply_k = 0; MatrixMultiply_k < 16; MatrixMultiply_k += 2) {
                float64x2_t In2_Batch = vld1q_f64(&In2[MatrixMultiply_i * 16 + MatrixMultiply_k]);
                float64x2_t In1_Batch = vld1q_f64(&In1[MatrixMultiply_j * 16 + MatrixMultiply_k]);
                MatrixMultiply_tempVar1_Batch = vmlaq_f64(MatrixMultiply_tempVar1_Batch, In2_Batch, In1_Batch);
            }
            MatrixMultiply_out[MatrixMultiply_i * 16 + MatrixMultiply_j] = vgetq_lane_f64(MatrixMultiply_tempVar1_Batch, 0) + vgetq_lane_f64(MatrixMultiply_tempVar1_Batch, 1);
        }
    }
    batchIndex1 = 0;
    for (batchIndex2 = 0; batchIndex2 < 4; batchIndex2++) {
        MatrixMultiply_tempVar2 = (batchIndex2 + 12) << 4;
        Out1[batchIndex1] = MatrixMultiply_out[MatrixMultiply_tempVar2 + 12];
        Out1[batchIndex1 + 1] = MatrixMultiply_out[MatrixMultiply_tempVar2 + 13];
        Out1[batchIndex1 + 2] = MatrixMultiply_out[MatrixMultiply_tempVar2 + 14];
        Out1[batchIndex1 + 3] = MatrixMultiply_out[MatrixMultiply_tempVar2 + 15];
        batchIndex1 += 4;
    }
}