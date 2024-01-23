#include "define.h"
struct system_1036_state system_1036_instance;
void system_1036_Init(struct system_1036_state* self) {
    system_1039_Init(&system_1039_instance);
    system_1106_Init(&system_1106_instance);
}
void system_1036_Update(struct system_1036_state* self, int SenserId, int TValue, int* FindId, int* FindIdT) {
    int FindSenserId_Out1 = 0;
    int FindSenserIdT_FindPT = 0;
    system_1039_Update(&system_1039_instance, SenserId, &FindSenserId_Out1);
    system_1106_Update(&system_1106_instance, TValue, &FindSenserIdT_FindPT);
    *FindId = FindSenserId_Out1;
    *FindIdT = FindSenserIdT_FindPT;
}