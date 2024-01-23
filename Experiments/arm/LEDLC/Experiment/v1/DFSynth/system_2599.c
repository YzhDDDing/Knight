#include "define.h"
struct system_2599_state system_2599_instance;
void system_2599_Init(struct system_2599_state* self) {
    system_2601_Init(&system_2601_instance);
}
void system_2599_Update(struct system_2599_state* self) {
    system_2601_Update(&system_2601_instance);
}