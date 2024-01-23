#include "define.h"
struct system_634_state system_634_instance;
void system_634_Init(struct system_634_state* self) {
    system_726_Init(&system_726_instance);
    system_730_Init(&system_730_instance);
}
void system_634_Update(struct system_634_state* self, int PortId, int Arg1, int Arg2, int Arg3, int* Result, int* MSG) {
    bool CompareTo_Constant_DefaultOutport1;
    bool If_DefaultOutport1;
    bool If_DefaultOutport2;
    int Merge_DefaultOutport1;
    int Merge1_DefaultOutport1;
    CompareTo_Constant_DefaultOutport1 = PortId == 0;
    If_DefaultOutport1 = (CompareTo_Constant_DefaultOutport1 != 0);
    If_DefaultOutport2 = !(CompareTo_Constant_DefaultOutport1 != 0);
    if (If_DefaultOutport1) {
        system_726_Update(&system_726_instance, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (If_DefaultOutport2) {
        system_730_Update(&system_730_instance, PortId, Arg1, Arg2, Arg3, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    *Result = Merge_DefaultOutport1;
    *MSG = Merge1_DefaultOutport1;
}