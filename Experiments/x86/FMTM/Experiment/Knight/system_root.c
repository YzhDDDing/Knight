#include "define.h"
struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self) {
    system_1253_Init(&system_1253_instance);
}
void system_root_Update(struct system_root_state* self, int SenserId, int Opcode, int TValue, int* Res, int* R) {
    int Subsystem_Res;
    int Subsystem_R;
    system_1253_Update(&system_1253_instance, SenserId, Opcode, TValue, &Subsystem_Res, &Subsystem_R);
    *Res = Subsystem_Res;
    *R = Subsystem_R;
}