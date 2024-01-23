#include "FMTM.h"
#include "rtwtypes.h"
#include "FMTM_private.h"
#include <string.h>

int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

void FMTM_Error(int32_T *rty_Res, int32_T *rty_R)
{
  *rty_Res = -2;
  *rty_R = 0;
}

void FMTM_FindSenserId(int32_T rtu_SenserId, int32_T *rty_Out1, int32_T
  *rtd_FoundId_o, const int32_T rtd_SenserIdData[256], const int32_T
  rtd_SenserIdUsed[256], int32_T rtp_POOL_SIZE)
{
  int32_T rtb_DataStoreRead2_pj[256];
  int32_T rtb_DataStoreRead_j[256];
  int32_T i;
  if (rtp_POOL_SIZE > 0) {
    for (i = 0; i < 256; i++) {
      rtb_DataStoreRead_j[i] = rtd_SenserIdData[i];
      rtb_DataStoreRead2_pj[i] = rtd_SenserIdUsed[i];
    }
  }

  for (i = 0; i < rtp_POOL_SIZE; i++) {
    int32_T rtb_DataStoreRead1_cy;
    int32_T rtb_ForIterator_e;
    int32_T rtb_Selector1_l;
    int32_T rtb_Selector_o;
    boolean_T rtb_AND1_e;
    boolean_T rtb_AND_g;
    boolean_T rtb_Compare_e;
    boolean_T rtb_Compare_n1;
    boolean_T rtb_Equal_n;
    rtb_ForIterator_e = i;
    rtb_Selector_o = rtb_DataStoreRead_j[rtb_ForIterator_e];
    rtb_Equal_n = (rtu_SenserId == rtb_Selector_o);
    rtb_Selector1_l = rtb_DataStoreRead2_pj[rtb_ForIterator_e];
    rtb_Compare_n1 = (rtb_Selector1_l == 1);
    rtb_AND1_e = (rtb_Equal_n && rtb_Compare_n1);
    rtb_DataStoreRead1_cy = *rtd_FoundId_o;
    rtb_Compare_e = (rtb_DataStoreRead1_cy == -1);
    rtb_AND_g = (rtb_AND1_e && rtb_Compare_e);
    if (rtb_AND_g) {
      *rty_Out1 = rtb_ForIterator_e;
    } else {
      *rty_Out1 = rtb_DataStoreRead1_cy;
    }

    *rtd_FoundId_o = *rty_Out1;
  }
}

void FMTM_step(RT_MODEL_FMTM_T *const FMTM_M, int32_T FMTM_U_SenserId, int32_T
               FMTM_U_Opcode, int32_T FMTM_U_TValue, int32_T *FMTM_Y_Res,
               int32_T *FMTM_Y_R)
{
  B_FMTM_T *FMTM_B = FMTM_M->blockIO;
  DW_FMTM_T *FMTM_DW = FMTM_M->dwork;
  int32_T rtb_Assignment[256];
  int32_T rtb_Assignment1[256];
  int32_T rtb_Assignment1_o[256];
  int32_T rtb_Assignment_h[256];
  int32_T rtb_DataStoreRead[256];
  int32_T rtb_DataStoreRead1_e[256];
  int32_T rtb_DataStoreRead2[256];
  int32_T rtb_DataStoreRead2_i[256];
  int32_T rtb_DataStoreRead2_l[256];
  int32_T rtb_DataStoreRead2_ny[256];
  int32_T rtb_DataStoreRead2_o1[256];
  int32_T rtb_DataStoreRead_d[256];
  int32_T rtb_DataStoreRead_e[256];
  int32_T rtb_DataStoreRead_o[256];
  int32_T rtb_DataStoreRead_oz[256];
  int32_T FoundE;
  int32_T Switch_m;
  int32_T i;
  int32_T rtb_Switch_l;
  int32_T s15_iter;
  boolean_T Switch_l4;
  switch (FMTM_U_Opcode) {
   case 1:
    {
      boolean_T rtb_Compare_o4;
      rtb_Compare_o4 = (FMTM_U_SenserId == 0);
      if (rtb_Compare_o4) {
        FMTM_Error(&FMTM_B->Merge, &FMTM_B->Merge1);
      } else {
        boolean_T Found;
        boolean_T rtb_AND_lk;
        Found = false;
        FoundE = -1;
        for (s15_iter = 0; s15_iter < 256; s15_iter++) {
          int32_T rtb_DataStoreRead1_f;
          int32_T rtb_ForIterator_h;
          int32_T rtb_ForIterator_ox;
          boolean_T rtb_AND_g;
          boolean_T rtb_AND_l;
          rtb_ForIterator_h = s15_iter;
          for (i = 0; i < 256; i++) {
            rtb_DataStoreRead_oz[i] = FMTM_DW->SenserIdUsed[i];
            rtb_DataStoreRead2_l[i] = FMTM_DW->SenserIdUsed[i];
          }

          int32_T rtb_Selector1_j;
          int32_T rtb_Selector_e;
          boolean_T rtb_Compare_py;
          boolean_T rtb_Equal_j;
          rtb_Selector_e = rtb_DataStoreRead_oz[rtb_ForIterator_h];
          rtb_Equal_j = (rtb_Selector_e == FMTM_U_SenserId);
          rtb_Selector1_j = rtb_DataStoreRead2_l[rtb_ForIterator_h];
          rtb_Compare_py = (rtb_Selector1_j == 1);
          rtb_AND_g = (rtb_Equal_j && rtb_Compare_py);
          if (rtb_AND_g) {
            Switch_l4 = true;
          } else {
            boolean_T rtb_DataStoreRead1_k;
            rtb_DataStoreRead1_k = Found;
            Switch_l4 = rtb_DataStoreRead1_k;
          }

          Found = Switch_l4;
          rtb_ForIterator_ox = s15_iter;
          for (i = 0; i < 256; i++) {
            rtb_DataStoreRead2_o1[i] = FMTM_DW->SenserIdUsed[i];
          }

          int32_T rtb_Selector1_l;
          boolean_T rtb_Compare_aa;
          boolean_T rtb_Compare_ik;
          rtb_Selector1_l = rtb_DataStoreRead2_o1[rtb_ForIterator_ox];
          rtb_Compare_aa = (rtb_Selector1_l == 0);
          rtb_DataStoreRead1_f = FoundE;
          rtb_Compare_ik = (rtb_DataStoreRead1_f == -1);
          rtb_AND_l = (rtb_Compare_aa && rtb_Compare_ik);
          if (rtb_AND_l) {
            Switch_m = rtb_ForIterator_ox;
          } else {
            Switch_m = rtb_DataStoreRead1_f;
          }

          FoundE = Switch_m;
        }

        boolean_T rtb_Compare_fx;
        boolean_T rtb_Compare_i;
        rtb_Compare_i = !Switch_l4;
        rtb_Compare_fx = (Switch_m != -1);
        rtb_AND_lk = (rtb_Compare_i && rtb_Compare_fx);
        if (rtb_AND_lk) {
          boolean_T rtb_Compare_p;
          FMTM_B->Merge = 1;
          for (FoundE = 0; FoundE < 256; FoundE++) {
            int32_T rtb_ForIterator_o;
            int32_T rtb_Switch1_f;
            int32_T rtb_Switch_c;
            boolean_T rtb_Equal_m;
            rtb_ForIterator_o = FoundE;
            for (i = 0; i < 256; i++) {
              rtb_DataStoreRead_e[i] = FMTM_DW->SenserIdData[i];
            }

            rtb_Equal_m = (Switch_m == rtb_ForIterator_o);
            if (rtb_Equal_m) {
              rtb_Switch_c = FMTM_U_SenserId;
            } else {
              int32_T rtb_Selector_i;
              rtb_Selector_i = rtb_DataStoreRead_e[rtb_ForIterator_o];
              rtb_Switch_c = rtb_Selector_i;
            }

            if (FoundE == 0) {
              for (i = 0; i < 256; i++) {
                rtb_Assignment_h[i] = rtb_DataStoreRead_e[i];
              }
            }

            rtb_Assignment_h[rtb_ForIterator_o] = rtb_Switch_c;
            for (i = 0; i < 256; i++) {
              FMTM_DW->SenserIdData[i] = rtb_Assignment_h[i];
              rtb_DataStoreRead1_e[i] = FMTM_DW->SenserIdUsed[i];
            }

            if (rtb_Equal_m) {
              rtb_Switch1_f = 1;
            } else {
              int32_T rtb_Selector1_c;
              rtb_Selector1_c = rtb_DataStoreRead1_e[rtb_ForIterator_o];
              rtb_Switch1_f = rtb_Selector1_c;
            }

            if (FoundE == 0) {
              for (i = 0; i < 256; i++) {
                rtb_Assignment1_o[i] = rtb_DataStoreRead1_e[i];
              }
            }

            rtb_Assignment1_o[rtb_ForIterator_o] = rtb_Switch1_f;
            for (i = 0; i < 256; i++) {
              FMTM_DW->SenserIdUsed[i] = rtb_Assignment1_o[i];
            }
          }

          rtb_Compare_p = (Switch_m == 0);
          if (rtb_Compare_p) {
            FMTM_B->Switch_p = 1;
          } else {
            int32_T rtb_Switch1_i5;
            boolean_T rtb_Compare_da;
            rtb_Compare_da = (Switch_m == 1);
            if (rtb_Compare_da) {
              rtb_Switch1_i5 = 2;
            } else {
              int32_T rtb_Switch2_c;
              boolean_T rtb_Compare_nxr;
              rtb_Compare_nxr = (Switch_m == 2);
              if (rtb_Compare_nxr) {
                rtb_Switch2_c = 3;
              } else {
                rtb_Switch2_c = 4;
              }

              rtb_Switch1_i5 = rtb_Switch2_c;
            }

            FMTM_B->Switch_p = rtb_Switch1_i5;
          }
        } else {
          FMTM_B->Merge = -10004;
        }

        FMTM_B->Merge1 = FMTM_B->Switch_p;
      }
    }
    break;

   case 3:
    {
      boolean_T rtb_Compare_ck;
      rtb_Compare_ck = (FMTM_U_SenserId == 0);
      if (rtb_Compare_ck) {
        FMTM_Error(&FMTM_B->Merge, &FMTM_B->Merge1);
      } else {
        boolean_T rtb_AND_m;
        s15_iter = -1;
        FoundE = -1;
        FMTM_FindSenserId(FMTM_U_SenserId, &FMTM_B->Switch_l, &s15_iter,
                          FMTM_DW->SenserIdData, FMTM_DW->SenserIdUsed, 256);
        for (s15_iter = 0; s15_iter < 256; s15_iter++) {
          int32_T rtb_DataStoreRead1_al;
          int32_T rtb_ForIterator_a;
          boolean_T rtb_AND_f;
          rtb_ForIterator_a = s15_iter;
          for (i = 0; i < 256; i++) {
            rtb_DataStoreRead_o[i] = FMTM_DW->SenserIdData[i];
            rtb_DataStoreRead2_ny[i] = FMTM_DW->SenserIdUsed[i];
          }

          int32_T rtb_Selector1_b;
          int32_T rtb_Selector_o;
          boolean_T rtb_AND1_i;
          boolean_T rtb_Compare_c;
          boolean_T rtb_Compare_j;
          boolean_T rtb_Equal_o;
          rtb_Selector_o = rtb_DataStoreRead_o[rtb_ForIterator_a];
          rtb_Equal_o = (FMTM_U_TValue == rtb_Selector_o);
          rtb_Selector1_b = rtb_DataStoreRead2_ny[rtb_ForIterator_a];
          rtb_Compare_c = (rtb_Selector1_b == 1);
          rtb_AND1_i = (rtb_Equal_o && rtb_Compare_c);
          rtb_DataStoreRead1_al = FoundE;
          rtb_Compare_j = (rtb_DataStoreRead1_al == -1);
          rtb_AND_f = (rtb_AND1_i && rtb_Compare_j);
          if (rtb_AND_f) {
            i = rtb_ForIterator_a;
          } else {
            i = rtb_DataStoreRead1_al;
          }

          FoundE = i;
        }

        boolean_T rtb_Compare_kf;
        boolean_T rtb_Compare_o;
        rtb_Compare_o = (FMTM_B->Switch_l != -1);
        rtb_Compare_kf = (i != -1);
        rtb_AND_m = (rtb_Compare_o && rtb_Compare_kf);
        if (rtb_AND_m) {
          boolean_T rtb_Compare_e;
          rtb_Compare_e = (FMTM_U_SenserId == 1);
          if (rtb_Compare_e) {
            FMTM_B->Merge = 1001;
          } else {
            int32_T rtb_Switch1_p;
            boolean_T rtb_Compare_bv;
            rtb_Compare_bv = (FMTM_U_SenserId == 2);
            if (rtb_Compare_bv) {
              rtb_Switch1_p = 1002;
            } else {
              int32_T rtb_Switch2_l;
              boolean_T rtb_Compare_oe;
              rtb_Compare_oe = (FMTM_U_SenserId == 4);
              if (rtb_Compare_oe) {
                rtb_Switch2_l = 1004;
              } else {
                int32_T rtb_Switch3_m;
                boolean_T rtb_Compare_ko;
                rtb_Compare_ko = (FMTM_U_SenserId == 8);
                if (rtb_Compare_ko) {
                  rtb_Switch3_m = 1008;
                } else {
                  int32_T rtb_Switch4;
                  boolean_T rtb_Compare_n;
                  rtb_Compare_n = (FMTM_U_SenserId == 16);
                  if (rtb_Compare_n) {
                    rtb_Switch4 = 1016;
                  } else {
                    int32_T rtb_Switch5;
                    boolean_T rtb_Compare_h;
                    rtb_Compare_h = (FMTM_U_SenserId == 32);
                    if (rtb_Compare_h) {
                      rtb_Switch5 = 1032;
                    } else {
                      rtb_Switch5 = FMTM_U_TValue;
                    }

                    rtb_Switch4 = rtb_Switch5;
                  }

                  rtb_Switch3_m = rtb_Switch4;
                }

                rtb_Switch2_l = rtb_Switch3_m;
              }

              rtb_Switch1_p = rtb_Switch2_l;
            }

            FMTM_B->Merge = rtb_Switch1_p;
          }

          FMTM_B->OutportBufferForR = FMTM_ConstB.Constant;
        } else {
          FMTM_B->Merge = -8;
        }

        FMTM_B->Merge1 = FMTM_B->OutportBufferForR;
      }
    }
    break;

   case 4:
    {
      boolean_T rtb_Compare_ct;
      rtb_Compare_ct = (FMTM_U_SenserId == 0);
      if (rtb_Compare_ct) {
        FMTM_Error(&FMTM_B->Merge, &FMTM_B->Merge1);
      } else {
        boolean_T rtb_Compare_eq;
        FoundE = -1;
        for (s15_iter = 0; s15_iter < 256; s15_iter++) {
          int32_T rtb_DataStoreRead1;
          int32_T rtb_ForIterator_b;
          boolean_T rtb_AND;
          rtb_ForIterator_b = s15_iter;
          for (i = 0; i < 256; i++) {
            rtb_DataStoreRead_d[i] = FMTM_DW->SenserIdData[i];
            rtb_DataStoreRead2_i[i] = FMTM_DW->SenserIdUsed[i];
          }

          int32_T rtb_Selector1_f;
          int32_T rtb_Selector_l;
          boolean_T rtb_AND1;
          boolean_T rtb_Compare_if;
          boolean_T rtb_Compare_lx;
          boolean_T rtb_Equal_h;
          rtb_Selector_l = rtb_DataStoreRead_d[rtb_ForIterator_b];
          rtb_Equal_h = (FMTM_U_SenserId == rtb_Selector_l);
          rtb_Selector1_f = rtb_DataStoreRead2_i[rtb_ForIterator_b];
          rtb_Compare_if = (rtb_Selector1_f == 1);
          rtb_AND1 = (rtb_Equal_h && rtb_Compare_if);
          rtb_DataStoreRead1 = FoundE;
          rtb_Compare_lx = (rtb_DataStoreRead1 == -1);
          rtb_AND = (rtb_AND1 && rtb_Compare_lx);
          if (rtb_AND) {
            i = rtb_ForIterator_b;
          } else {
            i = rtb_DataStoreRead1;
          }

          FoundE = i;
        }

        rtb_Compare_eq = (i != -1);
        if (rtb_Compare_eq) {
          FMTM_B->Merge = i;
          FMTM_B->Merge1 = 1;
        } else {
          FMTM_B->Merge = -1;
          FMTM_B->Merge1 = -1;
        }
      }
    }
    break;

   case 5:
    {
      boolean_T rtb_Compare_f0;
      rtb_Compare_f0 = (FMTM_U_SenserId == 0);
      if (rtb_Compare_f0) {
        FMTM_Error(&FMTM_B->Merge, &FMTM_B->Merge1);
      } else {
        uint8_T rtb_Compare;
        FoundE = -1;
        FMTM_FindSenserId(FMTM_U_SenserId, &rtb_Switch_l, &FoundE,
                          FMTM_DW->SenserIdData, FMTM_DW->SenserIdUsed, 256);
        rtb_Compare = (uint8_T)(rtb_Switch_l == -1);
        if (rtb_Compare != 0) {
          FoundE = -8;
        } else {
          int32_T rtb_SenserId;
          rtb_SenserId = FMTM_U_SenserId;
          for (FoundE = 0; FoundE < 256; FoundE++) {
            int32_T rtb_ForIterator;
            int32_T rtb_Switch;
            int32_T rtb_Switch1;
            boolean_T rtb_Equal;
            rtb_ForIterator = FoundE;
            for (i = 0; i < 256; i++) {
              rtb_DataStoreRead[i] = FMTM_DW->SenserIdData[i];
            }

            rtb_Equal = (rtb_SenserId == rtb_ForIterator);
            if (rtb_Equal) {
              rtb_Switch = 0;
            } else {
              int32_T rtb_Selector;
              rtb_Selector = rtb_DataStoreRead[rtb_ForIterator];
              rtb_Switch = rtb_Selector;
            }

            if (FoundE == 0) {
              for (i = 0; i < 256; i++) {
                rtb_Assignment[i] = rtb_DataStoreRead[i];
              }
            }

            rtb_Assignment[rtb_ForIterator] = rtb_Switch;
            for (i = 0; i < 256; i++) {
              FMTM_DW->SenserIdData[i] = rtb_Assignment[i];
              rtb_DataStoreRead2[i] = FMTM_DW->SenserIdUsed[i];
            }

            if (rtb_Equal) {
              rtb_Switch1 = 0;
            } else {
              int32_T rtb_Selector1;
              rtb_Selector1 = rtb_DataStoreRead2[rtb_ForIterator];
              rtb_Switch1 = rtb_Selector1;
            }

            if (FoundE == 0) {
              for (i = 0; i < 256; i++) {
                rtb_Assignment1[i] = rtb_DataStoreRead2[i];
              }
            }

            rtb_Assignment1[rtb_ForIterator] = rtb_Switch1;
            for (i = 0; i < 256; i++) {
              FMTM_DW->SenserIdUsed[i] = rtb_Assignment1[i];
            }
          }

          FoundE = rtb_SenserId;
        }

        FMTM_B->Merge1 = 1;
        FMTM_B->Merge = FoundE;
      }
    }
    break;
  }

  *FMTM_Y_Res = FMTM_B->Merge;
  *FMTM_Y_R = FMTM_B->Merge1;
}

void FMTM_initialize(RT_MODEL_FMTM_T *const FMTM_M, int32_T *FMTM_U_SenserId,
                     int32_T *FMTM_U_Opcode, int32_T *FMTM_U_TValue, int32_T
                     *FMTM_Y_Res, int32_T *FMTM_Y_R)
{
  B_FMTM_T *FMTM_B = FMTM_M->blockIO;
  DW_FMTM_T *FMTM_DW = FMTM_M->dwork;
  (void) memset(((void *) FMTM_B), 0,
                sizeof(B_FMTM_T));
  (void) memset((void *)FMTM_DW, 0,
                sizeof(DW_FMTM_T));
  *FMTM_U_SenserId = 0;
  *FMTM_U_Opcode = 0;
  *FMTM_U_TValue = 0;
  *FMTM_Y_Res = 0;
  *FMTM_Y_R = 0;
  FMTM_B->OutportBufferForR = FMTM_ConstB.Constant;
  FMTM_B->Merge = 0;
  FMTM_B->Merge1 = 0;
}

void FMTM_terminate(RT_MODEL_FMTM_T *const FMTM_M)
{
  UNUSED_PARAMETER(FMTM_M);
}
