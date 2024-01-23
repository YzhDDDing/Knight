#include "define.h"
float Data_StoreMemory_Data[64];
int Data_StoreMemory1_ID;
int Data_StoreMemory2_Index;
int Data_StoreMemory3_Init;
int Data_StoreMemory4_Terminate;
int Data_StoreMemory5_Error;
int Data_StoreMemory6_Satisfied[64];
float Data_StoreMemory7_State;
float Data_StoreMemory8_Data_o[64];
int Data_StoreMemory9_Sat_o[64];
struct system_1827_state system_1827_instance;
void system_1827_Init(struct system_1827_state* self) {
    memset(Data_StoreMemory_Data, 0, sizeof(Data_StoreMemory_Data));
    Data_StoreMemory1_ID = 0;
    Data_StoreMemory2_Index = 0;
    Data_StoreMemory3_Init = 0;
    Data_StoreMemory4_Terminate = 0;
    Data_StoreMemory5_Error = 0;
    memset(Data_StoreMemory6_Satisfied, 0, sizeof(Data_StoreMemory6_Satisfied));
    Data_StoreMemory7_State = 0;
    memset(Data_StoreMemory8_Data_o, 0, sizeof(Data_StoreMemory8_Data_o));
    memset(Data_StoreMemory9_Sat_o, 0, sizeof(Data_StoreMemory9_Sat_o));
    system_1832_Init(&system_1832_instance);
    system_1897_Init(&system_1897_instance);
    system_2747_Init(&system_2747_instance);
    system_2676_Init(&system_2676_instance);
}
void system_1827_Update(struct system_1827_state* self, float t, int* Output) {
    int FunctionCallSubsystem2_Output = 0;
    system_1832_Update(&system_1832_instance);
    system_1897_Update(&system_1897_instance, t);
    system_2747_Update(&system_2747_instance);
    system_2676_Update(&system_2676_instance, t, &FunctionCallSubsystem2_Output);
    *Output = FunctionCallSubsystem2_Output;
}