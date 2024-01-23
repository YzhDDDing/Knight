#include "define.h"
int Data_StoreMemory1_FoundId_1;
int Data_StoreMemory2_FoundIdT;
struct system_1023_state system_1023_instance;
void system_1023_Init(struct system_1023_state* self) {
    Data_StoreMemory1_FoundId_1 = -1;
    Data_StoreMemory2_FoundIdT = -1;
    system_1052_Init(&system_1052_instance);
    system_1036_Init(&system_1036_instance);
    system_1282_Init(&system_1282_instance);
}
void system_1023_Update(struct system_1023_state* self, int SenserId, int TValue, int* Res, int* R) {
    int FindInPool_FindId;
    int FindInPool_FindIdT;
    bool CompareTo_Constant1_DefaultOutport1;
    bool CompareTo_Constant2_DefaultOutport1;
    bool AND_DefaultOutport1;
    int Subsystem_Res;
    int Subsystem_R;
    system_1052_Update(&system_1052_instance);
    system_1036_Update(&system_1036_instance, SenserId, TValue, &FindInPool_FindId, &FindInPool_FindIdT);
    CompareTo_Constant1_DefaultOutport1 = FindInPool_FindId != -1;
    CompareTo_Constant2_DefaultOutport1 = FindInPool_FindIdT != -1;
    AND_DefaultOutport1 = (CompareTo_Constant1_DefaultOutport1 && CompareTo_Constant2_DefaultOutport1);
    system_1282_Update(&system_1282_instance, AND_DefaultOutport1, SenserId, TValue, &Subsystem_Res, &Subsystem_R);
    *Res = Subsystem_Res;
    *R = Subsystem_R;
}