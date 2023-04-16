#include "conv_1d_f32_Intel.h"
#include <string.h>
#include <immintrin.h>
float Conv_Buf[168];
void conv_1d_f32_Intel(int n, float* in, int kernelSize, float* kernel, float* out) {
    int iConvSize = n + kernelSize - 1;
    memcpy(&Conv_Buf[kernelSize - 1], in, n * sizeof(float));
    memset(out, 0, iConvSize * sizeof(float));
    for(int i = 0; i < kernelSize/2; i++) {
        float t = kernel[i];
        kernel[i] = kernel[kernelSize-i-1];
        kernel[kernelSize-i-1] = t;
    }
    for (int kx = 0; kx < kernelSize; kx++) {
        int x;
        __m256 kernel_kx_vec = _mm256_broadcast_ss(&kernel[kx]);
        for (x = 0; x + 7 < iConvSize; x += 8) {
            __m256 Conv_Buf_vec = _mm256_loadu_ps(&Conv_Buf[x + kx]);
            __m256 out_vec = _mm256_loadu_ps(&out[x]);
            __m256 mul_vec = _mm256_mul_ps(Conv_Buf_vec, kernel_kx_vec);
            __m256 add_vec = _mm256_add_ps(out_vec, mul_vec);
            _mm256_storeu_ps(&out[x], add_vec);
        }
        for (; x < iConvSize; x++) {
            out[x] += Conv_Buf[x + kx] * kernel[kx];
        }
    }
}