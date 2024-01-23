#include "define.h"
struct system_772_state system_772_instance;
void system_772_Init(struct system_772_state* self) {
    system_744_Init(&system_744_instance);
    system_805_Init(&system_805_instance);
}
void system_772_Update(struct system_772_state* self, int ArmId, bool* FindPort, int* FindE) {
    bool FindArmIdInPool_Out1;
    int FindEmptyInPool_Out1;
    system_744_Update(&system_744_instance, ArmId, &FindArmIdInPool_Out1);
    system_805_Update(&system_805_instance, &FindEmptyInPool_Out1);
    *FindPort = FindArmIdInPool_Out1;
    *FindE = FindEmptyInPool_Out1;
}