#include "define.h"
struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self) {
}
void system_root_Update(struct system_root_state* self, int In1[256], int In2[512], int In3, int Output[16]) {
    int* Selector1_DefaultOutport1 = In2 + In3; 
    Output[0] = In1[1] + Selector1_DefaultOutport1[1];
    Output[1] = In1[16] + Selector1_DefaultOutport1[16];
    Output[2] = In1[33] + Selector1_DefaultOutport1[33];
    Output[3] = In1[45] + Selector1_DefaultOutport1[45];
    Output[4] = In1[71] + Selector1_DefaultOutport1[71];
    Output[5] = In1[86] + Selector1_DefaultOutport1[86];
    Output[6] = In1[103] + Selector1_DefaultOutport1[103];
    Output[7] = In1[122] + Selector1_DefaultOutport1[122];
    Output[8] = In1[130] + Selector1_DefaultOutport1[130];
    Output[9] = In1[139] + Selector1_DefaultOutport1[139];
    Output[10] = In1[154] + Selector1_DefaultOutport1[154];
    Output[11] = In1[176] + Selector1_DefaultOutport1[176];
    Output[12] = In1[195] + Selector1_DefaultOutport1[195];
    Output[13] = In1[211] + Selector1_DefaultOutport1[211];
    Output[14] = In1[231] + Selector1_DefaultOutport1[231];
    Output[15] = In1[252] + Selector1_DefaultOutport1[252];
}