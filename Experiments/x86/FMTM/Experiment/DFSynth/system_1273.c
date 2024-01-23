#include "define.h"
struct system_1273_state system_1273_instance;
void system_1273_Init(struct system_1273_state* self) {
    system_797_Init(&system_797_instance);
    system_792_Init(&system_792_instance);
}
void system_1273_Update(struct system_1273_state* self, bool Gate, int PortId, int FindE, int* Res, int* R) {
    bool If_DefaultOutport1;
    bool If_DefaultOutport2;
    int AddSenserId_R;
    int Merge_DefaultOutport1;
    If_DefaultOutport1 = (Gate != 0);
    If_DefaultOutport2 = !(Gate != 0);
    if (If_DefaultOutport1) {
        system_797_Update(&system_797_instance, PortId, FindE, &Merge_DefaultOutport1, &AddSenserId_R);
    }
    if (If_DefaultOutport2) {
        system_792_Update(&system_792_instance, &Merge_DefaultOutport1);
    }
    *Res = Merge_DefaultOutport1;
    *R = AddSenserId_R;
}