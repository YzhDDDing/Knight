#include "define.h"
int Data_StoreMemory_find_1;
int Data_StoreMemory1_ret_index_1;
struct system_19_state system_19_instance;
void system_19_Init(struct system_19_state* self) {
    Data_StoreMemory_find_1 = 0;
    Data_StoreMemory1_ret_index_1 = 0;
    system_179_Init(&system_179_instance);
    system_183_Init(&system_183_instance);
    system_209_Init(&system_209_instance);
}
void system_19_Update(struct system_19_state* self, int taskId, int* res, int* out) {
    int FunctionCallSubsystem2_res = 0;
    int FunctionCallSubsystem2_value_out = 0;
    system_179_Update(&system_179_instance);
    system_183_Update(&system_183_instance, taskId);
    system_209_Update(&system_209_instance, &FunctionCallSubsystem2_res, &FunctionCallSubsystem2_value_out);
    *res = FunctionCallSubsystem2_res;
    *out = FunctionCallSubsystem2_value_out;
}