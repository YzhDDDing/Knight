#include "define.h"
int Data_StoreMemory1_Found_P;
struct system_948_state system_948_instance;
void system_948_Init(struct system_948_state* self) {
    Data_StoreMemory1_Found_P = -1;
    system_994_Init(&system_994_instance);
    system_978_Init(&system_978_instance);
    system_1142_Init(&system_1142_instance);
    system_1150_Init(&system_1150_instance);
}
void system_948_Update(struct system_948_state* self, int PortId, int Arg1, int Arg2, int Arg3, int* Result, int* MSG) {
    int FindInPool_FindP = 0;
    bool CompareTo_Constant_DefaultOutport1 = 0;
    bool If_DefaultOutport1 = 0;
    bool If_DefaultOutport2 = 0;
    int Merge_DefaultOutport1 = 0;
    int Merge1_DefaultOutport1 = 0;
    system_994_Update(&system_994_instance);
    system_978_Update(&system_978_instance, PortId, &FindInPool_FindP);
    CompareTo_Constant_DefaultOutport1 = FindInPool_FindP != -1;
    If_DefaultOutport1 = (CompareTo_Constant_DefaultOutport1 != 0);
    If_DefaultOutport2 = !(CompareTo_Constant_DefaultOutport1 != 0);
    if (If_DefaultOutport1) {
        system_1142_Update(&system_1142_instance, FindInPool_FindP, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (If_DefaultOutport2) {
        system_1150_Update(&system_1150_instance, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    *Result = Merge_DefaultOutport1;
    *MSG = Merge1_DefaultOutport1;
}