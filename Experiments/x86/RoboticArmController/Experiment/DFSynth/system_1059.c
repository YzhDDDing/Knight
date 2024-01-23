#include "define.h"
struct system_1059_state system_1059_instance;
void system_1059_Init(struct system_1059_state* self) {
}
void system_1059_Update(struct system_1059_state* self, int ArmId, int TargetP, int m, int m2, int* Res, int* B) {
    int Constant1_DefaultOutport1;
    int Constant2_DefaultOutport1;
    int Constant3_DefaultOutport1;
    int Constant4_DefaultOutport1;
    int Constant5_DefaultOutport1;
    int Constant6_DefaultOutport1;
    int Subtract_DefaultOutport1;
    bool CompareTo_Constant_DefaultOutport1;
    bool CompareTo_Constant1_DefaultOutport1;
    bool CompareTo_Constant2_DefaultOutport1;
    bool CompareTo_Constant3_DefaultOutport1;
    bool CompareTo_Constant4_DefaultOutport1;
    bool CompareTo_Constant5_DefaultOutport1;
    int Switch5_DefaultOutport1;
    int Switch4_DefaultOutport1;
    int Switch3_DefaultOutport1;
    int Switch2_DefaultOutport1;
    int Switch1_DefaultOutport1;
    int Switch_DefaultOutport1;
    *Res = TargetP;
    Constant1_DefaultOutport1 = 101;
    Constant2_DefaultOutport1 = 102;
    Constant3_DefaultOutport1 = 103;
    Constant4_DefaultOutport1 = -101;
    Constant5_DefaultOutport1 = -102;
    Constant6_DefaultOutport1 = -103;
    Subtract_DefaultOutport1 = m2 - m;
    CompareTo_Constant_DefaultOutport1 = Subtract_DefaultOutport1 == 1;
    CompareTo_Constant1_DefaultOutport1 = Subtract_DefaultOutport1 == 2;
    CompareTo_Constant2_DefaultOutport1 = Subtract_DefaultOutport1 == 3;
    CompareTo_Constant3_DefaultOutport1 = Subtract_DefaultOutport1 == -1;
    CompareTo_Constant4_DefaultOutport1 = Subtract_DefaultOutport1 == -2;
    CompareTo_Constant5_DefaultOutport1 = Subtract_DefaultOutport1 == -3;
    if (CompareTo_Constant5_DefaultOutport1 > 0) {
        Switch5_DefaultOutport1 = Constant6_DefaultOutport1;
    }
    else {
        Switch5_DefaultOutport1 = Subtract_DefaultOutport1;
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
    *B = Switch_DefaultOutport1;
}