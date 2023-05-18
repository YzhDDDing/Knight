#include "conv_1d_f32_Intel.h"
#include <string.h>
#include <immintrin.h>
#include <xmmintrin.h>
void conv_1d_f32_Intel(int n, float* in, int kernelSize, float* kernel, float* out) {
    n = n + (int)(kernelSize / 2) * 2;
    memset(out, 0, n * sizeof(float));
    int iConvSize = n - kernelSize + 1;
    int kernelSizeDiv2 = kernelSize / 2;
    float* pDstTemp = out + kernelSizeDiv2;
    for (int kx = 0, start = 0; kx < kernelSize; kx++, start++) {
        for (int x = 0; x < iConvSize; x+=4) {
            __m128 add_t = _mm_loadu_ps(&pDstTemp[x]);
            __m128 mul1_t = _mm_loadu_ps(&in[start + x]);
            __m128 mul2_t = _mm_loadu_ps(&kernel[kx]);
            add_t = _mm_fmadd_ps(mul1_t, mul2_t, add_t);
            _mm_storeu_ps(&pDstTemp[x], add_t);
        }
        for (int x = 0; x < iConvSize%4; x+=4) {
            pDstTemp[x] += in[start + x] * kernel[kx];
        }
    }
}