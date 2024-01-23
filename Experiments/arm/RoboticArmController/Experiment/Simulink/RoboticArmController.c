#include "RoboticArmController.h"
#include "rtwtypes.h"
#include "RoboticArmController_private.h"
#include <string.h>

void RoboticArmController_Error(int32_T *rty_Res, int32_T *rty_B)
{
  *rty_Res = -1;
  *rty_B = 0;
}

void RoboticArmContr_FindArmIdInPool(int32_T rtu_ArmId, int32_T *rty_Out1, const
  int32_T rtd_ArmIdPool[128], const int32_T rtd_ArmIdPoolF[128], int32_T
  *rtd_FoundArm_n, int32_T rtp_POOL_SIZE)
{
  int32_T rtb_DataStoreRead2_pj[128];
  int32_T rtb_DataStoreRead_dy[128];
  int32_T i;
  if (rtp_POOL_SIZE > 0) {
    for (i = 0; i < 128; i++) {
      rtb_DataStoreRead_dy[i] = rtd_ArmIdPool[i];
      rtb_DataStoreRead2_pj[i] = rtd_ArmIdPoolF[i];
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
    rtb_Selector_o = rtb_DataStoreRead_dy[rtb_ForIterator_e];
    rtb_Equal_n = (rtu_ArmId == rtb_Selector_o);
    rtb_Selector1_l = rtb_DataStoreRead2_pj[rtb_ForIterator_e];
    rtb_Compare_n1 = (rtb_Selector1_l == 1);
    rtb_AND1_e = (rtb_Equal_n && rtb_Compare_n1);
    rtb_DataStoreRead1_cy = *rtd_FoundArm_n;
    rtb_Compare_cc = (rtb_DataStoreRead1_cy == -1);
    rtb_AND_g = (rtb_AND1_e && rtb_Compare_cc);
    if (rtb_AND_g) {
      *rty_Out1 = rtb_ForIterator_e;
    } else {
      *rty_Out1 = rtb_DataStoreRead1_cy;
    }

    *rtd_FoundArm_n = *rty_Out1;
  }
}

void RoboticArmController_Err(int32_T *rty_Res)
{
  *rty_Res = -3;
}

void RoboticArmCon_FindArmIdInPool_f(int32_T rtu_ArmId, int32_T *rty_Out1, const
  int32_T rtd_ArmIdPool[128], const int32_T rtd_ArmIdPoolF[128], int32_T
  *rtd_FoundArm_g, int32_T rtp_POOL_SIZE)
{
  int32_T rtb_DataStoreRead2_gp[128];
  int32_T rtb_DataStoreRead_k[128];
  int32_T i;
  if (rtp_POOL_SIZE > 0) {
    for (i = 0; i < 128; i++) {
      rtb_DataStoreRead_k[i] = rtd_ArmIdPool[i];
      rtb_DataStoreRead2_gp[i] = rtd_ArmIdPoolF[i];
    }
  }

  for (i = 0; i < rtp_POOL_SIZE; i++) {
    int32_T rtb_DataStoreRead1_o;
    int32_T rtb_ForIterator_eu;
    int32_T rtb_Selector1_j;
    int32_T rtb_Selector_eb;
    boolean_T rtb_AND1_l;
    boolean_T rtb_AND_g;
    boolean_T rtb_Compare_at;
    boolean_T rtb_Compare_cb;
    boolean_T rtb_Equal_o3;
    rtb_ForIterator_eu = i;
    rtb_Selector_eb = rtb_DataStoreRead_k[rtb_ForIterator_eu];
    rtb_Equal_o3 = (rtu_ArmId == rtb_Selector_eb);
    rtb_Selector1_j = rtb_DataStoreRead2_gp[rtb_ForIterator_eu];
    rtb_Compare_cb = (rtb_Selector1_j >= 1);
    rtb_AND1_l = (rtb_Equal_o3 && rtb_Compare_cb);
    rtb_DataStoreRead1_o = *rtd_FoundArm_g;
    rtb_Compare_at = (rtb_DataStoreRead1_o == -1);
    rtb_AND_g = (rtb_AND1_l && rtb_Compare_at);
    if (rtb_AND_g) {
      *rty_Out1 = rtb_ForIterator_eu;
    } else {
      *rty_Out1 = rtb_DataStoreRead1_o;
    }

    *rtd_FoundArm_g = *rty_Out1;
  }
}

void RoboticArmController_step(RT_MODEL_RoboticArmController_T *const
  RoboticArmController_M, int32_T RoboticArmController_U_ArmId, int32_T
  RoboticArmController_U_Op, int32_T RoboticArmController_U_P1, int32_T
  RoboticArmController_U_P2, int32_T RoboticArmController_U_P3, int32_T
  *RoboticArmController_Y_Res, int32_T *RoboticArmController_Y_B)
{
  B_RoboticArmController_T *RoboticArmController_B =
    RoboticArmController_M->blockIO;
  DW_RoboticArmController_T *RoboticArmController_DW =
    RoboticArmController_M->dwork;
  int32_T rtb_Assignment[128];
  int32_T rtb_Assignment1[128];
  int32_T rtb_Assignment1_c[128];
  int32_T rtb_Assignment1_j[128];
  int32_T rtb_Assignment1_o[128];
  int32_T rtb_Assignment_c[128];
  int32_T rtb_Assignment_h[128];
  int32_T rtb_Assignment_k[128];
  int32_T rtb_DataStoreRead[128];
  int32_T rtb_DataStoreRead1_e[128];
  int32_T rtb_DataStoreRead2[128];
  int32_T rtb_DataStoreRead2_aa[128];
  int32_T rtb_DataStoreRead2_c[128];
  int32_T rtb_DataStoreRead2_ca[128];
  int32_T rtb_DataStoreRead2_ek[128];
  int32_T rtb_DataStoreRead2_f[128];
  int32_T rtb_DataStoreRead2_p[128];
  int32_T rtb_DataStoreRead_a[128];
  int32_T rtb_DataStoreRead_d[128];
  int32_T rtb_DataStoreRead_e[128];
  int32_T rtb_DataStoreRead_h[128];
  int32_T rtb_DataStoreRead_j[128];
  int32_T rtb_DataStoreRead_m[128];
  int32_T Found_E;
  int32_T Switch_m;
  int32_T i;
  int32_T rtb_Merge;
  int32_T rtb_Merge1;
  int32_T rtb_Switch_ci;
  int32_T rtb_Switch_l;
  int32_T rtb_Switch_mm;
  int32_T s96_iter;
  boolean_T Switch_l4;
  switch (RoboticArmController_U_Op) {
   case 10001:
    {
      boolean_T rtb_Compare_lq;
      rtb_Compare_lq = (RoboticArmController_U_ArmId == 0);
      if (rtb_Compare_lq) {
        RoboticArmController_Error(&rtb_Merge, &rtb_Merge1);
      } else {
        boolean_T Found;
        boolean_T rtb_AND_l;
        Found = false;
        Found_E = -1;
        for (s96_iter = 0; s96_iter < 128; s96_iter++) {
          int32_T rtb_DataStoreRead1_fi;
          int32_T rtb_ForIterator_b;
          int32_T rtb_ForIterator_j;
          boolean_T rtb_AND_j;
          boolean_T rtb_AND_jj;
          rtb_ForIterator_j = s96_iter;
          for (i = 0; i < 128; i++) {
            rtb_DataStoreRead_a[i] = RoboticArmController_DW->ArmIdPool[i];
            rtb_DataStoreRead2_p[i] = RoboticArmController_DW->ArmIdPoolF[i];
          }

          int32_T rtb_Selector1_f;
          int32_T rtb_Selector_l;
          boolean_T rtb_Compare_pu;
          boolean_T rtb_Equal_ku;
          rtb_Selector_l = rtb_DataStoreRead_a[rtb_ForIterator_j];
          rtb_Equal_ku = (rtb_Selector_l == RoboticArmController_U_ArmId);
          rtb_Selector1_f = rtb_DataStoreRead2_p[rtb_ForIterator_j];
          rtb_Compare_pu = (rtb_Selector1_f == 1);
          rtb_AND_j = (rtb_Equal_ku && rtb_Compare_pu);
          if (rtb_AND_j) {
            Switch_l4 = true;
          } else {
            boolean_T rtb_DataStoreRead1_k;
            rtb_DataStoreRead1_k = Found;
            Switch_l4 = rtb_DataStoreRead1_k;
          }

          Found = Switch_l4;
          rtb_ForIterator_b = s96_iter;
          for (i = 0; i < 128; i++) {
            rtb_DataStoreRead2_ca[i] = RoboticArmController_DW->ArmIdPoolF[i];
          }

          int32_T rtb_Selector1_lc;
          boolean_T rtb_Compare_av;
          boolean_T rtb_Compare_j1;
          rtb_Selector1_lc = rtb_DataStoreRead2_ca[rtb_ForIterator_b];
          rtb_Compare_av = (rtb_Selector1_lc == 0);
          rtb_DataStoreRead1_fi = Found_E;
          rtb_Compare_j1 = (rtb_DataStoreRead1_fi == -1);
          rtb_AND_jj = (rtb_Compare_av && rtb_Compare_j1);
          if (rtb_AND_jj) {
            Switch_m = rtb_ForIterator_b;
          } else {
            Switch_m = rtb_DataStoreRead1_fi;
          }

          Found_E = Switch_m;
        }

        boolean_T rtb_Compare_ei;
        boolean_T rtb_Compare_l4;
        rtb_Compare_l4 = !Switch_l4;
        rtb_Compare_ei = (Switch_m != -1);
        rtb_AND_l = (rtb_Compare_l4 && rtb_Compare_ei);
        if (rtb_AND_l) {
          boolean_T rtb_Compare_eg;
          rtb_Merge = 1;
          for (Found_E = 0; Found_E < 128; Found_E++) {
            int32_T rtb_ForIterator_o;
            int32_T rtb_Switch1_f;
            int32_T rtb_Switch_c;
            boolean_T rtb_Equal_m;
            rtb_ForIterator_o = Found_E;
            for (i = 0; i < 128; i++) {
              rtb_DataStoreRead_e[i] = RoboticArmController_DW->ArmIdPool[i];
            }

            rtb_Equal_m = (Switch_m == rtb_ForIterator_o);
            if (rtb_Equal_m) {
              rtb_Switch_c = RoboticArmController_U_ArmId;
            } else {
              int32_T rtb_Selector_i;
              rtb_Selector_i = rtb_DataStoreRead_e[rtb_ForIterator_o];
              rtb_Switch_c = rtb_Selector_i;
            }

            if (Found_E == 0) {
              for (i = 0; i < 128; i++) {
                rtb_Assignment_h[i] = rtb_DataStoreRead_e[i];
              }
            }

            rtb_Assignment_h[rtb_ForIterator_o] = rtb_Switch_c;
            for (i = 0; i < 128; i++) {
              RoboticArmController_DW->ArmIdPool[i] = rtb_Assignment_h[i];
              rtb_DataStoreRead1_e[i] = RoboticArmController_DW->ArmIdPoolF[i];
            }

            if (rtb_Equal_m) {
              rtb_Switch1_f = 1;
            } else {
              int32_T rtb_Selector1_c;
              rtb_Selector1_c = rtb_DataStoreRead1_e[rtb_ForIterator_o];
              rtb_Switch1_f = rtb_Selector1_c;
            }

            if (Found_E == 0) {
              for (i = 0; i < 128; i++) {
                rtb_Assignment1_o[i] = rtb_DataStoreRead1_e[i];
              }
            }

            rtb_Assignment1_o[rtb_ForIterator_o] = rtb_Switch1_f;
            for (i = 0; i < 128; i++) {
              RoboticArmController_DW->ArmIdPoolF[i] = rtb_Assignment1_o[i];
            }
          }

          rtb_Compare_eg = (Switch_m == 0);
          if (rtb_Compare_eg) {
            RoboticArmController_B->Switch_p = 1;
          } else {
            int32_T rtb_Switch1_p;
            boolean_T rtb_Compare_da;
            rtb_Compare_da = (Switch_m == 1);
            if (rtb_Compare_da) {
              rtb_Switch1_p = 2;
            } else {
              int32_T rtb_Switch2_c;
              boolean_T rtb_Compare_mi;
              rtb_Compare_mi = (Switch_m == 2);
              if (rtb_Compare_mi) {
                rtb_Switch2_c = 3;
              } else {
                rtb_Switch2_c = 4;
              }

              rtb_Switch1_p = rtb_Switch2_c;
            }

            RoboticArmController_B->Switch_p = rtb_Switch1_p;
          }
        } else {
          rtb_Merge = -4;
        }

        rtb_Merge1 = RoboticArmController_B->Switch_p;
      }
    }
    break;

   case 10002:
    {
      boolean_T rtb_Compare_jj;
      rtb_Compare_jj = (RoboticArmController_U_ArmId == 0);
      if (rtb_Compare_jj) {
        RoboticArmController_Error(&rtb_Merge, &rtb_Merge1);
      } else {
        boolean_T rtb_AND_hg;
        s96_iter = -1;
        Found_E = -1;
        RoboticArmContr_FindArmIdInPool(RoboticArmController_U_ArmId,
          &RoboticArmController_B->Switch_l, RoboticArmController_DW->ArmIdPool,
          RoboticArmController_DW->ArmIdPoolF, &s96_iter, 128);
        for (s96_iter = 0; s96_iter < 128; s96_iter++) {
          int32_T rtb_DataStoreRead1_al;
          int32_T rtb_ForIterator_p;
          boolean_T rtb_AND_f;
          rtb_ForIterator_p = s96_iter;
          for (i = 0; i < 128; i++) {
            rtb_DataStoreRead_d[i] = RoboticArmController_DW->ArmIdPool[i];
            rtb_DataStoreRead2_aa[i] = RoboticArmController_DW->ArmIdPoolF[i];
          }

          int32_T rtb_Selector1_m;
          int32_T rtb_Selector_a;
          boolean_T rtb_AND1_i;
          boolean_T rtb_Compare_e5u;
          boolean_T rtb_Compare_jc;
          boolean_T rtb_Equal_g;
          rtb_Selector_a = rtb_DataStoreRead_d[rtb_ForIterator_p];
          rtb_Equal_g = (RoboticArmController_U_P1 == rtb_Selector_a);
          rtb_Selector1_m = rtb_DataStoreRead2_aa[rtb_ForIterator_p];
          rtb_Compare_e5u = (rtb_Selector1_m == 1);
          rtb_AND1_i = (rtb_Equal_g && rtb_Compare_e5u);
          rtb_DataStoreRead1_al = Found_E;
          rtb_Compare_jc = (rtb_DataStoreRead1_al == -1);
          rtb_AND_f = (rtb_AND1_i && rtb_Compare_jc);
          if (rtb_AND_f) {
            i = rtb_ForIterator_p;
          } else {
            i = rtb_DataStoreRead1_al;
          }

          Found_E = i;
        }

        boolean_T rtb_Compare_az;
        boolean_T rtb_Compare_b;
        rtb_Compare_az = (RoboticArmController_B->Switch_l != -1);
        rtb_Compare_b = (i != -1);
        rtb_AND_hg = (rtb_Compare_az && rtb_Compare_b);
        if (rtb_AND_hg) {
          int32_T rtb_Subtract_j;
          boolean_T rtb_Compare_en;
          rtb_Merge = RoboticArmController_U_P1;
          rtb_Subtract_j = RoboticArmController_U_P3 - RoboticArmController_U_P2;
          rtb_Compare_en = (rtb_Subtract_j == 1);
          if (rtb_Compare_en) {
            RoboticArmController_B->Switch_i = 101;
          } else {
            int32_T rtb_Switch1_l;
            boolean_T rtb_Compare_jx;
            rtb_Compare_jx = (rtb_Subtract_j == 2);
            if (rtb_Compare_jx) {
              rtb_Switch1_l = 102;
            } else {
              int32_T rtb_Switch2_a;
              boolean_T rtb_Compare_m;
              rtb_Compare_m = (rtb_Subtract_j == 3);
              if (rtb_Compare_m) {
                rtb_Switch2_a = 103;
              } else {
                int32_T rtb_Switch3_j;
                boolean_T rtb_Compare_pi;
                rtb_Compare_pi = (rtb_Subtract_j == -1);
                if (rtb_Compare_pi) {
                  rtb_Switch3_j = -101;
                } else {
                  int32_T rtb_Switch4_b;
                  boolean_T rtb_Compare_mj;
                  rtb_Compare_mj = (rtb_Subtract_j == -2);
                  if (rtb_Compare_mj) {
                    rtb_Switch4_b = -102;
                  } else {
                    int32_T rtb_Switch5;
                    boolean_T rtb_Compare_lk;
                    rtb_Compare_lk = (rtb_Subtract_j == -3);
                    if (rtb_Compare_lk) {
                      rtb_Switch5 = -103;
                    } else {
                      rtb_Switch5 = rtb_Subtract_j;
                    }

                    rtb_Switch4_b = rtb_Switch5;
                  }

                  rtb_Switch3_j = rtb_Switch4_b;
                }

                rtb_Switch2_a = rtb_Switch3_j;
              }

              rtb_Switch1_l = rtb_Switch2_a;
            }

            RoboticArmController_B->Switch_i = rtb_Switch1_l;
          }
        } else {
          RoboticArmController_Err(&rtb_Merge);
        }

        rtb_Merge1 = RoboticArmController_B->Switch_i;
      }
    }
    break;

   case 10004:
    {
      boolean_T rtb_Compare_c;
      rtb_Compare_c = (RoboticArmController_U_ArmId == 0);
      if (rtb_Compare_c) {
        RoboticArmController_Error(&rtb_Merge, &rtb_Merge1);
      } else {
        boolean_T rtb_Compare_i4;
        Found_E = -1;
        RoboticArmContr_FindArmIdInPool(RoboticArmController_U_ArmId,
          &RoboticArmController_B->Switch, RoboticArmController_DW->ArmIdPool,
          RoboticArmController_DW->ArmIdPoolF, &Found_E, 128);
        rtb_Compare_i4 = (RoboticArmController_B->Switch != -1);
        if (rtb_Compare_i4) {
          rtb_Merge = RoboticArmController_B->Switch;
          rtb_Merge1 = 1;
        } else {
          rtb_Merge = -1;
          rtb_Merge1 = -1;
        }
      }
    }
    break;

   case 10008:
    {
      boolean_T rtb_Compare_ia;
      rtb_Compare_ia = (RoboticArmController_U_ArmId == 0);
      if (rtb_Compare_ia) {
        RoboticArmController_Error(&rtb_Merge, &rtb_Merge1);
      } else {
        uint8_T rtb_Compare_p;
        Found_E = -1;
        RoboticArmCon_FindArmIdInPool_f(RoboticArmController_U_ArmId,
          &rtb_Switch_l, RoboticArmController_DW->ArmIdPool,
          RoboticArmController_DW->ArmIdPoolF, &Found_E, 128);
        rtb_Compare_p = (uint8_T)(rtb_Switch_l == -1);
        if (rtb_Compare_p != 0) {
          RoboticArmController_Err(&Found_E);
        } else {
          int32_T rtb_ArmId_m;
          rtb_ArmId_m = RoboticArmController_U_ArmId;
          for (Found_E = 0; Found_E < 128; Found_E++) {
            int32_T rtb_ForIterator_jg;
            int32_T rtb_Switch1_lo;
            int32_T rtb_Switch_b;
            boolean_T rtb_Equal_fr;
            rtb_ForIterator_jg = Found_E;
            for (i = 0; i < 128; i++) {
              rtb_DataStoreRead_m[i] = RoboticArmController_DW->ArmIdPool[i];
            }

            rtb_Equal_fr = (rtb_ArmId_m == rtb_ForIterator_jg);
            if (rtb_Equal_fr) {
              rtb_Switch_b = 0;
            } else {
              int32_T rtb_Selector_p;
              rtb_Selector_p = rtb_DataStoreRead_m[rtb_ForIterator_jg];
              rtb_Switch_b = rtb_Selector_p;
            }

            if (Found_E == 0) {
              for (i = 0; i < 128; i++) {
                rtb_Assignment_c[i] = rtb_DataStoreRead_m[i];
              }
            }

            rtb_Assignment_c[rtb_ForIterator_jg] = rtb_Switch_b;
            for (i = 0; i < 128; i++) {
              RoboticArmController_DW->ArmIdPool[i] = rtb_Assignment_c[i];
              rtb_DataStoreRead2_f[i] = RoboticArmController_DW->ArmIdPoolF[i];
            }

            if (rtb_Equal_fr) {
              rtb_Switch1_lo = 0;
            } else {
              int32_T rtb_Selector1_j;
              rtb_Selector1_j = rtb_DataStoreRead2_f[rtb_ForIterator_jg];
              rtb_Switch1_lo = rtb_Selector1_j;
            }

            if (Found_E == 0) {
              for (i = 0; i < 128; i++) {
                rtb_Assignment1_j[i] = rtb_DataStoreRead2_f[i];
              }
            }

            rtb_Assignment1_j[rtb_ForIterator_jg] = rtb_Switch1_lo;
            for (i = 0; i < 128; i++) {
              RoboticArmController_DW->ArmIdPoolF[i] = rtb_Assignment1_j[i];
            }
          }

          Found_E = rtb_ArmId_m;
          RoboticArmController_B->OutportBufferForB_ky =
            RoboticArmController_ConstB.Constant_l;
        }

        rtb_Merge1 = RoboticArmController_B->OutportBufferForB_ky;
        rtb_Merge = Found_E;
      }
    }
    break;

   case 10016:
    {
      boolean_T rtb_Compare_ch;
      rtb_Compare_ch = (RoboticArmController_U_ArmId == 0);
      if (rtb_Compare_ch) {
        RoboticArmController_Error(&rtb_Merge, &rtb_Merge1);
      } else {
        uint8_T rtb_Compare_ha;
        Found_E = -1;
        RoboticArmCon_FindArmIdInPool_f(RoboticArmController_U_ArmId,
          &rtb_Switch_ci, RoboticArmController_DW->ArmIdPool,
          RoboticArmController_DW->ArmIdPoolF, &Found_E, 128);
        rtb_Compare_ha = (uint8_T)(rtb_Switch_ci == -1);
        if (rtb_Compare_ha != 0) {
          RoboticArmController_Err(&Found_E);
        } else {
          int32_T rtb_ArmId_f;
          int32_T rtb_Switch4_o;
          boolean_T rtb_Compare_fi;
          rtb_ArmId_f = RoboticArmController_U_ArmId;
          rtb_Compare_fi = (RoboticArmController_U_P3 == 5);
          if (rtb_Compare_fi) {
            rtb_Switch4_o = 5;
          } else {
            int32_T rtb_Switch3_k;
            boolean_T rtb_Compare_lf;
            rtb_Compare_lf = (RoboticArmController_U_P2 == 4);
            if (rtb_Compare_lf) {
              rtb_Switch3_k = 4;
            } else {
              int32_T rtb_Switch2_j;
              boolean_T rtb_Compare_i;
              rtb_Compare_i = (RoboticArmController_U_P1 == 3);
              if (rtb_Compare_i) {
                rtb_Switch2_j = 3;
              } else {
                rtb_Switch2_j = 1;
              }

              rtb_Switch3_k = rtb_Switch2_j;
            }

            rtb_Switch4_o = rtb_Switch3_k;
          }

          for (Found_E = 0; Found_E < 128; Found_E++) {
            int32_T rtb_ForIterator_na;
            int32_T rtb_Switch1_a;
            int32_T rtb_Switch_a;
            boolean_T rtb_Equal_p;
            rtb_ForIterator_na = Found_E;
            for (i = 0; i < 128; i++) {
              rtb_DataStoreRead_j[i] = RoboticArmController_DW->ArmIdPool[i];
            }

            rtb_Equal_p = (rtb_ArmId_f == rtb_ForIterator_na);
            if (rtb_Equal_p) {
              rtb_Switch_a = 1;
            } else {
              int32_T rtb_Selector_e;
              rtb_Selector_e = rtb_DataStoreRead_j[rtb_ForIterator_na];
              rtb_Switch_a = rtb_Selector_e;
            }

            if (Found_E == 0) {
              for (i = 0; i < 128; i++) {
                rtb_Assignment_k[i] = rtb_DataStoreRead_j[i];
              }
            }

            rtb_Assignment_k[rtb_ForIterator_na] = rtb_Switch_a;
            for (i = 0; i < 128; i++) {
              RoboticArmController_DW->ArmIdPool[i] = rtb_Assignment_k[i];
              rtb_DataStoreRead2_ek[i] = RoboticArmController_DW->ArmIdPoolF[i];
            }

            if (rtb_Equal_p) {
              rtb_Switch1_a = rtb_Switch4_o;
            } else {
              int32_T rtb_Selector1_o;
              rtb_Selector1_o = rtb_DataStoreRead2_ek[rtb_ForIterator_na];
              rtb_Switch1_a = rtb_Selector1_o;
            }

            if (Found_E == 0) {
              for (i = 0; i < 128; i++) {
                rtb_Assignment1_c[i] = rtb_DataStoreRead2_ek[i];
              }
            }

            rtb_Assignment1_c[rtb_ForIterator_na] = rtb_Switch1_a;
            for (i = 0; i < 128; i++) {
              RoboticArmController_DW->ArmIdPoolF[i] = rtb_Assignment1_c[i];
            }
          }

          Found_E = rtb_ArmId_f;
          RoboticArmController_B->OutportBufferForB_k =
            RoboticArmController_ConstB.Constant_g;
        }

        rtb_Merge1 = RoboticArmController_B->OutportBufferForB_k;
        rtb_Merge = Found_E;
      }
    }
    break;

   case 10032:
    {
      boolean_T rtb_Compare_mk;
      rtb_Compare_mk = (RoboticArmController_U_ArmId == 0);
      if (rtb_Compare_mk) {
        RoboticArmController_Error(&rtb_Merge, &rtb_Merge1);
      } else {
        uint8_T rtb_Compare;
        Found_E = -1;
        for (s96_iter = 0; s96_iter < 128; s96_iter++) {
          int32_T rtb_DataStoreRead1;
          int32_T rtb_ForIterator_h;
          boolean_T rtb_AND;
          rtb_ForIterator_h = s96_iter;
          for (i = 0; i < 128; i++) {
            rtb_DataStoreRead_h[i] = RoboticArmController_DW->ArmIdPool[i];
            rtb_DataStoreRead2_c[i] = RoboticArmController_DW->ArmIdPoolF[i];
          }

          int32_T rtb_Selector1_d;
          int32_T rtb_Selector_g;
          boolean_T rtb_AND1;
          boolean_T rtb_Compare_bx;
          boolean_T rtb_Compare_d;
          boolean_T rtb_Equal_f;
          rtb_Selector_g = rtb_DataStoreRead_h[rtb_ForIterator_h];
          rtb_Equal_f = (RoboticArmController_U_ArmId == rtb_Selector_g);
          rtb_Selector1_d = rtb_DataStoreRead2_c[rtb_ForIterator_h];
          rtb_Compare_d = (rtb_Selector1_d == 5);
          rtb_AND1 = (rtb_Equal_f && rtb_Compare_d);
          rtb_DataStoreRead1 = Found_E;
          rtb_Compare_bx = (rtb_DataStoreRead1 == -1);
          rtb_AND = (rtb_AND1 && rtb_Compare_bx);
          if (rtb_AND) {
            rtb_Switch_mm = rtb_ForIterator_h;
          } else {
            rtb_Switch_mm = rtb_DataStoreRead1;
          }

          Found_E = rtb_Switch_mm;
        }

        rtb_Compare = (uint8_T)(rtb_Switch_mm == -1);
        if (rtb_Compare != 0) {
          RoboticArmController_Err(&Found_E);
        } else {
          int32_T rtb_ArmId;
          int32_T rtb_Switch4;
          boolean_T rtb_Compare_dh;
          rtb_ArmId = RoboticArmController_U_ArmId;
          rtb_Compare_dh = (RoboticArmController_U_P3 == 8);
          if (rtb_Compare_dh) {
            rtb_Switch4 = 8;
          } else {
            int32_T rtb_Switch3;
            boolean_T rtb_Compare_ib;
            rtb_Compare_ib = (RoboticArmController_U_P2 == 7);
            if (rtb_Compare_ib) {
              rtb_Switch3 = 7;
            } else {
              int32_T rtb_Switch2;
              boolean_T rtb_Compare_o;
              rtb_Compare_o = (RoboticArmController_U_P1 == 6);
              if (rtb_Compare_o) {
                rtb_Switch2 = 6;
              } else {
                rtb_Switch2 = 1;
              }

              rtb_Switch3 = rtb_Switch2;
            }

            rtb_Switch4 = rtb_Switch3;
          }

          for (Found_E = 0; Found_E < 128; Found_E++) {
            int32_T rtb_ForIterator;
            int32_T rtb_Switch;
            int32_T rtb_Switch1;
            boolean_T rtb_Equal;
            rtb_ForIterator = Found_E;
            for (i = 0; i < 128; i++) {
              rtb_DataStoreRead[i] = RoboticArmController_DW->ArmIdPool[i];
            }

            rtb_Equal = (rtb_ArmId == rtb_ForIterator);
            if (rtb_Equal) {
              rtb_Switch = 1;
            } else {
              int32_T rtb_Selector;
              rtb_Selector = rtb_DataStoreRead[rtb_ForIterator];
              rtb_Switch = rtb_Selector;
            }

            if (Found_E == 0) {
              for (i = 0; i < 128; i++) {
                rtb_Assignment[i] = rtb_DataStoreRead[i];
              }
            }

            rtb_Assignment[rtb_ForIterator] = rtb_Switch;
            for (i = 0; i < 128; i++) {
              RoboticArmController_DW->ArmIdPool[i] = rtb_Assignment[i];
              rtb_DataStoreRead2[i] = RoboticArmController_DW->ArmIdPoolF[i];
            }

            if (rtb_Equal) {
              rtb_Switch1 = rtb_Switch4;
            } else {
              int32_T rtb_Selector1;
              rtb_Selector1 = rtb_DataStoreRead2[rtb_ForIterator];
              rtb_Switch1 = rtb_Selector1;
            }

            if (Found_E == 0) {
              for (i = 0; i < 128; i++) {
                rtb_Assignment1[i] = rtb_DataStoreRead2[i];
              }
            }

            rtb_Assignment1[rtb_ForIterator] = rtb_Switch1;
            for (i = 0; i < 128; i++) {
              RoboticArmController_DW->ArmIdPoolF[i] = rtb_Assignment1[i];
            }
          }

          Found_E = rtb_ArmId;
          RoboticArmController_B->OutportBufferForB =
            RoboticArmController_ConstB.Constant;
        }

        rtb_Merge1 = RoboticArmController_B->OutportBufferForB;
        rtb_Merge = Found_E;
      }
    }
    break;

   default:
    rtb_Merge = -2;
    rtb_Merge1 = 0;
    break;
  }

  *RoboticArmController_Y_Res = rtb_Merge;
  *RoboticArmController_Y_B = rtb_Merge1;
}

void RoboticArmController_initialize(RT_MODEL_RoboticArmController_T *const
  RoboticArmController_M, int32_T *RoboticArmController_U_ArmId, int32_T
  *RoboticArmController_U_Op, int32_T *RoboticArmController_U_P1, int32_T
  *RoboticArmController_U_P2, int32_T *RoboticArmController_U_P3, int32_T
  *RoboticArmController_Y_Res, int32_T *RoboticArmController_Y_B)
{
  B_RoboticArmController_T *RoboticArmController_B =
    RoboticArmController_M->blockIO;
  DW_RoboticArmController_T *RoboticArmController_DW =
    RoboticArmController_M->dwork;
  (void) memset(((void *) RoboticArmController_B), 0,
                sizeof(B_RoboticArmController_T));
  (void) memset((void *)RoboticArmController_DW, 0,
                sizeof(DW_RoboticArmController_T));
  *RoboticArmController_U_ArmId = 0;
  *RoboticArmController_U_Op = 0;
  *RoboticArmController_U_P1 = 0;
  *RoboticArmController_U_P2 = 0;
  *RoboticArmController_U_P3 = 0;
  *RoboticArmController_Y_Res = 0;
  *RoboticArmController_Y_B = 0;
  RoboticArmController_B->OutportBufferForB_ky =
    RoboticArmController_ConstB.Constant_l;
  RoboticArmController_B->OutportBufferForB_k =
    RoboticArmController_ConstB.Constant_g;
  RoboticArmController_B->OutportBufferForB =
    RoboticArmController_ConstB.Constant;
}

void RoboticArmController_terminate(RT_MODEL_RoboticArmController_T *const
  RoboticArmController_M)
{
  UNUSED_PARAMETER(RoboticArmController_M);
}
