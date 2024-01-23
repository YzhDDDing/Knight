#include "define.h"
int PortPool_PortPool[256];
int PortPool1_PortPoolF[256];
int PortPool2_PortConfound[256];
int PortPool3_PortConfoundF[256];
int PortPool4_Bright[256];
int PortPool5_BrightF[256];
struct system_1253_state system_1253_instance;
void system_1253_Init(struct system_1253_state* self) {
    memset(PortPool_PortPool, 0, sizeof(PortPool_PortPool));
    memset(PortPool1_PortPoolF, 0, sizeof(PortPool1_PortPoolF));
    memset(PortPool2_PortConfound, 0, sizeof(PortPool2_PortConfound));
    memset(PortPool3_PortConfoundF, 0, sizeof(PortPool3_PortConfoundF));
    memset(PortPool4_Bright, 0, sizeof(PortPool4_Bright));
    memset(PortPool5_BrightF, 0, sizeof(PortPool5_BrightF));
    system_684_Init(&system_684_instance);
    system_714_Init(&system_714_instance);
    system_698_Init(&system_698_instance);
    system_634_Init(&system_634_instance);
    system_670_Init(&system_670_instance);
}
void system_1253_Update(struct system_1253_state* self, int In1, int In2, int In3, int In4, int In5, int* Out1, int* Out2) {
    bool Switch_Case_DefaultOutport1 = 0;
    bool Switch_Case_DefaultOutport2 = 0;
    bool Switch_Case_DefaultOutport3 = 0;
    bool Switch_Case_DefaultOutport4 = 0;
    bool Switch_Case_DefaultOutport5 = 0;
    int Merge_DefaultOutport1 = 0;
    int Merge1_DefaultOutport1 = 0;
    Switch_Case_DefaultOutport1 = In2 == 10001;
    Switch_Case_DefaultOutport2 = In2 == 10002;
    Switch_Case_DefaultOutport3 = In2 == 10003;
    Switch_Case_DefaultOutport4 = In2 == 10004;
    Switch_Case_DefaultOutport5 = !Switch_Case_DefaultOutport1 && !Switch_Case_DefaultOutport2 && !Switch_Case_DefaultOutport3 && !Switch_Case_DefaultOutport4;
    if (Switch_Case_DefaultOutport3) {
        system_684_Update(&system_684_instance, In1, In3, In4, In5, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (Switch_Case_DefaultOutport5) {
        system_714_Update(&system_714_instance, In1, In3, In4, In5, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (Switch_Case_DefaultOutport4) {
        system_698_Update(&system_698_instance, In1, In3, In4, In5, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (Switch_Case_DefaultOutport1) {
        system_634_Update(&system_634_instance, In1, In3, In4, In5, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (Switch_Case_DefaultOutport2) {
        system_670_Update(&system_670_instance, In1, In3, In4, In5, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    *Out1 = Merge_DefaultOutport1;
    *Out2 = Merge1_DefaultOutport1;
}