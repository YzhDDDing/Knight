#include "define.h"
int Data_StoreMemory1_FoundId_2;
struct system_948_state system_948_instance;
void system_948_Init(struct system_948_state* self) {
    Data_StoreMemory1_FoundId_2 = -1;
    system_994_Init(&system_994_instance);
    system_978_Init(&system_978_instance);
    system_1288_Init(&system_1288_instance);
}
void system_948_Update(struct system_948_state* self, int SenserId, int TValue, int* Res, int* R) {
    int FindInPool_FindId;
    bool CompareTo_Constant_DefaultOutport1;
    int Subsystem_Res;
    int Subsystem_R;
    system_994_Update(&system_994_instance);
    system_978_Update(&system_978_instance, SenserId, &FindInPool_FindId);
    CompareTo_Constant_DefaultOutport1 = FindInPool_FindId != -1;
    system_1288_Update(&system_1288_instance, FindInPool_FindId, CompareTo_Constant_DefaultOutport1, &Subsystem_Res, &Subsystem_R);
    *Res = Subsystem_Res;
    *R = Subsystem_R;
}