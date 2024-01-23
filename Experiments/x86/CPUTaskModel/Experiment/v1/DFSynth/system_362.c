#include "define.h"
struct system_362_state system_362_instance;
void system_362_Init(struct system_362_state* self) {
    system_368_Init(&system_368_instance);
    system_372_Init(&system_372_instance);
}
void system_362_Update(struct system_362_state* self) {
    char Data_StoreRead_DefaultOutport1;
    bool If_DefaultOutport1;
    bool If_DefaultOutport2;
    Data_StoreRead_DefaultOutport1 = Data_StoreMemory2_Init;
    If_DefaultOutport1 = (Data_StoreRead_DefaultOutport1 > 0);
    If_DefaultOutport2 = !(Data_StoreRead_DefaultOutport1 > 0);
    if (If_DefaultOutport2) {
        system_368_Update(&system_368_instance);
    }
    if (If_DefaultOutport1) {
        system_372_Update(&system_372_instance);
    }
}