#include "define.h"
struct system_2747_state system_2747_instance;
void system_2747_Init(struct system_2747_state* self) {
    system_2751_Init(&system_2751_instance);
    system_2760_Init(&system_2760_instance);
}
void system_2747_Update(struct system_2747_state* self) {
    system_2751_Update(&system_2751_instance);
    system_2760_Update(&system_2760_instance);
}