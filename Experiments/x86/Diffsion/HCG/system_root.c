#include "define.h"
struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self) {
    system_236_Init(&system_236_instance);
}
void system_root_Update(struct system_root_state* self, float Inport, int Outport[32]) {
    int Diffsion_Output[32];
    system_236_Update(&system_236_instance, Inport, Diffsion_Output);
    int batchIndex;
    for (batchIndex = 0;batchIndex < 32;batchIndex += 4) {
        __m128i Diffsion_Output_Batch = _mm_set_epi32((Diffsion_Output + batchIndex)[3], (Diffsion_Output + batchIndex)[2], (Diffsion_Output + batchIndex)[1], (Diffsion_Output + batchIndex)[0]);
        (Outport + batchIndex)[0] = ((int*)&Diffsion_Output_Batch)[0];
        (Outport + batchIndex)[1] = ((int*)&Diffsion_Output_Batch)[1];
        (Outport + batchIndex)[2] = ((int*)&Diffsion_Output_Batch)[2];
        (Outport + batchIndex)[3] = ((int*)&Diffsion_Output_Batch)[3];
    }
}