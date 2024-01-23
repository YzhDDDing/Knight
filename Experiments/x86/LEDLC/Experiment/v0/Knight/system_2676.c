#include "define.h"
struct system_2676_state system_2676_instance;
void system_2676_Init(struct system_2676_state* self) {
    system_2681_Init(&system_2681_instance);
}
void system_2676_Update(struct system_2676_state* self, float t, int* Output) {
    int Data_StoreRead_DefaultOutport1;
    bool If_DefaultOutport1;
    bool If_DefaultOutport2;
    int If_ActionSubsystem_Output1;
    Data_StoreRead_DefaultOutport1 = Data_StoreMemory4_Terminate;
    If_DefaultOutport1 = (Data_StoreRead_DefaultOutport1 == 0);
    If_DefaultOutport2 = !(Data_StoreRead_DefaultOutport1 == 0);
    if (If_DefaultOutport2) {
        system_2681_Update(&system_2681_instance, t, &If_ActionSubsystem_Output1);
    }
    *Output = If_ActionSubsystem_Output1;
}