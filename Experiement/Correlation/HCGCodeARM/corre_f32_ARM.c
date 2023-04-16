#include "corre_f32_ARM.h"
#include <string.h>
#include <arm_neon.h>
float Corre_Buf[258];
void corre_f32_ARM(int n, float* in, int kernelSize, float* kernel, float* out) {	
    int iConvSize = n + kernelSize - 1;
    memcpy(&Corre_Buf[kernelSize - 1], in, n * sizeof(float));
    memset(out, 0, iConvSize * sizeof(float));
    for (int kx = 0; kx < kernelSize; kx++) {
        int x;
        float32x4_t kernel_v = vdupq_n_f32(kernel[kx]);
        for (x = 0; x + 3 < iConvSize; x += 4) {
            float32x4_t in_v = vld1q_f32(&Corre_Buf[x + kx]);
            float32x4_t out_v = vld1q_f32(&out[x]);
            float32x4_t mul_v = vmulq_f32(in_v, kernel_v);
            out_v = vaddq_f32(out_v, mul_v);
            vst1q_f32(&out[x], out_v);
        }
        for (; x < iConvSize; x++) {
            out[x] += Corre_Buf[x + kx] * kernel[kx];
        }
    }
    for(int i = 0; i < iConvSize/2; i++) {
        float t = out[i];
        out[i] = out[iConvSize-i-1];
        out[iConvSize-i-1] = t;
    }
}