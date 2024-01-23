#include "define.h"
struct system_269_state system_269_instance;
void system_269_Init(struct system_269_state* self) {
}
void system_269_Update(struct system_269_state* self, float Inport, int Output[32]) {
    int Constant_DefaultOutport1;
    int Constant1_DefaultOutport1;
    int Constant2_DefaultOutport1;
    int Constant3_DefaultOutport1;
    int * Data_StoreRead_DefaultOutport1 = &(Data_StoreMemory2_Di_m1[0]);
    int * Data_StoreRead1_DefaultOutport1 = &(Data_StoreMemory3_Di_m2[0]);
    int For_Iterator_DefaultOutport1 = -1;
    int Selector_DefaultOutport1;
    int Selector1_DefaultOutport1;
    int Product_DefaultOutport1;
    int Add1_DefaultOutport1;
    int Add1_BatchTempVar;
    int Product1_DefaultOutport1;
    int Assignment_DefaultOutport1[32];
    unsigned char Assignment_init = 0;
    int Add_DefaultOutport1[32];
    int Add_BatchTempVar[32];
    int Product2_DefaultOutport1[32];
    int Switch_DefaultOutport1[32];
    for (int i = 0; i < 32; i++) {
        Constant_DefaultOutport1 = 3;
        Constant1_DefaultOutport1 = 11;
        Constant2_DefaultOutport1 = 5;
        Constant3_DefaultOutport1 = 0;
        For_Iterator_DefaultOutport1++;
        Selector_DefaultOutport1 = Data_StoreRead_DefaultOutport1[For_Iterator_DefaultOutport1];
        Selector1_DefaultOutport1 = Data_StoreRead1_DefaultOutport1[For_Iterator_DefaultOutport1];
        Product_DefaultOutport1 = Selector_DefaultOutport1 * Constant2_DefaultOutport1;
        Add1_DefaultOutport1 = Selector1_DefaultOutport1 + Constant1_DefaultOutport1 - Product_DefaultOutport1;
        Product1_DefaultOutport1 = Add1_DefaultOutport1 * Selector1_DefaultOutport1;
        if (Assignment_init == 0) {
            Assignment_init = 1;
            int batchIndex;
            for (batchIndex = 0; batchIndex < 32; batchIndex++) {
                Assignment_DefaultOutport1[batchIndex] = Data_StoreRead_DefaultOutport1[batchIndex];
            }
        }
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Product1_DefaultOutport1;
        int batchIndex;
        for (batchIndex = 0; batchIndex < 32; batchIndex++) {
            Add_BatchTempVar[batchIndex] = (int)((int)Inport + Assignment_DefaultOutport1[batchIndex]);
        }
        int batchIndex1;
        for (batchIndex1 = 0; batchIndex1 < 32; batchIndex1++) {
            Add_DefaultOutport1[batchIndex1] = Add_BatchTempVar[batchIndex1] + Constant_DefaultOutport1;
        }
        int batchIndex2;
        for (batchIndex2 = 0; batchIndex2 < 32; batchIndex2++) {
            Product2_DefaultOutport1[batchIndex2] = Add_DefaultOutport1[batchIndex2] * Constant_DefaultOutport1;
        }
        for (int Switch_i = 0;Switch_i < 32;Switch_i++) {
            if (Product2_DefaultOutport1[Switch_i] > 0) {
                Switch_DefaultOutport1[Switch_i] = Product2_DefaultOutport1[Switch_i];
            }
            else {
                Switch_DefaultOutport1[Switch_i] = Constant3_DefaultOutport1;
            }
        }
    }
    int batchIndex;
    for (batchIndex = 0; batchIndex < 32; batchIndex++) {
        Output[batchIndex] = Switch_DefaultOutport1[batchIndex];
    }
}