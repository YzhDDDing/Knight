#include "define.h"
struct system_2687_state system_2687_instance;
void system_2687_Init(struct system_2687_state* self) {
}
void system_2687_Update(struct system_2687_state* self, int* Output) {
    int Constant_DefaultOutport1 = 0;
    Constant_DefaultOutport1 = 1;
    Data_StoreMemory7_State = Constant_DefaultOutport1;
    *Output = Constant_DefaultOutport1;
}