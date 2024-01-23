#include "define.h"
struct system_22_state system_22_instance;
void system_22_Init(struct system_22_state* self) {
    system_61_Init(&system_61_instance);
}
void system_22_Update(struct system_22_state* self, float signal2[32], float signal_o2[32]) {
    float For_IteratorSubsystem_signal_o2[32] = {0};
    system_61_Update(&system_61_instance, signal2, For_IteratorSubsystem_signal_o2);
    int batchIndex = 0;
    for (batchIndex = 0;batchIndex < 32;batchIndex += 4) {
        __m128 For_IteratorSubsystem_signal_o2_Batch = _mm_load_ps(For_IteratorSubsystem_signal_o2 + batchIndex);
        _mm_store_ps(signal_o2 + batchIndex, For_IteratorSubsystem_signal_o2_Batch);
    }
}