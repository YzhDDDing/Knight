#ifndef _DEFINE_H_
#define _DEFINE_H_
#include <string.h>
#define length 32
struct system_14_state;
struct system_14_state
{
};
extern struct system_14_state system_14_instance;
struct system_45_state;
struct system_45_state
{
};
extern struct system_45_state system_45_instance;
struct system_18_state;
struct system_18_state
{
};
extern struct system_18_state system_18_instance;
struct system_61_state;
struct system_61_state
{
};
extern struct system_61_state system_61_instance;
struct system_22_state;
struct system_22_state
{
};
extern struct system_22_state system_22_instance;
struct system_76_state;
struct system_76_state
{
};
extern struct system_76_state system_76_instance;
struct system_26_state;
struct system_26_state
{
};
extern struct system_26_state system_26_instance;
struct system_123_state;
struct system_123_state
{
};
extern struct system_123_state system_123_instance;
struct system_141_state;
struct system_141_state
{
};
extern struct system_141_state system_141_instance;
struct system_139_state;
struct system_139_state
{
};
extern struct system_139_state system_139_instance;
struct system_157_state;
struct system_157_state
{
};
extern struct system_157_state system_157_instance;
struct system_155_state;
struct system_155_state
{
};
extern struct system_155_state system_155_instance;
struct system_173_state;
struct system_173_state
{
};
extern struct system_173_state system_173_instance;
struct system_171_state;
struct system_171_state
{
};
extern struct system_171_state system_171_instance;
struct system_134_state;
struct system_134_state
{
};
extern struct system_134_state system_134_instance;
struct system_5_state;
struct system_5_state
{
};
extern double Data_StoreMemory_default_hp1;
extern double Data_StoreMemory1_default_hp2;
extern double Data_StoreMemory2_default_hp3;
extern double Data_StoreMemory3_default_lp1;
extern double Data_StoreMemory4_default_lp2;
extern double Data_StoreMemory5_default_lp3;
extern double Data_StoreMemory6_S1[32];
extern double Data_StoreMemory7_S2[32];
extern double Data_StoreMemory8_S3[32];
extern struct system_5_state system_5_instance;
struct system_root_state;
struct system_root_state
{
};
extern struct system_root_state system_root_instance;
void system_14_Init(struct system_14_state *self);
void system_14_Update(struct system_14_state *self);
void system_45_Init(struct system_45_state *self);
void system_45_Update(struct system_45_state *self, double signal1[32], double signal_h1[32]);
void system_18_Init(struct system_18_state *self);
void system_18_Update(struct system_18_state *self, double signal1[32], double signal_h1[32]);
void system_61_Init(struct system_61_state *self);
void system_61_Update(struct system_61_state *self, double signal2[32], double signal_h2[32]);
void system_22_Init(struct system_22_state *self);
void system_22_Update(struct system_22_state *self, double signal2[32], double signal_h2[32]);
void system_76_Init(struct system_76_state *self);
void system_76_Update(struct system_76_state *self, double signal3[32], double signal_o3[32]);
void system_26_Init(struct system_26_state *self);
void system_26_Update(struct system_26_state *self, double signal3[32], double signal_o3[32]);
void system_123_Init(struct system_123_state *self);
void system_123_Update(struct system_123_state *self, double signal1[32], double signal2[32], double signal3[32],
                       double signal_h1[32], double signal_h2[32], double signal_h3[32]);
void system_141_Init(struct system_141_state *self);
void system_141_Update(struct system_141_state *self, double signal1[32], double signal_l1[32]);
void system_139_Init(struct system_139_state *self);
void system_139_Update(struct system_139_state *self, double signal1[32], double signal_l1[32]);
void system_157_Init(struct system_157_state *self);
void system_157_Update(struct system_157_state *self, double signal2[32], double signal_l2[32]);
void system_155_Init(struct system_155_state *self);
void system_155_Update(struct system_155_state *self, double signal2[32], double signal_l2[32]);
void system_173_Init(struct system_173_state *self);
void system_173_Update(struct system_173_state *self, double signal3[32], double signal_o3[32]);
void system_171_Init(struct system_171_state *self);
void system_171_Update(struct system_171_state *self, double signal3[32], double signal_l3[32]);
void system_134_Init(struct system_134_state *self);
void system_134_Update(struct system_134_state *self, double signal1[32], double signal2[32], double signal3[32],
                       double signal_l1[32], double signal_l2[32], double signal_l3[32]);
void system_5_Init(struct system_5_state *self);
void system_5_Update(struct system_5_state *self, double signal1[32], double signal2[32], double signal3[32],
                     double signal_h1[32], double signal_h2[32], double signal_h3[32], double signal_l1[32],
                     double signal_l2[32], double signal_l3[32]);
void system_root_Init(struct system_root_state *self);
void system_root_Update(struct system_root_state *self, double signal1[32], double signal2[32], double signal3[32],
                        double signal_h1[32], double signal_h2[32], double signal_h3[32], double signal_l1[32],
                        double signal_l2[32], double signal_l3[32]);
#endif
