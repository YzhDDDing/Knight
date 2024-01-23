#ifndef _DEFINE_H_
#define _DEFINE_H_
#include <string.h>
#define bool unsigned char
#define bool unsigned char
#define bool unsigned char
#define bool unsigned char
#define bool unsigned char
#define bool unsigned char
struct system_58_state;
struct system_58_state {
};
extern struct system_58_state system_58_instance;
struct system_368_state;
struct system_368_state {
};
extern struct system_368_state system_368_instance;
struct system_372_state;
struct system_372_state {
};
extern struct system_372_state system_372_instance;
struct system_362_state;
struct system_362_state {
};
extern struct system_362_state system_362_instance;
struct system_109_state;
struct system_109_state {
};
extern struct system_109_state system_109_instance;
struct system_85_state;
struct system_85_state {
};
extern struct system_85_state system_85_instance;
struct system_113_state;
struct system_113_state {
};
extern struct system_113_state system_113_instance;
struct system_125_state;
struct system_125_state {
};
extern struct system_125_state system_125_instance;
struct system_15_state;
struct system_15_state {
};
extern int Data_StoreMemory_find;
extern int Data_StoreMemory1_ret_index;
extern struct system_15_state system_15_instance;
struct system_179_state;
struct system_179_state {
};
extern struct system_179_state system_179_instance;
struct system_186_state;
struct system_186_state {
};
extern struct system_186_state system_186_instance;
struct system_183_state;
struct system_183_state {
};
extern struct system_183_state system_183_instance;
struct system_209_state;
struct system_209_state {
};
extern struct system_209_state system_209_instance;
struct system_19_state;
struct system_19_state {
};
extern int Data_StoreMemory_find_1;
extern int Data_StoreMemory1_ret_index_1;
extern struct system_19_state system_19_instance;
struct system_245_state;
struct system_245_state {
};
extern struct system_245_state system_245_instance;
struct system_254_state;
struct system_254_state {
};
extern struct system_254_state system_254_instance;
struct system_251_state;
struct system_251_state {
};
extern struct system_251_state system_251_instance;
struct system_279_state;
struct system_279_state {
};
extern struct system_279_state system_279_instance;
struct system_23_state;
struct system_23_state {
};
extern int Data_StoreMemory_find_2;
extern int Data_StoreMemory1_ret_index_2;
extern struct system_23_state system_23_instance;
struct system_295_state;
struct system_295_state {
};
extern struct system_295_state system_295_instance;
struct system_305_state;
struct system_305_state {
};
extern struct system_305_state system_305_instance;
struct system_301_state;
struct system_301_state {
};
extern struct system_301_state system_301_instance;
struct system_330_state;
struct system_330_state {
};
extern struct system_330_state system_330_instance;
struct system_27_state;
struct system_27_state {
};
extern int Data_StoreMemory_find_3;
extern int Data_StoreMemory1_ret_index_3;
extern struct system_27_state system_27_instance;
struct system_39_state;
struct system_39_state {
};
extern struct system_39_state system_39_instance;
struct system_353_state;
struct system_353_state {
};
extern int Data_StoreMemory3_B[64];
extern struct system_353_state system_353_instance;
struct system_root_state;
struct system_root_state {
};
extern int Data_StoreMemory_A[64];
extern char Data_StoreMemory1_Aflag[64];
extern char Data_StoreMemory2_Init;
extern struct system_root_state system_root_instance;
void system_58_Init(struct system_58_state* self);
void system_58_Update(struct system_58_state* self, char In1);
void system_368_Init(struct system_368_state* self);
void system_368_Update(struct system_368_state* self);
void system_372_Init(struct system_372_state* self);
void system_372_Update(struct system_372_state* self);
void system_362_Init(struct system_362_state* self);
void system_362_Update(struct system_362_state* self);
void system_109_Init(struct system_109_state* self);
void system_109_Update(struct system_109_state* self);
void system_85_Init(struct system_85_state* self);
void system_85_Update(struct system_85_state* self, int value);
void system_113_Init(struct system_113_state* self);
void system_113_Update(struct system_113_state* self, int value);
void system_125_Init(struct system_125_state* self);
void system_125_Update(struct system_125_state* self, int* res, int* value_out);
void system_15_Init(struct system_15_state* self);
void system_15_Update(struct system_15_state* self, int taskId, int* res, int* out);
void system_179_Init(struct system_179_state* self);
void system_179_Update(struct system_179_state* self);
void system_186_Init(struct system_186_state* self);
void system_186_Update(struct system_186_state* self, int value);
void system_183_Init(struct system_183_state* self);
void system_183_Update(struct system_183_state* self, int value);
void system_209_Init(struct system_209_state* self);
void system_209_Update(struct system_209_state* self, int* res, int* value_out);
void system_19_Init(struct system_19_state* self);
void system_19_Update(struct system_19_state* self, int taskId, int* res, int* out);
void system_245_Init(struct system_245_state* self);
void system_245_Update(struct system_245_state* self);
void system_254_Init(struct system_254_state* self);
void system_254_Update(struct system_254_state* self, int value, int value2);
void system_251_Init(struct system_251_state* self);
void system_251_Update(struct system_251_state* self, int value, int value2);
void system_279_Init(struct system_279_state* self);
void system_279_Update(struct system_279_state* self, int* res, int* value_out);
void system_23_Init(struct system_23_state* self);
void system_23_Update(struct system_23_state* self, int taskId, int para, int* res, int* out);
void system_295_Init(struct system_295_state* self);
void system_295_Update(struct system_295_state* self);
void system_305_Init(struct system_305_state* self);
void system_305_Update(struct system_305_state* self, int value);
void system_301_Init(struct system_301_state* self);
void system_301_Update(struct system_301_state* self, int value, int para);
void system_330_Init(struct system_330_state* self);
void system_330_Update(struct system_330_state* self, int* res, int* value_out);
void system_27_Init(struct system_27_state* self);
void system_27_Update(struct system_27_state* self, int taskId, int para, int* res, int* out);
void system_39_Init(struct system_39_state* self);
void system_39_Update(struct system_39_state* self, int taskId, int* res, int* out);
void system_353_Init(struct system_353_state* self);
void system_353_Update(struct system_353_state* self, int taskId, int op, int para, int* res, int* out);
void system_root_Init(struct system_root_state* self);
void system_root_Update(struct system_root_state* self, int op, int taskId, int para, int* res, int* out);
#endif
