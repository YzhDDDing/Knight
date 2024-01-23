#include "define.h"
struct system_1434_state system_1434_instance;
void system_1434_Init(struct system_1434_state* self) {
    system_1441_Init(&system_1441_instance);
}
void system_1434_Update(struct system_1434_state* self, int ArmId, int P1, int P2, int P3, int* Res, int* B) {
    int Constant_DefaultOutport1 = 0;
    *Res = ArmId;
    Constant_DefaultOutport1 = 1;
    system_1441_Update(&system_1441_instance, ArmId, P1, P2, P3);
    *B = Constant_DefaultOutport1;
}