#include "define.h"
struct system_2760_state system_2760_instance;
void system_2760_Init(struct system_2760_state* self) {
    system_2762_Init(&system_2762_instance);
}
void system_2760_Update(struct system_2760_state* self) {
    system_2762_Update(&system_2762_instance);
}