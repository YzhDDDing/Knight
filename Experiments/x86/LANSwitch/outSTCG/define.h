#ifndef _DEFINE_H_
#define _DEFINE_H_
/* Head File define of  */
#include <string.h>
#define RT_PI 3.14159265358979323846
#define RT_PIF 3.1415927F
#define RT_LN_10 2.30258509299404568402
#define RT_LN_10F 2.3025851F
#define RT_LOG10E 0.43429448190325182765
#define RT_LOG10EF 0.43429449F
#define RT_E 2.7182818284590452354
#define RT_EF 2.7182817F
#define UNUSED_PARAMETER(x) (void)(x)
#define rtmGetErrorStatus(rtm) ((rtm)->errorStatus)
#define rtmSetErrorStatus(rtm,val) ((rtm)->errorStatus=(val))
typedef signed char int8_T;
typedef unsigned char uint8_T;
typedef short int16_T;
typedef unsigned short uint16_T;
typedef int int32_T;
typedef unsigned int uint32_T;
typedef float real32_T;
typedef double real64_T;
typedef double real_T;
typedef double time_T;
typedef unsigned char boolean_T;
typedef int int_T;
typedef unsigned int uint_T;
typedef unsigned long ulong_T;
typedef char char_T;
typedef unsigned char uchar_T;
typedef char_T byte_T;
typedef struct creal32_T creal32_T;
typedef struct creal64_T creal64_T;
typedef struct creal_T creal_T;
typedef struct cint8_T cint8_T;
typedef struct cuint8_T cuint8_T;
typedef struct cint16_T cint16_T;
typedef struct cuint16_T cuint16_T;
typedef struct cint32_T cint32_T;
typedef struct cuint32_T cuint32_T;
typedef void * pointer_T;
typedef int ZCEventType;
typedef struct _ssMdlInfo _ssMdlInfo;
typedef struct tag_RTM_LANSwitch_T RT_MODEL_LANSwitch_T;
typedef struct B_LANSwitch_T B_LANSwitch_T;
typedef struct DW_LANSwitch_T DW_LANSwitch_T;
typedef struct ConstB_LANSwitch_T ConstB_LANSwitch_T;
typedef struct TaskCounters_LANSwitch_T TaskCounters_LANSwitch_T;
typedef struct TIME_LANSwitch_T TIME_LANSwitch_T;
struct B_LANSwitch_T;
struct DW_LANSwitch_T;
struct ConstB_LANSwitch_T;
struct creal32_T;
struct creal64_T;
struct creal_T;
struct cint8_T;
struct cuint8_T;
struct cint16_T;
struct cuint16_T;
struct cint32_T;
struct cuint32_T;
struct TaskCounters_LANSwitch_T;
struct TIME_LANSwitch_T;
struct tag_RTM_LANSwitch_T;
struct B_LANSwitch_T {
    int32_T OutportBufferForMSG;
    int32_T Switch_i;
    int32_T Switch_p;
};
struct DW_LANSwitch_T {
    int32_T PortPool[256];
    int32_T PortPoolF[256];
};
struct ConstB_LANSwitch_T {
    int32_T Constant;
};
struct creal32_T {
    real32_T re;
    real32_T im;
};
struct creal64_T {
    real64_T re;
    real64_T im;
};
struct creal_T {
    real_T re;
    real_T im;
};
struct cint8_T {
    int8_T re;
    int8_T im;
};
struct cuint8_T {
    uint8_T re;
    uint8_T im;
};
struct cint16_T {
    int16_T re;
    int16_T im;
};
struct cuint16_T {
    uint16_T re;
    uint16_T im;
};
struct cint32_T {
    int32_T re;
    int32_T im;
};
struct cuint32_T {
    uint32_T re;
    uint32_T im;
};
struct TaskCounters_LANSwitch_T {
    uint16_T TID[2];
};
struct TIME_LANSwitch_T {
    struct TaskCounters_LANSwitch_T TaskCounters;
};
struct tag_RTM_LANSwitch_T {
    char_T * errorStatus;
    struct B_LANSwitch_T * blockIO;
    struct DW_LANSwitch_T * dwork;
    struct TIME_LANSwitch_T Timing;
};
/* Global Variable define of  */
extern struct tag_RTM_LANSwitch_T LANSwitch_instance;
/* Global Variable define of  */
extern struct DW_LANSwitch_T LANSwitch_DW_instance;
/* Global Variable define of  */
extern struct B_LANSwitch_T LANSwitch_B_instance;
/* Global Variable define of  */
extern struct ConstB_LANSwitch_T LANSwitch_ConstB;
/* Update function of "LANSwitch" */
void LANSwitch_step(RT_MODEL_LANSwitch_T* LANSwitch_M, int32_T LANSwitch_U_PortId, int32_T LANSwitch_U_CMD, int32_T LANSwitch_U_Arg1, int32_T LANSwitch_U_Arg2, int32_T LANSwitch_U_Arg3, int32_T* LANSwitch_Y_Result, int32_T* LANSwitch_Y_MSG);
/* Init function of "LANSwitch" */
void LANSwitch_init(RT_MODEL_LANSwitch_T* LANSwitch_M, int32_T* LANSwitch_U_PortId, int32_T* LANSwitch_U_CMD, int32_T* LANSwitch_U_Arg1, int32_T* LANSwitch_U_Arg2, int32_T* LANSwitch_U_Arg3, int32_T* LANSwitch_Y_Result, int32_T* LANSwitch_Y_MSG);
/* Normal function of  */
void LANSwitch_Error(int32_T* rty_Result, int32_T* rty_MSG);
/* Normal function of  */
void LANSwitch_FindPortInPool(int32_T rtu_PortId, int32_T* rty_Out1, int32_T* rtd_Found_P_e, int32_T rtd_PortPool[256], int32_T rtd_PortPoolF[256]);
/* Normal function of  */
void LANSwitch_Err(int32_T* rty_Result);
#endif
