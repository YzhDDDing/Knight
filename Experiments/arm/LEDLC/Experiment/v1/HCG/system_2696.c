#include "define.h"
struct system_2696_state system_2696_instance;
void system_2696_Init(struct system_2696_state* self) {
    system_2700_Init(&system_2700_instance);
    system_2705_Init(&system_2705_instance);
}
void system_2696_Update(struct system_2696_state* self, float t, int* Output) {
    bool If_DefaultOutport1 = 0;
    bool If_DefaultOutport2 = 0;
    int Merge_DefaultOutport1 = 0;
    If_DefaultOutport1 = (t >= 2);
    If_DefaultOutport2 = !(t >= 2);
    if (If_DefaultOutport1) {
        system_2700_Update(&system_2700_instance, t, &Merge_DefaultOutport1);
    }
    if (If_DefaultOutport2) {
        system_2705_Update(&system_2705_instance, t, &Merge_DefaultOutport1);
    }
    *Output = Merge_DefaultOutport1;
}