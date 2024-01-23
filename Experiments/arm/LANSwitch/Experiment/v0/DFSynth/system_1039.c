#include "define.h"
struct system_1039_state system_1039_instance;
void system_1039_Init(struct system_1039_state* self) {
}
void system_1039_Update(struct system_1039_state* self, int PortId, int* Out1) {
    int * Data_StoreRead_DefaultOutport1 = &(PortPool_PortPool[0]);
    int Data_StoreRead1_DefaultOutport1;
    int * Data_StoreRead2_DefaultOutport1 = &(PortPool1_PortPoolF[0]);
    int For_Iterator_DefaultOutport1 = -1;
    int T_DefaultOutport1;
    int T1_DefaultOutport1;
    int T2_DefaultOutport1;
    int T3_DefaultOutport1;
    int delta1_DefaultOutport1;
    int delta2_DefaultOutport1;
    bool CompareTo_Constant1_DefaultOutport1;
    int Selector_DefaultOutport1;
    int Selector1_DefaultOutport1;
    int Assignment_DefaultOutport1[256];
    unsigned char Assignment_init = 0;
    int Assignment1_DefaultOutport1[256];
    unsigned char Assignment1_init = 0;
    bool CompareTo_Constant_DefaultOutport1;
    bool Equal_DefaultOutport1;
    bool AND1_DefaultOutport1;
    int Add_DefaultOutport1[256];
    int Add1_DefaultOutport1[256];
    int Add2_DefaultOutport1[256];
    int Add3_DefaultOutport1[256];
    bool AND_DefaultOutport1;
    int Product_DefaultOutport1[256];
    int Product1_DefaultOutport1[256];
    int Product2_DefaultOutport1[256];
    int Product3_DefaultOutport1[256];
    int Switch_DefaultOutport1;
    int Switch2_DefaultOutport1[256];
    int Switch3_DefaultOutport1[256];
    int Switch5_DefaultOutport1[256];
    int Switch6_DefaultOutport1[256];
    int Switch1_DefaultOutport1[256];
    int Switch4_DefaultOutport1[256];
    for (int i = 0; i < 256; i++) {
        Data_StoreRead1_DefaultOutport1 = Data_StoreMemory1_Found_P_2;
        For_Iterator_DefaultOutport1++;
        T_DefaultOutport1 = 2;
        T1_DefaultOutport1 = 2;
        T2_DefaultOutport1 = 2;
        T3_DefaultOutport1 = 2;
        delta1_DefaultOutport1 = 4;
        delta2_DefaultOutport1 = 4;
        CompareTo_Constant1_DefaultOutport1 = Data_StoreRead1_DefaultOutport1 == -1;
        Selector_DefaultOutport1 = Data_StoreRead_DefaultOutport1[For_Iterator_DefaultOutport1];
        Selector1_DefaultOutport1 = Data_StoreRead2_DefaultOutport1[For_Iterator_DefaultOutport1];
        if (Assignment_init == 0) {
            Assignment_init = 1;
            int batchIndex;
            for (batchIndex = 0; batchIndex < 256; batchIndex++) {
                Assignment_DefaultOutport1[batchIndex] = Data_StoreRead2_DefaultOutport1[batchIndex];
            }
        }
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Selector1_DefaultOutport1;
        if (Assignment1_init == 0) {
            Assignment1_init = 1;
            int batchIndex;
            for (batchIndex = 0; batchIndex < 256; batchIndex++) {
                Assignment1_DefaultOutport1[batchIndex] = Data_StoreRead_DefaultOutport1[batchIndex];
            }
        }
        Assignment1_DefaultOutport1[For_Iterator_DefaultOutport1] = Selector_DefaultOutport1;
        CompareTo_Constant_DefaultOutport1 = Selector1_DefaultOutport1 == 1;
        Equal_DefaultOutport1 = PortId == Selector_DefaultOutport1;
        AND1_DefaultOutport1 = (Equal_DefaultOutport1 && CompareTo_Constant_DefaultOutport1);
        int batchIndex;
        for (batchIndex = 0; batchIndex < 256; batchIndex++) {
            Add_DefaultOutport1[batchIndex] = PortId + Assignment_DefaultOutport1[batchIndex];
        }
        int batchIndex1;
        for (batchIndex1 = 0; batchIndex1 < 256; batchIndex1++) {
            Add1_DefaultOutport1[batchIndex1] = Assignment_DefaultOutport1[batchIndex1] - delta1_DefaultOutport1;
        }
        int batchIndex2;
        for (batchIndex2 = 0; batchIndex2 < 256; batchIndex2++) {
            Add2_DefaultOutport1[batchIndex2] = PortId + Assignment1_DefaultOutport1[batchIndex2];
        }
        int batchIndex3;
        for (batchIndex3 = 0; batchIndex3 < 256; batchIndex3++) {
            Add3_DefaultOutport1[batchIndex3] = Assignment1_DefaultOutport1[batchIndex3] - delta2_DefaultOutport1;
        }
        AND_DefaultOutport1 = (AND1_DefaultOutport1 && CompareTo_Constant1_DefaultOutport1);
        int batchIndex4;
        for (batchIndex4 = 0; batchIndex4 < 256; batchIndex4++) {
            Product_DefaultOutport1[batchIndex4] = Add_DefaultOutport1[batchIndex4] * T_DefaultOutport1;
        }
        int batchIndex5;
        for (batchIndex5 = 0; batchIndex5 < 256; batchIndex5++) {
            Product1_DefaultOutport1[batchIndex5] = Add1_DefaultOutport1[batchIndex5] * T1_DefaultOutport1;
        }
        int batchIndex6;
        for (batchIndex6 = 0; batchIndex6 < 256; batchIndex6++) {
            Product2_DefaultOutport1[batchIndex6] = Add2_DefaultOutport1[batchIndex6] * T2_DefaultOutport1;
        }
        int batchIndex7;
        for (batchIndex7 = 0; batchIndex7 < 256; batchIndex7++) {
            Product3_DefaultOutport1[batchIndex7] = Add3_DefaultOutport1[batchIndex7] * T3_DefaultOutport1;
        }
        if (AND_DefaultOutport1 != 0) {
            Switch_DefaultOutport1 = For_Iterator_DefaultOutport1;
        }
        else {
            Switch_DefaultOutport1 = Data_StoreRead1_DefaultOutport1;
        }
        for (int Switch2_i = 0;Switch2_i < 256;Switch2_i++) {
            if (Add_DefaultOutport1[Switch2_i] >= 19) {
                Switch2_DefaultOutport1[Switch2_i] = Add_DefaultOutport1[Switch2_i];
            }
            else {
                Switch2_DefaultOutport1[Switch2_i] = Product_DefaultOutport1[Switch2_i];
            }
        }
        for (int Switch3_i = 0;Switch3_i < 256;Switch3_i++) {
            if (Add1_DefaultOutport1[Switch3_i] >= 10) {
                Switch3_DefaultOutport1[Switch3_i] = Add1_DefaultOutport1[Switch3_i];
            }
            else {
                Switch3_DefaultOutport1[Switch3_i] = Product1_DefaultOutport1[Switch3_i];
            }
        }
        for (int Switch5_i = 0;Switch5_i < 256;Switch5_i++) {
            if (Add2_DefaultOutport1[Switch5_i] >= 19) {
                Switch5_DefaultOutport1[Switch5_i] = Add2_DefaultOutport1[Switch5_i];
            }
            else {
                Switch5_DefaultOutport1[Switch5_i] = Product2_DefaultOutport1[Switch5_i];
            }
        }
        for (int Switch6_i = 0;Switch6_i < 256;Switch6_i++) {
            if (Add3_DefaultOutport1[Switch6_i] >= 10) {
                Switch6_DefaultOutport1[Switch6_i] = Add3_DefaultOutport1[Switch6_i];
            }
            else {
                Switch6_DefaultOutport1[Switch6_i] = Product3_DefaultOutport1[Switch6_i];
            }
        }
        Data_StoreMemory1_Found_P_2 = Switch_DefaultOutport1;
        for (int Switch1_i = 0;Switch1_i < 256;Switch1_i++) {
            if (Assignment_DefaultOutport1[Switch1_i] >= 191) {
                Switch1_DefaultOutport1[Switch1_i] = Switch2_DefaultOutport1[Switch1_i];
            }
            else {
                Switch1_DefaultOutport1[Switch1_i] = Switch3_DefaultOutport1[Switch1_i];
            }
        }
        for (int Switch4_i = 0;Switch4_i < 256;Switch4_i++) {
            if (Assignment1_DefaultOutport1[Switch4_i] >= 191) {
                Switch4_DefaultOutport1[Switch4_i] = Switch5_DefaultOutport1[Switch4_i];
            }
            else {
                Switch4_DefaultOutport1[Switch4_i] = Switch6_DefaultOutport1[Switch4_i];
            }
        }
        for (int Data_StoreWrite_i = 0;Data_StoreWrite_i < 256;Data_StoreWrite_i++) {
            PortPool5_BrightF[Data_StoreWrite_i] = Switch1_DefaultOutport1[Data_StoreWrite_i];
        }
        for (int Data_StoreWrite2_i = 0;Data_StoreWrite2_i < 256;Data_StoreWrite2_i++) {
            PortPool4_Bright[Data_StoreWrite2_i] = Switch4_DefaultOutport1[Data_StoreWrite2_i];
        }
    }
    *Out1 = Switch_DefaultOutport1;
}