#include "define.h"
int A_state[64];
int B_state[64];
struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self) {
}
void system_root_Update(struct system_root_state* self, int Outport[64]) {
    system_209_Update(&system_209_instance, Outport);
}