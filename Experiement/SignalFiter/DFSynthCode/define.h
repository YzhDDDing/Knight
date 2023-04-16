#ifndef _DEFINE_H_
#define _DEFINE_H_
struct system_34_state;
struct system_34_state {
};
extern struct system_34_state system_34_instance;
struct system_root_state;
struct system_root_state {
};
extern int signal_state[64];
extern struct system_root_state system_root_instance;
void system_34_Init(struct system_34_state* self);
void system_34_Update(struct system_34_state* self, int Inport[32], int Output[64]);
void system_root_Init(struct system_root_state* self);
void system_root_Update(struct system_root_state* self, int Inport[32], int Output[64]);
#endif
