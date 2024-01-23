#include "define.h"
int Data_StoreMemory_find_2;
int Data_StoreMemory1_ret_index_2;
struct system_23_state system_23_instance;
void system_23_Init(struct system_23_state* self) {
    Data_StoreMemory_find_2 = 0;
    Data_StoreMemory1_ret_index_2 = 0;
    system_245_Init(&system_245_instance);
    system_251_Init(&system_251_instance);
    system_279_Init(&system_279_instance);
}
void system_23_Update(struct system_23_state* self, int taskId, int para, int* res, int* out) {
    int FunctionCallSubsystem2_res = 0;
    int FunctionCallSubsystem2_value_out = 0;
    system_245_Update(&system_245_instance);
    system_251_Update(&system_251_instance, taskId, para);
    system_279_Update(&system_279_instance, &FunctionCallSubsystem2_res, &FunctionCallSubsystem2_value_out);
    *res = FunctionCallSubsystem2_res;
    *out = FunctionCallSubsystem2_value_out;
}