#include "define.h"
int Data_StoreMemory1_FoundArm_2;
struct system_1281_state system_1281_instance;
void system_1281_Init(struct system_1281_state* self) {
    Data_StoreMemory1_FoundArm_2 = -1;
    system_1338_Init(&system_1338_instance);
    system_1289_Init(&system_1289_instance);
}
void system_1281_Update(struct system_1281_state* self, int ArmId, int P1, int P2, int P3, int* Res, int* B) {
    int FindInPool_Res;
    int FindInPool_B;
    system_1338_Update(&system_1338_instance);
    system_1289_Update(&system_1289_instance, ArmId, P1, P2, P3, &FindInPool_Res, &FindInPool_B);
    *Res = FindInPool_Res;
    *B = FindInPool_B;
}