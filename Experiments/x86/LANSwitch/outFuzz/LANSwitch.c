#include "define.h"
struct tag_RTM_LANSwitch_T LANSwitch_instance;
struct DW_LANSwitch_T LANSwitch_DW_instance;
struct B_LANSwitch_T LANSwitch_B_instance;
void LANSwitch_step(RT_MODEL_LANSwitch_T* LANSwitch_M, int32_T LANSwitch_U_PortId, int32_T LANSwitch_U_CMD, int32_T LANSwitch_U_Arg1, int32_T LANSwitch_U_Arg2, int32_T LANSwitch_U_Arg3, int32_T* LANSwitch_Y_Result, int32_T* LANSwitch_Y_MSG) {
    struct B_LANSwitch_T * LANSwitch_B = LANSwitch_M->blockIO;
    struct DW_LANSwitch_T * LANSwitch_DW = LANSwitch_M->dwork;
    int32_T rtb_Assignment[256];
    int32_T rtb_Assignment1[256];
    int32_T rtb_Assignment1_o[256];
    int32_T rtb_Assignment_h[256];
    int32_T rtb_DataStoreRead[256];
    int32_T rtb_DataStoreRead1_l[256];
    int32_T rtb_DataStoreRead2[256];
    int32_T rtb_DataStoreRead2_c[256];
    int32_T rtb_DataStoreRead2_e[256];
    int32_T rtb_DataStoreRead2_p[256];
    int32_T rtb_DataStoreRead_e[256];
    int32_T rtb_DataStoreRead_l[256];
    int32_T rtb_DataStoreRead_n[256];
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
        BranchCoverageStatistics(0);
        {
            boolean_T rtb_Compare_c;
            rtb_Compare_c = (LANSwitch_U_PortId == 0);
            if (rtb_Compare_c) {
                BranchCoverageStatistics(1);
                LANSwitch_Error(&rtb_Merge, &rtb_Merge1);
            }
            else {
                BranchCoverageStatistics(2);
                boolean_T Found;
                boolean_T rtb_AND_k;
                Found = false;
                Found_E = -1;
                for (s43_iter = 0;s43_iter < 256;s43_iter++) {
                    BranchCoverageStatistics(3);
                    int32_T rtb_DataStoreRead1_f;
                    int32_T rtb_ForIterator_b;
                    int32_T rtb_ForIterator_oy;
                    boolean_T rtb_AND_d;
                    boolean_T rtb_AND_pv;
                    rtb_ForIterator_oy = s43_iter;
                    for (i = 0;i < 256;i++) {
                        BranchCoverageStatistics(4);
                        rtb_DataStoreRead_l[i] = LANSwitch_DW->PortPool[i];
                        rtb_DataStoreRead2_e[i] = LANSwitch_DW->PortPoolF[i];
                    }
                    BranchCoverageStatistics(5);
                    int32_T rtb_Selector1_g;
                    int32_T rtb_Selector_b;
                    boolean_T rtb_Compare_p;
                    boolean_T rtb_Equal_a;
                    rtb_Selector_b = rtb_DataStoreRead_l[rtb_ForIterator_oy];
                    rtb_Equal_a = (rtb_Selector_b == LANSwitch_U_PortId);
                    rtb_Selector1_g = rtb_DataStoreRead2_e[rtb_ForIterator_oy];
                    rtb_Compare_p = (rtb_Selector1_g == 1);
                    if (rtb_Equal_a) {
                        BranchCoverageStatistics(6);
                    }
                    else {
                        BranchCoverageStatistics(7);
                    }
                    if (rtb_Compare_p) {
                        BranchCoverageStatistics(8);
                    }
                    else {
                        BranchCoverageStatistics(9);
                    }
                    if (rtb_Equal_a) {
                        BranchCoverageStatistics(10);
                    }
                    else {
                        BranchCoverageStatistics(11);
                    }
                    if (rtb_Compare_p) {
                        BranchCoverageStatistics(12);
                    }
                    else {
                        BranchCoverageStatistics(13);
                    }
                    rtb_AND_d = (rtb_Equal_a && rtb_Compare_p);
                    if (rtb_AND_d) {
                        BranchCoverageStatistics(14);
                        Switch_l4 = true;
                    }
                    else {
                        BranchCoverageStatistics(15);
                        boolean_T rtb_DataStoreRead1_e;
                        rtb_DataStoreRead1_e = Found;
                        Switch_l4 = rtb_DataStoreRead1_e;
                    }
                    Found = Switch_l4;
                    rtb_ForIterator_b = s43_iter;
                    for (i = 0;i < 256;i++) {
                        BranchCoverageStatistics(16);
                        rtb_DataStoreRead2_p[i] = LANSwitch_DW->PortPoolF[i];
                    }
                    BranchCoverageStatistics(17);
                    int32_T rtb_Selector1_n;
                    boolean_T rtb_Compare_di;
                    boolean_T rtb_Compare_jk;
                    rtb_Selector1_n = rtb_DataStoreRead2_p[rtb_ForIterator_b];
                    rtb_Compare_di = (rtb_Selector1_n == 0);
                    rtb_DataStoreRead1_f = Found_E;
                    rtb_Compare_jk = (rtb_DataStoreRead1_f == -1);
                    if (rtb_Compare_di) {
                        BranchCoverageStatistics(18);
                    }
                    else {
                        BranchCoverageStatistics(19);
                    }
                    if (rtb_Compare_jk) {
                        BranchCoverageStatistics(20);
                    }
                    else {
                        BranchCoverageStatistics(21);
                    }
                    if (rtb_Compare_di) {
                        BranchCoverageStatistics(22);
                    }
                    else {
                        BranchCoverageStatistics(23);
                    }
                    if (rtb_Compare_jk) {
                        BranchCoverageStatistics(24);
                    }
                    else {
                        BranchCoverageStatistics(25);
                    }
                    rtb_AND_pv = (rtb_Compare_di && rtb_Compare_jk);
                    if (rtb_AND_pv) {
                        BranchCoverageStatistics(26);
                        Switch_m = rtb_ForIterator_b;
                    }
                    else {
                        BranchCoverageStatistics(27);
                        Switch_m = rtb_DataStoreRead1_f;
                    }
                    Found_E = Switch_m;
                }
                BranchCoverageStatistics(28);
                boolean_T rtb_Compare_ej;
                boolean_T rtb_Compare_m;
                rtb_Compare_m = !Switch_l4;
                rtb_Compare_ej = (Switch_m != -1);
                if (rtb_Compare_m) {
                    BranchCoverageStatistics(29);
                }
                else {
                    BranchCoverageStatistics(30);
                }
                if (rtb_Compare_ej) {
                    BranchCoverageStatistics(31);
                }
                else {
                    BranchCoverageStatistics(32);
                }
                if (rtb_Compare_m) {
                    BranchCoverageStatistics(33);
                }
                else {
                    BranchCoverageStatistics(34);
                }
                if (rtb_Compare_ej) {
                    BranchCoverageStatistics(35);
                }
                else {
                    BranchCoverageStatistics(36);
                }
                rtb_AND_k = (rtb_Compare_m && rtb_Compare_ej);
                if (rtb_AND_k) {
                    BranchCoverageStatistics(37);
                    boolean_T rtb_Compare_np;
                    rtb_Merge = 1;
                    for (Found_E = 0;Found_E < 256;Found_E++) {
                        BranchCoverageStatistics(38);
                        int32_T rtb_ForIterator_o;
                        int32_T rtb_Switch1_f;
                        int32_T rtb_Switch_c;
                        boolean_T rtb_Equal_m;
                        rtb_ForIterator_o = Found_E;
                        for (i = 0;i < 256;i++) {
                            BranchCoverageStatistics(39);
                            rtb_DataStoreRead_e[i] = LANSwitch_DW->PortPool[i];
                        }
                        BranchCoverageStatistics(40);
                        rtb_Equal_m = (Switch_m == rtb_ForIterator_o);
                        if (rtb_Equal_m) {
                            BranchCoverageStatistics(41);
                            rtb_Switch_c = LANSwitch_U_PortId;
                        }
                        else {
                            BranchCoverageStatistics(42);
                            int32_T rtb_Selector_i;
                            rtb_Selector_i = rtb_DataStoreRead_e[rtb_ForIterator_o];
                            rtb_Switch_c = rtb_Selector_i;
                        }
                        if (Found_E == 0) {
                            BranchCoverageStatistics(43);
                            for (i = 0;i < 256;i++) {
                                BranchCoverageStatistics(44);
                                rtb_Assignment_h[i] = rtb_DataStoreRead_e[i];
                            }
                            BranchCoverageStatistics(45);
                        }
                        else {
                            BranchCoverageStatistics(46);
                        }
                        rtb_Assignment_h[rtb_ForIterator_o] = rtb_Switch_c;
                        for (i = 0;i < 256;i++) {
                            BranchCoverageStatistics(47);
                            LANSwitch_DW->PortPool[i] = rtb_Assignment_h[i];
                            rtb_DataStoreRead1_l[i] = LANSwitch_DW->PortPoolF[i];
                        }
                        BranchCoverageStatistics(48);
                        if (rtb_Equal_m) {
                            BranchCoverageStatistics(49);
                            rtb_Switch1_f = 1;
                        }
                        else {
                            BranchCoverageStatistics(50);
                            int32_T rtb_Selector1_c;
                            rtb_Selector1_c = rtb_DataStoreRead1_l[rtb_ForIterator_o];
                            rtb_Switch1_f = rtb_Selector1_c;
                        }
                        if (Found_E == 0) {
                            BranchCoverageStatistics(51);
                            for (i = 0;i < 256;i++) {
                                BranchCoverageStatistics(52);
                                rtb_Assignment1_o[i] = rtb_DataStoreRead1_l[i];
                            }
                            BranchCoverageStatistics(53);
                        }
                        else {
                            BranchCoverageStatistics(54);
                        }
                        rtb_Assignment1_o[rtb_ForIterator_o] = rtb_Switch1_f;
                        for (i = 0;i < 256;i++) {
                            BranchCoverageStatistics(55);
                            LANSwitch_DW->PortPoolF[i] = rtb_Assignment1_o[i];
                        }
                        BranchCoverageStatistics(56);
                    }
                    BranchCoverageStatistics(57);
                    rtb_Compare_np = (Switch_m == 0);
                    if (rtb_Compare_np) {
                        BranchCoverageStatistics(58);
                        LANSwitch_B->Switch_p = 1;
                    }
                    else {
                        BranchCoverageStatistics(59);
                        int32_T rtb_Switch1_p;
                        boolean_T rtb_Compare_le;
                        rtb_Compare_le = (Switch_m == 1);
                        if (rtb_Compare_le) {
                            BranchCoverageStatistics(60);
                            rtb_Switch1_p = 2;
                        }
                        else {
                            BranchCoverageStatistics(61);
                            int32_T rtb_Switch2_d;
                            boolean_T rtb_Compare_nr;
                            rtb_Compare_nr = (Switch_m == 2);
                            if (rtb_Compare_nr) {
                                BranchCoverageStatistics(62);
                                rtb_Switch2_d = 3;
                            }
                            else {
                                BranchCoverageStatistics(63);
                                rtb_Switch2_d = 4;
                            }
                            rtb_Switch1_p = rtb_Switch2_d;
                        }
                        LANSwitch_B->Switch_p = rtb_Switch1_p;
                    }
                }
                else {
                    BranchCoverageStatistics(64);
                    rtb_Merge = -10002;
                }
                rtb_Merge1 = LANSwitch_B->Switch_p;
            }
            break;
        }
    case 10002:
        BranchCoverageStatistics(65);
        {
            boolean_T rtb_Compare_ck;
            rtb_Compare_ck = (LANSwitch_U_PortId == 0);
            if (rtb_Compare_ck) {
                BranchCoverageStatistics(66);
                LANSwitch_Error(&rtb_Merge, &rtb_Merge1);
            }
            else {
                BranchCoverageStatistics(67);
                boolean_T rtb_AND;
                Switch_m = -1;
                Found_E = -1;
                LANSwitch_FindPortInPool(LANSwitch_U_PortId, &s43_iter, &Switch_m, LANSwitch_DW->PortPool, LANSwitch_DW->PortPoolF);
                for (Switch_m = 0;Switch_m < 256;Switch_m++) {
                    BranchCoverageStatistics(68);
                    int32_T rtb_DataStoreRead1;
                    int32_T rtb_ForIterator_a;
                    boolean_T rtb_AND_e;
                    rtb_ForIterator_a = Switch_m;
                    for (i = 0;i < 256;i++) {
                        BranchCoverageStatistics(69);
                        rtb_DataStoreRead_n[i] = LANSwitch_DW->PortPool[i];
                        rtb_DataStoreRead2_c[i] = LANSwitch_DW->PortPoolF[i];
                    }
                    BranchCoverageStatistics(70);
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
                        BranchCoverageStatistics(71);
                    }
                    else {
                        BranchCoverageStatistics(72);
                    }
                    if (rtb_Compare_ai) {
                        BranchCoverageStatistics(73);
                    }
                    else {
                        BranchCoverageStatistics(74);
                    }
                    if (rtb_Equal_c) {
                        BranchCoverageStatistics(75);
                    }
                    else {
                        BranchCoverageStatistics(76);
                    }
                    if (rtb_Compare_ai) {
                        BranchCoverageStatistics(77);
                    }
                    else {
                        BranchCoverageStatistics(78);
                    }
                    rtb_AND1 = (rtb_Equal_c && rtb_Compare_ai);
                    rtb_DataStoreRead1 = Found_E;
                    rtb_Compare_o5 = (rtb_DataStoreRead1 == -1);
                    if (rtb_AND1) {
                        BranchCoverageStatistics(79);
                    }
                    else {
                        BranchCoverageStatistics(80);
                    }
                    if (rtb_Compare_o5) {
                        BranchCoverageStatistics(81);
                    }
                    else {
                        BranchCoverageStatistics(82);
                    }
                    if (rtb_AND1) {
                        BranchCoverageStatistics(83);
                    }
                    else {
                        BranchCoverageStatistics(84);
                    }
                    if (rtb_Compare_o5) {
                        BranchCoverageStatistics(85);
                    }
                    else {
                        BranchCoverageStatistics(86);
                    }
                    rtb_AND_e = (rtb_AND1 && rtb_Compare_o5);
                    if (rtb_AND_e) {
                        BranchCoverageStatistics(87);
                        i = rtb_ForIterator_a;
                    }
                    else {
                        BranchCoverageStatistics(88);
                        i = rtb_DataStoreRead1;
                    }
                    Found_E = i;
                }
                BranchCoverageStatistics(89);
                boolean_T rtb_Compare_f;
                boolean_T rtb_Compare_i;
                rtb_Compare_f = (s43_iter != -1);
                rtb_Compare_i = (i != -1);
                if (rtb_Compare_f) {
                    BranchCoverageStatistics(90);
                }
                else {
                    BranchCoverageStatistics(91);
                }
                if (rtb_Compare_i) {
                    BranchCoverageStatistics(92);
                }
                else {
                    BranchCoverageStatistics(93);
                }
                if (rtb_Compare_f) {
                    BranchCoverageStatistics(94);
                }
                else {
                    BranchCoverageStatistics(95);
                }
                if (rtb_Compare_i) {
                    BranchCoverageStatistics(96);
                }
                else {
                    BranchCoverageStatistics(97);
                }
                rtb_AND = (rtb_Compare_f && rtb_Compare_i);
                if (rtb_AND) {
                    BranchCoverageStatistics(98);
                    int32_T rtb_Subtract;
                    boolean_T rtb_Compare_nw;
                    rtb_Merge = LANSwitch_U_Arg1;
                    rtb_Subtract = LANSwitch_U_Arg3 - LANSwitch_U_Arg2;
                    rtb_Compare_nw = (rtb_Subtract == 1);
                    if (rtb_Compare_nw) {
                        BranchCoverageStatistics(99);
                        LANSwitch_B->Switch_i = 101;
                    }
                    else {
                        BranchCoverageStatistics(100);
                        int32_T rtb_Switch1_l;
                        boolean_T rtb_Compare_cv;
                        rtb_Compare_cv = (rtb_Subtract == 2);
                        if (rtb_Compare_cv) {
                            BranchCoverageStatistics(101);
                            rtb_Switch1_l = 102;
                        }
                        else {
                            BranchCoverageStatistics(102);
                            int32_T rtb_Switch2;
                            boolean_T rtb_Compare_bl;
                            rtb_Compare_bl = (rtb_Subtract == 3);
                            if (rtb_Compare_bl) {
                                BranchCoverageStatistics(103);
                                rtb_Switch2 = 103;
                            }
                            else {
                                BranchCoverageStatistics(104);
                                int32_T rtb_Switch3;
                                boolean_T rtb_Compare_g;
                                rtb_Compare_g = (rtb_Subtract == -1);
                                if (rtb_Compare_g) {
                                    BranchCoverageStatistics(105);
                                    rtb_Switch3 = -101;
                                }
                                else {
                                    BranchCoverageStatistics(106);
                                    int32_T rtb_Switch4;
                                    boolean_T rtb_Compare_hn;
                                    rtb_Compare_hn = (rtb_Subtract == -2);
                                    if (rtb_Compare_hn) {
                                        BranchCoverageStatistics(107);
                                        rtb_Switch4 = -102;
                                    }
                                    else {
                                        BranchCoverageStatistics(108);
                                        int32_T rtb_Switch5;
                                        boolean_T rtb_Compare_pyv;
                                        rtb_Compare_pyv = (rtb_Subtract == -3);
                                        if (rtb_Compare_pyv) {
                                            BranchCoverageStatistics(109);
                                            rtb_Switch5 = -103;
                                        }
                                        else {
                                            BranchCoverageStatistics(110);
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
                    BranchCoverageStatistics(111);
                    LANSwitch_Err(&rtb_Merge);
                }
                rtb_Merge1 = LANSwitch_B->Switch_i;
            }
            break;
        }
    case 10003:
        BranchCoverageStatistics(112);
        {
            boolean_T rtb_Compare_ct;
            rtb_Compare_ct = (LANSwitch_U_PortId == 0);
            if (rtb_Compare_ct) {
                BranchCoverageStatistics(113);
                LANSwitch_Error(&rtb_Merge, &rtb_Merge1);
            }
            else {
                BranchCoverageStatistics(114);
                boolean_T rtb_Compare_b;
                Found_E = -1;
                LANSwitch_FindPortInPool(LANSwitch_U_PortId, &s43_iter, &Found_E, LANSwitch_DW->PortPool, LANSwitch_DW->PortPoolF);
                rtb_Compare_b = (s43_iter != -1);
                if (rtb_Compare_b) {
                    BranchCoverageStatistics(115);
                    rtb_Merge = s43_iter;
                    rtb_Merge1 = 1;
                }
                else {
                    BranchCoverageStatistics(116);
                    rtb_Merge = -1;
                    rtb_Merge1 = -1;
                }
            }
            break;
        }
    case 10004:
        BranchCoverageStatistics(117);
        {
            boolean_T rtb_Compare_k;
            rtb_Compare_k = (LANSwitch_U_PortId == 0);
            if (rtb_Compare_k) {
                BranchCoverageStatistics(118);
                LANSwitch_Error(&rtb_Merge, &rtb_Merge1);
            }
            else {
                BranchCoverageStatistics(119);
                uint8_T rtb_Compare;
                Found_E = -1;
                LANSwitch_FindPortInPool(LANSwitch_U_PortId, &rtb_Switch_l, &Found_E, LANSwitch_DW->PortPool, LANSwitch_DW->PortPoolF);
                rtb_Compare = (uint8_T)(rtb_Switch_l == -1);
                if (rtb_Compare != 0) {
                    BranchCoverageStatistics(120);
                    LANSwitch_Err(&Found_E);
                }
                else {
                    BranchCoverageStatistics(121);
                    int32_T rtb_PortId;
                    rtb_PortId = LANSwitch_U_PortId;
                    for (Found_E = 0;Found_E < 256;Found_E++) {
                        BranchCoverageStatistics(122);
                        int32_T rtb_ForIterator;
                        int32_T rtb_Switch;
                        int32_T rtb_Switch1;
                        boolean_T rtb_Equal;
                        rtb_ForIterator = Found_E;
                        for (i = 0;i < 256;i++) {
                            BranchCoverageStatistics(123);
                            rtb_DataStoreRead[i] = LANSwitch_DW->PortPool[i];
                        }
                        BranchCoverageStatistics(124);
                        rtb_Equal = (rtb_PortId == rtb_ForIterator);
                        if (rtb_Equal) {
                            BranchCoverageStatistics(125);
                            rtb_Switch = 0;
                        }
                        else {
                            BranchCoverageStatistics(126);
                            int32_T rtb_Selector;
                            rtb_Selector = rtb_DataStoreRead[rtb_ForIterator];
                            rtb_Switch = rtb_Selector;
                        }
                        if (Found_E == 0) {
                            BranchCoverageStatistics(127);
                            for (i = 0;i < 256;i++) {
                                BranchCoverageStatistics(128);
                                rtb_Assignment[i] = rtb_DataStoreRead[i];
                            }
                            BranchCoverageStatistics(129);
                        }
                        else {
                            BranchCoverageStatistics(130);
                        }
                        rtb_Assignment[rtb_ForIterator] = rtb_Switch;
                        for (i = 0;i < 256;i++) {
                            BranchCoverageStatistics(131);
                            LANSwitch_DW->PortPool[i] = rtb_Assignment[i];
                            rtb_DataStoreRead2[i] = LANSwitch_DW->PortPoolF[i];
                        }
                        BranchCoverageStatistics(132);
                        if (rtb_Equal) {
                            BranchCoverageStatistics(133);
                            rtb_Switch1 = 0;
                        }
                        else {
                            BranchCoverageStatistics(134);
                            int32_T rtb_Selector1;
                            rtb_Selector1 = rtb_DataStoreRead2[rtb_ForIterator];
                            rtb_Switch1 = rtb_Selector1;
                        }
                        if (Found_E == 0) {
                            BranchCoverageStatistics(135);
                            for (i = 0;i < 256;i++) {
                                BranchCoverageStatistics(136);
                                rtb_Assignment1[i] = rtb_DataStoreRead2[i];
                            }
                            BranchCoverageStatistics(137);
                        }
                        else {
                            BranchCoverageStatistics(138);
                        }
                        rtb_Assignment1[rtb_ForIterator] = rtb_Switch1;
                        for (i = 0;i < 256;i++) {
                            BranchCoverageStatistics(139);
                            LANSwitch_DW->PortPoolF[i] = rtb_Assignment1[i];
                        }
                        BranchCoverageStatistics(140);
                    }
                    BranchCoverageStatistics(141);
                    Found_E = rtb_PortId;
                    LANSwitch_B->OutportBufferForMSG = LANSwitch_ConstB.Constant;
                }
                rtb_Merge1 = LANSwitch_B->OutportBufferForMSG;
                rtb_Merge = Found_E;
            }
            break;
        }
    default:
        BranchCoverageStatistics(142);
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
    int32_T rtb_DataStoreRead2_pj[256];
    int32_T rtb_DataStoreRead_j[256];
    int32_T i;
    for (i = 0;i < 256;i++) {
        BranchCoverageStatistics(143);
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
            BranchCoverageStatistics(144);
        }
        else {
            BranchCoverageStatistics(145);
        }
        if (rtb_Compare_n1) {
            BranchCoverageStatistics(146);
        }
        else {
            BranchCoverageStatistics(147);
        }
        if (rtb_Equal_n) {
            BranchCoverageStatistics(148);
        }
        else {
            BranchCoverageStatistics(149);
        }
        if (rtb_Compare_n1) {
            BranchCoverageStatistics(150);
        }
        else {
            BranchCoverageStatistics(151);
        }
        rtb_AND1_e = (rtb_Equal_n && rtb_Compare_n1);
        rtb_DataStoreRead1_cy = *rtd_Found_P_e;
        rtb_Compare_cc = (rtb_DataStoreRead1_cy == -1);
        if (rtb_AND1_e) {
            BranchCoverageStatistics(152);
        }
        else {
            BranchCoverageStatistics(153);
        }
        if (rtb_Compare_cc) {
            BranchCoverageStatistics(154);
        }
        else {
            BranchCoverageStatistics(155);
        }
        if (rtb_AND1_e) {
            BranchCoverageStatistics(156);
        }
        else {
            BranchCoverageStatistics(157);
        }
        if (rtb_Compare_cc) {
            BranchCoverageStatistics(158);
        }
        else {
            BranchCoverageStatistics(159);
        }
        rtb_AND_g = (rtb_AND1_e && rtb_Compare_cc);
        if (rtb_AND_g) {
            BranchCoverageStatistics(160);
            *rty_Out1 = rtb_ForIterator_e;
        }
        else {
            BranchCoverageStatistics(161);
            *rty_Out1 = rtb_DataStoreRead1_cy;
        }
        *rtd_Found_P_e = *rty_Out1;
    }
    BranchCoverageStatistics(162);
}
void LANSwitch_Err(int32_T* rty_Result) {
    *rty_Result = -10003;
}