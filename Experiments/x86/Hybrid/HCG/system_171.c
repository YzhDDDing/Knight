#include "define.h"
struct system_171_state system_171_instance;
void system_171_Init(struct system_171_state* self) {
    system_173_Init(&system_173_instance);
}
void system_171_Update(struct system_171_state* self, double signal3[32], double signal_l3[32]) {
    double For_IteratorSubsystem_signal_o3[32] = {0};
    system_173_Update(&system_173_instance, signal3, For_IteratorSubsystem_signal_o3);
    int batchIndex;
    for (batchIndex = 0; batchIndex < 32; batchIndex++) {
        signal_l3[batchIndex] = For_IteratorSubsystem_signal_o3[batchIndex];
    }
}