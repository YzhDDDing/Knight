#include "define.h"
struct system_978_state system_978_instance;
void system_978_Init(struct system_978_state* self) {
    system_981_Init(&system_981_instance);
}
void system_978_Update(struct system_978_state* self, int SenserId, int* FindId) {
    int FindSenserId_FindId = 0;
    system_981_Update(&system_981_instance, SenserId, &FindSenserId_FindId);
    *FindId = FindSenserId_FindId;
}