#include "define.h"
struct system_34_state system_34_instance;
void system_34_Init(struct system_34_state* self) {
}
void system_34_Update(struct system_34_state* self, int Inport[32], int Output[64]) {
    int Constant_DefaultOutport1;
    int Constant2_DefaultOutport1;
    int Constant3_DefaultOutport1;
    int For_Iterator_DefaultOutport1 = -1;
    int Selector_DefaultOutport1;
    int Assignment_DefaultOutport1[64];
    int Add_DefaultOutport1[64];
    int Product_DefaultOutport1[64];
    int Switch_DefaultOutport1[64];
    unsigned char Assignment_init = 0;
    int batchIndex;
    int batchIndex2;
    int batchIndex3;
    int batchIndex4;
    for (int i = 0; i < 32; i++) {
        Constant_DefaultOutport1 = 3;
        Constant2_DefaultOutport1 = 0;
        Constant3_DefaultOutport1 = 11;
        For_Iterator_DefaultOutport1++;
        Selector_DefaultOutport1 = Inport[For_Iterator_DefaultOutport1];
        if (Assignment_init == 0) {
            Assignment_init = 1;
            for (batchIndex = 0; batchIndex < 64; batchIndex++) {
                Assignment_DefaultOutport1[batchIndex] = signal_state[batchIndex];
            }
        }
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Selector_DefaultOutport1;
        for (batchIndex2 = 0; batchIndex2 < 64; batchIndex2++) {
            Add_DefaultOutport1[batchIndex2] = Assignment_DefaultOutport1[batchIndex2] + Constant_DefaultOutport1;
        }
        for (batchIndex3 = 0; batchIndex3 < 64; batchIndex3++) {
            Product_DefaultOutport1[batchIndex3] = Add_DefaultOutport1[batchIndex3] * Constant3_DefaultOutport1;
        }
        for (int Switch_i = 0;Switch_i < 64;Switch_i++) {
            if (Product_DefaultOutport1[Switch_i] > 32) {
                Switch_DefaultOutport1[Switch_i] = Product_DefaultOutport1[Switch_i];
            }
            else {
                Switch_DefaultOutport1[Switch_i] = Constant2_DefaultOutport1;
            }
        }
    }
    for (batchIndex4 = 0; batchIndex4 < 64; batchIndex4++) {
        Output[batchIndex4] = Switch_DefaultOutport1[batchIndex4];
    }
}