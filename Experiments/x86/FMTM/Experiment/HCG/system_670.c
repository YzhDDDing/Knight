#include "define.h"
struct system_670_state system_670_instance;
void system_670_Init(struct system_670_state* self) {
    system_1017_Init(&system_1017_instance);
    system_1023_Init(&system_1023_instance);
}
void system_670_Update(struct system_670_state* self, int SenserId, int TValue, int* Res, int* R) {
    bool CompareTo_Constant_DefaultOutport1 = 0;
    bool If_DefaultOutport1 = 0;
    bool If_DefaultOutport2 = 0;
    int Merge_DefaultOutport1 = 0;
    int Merge1_DefaultOutport1 = 0;
    CompareTo_Constant_DefaultOutport1 = SenserId == 0;
    If_DefaultOutport1 = (CompareTo_Constant_DefaultOutport1 != 0);
    If_DefaultOutport2 = !(CompareTo_Constant_DefaultOutport1 != 0);
    if (If_DefaultOutport1) {
        system_1017_Update(&system_1017_instance, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (If_DefaultOutport2) {
        system_1023_Update(&system_1023_instance, SenserId, TValue, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    *Res = Merge_DefaultOutport1;
    *R = Merge1_DefaultOutport1;
}