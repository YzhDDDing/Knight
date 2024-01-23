#include "define.h"
struct system_1288_state system_1288_instance;
void system_1288_Init(struct system_1288_state* self) {
    system_1142_Init(&system_1142_instance);
    system_1150_Init(&system_1150_instance);
}
void system_1288_Update(struct system_1288_state* self, int FindId, bool Gate, int* Res, int* R) {
    bool If_DefaultOutport1;
    bool If_DefaultOutport2;
    int Merge_DefaultOutport1;
    int Merge1_DefaultOutport1;
    If_DefaultOutport1 = (Gate != 0);
    If_DefaultOutport2 = !(Gate != 0);
    if (If_DefaultOutport1) {
        system_1142_Update(&system_1142_instance, FindId, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    if (If_DefaultOutport2) {
        system_1150_Update(&system_1150_instance, &Merge_DefaultOutport1, &Merge1_DefaultOutport1);
    }
    *Res = Merge_DefaultOutport1;
    *R = Merge1_DefaultOutport1;
}