#ifndef _DEFINE_H_
#define _DEFINE_H_
#include <immintrin.h>
struct system_209_state;
struct system_209_state {
};
extern struct system_209_state system_209_instance;
struct system_root_state;
struct system_root_state {
};
extern int A_state[64];
extern int B_state[64];
extern struct system_root_state system_root_instance;
void system_209_Init(struct system_209_state* self);
void system_209_Update(struct system_209_state* self, int Output[64]);
void system_root_Init(struct system_root_state* self);
void system_root_Update(struct system_root_state* self, int Outport[64]);
#endif
