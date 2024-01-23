#include "define.h"
int Data_StoreMemory1_Found_P_1;
struct system_857_state system_857_instance;
void system_857_Init(struct system_857_state* self) {
    Data_StoreMemory1_Found_P_1 = -1;
    system_917_Init(&system_917_instance);
    system_890_Init(&system_890_instance);
}
void system_857_Update(struct system_857_state* self, int PortId, int Arg1, int Arg2, int Arg3, int* Result, int* MSG) {
    int FindInPool_Result;
    int FindInPool_MSG;
    system_917_Update(&system_917_instance);
    system_890_Update(&system_890_instance, PortId, &FindInPool_Result, &FindInPool_MSG);
    *Result = FindInPool_Result;
    *MSG = FindInPool_MSG;
}