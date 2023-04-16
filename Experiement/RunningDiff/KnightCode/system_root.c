#include "define.h"
#include <string.h>
#include <stdio.h>
double Difference_PreviousValue;
struct system_root_state system_root_instance;

void system_root_Init(struct system_root_state* self) {
}
void system_root_Update(struct system_root_state* self, double In1[128], double In2[128], double Out1[8]) {
    Out1[0] = In1[1] - In1[0] + In2[1];
    Out1[1] = In1[16] - In1[15] + In2[16];
    Out1[2] = In1[33] - In1[32] + In2[33];
    Out1[3] = In1[45] - In1[44] + In2[45];
    Out1[4] = In1[71] - In1[70] + In2[71];
    Out1[5] = In1[86] - In1[85] + In2[86];
    Out1[6] = In1[103] - In1[102] + In2[103];
    Out1[7] = In1[122] - In1[121] + In2[122];
}