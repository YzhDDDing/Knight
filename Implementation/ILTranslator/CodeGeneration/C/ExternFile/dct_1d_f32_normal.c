#include "dct_1d_f32_normal.h"
#include <math.h>

void dct_1d_f32_normal(int n, float* in, float* out) {
    int k, i;
    float A, s;
    for(k = 0; k < n; k++) {
        s = 0;
        if(k==0)
            A = sqrt(1.0/n);
        else
            A = sqrt(2.0/n);
        for(i = 0; i < n; i++) {
            float tmp = in[i]*cos((3.14159265358979*(2*i+1)*k)/(2*n));
            s = s + tmp;
        }
        out[k] = A * s;
    }
}