#include "define.h"
struct system_1296_state system_1296_instance;
void system_1296_Init(struct system_1296_state* self) {
    system_886_Init(&system_886_instance);
    system_864_Init(&system_864_instance);
}
void system_1296_Update(struct system_1296_state* self, int SenserId, bool Gate, int* Out1, int* Out2) {
    bool If_DefaultOutport1;
    bool If_DefaultOutport2;
    int Merge_DefaultOutport1;
    int Merge1_DefaultOutport1;
    If_DefaultOutport1 = (Gate != 0);
    If_DefaultOutport2 = !(Gate != 0);
    if (If_DefaultOutport1) {
        system_886_Update(&system_886_instance, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (If_DefaultOutport2) {
        system_864_Update(&system_864_instance, SenserId, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    *Out1 = Merge_DefaultOutport1;
    *Out2 = Merge1_DefaultOutport1;
}