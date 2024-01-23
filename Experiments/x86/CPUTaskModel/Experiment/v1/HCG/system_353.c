#include "define.h"
int Data_StoreMemory3_B[64];
struct system_353_state system_353_instance;
void system_353_Init(struct system_353_state* self) {
    memset(Data_StoreMemory3_B, 0, sizeof(Data_StoreMemory3_B));
    system_15_Init(&system_15_instance);
    system_19_Init(&system_19_instance);
    system_23_Init(&system_23_instance);
    system_27_Init(&system_27_instance);
    system_39_Init(&system_39_instance);
}
void system_353_Update(struct system_353_state* self, int taskId, int op, int para, int* res, int* out) {
    bool Switch_Case_DefaultOutport1;
    bool Switch_Case_DefaultOutport2;
    bool Switch_Case_DefaultOutport3;
    bool Switch_Case_DefaultOutport4;
    bool Switch_Case_DefaultOutport5;
    int Merge_DefaultOutport1;
    int Merge1_DefaultOutport1;
    Switch_Case_DefaultOutport1 = op == 1;
    Switch_Case_DefaultOutport2 = op == 2;
    Switch_Case_DefaultOutport3 = op == 3;
    Switch_Case_DefaultOutport4 = op == 4;
    Switch_Case_DefaultOutport5 = !Switch_Case_DefaultOutport1 && !Switch_Case_DefaultOutport2 && !Switch_Case_DefaultOutport3 && !Switch_Case_DefaultOutport4;
    if (Switch_Case_DefaultOutport1) {
        system_15_Update(&system_15_instance, taskId, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (Switch_Case_DefaultOutport2) {
        system_19_Update(&system_19_instance, taskId, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (Switch_Case_DefaultOutport3) {
        system_23_Update(&system_23_instance, taskId, para, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (Switch_Case_DefaultOutport4) {
        system_27_Update(&system_27_instance, taskId, para, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (Switch_Case_DefaultOutport5) {
        system_39_Update(&system_39_instance, taskId, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    *res = Merge_DefaultOutport1;
    *out = Merge1_DefaultOutport1;
}