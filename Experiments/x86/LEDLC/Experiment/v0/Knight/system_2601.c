#include "define.h"
struct system_2601_state system_2601_instance;
void system_2601_Init(struct system_2601_state* self) {
}
void system_2601_Update(struct system_2601_state* self) {
    int Data_StoreRead_DefaultOutport1;
    int * Data_StoreRead1_DefaultOutport1 = &(Data_StoreMemory6_Satisfied[0]);
    int For_Iterator_DefaultOutport1 = -1;
    float delta_DefaultOutport1;
    bool CompareTo_Constant1_DefaultOutport1;
    int Selector_DefaultOutport1;
    int Assignment_DefaultOutport1[256];
    unsigned char Assignment_init = 0;
    bool CompareTo_Constant_DefaultOutport1;
    bool AND_DefaultOutport1;
    int Add_DefaultOutport1[256];
    int Product_DefaultOutport1[256];
    int Switch_DefaultOutport1;
    int Switch1_DefaultOutport1[256];
    for (int i = 0; i < 256; i++) {
        Data_StoreRead_DefaultOutport1 = Data_StoreMemory2_Index;
        For_Iterator_DefaultOutport1++;
        delta_DefaultOutport1 = 2;
        CompareTo_Constant1_DefaultOutport1 = Data_StoreRead_DefaultOutport1 == -1;
        Selector_DefaultOutport1 = Data_StoreRead1_DefaultOutport1[For_Iterator_DefaultOutport1];
        if (Assignment_init == 0) {
            Assignment_init = 1;
            int batchIndex;
            for (batchIndex = 0; batchIndex < 256; batchIndex++) {
                Assignment_DefaultOutport1[batchIndex] = Data_StoreRead1_DefaultOutport1[batchIndex];
            }
        }
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Selector_DefaultOutport1;
        CompareTo_Constant_DefaultOutport1 = Selector_DefaultOutport1 == 0;
        AND_DefaultOutport1 = (CompareTo_Constant1_DefaultOutport1 && CompareTo_Constant_DefaultOutport1);
        if (AND_DefaultOutport1 != 0) {
            Switch_DefaultOutport1 = For_Iterator_DefaultOutport1;
        }
        else {
            Switch_DefaultOutport1 = Data_StoreRead_DefaultOutport1;
        }
        Data_StoreMemory2_Index = Switch_DefaultOutport1;
    }
    int batchIndex;
    for (batchIndex = 0; batchIndex < 256; batchIndex++) {
        Add_DefaultOutport1[batchIndex] = Assignment_DefaultOutport1[batchIndex] + Data_StoreRead_DefaultOutport1;
    }
    int batchIndex1;
    for (batchIndex1 = 0; batchIndex1 < 256; batchIndex1++) {
        Product_DefaultOutport1[batchIndex1] = (int)(Add_DefaultOutport1[batchIndex1] * (int)delta_DefaultOutport1);
    }
    for (int Switch1_i = 0;Switch1_i < 256;Switch1_i++) {
        if (Assignment_DefaultOutport1[Switch1_i] > 144) {
            Switch1_DefaultOutport1[Switch1_i] = Assignment_DefaultOutport1[Switch1_i];
        }
        else {
            Switch1_DefaultOutport1[Switch1_i] = Product_DefaultOutport1[Switch1_i];
        }
    }
    for (int Data_StoreWrite2_i = 0;Data_StoreWrite2_i < 256;Data_StoreWrite2_i++) {
        Data_StoreMemory9_Sat_o[Data_StoreWrite2_i] = Switch1_DefaultOutport1[Data_StoreWrite2_i];
    }
}