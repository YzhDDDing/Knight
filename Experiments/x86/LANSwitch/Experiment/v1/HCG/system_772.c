#include "define.h"
struct system_772_state system_772_instance;
void system_772_Init(struct system_772_state* self) {
    system_805_Init(&system_805_instance);
    system_744_Init(&system_744_instance);
}
void system_772_Update(struct system_772_state* self, int PortId, bool* FindPort, int* FindE) {
    int FindEmptyInPool_Out1 = 0;
    bool FindPortInPool_Out1 = 0;
    system_805_Update(&system_805_instance, &FindEmptyInPool_Out1);
    system_744_Update(&system_744_instance, PortId, &FindPortInPool_Out1);
    *FindPort = FindPortInPool_Out1;
    *FindE = FindEmptyInPool_Out1;
}