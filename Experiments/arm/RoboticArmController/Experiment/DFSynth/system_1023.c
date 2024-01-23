#include "define.h"
int Data_StoreMemory1_FoundArm_4;
int Data_StoreMemory2_FoundArmT;
struct system_1023_state system_1023_instance;
void system_1023_Init(struct system_1023_state* self) {
    Data_StoreMemory1_FoundArm_4 = -1;
    Data_StoreMemory2_FoundArmT = -1;
    system_1052_Init(&system_1052_instance);
    system_1036_Init(&system_1036_instance);
    system_1032_Init(&system_1032_instance);
    system_1059_Init(&system_1059_instance);
}
void system_1023_Update(struct system_1023_state* self, int ArmId, int P1, int P2, int P3, int* Res, int* B) {
    int FindInPool_FindP;
    int FindInPool_FindPT;
    bool CompareTo_Constant1_DefaultOutport1;
    bool CompareTo_Constant2_DefaultOutport1;
    bool AND_DefaultOutport1;
    bool If_DefaultOutport1;
    bool If_DefaultOutport2;
    int SetPortInPool_B;
    int Merge_DefaultOutport1;
    system_1052_Update(&system_1052_instance);
    system_1036_Update(&system_1036_instance, ArmId, P1, &FindInPool_FindP, &FindInPool_FindPT);
    CompareTo_Constant1_DefaultOutport1 = FindInPool_FindP != -1;
    CompareTo_Constant2_DefaultOutport1 = FindInPool_FindPT != -1;
    AND_DefaultOutport1 = (CompareTo_Constant1_DefaultOutport1 && CompareTo_Constant2_DefaultOutport1);
    If_DefaultOutport1 = (AND_DefaultOutport1 != 0);
    If_DefaultOutport2 = !(AND_DefaultOutport1 != 0);
    if (If_DefaultOutport2) {
        system_1032_Update(&system_1032_instance, &Merge_DefaultOutport1);
    }
    if (If_DefaultOutport1) {
        system_1059_Update(&system_1059_instance, ArmId, P1, P2, P3, &Merge_DefaultOutport1, &SetPortInPool_B);
    }
    *Res = Merge_DefaultOutport1;
    *B = SetPortInPool_B;
}