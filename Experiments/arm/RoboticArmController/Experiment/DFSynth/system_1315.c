#include "define.h"
struct system_1315_state system_1315_instance;
void system_1315_Init(struct system_1315_state* self) {
    system_1319_Init(&system_1319_instance);
}
void system_1315_Update(struct system_1315_state* self, int ArmId, int P1, int P2, int P3, int* Res, int* B) {
    int Constant_DefaultOutport1;
    *Res = ArmId;
    Constant_DefaultOutport1 = 1;
    system_1319_Update(&system_1319_instance, ArmId, P1, P2, P3);
    *B = Constant_DefaultOutport1;
}