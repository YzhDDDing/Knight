#include "define.h"
struct system_279_state system_279_instance;
void system_279_Init(struct system_279_state* self) {
}
void system_279_Update(struct system_279_state* self, int* res, int* value_out) {
    int Data_StoreRead_DefaultOutport1;
    int Data_StoreRead1_DefaultOutport1;
    Data_StoreRead_DefaultOutport1 = Data_StoreMemory_find_2;
    Data_StoreRead1_DefaultOutport1 = Data_StoreMemory1_ret_index_2;
    *res = Data_StoreRead_DefaultOutport1;
    *value_out = Data_StoreRead1_DefaultOutport1;
}