#include "define.h"
int Data_StoreMemory1_FoundArm;
struct system_948_state system_948_instance;
void system_948_Init(struct system_948_state* self) {
    Data_StoreMemory1_FoundArm = -1;
    system_994_Init(&system_994_instance);
    system_978_Init(&system_978_instance);
    system_1142_Init(&system_1142_instance);
    system_1150_Init(&system_1150_instance);
}
void system_948_Update(struct system_948_state* self, int ArmId, int P1, int P2, int P3, int* Res, int* B) {
    int FindInPool_FindP;
    bool CompareTo_Constant_DefaultOutport1;
    bool If_DefaultOutport1;
    bool If_DefaultOutport2;
    int Merge_DefaultOutport1;
    int Merge1_DefaultOutport1;
    system_994_Update(&system_994_instance);
    system_978_Update(&system_978_instance, ArmId, &FindInPool_FindP);
    CompareTo_Constant_DefaultOutport1 = FindInPool_FindP != -1;
    If_DefaultOutport1 = (CompareTo_Constant_DefaultOutport1 != 0);
    If_DefaultOutport2 = !(CompareTo_Constant_DefaultOutport1 != 0);
    if (If_DefaultOutport1) {
        system_1142_Update(&system_1142_instance, FindInPool_FindP, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (If_DefaultOutport2) {
        system_1150_Update(&system_1150_instance, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    *Res = Merge_DefaultOutport1;
    *B = Merge1_DefaultOutport1;
}