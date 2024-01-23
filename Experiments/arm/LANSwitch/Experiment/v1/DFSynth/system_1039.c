#include "define.h"
struct system_1039_state system_1039_instance;
void system_1039_Init(struct system_1039_state* self) {
}
void system_1039_Update(struct system_1039_state* self, int PortId, int* Out1) {
    int * Data_StoreRead_DefaultOutport1 = &(PortPool_PortPool[0]);
    int Data_StoreRead1_DefaultOutport1;
    int * Data_StoreRead2_DefaultOutport1 = &(PortPool1_PortPoolF[0]);
    int For_Iterator_DefaultOutport1 = -1;
    bool CompareTo_Constant1_DefaultOutport1;
    int Selector_DefaultOutport1;
    int Selector1_DefaultOutport1;
    bool CompareTo_Constant_DefaultOutport1;
    bool Equal_DefaultOutport1;
    bool AND1_DefaultOutport1;
    bool AND_DefaultOutport1;
    int Switch_DefaultOutport1;
    for (int i = 0; i < 256; i++) {
        Data_StoreRead1_DefaultOutport1 = Data_StoreMemory1_Found_P_2;
        For_Iterator_DefaultOutport1++;
        CompareTo_Constant1_DefaultOutport1 = Data_StoreRead1_DefaultOutport1 == -1;
        Selector_DefaultOutport1 = Data_StoreRead_DefaultOutport1[For_Iterator_DefaultOutport1];
        Selector1_DefaultOutport1 = Data_StoreRead2_DefaultOutport1[For_Iterator_DefaultOutport1];
        CompareTo_Constant_DefaultOutport1 = Selector1_DefaultOutport1 == 1;
        Equal_DefaultOutport1 = PortId == Selector_DefaultOutport1;
        AND1_DefaultOutport1 = (Equal_DefaultOutport1 && CompareTo_Constant_DefaultOutport1);
        AND_DefaultOutport1 = (AND1_DefaultOutport1 && CompareTo_Constant1_DefaultOutport1);
        if (AND_DefaultOutport1 != 0) {
            Switch_DefaultOutport1 = For_Iterator_DefaultOutport1;
        }
        else {
            Switch_DefaultOutport1 = Data_StoreRead1_DefaultOutport1;
        }
        Data_StoreMemory1_Found_P_2 = Switch_DefaultOutport1;
    }
    *Out1 = Switch_DefaultOutport1;
}