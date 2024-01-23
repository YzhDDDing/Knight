#include "define.h"
struct system_2751_state system_2751_instance;
void system_2751_Init(struct system_2751_state* self) {
    system_2755_Init(&system_2755_instance);
}
void system_2751_Update(struct system_2751_state* self) {
    int Data_StoreRead_DefaultOutport1 = 0;
    bool If_DefaultOutport1 = 0;
    bool If_DefaultOutport2 = 0;
    Data_StoreRead_DefaultOutport1 = Data_StoreMemory4_Terminate;
    If_DefaultOutport1 = (Data_StoreRead_DefaultOutport1 > 0);
    If_DefaultOutport2 = !(Data_StoreRead_DefaultOutport1 > 0);
    if (If_DefaultOutport2) {
        system_2755_Update(&system_2755_instance);
    }
}