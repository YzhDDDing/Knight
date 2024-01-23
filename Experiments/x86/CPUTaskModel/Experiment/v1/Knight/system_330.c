#include "define.h"
struct system_330_state system_330_instance;
void system_330_Init(struct system_330_state* self) {
}
void system_330_Update(struct system_330_state* self, int* res, int* value_out) {
    int Data_StoreRead_DefaultOutport1;
    int Data_StoreRead1_DefaultOutport1;
    Data_StoreRead_DefaultOutport1 = Data_StoreMemory_find_3;
    Data_StoreRead1_DefaultOutport1 = Data_StoreMemory1_ret_index_3;
    *res = Data_StoreRead_DefaultOutport1;
    *value_out = Data_StoreRead1_DefaultOutport1;
}