#include "define.h"
struct system_2728_state system_2728_instance;
void system_2728_Init(struct system_2728_state* self) {
    system_2732_Init(&system_2732_instance);
}
void system_2728_Update(struct system_2728_state* self, float t, int* Output) {
    bool If_DefaultOutport1 = 0;
    bool If_DefaultOutport2 = 0;
    int If_ActionSubsystem_Output = 0;
    If_DefaultOutport1 = (t != -1);
    If_DefaultOutport2 = !(t != -1);
    if (If_DefaultOutport1) {
        system_2732_Update(&system_2732_instance, t, &If_ActionSubsystem_Output);
    }
    *Output = If_ActionSubsystem_Output;
}