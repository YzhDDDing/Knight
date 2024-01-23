#include "define.h"
struct system_76_state system_76_instance;
void system_76_Init(struct system_76_state* self) {
}
void system_76_Update(struct system_76_state* self, float signal3[32], float signal_o3[32]) {
    float Data_StoreRead_DefaultOutport1 = 0;
    float * Data_StoreRead1_DefaultOutport1 = &(Data_StoreMemory5_S3[0]);
    int For_Iterator_DefaultOutport1 = -1;
    float T_DefaultOutport1 = 0;
    float dt_DefaultOutport1 = 0;
    float Selector_DefaultOutport1 = 0;
    float Selector1_DefaultOutport1 = 0;
    float Add_DefaultOutport1 = 0;
    float Add2_DefaultOutport1 = 0;
    float Product1_DefaultOutport1 = 0;
    float Assignment_DefaultOutport1[32] = {0};
    unsigned char Assignment_init = 0;
    float Add1_DefaultOutport1[32] = {0};
    float Product_DefaultOutport1[32] = {0};
    float Divide_DefaultOutport1[32] = {0};
    float Switch_DefaultOutport1[32] = {0};
    for (int i = 0; i < 32; i++) {
        Data_StoreRead_DefaultOutport1 = Data_StoreMemory2_default_hp3;
        For_Iterator_DefaultOutport1++;
        T_DefaultOutport1 = 3;
        dt_DefaultOutport1 = 3.1;
        Selector_DefaultOutport1 = signal3[For_Iterator_DefaultOutport1];
        Selector1_DefaultOutport1 = Data_StoreRead1_DefaultOutport1[For_Iterator_DefaultOutport1];
        Add_DefaultOutport1 = Data_StoreRead_DefaultOutport1 + Selector_DefaultOutport1;
        Add2_DefaultOutport1 = Selector1_DefaultOutport1 + Add_DefaultOutport1;
        Product1_DefaultOutport1 = T_DefaultOutport1 * Add2_DefaultOutport1;
        if (Assignment_init == 0) {
            Assignment_init = 1;
            int batchIndex;
            for (batchIndex = 0; batchIndex < 32; batchIndex++) {
                Assignment_DefaultOutport1[batchIndex] = Data_StoreRead1_DefaultOutport1[batchIndex];
            }
        }
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Product1_DefaultOutport1;
    }
    int batchIndex;
    for (batchIndex = 0; batchIndex < 32; batchIndex++) {
        Add1_DefaultOutport1[batchIndex] = dt_DefaultOutport1 + Assignment_DefaultOutport1[batchIndex];
    }
    int batchIndex1;
    for (batchIndex1 = 0; batchIndex1 < 32; batchIndex1++) {
        Product_DefaultOutport1[batchIndex1] = Data_StoreRead_DefaultOutport1 * Add1_DefaultOutport1[batchIndex1];
    }
    int batchIndex2;
    for (batchIndex2 = 0; batchIndex2 < 32; batchIndex2++) {
        Divide_DefaultOutport1[batchIndex2] = Product_DefaultOutport1[batchIndex2] / Data_StoreRead_DefaultOutport1;
    }
    for (int Switch_i = 0;Switch_i < 32;Switch_i++) {
        if (Product_DefaultOutport1[Switch_i] > 17.13) {
            Switch_DefaultOutport1[Switch_i] = Divide_DefaultOutport1[Switch_i];
        }
        else {
            Switch_DefaultOutport1[Switch_i] = Product_DefaultOutport1[Switch_i];
        }
    }
    int batchIndex3;
    for (batchIndex3 = 0; batchIndex3 < 32; batchIndex3++) {
        signal_o3[batchIndex3] = Switch_DefaultOutport1[batchIndex3];
    }
}