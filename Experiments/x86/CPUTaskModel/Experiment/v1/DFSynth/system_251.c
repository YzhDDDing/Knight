#include "define.h"
struct system_251_state system_251_instance;
void system_251_Init(struct system_251_state* self) {
    system_254_Init(&system_254_instance);
}
void system_251_Update(struct system_251_state* self, int value, int value2) {
    system_254_Update(&system_254_instance, value, value2);
}