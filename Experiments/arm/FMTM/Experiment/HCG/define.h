#ifndef _DEFINE_H_
#define _DEFINE_H_
#include <arm_neon.h>
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
#define bool unsigned char
#define bool unsigned char
#define bool unsigned char
#define bool unsigned char
#define bool unsigned char
#define bool unsigned char
#define bool unsigned char
#define POOL_SIZE 256
struct system_726_state;
struct system_726_state {
};
extern struct system_726_state system_726_instance;
struct system_770_state;
struct system_770_state {
};
extern struct system_770_state system_770_instance;
struct system_805_state;
struct system_805_state {
};
extern struct system_805_state system_805_instance;
struct system_744_state;
struct system_744_state {
};
extern struct system_744_state system_744_instance;
struct system_772_state;
struct system_772_state {
};
extern struct system_772_state system_772_instance;
struct system_833_state;
struct system_833_state {
};
extern struct system_833_state system_833_instance;
struct system_797_state;
struct system_797_state {
};
extern struct system_797_state system_797_instance;
struct system_792_state;
struct system_792_state {
};
extern struct system_792_state system_792_instance;
struct system_1273_state;
struct system_1273_state {
};
extern struct system_1273_state system_1273_instance;
struct system_730_state;
struct system_730_state {
};
extern bool Data_StoreMemory_Found;
extern int Data_StoreMemory1_FoundE;
extern struct system_730_state system_730_instance;
struct system_634_state;
struct system_634_state {
};
extern struct system_634_state system_634_instance;
struct system_851_state;
struct system_851_state {
};
extern struct system_851_state system_851_instance;
struct system_917_state;
struct system_917_state {
};
extern struct system_917_state system_917_instance;
struct system_893_state;
struct system_893_state {
};
extern struct system_893_state system_893_instance;
struct system_886_state;
struct system_886_state {
};
extern struct system_886_state system_886_instance;
struct system_869_state;
struct system_869_state {
};
extern struct system_869_state system_869_instance;
struct system_864_state;
struct system_864_state {
};
extern struct system_864_state system_864_instance;
struct system_1296_state;
struct system_1296_state {
};
extern struct system_1296_state system_1296_instance;
struct system_890_state;
struct system_890_state {
};
extern struct system_890_state system_890_instance;
struct system_857_state;
struct system_857_state {
};
extern int Data_StoreMemory1_FoundId;
extern struct system_857_state system_857_instance;
struct system_698_state;
struct system_698_state {
};
extern struct system_698_state system_698_instance;
struct system_1017_state;
struct system_1017_state {
};
extern struct system_1017_state system_1017_instance;
struct system_1052_state;
struct system_1052_state {
};
extern struct system_1052_state system_1052_instance;
struct system_1039_state;
struct system_1039_state {
};
extern struct system_1039_state system_1039_instance;
struct system_1106_state;
struct system_1106_state {
};
extern struct system_1106_state system_1106_instance;
struct system_1036_state;
struct system_1036_state {
};
extern struct system_1036_state system_1036_instance;
struct system_1032_state;
struct system_1032_state {
};
extern struct system_1032_state system_1032_instance;
struct system_1059_state;
struct system_1059_state {
};
extern struct system_1059_state system_1059_instance;
struct system_1282_state;
struct system_1282_state {
};
extern struct system_1282_state system_1282_instance;
struct system_1023_state;
struct system_1023_state {
};
extern int Data_StoreMemory1_FoundId_1;
extern int Data_StoreMemory2_FoundIdT;
extern struct system_1023_state system_1023_instance;
struct system_670_state;
struct system_670_state {
};
extern struct system_670_state system_670_instance;
struct system_942_state;
struct system_942_state {
};
extern struct system_942_state system_942_instance;
struct system_994_state;
struct system_994_state {
};
extern struct system_994_state system_994_instance;
struct system_981_state;
struct system_981_state {
};
extern struct system_981_state system_981_instance;
struct system_978_state;
struct system_978_state {
};
extern struct system_978_state system_978_instance;
struct system_1142_state;
struct system_1142_state {
};
extern struct system_1142_state system_1142_instance;
struct system_1150_state;
struct system_1150_state {
};
extern struct system_1150_state system_1150_instance;
struct system_1288_state;
struct system_1288_state {
};
extern struct system_1288_state system_1288_instance;
struct system_948_state;
struct system_948_state {
};
extern int Data_StoreMemory1_FoundId_2;
extern struct system_948_state system_948_instance;
struct system_684_state;
struct system_684_state {
};
extern struct system_684_state system_684_instance;
struct system_1253_state;
struct system_1253_state {
};
extern int SenserIdData_SenserIdData[256];
extern int SenserIdData1_SenserIdConfound[256];
extern int SenserIdUsed_SenserIdUsed[256];
extern int SenserIdUsed1_SenserUsedLog[256];
extern struct system_1253_state system_1253_instance;
struct system_root_state;
struct system_root_state {
};
extern struct system_root_state system_root_instance;
void system_726_Init(struct system_726_state* self);
void system_726_Update(struct system_726_state* self, int* Res, int* R);
void system_770_Init(struct system_770_state* self);
void system_770_Update(struct system_770_state* self);
void system_805_Init(struct system_805_state* self);
void system_805_Update(struct system_805_state* self, int* Out1);
void system_744_Init(struct system_744_state* self);
void system_744_Update(struct system_744_state* self, int SenserId, bool* Out1);
void system_772_Init(struct system_772_state* self);
void system_772_Update(struct system_772_state* self, int SenserId, bool* FindS, int* FindE);
void system_833_Init(struct system_833_state* self);
void system_833_Update(struct system_833_state* self, int PortId, int FindE);
void system_797_Init(struct system_797_state* self);
void system_797_Update(struct system_797_state* self, int PortId, int FindE, int* Res, int* R);
void system_792_Init(struct system_792_state* self);
void system_792_Update(struct system_792_state* self, int* Result);
void system_1273_Init(struct system_1273_state* self);
void system_1273_Update(struct system_1273_state* self, bool Gate, int PortId, int FindE, int* Res, int* R);
void system_730_Init(struct system_730_state* self);
void system_730_Update(struct system_730_state* self, int SenserId, int TValue, int* Res, int* R);
void system_634_Init(struct system_634_state* self);
void system_634_Update(struct system_634_state* self, int SenserId, int TValue, int* Res, int* R);
void system_851_Init(struct system_851_state* self);
void system_851_Update(struct system_851_state* self, int* Res, int* R);
void system_917_Init(struct system_917_state* self);
void system_917_Update(struct system_917_state* self);
void system_893_Init(struct system_893_state* self);
void system_893_Update(struct system_893_state* self, int SenserId, int* Out1);
void system_886_Init(struct system_886_state* self);
void system_886_Update(struct system_886_state* self, int* Result, int* R);
void system_869_Init(struct system_869_state* self);
void system_869_Update(struct system_869_state* self, int FindId);
void system_864_Init(struct system_864_state* self);
void system_864_Update(struct system_864_state* self, int SenserId, int* Res, int* R);
void system_1296_Init(struct system_1296_state* self);
void system_1296_Update(struct system_1296_state* self, int SenserId, bool Gate, int* Out1, int* Out2);
void system_890_Init(struct system_890_state* self);
void system_890_Update(struct system_890_state* self, int SenserId, int* Res, int* R);
void system_857_Init(struct system_857_state* self);
void system_857_Update(struct system_857_state* self, int SenserId, int TValue, int* Res, int* R);
void system_698_Init(struct system_698_state* self);
void system_698_Update(struct system_698_state* self, int SenserId, int TValue, int* Res, int* R);
void system_1017_Init(struct system_1017_state* self);
void system_1017_Update(struct system_1017_state* self, int* Res, int* R);
void system_1052_Init(struct system_1052_state* self);
void system_1052_Update(struct system_1052_state* self);
void system_1039_Init(struct system_1039_state* self);
void system_1039_Update(struct system_1039_state* self, int SenserId, int* Out1);
void system_1106_Init(struct system_1106_state* self);
void system_1106_Update(struct system_1106_state* self, int TValue, int* FindPT);
void system_1036_Init(struct system_1036_state* self);
void system_1036_Update(struct system_1036_state* self, int SenserId, int TValue, int* FindId, int* FindIdT);
void system_1032_Init(struct system_1032_state* self);
void system_1032_Update(struct system_1032_state* self, int* Res);
void system_1059_Init(struct system_1059_state* self);
void system_1059_Update(struct system_1059_state* self, int SenserId, int TValue, int* Res, int* R);
void system_1282_Init(struct system_1282_state* self);
void system_1282_Update(struct system_1282_state* self, bool Gate, int SenserId, int TValue, int* Res, int* R);
void system_1023_Init(struct system_1023_state* self);
void system_1023_Update(struct system_1023_state* self, int SenserId, int TValue, int* Res, int* R);
void system_670_Init(struct system_670_state* self);
void system_670_Update(struct system_670_state* self, int SenserId, int TValue, int* Res, int* R);
void system_942_Init(struct system_942_state* self);
void system_942_Update(struct system_942_state* self, int* Res, int* R);
void system_994_Init(struct system_994_state* self);
void system_994_Update(struct system_994_state* self);
void system_981_Init(struct system_981_state* self);
void system_981_Update(struct system_981_state* self, int SenserId, int* FindId);
void system_978_Init(struct system_978_state* self);
void system_978_Update(struct system_978_state* self, int SenserId, int* FindId);
void system_1142_Init(struct system_1142_state* self);
void system_1142_Update(struct system_1142_state* self, int FindId, int* Res, int* R);
void system_1150_Init(struct system_1150_state* self);
void system_1150_Update(struct system_1150_state* self, int* Res, int* R);
void system_1288_Init(struct system_1288_state* self);
void system_1288_Update(struct system_1288_state* self, int FindId, bool Gate, int* Res, int* R);
void system_948_Init(struct system_948_state* self);
void system_948_Update(struct system_948_state* self, int SenserId, int TValue, int* Res, int* R);
void system_684_Init(struct system_684_state* self);
void system_684_Update(struct system_684_state* self, int SenserId, int TValue, int* Res, int* R);
void system_1253_Init(struct system_1253_state* self);
void system_1253_Update(struct system_1253_state* self, int SenserId, int Opcode, int TValue, int* Res, int* R);
void system_root_Init(struct system_root_state* self);
void system_root_Update(struct system_root_state* self, int SenserId, int Opcode, int TValue, int* Res, int* R);
#endif
