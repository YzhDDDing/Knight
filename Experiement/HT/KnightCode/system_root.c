#include "define.h"
struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self) {
}
void system_root_Update(struct system_root_state* self, double In2[256], double Out1[64]) {
    int batchIndex1;
    int batchIndex2;
    double HermitianTranspose_B_Outport[256];
    for (batchIndex1 = 0; batchIndex1 < 8; batchIndex1++){
        for(batchIndex2 = 0; batchIndex2 < 8; batchIndex2++){
            Out1[batchIndex2 + (batchIndex1 << 3)] = In2[(batchIndex2 << 4) + batchIndex1];
        }
    }
}