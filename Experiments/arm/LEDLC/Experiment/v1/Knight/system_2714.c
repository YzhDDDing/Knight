#include "define.h"
struct system_2714_state system_2714_instance;
void system_2714_Init(struct system_2714_state* self) {
}
void system_2714_Update(struct system_2714_state* self, float t, int* Output) {
    bool CompareTo_Constant_DefaultOutport1;
    bool CompareTo_Constant1_DefaultOutport1;
    int Constant1_DefaultOutport1;
    int Constant2_DefaultOutport1;
    bool AND_DefaultOutport1;
    int Switch_DefaultOutport1;
    CompareTo_Constant_DefaultOutport1 = t > 19;
    CompareTo_Constant1_DefaultOutport1 = t < 23;
    Constant1_DefaultOutport1 = -1;
    Constant2_DefaultOutport1 = -3;
    AND_DefaultOutport1 = (CompareTo_Constant_DefaultOutport1 && CompareTo_Constant1_DefaultOutport1);
    if (AND_DefaultOutport1 > 0) {
        Switch_DefaultOutport1 = Constant1_DefaultOutport1;
    }
    else {
        Switch_DefaultOutport1 = Constant2_DefaultOutport1;
    }
    *Output = Switch_DefaultOutport1;
}