#include "define.h"
struct system_833_state system_833_instance;
void system_833_Init(struct system_833_state* self) {
}
void system_833_Update(struct system_833_state* self, int PortId, int FindE) {
    int Con_Value_DefaultOutport1;
    int Con_Value1_DefaultOutport1;
    int Constant_DefaultOutport1;
    int * Data_StoreRead_DefaultOutport1 = &(PortPool_PortPool[0]);
    int * Data_StoreRead1_DefaultOutport1 = &(PortPool1_PortPoolF[0]);
    int For_Iterator_DefaultOutport1 = -1;
    int T_DefaultOutport1;
    float T1_DefaultOutport1;
    int key_DefaultOutport1;
    float key1_DefaultOutport1;
    bool Equal_DefaultOutport1;
    int Selector_DefaultOutport1;
    int Selector1_DefaultOutport1;
    int Subtract1_DefaultOutport1;
    int Subtract3_DefaultOutport1;
    int Switch_DefaultOutport1;
    int Switch1_DefaultOutport1;
    int Assignment_DefaultOutport1[256];
    unsigned char Assignment_init = 0;
    int Assignment1_DefaultOutport1[256];
    unsigned char Assignment1_init = 0;
    int Add_DefaultOutport1[256];
    int Add1_DefaultOutport1[256];
    int Product1_DefaultOutport1[256];
    int Product3_DefaultOutport1[256];
    int Product_DefaultOutport1[256];
    int Product2_DefaultOutport1[256];
    int Subtract_DefaultOutport1[256];
    int Subtract2_DefaultOutport1[256];
    int Switch2_DefaultOutport1[256];
    int Switch3_DefaultOutport1[256];
    for (int i = 0; i < 256; i++) {
        Con_Value_DefaultOutport1 = 7;
        Con_Value1_DefaultOutport1 = 9;
        Constant_DefaultOutport1 = 1;
        For_Iterator_DefaultOutport1++;
        T_DefaultOutport1 = 11;
        T1_DefaultOutport1 = 5;
        key_DefaultOutport1 = 1004;
        key1_DefaultOutport1 = 1003;
        Equal_DefaultOutport1 = FindE == For_Iterator_DefaultOutport1;
        Selector_DefaultOutport1 = Data_StoreRead_DefaultOutport1[For_Iterator_DefaultOutport1];
        Selector1_DefaultOutport1 = Data_StoreRead1_DefaultOutport1[For_Iterator_DefaultOutport1];
        Subtract1_DefaultOutport1 = T_DefaultOutport1 - Con_Value_DefaultOutport1;
        Subtract3_DefaultOutport1 = T1_DefaultOutport1 - Con_Value1_DefaultOutport1;
        if (Equal_DefaultOutport1 > 0) {
            Switch_DefaultOutport1 = PortId;
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
            for (batchIndex = 0; batchIndex < 256; batchIndex++) {
                Assignment_DefaultOutport1[batchIndex] = Data_StoreRead_DefaultOutport1[batchIndex];
            }
        }
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Switch_DefaultOutport1;
        if (Assignment1_init == 0) {
            Assignment1_init = 1;
            int batchIndex;
            for (batchIndex = 0; batchIndex < 256; batchIndex++) {
                Assignment1_DefaultOutport1[batchIndex] = Data_StoreRead1_DefaultOutport1[batchIndex];
            }
        }
        Assignment1_DefaultOutport1[For_Iterator_DefaultOutport1] = Switch1_DefaultOutport1;
        int batchIndex;
        for (batchIndex = 0; batchIndex < 256; batchIndex++) {
            Add_DefaultOutport1[batchIndex] = Con_Value_DefaultOutport1 + Assignment_DefaultOutport1[batchIndex];
        }
        int batchIndex1;
        for (batchIndex1 = 0; batchIndex1 < 256; batchIndex1++) {
            Add1_DefaultOutport1[batchIndex1] = Assignment1_DefaultOutport1[batchIndex1] + Con_Value1_DefaultOutport1;
        }
        for (int Data_StoreWrite_i = 0;Data_StoreWrite_i < 256;Data_StoreWrite_i++) {
            PortPool_PortPool[Data_StoreWrite_i] = Assignment_DefaultOutport1[Data_StoreWrite_i];
        }
        for (int Data_StoreWrite1_i = 0;Data_StoreWrite1_i < 256;Data_StoreWrite1_i++) {
            PortPool1_PortPoolF[Data_StoreWrite1_i] = Assignment1_DefaultOutport1[Data_StoreWrite1_i];
        }
        int batchIndex2;
        for (batchIndex2 = 0; batchIndex2 < 256; batchIndex2++) {
            Product1_DefaultOutport1[batchIndex2] = Subtract1_DefaultOutport1 * Assignment_DefaultOutport1[batchIndex2];
        }
        int batchIndex3;
        for (batchIndex3 = 0; batchIndex3 < 256; batchIndex3++) {
            Product3_DefaultOutport1[batchIndex3] = Subtract3_DefaultOutport1 * Assignment1_DefaultOutport1[batchIndex3];
        }
        int batchIndex4;
        for (batchIndex4 = 0; batchIndex4 < 256; batchIndex4++) {
            Product_DefaultOutport1[batchIndex4] = T_DefaultOutport1 * Add_DefaultOutport1[batchIndex4];
        }
        int batchIndex5;
        for (batchIndex5 = 0; batchIndex5 < 256; batchIndex5++) {
            Product2_DefaultOutport1[batchIndex5] = (int)(Add1_DefaultOutport1[batchIndex5] * (int)T1_DefaultOutport1);
        }
        int batchIndex6;
        for (batchIndex6 = 0; batchIndex6 < 256; batchIndex6++) {
            Subtract_DefaultOutport1[batchIndex6] = Product_DefaultOutport1[batchIndex6] - key_DefaultOutport1;
        }
        int batchIndex7;
        for (batchIndex7 = 0; batchIndex7 < 256; batchIndex7++) {
            Subtract2_DefaultOutport1[batchIndex7] = (int)(Product2_DefaultOutport1[batchIndex7] - (int)key1_DefaultOutport1);
        }
        for (int Switch2_i = 0;Switch2_i < 256;Switch2_i++) {
            if (Subtract_DefaultOutport1[Switch2_i] > 1000) {
                Switch2_DefaultOutport1[Switch2_i] = Product1_DefaultOutport1[Switch2_i];
            }
            else {
                Switch2_DefaultOutport1[Switch2_i] = Assignment_DefaultOutport1[Switch2_i];
            }
        }
        for (int Switch3_i = 0;Switch3_i < 256;Switch3_i++) {
            if (Subtract2_DefaultOutport1[Switch3_i] > 1000) {
                Switch3_DefaultOutport1[Switch3_i] = Product3_DefaultOutport1[Switch3_i];
            }
            else {
                Switch3_DefaultOutport1[Switch3_i] = Assignment1_DefaultOutport1[Switch3_i];
            }
        }
        for (int Data_StoreWrite2_i = 0;Data_StoreWrite2_i < 256;Data_StoreWrite2_i++) {
            PortPool2_PortConfound[Data_StoreWrite2_i] = Switch2_DefaultOutport1[Data_StoreWrite2_i];
        }
        for (int Data_StoreWrite3_i = 0;Data_StoreWrite3_i < 256;Data_StoreWrite3_i++) {
            PortPool3_PortConfoundF[Data_StoreWrite3_i] = Switch3_DefaultOutport1[Data_StoreWrite3_i];
        }
    }
}