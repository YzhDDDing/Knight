#ifndef _DEFINE_H_
#define _DEFINE_H_
struct system_root_state;
struct system_root_state {
    
};
extern double Difference_PreviousValue;
extern struct system_root_state system_root_instance;
void system_root_Init(struct system_root_state* self);
void system_root_Update(struct system_root_state* self, double In1[128], double In2[128], double Out1[8]);
#endif
