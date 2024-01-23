#include "define.h"
struct system_243_state system_243_instance;
void system_243_Init(struct system_243_state* self) {
    system_247_Init(&system_247_instance);
}
void system_243_Update(struct system_243_state* self, int Outport[32]) {
    int For_IteratorSubsystem1_Output[32];
    system_247_Update(&system_247_instance, For_IteratorSubsystem1_Output);
    int batchIndex;
    for (batchIndex = 0;batchIndex < 32;batchIndex += 4) {
        __m128i For_IteratorSubsystem1_Output_Batch = _mm_set_epi32((For_IteratorSubsystem1_Output + batchIndex)[3], (For_IteratorSubsystem1_Output + batchIndex)[2], (For_IteratorSubsystem1_Output + batchIndex)[1], (For_IteratorSubsystem1_Output + batchIndex)[0]);
        (Outport + batchIndex)[0] = ((int*)&For_IteratorSubsystem1_Output_Batch)[0];
        (Outport + batchIndex)[1] = ((int*)&For_IteratorSubsystem1_Output_Batch)[1];
        (Outport + batchIndex)[2] = ((int*)&For_IteratorSubsystem1_Output_Batch)[2];
        (Outport + batchIndex)[3] = ((int*)&For_IteratorSubsystem1_Output_Batch)[3];
    }
}