#include "define.h"
struct system_26_state system_26_instance;
void system_26_Init(struct system_26_state* self) {
    system_76_Init(&system_76_instance);
}
void system_26_Update(struct system_26_state* self, float signal3[32], float signal_o3[32]) {
    float For_IteratorSubsystem_signal_o3[32] = {0};
    system_76_Update(&system_76_instance, signal3, For_IteratorSubsystem_signal_o3);
    int batchIndex = 0;
    for (batchIndex = 0;batchIndex < 32;batchIndex += 4) {
        float32x4_t For_IteratorSubsystem_signal_o3_Batch = vld1q_f32(For_IteratorSubsystem_signal_o3 + batchIndex);
        vst1q_f32(signal_o3 + batchIndex, For_IteratorSubsystem_signal_o3_Batch);
    }
}