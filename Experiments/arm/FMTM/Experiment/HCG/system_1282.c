#include "define.h"
struct system_1282_state system_1282_instance;
void system_1282_Init(struct system_1282_state* self) {
    system_1032_Init(&system_1032_instance);
    system_1059_Init(&system_1059_instance);
}
void system_1282_Update(struct system_1282_state* self, bool Gate, int SenserId, int TValue, int* Res, int* R) {
    bool If_DefaultOutport1 = 0;
    bool If_DefaultOutport2 = 0;
    int SetSenserId_R = 0;
    int Merge_DefaultOutport1 = 0;
    If_DefaultOutport1 = (Gate != 0);
    If_DefaultOutport2 = !(Gate != 0);
    if (If_DefaultOutport2) {
        system_1032_Update(&system_1032_instance, &Merge_DefaultOutport1);
    }
    if (If_DefaultOutport1) {
        system_1059_Update(&system_1059_instance, SenserId, TValue, &Merge_DefaultOutport1, &SetSenserId_R);
    }
    *Res = Merge_DefaultOutport1;
    *R = SetSenserId_R;
}