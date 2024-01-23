#include "define.h"
struct system_155_state system_155_instance;
void system_155_Init(struct system_155_state* self) {
    system_157_Init(&system_157_instance);
}
void system_155_Update(struct system_155_state* self, double signal2[32], double signal_l2[32]) {
    double For_IteratorSubsystem_signal_l2[32] = {0};
    system_157_Update(&system_157_instance, signal2, For_IteratorSubsystem_signal_l2);
    int batchIndex;
    for (batchIndex = 0; batchIndex < 32; batchIndex++) {
        signal_l2[batchIndex] = For_IteratorSubsystem_signal_l2[batchIndex];
    }
}