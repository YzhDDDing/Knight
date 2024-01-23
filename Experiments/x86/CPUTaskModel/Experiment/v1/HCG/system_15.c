#include "define.h"
int Data_StoreMemory_find;
int Data_StoreMemory1_ret_index;
struct system_15_state system_15_instance;
void system_15_Init(struct system_15_state* self) {
    Data_StoreMemory_find = 0;
    Data_StoreMemory1_ret_index = 0;
    system_109_Init(&system_109_instance);
    system_113_Init(&system_113_instance);
    system_125_Init(&system_125_instance);
}
void system_15_Update(struct system_15_state* self, int taskId, int* res, int* out) {
    int FunctionCallSubsystem2_res;
    int FunctionCallSubsystem2_value_out;
    system_109_Update(&system_109_instance);
    system_113_Update(&system_113_instance, taskId);
    system_125_Update(&system_125_instance, &FunctionCallSubsystem2_res, &FunctionCallSubsystem2_value_out);
    *res = FunctionCallSubsystem2_res;
    *out = FunctionCallSubsystem2_value_out;
}