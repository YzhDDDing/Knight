#include "define.h"
struct system_1384_state system_1384_instance;
void system_1384_Init(struct system_1384_state* self) {
    system_1391_Init(&system_1391_instance);
    system_1397_Init(&system_1397_instance);
}
void system_1384_Update(struct system_1384_state* self, int ArmId, int P1, int P2, int P3, int* Res, int* B) {
    bool CompareTo_Constant_DefaultOutport1 = 0;
    bool If_DefaultOutport1 = 0;
    bool If_DefaultOutport2 = 0;
    int Merge_DefaultOutport1 = 0;
    int Merge1_DefaultOutport1 = 0;
    CompareTo_Constant_DefaultOutport1 = ArmId == 0;
    If_DefaultOutport1 = (CompareTo_Constant_DefaultOutport1 != 0);
    If_DefaultOutport2 = !(CompareTo_Constant_DefaultOutport1 != 0);
    if (If_DefaultOutport1) {
        system_1391_Update(&system_1391_instance, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (If_DefaultOutport2) {
        system_1397_Update(&system_1397_instance, ArmId, P1, P2, P3, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    *Res = Merge_DefaultOutport1;
    *B = Merge1_DefaultOutport1;
}