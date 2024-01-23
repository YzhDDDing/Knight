#include "define.h"
struct system_301_state system_301_instance;
void system_301_Init(struct system_301_state* self) {
    system_305_Init(&system_305_instance);
}
void system_301_Update(struct system_301_state* self, int value, int para) {
    system_305_Update(&system_305_instance, value);
}