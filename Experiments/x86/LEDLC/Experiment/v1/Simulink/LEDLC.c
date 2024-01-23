#include "LEDLC.h"
#include "rtwtypes.h"
#include <string.h>

void LEDLC_step(RT_MODEL_LEDLC_T *const LEDLC_M, real32_T LEDLC_U_t, int32_T
                *LEDLC_Y_Output)
{
  B_LEDLC_T *LEDLC_B = LEDLC_M->blockIO;
  DW_LEDLC_T *LEDLC_DW = LEDLC_M->dwork;
  int32_T rtb_Assignment1[64];
  int32_T rtb_Assignment_j[64];
  int32_T rtb_DataStoreRead1_f[64];
  int32_T i;
  int32_T rtb_DataStoreRead1_b;
  int32_T rtb_DataStoreRead1_p;
  int32_T rtb_DataStoreRead2_p;
  int32_T rtb_DataStoreRead_e;
  int32_T rtb_DataStoreRead_m;
  int32_T s41_iter;
  real32_T rtb_Assignment[64];
  real32_T rtb_Assignment_n[64];
  real32_T rtb_DataStoreRead[64];
  real32_T rtb_DataStoreRead_nn;
  rtb_DataStoreRead1_p = LEDLC_DW->Init;
  if (rtb_DataStoreRead1_p == 0) {
    LEDLC_DW->Init = 1;
    LEDLC_DW->Terminate = 0;
    LEDLC_DW->State = 0;
    for (s41_iter = 0; s41_iter < 64; s41_iter++) {
      int32_T rtb_ForIterator_j;
      rtb_ForIterator_j = s41_iter;
      for (i = 0; i < 64; i++) {
        rtb_DataStoreRead_nn = LEDLC_DW->Data[i];
        if (s41_iter == 0) {
          rtb_Assignment_n[i] = rtb_DataStoreRead_nn;
        }
      }

      rtb_Assignment_n[rtb_ForIterator_j] = 0.0F;
      for (i = 0; i < 64; i++) {
        LEDLC_DW->Data[i] = rtb_Assignment_n[i];
        rtb_DataStoreRead1_b = LEDLC_DW->Satisfied[i];
        if (s41_iter == 0) {
          rtb_Assignment1[i] = rtb_DataStoreRead1_b;
        }
      }

      rtb_Assignment1[rtb_ForIterator_j] = 0;
      for (i = 0; i < 64; i++) {
        LEDLC_DW->Satisfied[i] = rtb_Assignment1[i];
      }
    }
  }

  s41_iter = -1;
  for (i = 0; i < 64; i++) {
    int32_T rtb_DataStoreRead_p;
    int32_T rtb_ForIterator_d;
    int32_T rtb_Selector_a;
    int32_T rtb_Switch_f;
    boolean_T rtb_AND_k0;
    boolean_T rtb_Compare_dj;
    boolean_T rtb_Compare_p4;
    rtb_DataStoreRead1_f[i] = LEDLC_DW->Satisfied[i];
    rtb_ForIterator_d = i;
    rtb_DataStoreRead_p = s41_iter;
    rtb_Compare_dj = (rtb_DataStoreRead_p == -1);
    rtb_Selector_a = rtb_DataStoreRead1_f[rtb_ForIterator_d];
    rtb_Compare_p4 = (rtb_Selector_a == 0);
    rtb_AND_k0 = (rtb_Compare_dj && rtb_Compare_p4);
    if (rtb_AND_k0) {
      rtb_Switch_f = rtb_ForIterator_d;
    } else {
      rtb_Switch_f = rtb_DataStoreRead_p;
    }

    s41_iter = rtb_Switch_f;
  }

  rtb_DataStoreRead2_p = s41_iter;
  if (rtb_DataStoreRead2_p != -1) {
    int32_T rtb_DataStoreRead_c;
    real32_T rtb_Switch;
    boolean_T rtb_AND_o;
    boolean_T rtb_Compare_i;
    boolean_T rtb_Compare_p;
    rtb_Compare_p = (LEDLC_U_t <= 2.0F);
    rtb_Compare_i = (LEDLC_U_t >= 1.0F);
    rtb_AND_o = (rtb_Compare_p && rtb_Compare_i);
    if (rtb_AND_o) {
      rtb_Switch = 1.5F;
    } else {
      rtb_Switch = LEDLC_U_t;
    }

    rtb_DataStoreRead_c = s41_iter;
    for (i = 0; i < 64; i++) {
      rtb_DataStoreRead_nn = LEDLC_DW->Data[i];
      rtb_Assignment[i] = rtb_DataStoreRead_nn;
    }

    rtb_Assignment[rtb_DataStoreRead_c] = rtb_Switch;
    for (i = 0; i < 64; i++) {
      LEDLC_DW->Data[i] = rtb_Assignment[i];
    }
  }

  rtb_DataStoreRead_e = LEDLC_DW->Terminate;
  if (rtb_DataStoreRead_e <= 0) {
    LEDLC_DW->Terminate = 1;
  }

  for (i = 0; i < 64; i++) {
    rtb_DataStoreRead[i] = LEDLC_DW->Data[i];
  }

  for (s41_iter = 0; s41_iter < 64; s41_iter++) {
    int32_T rtb_ForIterator;
    int32_T rtb_Switch1;
    int32_T rtb_Switch2;
    int32_T rtb_Switch_a;
    real32_T rtb_Add;
    real32_T rtb_Gain;
    real32_T rtb_Selector;
    real32_T rtb_Selector1;
    boolean_T rtb_AND_a;
    boolean_T rtb_RelationalOperator;
    boolean_T rtb_RelationalOperator1;
    rtb_ForIterator = s41_iter;
    rtb_Selector = rtb_DataStoreRead[rtb_ForIterator];
    if (rtb_ForIterator != 0) {
      int32_T rtb_AddConstant1;
      rtb_AddConstant1 = rtb_ForIterator;
      rtb_Switch_a = rtb_AddConstant1 - 1;
    } else {
      rtb_Switch_a = 0;
    }

    rtb_Selector1 = rtb_DataStoreRead[rtb_Switch_a];
    rtb_Add = rtb_Selector + rtb_Selector1;
    rtb_Gain = 2.34F * rtb_Add;
    rtb_RelationalOperator = (rtb_Gain <= 18.4);
    rtb_RelationalOperator1 = (rtb_Gain >= 1.2);
    rtb_AND_a = (rtb_RelationalOperator && rtb_RelationalOperator1);
    if (rtb_AND_a) {
      int32_T rtb_DataStoreRead1_nn;
      rtb_DataStoreRead1_nn = LEDLC_DW->Terminate;
      rtb_Switch1 = rtb_DataStoreRead1_nn;
    } else {
      rtb_Switch1 = 0;
    }

    LEDLC_DW->Terminate = rtb_Switch1;
    rtb_Switch2 = rtb_AND_a;
    for (i = 0; i < 64; i++) {
      rtb_DataStoreRead1_b = LEDLC_DW->Satisfied[i];
      if (s41_iter == 0) {
        rtb_Assignment_j[i] = rtb_DataStoreRead1_b;
      }
    }

    rtb_Assignment_j[rtb_ForIterator] = rtb_Switch2;
    for (i = 0; i < 64; i++) {
      LEDLC_DW->Satisfied[i] = rtb_Assignment_j[i];
    }
  }

  rtb_DataStoreRead_m = LEDLC_DW->Terminate;
  if (rtb_DataStoreRead_m != 0) {
    int32_T rtb_DataStoreRead_pu;
    rtb_DataStoreRead_pu = LEDLC_DW->State;
    switch (rtb_DataStoreRead_pu) {
     case 0:
      LEDLC_DW->State = 1;
      LEDLC_B->Merge = 1;
      break;

     case 1:
      {
        if (LEDLC_U_t >= 2.0F) {
          boolean_T rtb_AND_j;
          boolean_T rtb_Compare_me;
          boolean_T rtb_Compare_o;
          rtb_Compare_me = (LEDLC_U_t > 7.0F);
          rtb_Compare_o = (LEDLC_U_t < 11.0F);
          rtb_AND_j = (rtb_Compare_me && rtb_Compare_o);
          if (rtb_AND_j) {
            LEDLC_B->Merge = -1;
          } else {
            LEDLC_B->Merge = -3;
          }
        } else {
          boolean_T rtb_AND_d;
          boolean_T rtb_Compare_f;
          boolean_T rtb_Compare_pf;
          LEDLC_DW->State = 2;
          rtb_Compare_pf = (LEDLC_U_t > 0.5F);
          rtb_Compare_f = (LEDLC_U_t < 1.0F);
          rtb_AND_d = (rtb_Compare_pf && rtb_Compare_f);
          if (rtb_AND_d) {
            LEDLC_B->Merge = 1;
          } else {
            LEDLC_B->Merge = 3;
          }
        }
      }
      break;

     case 2:
      {
        if (LEDLC_U_t > 9.0F) {
          boolean_T rtb_AND_l;
          boolean_T rtb_Compare_ey;
          boolean_T rtb_Compare_j;
          rtb_Compare_ey = (LEDLC_U_t > 19.0F);
          rtb_Compare_j = (LEDLC_U_t < 23.0F);
          rtb_AND_l = (rtb_Compare_ey && rtb_Compare_j);
          if (rtb_AND_l) {
            LEDLC_B->Merge = -1;
          } else {
            LEDLC_B->Merge = -3;
          }
        } else {
          boolean_T rtb_AND;
          boolean_T rtb_Compare_b;
          boolean_T rtb_Compare_k;
          LEDLC_DW->State = 3;
          rtb_Compare_b = (LEDLC_U_t > 2.5F);
          rtb_Compare_k = (LEDLC_U_t < 5.5F);
          rtb_AND = (rtb_Compare_b && rtb_Compare_k);
          if (rtb_AND) {
            LEDLC_B->Merge = -1;
          } else {
            LEDLC_B->Merge = -3;
          }
        }
      }
      break;

     case 3:
      LEDLC_DW->State = 4;
      break;

     case 4:
      {
        if (LEDLC_U_t != -1.0F) {
          boolean_T rtb_Compare;
          rtb_Compare = (LEDLC_U_t != 9.0F);
          if (rtb_Compare) {
            LEDLC_B->Switch = -1;
          } else {
            LEDLC_B->Switch = -3;
          }
        }

        LEDLC_B->Merge = LEDLC_B->Switch;
      }
      break;

     default:
      LEDLC_B->Merge = -1;
      break;
    }
  }

  *LEDLC_Y_Output = LEDLC_B->Merge;
}

void LEDLC_initialize(RT_MODEL_LEDLC_T *const LEDLC_M, real32_T *LEDLC_U_t,
                      int32_T *LEDLC_Y_Output)
{
  B_LEDLC_T *LEDLC_B = LEDLC_M->blockIO;
  DW_LEDLC_T *LEDLC_DW = LEDLC_M->dwork;
  (void) memset(((void *) LEDLC_B), 0,
                sizeof(B_LEDLC_T));
  (void) memset((void *)LEDLC_DW, 0,
                sizeof(DW_LEDLC_T));
  *LEDLC_U_t = 0.0F;
  *LEDLC_Y_Output = 0;
  LEDLC_B->Merge = 0;
}

void LEDLC_terminate(RT_MODEL_LEDLC_T *const LEDLC_M)
{
  UNUSED_PARAMETER(LEDLC_M);
}
