#include "define.h"
struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self) {
    system_1253_Init(&system_1253_instance);
}
void system_root_Update(struct system_root_state* self, int ArmId, int Op, int P1, int P2, int P3, int* Res, int* B) {
    int Main_Out1;
    int Main_Out2;
    system_1253_Update(&system_1253_instance, ArmId, Op, P1, P2, P3, &Main_Out1, &Main_Out2);
    *Res = Main_Out1;
    *B = Main_Out2;
}