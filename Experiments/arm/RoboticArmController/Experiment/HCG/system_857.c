#include "define.h"
int Data_StoreMemory1_FoundArm_1;
struct system_857_state system_857_instance;
void system_857_Init(struct system_857_state* self) {
    Data_StoreMemory1_FoundArm_1 = -1;
    system_917_Init(&system_917_instance);
    system_890_Init(&system_890_instance);
}
void system_857_Update(struct system_857_state* self, int ArmId, int P1, int P2, int P3, int* Res, int* B) {
    int FindInPool_Res = 0;
    int FindInPool_B = 0;
    system_917_Update(&system_917_instance);
    system_890_Update(&system_890_instance, ArmId, &FindInPool_Res, &FindInPool_B);
    *Res = FindInPool_Res;
    *B = FindInPool_B;
}