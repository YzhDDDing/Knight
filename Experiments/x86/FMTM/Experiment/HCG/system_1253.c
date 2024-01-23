#include "define.h"
int SenserIdData_SenserIdData[256];
int SenserIdData1_SenserIdConfound[256];
int SenserIdUsed_SenserIdUsed[256];
int SenserIdUsed1_SenserUsedLog[256];
struct system_1253_state system_1253_instance;
void system_1253_Init(struct system_1253_state* self) {
    memset(SenserIdData_SenserIdData, 0, sizeof(SenserIdData_SenserIdData));
    memset(SenserIdData1_SenserIdConfound, 0, sizeof(SenserIdData1_SenserIdConfound));
    memset(SenserIdUsed_SenserIdUsed, 0, sizeof(SenserIdUsed_SenserIdUsed));
    memset(SenserIdUsed1_SenserUsedLog, 0, sizeof(SenserIdUsed1_SenserUsedLog));
    system_634_Init(&system_634_instance);
    system_698_Init(&system_698_instance);
    system_670_Init(&system_670_instance);
    system_684_Init(&system_684_instance);
}
void system_1253_Update(struct system_1253_state* self, int SenserId, int Opcode, int TValue, int* Res, int* R) {
    bool Switch_Case_DefaultOutport1 = 0;
    bool Switch_Case_DefaultOutport2 = 0;
    bool Switch_Case_DefaultOutport3 = 0;
    bool Switch_Case_DefaultOutport4 = 0;
    bool Switch_Case_DefaultOutport5 = 0;
    int Merge_DefaultOutport1 = 0;
    int Merge1_DefaultOutport1 = 0;
    Switch_Case_DefaultOutport1 = Opcode == 1;
    Switch_Case_DefaultOutport2 = Opcode == 3;
    Switch_Case_DefaultOutport3 = Opcode == 4;
    Switch_Case_DefaultOutport4 = Opcode == 5;
    Switch_Case_DefaultOutport5 = !Switch_Case_DefaultOutport1 && !Switch_Case_DefaultOutport2 && !Switch_Case_DefaultOutport3 && !Switch_Case_DefaultOutport4;
    if (Switch_Case_DefaultOutport1) {
        system_634_Update(&system_634_instance, SenserId, TValue, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (Switch_Case_DefaultOutport4) {
        system_698_Update(&system_698_instance, SenserId, TValue, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (Switch_Case_DefaultOutport2) {
        system_670_Update(&system_670_instance, SenserId, TValue, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (Switch_Case_DefaultOutport3) {
        system_684_Update(&system_684_instance, SenserId, TValue, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    *Res = Merge_DefaultOutport1;
    *R = Merge1_DefaultOutport1;
}