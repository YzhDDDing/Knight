#ifndef _DEFINE_H_
#define _DEFINE_H_
struct system_root_state;
struct system_root_state {
};
extern struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self);
void system_root_Update(struct system_root_state* self, float Inport2[150], float Inport3[10], float Outport[20]);
#endif
