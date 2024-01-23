#include "define.h"
struct system_1036_state system_1036_instance;
void system_1036_Init(struct system_1036_state* self) {
    system_1039_Init(&system_1039_instance);
    system_1106_Init(&system_1106_instance);
}
void system_1036_Update(struct system_1036_state* self, int PortId, int TargetP, int* FindP, int* FindPT) {
    int FindPortInPool_Out1 = 0;
    int FindPortTInPool_Out1 = 0;
    system_1039_Update(&system_1039_instance, PortId, &FindPortInPool_Out1);
    system_1106_Update(&system_1106_instance, TargetP, &FindPortTInPool_Out1);
    *FindP = FindPortInPool_Out1;
    *FindPT = FindPortTInPool_Out1;
}