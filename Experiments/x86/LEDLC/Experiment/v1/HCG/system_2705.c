#include "define.h"
struct system_2705_state system_2705_instance;
void system_2705_Init(struct system_2705_state* self) {
}
void system_2705_Update(struct system_2705_state* self, float t, int* Out1) {
    bool CompareTo_Constant1_DefaultOutport1 = 0;
    bool CompareTo_Constant2_DefaultOutport1 = 0;
    int Constant_DefaultOutport1 = 0;
    int Constant1_DefaultOutport1 = 0;
    int Constant2_DefaultOutport1 = 0;
    bool AND_DefaultOutport1 = 0;
    int Switch_DefaultOutport1 = 0;
    CompareTo_Constant1_DefaultOutport1 = t > 0.5;
    CompareTo_Constant2_DefaultOutport1 = t < 1;
    Constant_DefaultOutport1 = 2;
    Constant1_DefaultOutport1 = 1;
    Constant2_DefaultOutport1 = 3;
    AND_DefaultOutport1 = (CompareTo_Constant1_DefaultOutport1 && CompareTo_Constant2_DefaultOutport1);
    Data_StoreMemory7_State = Constant_DefaultOutport1;
    if (AND_DefaultOutport1 > 0) {
        Switch_DefaultOutport1 = Constant1_DefaultOutport1;
    }
    else {
        Switch_DefaultOutport1 = Constant2_DefaultOutport1;
    }
    *Out1 = Switch_DefaultOutport1;
}