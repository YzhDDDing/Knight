#include "define.h"
struct system_1885_state system_1885_instance;
void system_1885_Init(struct system_1885_state* self) {
}
void system_1885_Update(struct system_1885_state* self) {
    int Constant1_DefaultOutport1;
    float Constant2_DefaultOutport1;
    float * Data_StoreRead_DefaultOutport1 = &(Data_StoreMemory_Data[0]);
    int * Data_StoreRead1_DefaultOutport1 = &(Data_StoreMemory6_Satisfied[0]);
    int For_Iterator_DefaultOutport1 = -1;
    float delta_DefaultOutport1;
    int shift_DefaultOutport1;
    float Assignment_DefaultOutport1[256];
    unsigned char Assignment_init = 0;
    int Assignment1_DefaultOutport1[256];
    unsigned char Assignment1_init = 0;
    float Add_DefaultOutport1[256];
    int Add1_DefaultOutport1[256];
    for (int i = 0; i < 256; i++) {
        Constant1_DefaultOutport1 = 0;
        Constant2_DefaultOutport1 = 0;
        For_Iterator_DefaultOutport1++;
        delta_DefaultOutport1 = 15;
        shift_DefaultOutport1 = 15;
        if (Assignment_init == 0) {
            Assignment_init = 1;
            int batchIndex;
            for (batchIndex = 0; batchIndex < 256; batchIndex++) {
                Assignment_DefaultOutport1[batchIndex] = Data_StoreRead_DefaultOutport1[batchIndex];
            }
        }
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Constant2_DefaultOutport1;
        if (Assignment1_init == 0) {
            Assignment1_init = 1;
            int batchIndex;
            for (batchIndex = 0; batchIndex < 256; batchIndex++) {
                Assignment1_DefaultOutport1[batchIndex] = Data_StoreRead1_DefaultOutport1[batchIndex];
            }
        }
        Assignment1_DefaultOutport1[For_Iterator_DefaultOutport1] = Constant1_DefaultOutport1;
    }
    int batchIndex;
    for (batchIndex = 0; batchIndex < 256; batchIndex++) {
        Add_DefaultOutport1[batchIndex] = delta_DefaultOutport1 + Assignment_DefaultOutport1[batchIndex];
    }
    int batchIndex1;
    for (batchIndex1 = 0; batchIndex1 < 256; batchIndex1++) {
        Add1_DefaultOutport1[batchIndex1] = Assignment1_DefaultOutport1[batchIndex1] + shift_DefaultOutport1;
    }
    for (int Data_StoreWrite1_i = 0;Data_StoreWrite1_i < 256;Data_StoreWrite1_i++) {
        Data_StoreMemory6_Satisfied[Data_StoreWrite1_i] = Assignment1_DefaultOutport1[Data_StoreWrite1_i];
    }
    for (int Data_StoreWrite_i = 0;Data_StoreWrite_i < 256;Data_StoreWrite_i++) {
        Data_StoreMemory_Data[Data_StoreWrite_i] = Assignment_DefaultOutport1[Data_StoreWrite_i];
    }
    for (int Data_StoreWrite3_i = 0;Data_StoreWrite3_i < 256;Data_StoreWrite3_i++) {
        Data_StoreMemory9_Sat_o[Data_StoreWrite3_i] = Add1_DefaultOutport1[Data_StoreWrite3_i];
    }
    for (int Data_StoreWrite2_i = 0;Data_StoreWrite2_i < 256;Data_StoreWrite2_i++) {
        Data_StoreMemory8_Data_o[Data_StoreWrite2_i] = Add_DefaultOutport1[Data_StoreWrite2_i];
    }
}