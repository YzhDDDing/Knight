#include "define.h"
struct system_2585_state system_2585_instance;
void system_2585_Init(struct system_2585_state *self)
{
    system_2591_Init(&system_2591_instance);
}
void system_2585_Update(struct system_2585_state *self, float Inport)
{
    int Data_StoreRead2_DefaultOutport1;
    bool If_DefaultOutport1;
    bool If_DefaultOutport2;
    Data_StoreRead2_DefaultOutport1 = Data_StoreMemory2_Index;
    If_DefaultOutport1 = (Data_StoreRead2_DefaultOutport1 != -1);
    If_DefaultOutport2 = !(Data_StoreRead2_DefaultOutport1 != -1);
    if (If_DefaultOutport1)
    {
        system_2591_Update(&system_2591_instance, Inport);
    }
}