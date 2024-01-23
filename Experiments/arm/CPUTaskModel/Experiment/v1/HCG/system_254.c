#include "define.h"
struct system_254_state system_254_instance;
void system_254_Init(struct system_254_state* self) {
}
void system_254_Update(struct system_254_state* self, int value, int value2) {
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
    int Switch2_DefaultOutport1 = 0;
    int Switch3_DefaultOutport1 = 0;
    int Assignment1_DefaultOutport1[64] = {0};
    unsigned char Assignment1_init = 0;
    int Switch1_DefaultOutport1 = 0;
    int Add_DefaultOutport1[64] = {0};
    int Product_DefaultOutport1[64] = {0};
    for (int i = 0; i < 16; i++) {
        Constant1_DefaultOutport1 = 1;
        Constant2_DefaultOutport1 = 0;
        Data_StoreRead2_DefaultOutport1 = Data_StoreMemory_find_2;
        Data_StoreRead3_DefaultOutport1 = Data_StoreMemory_find_2;
        Data_StoreRead4_DefaultOutport1 = Data_StoreMemory1_ret_index_2;
        For_Iterator_DefaultOutport1++;
        NOT_DefaultOutport1 = !Data_StoreRead3_DefaultOutport1;
        Selector_DefaultOutport1 = Data_StoreRead_DefaultOutport1[For_Iterator_DefaultOutport1];
        Selector1_DefaultOutport1 = Data_StoreRead1_DefaultOutport1[For_Iterator_DefaultOutport1];
        NOT1_DefaultOutport1 = !Selector_DefaultOutport1;
        Subtract_DefaultOutport1 = Selector1_DefaultOutport1 - value;
        OR_DefaultOutport1 = (Data_StoreRead2_DefaultOutport1 || NOT1_DefaultOutport1 || Subtract_DefaultOutport1);
        AND_DefaultOutport1 = (OR_DefaultOutport1 && NOT_DefaultOutport1);
        if (OR_DefaultOutport1 != 0) {
            Switch2_DefaultOutport1 = Selector1_DefaultOutport1;
        }
        else {
            Switch2_DefaultOutport1 = value2;
        }
        if (OR_DefaultOutport1 != 0) {
            Switch3_DefaultOutport1 = Data_StoreRead4_DefaultOutport1;
        }
        else {
            Switch3_DefaultOutport1 = For_Iterator_DefaultOutport1;
        }
        if (Assignment1_init == 0) {
            Assignment1_init = 1;
            int batchIndex = 0;
            for (batchIndex = 0;batchIndex < 64;batchIndex += 4) {
                int32x4_t Data_StoreRead1_DefaultOutport1_Batch = vld1q_s32(Data_StoreRead1_DefaultOutport1 + batchIndex);
                vst1q_s32(Assignment1_DefaultOutport1 + batchIndex, Data_StoreRead1_DefaultOutport1_Batch);
            }
        }
        Assignment1_DefaultOutport1[For_Iterator_DefaultOutport1] = Switch2_DefaultOutport1;
        Data_StoreMemory1_ret_index_2 = Switch3_DefaultOutport1;
        if (AND_DefaultOutport1 != 0) {
            Switch1_DefaultOutport1 = Constant2_DefaultOutport1;
        }
        else {
            Switch1_DefaultOutport1 = Constant1_DefaultOutport1;
        }
        int32x4_t value2_Batch = vdupq_n_s32(value2);
        int batchIndex = 0;
        for (batchIndex = 0;batchIndex < 64;batchIndex += 4) {
            int32x4_t Assignment1_DefaultOutport1_Batch = vld1q_s32(Assignment1_DefaultOutport1 + batchIndex);
            int32x4_t Add_DefaultOutport1_Batch = {0};
            Add_DefaultOutport1_Batch = vaddq_s32(value2_Batch, Assignment1_DefaultOutport1_Batch);
            int32x4_t Product_DefaultOutport1_Batch = {0};
            Product_DefaultOutport1_Batch = vmulq_s32(Add_DefaultOutport1_Batch, value2_Batch);
            vst1q_s32(Product_DefaultOutport1 + batchIndex, Product_DefaultOutport1_Batch);
        }
        Data_StoreMemory_find_2 = Switch1_DefaultOutport1;
        for (int Data_StoreWrite3_i = 0;Data_StoreWrite3_i < 64;Data_StoreWrite3_i++) {
            Data_StoreMemory_A[Data_StoreWrite3_i] = Assignment1_DefaultOutport1[Data_StoreWrite3_i];
        }
        for (int Data_StoreWrite4_i = 0;Data_StoreWrite4_i < 64;Data_StoreWrite4_i++) {
            Data_StoreMemory3_B[Data_StoreWrite4_i] = Product_DefaultOutport1[Data_StoreWrite4_i];
        }
    }
}