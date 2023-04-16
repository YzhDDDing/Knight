#ifndef _DEFINE_H_
#define _DEFINE_H_
#include "corre_f32_normal.h"
struct system_root_state;
struct system_root_state {
};
extern float Corre_Buf[258];
extern struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self);
void system_root_Update(struct system_root_state* self, float Inport[10], float Inport1[240], float Outport[20]);
#endif
