#include "LANSwitch.h"
#include "rtwtypes.h"
#include "LANSwitch_private.h"
#include <string.h>

void LANSwitch_Error(int32_T *rty_Result, int32_T *rty_MSG)
{
  *rty_Result = -10001;
  *rty_MSG = 0;
}

void LANSwitch_FindPortInPool(int32_T rtu_PortId, int32_T *rty_Out1, int32_T
  *rtd_Found_P_e, const int32_T rtd_PortPool[256], const int32_T rtd_PortPoolF
  [256], int32_T rtp_POOL_SIZE)
{
  int32_T rtb_DataStoreRead2_h[256];
  int32_T rtb_DataStoreRead_j[256];
  int32_T i;
  if (rtp_POOL_SIZE > 0) {
    for (i = 0; i < 256; i++) {
      rtb_DataStoreRead_j[i] = rtd_PortPool[i];
      rtb_DataStoreRead2_h[i] = rtd_PortPoolF[i];
    }
  }

  for (i = 0; i < rtp_POOL_SIZE; i++) {
    int32_T rtb_DataStoreRead1_cy;
    int32_T rtb_ForIterator_e;
    int32_T rtb_Selector1_l;
    int32_T rtb_Selector_o;
    boolean_T rtb_AND1_e;
    boolean_T rtb_AND_g;
    boolean_T rtb_Compare_cc;
    boolean_T rtb_Compare_n1;
    boolean_T rtb_Equal_n;
    rtb_ForIterator_e = i;
    rtb_Selector_o = rtb_DataStoreRead_j[rtb_ForIterator_e];
    rtb_Equal_n = (rtu_PortId == rtb_Selector_o);
    rtb_Selector1_l = rtb_DataStoreRead2_h[rtb_ForIterator_e];
    rtb_Compare_n1 = (rtb_Selector1_l == 1);
    rtb_AND1_e = (rtb_Equal_n && rtb_Compare_n1);
    rtb_DataStoreRead1_cy = *rtd_Found_P_e;
    rtb_Compare_cc = (rtb_DataStoreRead1_cy == -1);
    rtb_AND_g = (rtb_AND1_e && rtb_Compare_cc);
    if (rtb_AND_g) {
      *rty_Out1 = rtb_ForIterator_e;
    } else {
      *rty_Out1 = rtb_DataStoreRead1_cy;
    }

    *rtd_Found_P_e = *rty_Out1;
  }
}

void LANSwitch_Err(int32_T *rty_Result)
{
  *rty_Result = -10003;
}

void LANSwitch_step(RT_MODEL_LANSwitch_T *const LANSwitch_M, int32_T
                    LANSwitch_U_PortId, int32_T LANSwitch_U_CMD, int32_T
                    LANSwitch_U_Arg1, int32_T LANSwitch_U_Arg2, int32_T
                    LANSwitch_U_Arg3, int32_T *LANSwitch_Y_Result, int32_T
                    *LANSwitch_Y_MSG)
{
  B_LANSwitch_T *LANSwitch_B = LANSwitch_M->blockIO;
  DW_LANSwitch_T *LANSwitch_DW = LANSwitch_M->dwork;
  int32_T rtb_Assignment[256];
  int32_T rtb_Assignment1[256];
  int32_T rtb_Assignment1_o[256];
  int32_T rtb_Assignment_h[256];
  int32_T rtb_DataStoreRead[256];
  int32_T rtb_DataStoreRead1_l[256];
  int32_T rtb_DataStoreRead2[256];
  int32_T rtb_DataStoreRead2_f[256];
  int32_T rtb_DataStoreRead2_m[256];
  int32_T rtb_DataStoreRead2_p[256];
  int32_T rtb_DataStoreRead_a[256];
  int32_T rtb_DataStoreRead_e[256];
  int32_T rtb_DataStoreRead_l[256];
  int32_T Found_E;
  int32_T Switch_m;
  int32_T i;
  int32_T rtb_Merge;
  int32_T rtb_Merge1;
  int32_T rtb_Switch_l;
  int32_T s44_iter;
  boolean_T Switch_l4;
  switch (LANSwitch_U_CMD) {
   case 10001:
    {
      boolean_T rtb_Compare_c;
      rtb_Compare_c = (LANSwitch_U_PortId == 0);
      if (rtb_Compare_c) {
        LANSwitch_Error(&rtb_Merge, &rtb_Merge1);
      } else {
        boolean_T Found;
        boolean_T rtb_AND_k;
        Found = false;
        Found_E = -1;
        for (s44_iter = 0; s44_iter < 256; s44_iter++) {
          int32_T rtb_DataStoreRead1_f;
          int32_T rtb_ForIterator_b;
          int32_T rtb_ForIterator_oy;
          boolean_T rtb_AND_d;
          boolean_T rtb_AND_pv;
          rtb_ForIterator_oy = s44_iter;
          for (i = 0; i < 256; i++) {
            rtb_DataStoreRead_l[i] = LANSwitch_DW->PortPool[i];
            rtb_DataStoreRead2_p[i] = LANSwitch_DW->PortPoolF[i];
          }

          int32_T rtb_Selector1_g;
          int32_T rtb_Selector_b;
          boolean_T rtb_Compare_ff;
          boolean_T rtb_Equal_f3;
          rtb_Selector_b = rtb_DataStoreRead_l[rtb_ForIterator_oy];
          rtb_Equal_f3 = (rtb_Selector_b == LANSwitch_U_PortId);
          rtb_Selector1_g = rtb_DataStoreRead2_p[rtb_ForIterator_oy];
          rtb_Compare_ff = (rtb_Selector1_g == 1);
          rtb_AND_d = (rtb_Equal_f3 && rtb_Compare_ff);
          if (rtb_AND_d) {
            Switch_l4 = true;
          } else {
            boolean_T rtb_DataStoreRead1_e;
            rtb_DataStoreRead1_e = Found;
            Switch_l4 = rtb_DataStoreRead1_e;
          }

          Found = Switch_l4;
          rtb_ForIterator_b = s44_iter;
          for (i = 0; i < 256; i++) {
            rtb_DataStoreRead2_m[i] = LANSwitch_DW->PortPoolF[i];
          }

          int32_T rtb_Selector1_n;
          boolean_T rtb_Compare_di;
          boolean_T rtb_Compare_n;
          rtb_Selector1_n = rtb_DataStoreRead2_m[rtb_ForIterator_b];
          rtb_Compare_di = (rtb_Selector1_n == 0);
          rtb_DataStoreRead1_f = Found_E;
          rtb_Compare_n = (rtb_DataStoreRead1_f == -1);
          rtb_AND_pv = (rtb_Compare_di && rtb_Compare_n);
          if (rtb_AND_pv) {
            Switch_m = rtb_ForIterator_b;
          } else {
            Switch_m = rtb_DataStoreRead1_f;
          }

          Found_E = Switch_m;
        }

        boolean_T rtb_Compare_a;
        boolean_T rtb_Compare_mn;
        rtb_Compare_mn = !Switch_l4;
        rtb_Compare_a = (Switch_m != -1);
        rtb_AND_k = (rtb_Compare_mn && rtb_Compare_a);
        if (rtb_AND_k) {
          boolean_T rtb_Compare_lc;
          rtb_Merge = 1;
          for (Found_E = 0; Found_E < 256; Found_E++) {
            int32_T rtb_ForIterator_o;
            int32_T rtb_Switch1_f;
            int32_T rtb_Switch_c;
            boolean_T rtb_Equal_m;
            rtb_ForIterator_o = Found_E;
            for (i = 0; i < 256; i++) {
              rtb_DataStoreRead_e[i] = LANSwitch_DW->PortPool[i];
            }

            rtb_Equal_m = (Switch_m == rtb_ForIterator_o);
            if (rtb_Equal_m) {
              rtb_Switch_c = LANSwitch_U_PortId;
            } else {
              int32_T rtb_Selector_i;
              rtb_Selector_i = rtb_DataStoreRead_e[rtb_ForIterator_o];
              rtb_Switch_c = rtb_Selector_i;
            }

            if (Found_E == 0) {
              for (i = 0; i < 256; i++) {
                rtb_Assignment_h[i] = rtb_DataStoreRead_e[i];
              }
            }

            rtb_Assignment_h[rtb_ForIterator_o] = rtb_Switch_c;
            for (i = 0; i < 256; i++) {
              LANSwitch_DW->PortPool[i] = rtb_Assignment_h[i];
              rtb_DataStoreRead1_l[i] = LANSwitch_DW->PortPoolF[i];
            }

            if (rtb_Equal_m) {
              rtb_Switch1_f = 1;
            } else {
              int32_T rtb_Selector1_c;
              rtb_Selector1_c = rtb_DataStoreRead1_l[rtb_ForIterator_o];
              rtb_Switch1_f = rtb_Selector1_c;
            }

            if (Found_E == 0) {
              for (i = 0; i < 256; i++) {
                rtb_Assignment1_o[i] = rtb_DataStoreRead1_l[i];
              }
            }

            rtb_Assignment1_o[rtb_ForIterator_o] = rtb_Switch1_f;
            for (i = 0; i < 256; i++) {
              LANSwitch_DW->PortPoolF[i] = rtb_Assignment1_o[i];
            }
          }

          rtb_Compare_lc = (Switch_m == 0);
          if (rtb_Compare_lc) {
            LANSwitch_B->Switch_p = 1;
          } else {
            int32_T rtb_Switch1_p;
            boolean_T rtb_Compare_k0;
            rtb_Compare_k0 = (Switch_m == 1);
            if (rtb_Compare_k0) {
              rtb_Switch1_p = 2;
            } else {
              int32_T rtb_Switch2_c;
              boolean_T rtb_Compare_cl0;
              rtb_Compare_cl0 = (Switch_m == 2);
              if (rtb_Compare_cl0) {
                rtb_Switch2_c = 3;
              } else {
                rtb_Switch2_c = 4;
              }

              rtb_Switch1_p = rtb_Switch2_c;
            }

            LANSwitch_B->Switch_p = rtb_Switch1_p;
          }
        } else {
          rtb_Merge = -10004;
        }

        rtb_Merge1 = LANSwitch_B->Switch_p;
      }
    }
    break;

   case 10002:
    {
      boolean_T rtb_Compare_ck;
      rtb_Compare_ck = (LANSwitch_U_PortId == 0);
      if (rtb_Compare_ck) {
        LANSwitch_Error(&rtb_Merge, &rtb_Merge1);
      } else {
        boolean_T rtb_AND;
        s44_iter = -1;
        Found_E = -1;
        LANSwitch_FindPortInPool(LANSwitch_U_PortId, &LANSwitch_B->Switch_l,
          &s44_iter, LANSwitch_DW->PortPool, LANSwitch_DW->PortPoolF, 256);
        for (s44_iter = 0; s44_iter < 256; s44_iter++) {
          int32_T rtb_DataStoreRead1;
          int32_T rtb_ForIterator_d;
          boolean_T rtb_AND_m;
          rtb_ForIterator_d = s44_iter;
          for (i = 0; i < 256; i++) {
            rtb_DataStoreRead_a[i] = LANSwitch_DW->PortPool[i];
            rtb_DataStoreRead2_f[i] = LANSwitch_DW->PortPoolF[i];
          }

          int32_T rtb_Selector1_oh;
          int32_T rtb_Selector_g;
          boolean_T rtb_AND1;
          boolean_T rtb_Compare_bk;
          boolean_T rtb_Compare_d;
          boolean_T rtb_Equal_l;
          rtb_Selector_g = rtb_DataStoreRead_a[rtb_ForIterator_d];
          rtb_Equal_l = (LANSwitch_U_Arg1 == rtb_Selector_g);
          rtb_Selector1_oh = rtb_DataStoreRead2_f[rtb_ForIterator_d];
          rtb_Compare_d = (rtb_Selector1_oh == 1);
          rtb_AND1 = (rtb_Equal_l && rtb_Compare_d);
          rtb_DataStoreRead1 = Found_E;
          rtb_Compare_bk = (rtb_DataStoreRead1 == -1);
          rtb_AND_m = (rtb_AND1 && rtb_Compare_bk);
          if (rtb_AND_m) {
            i = rtb_ForIterator_d;
          } else {
            i = rtb_DataStoreRead1;
          }

          Found_E = i;
        }

        boolean_T rtb_Compare_f;
        boolean_T rtb_Compare_i;
        rtb_Compare_f = (LANSwitch_B->Switch_l != -1);
        rtb_Compare_i = (i != -1);
        rtb_AND = (rtb_Compare_f && rtb_Compare_i);
        if (rtb_AND) {
          int32_T rtb_Subtract_j;
          boolean_T rtb_Compare_g;
          rtb_Merge = LANSwitch_U_Arg1;
          rtb_Subtract_j = LANSwitch_U_Arg3 - LANSwitch_U_Arg2;
          rtb_Compare_g = (rtb_Subtract_j == 1);
          if (rtb_Compare_g) {
            LANSwitch_B->Switch_i = 101;
          } else {
            int32_T rtb_Switch1_l;
            boolean_T rtb_Compare_is;
            rtb_Compare_is = (rtb_Subtract_j == 2);
            if (rtb_Compare_is) {
              rtb_Switch1_l = 102;
            } else {
              int32_T rtb_Switch2_a;
              boolean_T rtb_Compare_l;
              rtb_Compare_l = (rtb_Subtract_j == 3);
              if (rtb_Compare_l) {
                rtb_Switch2_a = 103;
              } else {
                int32_T rtb_Switch3_j;
                boolean_T rtb_Compare_gf;
                rtb_Compare_gf = (rtb_Subtract_j == -1);
                if (rtb_Compare_gf) {
                  rtb_Switch3_j = -101;
                } else {
                  int32_T rtb_Switch4;
                  boolean_T rtb_Compare_p;
                  rtb_Compare_p = (rtb_Subtract_j == -2);
                  if (rtb_Compare_p) {
                    rtb_Switch4 = -102;
                  } else {
                    int32_T rtb_Switch5;
                    boolean_T rtb_Compare_pm;
                    rtb_Compare_pm = (rtb_Subtract_j == -3);
                    if (rtb_Compare_pm) {
                      rtb_Switch5 = -103;
                    } else {
                      rtb_Switch5 = rtb_Subtract_j;
                    }

                    rtb_Switch4 = rtb_Switch5;
                  }

                  rtb_Switch3_j = rtb_Switch4;
                }

                rtb_Switch2_a = rtb_Switch3_j;
              }

              rtb_Switch1_l = rtb_Switch2_a;
            }

            LANSwitch_B->Switch_i = rtb_Switch1_l;
          }
        } else {
          LANSwitch_Err(&rtb_Merge);
        }

        rtb_Merge1 = LANSwitch_B->Switch_i;
      }
    }
    break;

   case 10003:
    {
      boolean_T rtb_Compare_ct;
      rtb_Compare_ct = (LANSwitch_U_PortId == 0);
      if (rtb_Compare_ct) {
        LANSwitch_Error(&rtb_Merge, &rtb_Merge1);
      } else {
        boolean_T rtb_Compare_b;
        Found_E = -1;
        LANSwitch_FindPortInPool(LANSwitch_U_PortId, &LANSwitch_B->Switch,
          &Found_E, LANSwitch_DW->PortPool, LANSwitch_DW->PortPoolF, 256);
        rtb_Compare_b = (LANSwitch_B->Switch != -1);
        if (rtb_Compare_b) {
          rtb_Merge = LANSwitch_B->Switch;
          rtb_Merge1 = 1;
        } else {
          rtb_Merge = -1;
          rtb_Merge1 = -1;
        }
      }
    }
    break;

   case 10004:
    {
      boolean_T rtb_Compare_k;
      rtb_Compare_k = (LANSwitch_U_PortId == 0);
      if (rtb_Compare_k) {
        LANSwitch_Error(&rtb_Merge, &rtb_Merge1);
      } else {
        uint8_T rtb_Compare;
        Found_E = -1;
        LANSwitch_FindPortInPool(LANSwitch_U_PortId, &rtb_Switch_l, &Found_E,
          LANSwitch_DW->PortPool, LANSwitch_DW->PortPoolF, 256);
        rtb_Compare = (uint8_T)(rtb_Switch_l == -1);
        if (rtb_Compare != 0) {
          LANSwitch_Err(&Found_E);
        } else {
          int32_T rtb_PortId;
          rtb_PortId = LANSwitch_U_PortId;
          for (Found_E = 0; Found_E < 256; Found_E++) {
            int32_T rtb_ForIterator;
            int32_T rtb_Switch;
            int32_T rtb_Switch1;
            boolean_T rtb_Equal;
            rtb_ForIterator = Found_E;
            for (i = 0; i < 256; i++) {
              rtb_DataStoreRead[i] = LANSwitch_DW->PortPool[i];
            }

            rtb_Equal = (rtb_PortId == rtb_ForIterator);
            if (rtb_Equal) {
              rtb_Switch = 0;
            } else {
              int32_T rtb_Selector;
              rtb_Selector = rtb_DataStoreRead[rtb_ForIterator];
              rtb_Switch = rtb_Selector;
            }

            if (Found_E == 0) {
              for (i = 0; i < 256; i++) {
                rtb_Assignment[i] = rtb_DataStoreRead[i];
              }
            }

            rtb_Assignment[rtb_ForIterator] = rtb_Switch;
            for (i = 0; i < 256; i++) {
              LANSwitch_DW->PortPool[i] = rtb_Assignment[i];
              rtb_DataStoreRead2[i] = LANSwitch_DW->PortPoolF[i];
            }

            if (rtb_Equal) {
              rtb_Switch1 = 0;
            } else {
              int32_T rtb_Selector1;
              rtb_Selector1 = rtb_DataStoreRead2[rtb_ForIterator];
              rtb_Switch1 = rtb_Selector1;
            }

            if (Found_E == 0) {
              for (i = 0; i < 256; i++) {
                rtb_Assignment1[i] = rtb_DataStoreRead2[i];
              }
            }

            rtb_Assignment1[rtb_ForIterator] = rtb_Switch1;
            for (i = 0; i < 256; i++) {
              LANSwitch_DW->PortPoolF[i] = rtb_Assignment1[i];
            }
          }

          Found_E = rtb_PortId;
          LANSwitch_B->OutportBufferForMSG = LANSwitch_ConstB.Constant;
        }

        rtb_Merge1 = LANSwitch_B->OutportBufferForMSG;
        rtb_Merge = Found_E;
      }
    }
    break;

   default:
    rtb_Merge = -10002;
    rtb_Merge1 = 0;
    break;
  }

  *LANSwitch_Y_Result = rtb_Merge;
  *LANSwitch_Y_MSG = rtb_Merge1;
}

void LANSwitch_initialize(RT_MODEL_LANSwitch_T *const LANSwitch_M, int32_T
  *LANSwitch_U_PortId, int32_T *LANSwitch_U_CMD, int32_T *LANSwitch_U_Arg1,
  int32_T *LANSwitch_U_Arg2, int32_T *LANSwitch_U_Arg3, int32_T
  *LANSwitch_Y_Result, int32_T *LANSwitch_Y_MSG)
{
  B_LANSwitch_T *LANSwitch_B = LANSwitch_M->blockIO;
  DW_LANSwitch_T *LANSwitch_DW = LANSwitch_M->dwork;
  (void) memset(((void *) LANSwitch_B), 0,
                sizeof(B_LANSwitch_T));
  (void) memset((void *)LANSwitch_DW, 0,
                sizeof(DW_LANSwitch_T));
  *LANSwitch_U_PortId = 0;
  *LANSwitch_U_CMD = 0;
  *LANSwitch_U_Arg1 = 0;
  *LANSwitch_U_Arg2 = 0;
  *LANSwitch_U_Arg3 = 0;
  *LANSwitch_Y_Result = 0;
  *LANSwitch_Y_MSG = 0;
  LANSwitch_B->OutportBufferForMSG = LANSwitch_ConstB.Constant;
}

void LANSwitch_terminate(RT_MODEL_LANSwitch_T *const LANSwitch_M)
{
  UNUSED_PARAMETER(LANSwitch_M);
}
