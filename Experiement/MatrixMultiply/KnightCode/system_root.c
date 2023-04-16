#include "define.h"
#include <string.h>
struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self) {
}
void system_root_Update(struct system_root_state* self, double In2[256], double In1[256], double Out1[16]) {
    int batchIndex1;
    int batchIndex2;
    int batchIndex3;
    int MatrixMultiply_tempVar0;
    int MatrixMultiply_tempVar1;
    int MatrixMultiply_tempVar2;
    for (batchIndex1 = 12; batchIndex1 < 16; batchIndex1++) {
        for(batchIndex2 = 12; batchIndex2 < 16; batchIndex2++) {
            int MatrixMultiply_tempVar0 = batchIndex1 << 4;
            MatrixMultiply_tempVar1 = batchIndex2 + MatrixMultiply_tempVar0;
            MatrixMultiply_tempVar2 = batchIndex2 -12 + ((batchIndex1-12) << 2);
            Out1[MatrixMultiply_tempVar2] = 0.0;
            for(batchIndex3 = 0; batchIndex3 < 16; batchIndex3 ++) {
                Out1[MatrixMultiply_tempVar2] += In2[(batchIndex3 << 4) + batchIndex2] * In1[MatrixMultiply_tempVar0 + batchIndex3];
            }
        }
    }
}