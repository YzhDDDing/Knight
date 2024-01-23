#include "conv_1d_f32_normal.h"
#include <string.h>
void conv_1d_f32_normal(int n, float* in, int kernelSize, float* kernel, float* out)
{	
    n = n + (int)(kernelSize / 2) * 2;
    memset(out, 0, n * sizeof(float));
    int iConvSize = n - kernelSize + 1;
    int kernelSizeDiv2 = kernelSize / 2;
    for (int itDst = kernelSizeDiv2; itDst < n - kernelSizeDiv2; ++itDst)
    {
        for (int itker = 0, itSrc = itDst - kernelSizeDiv2; itker < kernelSize; ++itker, ++itSrc)
        {
            out[itDst] += kernel[itker] * in[itSrc];
        }
    }
}