#include "define.h"
struct system_772_state system_772_instance;
void system_772_Init(struct system_772_state* self) {
    system_805_Init(&system_805_instance);
    system_744_Init(&system_744_instance);
}
void system_772_Update(struct system_772_state* self, int SenserId, bool* FindS, int* FindE) {
    int FindEmpty_Out1;
    bool FindSenserId_Out1;
    system_805_Update(&system_805_instance, &FindEmpty_Out1);
    system_744_Update(&system_744_instance, SenserId, &FindSenserId_Out1);
    *FindS = FindSenserId_Out1;
    *FindE = FindEmpty_Out1;
}