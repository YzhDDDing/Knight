#include "define.h"
struct system_833_state system_833_instance;
void system_833_Init(struct system_833_state* self) {
}
void system_833_Update(struct system_833_state* self, int ArmId, int FindE) {
    int Constant_DefaultOutport1;
    int * Data_StoreRead_DefaultOutport1 = &(PortPool_ArmIdPool[0]);
    int * Data_StoreRead1_DefaultOutport1 = &(PortPool1_ArmIdPoolF[0]);
    int For_Iterator_DefaultOutport1 = -1;
    int T_DefaultOutport1;
    int delta_DefaultOutport1;
    int key_DefaultOutport1;
    int key1_DefaultOutport1;
    bool Equal_DefaultOutport1;
    int Selector_DefaultOutport1;
    int Selector1_DefaultOutport1;
    int Switch_DefaultOutport1;
    int Switch1_DefaultOutport1;
    int Assignment_DefaultOutport1[128];
    unsigned char Assignment_init = 0;
    int Assignment1_DefaultOutport1[128];
    unsigned char Assignment1_init = 0;
    int Add_DefaultOutport1[128];
    int Add1_DefaultOutport1[128];
    int Product_DefaultOutport1[128];
    int Product1_DefaultOutport1[128];
    int Subtract_DefaultOutport1[128];
    int Subtract1_DefaultOutport1[128];
    for (int i = 0; i < 128; i++) {
        Constant_DefaultOutport1 = 1;
        For_Iterator_DefaultOutport1++;
        T_DefaultOutport1 = 4;
        delta_DefaultOutport1 = 3;
        key_DefaultOutport1 = 201;
        key1_DefaultOutport1 = 201;
        Equal_DefaultOutport1 = FindE == For_Iterator_DefaultOutport1;
        Selector_DefaultOutport1 = Data_StoreRead_DefaultOutport1[For_Iterator_DefaultOutport1];
        Selector1_DefaultOutport1 = Data_StoreRead1_DefaultOutport1[For_Iterator_DefaultOutport1];
        if (Equal_DefaultOutport1 > 0) {
            Switch_DefaultOutport1 = ArmId;
        }
        else {
            Switch_DefaultOutport1 = Selector_DefaultOutport1;
        }
        if (Equal_DefaultOutport1 > 0) {
            Switch1_DefaultOutport1 = Constant_DefaultOutport1;
        }
        else {
            Switch1_DefaultOutport1 = Selector1_DefaultOutport1;
        }
        if (Assignment_init == 0) {
            Assignment_init = 1;
            int batchIndex;
            for (batchIndex = 0; batchIndex < 128; batchIndex++) {
                Assignment_DefaultOutport1[batchIndex] = Data_StoreRead_DefaultOutport1[batchIndex];
            }
        }
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Switch_DefaultOutport1;
        if (Assignment1_init == 0) {
            Assignment1_init = 1;
            int batchIndex;
            for (batchIndex = 0; batchIndex < 128; batchIndex++) {
                Assignment1_DefaultOutport1[batchIndex] = Data_StoreRead1_DefaultOutport1[batchIndex];
            }
        }
        Assignment1_DefaultOutport1[For_Iterator_DefaultOutport1] = Switch1_DefaultOutport1;
        int batchIndex;
        for (batchIndex = 0; batchIndex < 128; batchIndex++) {
            Add_DefaultOutport1[batchIndex] = ArmId + Assignment_DefaultOutport1[batchIndex];
        }
        int batchIndex1;
        for (batchIndex1 = 0; batchIndex1 < 128; batchIndex1++) {
            Add1_DefaultOutport1[batchIndex1] = Assignment1_DefaultOutport1[batchIndex1] + ArmId;
        }
        for (int Data_StoreWrite_i = 0;Data_StoreWrite_i < 128;Data_StoreWrite_i++) {
            PortPool_ArmIdPool[Data_StoreWrite_i] = Assignment_DefaultOutport1[Data_StoreWrite_i];
        }
        for (int Data_StoreWrite1_i = 0;Data_StoreWrite1_i < 128;Data_StoreWrite1_i++) {
            PortPool1_ArmIdPoolF[Data_StoreWrite1_i] = Assignment1_DefaultOutport1[Data_StoreWrite1_i];
        }
        int batchIndex2;
        for (batchIndex2 = 0; batchIndex2 < 128; batchIndex2++) {
            Product_DefaultOutport1[batchIndex2] = delta_DefaultOutport1 * Add_DefaultOutport1[batchIndex2];
        }
        int batchIndex3;
        for (batchIndex3 = 0; batchIndex3 < 128; batchIndex3++) {
            Product1_DefaultOutport1[batchIndex3] = Add1_DefaultOutport1[batchIndex3] * T_DefaultOutport1;
        }
        int batchIndex4;
        for (batchIndex4 = 0; batchIndex4 < 128; batchIndex4++) {
            Subtract_DefaultOutport1[batchIndex4] = Product_DefaultOutport1[batchIndex4] - key_DefaultOutport1;
        }
        int batchIndex5;
        for (batchIndex5 = 0; batchIndex5 < 128; batchIndex5++) {
            Subtract1_DefaultOutport1[batchIndex5] = Product1_DefaultOutport1[batchIndex5] - key1_DefaultOutport1;
        }
        for (int Data_StoreWrite2_i = 0;Data_StoreWrite2_i < 128;Data_StoreWrite2_i++) {
            PortPool2_ArmIdPool_C[Data_StoreWrite2_i] = Subtract_DefaultOutport1[Data_StoreWrite2_i];
        }
        for (int Data_StoreWrite3_i = 0;Data_StoreWrite3_i < 128;Data_StoreWrite3_i++) {
            PortPool3_ArmIdPoolF_C[Data_StoreWrite3_i] = Subtract1_DefaultOutport1[Data_StoreWrite3_i];
        }
    }
}