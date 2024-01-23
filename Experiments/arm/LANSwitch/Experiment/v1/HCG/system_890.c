#include "define.h"
struct system_890_state system_890_instance;
void system_890_Init(struct system_890_state* self) {
    system_893_Init(&system_893_instance);
    system_886_Init(&system_886_instance);
    system_864_Init(&system_864_instance);
}
void system_890_Update(struct system_890_state* self, int PortId, int* Result, int* MSG) {
    int FindPortInPool_Out1 = 0;
    bool CompareTo_Constant1_DefaultOutport1 = 0;
    bool If_DefaultOutport1 = 0;
    bool If_DefaultOutport2 = 0;
    int SetPortInPool_MSG = 0;
    int Merge_DefaultOutport1 = 0;
    system_893_Update(&system_893_instance, PortId, &FindPortInPool_Out1);
    CompareTo_Constant1_DefaultOutport1 = FindPortInPool_Out1 == -1;
    If_DefaultOutport1 = (CompareTo_Constant1_DefaultOutport1 != 0);
    If_DefaultOutport2 = !(CompareTo_Constant1_DefaultOutport1 != 0);
    if (If_DefaultOutport1) {
        system_886_Update(&system_886_instance, &Merge_DefaultOutport1);
    }
    if (If_DefaultOutport2) {
        system_864_Update(&system_864_instance, PortId, &Merge_DefaultOutport1, &SetPortInPool_MSG);
    }
    *Result = Merge_DefaultOutport1;
    *MSG = SetPortInPool_MSG;
}