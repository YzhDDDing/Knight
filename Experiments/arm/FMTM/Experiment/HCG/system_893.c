#include "define.h"
struct system_893_state system_893_instance;
void system_893_Init(struct system_893_state* self) {
}
void system_893_Update(struct system_893_state* self, int SenserId, int* Out1) {
    int * Data_StoreRead_DefaultOutport1 = &(SenserIdData_SenserIdData[0]);
    int Data_StoreRead1_DefaultOutport1 = 0;
    int * Data_StoreRead2_DefaultOutport1 = &(SenserIdUsed_SenserIdUsed[0]);
    int For_Iterator_DefaultOutport1 = -1;
    bool CompareTo_Constant1_DefaultOutport1 = 0;
    int Selector_DefaultOutport1 = 0;
    int Selector1_DefaultOutport1 = 0;
    bool CompareTo_Constant_DefaultOutport1 = 0;
    bool Equal_DefaultOutport1 = 0;
    bool AND1_DefaultOutport1 = 0;
    bool AND_DefaultOutport1 = 0;
    int Switch_DefaultOutport1 = 0;
    for (int i = 0; i < 256; i++) {
        Data_StoreRead1_DefaultOutport1 = Data_StoreMemory1_FoundId;
        For_Iterator_DefaultOutport1++;
        CompareTo_Constant1_DefaultOutport1 = Data_StoreRead1_DefaultOutport1 == -1;
        Selector_DefaultOutport1 = Data_StoreRead_DefaultOutport1[For_Iterator_DefaultOutport1];
        Selector1_DefaultOutport1 = Data_StoreRead2_DefaultOutport1[For_Iterator_DefaultOutport1];
        CompareTo_Constant_DefaultOutport1 = Selector1_DefaultOutport1 == 1;
        Equal_DefaultOutport1 = SenserId == Selector_DefaultOutport1;
        AND1_DefaultOutport1 = (Equal_DefaultOutport1 && CompareTo_Constant_DefaultOutport1);
        AND_DefaultOutport1 = (AND1_DefaultOutport1 && CompareTo_Constant1_DefaultOutport1);
        if (AND_DefaultOutport1 != 0) {
            Switch_DefaultOutport1 = For_Iterator_DefaultOutport1;
        }
        else {
            Switch_DefaultOutport1 = Data_StoreRead1_DefaultOutport1;
        }
        Data_StoreMemory1_FoundId = Switch_DefaultOutport1;
    }
    *Out1 = Switch_DefaultOutport1;
}