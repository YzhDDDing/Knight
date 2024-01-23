#include "define.h"
struct system_890_state system_890_instance;
void system_890_Init(struct system_890_state* self) {
    system_893_Init(&system_893_instance);
    system_886_Init(&system_886_instance);
    system_864_Init(&system_864_instance);
}
void system_890_Update(struct system_890_state* self, int ArmId, int* Res, int* B) {
    int FindArmIdInPool_Out1 = 0;
    bool CompareTo_Constant1_DefaultOutport1 = 0;
    bool If_DefaultOutport1 = 0;
    bool If_DefaultOutport2 = 0;
    int SetArmIdInPool_B = 0;
    int Merge_DefaultOutport1 = 0;
    system_893_Update(&system_893_instance, ArmId, &FindArmIdInPool_Out1);
    CompareTo_Constant1_DefaultOutport1 = FindArmIdInPool_Out1 == -1;
    If_DefaultOutport1 = (CompareTo_Constant1_DefaultOutport1 != 0);
    If_DefaultOutport2 = !(CompareTo_Constant1_DefaultOutport1 != 0);
    if (If_DefaultOutport1) {
        system_886_Update(&system_886_instance, &Merge_DefaultOutport1);
    }
    if (If_DefaultOutport2) {
        system_864_Update(&system_864_instance, ArmId, &Merge_DefaultOutport1, &SetArmIdInPool_B);
    }
    *Res = Merge_DefaultOutport1;
    *B = SetArmIdInPool_B;
}