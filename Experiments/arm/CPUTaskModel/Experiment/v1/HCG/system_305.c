#include "define.h"
struct system_305_state system_305_instance;
void system_305_Init(struct system_305_state* self) {
}
void system_305_Update(struct system_305_state* self, int value) {
    int Constant1_DefaultOutport1 = 0;
    int Constant2_DefaultOutport1 = 0;
    char * Data_StoreRead_DefaultOutport1 = &(Data_StoreMemory1_Aflag[0]);
    int * Data_StoreRead1_DefaultOutport1 = &(Data_StoreMemory_A[0]);
    int Data_StoreRead2_DefaultOutport1 = 0;
    int Data_StoreRead3_DefaultOutport1 = 0;
    int Data_StoreRead4_DefaultOutport1 = 0;
    int For_Iterator_DefaultOutport1 = -1;
    bool NOT_DefaultOutport1 = 0;
    char Selector_DefaultOutport1 = 0;
    int Selector1_DefaultOutport1 = 0;
    bool NOT1_DefaultOutport1 = 0;
    int Subtract_DefaultOutport1 = 0;
    bool OR_DefaultOutport1 = 0;
    bool AND_DefaultOutport1 = 0;
    int Switch3_DefaultOutport1 = 0;
    int Switch1_DefaultOutport1 = 0;
    for (int i = 0; i < 16; i++) {
        Constant1_DefaultOutport1 = 1;
        Constant2_DefaultOutport1 = 0;
        Data_StoreRead2_DefaultOutport1 = Data_StoreMemory_find_3;
        Data_StoreRead3_DefaultOutport1 = Data_StoreMemory_find_3;
        Data_StoreRead4_DefaultOutport1 = Data_StoreMemory1_ret_index_3;
        For_Iterator_DefaultOutport1++;
        NOT_DefaultOutport1 = !Data_StoreRead3_DefaultOutport1;
        Selector_DefaultOutport1 = Data_StoreRead_DefaultOutport1[For_Iterator_DefaultOutport1];
        Selector1_DefaultOutport1 = Data_StoreRead1_DefaultOutport1[For_Iterator_DefaultOutport1];
        NOT1_DefaultOutport1 = !Selector_DefaultOutport1;
        Subtract_DefaultOutport1 = Selector1_DefaultOutport1 - value;
        OR_DefaultOutport1 = (Data_StoreRead2_DefaultOutport1 || NOT1_DefaultOutport1 || Subtract_DefaultOutport1);
        AND_DefaultOutport1 = (OR_DefaultOutport1 && NOT_DefaultOutport1);
        if (OR_DefaultOutport1 != 0) {
            Switch3_DefaultOutport1 = Data_StoreRead4_DefaultOutport1;
        }
        else {
            Switch3_DefaultOutport1 = For_Iterator_DefaultOutport1;
        }
        Data_StoreMemory1_ret_index_3 = Switch3_DefaultOutport1;
        if (AND_DefaultOutport1 != 0) {
            Switch1_DefaultOutport1 = Constant2_DefaultOutport1;
        }
        else {
            Switch1_DefaultOutport1 = Constant1_DefaultOutport1;
        }
        Data_StoreMemory_find_3 = Switch1_DefaultOutport1;
    }
}