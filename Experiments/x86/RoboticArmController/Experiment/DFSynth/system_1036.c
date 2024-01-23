#include "define.h"
struct system_1036_state system_1036_instance;
void system_1036_Init(struct system_1036_state* self) {
    system_1039_Init(&system_1039_instance);
    system_1106_Init(&system_1106_instance);
}
void system_1036_Update(struct system_1036_state* self, int ArmId, int TargetP, int* FindP, int* FindPT) {
    int FindArmIdInPool_Out1;
    int FindArmIdTInPool_FindPT;
    system_1039_Update(&system_1039_instance, ArmId, &FindArmIdInPool_Out1);
    system_1106_Update(&system_1106_instance, TargetP, &FindArmIdTInPool_FindPT);
    *FindP = FindArmIdInPool_Out1;
    *FindPT = FindArmIdTInPool_FindPT;
}