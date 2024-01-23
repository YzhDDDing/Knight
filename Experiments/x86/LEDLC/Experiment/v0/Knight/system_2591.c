#include "define.h"
struct system_2591_state system_2591_instance;
void system_2591_Init(struct system_2591_state* self) {
}
void system_2591_Update(struct system_2591_state* self, float t) {
    bool CompareTo_Constant_DefaultOutport1;
    bool CompareTo_Constant1_DefaultOutport1;
    float Constant_DefaultOutport1;
    int Data_StoreRead_DefaultOutport1;
    float * Data_StoreRead1_DefaultOutport1 = &(Data_StoreMemory_Data[0]);
    bool AND_DefaultOutport1;
    float Switch_DefaultOutport1;
    float Assignment_DefaultOutport1[256];
    unsigned char Assignment_init = 0;
    CompareTo_Constant_DefaultOutport1 = t <= 2;
    CompareTo_Constant1_DefaultOutport1 = t >= 1;
    Constant_DefaultOutport1 = 1.5;
    Data_StoreRead_DefaultOutport1 = Data_StoreMemory2_Index;
    AND_DefaultOutport1 = (CompareTo_Constant_DefaultOutport1 && CompareTo_Constant1_DefaultOutport1);
    if (AND_DefaultOutport1 != 0) {
        Switch_DefaultOutport1 = Constant_DefaultOutport1;
    }
    else {
        Switch_DefaultOutport1 = t;
    }
    if (Assignment_init == 0) {
        Assignment_init = 1;
        int batchIndex;
        for (batchIndex = 0; batchIndex < 256; batchIndex++) {
            Assignment_DefaultOutport1[batchIndex] = Data_StoreRead1_DefaultOutport1[batchIndex];
        }
    }
    Assignment_DefaultOutport1[Data_StoreRead_DefaultOutport1] = Switch_DefaultOutport1;
    for (int Data_StoreWrite_i = 0;Data_StoreWrite_i < 256;Data_StoreWrite_i++) {
        Data_StoreMemory_Data[Data_StoreWrite_i] = Assignment_DefaultOutport1[Data_StoreWrite_i];
    }
}