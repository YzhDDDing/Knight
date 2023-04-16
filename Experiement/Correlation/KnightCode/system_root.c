#include "define.h"
struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self) {
}
void system_root_Update(struct system_root_state* self, float Inport[10], float Inport1[240], float Outport[20]) {
    int Corre_i, Corre_j;
    int Corre_jEnd;
    float Corre_acc = 0;
    for (Corre_i = 0; Corre_i < 20; Corre_i++) {
        float Corre_acc = 0;
        for (Corre_j=0; Corre_j <= 9; Corre_j++) {
            Corre_acc += Inport1[Corre_i+Corre_j+202] * Inport[Corre_j];
        }
        Outport[20-Corre_i-1] = Corre_acc;
    }
}