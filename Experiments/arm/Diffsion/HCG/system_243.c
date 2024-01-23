#include "define.h"
struct system_243_state system_243_instance;
void system_243_Init(struct system_243_state* self) {
    system_247_Init(&system_247_instance);
}
void system_243_Update(struct system_243_state* self, int Outport[32]) {
    int For_IteratorSubsystem1_Output[32] = {0};
    system_247_Update(&system_247_instance, For_IteratorSubsystem1_Output);
    int batchIndex = 0;
    for (batchIndex = 0;batchIndex < 32;batchIndex += 4) {
        int32x4_t For_IteratorSubsystem1_Output_Batch = vld1q_s32(For_IteratorSubsystem1_Output + batchIndex);
        vst1q_s32(Outport + batchIndex, For_IteratorSubsystem1_Output_Batch);
    }
}