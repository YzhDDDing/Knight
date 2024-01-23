#include "define.h"
struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self) {
    system_1827_Init(&system_1827_instance);
}
void system_root_Update(struct system_root_state* self, float t, int* Output) {
    int Subsystem_Output;
    system_1827_Update(&system_1827_instance, t, &Subsystem_Output);
    *Output = Subsystem_Output;
}