#include "corre_f32_normal.h"
#include <string.h>
float Corre_Buf[258];
void corre_f32_normal(int n, float* in, int kernelSize, float* kernel, float* out) {	
    int iConvSize = n + kernelSize - 1;
    memcpy(&Corre_Buf[kernelSize - 1], in, n * sizeof(float));
    memset(out, 0, iConvSize * sizeof(float));
    for (int kx = 0; kx < kernelSize; kx++) {
        for (int x = 0; x < iConvSize; x++) {
            out[iConvSize-x-1] += Corre_Buf[x+kx] * kernel[kx];
        }
    }
}