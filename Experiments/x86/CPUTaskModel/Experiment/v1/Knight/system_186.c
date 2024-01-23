#include "define.h"
struct system_186_state system_186_instance;
void system_186_Init(struct system_186_state* self) {
}
void system_186_Update(struct system_186_state* self, int value) {
    char Constant_DefaultOutport1;
    int Constant1_DefaultOutport1;
    int Constant2_DefaultOutport1;
    char * Data_StoreRead_DefaultOutport1 = &(Data_StoreMemory1_Aflag[0]);
    int * Data_StoreRead1_DefaultOutport1 = &(Data_StoreMemory_A[0]);
    int Data_StoreRead2_DefaultOutport1;
    int Data_StoreRead3_DefaultOutport1;
    int Data_StoreRead4_DefaultOutport1;
    int For_Iterator_DefaultOutport1 = -1;
    bool NOT_DefaultOutport1;
    char Selector_DefaultOutport1;
    int Selector1_DefaultOutport1;
    bool NOT1_DefaultOutport1;
    int Subtract_DefaultOutport1;
    bool OR1_DefaultOutport1;
    bool OR_DefaultOutport1;
    bool AND_DefaultOutport1;
    char Switch2_DefaultOutport1;
    int Switch3_DefaultOutport1;
    char Assignment1_DefaultOutport1[64];
    unsigned char Assignment1_init = 0;
    int Switch1_DefaultOutport1;
    for (int i = 0; i < 16; i++) {
        Constant_DefaultOutport1 = 0;
        Constant1_DefaultOutport1 = 1;
        Constant2_DefaultOutport1 = 0;
        Data_StoreRead2_DefaultOutport1 = Data_StoreMemory_find_1;
        Data_StoreRead3_DefaultOutport1 = Data_StoreMemory_find_1;
        Data_StoreRead4_DefaultOutport1 = Data_StoreMemory1_ret_index_1;
        For_Iterator_DefaultOutport1++;
        NOT_DefaultOutport1 = !Data_StoreRead3_DefaultOutport1;
        Selector_DefaultOutport1 = Data_StoreRead_DefaultOutport1[For_Iterator_DefaultOutport1];
        Selector1_DefaultOutport1 = Data_StoreRead1_DefaultOutport1[For_Iterator_DefaultOutport1];
        NOT1_DefaultOutport1 = !Selector_DefaultOutport1;
        Subtract_DefaultOutport1 = Selector1_DefaultOutport1 - value;
        OR1_DefaultOutport1 = (Data_StoreRead2_DefaultOutport1 || NOT1_DefaultOutport1);
        OR_DefaultOutport1 = (OR1_DefaultOutport1 || Subtract_DefaultOutport1);
        AND_DefaultOutport1 = (OR_DefaultOutport1 && NOT_DefaultOutport1);
        if (OR_DefaultOutport1 != 0) {
            Switch2_DefaultOutport1 = Selector_DefaultOutport1;
        }
        else {
            Switch2_DefaultOutport1 = Constant_DefaultOutport1;
        }
        if (OR_DefaultOutport1 != 0) {
            Switch3_DefaultOutport1 = Data_StoreRead4_DefaultOutport1;
        }
        else {
            Switch3_DefaultOutport1 = For_Iterator_DefaultOutport1;
        }
        if (Assignment1_init == 0) {
            Assignment1_init = 1;
            int batchIndex;
            for (batchIndex = 0; batchIndex < 64; batchIndex++) {
                Assignment1_DefaultOutport1[batchIndex] = Data_StoreRead_DefaultOutport1[batchIndex];
            }
        }
        Assignment1_DefaultOutport1[For_Iterator_DefaultOutport1] = Switch2_DefaultOutport1;
        Data_StoreMemory1_ret_index_1 = Switch3_DefaultOutport1;
        if (AND_DefaultOutport1 != 0) {
            Switch1_DefaultOutport1 = Constant2_DefaultOutport1;
        }
        else {
            Switch1_DefaultOutport1 = Constant1_DefaultOutport1;
        }
        Data_StoreMemory_find_1 = Switch1_DefaultOutport1;
    }
    for (int Data_StoreWrite1_i = 0;Data_StoreWrite1_i < 64;Data_StoreWrite1_i++) {
        Data_StoreMemory1_Aflag[Data_StoreWrite1_i] = Assignment1_DefaultOutport1[Data_StoreWrite1_i];
    }
}