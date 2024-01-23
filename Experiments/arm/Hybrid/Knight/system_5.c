#include "define.h"
float Data_StoreMemory_default_hp1;
float Data_StoreMemory1_default_hp2;
float Data_StoreMemory2_default_hp3;
float Data_StoreMemory3_default_lp1;
float Data_StoreMemory4_default_lp2;
float Data_StoreMemory5_default_lp3;
double Data_StoreMemory6_S1[32];
double Data_StoreMemory7_S2[32];
double Data_StoreMemory8_S3[32];
struct system_5_state system_5_instance;
void system_5_Init(struct system_5_state* self) {
    Data_StoreMemory_default_hp1 = 0;
    Data_StoreMemory1_default_hp2 = 0;
    Data_StoreMemory2_default_hp3 = 0;
    Data_StoreMemory3_default_lp1 = 0;
    Data_StoreMemory4_default_lp2 = 0;
    Data_StoreMemory5_default_lp3 = 0;
    memset(Data_StoreMemory6_S1, 0, sizeof(Data_StoreMemory6_S1));
    memset(Data_StoreMemory7_S2, 0, sizeof(Data_StoreMemory7_S2));
    memset(Data_StoreMemory8_S3, 0, sizeof(Data_StoreMemory8_S3));
    system_14_Init(&system_14_instance);
    system_123_Init(&system_123_instance);
    system_134_Init(&system_134_instance);
}
void system_5_Update(struct system_5_state* self, double signal1[32], double signal2[32], double signal3[32], double signal_h1[32], double signal_h2[32], double signal_h3[32], double signal_l1[32], double signal_l2[32], double signal_l3[32]) {
    double HighPass_signal_h1[32] = {0};
    double HighPass_signal_h2[32] = {0};
    double HighPass_signal_h3[32] = {0};
    double LowPass_signal_l1[32] = {0};
    double LowPass_signal_l2[32] = {0};
    double LowPass_signal_l3[32] = {0};
    system_14_Update(&system_14_instance);
    system_123_Update(&system_123_instance, signal1, signal2, signal3, HighPass_signal_h1, HighPass_signal_h2, HighPass_signal_h3);
    system_134_Update(&system_134_instance, signal1, signal2, signal3, LowPass_signal_l1, LowPass_signal_l2, LowPass_signal_l3);
    int batchIndex;
    for (batchIndex = 0; batchIndex < 32; batchIndex++) {
        signal_h1[batchIndex] = HighPass_signal_h1[batchIndex];
    }
    int batchIndex1;
    for (batchIndex1 = 0; batchIndex1 < 32; batchIndex1++) {
        signal_h2[batchIndex1] = HighPass_signal_h2[batchIndex1];
    }
    int batchIndex2;
    for (batchIndex2 = 0; batchIndex2 < 32; batchIndex2++) {
        signal_h3[batchIndex2] = HighPass_signal_h3[batchIndex2];
    }
    int batchIndex3;
    for (batchIndex3 = 0; batchIndex3 < 32; batchIndex3++) {
        signal_l1[batchIndex3] = LowPass_signal_l1[batchIndex3];
    }
    int batchIndex4;
    for (batchIndex4 = 0; batchIndex4 < 32; batchIndex4++) {
        signal_l2[batchIndex4] = LowPass_signal_l2[batchIndex4];
    }
    int batchIndex5;
    for (batchIndex5 = 0; batchIndex5 < 32; batchIndex5++) {
        signal_l3[batchIndex5] = LowPass_signal_l3[batchIndex5];
    }
}