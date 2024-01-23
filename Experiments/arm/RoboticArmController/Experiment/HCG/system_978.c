#include "define.h"
struct system_978_state system_978_instance;
void system_978_Init(struct system_978_state* self) {
    system_981_Init(&system_981_instance);
}
void system_978_Update(struct system_978_state* self, int ArmId, int* FindP) {
    int FindArmIdInPool_Out1 = 0;
    system_981_Update(&system_981_instance, ArmId, &FindArmIdInPool_Out1);
    *FindP = FindArmIdInPool_Out1;
}