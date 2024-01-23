#include "define.h"
struct system_2700_state system_2700_instance;
void system_2700_Init(struct system_2700_state* self) {
}
void system_2700_Update(struct system_2700_state* self, float t, int* Output) {
    bool CompareTo_Constant_DefaultOutport1 = 0;
    bool CompareTo_Constant1_DefaultOutport1 = 0;
    int Constant_DefaultOutport1 = 0;
    int Constant1_DefaultOutport1 = 0;
    bool AND_DefaultOutport1 = 0;
    int Switch_DefaultOutport1 = 0;
    CompareTo_Constant_DefaultOutport1 = t > 7;
    CompareTo_Constant1_DefaultOutport1 = t < 11;
    Constant_DefaultOutport1 = -1;
    Constant1_DefaultOutport1 = -3;
    AND_DefaultOutport1 = (CompareTo_Constant_DefaultOutport1 && CompareTo_Constant1_DefaultOutport1);
    if (AND_DefaultOutport1 > 0) {
        Switch_DefaultOutport1 = Constant_DefaultOutport1;
    }
    else {
        Switch_DefaultOutport1 = Constant1_DefaultOutport1;
    }
    *Output = Switch_DefaultOutport1;
}