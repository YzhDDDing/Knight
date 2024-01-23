#include "define.h"
struct system_26_state system_26_instance;
void system_26_Init(struct system_26_state* self) {
    system_76_Init(&system_76_instance);
}
void system_26_Update(struct system_26_state* self, double signal3[32], double signal_o3[32]) {
    double For_IteratorSubsystem_signal_o3[32] = {0};
    system_76_Update(&system_76_instance, signal3, For_IteratorSubsystem_signal_o3);
    int batchIndex;
    for (batchIndex = 0; batchIndex < 32; batchIndex++) {
        signal_o3[batchIndex] = For_IteratorSubsystem_signal_o3[batchIndex];
    }
}