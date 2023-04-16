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
    int batchIndex;
    for (batchIndex = 0; batchIndex < 64; batchIndex++) {
        Assignment_DefaultOutport1[batchIndex] = signal_state[batchIndex];
    }
    for (int i = 0; i < 32; i++) {
        Constant_DefaultOutport1 = 3;
        Constant2_DefaultOutport1 = 0;
        Constant3_DefaultOutport1 = 11;
        For_Iterator_DefaultOutport1++;
        Selector_DefaultOutport1 = Inport[For_Iterator_DefaultOutport1];
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Selector_DefaultOutport1;
        Add_DefaultOutport1[For_Iterator_DefaultOutport1] = Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] + Constant_DefaultOutport1;
        Product_DefaultOutport1[For_Iterator_DefaultOutport1] = Add_DefaultOutport1[For_Iterator_DefaultOutport1] * Constant3_DefaultOutport1;
        if (Product_DefaultOutport1[For_Iterator_DefaultOutport1] > 32) {
            Output[For_Iterator_DefaultOutport1] = Product_DefaultOutport1[For_Iterator_DefaultOutport1];
        } else {
            Output[For_Iterator_DefaultOutport1] = Constant2_DefaultOutport1;
        }
    }
    for (int i = 32; i < 64; i++) {
        Add_DefaultOutport1[i] = Assignment_DefaultOutport1[i] + Constant_DefaultOutport1;
        Product_DefaultOutport1[i] = Add_DefaultOutport1[i] * Constant3_DefaultOutport1;
        if (Product_DefaultOutport1[i] > 32) {
            Output[i] = Product_DefaultOutport1[i];
        } else {
            Output[i] = Constant2_DefaultOutport1;
        }
    }
}