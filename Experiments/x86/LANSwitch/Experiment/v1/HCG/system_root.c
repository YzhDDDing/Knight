#include "define.h"
struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self) {
    system_1253_Init(&system_1253_instance);
}
void system_root_Update(struct system_root_state* self, int PortId, int CMD, int Arg1, int Arg2, int Arg3, int* Result, int* MSG) {
    int Subsystem_Out1 = 0;
    int Subsystem_Out2 = 0;
    system_1253_Update(&system_1253_instance, PortId, CMD, Arg1, Arg2, Arg3, &Subsystem_Out1, &Subsystem_Out2);
    *Result = Subsystem_Out1;
    *MSG = Subsystem_Out2;
}