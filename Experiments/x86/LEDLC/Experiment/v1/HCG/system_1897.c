#include "define.h"
struct system_1897_state system_1897_instance;
void system_1897_Init(struct system_1897_state* self) {
    system_2581_Init(&system_2581_instance);
    system_2599_Init(&system_2599_instance);
    system_2585_Init(&system_2585_instance);
}
void system_1897_Update(struct system_1897_state* self, float t) {
    system_2581_Update(&system_2581_instance);
    system_2599_Update(&system_2599_instance);
    system_2585_Update(&system_2585_instance, t);
}