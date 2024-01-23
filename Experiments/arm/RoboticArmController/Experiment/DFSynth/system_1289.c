#include "define.h"
struct system_1289_state system_1289_instance;
void system_1289_Init(struct system_1289_state* self) {
    system_1297_Init(&system_1297_instance);
    system_1293_Init(&system_1293_instance);
    system_1315_Init(&system_1315_instance);
}
void system_1289_Update(struct system_1289_state* self, int ArmId, int P1, int P2, int P3, int* Res, int* B) {
    int FindArmIdInPool_Out1;
    bool CompareTo_Constant1_DefaultOutport1;
    bool If_DefaultOutport1;
    bool If_DefaultOutport2;
    int SetArmIdInPool_B;
    int Merge_DefaultOutport1;
    system_1297_Update(&system_1297_instance, ArmId, &FindArmIdInPool_Out1);
    CompareTo_Constant1_DefaultOutport1 = FindArmIdInPool_Out1 == -1;
    If_DefaultOutport1 = (CompareTo_Constant1_DefaultOutport1 != 0);
    If_DefaultOutport2 = !(CompareTo_Constant1_DefaultOutport1 != 0);
    if (If_DefaultOutport1) {
        system_1293_Update(&system_1293_instance, &Merge_DefaultOutport1);
    }
    if (If_DefaultOutport2) {
        system_1315_Update(&system_1315_instance, ArmId, P1, P2, P3, &Merge_DefaultOutport1, &SetArmIdInPool_B);
    }
    *Res = Merge_DefaultOutport1;
    *B = SetArmIdInPool_B;
}