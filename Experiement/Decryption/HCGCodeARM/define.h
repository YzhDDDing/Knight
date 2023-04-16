#ifndef _DEFINE_H_
#define _DEFINE_H_
#include <arm_neon.h>
struct system_root_state;
struct system_root_state {
};
extern struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self);
void system_root_Update(struct system_root_state* self, int In1[256], int In2[512], int In3, int Output[16]);
#endif
