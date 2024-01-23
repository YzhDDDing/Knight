#include "define.h"
float Data_StoreMemory_default_hp1;
float Data_StoreMemory1_default_hp2;
float Data_StoreMemory2_default_hp3;
float Data_StoreMemory3_S1[32];
float Data_StoreMemory4_S2[32];
float Data_StoreMemory5_S3[32];
struct system_5_state system_5_instance;
void system_5_Init(struct system_5_state* self) {
    Data_StoreMemory_default_hp1 = 0;
    Data_StoreMemory1_default_hp2 = 0;
    Data_StoreMemory2_default_hp3 = 0;
    memset(Data_StoreMemory3_S1, 0, sizeof(Data_StoreMemory3_S1));
    memset(Data_StoreMemory4_S2, 0, sizeof(Data_StoreMemory4_S2));
    memset(Data_StoreMemory5_S3, 0, sizeof(Data_StoreMemory5_S3));
    system_14_Init(&system_14_instance);
    system_18_Init(&system_18_instance);
    system_22_Init(&system_22_instance);
    system_26_Init(&system_26_instance);
}
void system_5_Update(struct system_5_state* self, float signal1[32], float signal2[32], float signal3[32], float signal_o1[32], float signal_o2[32], float signal_o3[32]) {
    float HighPass_S1_signal_o1[32] = {0};
    float HighPass_S2_signal_o2[32] = {0};
    float HighPass_S3_signal_o3[32] = {0};
    system_14_Update(&system_14_instance);
    system_18_Update(&system_18_instance, signal1, HighPass_S1_signal_o1);
    system_22_Update(&system_22_instance, signal2, HighPass_S2_signal_o2);
    system_26_Update(&system_26_instance, signal3, HighPass_S3_signal_o3);
    int batchIndex;
    for (batchIndex = 0; batchIndex < 32; batchIndex++) {
        signal_o1[batchIndex] = HighPass_S1_signal_o1[batchIndex];
    }
    int batchIndex1;
    for (batchIndex1 = 0; batchIndex1 < 32; batchIndex1++) {
        signal_o2[batchIndex1] = HighPass_S2_signal_o2[batchIndex1];
    }
    int batchIndex2;
    for (batchIndex2 = 0; batchIndex2 < 32; batchIndex2++) {
        signal_o3[batchIndex2] = HighPass_S3_signal_o3[batchIndex2];
    }
}