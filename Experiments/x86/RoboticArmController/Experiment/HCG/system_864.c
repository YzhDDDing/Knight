#include "define.h"
struct system_864_state system_864_instance;
void system_864_Init(struct system_864_state* self) {
    system_869_Init(&system_869_instance);
}
void system_864_Update(struct system_864_state* self, int ArmId, int* Res, int* B) {
    int Constant_DefaultOutport1 = 0;
    *Res = ArmId;
    Constant_DefaultOutport1 = 1;
    system_869_Update(&system_869_instance, ArmId);
    *B = Constant_DefaultOutport1;
}