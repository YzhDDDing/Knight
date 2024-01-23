#include "conv_1d_f32_normal.h"
#include <string.h>
float Conv_Buf[168];
void conv_1d_f32_normal(int n, float* in, int kernelSize, float* kernel, float* out) {	
    int iConvSize = n + kernelSize - 1;
    memcpy(&Conv_Buf[kernelSize - 1], in, n * sizeof(float));
    memset(out, 0, iConvSize * sizeof(float));
    for(int i = 0; i < kernelSize/2; i++) {
        float t = kernel[i];
        kernel[i] = kernel[kernelSize-i-1];
        kernel[kernelSize-i-1] = t;
    }
    for (int kx = 0; kx < kernelSize; kx++) {
        for (int x = 0; x < iConvSize; x++) {
            out[x] += Conv_Buf[x+kx] * kernel[kx];
        }
    }
}