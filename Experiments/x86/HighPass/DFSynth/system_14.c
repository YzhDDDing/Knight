#include "define.h"
struct system_14_state system_14_instance;
void system_14_Init(struct system_14_state* self) {
}
void system_14_Update(struct system_14_state* self) {
    float Constant_DefaultOutport1 = 0;
    float Constant1_DefaultOutport1 = 0;
    float Constant2_DefaultOutport1 = 0;
    Constant_DefaultOutport1 = 1.95;
    Constant1_DefaultOutport1 = 2.15;
    Constant2_DefaultOutport1 = 3;
    Data_StoreMemory_default_hp1 = Constant_DefaultOutport1;
    Data_StoreMemory1_default_hp2 = Constant1_DefaultOutport1;
    Data_StoreMemory2_default_hp3 = Constant2_DefaultOutport1;
}