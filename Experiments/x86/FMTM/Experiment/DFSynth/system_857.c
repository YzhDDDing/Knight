#include "define.h"
int Data_StoreMemory1_FoundId;
struct system_857_state system_857_instance;
void system_857_Init(struct system_857_state* self) {
    Data_StoreMemory1_FoundId = -1;
    system_917_Init(&system_917_instance);
    system_890_Init(&system_890_instance);
}
void system_857_Update(struct system_857_state* self, int SenserId, int TValue, int* Res, int* R) {
    int Find_Res;
    int Find_R;
    system_917_Update(&system_917_instance);
    system_890_Update(&system_890_instance, SenserId, &Find_Res, &Find_R);
    *Res = Find_Res;
    *R = Find_R;
}