#include "define.h"
#include <string.h>
#include <immintrin.h>
#include <stdio.h>
struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self) {
}
void system_root_Update(struct system_root_state* self, double In2[256], double In1[256], double Out1[16]) {
    int batchIndex1;
    int batchIndex2;
    int MatrixMultiply_tempVar;
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
            __m256d MatrixMultiply_tempVar1_Batch = _mm256_setzero_pd();
            for (MatrixMultiply_k = 0; MatrixMultiply_k < 16; MatrixMultiply_k += 4) {
                __m256d In2_Batch = _mm256_loadu_pd(&In2[MatrixMultiply_i * 16 + MatrixMultiply_k]);
                __m256d In1_Batch = _mm256_loadu_pd(&In1[MatrixMultiply_j * 16 + MatrixMultiply_k]);
                MatrixMultiply_tempVar1_Batch = _mm256_fmadd_pd(In2_Batch, In1_Batch, MatrixMultiply_tempVar1_Batch);
            }
            double MatrixMultiply_tempVar2[4];
            _mm256_storeu_pd(MatrixMultiply_tempVar2, MatrixMultiply_tempVar1_Batch);
            MatrixMultiply_out[MatrixMultiply_i * 16 + MatrixMultiply_j] = MatrixMultiply_tempVar2[0] + MatrixMultiply_tempVar2[1] + MatrixMultiply_tempVar2[2] + MatrixMultiply_tempVar2[3];
        }
    }
    batchIndex1 = 0;
    for (batchIndex2 = 0; batchIndex2 < 4; batchIndex2++) {
        MatrixMultiply_tempVar = (batchIndex2 + 12) << 4;
        Out1[batchIndex1] = MatrixMultiply_out[MatrixMultiply_tempVar + 12];
        Out1[batchIndex1 + 1] = MatrixMultiply_out[MatrixMultiply_tempVar + 13];
        Out1[batchIndex1 + 2] = MatrixMultiply_out[MatrixMultiply_tempVar + 14];
        Out1[batchIndex1 + 3] = MatrixMultiply_out[MatrixMultiply_tempVar + 15];
        batchIndex1 += 4;
    }
}