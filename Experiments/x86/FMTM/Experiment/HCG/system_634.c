#include "define.h"
struct system_634_state system_634_instance;
void system_634_Init(struct system_634_state* self) {
    system_726_Init(&system_726_instance);
    system_730_Init(&system_730_instance);
}
void system_634_Update(struct system_634_state* self, int SenserId, int TValue, int* Res, int* R) {
    bool CompareTo_Constant_DefaultOutport1 = 0;
    bool If_DefaultOutport1 = 0;
    bool If_DefaultOutport2 = 0;
    int Merge_DefaultOutport1 = 0;
    int Merge1_DefaultOutport1 = 0;
    CompareTo_Constant_DefaultOutport1 = SenserId == 0;
    If_DefaultOutport1 = (CompareTo_Constant_DefaultOutport1 != 0);
    If_DefaultOutport2 = !(CompareTo_Constant_DefaultOutport1 != 0);
    if (If_DefaultOutport1) {
        system_726_Update(&system_726_instance, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (If_DefaultOutport2) {
        system_730_Update(&system_730_instance, SenserId, TValue, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    *Res = Merge_DefaultOutport1;
    *R = Merge1_DefaultOutport1;
}