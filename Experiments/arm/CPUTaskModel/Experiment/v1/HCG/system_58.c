#include "define.h"
struct system_58_state system_58_instance;
void system_58_Init(struct system_58_state* self) {
}
void system_58_Update(struct system_58_state* self, char In1) {
    char * Data_StoreRead_DefaultOutport1 = &(Data_StoreMemory1_Aflag[0]);
    int For_Iterator_DefaultOutport1 = -1;
    char Assignment_DefaultOutport1[64] = {0};
    unsigned char Assignment_init = 0;
    for (int i = 0; i < 16; i++) {
        For_Iterator_DefaultOutport1++;
        if (Assignment_init == 0) {
            Assignment_init = 1;
            int batchIndex;
            for (batchIndex = 0; batchIndex < 64; batchIndex++) {
                Assignment_DefaultOutport1[batchIndex] = Data_StoreRead_DefaultOutport1[batchIndex];
            }
        }
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = In1;
        for (int Data_StoreWrite_i = 0;Data_StoreWrite_i < 64;Data_StoreWrite_i++) {
            Data_StoreMemory1_Aflag[Data_StoreWrite_i] = Assignment_DefaultOutport1[Data_StoreWrite_i];
        }
    }
}