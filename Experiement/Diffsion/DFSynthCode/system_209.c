#include "define.h"
struct system_209_state system_209_instance;
void system_209_Init(struct system_209_state* self) {
}
void system_209_Update(struct system_209_state* self, int Output[64]) {
    int Constant1_DefaultOutport = 11;
    int Constant2_DefaultOutport = 5;
    int Constant3_DefaultOutport = 3;
    int Constant4_DefaultOutport = 0;
    int Assignment_DefaultOutport1[64];
    int Selector_DefaultOutport1[64];
    int Selector1_DefaultOutport1[64];
    int Productor1_DefaultOutport1[64];
    int Add_DefaultOutport1[64];
    int Add1_DefaultOutport1[64];
    int Productor2_DefaultOutport1[64];
    int Productor3_DefaultOutport1[64];
    int Switch_DefaultOutport1[64];
    unsigned char Assignment_init = 0;
    int For_Iterator_DefaultOutport1 = -1;
    int batchIndex1;
    int batchIndex2;
    int batchIndex3;
    int batchIndex4;
    for (int i = 0; i < 64; i++) {
        For_Iterator_DefaultOutport1++;
        if (For_Iterator_DefaultOutport1 == 0) {
            for (batchIndex1 = 0; batchIndex1 < 64; batchIndex1++) {
                Assignment_DefaultOutport1[batchIndex1] = A_state[batchIndex1];
            }
        }
        Selector_DefaultOutport1[For_Iterator_DefaultOutport1] = A_state[For_Iterator_DefaultOutport1];
        Selector1_DefaultOutport1[For_Iterator_DefaultOutport1] = B_state[For_Iterator_DefaultOutport1];
        Productor1_DefaultOutport1[For_Iterator_DefaultOutport1] = Selector_DefaultOutport1[For_Iterator_DefaultOutport1] * Constant2_DefaultOutport;
        Add_DefaultOutport1[For_Iterator_DefaultOutport1] = Constant1_DefaultOutport + Selector1_DefaultOutport1[For_Iterator_DefaultOutport1] - Productor1_DefaultOutport1[For_Iterator_DefaultOutport1];
        Productor2_DefaultOutport1[For_Iterator_DefaultOutport1] = Add_DefaultOutport1[For_Iterator_DefaultOutport1] * Selector1_DefaultOutport1[For_Iterator_DefaultOutport1];
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Productor2_DefaultOutport1[For_Iterator_DefaultOutport1];
        for (batchIndex2 = 0; batchIndex2 < 64; batchIndex2++) {
            Add1_DefaultOutport1[batchIndex2] = Assignment_DefaultOutport1[batchIndex2] + Constant3_DefaultOutport;
        }
        for (batchIndex3 = 0; batchIndex3 < 64; batchIndex3++) {
            Productor3_DefaultOutport1[batchIndex3] = Add1_DefaultOutport1[batchIndex3] * Constant3_DefaultOutport;
        }
        for (int Switch_i = 0;Switch_i < 64;Switch_i++) {
            if (Productor3_DefaultOutport1[Switch_i] > 0) {
                Switch_DefaultOutport1[Switch_i] = Productor3_DefaultOutport1[Switch_i];
            } else {
                Switch_DefaultOutport1[Switch_i] = Constant4_DefaultOutport;
            }
        }
    }
    for(batchIndex4 = 0; batchIndex4 < 64; batchIndex4++) {
        Output[batchIndex4] = Switch_DefaultOutport1[batchIndex4];
    }
}