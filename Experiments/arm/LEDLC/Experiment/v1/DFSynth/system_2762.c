#include "define.h"
struct system_2762_state system_2762_instance;
void system_2762_Init(struct system_2762_state* self) {
}
void system_2762_Update(struct system_2762_state* self) {
    int Constant_DefaultOutport1;
    float Constant1_DefaultOutport1;
    float Constant2_DefaultOutport1;
    int Constant3_DefaultOutport1;
    int Constant4_DefaultOutport1;
    float * Data_StoreRead_DefaultOutport1 = &(Data_StoreMemory_Data[0]);
    int Data_StoreRead1_DefaultOutport1;
    int * Data_StoreRead2_DefaultOutport1 = &(Data_StoreMemory6_Satisfied[0]);
    int For_Iterator_DefaultOutport1 = -1;
    float T_DefaultOutport1;
    int delta_DefaultOutport1;
    int Add_Constant1_DefaultOutport1;
    float Selector_DefaultOutport1;
    int Switch_DefaultOutport1;
    float Selector1_DefaultOutport1;
    float Add_DefaultOutport1;
    float Gain_DefaultOutport1;
    bool RelationalOperator_DefaultOutport1;
    bool RelationalOperator1_DefaultOutport1;
    bool AND_DefaultOutport1;
    int Switch1_DefaultOutport1;
    int Switch2_DefaultOutport1;
    int Assignment_DefaultOutport1[64];
    unsigned char Assignment_init = 0;
    int Add1_DefaultOutport1[64];
    int Product_DefaultOutport1[64];
    int Switch3_DefaultOutport1[64];
    for (int i = 0; i < 64; i++) {
        Constant_DefaultOutport1 = 0;
        Constant1_DefaultOutport1 = 18.4;
        Constant2_DefaultOutport1 = 1.2;
        Constant3_DefaultOutport1 = 1;
        Constant4_DefaultOutport1 = 0;
        Data_StoreRead1_DefaultOutport1 = Data_StoreMemory4_Terminate;
        For_Iterator_DefaultOutport1++;
        T_DefaultOutport1 = 2;
        delta_DefaultOutport1 = 2;
        Add_Constant1_DefaultOutport1 = For_Iterator_DefaultOutport1 + -1;
        Selector_DefaultOutport1 = Data_StoreRead_DefaultOutport1[For_Iterator_DefaultOutport1];
        if (For_Iterator_DefaultOutport1 != 0) {
            Switch_DefaultOutport1 = Add_Constant1_DefaultOutport1;
        }
        else {
            Switch_DefaultOutport1 = For_Iterator_DefaultOutport1;
        }
        Selector1_DefaultOutport1 = Data_StoreRead_DefaultOutport1[Switch_DefaultOutport1];
        Add_DefaultOutport1 = Selector_DefaultOutport1 + Selector1_DefaultOutport1;
        Gain_DefaultOutport1 = 2.34 * Add_DefaultOutport1;
        RelationalOperator_DefaultOutport1 = Gain_DefaultOutport1 <= Constant1_DefaultOutport1;
        RelationalOperator1_DefaultOutport1 = Gain_DefaultOutport1 >= Constant2_DefaultOutport1;
        AND_DefaultOutport1 = (RelationalOperator_DefaultOutport1 && RelationalOperator1_DefaultOutport1);
        if (AND_DefaultOutport1 > 0) {
            Switch1_DefaultOutport1 = Data_StoreRead1_DefaultOutport1;
        }
        else {
            Switch1_DefaultOutport1 = Constant_DefaultOutport1;
        }
        if (AND_DefaultOutport1 > 0) {
            Switch2_DefaultOutport1 = Constant3_DefaultOutport1;
        }
        else {
            Switch2_DefaultOutport1 = Constant4_DefaultOutport1;
        }
        if (Assignment_init == 0) {
            Assignment_init = 1;
            int batchIndex;
            for (batchIndex = 0; batchIndex < 64; batchIndex++) {
                Assignment_DefaultOutport1[batchIndex] = Data_StoreRead2_DefaultOutport1[batchIndex];
            }
        }
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Switch2_DefaultOutport1;
        Data_StoreMemory4_Terminate = Switch1_DefaultOutport1;
        int batchIndex;
        for (batchIndex = 0; batchIndex < 64; batchIndex++) {
            Add1_DefaultOutport1[batchIndex] = (int)(Assignment_DefaultOutport1[batchIndex] + (int)T_DefaultOutport1);
        }
        for (int Data_StoreWrite1_i = 0;Data_StoreWrite1_i < 64;Data_StoreWrite1_i++) {
            Data_StoreMemory6_Satisfied[Data_StoreWrite1_i] = Assignment_DefaultOutport1[Data_StoreWrite1_i];
        }
        int batchIndex1;
        for (batchIndex1 = 0; batchIndex1 < 64; batchIndex1++) {
            Product_DefaultOutport1[batchIndex1] = Add1_DefaultOutport1[batchIndex1] * delta_DefaultOutport1;
        }
        for (int Switch3_i = 0;Switch3_i < 64;Switch3_i++) {
            if (Assignment_DefaultOutport1[Switch3_i] > 144) {
                Switch3_DefaultOutport1[Switch3_i] = Assignment_DefaultOutport1[Switch3_i];
            }
            else {
                Switch3_DefaultOutport1[Switch3_i] = Product_DefaultOutport1[Switch3_i];
            }
        }
        for (int Data_StoreWrite2_i = 0;Data_StoreWrite2_i < 64;Data_StoreWrite2_i++) {
            Data_StoreMemory9_Sat_o[Data_StoreWrite2_i] = Switch3_DefaultOutport1[Data_StoreWrite2_i];
        }
    }
}