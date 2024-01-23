#include "define.h"
struct system_2710_state system_2710_instance;
void system_2710_Init(struct system_2710_state* self) {
    system_2714_Init(&system_2714_instance);
    system_2719_Init(&system_2719_instance);
}
void system_2710_Update(struct system_2710_state* self, float t, int* Output) {
    bool If_DefaultOutport1;
    bool If_DefaultOutport2;
    int Merge_DefaultOutport1;
    If_DefaultOutport1 = (t > 9);
    If_DefaultOutport2 = !(t > 9);
    if (If_DefaultOutport1) {
        system_2714_Update(&system_2714_instance, t, &Merge_DefaultOutport1);
    }
    if (If_DefaultOutport2) {
        system_2719_Update(&system_2719_instance, t, &Merge_DefaultOutport1);
    }
    *Output = Merge_DefaultOutport1;
}