#include "define.h"
struct system_18_state system_18_instance;
void system_18_Init(struct system_18_state* self) {
    system_45_Init(&system_45_instance);
}
void system_18_Update(struct system_18_state* self, float signal1[32], float signal_o1[32]) {
    float For_IteratorSubsystem_signal_o1[32] = {0};
    system_45_Update(&system_45_instance, signal1, For_IteratorSubsystem_signal_o1);
    int batchIndex = 0;
    for (batchIndex = 0;batchIndex < 32;batchIndex += 4) {
        __m128 For_IteratorSubsystem_signal_o1_Batch = _mm_load_ps(For_IteratorSubsystem_signal_o1 + batchIndex);
        _mm_store_ps(signal_o1 + batchIndex, For_IteratorSubsystem_signal_o1_Batch);
    }
}