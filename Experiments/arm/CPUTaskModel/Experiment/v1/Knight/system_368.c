#include "define.h"
struct system_368_state system_368_instance;
void system_368_Init(struct system_368_state* self) {
    system_58_Init(&system_58_instance);
}
void system_368_Update(struct system_368_state* self) {
    char Constant_DefaultOutport1;
    char Constant1_DefaultOutport1;
    Constant_DefaultOutport1 = 0;
    Constant1_DefaultOutport1 = 1;
    Data_StoreMemory2_Init = Constant1_DefaultOutport1;
    system_58_Update(&system_58_instance, Constant_DefaultOutport1);
}