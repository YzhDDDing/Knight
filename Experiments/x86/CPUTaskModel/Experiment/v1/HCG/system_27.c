#include "define.h"
int Data_StoreMemory_find_3;
int Data_StoreMemory1_ret_index_3;
struct system_27_state system_27_instance;
void system_27_Init(struct system_27_state* self) {
    Data_StoreMemory_find_3 = 0;
    Data_StoreMemory1_ret_index_3 = 0;
    system_295_Init(&system_295_instance);
    system_301_Init(&system_301_instance);
    system_330_Init(&system_330_instance);
}
void system_27_Update(struct system_27_state* self, int taskId, int para, int* res, int* out) {
    int FunctionCallSubsystem2_res;
    int FunctionCallSubsystem2_value_out;
    system_295_Update(&system_295_instance);
    system_301_Update(&system_301_instance, taskId, para);
    system_330_Update(&system_330_instance, &FunctionCallSubsystem2_res, &FunctionCallSubsystem2_value_out);
    *res = FunctionCallSubsystem2_res;
    *out = FunctionCallSubsystem2_value_out;
}