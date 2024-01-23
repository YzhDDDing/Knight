#include "define.h"
struct system_684_state system_684_instance;
void system_684_Init(struct system_684_state* self) {
    system_942_Init(&system_942_instance);
    system_948_Init(&system_948_instance);
}
void system_684_Update(struct system_684_state* self, int SenserId, int TValue, int* Res, int* R) {
    bool CompareTo_Constant_DefaultOutport1;
    bool If_DefaultOutport1;
    bool If_DefaultOutport2;
    int Merge_DefaultOutport1;
    int Merge1_DefaultOutport1;
    CompareTo_Constant_DefaultOutport1 = SenserId == 0;
    If_DefaultOutport1 = (CompareTo_Constant_DefaultOutport1 != 0);
    If_DefaultOutport2 = !(CompareTo_Constant_DefaultOutport1 != 0);
    if (If_DefaultOutport1) {
        system_942_Update(&system_942_instance, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (If_DefaultOutport2) {
        system_948_Update(&system_948_instance, SenserId, TValue, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    *Res = Merge_DefaultOutport1;
    *R = Merge1_DefaultOutport1;
}