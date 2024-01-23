#include "define.h"
struct system_139_state system_139_instance;
void system_139_Init(struct system_139_state* self) {
    system_141_Init(&system_141_instance);
}
void system_139_Update(struct system_139_state* self, double signal1[32], double signal_l1[32]) {
    double For_IteratorSubsystem_signal_l1[32] = {0};
    system_141_Update(&system_141_instance, signal1, For_IteratorSubsystem_signal_l1);
    int batchIndex;
    for (batchIndex = 0; batchIndex < 32; batchIndex++) {
        signal_l1[batchIndex] = For_IteratorSubsystem_signal_l1[batchIndex];
    }
}