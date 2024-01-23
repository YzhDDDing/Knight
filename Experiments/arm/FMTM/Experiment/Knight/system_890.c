#include "define.h"
struct system_890_state system_890_instance;
void system_890_Init(struct system_890_state* self) {
    system_893_Init(&system_893_instance);
    system_1296_Init(&system_1296_instance);
}
void system_890_Update(struct system_890_state* self, int SenserId, int* Res, int* R) {
    int FindSenserId_Out1;
    bool CompareTo_Constant1_DefaultOutport1;
    int Subsystem_Out1;
    int Subsystem_Out2;
    system_893_Update(&system_893_instance, SenserId, &FindSenserId_Out1);
    CompareTo_Constant1_DefaultOutport1 = FindSenserId_Out1 == -1;
    system_1296_Update(&system_1296_instance, SenserId, CompareTo_Constant1_DefaultOutport1, &Subsystem_Out1, &Subsystem_Out2);
    *Res = Subsystem_Out1;
    *R = Subsystem_Out2;
}