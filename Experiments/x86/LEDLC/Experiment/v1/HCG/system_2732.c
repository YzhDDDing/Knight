#include "define.h"
struct system_2732_state system_2732_instance;
void system_2732_Init(struct system_2732_state* self) {
}
void system_2732_Update(struct system_2732_state* self, float t, int* Output) {
    bool CompareTo_Constant_DefaultOutport1 = 0;
    int Constant1_DefaultOutport1 = 0;
    int Constant2_DefaultOutport1 = 0;
    int Switch_DefaultOutport1 = 0;
    CompareTo_Constant_DefaultOutport1 = t != 9;
    Constant1_DefaultOutport1 = -1;
    Constant2_DefaultOutport1 = -3;
    if (CompareTo_Constant_DefaultOutport1 > 0) {
        Switch_DefaultOutport1 = Constant1_DefaultOutport1;
    }
    else {
        Switch_DefaultOutport1 = Constant2_DefaultOutport1;
    }
    *Output = Switch_DefaultOutport1;
}