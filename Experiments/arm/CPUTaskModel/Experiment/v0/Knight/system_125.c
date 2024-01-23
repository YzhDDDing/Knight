#include "define.h"
struct system_125_state system_125_instance;
void system_125_Init(struct system_125_state* self) {
}
void system_125_Update(struct system_125_state* self, int* res, int* value_out) {
    int Constant_DefaultOutport1;
    int Constant1_DefaultOutport1;
    int Data_StoreRead1_DefaultOutport1;
    int Data_StoreRead2_DefaultOutport1;
    int Switch_DefaultOutport1;
    Constant_DefaultOutport1 = 1;
    Constant1_DefaultOutport1 = -1;
    Data_StoreRead1_DefaultOutport1 = Data_StoreMemory1_ret_index;
    Data_StoreRead2_DefaultOutport1 = Data_StoreMemory_find;
    if (Data_StoreRead2_DefaultOutport1 != 0) {
        Switch_DefaultOutport1 = Constant_DefaultOutport1;
    }
    else {
        Switch_DefaultOutport1 = Constant1_DefaultOutport1;
    }
    *res = Switch_DefaultOutport1;
    *value_out = Data_StoreRead1_DefaultOutport1;
}