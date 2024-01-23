#ifndef _DEFINE_H_
#define _DEFINE_H_
#include <immintrin.h>
#include <smmintrin.h>
#include <emmintrin.h>
#include <string.h>
#define length 32
struct system_247_state;
struct system_247_state {
};
extern struct system_247_state system_247_instance;
struct system_243_state;
struct system_243_state {
};
extern struct system_243_state system_243_instance;
struct system_269_state;
struct system_269_state {
};
extern struct system_269_state system_269_instance;
struct system_267_state;
struct system_267_state {
};
extern struct system_267_state system_267_instance;
struct system_236_state;
struct system_236_state {
};
extern int Data_StoreMemory_Di_s1[32];
extern int Data_StoreMemory1_Di_s2[32];
extern int Data_StoreMemory2_Di_m1[32];
extern int Data_StoreMemory3_Di_m2[32];
extern struct system_236_state system_236_instance;
struct system_root_state;
struct system_root_state {
};
extern struct system_root_state system_root_instance;
void system_247_Init(struct system_247_state* self);
void system_247_Update(struct system_247_state* self, int Output[32]);
void system_243_Init(struct system_243_state* self);
void system_243_Update(struct system_243_state* self, int Outport[32]);
void system_269_Init(struct system_269_state* self);
void system_269_Update(struct system_269_state* self, float Inport, int Output[32]);
void system_267_Init(struct system_267_state* self);
void system_267_Update(struct system_267_state* self, float Inport, int Outport[32]);
void system_236_Init(struct system_236_state* self);
void system_236_Update(struct system_236_state* self, float Inport, int Output[32]);
void system_root_Init(struct system_root_state* self);
void system_root_Update(struct system_root_state* self, float Inport, int Outport[32]);
#endif
