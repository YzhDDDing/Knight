#include "define.h"
struct system_209_state system_209_instance;
void system_209_Init(struct system_209_state* self) {
}
void system_209_Update(struct system_209_state* self, int* res, int* value_out) {
    int Data_StoreRead_DefaultOutport1 = 0;
    int Data_StoreRead1_DefaultOutport1 = 0;
    Data_StoreRead_DefaultOutport1 = Data_StoreMemory_find_1;
    Data_StoreRead1_DefaultOutport1 = Data_StoreMemory1_ret_index_1;
    *res = Data_StoreRead_DefaultOutport1;
    *value_out = Data_StoreRead1_DefaultOutport1;
}