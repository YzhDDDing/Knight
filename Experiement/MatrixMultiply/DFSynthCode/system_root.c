#include "define.h"
#include <string.h>
struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self) {
}
void system_root_Update(struct system_root_state* self, double In2[256], double In1[256], double Out1[16]) {
    int batchIndex1;
    int batchIndex2;
    int batchIndex3;
    int batchIndex4;
    int MatrixMultiply_tempVar0;
    int MatrixMultiply_tempVar1;
    int MatrixMultiply_tempVar2;
    double MatrixMultiply_out[256];
    for (batchIndex1 = 0; batchIndex1 < 16; batchIndex1++) {
        for(batchIndex2 = 0; batchIndex2 < 16; batchIndex2++) {
            int MatrixMultiply_tempVar0 = batchIndex1 << 4;
            MatrixMultiply_tempVar1 = batchIndex2 + MatrixMultiply_tempVar0;
            MatrixMultiply_out[MatrixMultiply_tempVar1] = 0.0;
            for(batchIndex3 = 0; batchIndex3 < 16; batchIndex3 ++) {
                MatrixMultiply_out[MatrixMultiply_tempVar1] += In2[(batchIndex3 << 4) + batchIndex2] * In1[MatrixMultiply_tempVar0 + batchIndex3];
            }
        }
    }
    batchIndex1 = 0;
    for (batchIndex4 = 0; batchIndex4 < 4; batchIndex4++) {
        MatrixMultiply_tempVar2 = (batchIndex4 + 12) << 4;
        Out1[batchIndex1] = MatrixMultiply_out[MatrixMultiply_tempVar2 + 12];
        Out1[batchIndex1 + 1] = MatrixMultiply_out[MatrixMultiply_tempVar2 + 13];
        Out1[batchIndex1 + 2] = MatrixMultiply_out[MatrixMultiply_tempVar2 + 14];
        Out1[batchIndex1 + 3] = MatrixMultiply_out[MatrixMultiply_tempVar2 + 15];
        batchIndex1 += 4;
    }
}