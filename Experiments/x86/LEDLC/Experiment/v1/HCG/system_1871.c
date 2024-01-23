#include "define.h"
struct system_1871_state system_1871_instance;
void system_1871_Init(struct system_1871_state* self) {
    system_1885_Init(&system_1885_instance);
}
void system_1871_Update(struct system_1871_state* self) {
    int Constant_DefaultOutport1 = 0;
    int Constant1_DefaultOutport1 = 0;
    int Constant2_DefaultOutport1 = 0;
    int Constant3_DefaultOutport1 = 0;
    int Constant4_DefaultOutport1 = 0;
    Constant_DefaultOutport1 = 0;
    Constant1_DefaultOutport1 = 1;
    Constant2_DefaultOutport1 = 0;
    Constant3_DefaultOutport1 = 3142;
    Constant4_DefaultOutport1 = 0;
    system_1885_Update(&system_1885_instance);
    Data_StoreMemory3_Init = Constant1_DefaultOutport1;
    Data_StoreMemory2_Index = Constant_DefaultOutport1;
    Data_StoreMemory4_Terminate = Constant2_DefaultOutport1;
    Data_StoreMemory1_ID = Constant3_DefaultOutport1;
    Data_StoreMemory7_State = Constant4_DefaultOutport1;
}