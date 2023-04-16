#include "define.h"
#include <string.h>
struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self) {
}
void system_root_Update(struct system_root_state* self, double In2[256], double Out1[64]) {
    int batchIndex1;
    int batchIndex2;
    int batchIndex3;
    int batchIndex4;
    double HermitianTranspose_B_Outport[256];
    for (batchIndex1 = 0; batchIndex1 < 16; batchIndex1++){
        for(batchIndex2 = 0; batchIndex2 < 16; batchIndex2++){
            HermitianTranspose_B_Outport[batchIndex2 + (batchIndex1 << 4)] = In2[(batchIndex2 << 4) + batchIndex1];
        }
    }
    batchIndex4 = 0;
    for (batchIndex3 = 0; batchIndex3 < 8 ; batchIndex3++) {
        memcpy(&Out1[batchIndex4], &HermitianTranspose_B_Outport[batchIndex3 << 4], sizeof(double) << 3U);
        batchIndex4 += 8;
    }
}