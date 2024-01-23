#include "define.h"
struct system_797_state system_797_instance;
void system_797_Init(struct system_797_state* self) {
    system_833_Init(&system_833_instance);
}
void system_797_Update(struct system_797_state* self, int PortId, int FindE, int* Res, int* R) {
    bool CompareTo_Constant_DefaultOutport1 = 0;
    bool CompareTo_Constant1_DefaultOutport1 = 0;
    bool CompareTo_Constant2_DefaultOutport1 = 0;
    int Constant_DefaultOutport1 = 0;
    int Constant1_DefaultOutport1 = 0;
    int Constant2_DefaultOutport1 = 0;
    int Constant3_DefaultOutport1 = 0;
    int Constant4_DefaultOutport1 = 0;
    int Switch2_DefaultOutport1 = 0;
    int Switch1_DefaultOutport1 = 0;
    int Switch_DefaultOutport1 = 0;
    CompareTo_Constant_DefaultOutport1 = FindE == 0;
    CompareTo_Constant1_DefaultOutport1 = FindE == 1;
    CompareTo_Constant2_DefaultOutport1 = FindE == 2;
    Constant_DefaultOutport1 = 1;
    Constant1_DefaultOutport1 = 1;
    Constant2_DefaultOutport1 = 2;
    Constant3_DefaultOutport1 = 3;
    Constant4_DefaultOutport1 = 4;
    system_833_Update(&system_833_instance, PortId, FindE);
    if (CompareTo_Constant2_DefaultOutport1 > 0) {
        Switch2_DefaultOutport1 = Constant3_DefaultOutport1;
    }
    else {
        Switch2_DefaultOutport1 = Constant4_DefaultOutport1;
    }
    if (CompareTo_Constant1_DefaultOutport1 > 0) {
        Switch1_DefaultOutport1 = Constant2_DefaultOutport1;
    }
    else {
        Switch1_DefaultOutport1 = Switch2_DefaultOutport1;
    }
    if (CompareTo_Constant_DefaultOutport1 > 0) {
        Switch_DefaultOutport1 = Constant1_DefaultOutport1;
    }
    else {
        Switch_DefaultOutport1 = Switch1_DefaultOutport1;
    }
    *Res = Constant_DefaultOutport1;
    *R = Switch_DefaultOutport1;
}