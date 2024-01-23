#include "define.h"
int Data_StoreMemory_A[16];
char Data_StoreMemory1_Aflag[16];
char Data_StoreMemory2_Init;
struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self) {
    memset(Data_StoreMemory_A, 0, sizeof(Data_StoreMemory_A));
    memset(Data_StoreMemory1_Aflag, 0, sizeof(Data_StoreMemory1_Aflag));
    Data_StoreMemory2_Init = 0;
    system_362_Init(&system_362_instance);
    system_353_Init(&system_353_instance);
}
void system_root_Update(struct system_root_state* self, int op, int taskId, int para, int* res, int* out) {
    int Subsystem_res;
    int Subsystem_out;
    system_362_Update(&system_362_instance);
    system_353_Update(&system_353_instance, taskId, op, para, &Subsystem_res, &Subsystem_out);
    *res = Subsystem_res;
    *out = Subsystem_out;
}