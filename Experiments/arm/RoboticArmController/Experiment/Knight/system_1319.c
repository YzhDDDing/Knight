#include "define.h"
struct system_1319_state system_1319_instance;
void system_1319_Init(struct system_1319_state* self) {
}
void system_1319_Update(struct system_1319_state* self, int FindP, int P1, int P2, int P3) {
    bool CompareTo_Constant_DefaultOutport1;
    bool CompareTo_Constant1_DefaultOutport1;
    bool CompareTo_Constant2_DefaultOutport1;
    int Constant_DefaultOutport1;
    int Constant1_DefaultOutport1;
    int Constant2_DefaultOutport1;
    int Constant3_DefaultOutport1;
    int * Data_StoreRead_DefaultOutport1 = &(PortPool_ArmIdPool[0]);
    int * Data_StoreRead2_DefaultOutport1 = &(PortPool1_ArmIdPoolF[0]);
    int For_Iterator_DefaultOutport1 = -1;
    float rate_DefaultOutport1;
    float rate1_DefaultOutport1;
    bool Equal_DefaultOutport1;
    int Selector_DefaultOutport1;
    int Selector1_DefaultOutport1;
    int Switch2_DefaultOutport1;
    int Switch_DefaultOutport1;
    int Switch3_DefaultOutport1;
    int Assignment_DefaultOutport1[128];
    unsigned char Assignment_init = 0;
    int Switch4_DefaultOutport1;
    int Add_DefaultOutport1[128];
    int Switch1_DefaultOutport1;
    int Assignment1_DefaultOutport1[128];
    unsigned char Assignment1_init = 0;
    int Product_DefaultOutport1[128];
    int Add1_DefaultOutport1[128];
    int Product1_DefaultOutport1[128];
    for (int i = 0; i < 128; i++) {
        CompareTo_Constant_DefaultOutport1 = P1 == 3;
        CompareTo_Constant1_DefaultOutport1 = P2 == 4;
        CompareTo_Constant2_DefaultOutport1 = P3 == 5;
        Constant_DefaultOutport1 = 1;
        Constant1_DefaultOutport1 = 3;
        Constant2_DefaultOutport1 = 4;
        Constant3_DefaultOutport1 = 5;
        For_Iterator_DefaultOutport1++;
        rate_DefaultOutport1 = 3;
        rate1_DefaultOutport1 = 3;
        Equal_DefaultOutport1 = FindP == For_Iterator_DefaultOutport1;
        Selector_DefaultOutport1 = Data_StoreRead_DefaultOutport1[For_Iterator_DefaultOutport1];
        Selector1_DefaultOutport1 = Data_StoreRead2_DefaultOutport1[For_Iterator_DefaultOutport1];
        if (CompareTo_Constant_DefaultOutport1 > 0) {
            Switch2_DefaultOutport1 = Constant1_DefaultOutport1;
        }
        else {
            Switch2_DefaultOutport1 = Constant_DefaultOutport1;
        }
        if (Equal_DefaultOutport1 > 0) {
            Switch_DefaultOutport1 = Constant_DefaultOutport1;
        }
        else {
            Switch_DefaultOutport1 = Selector_DefaultOutport1;
        }
        if (CompareTo_Constant1_DefaultOutport1 > 0) {
            Switch3_DefaultOutport1 = Constant2_DefaultOutport1;
        }
        else {
            Switch3_DefaultOutport1 = Switch2_DefaultOutport1;
        }
        if (Assignment_init == 0) {
            Assignment_init = 1;
            int batchIndex;
            for (batchIndex = 0; batchIndex < 128; batchIndex++) {
                Assignment_DefaultOutport1[batchIndex] = Data_StoreRead_DefaultOutport1[batchIndex];
            }
        }
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Switch_DefaultOutport1;
        if (CompareTo_Constant2_DefaultOutport1 > 0) {
            Switch4_DefaultOutport1 = Constant3_DefaultOutport1;
        }
        else {
            Switch4_DefaultOutport1 = Switch3_DefaultOutport1;
        }
        if (Equal_DefaultOutport1 > 0) {
            Switch1_DefaultOutport1 = Switch4_DefaultOutport1;
        }
        else {
            Switch1_DefaultOutport1 = Selector1_DefaultOutport1;
        }
        if (Assignment1_init == 0) {
            Assignment1_init = 1;
            int batchIndex;
            for (batchIndex = 0; batchIndex < 128; batchIndex++) {
                Assignment1_DefaultOutport1[batchIndex] = Data_StoreRead2_DefaultOutport1[batchIndex];
            }
        }
        Assignment1_DefaultOutport1[For_Iterator_DefaultOutport1] = Switch1_DefaultOutport1;
    }
    int batchIndex;
    for (batchIndex = 0; batchIndex < 128; batchIndex++) {
        Add_DefaultOutport1[batchIndex] = Assignment_DefaultOutport1[batchIndex] + Switch4_DefaultOutport1;
    }
    for (int Data_StoreWrite_i = 0;Data_StoreWrite_i < 128;Data_StoreWrite_i++) {
        PortPool_ArmIdPool[Data_StoreWrite_i] = Assignment_DefaultOutport1[Data_StoreWrite_i];
    }
    int batchIndex1;
    for (batchIndex1 = 0; batchIndex1 < 128; batchIndex1++) {
        Add1_DefaultOutport1[batchIndex1] = Assignment1_DefaultOutport1[batchIndex1] + Switch4_DefaultOutport1;
    }
    int batchIndex2;
    for (batchIndex2 = 0; batchIndex2 < 128; batchIndex2++) {
        Product_DefaultOutport1[batchIndex2] = (int)(Add_DefaultOutport1[batchIndex2] * (int)rate_DefaultOutport1);
    }
    for (int Data_StoreWrite1_i = 0;Data_StoreWrite1_i < 128;Data_StoreWrite1_i++) {
        PortPool1_ArmIdPoolF[Data_StoreWrite1_i] = Assignment1_DefaultOutport1[Data_StoreWrite1_i];
    }
    int batchIndex3;
    for (batchIndex3 = 0; batchIndex3 < 128; batchIndex3++) {
        Product1_DefaultOutport1[batchIndex3] = (int)((int)rate1_DefaultOutport1 * Add1_DefaultOutport1[batchIndex3]);
    }
    for (int Data_StoreWrite2_i = 0;Data_StoreWrite2_i < 128;Data_StoreWrite2_i++) {
        angle_Angle[Data_StoreWrite2_i] = Product_DefaultOutport1[Data_StoreWrite2_i];
    }
    for (int Data_StoreWrite3_i = 0;Data_StoreWrite3_i < 128;Data_StoreWrite3_i++) {
        angle1_AngleF[Data_StoreWrite3_i] = Product1_DefaultOutport1[Data_StoreWrite3_i];
    }
}