#ifndef _DEFINE_H_
#define _DEFINE_H_
#include <stdio.h>
#include <string.h>
#define bool unsigned char
#define bool unsigned char
#define bool unsigned char
#define bool unsigned char
#define bool unsigned char
#define bool unsigned char
#define bool unsigned char
#define bool unsigned char
#define bool unsigned char
#define bool unsigned char
#define bool unsigned char
#define bool unsigned char
#define bool unsigned char
#define bool unsigned char
#define bool unsigned char
#define bool unsigned char
#define id 3142
#define length 256
struct system_1885_state;
struct system_1885_state {
};
extern struct system_1885_state system_1885_instance;
struct system_1871_state;
struct system_1871_state {
};
extern struct system_1871_state system_1871_instance;
struct system_1832_state;
struct system_1832_state {
};
extern struct system_1832_state system_1832_instance;
struct system_2581_state;
struct system_2581_state {
};
extern struct system_2581_state system_2581_instance;
struct system_2601_state;
struct system_2601_state {
};
extern struct system_2601_state system_2601_instance;
struct system_2599_state;
struct system_2599_state {
};
extern struct system_2599_state system_2599_instance;
struct system_2591_state;
struct system_2591_state {
};
extern struct system_2591_state system_2591_instance;
struct system_2585_state;
struct system_2585_state {
};
extern struct system_2585_state system_2585_instance;
struct system_1897_state;
struct system_1897_state {
};
extern struct system_1897_state system_1897_instance;
struct system_2755_state;
struct system_2755_state {
};
extern struct system_2755_state system_2755_instance;
struct system_2751_state;
struct system_2751_state {
};
extern struct system_2751_state system_2751_instance;
struct system_2762_state;
struct system_2762_state {
};
extern struct system_2762_state system_2762_instance;
struct system_2760_state;
struct system_2760_state {
};
extern struct system_2760_state system_2760_instance;
struct system_2747_state;
struct system_2747_state {
};
extern struct system_2747_state system_2747_instance;
struct system_2687_state;
struct system_2687_state {
};
extern struct system_2687_state system_2687_instance;
struct system_2692_state;
struct system_2692_state {
};
extern struct system_2692_state system_2692_instance;
struct system_2700_state;
struct system_2700_state {
};
extern struct system_2700_state system_2700_instance;
struct system_2705_state;
struct system_2705_state {
};
extern struct system_2705_state system_2705_instance;
struct system_2696_state;
struct system_2696_state {
};
extern struct system_2696_state system_2696_instance;
struct system_2714_state;
struct system_2714_state {
};
extern struct system_2714_state system_2714_instance;
struct system_2719_state;
struct system_2719_state {
};
extern struct system_2719_state system_2719_instance;
struct system_2710_state;
struct system_2710_state {
};
extern struct system_2710_state system_2710_instance;
struct system_2724_state;
struct system_2724_state {
};
extern struct system_2724_state system_2724_instance;
struct system_2732_state;
struct system_2732_state {
};
extern struct system_2732_state system_2732_instance;
struct system_2728_state;
struct system_2728_state {
};
extern struct system_2728_state system_2728_instance;
struct system_2681_state;
struct system_2681_state {
};
extern struct system_2681_state system_2681_instance;
struct system_2676_state;
struct system_2676_state {
};
extern struct system_2676_state system_2676_instance;
struct system_1827_state;
struct system_1827_state {
};
extern float Data_StoreMemory_Data[256];
extern int Data_StoreMemory1_ID;
extern int Data_StoreMemory2_Index;
extern int Data_StoreMemory3_Init;
extern int Data_StoreMemory4_Terminate;
extern int Data_StoreMemory5_Error;
extern int Data_StoreMemory6_Satisfied[256];
extern float Data_StoreMemory7_State;
extern float Data_StoreMemory8_Data_o[256];
extern int Data_StoreMemory9_Sat_o[256];
extern struct system_1827_state system_1827_instance;
struct system_root_state;
struct system_root_state {
};
extern struct system_root_state system_root_instance;
void system_1885_Init(struct system_1885_state* self);
void system_1885_Update(struct system_1885_state* self);
void system_1871_Init(struct system_1871_state* self);
void system_1871_Update(struct system_1871_state* self);
void system_1832_Init(struct system_1832_state* self);
void system_1832_Update(struct system_1832_state* self);
void system_2581_Init(struct system_2581_state* self);
void system_2581_Update(struct system_2581_state* self);
void system_2601_Init(struct system_2601_state* self);
void system_2601_Update(struct system_2601_state* self);
void system_2599_Init(struct system_2599_state* self);
void system_2599_Update(struct system_2599_state* self);
void system_2591_Init(struct system_2591_state* self);
void system_2591_Update(struct system_2591_state* self, float t);
void system_2585_Init(struct system_2585_state* self);
void system_2585_Update(struct system_2585_state* self, float Inport);
void system_1897_Init(struct system_1897_state* self);
void system_1897_Update(struct system_1897_state* self, float t);
void system_2755_Init(struct system_2755_state* self);
void system_2755_Update(struct system_2755_state* self);
void system_2751_Init(struct system_2751_state* self);
void system_2751_Update(struct system_2751_state* self);
void system_2762_Init(struct system_2762_state* self);
void system_2762_Update(struct system_2762_state* self);
void system_2760_Init(struct system_2760_state* self);
void system_2760_Update(struct system_2760_state* self);
void system_2747_Init(struct system_2747_state* self);
void system_2747_Update(struct system_2747_state* self);
void system_2687_Init(struct system_2687_state* self);
void system_2687_Update(struct system_2687_state* self, int* Output);
void system_2692_Init(struct system_2692_state* self);
void system_2692_Update(struct system_2692_state* self, int* Output1);
void system_2700_Init(struct system_2700_state* self);
void system_2700_Update(struct system_2700_state* self, float t, int* Output);
void system_2705_Init(struct system_2705_state* self);
void system_2705_Update(struct system_2705_state* self, float t, int* Out1);
void system_2696_Init(struct system_2696_state* self);
void system_2696_Update(struct system_2696_state* self, float t, int* Output);
void system_2714_Init(struct system_2714_state* self);
void system_2714_Update(struct system_2714_state* self, float t, int* Output);
void system_2719_Init(struct system_2719_state* self);
void system_2719_Update(struct system_2719_state* self, float t, int* Out1);
void system_2710_Init(struct system_2710_state* self);
void system_2710_Update(struct system_2710_state* self, float t, int* Output);
void system_2724_Init(struct system_2724_state* self);
void system_2724_Update(struct system_2724_state* self);
void system_2732_Init(struct system_2732_state* self);
void system_2732_Update(struct system_2732_state* self, float t, int* Output);
void system_2728_Init(struct system_2728_state* self);
void system_2728_Update(struct system_2728_state* self, float t, int* Output);
void system_2681_Init(struct system_2681_state* self);
void system_2681_Update(struct system_2681_state* self, float t, int* Output1);
void system_2676_Init(struct system_2676_state* self);
void system_2676_Update(struct system_2676_state* self, float t, int* Output);
void system_1827_Init(struct system_1827_state* self);
void system_1827_Update(struct system_1827_state* self, float t, int* Output);
void system_root_Init(struct system_root_state* self);
void system_root_Update(struct system_root_state* self, float t, int* Output);
#endif
