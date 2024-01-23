#include "define.h"
#include "BitmapCov.h"
/* Code of LANSwitch */
/* Global Variable define of  */
struct tag_RTM_LANSwitch_T LANSwitch_instance;
/* Global Variable define of  */
struct DW_LANSwitch_T LANSwitch_DW_instance;
/* Global Variable define of  */
struct B_LANSwitch_T LANSwitch_B_instance;
/* Update function of "LANSwitch" */
void LANSwitch_step(RT_MODEL_LANSwitch_T* LANSwitch_M, int32_T LANSwitch_U_PortId, int32_T LANSwitch_U_CMD, int32_T LANSwitch_U_Arg1, int32_T LANSwitch_U_Arg2, int32_T LANSwitch_U_Arg3, int32_T* LANSwitch_Y_Result, int32_T* LANSwitch_Y_MSG) {
    /* Calculate code of  */
    BitmapCov::munitBitmap[0] = 1;
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
    bool bool_0_1 = LANSwitch_U_CMD != 10001;
    BitmapCov::mcdcDecTemp[0] |= (((unsigned int)bool_0_1) << 1);
    bool bool_0_2 = LANSwitch_U_CMD != 10002;
    BitmapCov::mcdcDecTemp[0] |= (((unsigned int)bool_0_2) << 2);
    bool bool_0_3 = LANSwitch_U_CMD != 10003;
    BitmapCov::mcdcDecTemp[0] |= (((unsigned int)bool_0_3) << 3);
    bool bool_0_4 = LANSwitch_U_CMD != 10004;
    BitmapCov::mcdcDecTemp[0] |= (((unsigned int)bool_0_4) << 4);
    bool bool_0_0 = true && (bool_0_1) && (bool_0_2) && (bool_0_3) && (bool_0_4);
    BitmapCov::mcdcDecTemp[0] |= (((unsigned int)bool_0_0) << 0);
    {
        std::set<unsigned int>* vect = BitmapCov::mcdcBitmap->at(0);
        vect->insert(BitmapCov::mcdcDecTemp[0]);
        BitmapCov::mcdcDecTemp[0] = 0;
    }
    switch(LANSwitch_U_CMD)
    {
    case 10001:
        BitmapCov::branchBitmap[0] = 1;
        {
            boolean_T rtb_Compare_c;
            rtb_Compare_c = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(LANSwitch_U_PortId == 0, 0, 1, 1), -1, 0, 1));
            if (rtb_Compare_c) {
                BitmapCov::branchBitmap[1] = 1;
                LANSwitch_Error(&rtb_Merge, &rtb_Merge1);
            }
            else {
                BitmapCov::branchBitmap[2] = 1;
                boolean_T Found;
                boolean_T rtb_AND_k;
                Found = false;
                Found_E = -1;
                for (s43_iter = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(s43_iter < 256, 2, 1, 2), -3, 0, 2);s43_iter++) {
                    BitmapCov::branchBitmap[3] = 1;
                    int32_T rtb_DataStoreRead1_f;
                    int32_T rtb_ForIterator_b;
                    int32_T rtb_ForIterator_oy;
                    boolean_T rtb_AND_d;
                    boolean_T rtb_AND_pv;
                    rtb_ForIterator_oy = s43_iter;
                    for (i = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i < 256, 4, 1, 3), -5, 0, 3);i++) {
                        BitmapCov::branchBitmap[4] = 1;
                        rtb_DataStoreRead_l[i] = LANSwitch_DW->PortPool[i];
                        rtb_DataStoreRead2_e[i] = LANSwitch_DW->PortPoolF[i];
                    }
                    BitmapCov::branchBitmap[5] = 1;
                    int32_T rtb_Selector1_g;
                    int32_T rtb_Selector_b;
                    boolean_T rtb_Compare_p;
                    boolean_T rtb_Equal_a;
                    rtb_Selector_b = rtb_DataStoreRead_l[rtb_ForIterator_oy];
                    rtb_Equal_a = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_Selector_b == LANSwitch_U_PortId, 6, 1, 4), -7, 0, 4));
                    rtb_Selector1_g = rtb_DataStoreRead2_e[rtb_ForIterator_oy];
                    rtb_Compare_p = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_Selector1_g == 1, 8, 1, 5), -9, 0, 5));
                    if (rtb_Equal_a) {
                        BitmapCov::branchBitmap[6] = 1;
                    }
                    else {
                        BitmapCov::branchBitmap[7] = 1;
                    }
                    if (rtb_Compare_p) {
                        BitmapCov::branchBitmap[8] = 1;
                    }
                    else {
                        BitmapCov::branchBitmap[9] = 1;
                    }
                    rtb_AND_d = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_Equal_a, 10, 1, 6)&BitmapCov::CondAndMCDCRecord(rtb_Compare_p, 12, 2, 6), -11, 0, 6));
                    if (rtb_AND_d) {
                        BitmapCov::branchBitmap[10] = 1;
                        Switch_l4 = true;
                    }
                    else {
                        BitmapCov::branchBitmap[11] = 1;
                        boolean_T rtb_DataStoreRead1_e;
                        rtb_DataStoreRead1_e = Found;
                        Switch_l4 = rtb_DataStoreRead1_e;
                    }
                    Found = Switch_l4;
                    rtb_ForIterator_b = s43_iter;
                    for (i = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i < 256, 14, 1, 7), -13, 0, 7);i++) {
                        BitmapCov::branchBitmap[12] = 1;
                        rtb_DataStoreRead2_p[i] = LANSwitch_DW->PortPoolF[i];
                    }
                    BitmapCov::branchBitmap[13] = 1;
                    int32_T rtb_Selector1_n;
                    boolean_T rtb_Compare_di;
                    boolean_T rtb_Compare_jk;
                    rtb_Selector1_n = rtb_DataStoreRead2_p[rtb_ForIterator_b];
                    rtb_Compare_di = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_Selector1_n == 0, 16, 1, 8), -15, 0, 8));
                    rtb_DataStoreRead1_f = Found_E;
                    rtb_Compare_jk = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_DataStoreRead1_f == -1, 18, 1, 9), -17, 0, 9));
                    if (rtb_Compare_di) {
                        BitmapCov::branchBitmap[14] = 1;
                    }
                    else {
                        BitmapCov::branchBitmap[15] = 1;
                    }
                    if (rtb_Compare_jk) {
                        BitmapCov::branchBitmap[16] = 1;
                    }
                    else {
                        BitmapCov::branchBitmap[17] = 1;
                    }
                    rtb_AND_pv = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_Compare_di, 20, 1, 10)&BitmapCov::CondAndMCDCRecord(rtb_Compare_jk, 22, 2, 10), -19, 0, 10));
                    if (rtb_AND_pv) {
                        BitmapCov::branchBitmap[18] = 1;
                        Switch_m = rtb_ForIterator_b;
                    }
                    else {
                        BitmapCov::branchBitmap[19] = 1;
                        Switch_m = rtb_DataStoreRead1_f;
                    }
                    Found_E = Switch_m;
                }
                BitmapCov::branchBitmap[20] = 1;
                boolean_T rtb_Compare_ej;
                boolean_T rtb_Compare_m;
                rtb_Compare_m = BitmapCov::CondAndMCDCRecord(!BitmapCov::CondAndMCDCRecord(Switch_l4, 24, 1, 11), -21, 0, 11);
                rtb_Compare_ej = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(Switch_m != -1, 26, 1, 12), -23, 0, 12));
                if (rtb_Compare_m) {
                    BitmapCov::branchBitmap[21] = 1;
                }
                else {
                    BitmapCov::branchBitmap[22] = 1;
                }
                if (rtb_Compare_ej) {
                    BitmapCov::branchBitmap[23] = 1;
                }
                else {
                    BitmapCov::branchBitmap[24] = 1;
                }
                rtb_AND_k = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_Compare_m, 28, 1, 13)&BitmapCov::CondAndMCDCRecord(rtb_Compare_ej, 30, 2, 13), -25, 0, 13));
                if (rtb_AND_k) {
                    BitmapCov::branchBitmap[25] = 1;
                    boolean_T rtb_Compare_np;
                    rtb_Merge = 1;
                    for (Found_E = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(Found_E < 256, 32, 1, 14), -27, 0, 14);Found_E++) {
                        BitmapCov::branchBitmap[26] = 1;
                        int32_T rtb_ForIterator_o;
                        int32_T rtb_Switch1_f;
                        int32_T rtb_Switch_c;
                        boolean_T rtb_Equal_m;
                        rtb_ForIterator_o = Found_E;
                        for (i = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i < 256, 34, 1, 15), -29, 0, 15);i++) {
                            BitmapCov::branchBitmap[27] = 1;
                            rtb_DataStoreRead_e[i] = LANSwitch_DW->PortPool[i];
                        }
                        BitmapCov::branchBitmap[28] = 1;
                        rtb_Equal_m = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(Switch_m == rtb_ForIterator_o, 36, 1, 16), -31, 0, 16));
                        if (rtb_Equal_m) {
                            BitmapCov::branchBitmap[29] = 1;
                            rtb_Switch_c = LANSwitch_U_PortId;
                        }
                        else {
                            BitmapCov::branchBitmap[30] = 1;
                            int32_T rtb_Selector_i;
                            rtb_Selector_i = rtb_DataStoreRead_e[rtb_ForIterator_o];
                            rtb_Switch_c = rtb_Selector_i;
                        }
                        if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(Found_E == 0, 38, 1, 17), -33, 0, 17)) {
                            BitmapCov::branchBitmap[31] = 1;
                            for (i = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i < 256, 40, 1, 18), -35, 0, 18);i++) {
                                BitmapCov::branchBitmap[32] = 1;
                                rtb_Assignment_h[i] = rtb_DataStoreRead_e[i];
                            }
                            BitmapCov::branchBitmap[33] = 1;
                        }
                        else {
                            BitmapCov::branchBitmap[34] = 1;
                        }
                        rtb_Assignment_h[rtb_ForIterator_o] = rtb_Switch_c;
                        for (i = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i < 256, 42, 1, 19), -37, 0, 19);i++) {
                            BitmapCov::branchBitmap[35] = 1;
                            LANSwitch_DW->PortPool[i] = rtb_Assignment_h[i];
                            rtb_DataStoreRead1_l[i] = LANSwitch_DW->PortPoolF[i];
                        }
                        BitmapCov::branchBitmap[36] = 1;
                        if (rtb_Equal_m) {
                            BitmapCov::branchBitmap[37] = 1;
                            rtb_Switch1_f = 1;
                        }
                        else {
                            BitmapCov::branchBitmap[38] = 1;
                            int32_T rtb_Selector1_c;
                            rtb_Selector1_c = rtb_DataStoreRead1_l[rtb_ForIterator_o];
                            rtb_Switch1_f = rtb_Selector1_c;
                        }
                        if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(Found_E == 0, 44, 1, 20), -39, 0, 20)) {
                            BitmapCov::branchBitmap[39] = 1;
                            for (i = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i < 256, 46, 1, 21), -41, 0, 21);i++) {
                                BitmapCov::branchBitmap[40] = 1;
                                rtb_Assignment1_o[i] = rtb_DataStoreRead1_l[i];
                            }
                            BitmapCov::branchBitmap[41] = 1;
                        }
                        else {
                            BitmapCov::branchBitmap[42] = 1;
                        }
                        rtb_Assignment1_o[rtb_ForIterator_o] = rtb_Switch1_f;
                        for (i = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i < 256, 48, 1, 22), -43, 0, 22);i++) {
                            BitmapCov::branchBitmap[43] = 1;
                            LANSwitch_DW->PortPoolF[i] = rtb_Assignment1_o[i];
                        }
                        BitmapCov::branchBitmap[44] = 1;
                    }
                    BitmapCov::branchBitmap[45] = 1;
                    rtb_Compare_np = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(Switch_m == 0, 50, 1, 23), -45, 0, 23));
                    if (rtb_Compare_np) {
                        BitmapCov::branchBitmap[46] = 1;
                        LANSwitch_B->Switch_p = 1;
                    }
                    else {
                        BitmapCov::branchBitmap[47] = 1;
                        int32_T rtb_Switch1_p;
                        boolean_T rtb_Compare_le;
                        rtb_Compare_le = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(Switch_m == 1, 52, 1, 24), -47, 0, 24));
                        if (rtb_Compare_le) {
                            BitmapCov::branchBitmap[48] = 1;
                            rtb_Switch1_p = 2;
                        }
                        else {
                            BitmapCov::branchBitmap[49] = 1;
                            int32_T rtb_Switch2_d;
                            boolean_T rtb_Compare_nr;
                            rtb_Compare_nr = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(Switch_m == 2, 54, 1, 25), -49, 0, 25));
                            if (rtb_Compare_nr) {
                                BitmapCov::branchBitmap[50] = 1;
                                rtb_Switch2_d = 3;
                            }
                            else {
                                BitmapCov::branchBitmap[51] = 1;
                                rtb_Switch2_d = 4;
                            }
                            rtb_Switch1_p = rtb_Switch2_d;
                        }
                        LANSwitch_B->Switch_p = rtb_Switch1_p;
                    }
                }
                else {
                    BitmapCov::branchBitmap[52] = 1;
                    rtb_Merge = -10002;
                }
                rtb_Merge1 = LANSwitch_B->Switch_p;
            }
            break;
        }
    case 10002:
        BitmapCov::branchBitmap[53] = 1;
        {
            boolean_T rtb_Compare_ck;
            rtb_Compare_ck = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(LANSwitch_U_PortId == 0, 56, 1, 26), -51, 0, 26));
            if (rtb_Compare_ck) {
                BitmapCov::branchBitmap[54] = 1;
                LANSwitch_Error(&rtb_Merge, &rtb_Merge1);
            }
            else {
                BitmapCov::branchBitmap[55] = 1;
                boolean_T rtb_AND;
                Switch_m = -1;
                Found_E = -1;
                LANSwitch_FindPortInPool(LANSwitch_U_PortId, &s43_iter, &Switch_m, LANSwitch_DW->PortPool, LANSwitch_DW->PortPoolF);
                for (Switch_m = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(Switch_m < 256, 58, 1, 27), -53, 0, 27);Switch_m++) {
                    BitmapCov::branchBitmap[56] = 1;
                    int32_T rtb_DataStoreRead1;
                    int32_T rtb_ForIterator_a;
                    boolean_T rtb_AND_e;
                    rtb_ForIterator_a = Switch_m;
                    for (i = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i < 256, 60, 1, 28), -55, 0, 28);i++) {
                        BitmapCov::branchBitmap[57] = 1;
                        rtb_DataStoreRead_n[i] = LANSwitch_DW->PortPool[i];
                        rtb_DataStoreRead2_c[i] = LANSwitch_DW->PortPoolF[i];
                    }
                    BitmapCov::branchBitmap[58] = 1;
                    int32_T rtb_Selector1_b;
                    int32_T rtb_Selector_a;
                    boolean_T rtb_AND1;
                    boolean_T rtb_Compare_ai;
                    boolean_T rtb_Compare_o5;
                    boolean_T rtb_Equal_c;
                    rtb_Selector_a = rtb_DataStoreRead_n[rtb_ForIterator_a];
                    rtb_Equal_c = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(LANSwitch_U_Arg1 == rtb_Selector_a, 62, 1, 29), -57, 0, 29));
                    rtb_Selector1_b = rtb_DataStoreRead2_c[rtb_ForIterator_a];
                    rtb_Compare_ai = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_Selector1_b == 1, 64, 1, 30), -59, 0, 30));
                    if (rtb_Equal_c) {
                        BitmapCov::branchBitmap[59] = 1;
                    }
                    else {
                        BitmapCov::branchBitmap[60] = 1;
                    }
                    if (rtb_Compare_ai) {
                        BitmapCov::branchBitmap[61] = 1;
                    }
                    else {
                        BitmapCov::branchBitmap[62] = 1;
                    }
                    rtb_AND1 = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_Equal_c, 66, 1, 31)&BitmapCov::CondAndMCDCRecord(rtb_Compare_ai, 68, 2, 31), -61, 0, 31));
                    rtb_DataStoreRead1 = Found_E;
                    rtb_Compare_o5 = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_DataStoreRead1 == -1, 70, 1, 32), -63, 0, 32));
                    if (rtb_AND1) {
                        BitmapCov::branchBitmap[63] = 1;
                    }
                    else {
                        BitmapCov::branchBitmap[64] = 1;
                    }
                    if (rtb_Compare_o5) {
                        BitmapCov::branchBitmap[65] = 1;
                    }
                    else {
                        BitmapCov::branchBitmap[66] = 1;
                    }
                    rtb_AND_e = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_AND1, 72, 1, 33)&BitmapCov::CondAndMCDCRecord(rtb_Compare_o5, 74, 2, 33), -65, 0, 33));
                    if (rtb_AND_e) {
                        BitmapCov::branchBitmap[67] = 1;
                        i = rtb_ForIterator_a;
                    }
                    else {
                        BitmapCov::branchBitmap[68] = 1;
                        i = rtb_DataStoreRead1;
                    }
                    Found_E = i;
                }
                BitmapCov::branchBitmap[69] = 1;
                boolean_T rtb_Compare_f;
                boolean_T rtb_Compare_i;
                rtb_Compare_f = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(s43_iter != -1, 76, 1, 34), -67, 0, 34));
                rtb_Compare_i = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i != -1, 78, 1, 35), -69, 0, 35));
                if (rtb_Compare_f) {
                    BitmapCov::branchBitmap[70] = 1;
                }
                else {
                    BitmapCov::branchBitmap[71] = 1;
                }
                if (rtb_Compare_i) {
                    BitmapCov::branchBitmap[72] = 1;
                }
                else {
                    BitmapCov::branchBitmap[73] = 1;
                }
                rtb_AND = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_Compare_f, 80, 1, 36)&BitmapCov::CondAndMCDCRecord(rtb_Compare_i, 82, 2, 36), -71, 0, 36));
                if (rtb_AND) {
                    BitmapCov::branchBitmap[74] = 1;
                    int32_T rtb_Subtract;
                    boolean_T rtb_Compare_nw;
                    rtb_Merge = LANSwitch_U_Arg1;
                    rtb_Subtract = LANSwitch_U_Arg3 - LANSwitch_U_Arg2;
                    rtb_Compare_nw = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_Subtract == 1, 84, 1, 37), -73, 0, 37));
                    if (rtb_Compare_nw) {
                        BitmapCov::branchBitmap[75] = 1;
                        LANSwitch_B->Switch_i = 101;
                    }
                    else {
                        BitmapCov::branchBitmap[76] = 1;
                        int32_T rtb_Switch1_l;
                        boolean_T rtb_Compare_cv;
                        rtb_Compare_cv = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_Subtract == 2, 86, 1, 38), -75, 0, 38));
                        if (rtb_Compare_cv) {
                            BitmapCov::branchBitmap[77] = 1;
                            rtb_Switch1_l = 102;
                        }
                        else {
                            BitmapCov::branchBitmap[78] = 1;
                            int32_T rtb_Switch2;
                            boolean_T rtb_Compare_bl;
                            rtb_Compare_bl = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_Subtract == 3, 88, 1, 39), -77, 0, 39));
                            if (rtb_Compare_bl) {
                                BitmapCov::branchBitmap[79] = 1;
                                rtb_Switch2 = 103;
                            }
                            else {
                                BitmapCov::branchBitmap[80] = 1;
                                int32_T rtb_Switch3;
                                boolean_T rtb_Compare_g;
                                rtb_Compare_g = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_Subtract == -1, 90, 1, 40), -79, 0, 40));
                                if (rtb_Compare_g) {
                                    BitmapCov::branchBitmap[81] = 1;
                                    rtb_Switch3 = -101;
                                }
                                else {
                                    BitmapCov::branchBitmap[82] = 1;
                                    int32_T rtb_Switch4;
                                    boolean_T rtb_Compare_hn;
                                    rtb_Compare_hn = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_Subtract == -2, 92, 1, 41), -81, 0, 41));
                                    if (rtb_Compare_hn) {
                                        BitmapCov::branchBitmap[83] = 1;
                                        rtb_Switch4 = -102;
                                    }
                                    else {
                                        BitmapCov::branchBitmap[84] = 1;
                                        int32_T rtb_Switch5;
                                        boolean_T rtb_Compare_pyv;
                                        rtb_Compare_pyv = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_Subtract == -3, 94, 1, 42), -83, 0, 42));
                                        if (rtb_Compare_pyv) {
                                            BitmapCov::branchBitmap[85] = 1;
                                            rtb_Switch5 = -103;
                                        }
                                        else {
                                            BitmapCov::branchBitmap[86] = 1;
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
                    BitmapCov::branchBitmap[87] = 1;
                    LANSwitch_Err(&rtb_Merge);
                }
                rtb_Merge1 = LANSwitch_B->Switch_i;
            }
            break;
        }
    case 10003:
        BitmapCov::branchBitmap[88] = 1;
        {
            boolean_T rtb_Compare_ct;
            rtb_Compare_ct = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(LANSwitch_U_PortId == 0, 96, 1, 43), -85, 0, 43));
            if (rtb_Compare_ct) {
                BitmapCov::branchBitmap[89] = 1;
                LANSwitch_Error(&rtb_Merge, &rtb_Merge1);
            }
            else {
                BitmapCov::branchBitmap[90] = 1;
                boolean_T rtb_Compare_b;
                Found_E = -1;
                LANSwitch_FindPortInPool(LANSwitch_U_PortId, &s43_iter, &Found_E, LANSwitch_DW->PortPool, LANSwitch_DW->PortPoolF);
                rtb_Compare_b = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(s43_iter != -1, 98, 1, 44), -87, 0, 44));
                if (rtb_Compare_b) {
                    BitmapCov::branchBitmap[91] = 1;
                    rtb_Merge = s43_iter;
                    rtb_Merge1 = 1;
                }
                else {
                    BitmapCov::branchBitmap[92] = 1;
                    rtb_Merge = -1;
                    rtb_Merge1 = -1;
                }
            }
            break;
        }
    case 10004:
        BitmapCov::branchBitmap[93] = 1;
        {
            boolean_T rtb_Compare_k;
            rtb_Compare_k = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(LANSwitch_U_PortId == 0, 100, 1, 45), -89, 0, 45));
            if (rtb_Compare_k) {
                BitmapCov::branchBitmap[94] = 1;
                LANSwitch_Error(&rtb_Merge, &rtb_Merge1);
            }
            else {
                BitmapCov::branchBitmap[95] = 1;
                uint8_T rtb_Compare;
                Found_E = -1;
                LANSwitch_FindPortInPool(LANSwitch_U_PortId, &rtb_Switch_l, &Found_E, LANSwitch_DW->PortPool, LANSwitch_DW->PortPoolF);
                rtb_Compare = (uint8_T)(BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_Switch_l == -1, 102, 1, 46), -91, 0, 46));
                if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_Compare != 0, 104, 1, 47), -93, 0, 47)) {
                    BitmapCov::branchBitmap[96] = 1;
                    LANSwitch_Err(&Found_E);
                }
                else {
                    BitmapCov::branchBitmap[97] = 1;
                    int32_T rtb_PortId;
                    rtb_PortId = LANSwitch_U_PortId;
                    for (Found_E = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(Found_E < 256, 106, 1, 48), -95, 0, 48);Found_E++) {
                        BitmapCov::branchBitmap[98] = 1;
                        int32_T rtb_ForIterator;
                        int32_T rtb_Switch;
                        int32_T rtb_Switch1;
                        boolean_T rtb_Equal;
                        rtb_ForIterator = Found_E;
                        for (i = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i < 256, 108, 1, 49), -97, 0, 49);i++) {
                            BitmapCov::branchBitmap[99] = 1;
                            rtb_DataStoreRead[i] = LANSwitch_DW->PortPool[i];
                        }
                        BitmapCov::branchBitmap[100] = 1;
                        rtb_Equal = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_PortId == rtb_ForIterator, 110, 1, 50), -99, 0, 50));
                        if (rtb_Equal) {
                            BitmapCov::branchBitmap[101] = 1;
                            rtb_Switch = 0;
                        }
                        else {
                            BitmapCov::branchBitmap[102] = 1;
                            int32_T rtb_Selector;
                            rtb_Selector = rtb_DataStoreRead[rtb_ForIterator];
                            rtb_Switch = rtb_Selector;
                        }
                        if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(Found_E == 0, 112, 1, 51), -101, 0, 51)) {
                            BitmapCov::branchBitmap[103] = 1;
                            for (i = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i < 256, 114, 1, 52), -103, 0, 52);i++) {
                                BitmapCov::branchBitmap[104] = 1;
                                rtb_Assignment[i] = rtb_DataStoreRead[i];
                            }
                            BitmapCov::branchBitmap[105] = 1;
                        }
                        else {
                            BitmapCov::branchBitmap[106] = 1;
                        }
                        rtb_Assignment[rtb_ForIterator] = rtb_Switch;
                        for (i = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i < 256, 116, 1, 53), -105, 0, 53);i++) {
                            BitmapCov::branchBitmap[107] = 1;
                            LANSwitch_DW->PortPool[i] = rtb_Assignment[i];
                            rtb_DataStoreRead2[i] = LANSwitch_DW->PortPoolF[i];
                        }
                        BitmapCov::branchBitmap[108] = 1;
                        if (rtb_Equal) {
                            BitmapCov::branchBitmap[109] = 1;
                            rtb_Switch1 = 0;
                        }
                        else {
                            BitmapCov::branchBitmap[110] = 1;
                            int32_T rtb_Selector1;
                            rtb_Selector1 = rtb_DataStoreRead2[rtb_ForIterator];
                            rtb_Switch1 = rtb_Selector1;
                        }
                        if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(Found_E == 0, 118, 1, 54), -107, 0, 54)) {
                            BitmapCov::branchBitmap[111] = 1;
                            for (i = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i < 256, 120, 1, 55), -109, 0, 55);i++) {
                                BitmapCov::branchBitmap[112] = 1;
                                rtb_Assignment1[i] = rtb_DataStoreRead2[i];
                            }
                            BitmapCov::branchBitmap[113] = 1;
                        }
                        else {
                            BitmapCov::branchBitmap[114] = 1;
                        }
                        rtb_Assignment1[rtb_ForIterator] = rtb_Switch1;
                        for (i = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i < 256, 122, 1, 56), -111, 0, 56);i++) {
                            BitmapCov::branchBitmap[115] = 1;
                            LANSwitch_DW->PortPoolF[i] = rtb_Assignment1[i];
                        }
                        BitmapCov::branchBitmap[116] = 1;
                    }
                    BitmapCov::branchBitmap[117] = 1;
                    Found_E = rtb_PortId;
                    LANSwitch_B->OutportBufferForMSG = LANSwitch_ConstB.Constant;
                }
                rtb_Merge1 = LANSwitch_B->OutportBufferForMSG;
                rtb_Merge = Found_E;
            }
            break;
        }
    default:
        BitmapCov::branchBitmap[118] = 1;
        {
            rtb_Merge = -10000;
            rtb_Merge1 = 0;
            break;
        }
    }
    *LANSwitch_Y_Result = rtb_Merge;
    *LANSwitch_Y_MSG = rtb_Merge1;
}
/* Init function of "LANSwitch" */
void LANSwitch_init(RT_MODEL_LANSwitch_T* LANSwitch_M, int32_T* LANSwitch_U_PortId, int32_T* LANSwitch_U_CMD, int32_T* LANSwitch_U_Arg1, int32_T* LANSwitch_U_Arg2, int32_T* LANSwitch_U_Arg3, int32_T* LANSwitch_Y_Result, int32_T* LANSwitch_Y_MSG) {
    /* Calculate code of  */
    BitmapCov::munitBitmap[1] = 1;
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
/* Normal function of  */
void LANSwitch_Error(int32_T* rty_Result, int32_T* rty_MSG) {
    /* Calculate code of  */
    BitmapCov::munitBitmap[2] = 1;
    *rty_Result = -10001;
    *rty_MSG = 0;
}
/* Normal function of  */
void LANSwitch_FindPortInPool(int32_T rtu_PortId, int32_T* rty_Out1, int32_T* rtd_Found_P_e, int32_T rtd_PortPool[256], int32_T rtd_PortPoolF[256]) {
    /* Calculate code of  */
    BitmapCov::munitBitmap[3] = 1;
    int32_T rtb_DataStoreRead2_pj[256];
    int32_T rtb_DataStoreRead_j[256];
    int32_T i;
    for (i = 0;BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(i < 256, 124, 1, 57), -113, 0, 57);i++) {
        BitmapCov::branchBitmap[119] = 1;
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
        rtb_Equal_n = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtu_PortId == rtb_Selector_o, 126, 1, 58), -115, 0, 58));
        rtb_Selector1_l = rtb_DataStoreRead2_pj[rtb_ForIterator_e];
        rtb_Compare_n1 = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_Selector1_l == 1, 128, 1, 59), -117, 0, 59));
        if (rtb_Equal_n) {
            BitmapCov::branchBitmap[120] = 1;
        }
        else {
            BitmapCov::branchBitmap[121] = 1;
        }
        if (rtb_Compare_n1) {
            BitmapCov::branchBitmap[122] = 1;
        }
        else {
            BitmapCov::branchBitmap[123] = 1;
        }
        rtb_AND1_e = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_Equal_n, 130, 1, 60)&BitmapCov::CondAndMCDCRecord(rtb_Compare_n1, 132, 2, 60), -119, 0, 60));
        rtb_DataStoreRead1_cy = *rtd_Found_P_e;
        rtb_Compare_cc = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_DataStoreRead1_cy == -1, 134, 1, 61), -121, 0, 61));
        if (rtb_AND1_e) {
            BitmapCov::branchBitmap[124] = 1;
        }
        else {
            BitmapCov::branchBitmap[125] = 1;
        }
        if (rtb_Compare_cc) {
            BitmapCov::branchBitmap[126] = 1;
        }
        else {
            BitmapCov::branchBitmap[127] = 1;
        }
        rtb_AND_g = (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(rtb_AND1_e, 136, 1, 62)&BitmapCov::CondAndMCDCRecord(rtb_Compare_cc, 138, 2, 62), -123, 0, 62));
        if (rtb_AND_g) {
            BitmapCov::branchBitmap[128] = 1;
            *rty_Out1 = rtb_ForIterator_e;
        }
        else {
            BitmapCov::branchBitmap[129] = 1;
            *rty_Out1 = rtb_DataStoreRead1_cy;
        }
        *rtd_Found_P_e = *rty_Out1;
    }
    BitmapCov::branchBitmap[130] = 1;
}
/* Normal function of  */
void LANSwitch_Err(int32_T* rty_Result) {
    /* Calculate code of  */
    BitmapCov::munitBitmap[4] = 1;
    *rty_Result = -10003;
}