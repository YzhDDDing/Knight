#include "define.h"
struct system_698_state system_698_instance;
void system_698_Init(struct system_698_state* self) {
    system_851_Init(&system_851_instance);
    system_857_Init(&system_857_instance);
}
void system_698_Update(struct system_698_state* self, int PortId, int Arg1, int Arg2, int Arg3, int* Result, int* MSG) {
    bool CompareTo_Constant_DefaultOutport1;
    bool If_DefaultOutport1;
    bool If_DefaultOutport2;
    int Merge_DefaultOutport1;
    int Merge1_DefaultOutport1;
    CompareTo_Constant_DefaultOutport1 = PortId == 0;
    If_DefaultOutport1 = (CompareTo_Constant_DefaultOutport1 != 0);
    If_DefaultOutport2 = !(CompareTo_Constant_DefaultOutport1 != 0);
    if (If_DefaultOutport1) {
        system_851_Update(&system_851_instance, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (If_DefaultOutport2) {
        system_857_Update(&system_857_instance, PortId, Arg1, Arg2, Arg3, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    *Result = Merge_DefaultOutport1;
    *MSG = Merge1_DefaultOutport1;
}