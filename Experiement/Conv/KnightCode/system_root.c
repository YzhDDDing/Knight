#include "define.h"
struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self) {
}
void system_root_Update(struct system_root_state* self, float Inport2[150], float Inport3[10], float Outport[20]) {
    int Conv_i, Conv_j;
    int Conv_jEnd;
    float Conv_acc = 0;
    for (Conv_i = 0; Conv_i < 20; Conv_i++) {
        float Conv_acc = 0;
        for (Conv_j=0; Conv_j <= 9; Conv_j++) {
            Conv_acc += Inport2[Conv_i+Conv_j+10] * Inport3[9-Conv_j];
        }
        Outport[Conv_i] = Conv_acc;
    }
}