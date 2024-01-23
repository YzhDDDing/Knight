#include "define.h"
struct system_14_state system_14_instance;
void system_14_Init(struct system_14_state* self) {
}
void system_14_Update(struct system_14_state* self) {
    float Constant_DefaultOutport1 = 0;
    float Constant1_DefaultOutport1 = 0;
    float Constant2_DefaultOutport1 = 0;
    float Constant3_DefaultOutport1 = 0;
    float Constant4_DefaultOutport1 = 0;
    float Constant5_DefaultOutport1 = 0;
    Constant_DefaultOutport1 = 1.95;
    Constant1_DefaultOutport1 = 2.15;
    Constant2_DefaultOutport1 = 3;
    Constant3_DefaultOutport1 = 1.55;
    Constant4_DefaultOutport1 = 3.13;
    Constant5_DefaultOutport1 = 2.78;
    Data_StoreMemory_default_hp1 = Constant_DefaultOutport1;
    Data_StoreMemory1_default_hp2 = Constant1_DefaultOutport1;
    Data_StoreMemory2_default_hp3 = Constant2_DefaultOutport1;
    Data_StoreMemory3_default_lp1 = Constant3_DefaultOutport1;
    Data_StoreMemory4_default_lp2 = Constant4_DefaultOutport1;
    Data_StoreMemory5_default_lp3 = Constant5_DefaultOutport1;
}