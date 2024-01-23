#include "define.h"
struct system_1832_state system_1832_instance;
void system_1832_Init(struct system_1832_state* self) {
    system_1871_Init(&system_1871_instance);
}
void system_1832_Update(struct system_1832_state* self) {
    int Data_StoreRead1_DefaultOutport1 = 0;
    bool If1_DefaultOutport1 = 0;
    bool If1_DefaultOutport2 = 0;
    Data_StoreRead1_DefaultOutport1 = Data_StoreMemory3_Init;
    If1_DefaultOutport1 = (Data_StoreRead1_DefaultOutport1 == 0);
    If1_DefaultOutport2 = !(Data_StoreRead1_DefaultOutport1 == 0);
    if (If1_DefaultOutport1) {
        system_1871_Update(&system_1871_instance);
    }
}