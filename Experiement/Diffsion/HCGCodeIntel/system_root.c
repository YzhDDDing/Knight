#include "define.h"
int A_state[64];
int B_state[64];
struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self) {
}
void system_root_Update(struct system_root_state* self, int Outport[64]) {
    int For_IteratorSubsystem1_Output[64];
    system_209_Update(&system_209_instance, For_IteratorSubsystem1_Output);
    int batchIndex;
    for(batchIndex = 0; batchIndex < 64; batchIndex += 8) {
        __m256i For_IteratorSubsystem1_Output_batch = _mm256_loadu_si256((__m256i*)&For_IteratorSubsystem1_Output[batchIndex]);
        _mm256_storeu_si256((__m256i*)&Outport[batchIndex], For_IteratorSubsystem1_Output_batch);
    }
}