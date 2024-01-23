#include "define.h"
struct system_805_state system_805_instance;
void system_805_Init(struct system_805_state* self) {
}
void system_805_Update(struct system_805_state* self, int* Out1) {
    int Data_StoreRead1_DefaultOutport1 = 0;
    int * Data_StoreRead2_DefaultOutport1 = &(SenserIdUsed_SenserIdUsed[0]);
    int For_Iterator_DefaultOutport1 = -1;
    bool CompareTo_Constant1_DefaultOutport1 = 0;
    int Selector1_DefaultOutport1 = 0;
    bool CompareTo_Constant2_DefaultOutport1 = 0;
    bool AND_DefaultOutport1 = 0;
    int Switch_DefaultOutport1 = 0;
    for (int i = 0; i < 256; i++) {
        Data_StoreRead1_DefaultOutport1 = Data_StoreMemory1_FoundE;
        For_Iterator_DefaultOutport1++;
        CompareTo_Constant1_DefaultOutport1 = Data_StoreRead1_DefaultOutport1 == -1;
        Selector1_DefaultOutport1 = Data_StoreRead2_DefaultOutport1[For_Iterator_DefaultOutport1];
        CompareTo_Constant2_DefaultOutport1 = Selector1_DefaultOutport1 == 0;
        AND_DefaultOutport1 = (CompareTo_Constant2_DefaultOutport1 && CompareTo_Constant1_DefaultOutport1);
        if (AND_DefaultOutport1 != 0) {
            Switch_DefaultOutport1 = For_Iterator_DefaultOutport1;
        }
        else {
            Switch_DefaultOutport1 = Data_StoreRead1_DefaultOutport1;
        }
        Data_StoreMemory1_FoundE = Switch_DefaultOutport1;
    }
    *Out1 = Switch_DefaultOutport1;
}