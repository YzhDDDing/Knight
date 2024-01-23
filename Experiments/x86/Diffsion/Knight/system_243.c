#include "define.h"
struct system_243_state system_243_instance;
void system_243_Init(struct system_243_state* self) {
    system_247_Init(&system_247_instance);
}
void system_243_Update(struct system_243_state* self, int Outport[32]) {
    int For_IteratorSubsystem1_Output[32];
    system_247_Update(&system_247_instance, For_IteratorSubsystem1_Output);
    int batchIndex;
    for (batchIndex = 0; batchIndex < 32; batchIndex++) {
        Outport[batchIndex] = For_IteratorSubsystem1_Output[batchIndex];
    }
}