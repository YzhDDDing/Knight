#include "define.h"
int PortPool_ArmIdPool[128];
int PortPool1_ArmIdPoolF[128];
int PortPool2_ArmIdPool_C[128];
int PortPool3_ArmIdPoolF_C[128];
int angle_Angle[128];
int angle1_AngleF[128];
struct system_1253_state system_1253_instance;
void system_1253_Init(struct system_1253_state* self) {
    memset(PortPool_ArmIdPool, 0, sizeof(PortPool_ArmIdPool));
    memset(PortPool1_ArmIdPoolF, 0, sizeof(PortPool1_ArmIdPoolF));
    memset(PortPool2_ArmIdPool_C, 0, sizeof(PortPool2_ArmIdPool_C));
    memset(PortPool3_ArmIdPoolF_C, 0, sizeof(PortPool3_ArmIdPoolF_C));
    memset(angle_Angle, 0, sizeof(angle_Angle));
    memset(angle1_AngleF, 0, sizeof(angle1_AngleF));
    system_684_Init(&system_684_instance);
    system_714_Init(&system_714_instance);
    system_698_Init(&system_698_instance);
    system_1268_Init(&system_1268_instance);
    system_1384_Init(&system_1384_instance);
    system_670_Init(&system_670_instance);
    system_634_Init(&system_634_instance);
}
void system_1253_Update(struct system_1253_state* self, int ArmId, int In2, int In3, int In4, int In5, int* Out1, int* Out2) {
    bool Switch_Case_DefaultOutport1;
    bool Switch_Case_DefaultOutport2;
    bool Switch_Case_DefaultOutport3;
    bool Switch_Case_DefaultOutport4;
    bool Switch_Case_DefaultOutport5;
    bool Switch_Case_DefaultOutport6;
    bool Switch_Case_DefaultOutport7;
    int Merge_DefaultOutport1;
    int Merge1_DefaultOutport1;
    Switch_Case_DefaultOutport1 = In2 == 10001;
    Switch_Case_DefaultOutport2 = In2 == 10002;
    Switch_Case_DefaultOutport3 = In2 == 10004;
    Switch_Case_DefaultOutport4 = In2 == 10008;
    Switch_Case_DefaultOutport5 = In2 == 10016;
    Switch_Case_DefaultOutport6 = In2 == 10032;
    Switch_Case_DefaultOutport7 = !Switch_Case_DefaultOutport1 && !Switch_Case_DefaultOutport2 && !Switch_Case_DefaultOutport3 && !Switch_Case_DefaultOutport4 && !Switch_Case_DefaultOutport5 && !Switch_Case_DefaultOutport6;
    if (Switch_Case_DefaultOutport3) {
        system_684_Update(&system_684_instance, ArmId, In3, In4, In5, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (Switch_Case_DefaultOutport7) {
        system_714_Update(&system_714_instance, ArmId, In3, In4, In5, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (Switch_Case_DefaultOutport4) {
        system_698_Update(&system_698_instance, ArmId, In3, In4, In5, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (Switch_Case_DefaultOutport5) {
        system_1268_Update(&system_1268_instance, ArmId, In3, In4, In5, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (Switch_Case_DefaultOutport6) {
        system_1384_Update(&system_1384_instance, ArmId, In3, In4, In5, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (Switch_Case_DefaultOutport2) {
        system_670_Update(&system_670_instance, ArmId, In3, In4, In5, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (Switch_Case_DefaultOutport1) {
        system_634_Update(&system_634_instance, ArmId, In3, In4, In5, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    *Out1 = Merge_DefaultOutport1;
    *Out2 = Merge1_DefaultOutport1;
}