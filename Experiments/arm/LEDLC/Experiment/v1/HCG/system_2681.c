#include "define.h"
struct system_2681_state system_2681_instance;
void system_2681_Init(struct system_2681_state* self) {
    system_2687_Init(&system_2687_instance);
    system_2692_Init(&system_2692_instance);
    system_2696_Init(&system_2696_instance);
    system_2710_Init(&system_2710_instance);
    system_2724_Init(&system_2724_instance);
    system_2728_Init(&system_2728_instance);
}
void system_2681_Update(struct system_2681_state* self, float t, int* Output1) {
    float Data_StoreRead_DefaultOutport1 = 0;
    bool Switch_Case_DefaultOutport1 = 0;
    bool Switch_Case_DefaultOutport2 = 0;
    bool Switch_Case_DefaultOutport3 = 0;
    bool Switch_Case_DefaultOutport4 = 0;
    bool Switch_Case_DefaultOutport5 = 0;
    bool Switch_Case_DefaultOutport6 = 0;
    int Merge_DefaultOutport1 = 0;
    Data_StoreRead_DefaultOutport1 = Data_StoreMemory7_State;
    Switch_Case_DefaultOutport1 = Data_StoreRead_DefaultOutport1 == 0;
    Switch_Case_DefaultOutport2 = Data_StoreRead_DefaultOutport1 == 1;
    Switch_Case_DefaultOutport3 = Data_StoreRead_DefaultOutport1 == 2;
    Switch_Case_DefaultOutport4 = Data_StoreRead_DefaultOutport1 == 3;
    Switch_Case_DefaultOutport5 = Data_StoreRead_DefaultOutport1 == 4;
    Switch_Case_DefaultOutport6 = !Switch_Case_DefaultOutport1 && !Switch_Case_DefaultOutport2 && !Switch_Case_DefaultOutport3 && !Switch_Case_DefaultOutport4 && !Switch_Case_DefaultOutport5;
    if (Switch_Case_DefaultOutport1) {
        system_2687_Update(&system_2687_instance, &Merge_DefaultOutport1);
    }
    if (Switch_Case_DefaultOutport6) {
        system_2692_Update(&system_2692_instance, &Merge_DefaultOutport1);
    }
    if (Switch_Case_DefaultOutport2) {
        system_2696_Update(&system_2696_instance, t, &Merge_DefaultOutport1);
    }
    if (Switch_Case_DefaultOutport3) {
        system_2710_Update(&system_2710_instance, t, &Merge_DefaultOutport1);
    }
    if (Switch_Case_DefaultOutport4) {
        system_2724_Update(&system_2724_instance);
    }
    if (Switch_Case_DefaultOutport5) {
        system_2728_Update(&system_2728_instance, t, &Merge_DefaultOutport1);
    }
    *Output1 = Merge_DefaultOutport1;
}