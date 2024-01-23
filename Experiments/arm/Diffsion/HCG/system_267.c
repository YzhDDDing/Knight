#include "define.h"
struct system_267_state system_267_instance;
void system_267_Init(struct system_267_state* self) {
    system_269_Init(&system_269_instance);
}
void system_267_Update(struct system_267_state* self, float Inport, int Outport[32]) {
    int For_IteratorSubsystem1_Output[32] = {0};
    system_269_Update(&system_269_instance, Inport, For_IteratorSubsystem1_Output);
    int batchIndex = 0;
    for (batchIndex = 0;batchIndex < 32;batchIndex += 4) {
        int32x4_t For_IteratorSubsystem1_Output_Batch = vld1q_s32(For_IteratorSubsystem1_Output + batchIndex);
        vst1q_s32(Outport + batchIndex, For_IteratorSubsystem1_Output_Batch);
    }
}