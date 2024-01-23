#include "define.h"
bool Data_StoreMemory_Found;
int Data_StoreMemory1_Found_E;
struct system_730_state system_730_instance;
void system_730_Init(struct system_730_state* self) {
    Data_StoreMemory_Found = 0;
    Data_StoreMemory1_Found_E = -1;
    system_770_Init(&system_770_instance);
    system_772_Init(&system_772_instance);
    system_797_Init(&system_797_instance);
    system_792_Init(&system_792_instance);
}
void system_730_Update(struct system_730_state* self, int ArmId, int P1, int P2, int P3, int* Res, int* B) {
    bool FindInPool_FindPort = 0;
    int FindInPool_FindE = 0;
    bool CompareTo_Constant_DefaultOutport1 = 0;
    bool CompareTo_Constant1_DefaultOutport1 = 0;
    bool AND_DefaultOutport1 = 0;
    bool If_DefaultOutport1 = 0;
    bool If_DefaultOutport2 = 0;
    int AddArmIdInPool_B = 0;
    int Merge_DefaultOutport1 = 0;
    system_770_Update(&system_770_instance);
    system_772_Update(&system_772_instance, ArmId, &FindInPool_FindPort, &FindInPool_FindE);
    CompareTo_Constant_DefaultOutport1 = FindInPool_FindPort == 0;
    CompareTo_Constant1_DefaultOutport1 = FindInPool_FindE != -1;
    AND_DefaultOutport1 = (CompareTo_Constant_DefaultOutport1 && CompareTo_Constant1_DefaultOutport1);
    If_DefaultOutport1 = (AND_DefaultOutport1 != 0);
    If_DefaultOutport2 = !(AND_DefaultOutport1 != 0);
    if (If_DefaultOutport1) {
        system_797_Update(&system_797_instance, ArmId, FindInPool_FindE, &Merge_DefaultOutport1, &AddArmIdInPool_B);
    }
    if (If_DefaultOutport2) {
        system_792_Update(&system_792_instance, &Merge_DefaultOutport1);
    }
    *Res = Merge_DefaultOutport1;
    *B = AddArmIdInPool_B;
}