#include "define.h"
bool Data_StoreMemory_Found;
int Data_StoreMemory1_FoundE;
struct system_730_state system_730_instance;
void system_730_Init(struct system_730_state* self) {
    Data_StoreMemory_Found = 0;
    Data_StoreMemory1_FoundE = -1;
    system_770_Init(&system_770_instance);
    system_772_Init(&system_772_instance);
    system_1273_Init(&system_1273_instance);
}
void system_730_Update(struct system_730_state* self, int SenserId, int TValue, int* Res, int* R) {
    bool Find_FindS;
    int Find_FindE;
    bool CompareTo_Constant_DefaultOutport1;
    bool CompareTo_Constant1_DefaultOutport1;
    bool AND_DefaultOutport1;
    int Subsystem_Res;
    int Subsystem_R;
    system_770_Update(&system_770_instance);
    system_772_Update(&system_772_instance, SenserId, &Find_FindS, &Find_FindE);
    CompareTo_Constant_DefaultOutport1 = Find_FindS == 0;
    CompareTo_Constant1_DefaultOutport1 = Find_FindE != -1;
    AND_DefaultOutport1 = (CompareTo_Constant_DefaultOutport1 && CompareTo_Constant1_DefaultOutport1);
    system_1273_Update(&system_1273_instance, AND_DefaultOutport1, SenserId, Find_FindE, &Subsystem_Res, &Subsystem_R);
    *Res = Subsystem_Res;
    *R = Subsystem_R;
}