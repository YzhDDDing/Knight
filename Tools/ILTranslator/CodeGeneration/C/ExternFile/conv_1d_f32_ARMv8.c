#include "conv_1d_f32_ARMv8.h"
#include <string.h>
#include <arm_neon.h>
void conv_1d_f32_ARMv8(int n, float* in, int kernelSize, float* kernel, float* out) {
    n = n + (int)(kernelSize / 2) * 2;
    memset(out, 0, n * sizeof(float));
    int iConvSize = n - kernelSize + 1;
    int kernelSizeDiv2 = kernelSize / 2;
    float* pDstTemp = out + kernelSizeDiv2;
    for (int kx = 0, start = 0; kx < kernelSize; kx++, start++) {
        for (int x = 0; x < iConvSize; x+=4) {
            float32x4_t add_t = vld1q_f32(&pDstTemp[x]);
            float32x4_t mul1_t = vld1q_f32(&in[start + x]);
            float32x4_t mul2_t = vld1q_f32(&kernel[kx]);
            add_t = vmlaq_f32(add_t, mul1_t, mul2_t);
            vst1q_f32(&pDstTemp[x], add_t);
        }
        for (int x = 0; x < iConvSize%4; x+=4) {
            pDstTemp[x] += in[start + x] * kernel[kx];
        }
    }
}