#include "define.h"
struct system_698_state system_698_instance;
void system_698_Init(struct system_698_state* self) {
    system_851_Init(&system_851_instance);
    system_857_Init(&system_857_instance);
}
void system_698_Update(struct system_698_state* self, int ArmId, int P1, int P2, int P3, int* Res, int* B) {
    bool CompareTo_Constant_DefaultOutport1 = 0;
    bool If_DefaultOutport1 = 0;
    bool If_DefaultOutport2 = 0;
    int Merge_DefaultOutport1 = 0;
    int Merge1_DefaultOutport1 = 0;
    CompareTo_Constant_DefaultOutport1 = ArmId == 0;
    If_DefaultOutport1 = (CompareTo_Constant_DefaultOutport1 != 0);
    If_DefaultOutport2 = !(CompareTo_Constant_DefaultOutport1 != 0);
    if (If_DefaultOutport1) {
        system_851_Update(&system_851_instance, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (If_DefaultOutport2) {
        system_857_Update(&system_857_instance, ArmId, P1, P2, P3, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    *Res = Merge_DefaultOutport1;
    *B = Merge1_DefaultOutport1;
}