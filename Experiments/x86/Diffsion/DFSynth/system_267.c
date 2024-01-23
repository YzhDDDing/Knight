#include "define.h"
struct system_267_state system_267_instance;
void system_267_Init(struct system_267_state* self) {
    system_269_Init(&system_269_instance);
}
void system_267_Update(struct system_267_state* self, float Inport, int Outport[32]) {
    int For_IteratorSubsystem1_Output[32];
    system_269_Update(&system_269_instance, Inport, For_IteratorSubsystem1_Output);
    int batchIndex;
    for (batchIndex = 0; batchIndex < 32; batchIndex++) {
        Outport[batchIndex] = For_IteratorSubsystem1_Output[batchIndex];
    }
}