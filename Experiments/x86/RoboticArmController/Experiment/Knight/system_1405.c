#include "define.h"
struct system_1405_state system_1405_instance;
void system_1405_Init(struct system_1405_state* self) {
    system_1416_Init(&system_1416_instance);
    system_1412_Init(&system_1412_instance);
    system_1434_Init(&system_1434_instance);
}
void system_1405_Update(struct system_1405_state* self, int ArmId, int P1, int P2, int P3, int* Res, int* B) {
    int FindArmIdInPool_Out1;
    bool CompareTo_Constant1_DefaultOutport1;
    bool If_DefaultOutport1;
    bool If_DefaultOutport2;
    int SetArmIdInPool_B;
    int Merge_DefaultOutport1;
    system_1416_Update(&system_1416_instance, ArmId, &FindArmIdInPool_Out1);
    CompareTo_Constant1_DefaultOutport1 = FindArmIdInPool_Out1 == -1;
    If_DefaultOutport1 = (CompareTo_Constant1_DefaultOutport1 != 0);
    If_DefaultOutport2 = !(CompareTo_Constant1_DefaultOutport1 != 0);
    if (If_DefaultOutport1) {
        system_1412_Update(&system_1412_instance, &Merge_DefaultOutport1);
    }
    if (If_DefaultOutport2) {
        system_1434_Update(&system_1434_instance, ArmId, P1, P2, P3, &Merge_DefaultOutport1, &SetArmIdInPool_B);
    }
    *Res = Merge_DefaultOutport1;
    *B = SetArmIdInPool_B;
}