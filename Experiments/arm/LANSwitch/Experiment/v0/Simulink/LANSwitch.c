#include "LANSwitch.h"
#include "rtwtypes.h"
#include "LANSwitch_private.h"
#include <string.h>

void LANSwitch_Error(int32_T *rty_Result, int32_T *rty_MSG)
{
  *rty_Result = -10001;
  *rty_MSG = 0;
}

void LANSwitch_Err(int32_T *rty_Result)
{
  *rty_Result = -10003;
}

void LANSwitch_FindPortInPool(int32_T rtu_PortId, int32_T *rty_Out1, int32_T
  *rtd_Found_P_d, const int32_T rtd_PortPool[256], const int32_T rtd_PortPoolF
  [256], int32_T rtp_POOL_SIZE)
{
  int32_T rtb_DataStoreRead2_g[256];
  int32_T rtb_DataStoreRead_n[256];
  int32_T i;
  if (rtp_POOL_SIZE > 0) {
    for (i = 0; i < 256; i++) {
      rtb_DataStoreRead_n[i] = rtd_PortPool[i];
      rtb_DataStoreRead2_g[i] = rtd_PortPoolF[i];
    }
  }

  for (i = 0; i < rtp_POOL_SIZE; i++) {
    int32_T rtb_DataStoreRead1_j;
    int32_T rtb_ForIterator_a;
    int32_T rtb_Selector1_m;
    int32_T rtb_Selector_g;
    boolean_T rtb_AND1_f;
    boolean_T rtb_AND_d;
    boolean_T rtb_Compare_hp;
    boolean_T rtb_Compare_o3;
    boolean_T rtb_Equal_b;
    rtb_ForIterator_a = i;
    rtb_Selector_g = rtb_DataStoreRead_n[rtb_ForIterator_a];
    rtb_Equal_b = (rtu_PortId == rtb_Selector_g);
    rtb_Selector1_m = rtb_DataStoreRead2_g[rtb_ForIterator_a];
    rtb_Compare_hp = (rtb_Selector1_m == 1);
    rtb_AND1_f = (rtb_Equal_b && rtb_Compare_hp);
    rtb_DataStoreRead1_j = *rtd_Found_P_d;
    rtb_Compare_o3 = (rtb_DataStoreRead1_j == -1);
    rtb_AND_d = (rtb_AND1_f && rtb_Compare_o3);
    if (rtb_AND_d) {
      *rty_Out1 = rtb_ForIterator_a;
    } else {
      *rty_Out1 = rtb_DataStoreRead1_j;
    }

    *rtd_Found_P_d = *rty_Out1;
  }
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
  int32_T rtb_DataStoreRead1_e[256];
  int32_T rtb_DataStoreRead2[256];
  int32_T rtb_DataStoreRead2_e[256];
  int32_T rtb_DataStoreRead2_i[256];
  int32_T rtb_DataStoreRead2_i5[256];
  int32_T rtb_DataStoreRead2_p[256];
  int32_T rtb_DataStoreRead_a[256];
  int32_T rtb_DataStoreRead_e[256];
  int32_T rtb_DataStoreRead_l[256];
  int32_T rtb_DataStoreRead_o[256];
  int32_T Found_E;
  int32_T Switch_h;
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
        boolean_T rtb_AND_o;
        Found = false;
        Found_E = -1;
        for (s44_iter = 0; s44_iter < 256; s44_iter++) {
          int32_T rtb_DataStoreRead1_m;
          int32_T rtb_ForIterator_oy;
          int32_T rtb_ForIterator_p;
          boolean_T rtb_AND_c;
          boolean_T rtb_AND_m;
          rtb_ForIterator_oy = s44_iter;
          for (i = 0; i < 256; i++) {
            rtb_DataStoreRead_l[i] = LANSwitch_DW->PortPool[i];
            rtb_DataStoreRead2_i5[i] = LANSwitch_DW->PortPoolF[i];
          }

          int32_T rtb_Selector1_f;
          int32_T rtb_Selector_mt;
          boolean_T rtb_Compare_f4;
          boolean_T rtb_Equal_f3;
          rtb_Selector_mt = rtb_DataStoreRead_l[rtb_ForIterator_oy];
          rtb_Equal_f3 = (rtb_Selector_mt == LANSwitch_U_PortId);
          rtb_Selector1_f = rtb_DataStoreRead2_i5[rtb_ForIterator_oy];
          rtb_Compare_f4 = (rtb_Selector1_f == 1);
          rtb_AND_m = (rtb_Equal_f3 && rtb_Compare_f4);
          if (rtb_AND_m) {
            Switch_l4 = true;
          } else {
            boolean_T rtb_DataStoreRead1_k;
            rtb_DataStoreRead1_k = Found;
            Switch_l4 = rtb_DataStoreRead1_k;
          }

          Found = Switch_l4;
          rtb_ForIterator_p = s44_iter;
          for (i = 0; i < 256; i++) {
            rtb_DataStoreRead2_p[i] = LANSwitch_DW->PortPoolF[i];
          }

          int32_T rtb_Selector1_lc;
          boolean_T rtb_Compare_da;
          boolean_T rtb_Compare_o5;
          rtb_Selector1_lc = rtb_DataStoreRead2_p[rtb_ForIterator_p];
          rtb_Compare_da = (rtb_Selector1_lc == 0);
          rtb_DataStoreRead1_m = Found_E;
          rtb_Compare_o5 = (rtb_DataStoreRead1_m == -1);
          rtb_AND_c = (rtb_Compare_da && rtb_Compare_o5);
          if (rtb_AND_c) {
            Switch_m = rtb_ForIterator_p;
          } else {
            Switch_m = rtb_DataStoreRead1_m;
          }

          Found_E = Switch_m;
        }

        boolean_T rtb_Compare_a;
        boolean_T rtb_Compare_aq;
        rtb_Compare_aq = !Switch_l4;
        rtb_Compare_a = (Switch_m != -1);
        rtb_AND_o = (rtb_Compare_aq && rtb_Compare_a);
        if (rtb_AND_o) {
          boolean_T rtb_Compare_o1;
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
              rtb_DataStoreRead1_e[i] = LANSwitch_DW->PortPoolF[i];
            }

            if (rtb_Equal_m) {
              rtb_Switch1_f = 1;
            } else {
              int32_T rtb_Selector1_c;
              rtb_Selector1_c = rtb_DataStoreRead1_e[rtb_ForIterator_o];
              rtb_Switch1_f = rtb_Selector1_c;
            }

            if (Found_E == 0) {
              for (i = 0; i < 256; i++) {
                rtb_Assignment1_o[i] = rtb_DataStoreRead1_e[i];
              }
            }

            rtb_Assignment1_o[rtb_ForIterator_o] = rtb_Switch1_f;
            for (i = 0; i < 256; i++) {
              LANSwitch_DW->PortPoolF[i] = rtb_Assignment1_o[i];
            }
          }

          rtb_Compare_o1 = (Switch_m == 0);
          if (rtb_Compare_o1) {
            LANSwitch_B->Switch_p = 1;
          } else {
            int32_T rtb_Switch1_p;
            boolean_T rtb_Compare_g4;
            rtb_Compare_g4 = (Switch_m == 1);
            if (rtb_Compare_g4) {
              rtb_Switch1_p = 2;
            } else {
              int32_T rtb_Switch2_c;
              boolean_T rtb_Compare_i;
              rtb_Compare_i = (Switch_m == 2);
              if (rtb_Compare_i) {
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
        for (Switch_m = 0; Switch_m < 256; Switch_m++) {
          int32_T rtb_DataStoreRead1;
          int32_T rtb_DataStoreRead1_bq;
          int32_T rtb_ForIterator_gc;
          int32_T rtb_ForIterator_id;
          int32_T rtb_Selector1_j;
          int32_T rtb_Selector_g;
          boolean_T rtb_AND1;
          boolean_T rtb_AND_j;
          boolean_T rtb_AND_l;
          boolean_T rtb_Compare_e;
          boolean_T rtb_Compare_f;
          boolean_T rtb_Compare_fx;
          boolean_T rtb_Equal_o;
          rtb_ForIterator_id = Switch_m;
          rtb_DataStoreRead1_bq = s44_iter;
          rtb_Compare_fx = (rtb_DataStoreRead1_bq == -1);
          for (i = 0; i < 256; i++) {
            rtb_DataStoreRead2_e[i] = LANSwitch_DW->PortPoolF[i];
            rtb_DataStoreRead_o[i] = LANSwitch_DW->PortPool[i];
            rtb_DataStoreRead2_i[i] = LANSwitch_DW->PortPoolF[i];
            rtb_DataStoreRead_a[i] = LANSwitch_DW->PortPool[i];
          }

          int32_T rtb_Selector1_lg;
          int32_T rtb_Selector_f;
          boolean_T rtb_AND1_g;
          boolean_T rtb_Compare_cw;
          boolean_T rtb_Equal_b;
          rtb_Selector1_lg = rtb_DataStoreRead2_e[rtb_ForIterator_id];
          rtb_Selector_f = rtb_DataStoreRead_o[rtb_ForIterator_id];
          rtb_Equal_b = (LANSwitch_U_PortId == rtb_Selector_f);
          rtb_Compare_cw = (rtb_Selector1_lg == 1);
          rtb_AND1_g = (rtb_Equal_b && rtb_Compare_cw);
          rtb_AND_j = (rtb_AND1_g && rtb_Compare_fx);
          if (rtb_AND_j) {
            i = rtb_ForIterator_id;
          } else {
            i = rtb_DataStoreRead1_bq;
          }

          s44_iter = i;
          rtb_ForIterator_gc = Switch_m;
          rtb_Selector1_j = rtb_DataStoreRead2_i[rtb_ForIterator_gc];
          rtb_Selector_g = rtb_DataStoreRead_a[rtb_ForIterator_gc];
          rtb_Equal_o = (LANSwitch_U_Arg1 == rtb_Selector_g);
          rtb_Compare_e = (rtb_Selector1_j == 1);
          rtb_AND1 = (rtb_Equal_o && rtb_Compare_e);
          rtb_DataStoreRead1 = Found_E;
          rtb_Compare_f = (rtb_DataStoreRead1 == -1);
          rtb_AND_l = (rtb_AND1 && rtb_Compare_f);
          if (rtb_AND_l) {
            Switch_h = rtb_ForIterator_gc;
          } else {
            Switch_h = rtb_DataStoreRead1;
          }

          Found_E = Switch_h;
        }

        boolean_T rtb_Compare_a5;
        boolean_T rtb_Compare_h;
        rtb_Compare_a5 = (i != -1);
        rtb_Compare_h = (Switch_h != -1);
        rtb_AND = (rtb_Compare_a5 && rtb_Compare_h);
        if (rtb_AND) {
          int32_T rtb_Subtract_j;
          boolean_T rtb_Compare_d;
          rtb_Merge = LANSwitch_U_Arg1;
          rtb_Subtract_j = LANSwitch_U_Arg3 - LANSwitch_U_Arg2;
          rtb_Compare_d = (rtb_Subtract_j == 1);
          if (rtb_Compare_d) {
            LANSwitch_B->Switch_i = 101;
          } else {
            int32_T rtb_Switch1_l;
            boolean_T rtb_Compare_cj;
            rtb_Compare_cj = (rtb_Subtract_j == 2);
            if (rtb_Compare_cj) {
              rtb_Switch1_l = 102;
            } else {
              int32_T rtb_Switch2_a;
              boolean_T rtb_Compare_o;
              rtb_Compare_o = (rtb_Subtract_j == 3);
              if (rtb_Compare_o) {
                rtb_Switch2_a = 103;
              } else {
                int32_T rtb_Switch3_j;
                boolean_T rtb_Compare_gf;
                rtb_Compare_gf = (rtb_Subtract_j == -1);
                if (rtb_Compare_gf) {
                  rtb_Switch3_j = -101;
                } else {
                  int32_T rtb_Switch4;
                  boolean_T rtb_Compare_p0;
                  rtb_Compare_p0 = (rtb_Subtract_j == -2);
                  if (rtb_Compare_p0) {
                    rtb_Switch4 = -102;
                  } else {
                    int32_T rtb_Switch5;
                    boolean_T rtb_Compare_pd;
                    rtb_Compare_pd = (rtb_Subtract_j == -3);
                    if (rtb_Compare_pd) {
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
