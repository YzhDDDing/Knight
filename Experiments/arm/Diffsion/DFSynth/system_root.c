#include "define.h"
struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self) {
    system_236_Init(&system_236_instance);
}
void system_root_Update(struct system_root_state* self, float Inport, int Outport[32]) {
    int Diffsion_Output[32];
    system_236_Update(&system_236_instance, Inport, Diffsion_Output);
    int batchIndex;
    for (batchIndex = 0; batchIndex < 32; batchIndex++) {
        Outport[batchIndex] = Diffsion_Output[batchIndex];
    }
}