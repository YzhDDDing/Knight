#include "define.h"
int Data_StoreMemory_Di_s1[32];
int Data_StoreMemory1_Di_s2[32];
int Data_StoreMemory2_Di_m1[32];
int Data_StoreMemory3_Di_m2[32];
struct system_236_state system_236_instance;
void system_236_Init(struct system_236_state* self) {
    memset(Data_StoreMemory_Di_s1, 0, sizeof(Data_StoreMemory_Di_s1));
    memset(Data_StoreMemory1_Di_s2, 0, sizeof(Data_StoreMemory1_Di_s2));
    memset(Data_StoreMemory2_Di_m1, 0, sizeof(Data_StoreMemory2_Di_m1));
    memset(Data_StoreMemory3_Di_m2, 0, sizeof(Data_StoreMemory3_Di_m2));
    system_243_Init(&system_243_instance);
    system_267_Init(&system_267_instance);
}
void system_236_Update(struct system_236_state* self, float Inport, int Output[32]) {
    int FunctionCallSubsystem_Outport[32] = {0};
    int FunctionCallSubsystem1_Outport[32] = {0};
    int Merge_DefaultOutport1[32] = {0};
    system_243_Update(&system_243_instance, FunctionCallSubsystem_Outport);
    system_267_Update(&system_267_instance, Inport, FunctionCallSubsystem1_Outport);
    int batchIndex = 0;
    for (batchIndex = 0;batchIndex < 32;batchIndex += 4) {
        int32x4_t Merge_DefaultOutport1_Batch = vld1q_s32(Merge_DefaultOutport1 + batchIndex);
        vst1q_s32(Output + batchIndex, Merge_DefaultOutport1_Batch);
    }
}