#include "define.h"
int Data_StoreMemory1_FoundArm_3;
struct system_1397_state system_1397_instance;
void system_1397_Init(struct system_1397_state* self) {
    Data_StoreMemory1_FoundArm_3 = -1;
    system_1472_Init(&system_1472_instance);
    system_1405_Init(&system_1405_instance);
}
void system_1397_Update(struct system_1397_state* self, int ArmId, int P1, int P2, int P3, int* Res, int* B) {
    int FindInPool_Res = 0;
    int FindInPool_B = 0;
    system_1472_Update(&system_1472_instance);
    system_1405_Update(&system_1405_instance, ArmId, P1, P2, P3, &FindInPool_Res, &FindInPool_B);
    *Res = FindInPool_Res;
    *B = FindInPool_B;
}