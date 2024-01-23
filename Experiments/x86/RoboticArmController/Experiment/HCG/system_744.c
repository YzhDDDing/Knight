#include "define.h"
struct system_744_state system_744_instance;
void system_744_Init(struct system_744_state* self) {
}
void system_744_Update(struct system_744_state* self, int ArmId, bool* Out1) {
    bool Constant_DefaultOutport1 = 0;
    int * Data_StoreRead_DefaultOutport1 = &(PortPool_ArmIdPool[0]);
    bool Data_StoreRead1_DefaultOutport1 = 0;
    int * Data_StoreRead2_DefaultOutport1 = &(PortPool1_ArmIdPoolF[0]);
    int For_Iterator_DefaultOutport1 = -1;
    int Selector_DefaultOutport1 = 0;
    int Selector1_DefaultOutport1 = 0;
    bool CompareTo_Constant_DefaultOutport1 = 0;
    bool Equal_DefaultOutport1 = 0;
    bool AND_DefaultOutport1 = 0;
    bool Switch_DefaultOutport1 = 0;
    for (int i = 0; i < 128; i++) {
        Constant_DefaultOutport1 = 1;
        Data_StoreRead1_DefaultOutport1 = Data_StoreMemory_Found;
        For_Iterator_DefaultOutport1++;
        Selector_DefaultOutport1 = Data_StoreRead_DefaultOutport1[For_Iterator_DefaultOutport1];
        Selector1_DefaultOutport1 = Data_StoreRead2_DefaultOutport1[For_Iterator_DefaultOutport1];
        CompareTo_Constant_DefaultOutport1 = Selector1_DefaultOutport1 == 1;
        Equal_DefaultOutport1 = Selector_DefaultOutport1 == ArmId;
        AND_DefaultOutport1 = (Equal_DefaultOutport1 && CompareTo_Constant_DefaultOutport1);
        if (AND_DefaultOutport1 != 0) {
            Switch_DefaultOutport1 = Constant_DefaultOutport1;
        }
        else {
            Switch_DefaultOutport1 = Data_StoreRead1_DefaultOutport1;
        }
        Data_StoreMemory_Found = Switch_DefaultOutport1;
    }
    *Out1 = Switch_DefaultOutport1;
}