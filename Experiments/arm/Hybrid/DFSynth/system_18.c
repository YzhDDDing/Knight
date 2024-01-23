#include "define.h"
struct system_18_state system_18_instance;
void system_18_Init(struct system_18_state* self) {
    system_45_Init(&system_45_instance);
}
void system_18_Update(struct system_18_state* self, double signal1[32], double signal_h1[32]) {
    double For_IteratorSubsystem_signal_h1[32] = {0};
    system_45_Update(&system_45_instance, signal1, For_IteratorSubsystem_signal_h1);
    int batchIndex;
    for (batchIndex = 0; batchIndex < 32; batchIndex++) {
        signal_h1[batchIndex] = For_IteratorSubsystem_signal_h1[batchIndex];
    }
}