#include "define.h"
int signal_state[64];
struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self) {
}
void system_root_Update(struct system_root_state* self, int Inport[32], int Output[64]) {
    int For_IteratorSubsystem_Output[64];
    system_34_Update(&system_34_instance, Inport, For_IteratorSubsystem_Output);
    int batchIndex;
    for (batchIndex = 0; batchIndex < 64; batchIndex++) {
        Output[batchIndex] = For_IteratorSubsystem_Output[batchIndex];
    }
}