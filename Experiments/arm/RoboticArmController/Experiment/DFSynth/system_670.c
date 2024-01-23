#include "define.h"
struct system_670_state system_670_instance;
void system_670_Init(struct system_670_state* self) {
    system_1017_Init(&system_1017_instance);
    system_1023_Init(&system_1023_instance);
}
void system_670_Update(struct system_670_state* self, int ArmId, int P1, int P2, int P3, int* Res, int* B) {
    bool CompareTo_Constant_DefaultOutport1;
    bool If_DefaultOutport1;
    bool If_DefaultOutport2;
    int Merge_DefaultOutport1;
    int Merge1_DefaultOutport1;
    CompareTo_Constant_DefaultOutport1 = ArmId == 0;
    If_DefaultOutport1 = (CompareTo_Constant_DefaultOutport1 != 0);
    If_DefaultOutport2 = !(CompareTo_Constant_DefaultOutport1 != 0);
    if (If_DefaultOutport1) {
        system_1017_Update(&system_1017_instance, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (If_DefaultOutport2) {
        system_1023_Update(&system_1023_instance, ArmId, P1, P2, P3, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    *Res = Merge_DefaultOutport1;
    *B = Merge1_DefaultOutport1;
}