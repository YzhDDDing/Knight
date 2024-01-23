#include "define.h"
struct system_698_state system_698_instance;
void system_698_Init(struct system_698_state* self) {
    system_851_Init(&system_851_instance);
    system_857_Init(&system_857_instance);
}
void system_698_Update(struct system_698_state* self, int SenserId, int TValue, int* Res, int* R) {
    bool CompareTo_Constant_DefaultOutport1;
    bool If_DefaultOutport1;
    bool If_DefaultOutport2;
    int Merge_DefaultOutport1;
    int Merge1_DefaultOutport1;
    CompareTo_Constant_DefaultOutport1 = SenserId == 0;
    If_DefaultOutport1 = (CompareTo_Constant_DefaultOutport1 != 0);
    If_DefaultOutport2 = !(CompareTo_Constant_DefaultOutport1 != 0);
    if (If_DefaultOutport1) {
        system_851_Update(&system_851_instance, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (If_DefaultOutport2) {
        system_857_Update(&system_857_instance, SenserId, TValue, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    *Res = Merge_DefaultOutport1;
    *R = Merge1_DefaultOutport1;
}