#include <string.h>
#include <assert.h>
#define RT_PI 3.14159265358979323846
#define RT_PIF 3.1415927F
#define RT_LN_10 2.30258509299404568402
#define RT_LN_10F 2.3025851F
#define RT_LOG10E 0.43429448190325182765
#define RT_LOG10EF 0.43429449F
#define RT_E 2.7182818284590452354
#define RT_EF 2.7182817F
#define false 0
#define true 1
#define NULL 0
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
    int32_T PortPool[3];
    int32_T PortPoolF[3];
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
struct tag_RTM_LANSwitch_T LANSwitch_instance;
struct DW_LANSwitch_T LANSwitch_DW_instance;
struct B_LANSwitch_T LANSwitch_B_instance;
struct ConstB_LANSwitch_T LANSwitch_ConstB = {1};
void LANSwitch_step(RT_MODEL_LANSwitch_T* LANSwitch_M, int32_T LANSwitch_U_PortId, int32_T LANSwitch_U_CMD, int32_T LANSwitch_U_Arg1, int32_T LANSwitch_U_Arg2, int32_T LANSwitch_U_Arg3, int32_T* LANSwitch_Y_Result, int32_T* LANSwitch_Y_MSG);
void LANSwitch_init(RT_MODEL_LANSwitch_T* LANSwitch_M, int32_T* LANSwitch_U_PortId, int32_T* LANSwitch_U_CMD, int32_T* LANSwitch_U_Arg1, int32_T* LANSwitch_U_Arg2, int32_T* LANSwitch_U_Arg3, int32_T* LANSwitch_Y_Result, int32_T* LANSwitch_Y_MSG);
void LANSwitch_Error(int32_T* rty_Result, int32_T* rty_MSG);
void LANSwitch_FindPortInPool(int32_T rtu_PortId, int32_T* rty_Out1, int32_T* rtd_Found_P_e, int32_T rtd_PortPool[256], int32_T rtd_PortPoolF[256]);
void LANSwitch_Err(int32_T* rty_Result);
void LANSwitch_step(RT_MODEL_LANSwitch_T* LANSwitch_M, int32_T LANSwitch_U_PortId, int32_T LANSwitch_U_CMD, int32_T LANSwitch_U_Arg1, int32_T LANSwitch_U_Arg2, int32_T LANSwitch_U_Arg3, int32_T* LANSwitch_Y_Result, int32_T* LANSwitch_Y_MSG) {
    struct B_LANSwitch_T * LANSwitch_B = LANSwitch_M->blockIO;
    struct DW_LANSwitch_T * LANSwitch_DW = LANSwitch_M->dwork;
    int32_T rtb_Assignment[3];
    int32_T rtb_Assignment1[3];
    int32_T rtb_Assignment1_o[3];
    int32_T rtb_Assignment_h[3];
    int32_T rtb_DataStoreRead[3];
    int32_T rtb_DataStoreRead1_l[3];
    int32_T rtb_DataStoreRead2[3];
    int32_T rtb_DataStoreRead2_c[3];
    int32_T rtb_DataStoreRead2_e[3];
    int32_T rtb_DataStoreRead2_p[3];
    int32_T rtb_DataStoreRead_e[3];
    int32_T rtb_DataStoreRead_l[3];
    int32_T rtb_DataStoreRead_n[3];
    int32_T Found_E;
    int32_T Switch_m;
    int32_T i;
    int32_T rtb_Merge;
    int32_T rtb_Merge1;
    int32_T rtb_Switch_l;
    int32_T s43_iter;
    boolean_T Switch_l4;
    switch(LANSwitch_U_CMD)
    {
    case 10001:
        __CPROVER_cover(1);
        {
            boolean_T rtb_Compare_c;
            rtb_Compare_c = (LANSwitch_U_PortId == 0);
            if (rtb_Compare_c) {
                __CPROVER_cover(2);
                LANSwitch_Error(&rtb_Merge, &rtb_Merge1);
            }
            else {
                __CPROVER_cover(3);
                boolean_T Found;
                boolean_T rtb_AND_k;
                Found = false;
                Found_E = -1;
                for (s43_iter = 0;s43_iter < 256;s43_iter++) {
                    __CPROVER_cover(4);
                    int32_T rtb_DataStoreRead1_f;
                    int32_T rtb_ForIterator_b;
                    int32_T rtb_ForIterator_oy;
                    boolean_T rtb_AND_d;
                    boolean_T rtb_AND_pv;
                    rtb_ForIterator_oy = s43_iter;
                    for (i = 0;i < 256;i++) {
                        __CPROVER_cover(5);
                        rtb_DataStoreRead_l[i] = LANSwitch_DW->PortPool[i];
                        rtb_DataStoreRead2_e[i] = LANSwitch_DW->PortPoolF[i];
                    }
                    __CPROVER_cover(6);
                    int32_T rtb_Selector1_g;
                    int32_T rtb_Selector_b;
                    boolean_T rtb_Compare_p;
                    boolean_T rtb_Equal_a;
                    rtb_Selector_b = rtb_DataStoreRead_l[rtb_ForIterator_oy];
                    rtb_Equal_a = (rtb_Selector_b == LANSwitch_U_PortId);
                    rtb_Selector1_g = rtb_DataStoreRead2_e[rtb_ForIterator_oy];
                    rtb_Compare_p = (rtb_Selector1_g == 1);
                    if (rtb_Equal_a) {
                        __CPROVER_cover(7);
                    }
                    else {
                        __CPROVER_cover(8);
                    }
                    if (rtb_Compare_p) {
                        __CPROVER_cover(9);
                    }
                    else {
                        __CPROVER_cover(10);
                    }
                    rtb_AND_d = (rtb_Equal_a && rtb_Compare_p);
                    if (rtb_AND_d) {
                        __CPROVER_cover(11);
                        Switch_l4 = true;
                    }
                    else {
                        __CPROVER_cover(12);
                        boolean_T rtb_DataStoreRead1_e;
                        rtb_DataStoreRead1_e = Found;
                        Switch_l4 = rtb_DataStoreRead1_e;
                    }
                    Found = Switch_l4;
                    rtb_ForIterator_b = s43_iter;
                    for (i = 0;i < 256;i++) {
                        __CPROVER_cover(13);
                        rtb_DataStoreRead2_p[i] = LANSwitch_DW->PortPoolF[i];
                    }
                    __CPROVER_cover(14);
                    int32_T rtb_Selector1_n;
                    boolean_T rtb_Compare_di;
                    boolean_T rtb_Compare_jk;
                    rtb_Selector1_n = rtb_DataStoreRead2_p[rtb_ForIterator_b];
                    rtb_Compare_di = (rtb_Selector1_n == 0);
                    rtb_DataStoreRead1_f = Found_E;
                    rtb_Compare_jk = (rtb_DataStoreRead1_f == -1);
                    if (rtb_Compare_di) {
                        __CPROVER_cover(15);
                    }
                    else {
                        __CPROVER_cover(16);
                    }
                    if (rtb_Compare_jk) {
                        __CPROVER_cover(17);
                    }
                    else {
                        __CPROVER_cover(18);
                    }
                    rtb_AND_pv = (rtb_Compare_di && rtb_Compare_jk);
                    if (rtb_AND_pv) {
                        __CPROVER_cover(19);
                        Switch_m = rtb_ForIterator_b;
                    }
                    else {
                        __CPROVER_cover(20);
                        Switch_m = rtb_DataStoreRead1_f;
                    }
                    Found_E = Switch_m;
                }
                __CPROVER_cover(21);
                boolean_T rtb_Compare_ej;
                boolean_T rtb_Compare_m;
                rtb_Compare_m = !Switch_l4;
                rtb_Compare_ej = (Switch_m != -1);
                if (rtb_Compare_m) {
                    __CPROVER_cover(22);
                }
                else {
                    __CPROVER_cover(23);
                }
                if (rtb_Compare_ej) {
                    __CPROVER_cover(24);
                }
                else {
                    __CPROVER_cover(25);
                }
                rtb_AND_k = (rtb_Compare_m && rtb_Compare_ej);
                if (rtb_AND_k) {
                    __CPROVER_cover(26);
                    boolean_T rtb_Compare_np;
                    rtb_Merge = 1;
                    for (Found_E = 0;Found_E < 256;Found_E++) {
                        __CPROVER_cover(27);
                        int32_T rtb_ForIterator_o;
                        int32_T rtb_Switch1_f;
                        int32_T rtb_Switch_c;
                        boolean_T rtb_Equal_m;
                        rtb_ForIterator_o = Found_E;
                        for (i = 0;i < 256;i++) {
                            __CPROVER_cover(28);
                            rtb_DataStoreRead_e[i] = LANSwitch_DW->PortPool[i];
                        }
                        __CPROVER_cover(29);
                        rtb_Equal_m = (Switch_m == rtb_ForIterator_o);
                        if (rtb_Equal_m) {
                            __CPROVER_cover(30);
                            rtb_Switch_c = LANSwitch_U_PortId;
                        }
                        else {
                            __CPROVER_cover(31);
                            int32_T rtb_Selector_i;
                            rtb_Selector_i = rtb_DataStoreRead_e[rtb_ForIterator_o];
                            rtb_Switch_c = rtb_Selector_i;
                        }
                        if (Found_E == 0) {
                            __CPROVER_cover(32);
                            for (i = 0;i < 256;i++) {
                                __CPROVER_cover(33);
                                rtb_Assignment_h[i] = rtb_DataStoreRead_e[i];
                            }
                            __CPROVER_cover(34);
                        }
                        else {
                            __CPROVER_cover(35);
                        }
                        rtb_Assignment_h[rtb_ForIterator_o] = rtb_Switch_c;
                        for (i = 0;i < 256;i++) {
                            __CPROVER_cover(36);
                            LANSwitch_DW->PortPool[i] = rtb_Assignment_h[i];
                            rtb_DataStoreRead1_l[i] = LANSwitch_DW->PortPoolF[i];
                        }
                        __CPROVER_cover(37);
                        if (rtb_Equal_m) {
                            __CPROVER_cover(38);
                            rtb_Switch1_f = 1;
                        }
                        else {
                            __CPROVER_cover(39);
                            int32_T rtb_Selector1_c;
                            rtb_Selector1_c = rtb_DataStoreRead1_l[rtb_ForIterator_o];
                            rtb_Switch1_f = rtb_Selector1_c;
                        }
                        if (Found_E == 0) {
                            __CPROVER_cover(40);
                            for (i = 0;i < 256;i++) {
                                __CPROVER_cover(41);
                                rtb_Assignment1_o[i] = rtb_DataStoreRead1_l[i];
                            }
                            __CPROVER_cover(42);
                        }
                        else {
                            __CPROVER_cover(43);
                        }
                        rtb_Assignment1_o[rtb_ForIterator_o] = rtb_Switch1_f;
                        for (i = 0;i < 256;i++) {
                            __CPROVER_cover(44);
                            LANSwitch_DW->PortPoolF[i] = rtb_Assignment1_o[i];
                        }
                        __CPROVER_cover(45);
                    }
                    __CPROVER_cover(46);
                    rtb_Compare_np = (Switch_m == 0);
                    if (rtb_Compare_np) {
                        __CPROVER_cover(47);
                        LANSwitch_B->Switch_p = 1;
                    }
                    else {
                        __CPROVER_cover(48);
                        int32_T rtb_Switch1_p;
                        boolean_T rtb_Compare_le;
                        rtb_Compare_le = (Switch_m == 1);
                        if (rtb_Compare_le) {
                            __CPROVER_cover(49);
                            rtb_Switch1_p = 2;
                        }
                        else {
                            __CPROVER_cover(50);
                            int32_T rtb_Switch2_d;
                            boolean_T rtb_Compare_nr;
                            rtb_Compare_nr = (Switch_m == 2);
                            if (rtb_Compare_nr) {
                                __CPROVER_cover(51);
                                rtb_Switch2_d = 3;
                            }
                            else {
                                __CPROVER_cover(52);
                                rtb_Switch2_d = 4;
                            }
                            rtb_Switch1_p = rtb_Switch2_d;
                        }
                        LANSwitch_B->Switch_p = rtb_Switch1_p;
                    }
                }
                else {
                    __CPROVER_cover(53);
                    rtb_Merge = -10002;
                }
                rtb_Merge1 = LANSwitch_B->Switch_p;
            }
            break;
        }
    case 10002:
        __CPROVER_cover(54);
        {
            boolean_T rtb_Compare_ck;
            rtb_Compare_ck = (LANSwitch_U_PortId == 0);
            if (rtb_Compare_ck) {
                __CPROVER_cover(55);
                LANSwitch_Error(&rtb_Merge, &rtb_Merge1);
            }
            else {
                __CPROVER_cover(56);
                boolean_T rtb_AND;
                Switch_m = -1;
                Found_E = -1;
                LANSwitch_FindPortInPool(LANSwitch_U_PortId, &s43_iter, &Switch_m, LANSwitch_DW->PortPool, LANSwitch_DW->PortPoolF);
                for (Switch_m = 0;Switch_m < 256;Switch_m++) {
                    __CPROVER_cover(57);
                    int32_T rtb_DataStoreRead1;
                    int32_T rtb_ForIterator_a;
                    boolean_T rtb_AND_e;
                    rtb_ForIterator_a = Switch_m;
                    for (i = 0;i < 256;i++) {
                        __CPROVER_cover(58);
                        rtb_DataStoreRead_n[i] = LANSwitch_DW->PortPool[i];
                        rtb_DataStoreRead2_c[i] = LANSwitch_DW->PortPoolF[i];
                    }
                    __CPROVER_cover(59);
                    int32_T rtb_Selector1_b;
                    int32_T rtb_Selector_a;
                    boolean_T rtb_AND1;
                    boolean_T rtb_Compare_ai;
                    boolean_T rtb_Compare_o5;
                    boolean_T rtb_Equal_c;
                    rtb_Selector_a = rtb_DataStoreRead_n[rtb_ForIterator_a];
                    rtb_Equal_c = (LANSwitch_U_Arg1 == rtb_Selector_a);
                    rtb_Selector1_b = rtb_DataStoreRead2_c[rtb_ForIterator_a];
                    rtb_Compare_ai = (rtb_Selector1_b == 1);
                    if (rtb_Equal_c) {
                        __CPROVER_cover(60);
                    }
                    else {
                        __CPROVER_cover(61);
                    }
                    if (rtb_Compare_ai) {
                        __CPROVER_cover(62);
                    }
                    else {
                        __CPROVER_cover(63);
                    }
                    rtb_AND1 = (rtb_Equal_c && rtb_Compare_ai);
                    rtb_DataStoreRead1 = Found_E;
                    rtb_Compare_o5 = (rtb_DataStoreRead1 == -1);
                    if (rtb_AND1) {
                        __CPROVER_cover(64);
                    }
                    else {
                        __CPROVER_cover(65);
                    }
                    if (rtb_Compare_o5) {
                        __CPROVER_cover(66);
                    }
                    else {
                        __CPROVER_cover(67);
                    }
                    rtb_AND_e = (rtb_AND1 && rtb_Compare_o5);
                    if (rtb_AND_e) {
                        __CPROVER_cover(68);
                        i = rtb_ForIterator_a;
                    }
                    else {
                        __CPROVER_cover(69);
                        i = rtb_DataStoreRead1;
                    }
                    Found_E = i;
                }
                __CPROVER_cover(70);
                boolean_T rtb_Compare_f;
                boolean_T rtb_Compare_i;
                rtb_Compare_f = (s43_iter != -1);
                rtb_Compare_i = (i != -1);
                if (rtb_Compare_f) {
                    __CPROVER_cover(71);
                }
                else {
                    __CPROVER_cover(72);
                }
                if (rtb_Compare_i) {
                    __CPROVER_cover(73);
                }
                else {
                    __CPROVER_cover(74);
                }
                rtb_AND = (rtb_Compare_f && rtb_Compare_i);
                if (rtb_AND) {
                    __CPROVER_cover(75);
                    int32_T rtb_Subtract;
                    boolean_T rtb_Compare_nw;
                    rtb_Merge = LANSwitch_U_Arg1;
                    rtb_Subtract = LANSwitch_U_Arg3 - LANSwitch_U_Arg2;
                    rtb_Compare_nw = (rtb_Subtract == 1);
                    if (rtb_Compare_nw) {
                        __CPROVER_cover(76);
                        LANSwitch_B->Switch_i = 101;
                    }
                    else {
                        __CPROVER_cover(77);
                        int32_T rtb_Switch1_l;
                        boolean_T rtb_Compare_cv;
                        rtb_Compare_cv = (rtb_Subtract == 2);
                        if (rtb_Compare_cv) {
                            __CPROVER_cover(78);
                            rtb_Switch1_l = 102;
                        }
                        else {
                            __CPROVER_cover(79);
                            int32_T rtb_Switch2;
                            boolean_T rtb_Compare_bl;
                            rtb_Compare_bl = (rtb_Subtract == 3);
                            if (rtb_Compare_bl) {
                                __CPROVER_cover(80);
                                rtb_Switch2 = 103;
                            }
                            else {
                                __CPROVER_cover(81);
                                int32_T rtb_Switch3;
                                boolean_T rtb_Compare_g;
                                rtb_Compare_g = (rtb_Subtract == -1);
                                if (rtb_Compare_g) {
                                    __CPROVER_cover(82);
                                    rtb_Switch3 = -101;
                                }
                                else {
                                    __CPROVER_cover(83);
                                    int32_T rtb_Switch4;
                                    boolean_T rtb_Compare_hn;
                                    rtb_Compare_hn = (rtb_Subtract == -2);
                                    if (rtb_Compare_hn) {
                                        __CPROVER_cover(84);
                                        rtb_Switch4 = -102;
                                    }
                                    else {
                                        __CPROVER_cover(85);
                                        int32_T rtb_Switch5;
                                        boolean_T rtb_Compare_pyv;
                                        rtb_Compare_pyv = (rtb_Subtract == -3);
                                        if (rtb_Compare_pyv) {
                                            __CPROVER_cover(86);
                                            rtb_Switch5 = -103;
                                        }
                                        else {
                                            __CPROVER_cover(87);
                                            rtb_Switch5 = rtb_Subtract;
                                        }
                                        rtb_Switch4 = rtb_Switch5;
                                    }
                                    rtb_Switch3 = rtb_Switch4;
                                }
                                rtb_Switch2 = rtb_Switch3;
                            }
                            rtb_Switch1_l = rtb_Switch2;
                        }
                        LANSwitch_B->Switch_i = rtb_Switch1_l;
                    }
                }
                else {
                    __CPROVER_cover(88);
                    LANSwitch_Err(&rtb_Merge);
                }
                rtb_Merge1 = LANSwitch_B->Switch_i;
            }
            break;
        }
    case 10003:
        __CPROVER_cover(89);
        {
            boolean_T rtb_Compare_ct;
            rtb_Compare_ct = (LANSwitch_U_PortId == 0);
            if (rtb_Compare_ct) {
                __CPROVER_cover(90);
                LANSwitch_Error(&rtb_Merge, &rtb_Merge1);
            }
            else {
                __CPROVER_cover(91);
                boolean_T rtb_Compare_b;
                Found_E = -1;
                LANSwitch_FindPortInPool(LANSwitch_U_PortId, &s43_iter, &Found_E, LANSwitch_DW->PortPool, LANSwitch_DW->PortPoolF);
                rtb_Compare_b = (s43_iter != -1);
                if (rtb_Compare_b) {
                    __CPROVER_cover(92);
                    rtb_Merge = s43_iter;
                    rtb_Merge1 = 1;
                }
                else {
                    __CPROVER_cover(93);
                    rtb_Merge = -1;
                    rtb_Merge1 = -1;
                }
            }
            break;
        }
    case 10004:
        __CPROVER_cover(94);
        {
            boolean_T rtb_Compare_k;
            rtb_Compare_k = (LANSwitch_U_PortId == 0);
            if (rtb_Compare_k) {
                __CPROVER_cover(95);
                LANSwitch_Error(&rtb_Merge, &rtb_Merge1);
            }
            else {
                __CPROVER_cover(96);
                uint8_T rtb_Compare;
                Found_E = -1;
                LANSwitch_FindPortInPool(LANSwitch_U_PortId, &rtb_Switch_l, &Found_E, LANSwitch_DW->PortPool, LANSwitch_DW->PortPoolF);
                rtb_Compare = (uint8_T)(rtb_Switch_l == -1);
                if (rtb_Compare != 0) {
                    __CPROVER_cover(97);
                    LANSwitch_Err(&Found_E);
                }
                else {
                    __CPROVER_cover(98);
                    int32_T rtb_PortId;
                    rtb_PortId = LANSwitch_U_PortId;
                    for (Found_E = 0;Found_E < 256;Found_E++) {
                        __CPROVER_cover(99);
                        int32_T rtb_ForIterator;
                        int32_T rtb_Switch;
                        int32_T rtb_Switch1;
                        boolean_T rtb_Equal;
                        rtb_ForIterator = Found_E;
                        for (i = 0;i < 256;i++) {
                            __CPROVER_cover(100);
                            rtb_DataStoreRead[i] = LANSwitch_DW->PortPool[i];
                        }
                        __CPROVER_cover(101);
                        rtb_Equal = (rtb_PortId == rtb_ForIterator);
                        if (rtb_Equal) {
                            __CPROVER_cover(102);
                            rtb_Switch = 0;
                        }
                        else {
                            __CPROVER_cover(103);
                            int32_T rtb_Selector;
                            rtb_Selector = rtb_DataStoreRead[rtb_ForIterator];
                            rtb_Switch = rtb_Selector;
                        }
                        if (Found_E == 0) {
                            __CPROVER_cover(104);
                            for (i = 0;i < 256;i++) {
                                __CPROVER_cover(105);
                                rtb_Assignment[i] = rtb_DataStoreRead[i];
                            }
                            __CPROVER_cover(106);
                        }
                        else {
                            __CPROVER_cover(107);
                        }
                        rtb_Assignment[rtb_ForIterator] = rtb_Switch;
                        for (i = 0;i < 256;i++) {
                            __CPROVER_cover(108);
                            LANSwitch_DW->PortPool[i] = rtb_Assignment[i];
                            rtb_DataStoreRead2[i] = LANSwitch_DW->PortPoolF[i];
                        }
                        __CPROVER_cover(109);
                        if (rtb_Equal) {
                            __CPROVER_cover(110);
                            rtb_Switch1 = 0;
                        }
                        else {
                            __CPROVER_cover(111);
                            int32_T rtb_Selector1;
                            rtb_Selector1 = rtb_DataStoreRead2[rtb_ForIterator];
                            rtb_Switch1 = rtb_Selector1;
                        }
                        if (Found_E == 0) {
                            __CPROVER_cover(112);
                            for (i = 0;i < 256;i++) {
                                __CPROVER_cover(113);
                                rtb_Assignment1[i] = rtb_DataStoreRead2[i];
                            }
                            __CPROVER_cover(114);
                        }
                        else {
                            __CPROVER_cover(115);
                        }
                        rtb_Assignment1[rtb_ForIterator] = rtb_Switch1;
                        for (i = 0;i < 256;i++) {
                            __CPROVER_cover(116);
                            LANSwitch_DW->PortPoolF[i] = rtb_Assignment1[i];
                        }
                        __CPROVER_cover(117);
                    }
                    __CPROVER_cover(118);
                    Found_E = rtb_PortId;
                    LANSwitch_B->OutportBufferForMSG = LANSwitch_ConstB.Constant;
                }
                rtb_Merge1 = LANSwitch_B->OutportBufferForMSG;
                rtb_Merge = Found_E;
            }
            break;
        }
    default:
        __CPROVER_cover(119);
        {
            rtb_Merge = -10000;
            rtb_Merge1 = 0;
            break;
        }
    }
    *LANSwitch_Y_Result = rtb_Merge;
    *LANSwitch_Y_MSG = rtb_Merge1;
}
void LANSwitch_init(RT_MODEL_LANSwitch_T* LANSwitch_M, int32_T* LANSwitch_U_PortId, int32_T* LANSwitch_U_CMD, int32_T* LANSwitch_U_Arg1, int32_T* LANSwitch_U_Arg2, int32_T* LANSwitch_U_Arg3, int32_T* LANSwitch_Y_Result, int32_T* LANSwitch_Y_MSG) {
    LANSwitch_M->blockIO = &LANSwitch_B_instance;
    LANSwitch_M->dwork = &LANSwitch_DW_instance;
    struct B_LANSwitch_T * LANSwitch_B = LANSwitch_M->blockIO;
    struct DW_LANSwitch_T * LANSwitch_DW = LANSwitch_M->dwork;
    (void)memset(((void*)LANSwitch_B), 0, sizeof(B_LANSwitch_T));
    (void)memset((void*)LANSwitch_DW, 0, sizeof(DW_LANSwitch_T));
    *LANSwitch_U_PortId = 0;
    *LANSwitch_U_CMD = 0;
    *LANSwitch_U_Arg1 = 0;
    *LANSwitch_U_Arg2 = 0;
    *LANSwitch_U_Arg3 = 0;
    *LANSwitch_Y_Result = 0;
    *LANSwitch_Y_MSG = 0;
    LANSwitch_B->OutportBufferForMSG = LANSwitch_ConstB.Constant;
}
void LANSwitch_Error(int32_T* rty_Result, int32_T* rty_MSG) {
    *rty_Result = -10001;
    *rty_MSG = 0;
}
void LANSwitch_FindPortInPool(int32_T rtu_PortId, int32_T* rty_Out1, int32_T* rtd_Found_P_e, int32_T rtd_PortPool[256], int32_T rtd_PortPoolF[256]) {
    int32_T rtb_DataStoreRead2_pj[3];
    int32_T rtb_DataStoreRead_j[3];
    int32_T i;
    for (i = 0;i < 256;i++) {
        __CPROVER_cover(120);
        int32_T rtb_DataStoreRead1_cy;
        int32_T rtb_ForIterator_e;
        int32_T rtb_Selector1_l;
        int32_T rtb_Selector_o;
        boolean_T rtb_AND1_e;
        boolean_T rtb_AND_g;
        boolean_T rtb_Compare_cc;
        boolean_T rtb_Compare_n1;
        boolean_T rtb_Equal_n;
        rtb_DataStoreRead_j[i] = rtd_PortPool[i];
        rtb_DataStoreRead2_pj[i] = rtd_PortPoolF[i];
        rtb_ForIterator_e = i;
        rtb_Selector_o = rtb_DataStoreRead_j[rtb_ForIterator_e];
        rtb_Equal_n = (rtu_PortId == rtb_Selector_o);
        rtb_Selector1_l = rtb_DataStoreRead2_pj[rtb_ForIterator_e];
        rtb_Compare_n1 = (rtb_Selector1_l == 1);
        if (rtb_Equal_n) {
            __CPROVER_cover(121);
        }
        else {
            __CPROVER_cover(122);
        }
        if (rtb_Compare_n1) {
            __CPROVER_cover(123);
        }
        else {
            __CPROVER_cover(124);
        }
        rtb_AND1_e = (rtb_Equal_n && rtb_Compare_n1);
        rtb_DataStoreRead1_cy = *rtd_Found_P_e;
        rtb_Compare_cc = (rtb_DataStoreRead1_cy == -1);
        if (rtb_AND1_e) {
            __CPROVER_cover(125);
        }
        else {
            __CPROVER_cover(126);
        }
        if (rtb_Compare_cc) {
            __CPROVER_cover(127);
        }
        else {
            __CPROVER_cover(128);
        }
        rtb_AND_g = (rtb_AND1_e && rtb_Compare_cc);
        if (rtb_AND_g) {
            __CPROVER_cover(129);
            *rty_Out1 = rtb_ForIterator_e;
        }
        else {
            __CPROVER_cover(130);
            *rty_Out1 = rtb_DataStoreRead1_cy;
        }
        *rtd_Found_P_e = *rty_Out1;
    }
    __CPROVER_cover(131);
}
void LANSwitch_Err(int32_T* rty_Result) {
    *rty_Result = -10003;
}

void globalVariableInit() {
    LANSwitch_instance.Timing.TaskCounters.TID; // Need to be modified: Variable LANSwitch_instance.Timing.TaskCounters.TID
    LANSwitch_DW_instance.PortPool; // Need to be modified: Variable LANSwitch_DW_instance.PortPool
    LANSwitch_DW_instance.PortPoolF; // Need to be modified: Variable LANSwitch_DW_instance.PortPoolF
    LANSwitch_B_instance.OutportBufferForMSG; // Need to be modified: Variable LANSwitch_B_instance.OutportBufferForMSG
    LANSwitch_B_instance.Switch_i; // Need to be modified: Variable LANSwitch_B_instance.Switch_i
    LANSwitch_B_instance.Switch_p; // Need to be modified: Variable LANSwitch_B_instance.Switch_p
    LANSwitch_ConstB.Constant; // Need to be modified: Variable LANSwitch_ConstB.Constant
}
int main() {
    int32_T init_LANSwitch_U_PortId;
    int32_T init_LANSwitch_U_CMD;
    int32_T init_LANSwitch_U_Arg1;
    int32_T init_LANSwitch_U_Arg2;
    int32_T init_LANSwitch_U_Arg3;
    int32_T init_LANSwitch_Y_Result;
    int32_T init_LANSwitch_Y_MSG;
    LANSwitch_init(&LANSwitch_instance, &init_LANSwitch_U_PortId, &init_LANSwitch_U_CMD, &init_LANSwitch_U_Arg1, &init_LANSwitch_U_Arg2, &init_LANSwitch_U_Arg3, &init_LANSwitch_Y_Result, &init_LANSwitch_Y_MSG);
    globalVariableInit();
    int32_T exec_LANSwitch_U_PortId;
    int32_T exec_LANSwitch_U_CMD;
    int32_T exec_LANSwitch_U_Arg1;
    int32_T exec_LANSwitch_U_Arg2;
    int32_T exec_LANSwitch_U_Arg3;
    int32_T exec_LANSwitch_Y_Result;
    int32_T exec_LANSwitch_Y_MSG;
    __CPROVER_input("exec_LANSwitch_U_PortId", exec_LANSwitch_U_PortId);
    __CPROVER_input("exec_LANSwitch_U_CMD", exec_LANSwitch_U_CMD);
    __CPROVER_input("exec_LANSwitch_U_Arg1", exec_LANSwitch_U_Arg1);
    __CPROVER_input("exec_LANSwitch_U_Arg2", exec_LANSwitch_U_Arg2);
    __CPROVER_input("exec_LANSwitch_U_Arg3", exec_LANSwitch_U_Arg3);
    LANSwitch_step(&LANSwitch_instance, exec_LANSwitch_U_PortId, exec_LANSwitch_U_CMD, exec_LANSwitch_U_Arg1, exec_LANSwitch_U_Arg2, exec_LANSwitch_U_Arg3, &exec_LANSwitch_Y_Result, &exec_LANSwitch_Y_MSG);
    return 0;
}