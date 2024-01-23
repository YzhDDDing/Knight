#include "define.h"
struct system_1059_state system_1059_instance;
void system_1059_Init(struct system_1059_state* self) {
}
void system_1059_Update(struct system_1059_state* self, int SenserId, int TValue, int* Res, int* R) {
    bool CompareTo_Constant_DefaultOutport1;
    bool CompareTo_Constant1_DefaultOutport1;
    bool CompareTo_Constant2_DefaultOutport1;
    bool CompareTo_Constant3_DefaultOutport1;
    bool CompareTo_Constant4_DefaultOutport1;
    bool CompareTo_Constant5_DefaultOutport1;
    int Constant_DefaultOutport1;
    int Constant1_DefaultOutport1;
    int Constant2_DefaultOutport1;
    int Constant3_DefaultOutport1;
    int Constant4_DefaultOutport1;
    int Constant5_DefaultOutport1;
    int Constant6_DefaultOutport1;
    int Switch5_DefaultOutport1;
    int Switch4_DefaultOutport1;
    int Switch3_DefaultOutport1;
    int Switch2_DefaultOutport1;
    int Switch1_DefaultOutport1;
    int Switch_DefaultOutport1;
    CompareTo_Constant_DefaultOutport1 = SenserId == 1;
    CompareTo_Constant1_DefaultOutport1 = SenserId == 2;
    CompareTo_Constant2_DefaultOutport1 = SenserId == 4;
    CompareTo_Constant3_DefaultOutport1 = SenserId == 8;
    CompareTo_Constant4_DefaultOutport1 = SenserId == 16;
    CompareTo_Constant5_DefaultOutport1 = SenserId == 32;
    Constant_DefaultOutport1 = 1023;
    Constant1_DefaultOutport1 = 1001;
    Constant2_DefaultOutport1 = 1002;
    Constant3_DefaultOutport1 = 1004;
    Constant4_DefaultOutport1 = 1008;
    Constant5_DefaultOutport1 = 1016;
    Constant6_DefaultOutport1 = 1032;
    if (CompareTo_Constant5_DefaultOutport1 > 0) {
        Switch5_DefaultOutport1 = Constant6_DefaultOutport1;
    }
    else {
        Switch5_DefaultOutport1 = TValue;
    }
    if (CompareTo_Constant4_DefaultOutport1 > 0) {
        Switch4_DefaultOutport1 = Constant5_DefaultOutport1;
    }
    else {
        Switch4_DefaultOutport1 = Switch5_DefaultOutport1;
    }
    if (CompareTo_Constant3_DefaultOutport1 > 0) {
        Switch3_DefaultOutport1 = Constant4_DefaultOutport1;
    }
    else {
        Switch3_DefaultOutport1 = Switch4_DefaultOutport1;
    }
    if (CompareTo_Constant2_DefaultOutport1 > 0) {
        Switch2_DefaultOutport1 = Constant3_DefaultOutport1;
    }
    else {
        Switch2_DefaultOutport1 = Switch3_DefaultOutport1;
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
    *Res = Switch_DefaultOutport1;
    *R = Constant_DefaultOutport1;
}