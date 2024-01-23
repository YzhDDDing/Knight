#ifndef _DEFINE_H_
#define _DEFINE_H_
#include <immintrin.h>
#include <smmintrin.h>
#include <emmintrin.h>
#include <string.h>
#define length 32
struct system_14_state;
struct system_14_state {
};
extern struct system_14_state system_14_instance;
struct system_45_state;
struct system_45_state {
};
extern struct system_45_state system_45_instance;
struct system_18_state;
struct system_18_state {
};
extern struct system_18_state system_18_instance;
struct system_61_state;
struct system_61_state {
};
extern struct system_61_state system_61_instance;
struct system_22_state;
struct system_22_state {
};
extern struct system_22_state system_22_instance;
struct system_76_state;
struct system_76_state {
};
extern struct system_76_state system_76_instance;
struct system_26_state;
struct system_26_state {
};
extern struct system_26_state system_26_instance;
struct system_5_state;
struct system_5_state {
};
extern float Data_StoreMemory_default_hp1;
extern float Data_StoreMemory1_default_hp2;
extern float Data_StoreMemory2_default_hp3;
extern float Data_StoreMemory3_S1[32];
extern float Data_StoreMemory4_S2[32];
extern float Data_StoreMemory5_S3[32];
extern struct system_5_state system_5_instance;
struct system_root_state;
struct system_root_state {
};
extern struct system_root_state system_root_instance;
void system_14_Init(struct system_14_state* self);
void system_14_Update(struct system_14_state* self);
void system_45_Init(struct system_45_state* self);
void system_45_Update(struct system_45_state* self, float signal1[32], float signal_o1[32]);
void system_18_Init(struct system_18_state* self);
void system_18_Update(struct system_18_state* self, float signal1[32], float signal_o1[32]);
void system_61_Init(struct system_61_state* self);
void system_61_Update(struct system_61_state* self, float signal2[32], float signal_o2[32]);
void system_22_Init(struct system_22_state* self);
void system_22_Update(struct system_22_state* self, float signal2[32], float signal_o2[32]);
void system_76_Init(struct system_76_state* self);
void system_76_Update(struct system_76_state* self, float signal3[32], float signal_o3[32]);
void system_26_Init(struct system_26_state* self);
void system_26_Update(struct system_26_state* self, float signal3[32], float signal_o3[32]);
void system_5_Init(struct system_5_state* self);
void system_5_Update(struct system_5_state* self, float signal1[32], float signal2[32], float signal3[32], float signal_o1[32], float signal_o2[32], float signal_o3[32]);
void system_root_Init(struct system_root_state* self);
void system_root_Update(struct system_root_state* self, float signal1[32], float signal2[32], float signal3[32], float signal_o1[32], float signal_o2[32], float signal_o3[32]);
#endif
