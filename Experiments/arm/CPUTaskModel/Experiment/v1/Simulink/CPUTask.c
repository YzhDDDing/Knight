#include "CPUTask.h"
#include "rtwtypes.h"
#include "CPUTask_private.h"
#include <string.h>

void CPUTask_FunctionCallSubsystem(int32_T *rtd_find_n, int32_T *rtd_ret_index_a)
{
  *rtd_find_n = 0;
  *rtd_ret_index_a = -1;
}

void CPUTask_step(RT_MODEL_CPUTask_T *const CPUTask_M, ExtU_CPUTask_T *CPUTask_U,
                  ExtY_CPUTask_T *CPUTask_Y)
{
  DW_CPUTask_T *CPUTask_DW = CPUTask_M->dwork;
  int32_T rtb_Assignment[16];
  int32_T rtb_Assignment1[16];
  int32_T rtb_DataStoreRead1[16];
  int32_T rtb_DataStoreRead1_j[16];
  int32_T rtb_DataStoreRead1_l[16];
  int32_T rtb_DataStoreRead1_o[16];
  int32_T find_n;
  int32_T i;
  int32_T s11_iter;
  int32_T s26_iter;
  int8_T rtb_Assignment1_c[16];
  int8_T rtb_Assignment1_m[16];
  int8_T rtb_Assignment_m[16];
  int8_T rtb_DataStoreRead[16];
  int8_T rtb_DataStoreRead_b[16];
  int8_T rtb_DataStoreRead_g[16];
  int8_T rtb_DataStoreRead_h[16];
  int8_T rtb_DataStoreRead_k;
  int8_T rtb_DataStoreRead_nq;
  rtb_DataStoreRead_k = CPUTask_DW->Init;
  if (rtb_DataStoreRead_k <= 0) {
    CPUTask_DW->Init = 1;
    for (s26_iter = 0; s26_iter < 16; s26_iter++) {
      int32_T rtb_ForIterator_h;
      rtb_ForIterator_h = s26_iter;
      for (i = 0; i < 16; i++) {
        rtb_DataStoreRead_nq = CPUTask_DW->Aflag[i];
        if (s26_iter == 0) {
          rtb_Assignment_m[i] = rtb_DataStoreRead_nq;
        }
      }

      rtb_Assignment_m[rtb_ForIterator_h] = 0;
      for (i = 0; i < 16; i++) {
        CPUTask_DW->Aflag[i] = rtb_Assignment_m[i];
      }
    }
  }

  switch (CPUTask_U->op) {
   case 1:
    {
      int32_T rtb_DataStoreRead2_d;
      CPUTask_FunctionCallSubsystem(&find_n, &s26_iter);
      for (s11_iter = 0; s11_iter < 16; s11_iter++) {
        int32_T rtb_DataStoreRead2_c;
        int32_T rtb_ForIterator_m;
        int32_T rtb_Switch;
        int32_T rtb_Switch3_b;
        int8_T rtb_Selector_a;
        boolean_T rtb_OR_a;
        rtb_ForIterator_m = s11_iter;
        rtb_DataStoreRead2_c = find_n;
        for (i = 0; i < 16; i++) {
          rtb_DataStoreRead1_j[i] = CPUTask_DW->A[i];
          rtb_DataStoreRead_g[i] = CPUTask_DW->Aflag[i];
        }

        rtb_Selector_a = rtb_DataStoreRead_g[rtb_ForIterator_m];
        rtb_OR_a = ((rtb_DataStoreRead2_c != 0) || (rtb_Selector_a != 0));
        if (rtb_OR_a) {
          int32_T rtb_Selector1_n;
          rtb_Selector1_n = rtb_DataStoreRead1_j[rtb_ForIterator_m];
          rtb_Switch = rtb_Selector1_n;
        } else {
          rtb_Switch = CPUTask_U->taskId;
        }

        if (s11_iter == 0) {
          for (i = 0; i < 16; i++) {
            rtb_Assignment[i] = rtb_DataStoreRead1_j[i];
          }
        }

        rtb_Assignment[rtb_ForIterator_m] = rtb_Switch;
        for (i = 0; i < 16; i++) {
          CPUTask_DW->A[i] = rtb_Assignment[i];
          if (s11_iter == 0) {
            rtb_Assignment1_c[i] = rtb_DataStoreRead_g[i];
          }
        }

        rtb_Assignment1_c[rtb_ForIterator_m] = rtb_Selector_a;
        for (i = 0; i < 16; i++) {
          boolean_T rtb_OR1_a;
          rtb_OR1_a = ((rtb_DataStoreRead2_c != 0) || (rtb_Assignment1_c[i] != 0));
          if (rtb_OR1_a) {
            rtb_DataStoreRead_nq = rtb_Selector_a;
          } else {
            rtb_DataStoreRead_nq = 1;
          }

          CPUTask_DW->Aflag[i] = rtb_DataStoreRead_nq;
        }

        int32_T rtb_DataStoreRead3_co;
        int32_T rtb_Switch1_h;
        boolean_T rtb_AND_h;
        boolean_T rtb_NOT_ji;
        rtb_DataStoreRead3_co = find_n;
        rtb_NOT_ji = (rtb_DataStoreRead3_co == 0);
        rtb_AND_h = (rtb_OR_a && rtb_NOT_ji);
        rtb_Switch1_h = !rtb_AND_h;
        find_n = rtb_Switch1_h;
        if (rtb_OR_a) {
          int32_T rtb_DataStoreRead4_h;
          rtb_DataStoreRead4_h = s26_iter;
          rtb_Switch3_b = rtb_DataStoreRead4_h;
        } else {
          rtb_Switch3_b = rtb_ForIterator_m;
        }

        s26_iter = rtb_Switch3_b;
      }

      rtb_DataStoreRead2_d = find_n;
      if (rtb_DataStoreRead2_d != 0) {
        find_n = 1;
      } else {
        find_n = -1;
      }
    }
    break;

   case 2:
    {
      CPUTask_FunctionCallSubsystem(&find_n, &s26_iter);
      for (s11_iter = 0; s11_iter < 16; s11_iter++) {
        int32_T rtb_DataStoreRead2_iv;
        int32_T rtb_ForIterator_mv;
        int32_T rtb_Switch3_e;
        int8_T rtb_Selector_n;
        int8_T rtb_Switch2_c;
        boolean_T rtb_OR_j;
        rtb_ForIterator_mv = s11_iter;
        rtb_DataStoreRead2_iv = find_n;
        for (i = 0; i < 16; i++) {
          rtb_DataStoreRead_b[i] = CPUTask_DW->Aflag[i];
          rtb_DataStoreRead1_o[i] = CPUTask_DW->A[i];
        }

        int32_T rtb_Selector1_a;
        int32_T rtb_Subtract_e;
        boolean_T rtb_NOT1_f;
        boolean_T rtb_OR1;
        rtb_Selector_n = rtb_DataStoreRead_b[rtb_ForIterator_mv];
        rtb_NOT1_f = (rtb_Selector_n == 0);
        rtb_OR1 = ((rtb_DataStoreRead2_iv != 0) || rtb_NOT1_f);
        rtb_Selector1_a = rtb_DataStoreRead1_o[rtb_ForIterator_mv];
        rtb_Subtract_e = rtb_Selector1_a - CPUTask_U->taskId;
        rtb_OR_j = (rtb_OR1 || (rtb_Subtract_e != 0));
        if (rtb_OR_j) {
          int32_T rtb_DataStoreRead4_l;
          rtb_DataStoreRead4_l = s26_iter;
          rtb_Switch3_e = rtb_DataStoreRead4_l;
          rtb_Switch2_c = rtb_Selector_n;
        } else {
          rtb_Switch3_e = rtb_ForIterator_mv;
          rtb_Switch2_c = 0;
        }

        s26_iter = rtb_Switch3_e;
        if (s11_iter == 0) {
          for (i = 0; i < 16; i++) {
            rtb_Assignment1_m[i] = rtb_DataStoreRead_b[i];
          }
        }

        rtb_Assignment1_m[rtb_ForIterator_mv] = rtb_Switch2_c;
        for (i = 0; i < 16; i++) {
          CPUTask_DW->Aflag[i] = rtb_Assignment1_m[i];
        }

        int32_T rtb_DataStoreRead3_h;
        int32_T rtb_Switch1_p;
        boolean_T rtb_AND_g;
        boolean_T rtb_NOT_d;
        rtb_DataStoreRead3_h = find_n;
        rtb_NOT_d = (rtb_DataStoreRead3_h == 0);
        rtb_AND_g = (rtb_OR_j && rtb_NOT_d);
        rtb_Switch1_p = !rtb_AND_g;
        find_n = rtb_Switch1_p;
      }
    }
    break;

   case 3:
    {
      CPUTask_FunctionCallSubsystem(&find_n, &s26_iter);
      for (s11_iter = 0; s11_iter < 16; s11_iter++) {
        int32_T rtb_DataStoreRead2_f;
        int32_T rtb_DataStoreRead3_a;
        int32_T rtb_ForIterator_n;
        int32_T rtb_Selector1_e;
        int32_T rtb_Switch1_j;
        int32_T rtb_Switch2;
        int32_T rtb_Switch3_p;
        boolean_T rtb_AND_e;
        boolean_T rtb_NOT_n;
        boolean_T rtb_OR_l;
        rtb_ForIterator_n = s11_iter;
        rtb_DataStoreRead2_f = find_n;
        for (i = 0; i < 16; i++) {
          rtb_DataStoreRead_h[i] = CPUTask_DW->Aflag[i];
          rtb_DataStoreRead1_l[i] = CPUTask_DW->A[i];
        }

        int32_T rtb_Subtract_o;
        int8_T rtb_Selector_i;
        boolean_T rtb_NOT1_o;
        rtb_Selector_i = rtb_DataStoreRead_h[rtb_ForIterator_n];
        rtb_NOT1_o = (rtb_Selector_i == 0);
        rtb_Selector1_e = rtb_DataStoreRead1_l[rtb_ForIterator_n];
        rtb_Subtract_o = rtb_Selector1_e - CPUTask_U->taskId;
        rtb_OR_l = ((rtb_DataStoreRead2_f != 0) || rtb_NOT1_o || (rtb_Subtract_o
          != 0));
        if (rtb_OR_l) {
          int32_T rtb_DataStoreRead4_d;
          rtb_DataStoreRead4_d = s26_iter;
          rtb_Switch3_p = rtb_DataStoreRead4_d;
        } else {
          rtb_Switch3_p = rtb_ForIterator_n;
        }

        s26_iter = rtb_Switch3_p;
        rtb_DataStoreRead3_a = find_n;
        rtb_NOT_n = (rtb_DataStoreRead3_a == 0);
        rtb_AND_e = (rtb_OR_l && rtb_NOT_n);
        rtb_Switch1_j = !rtb_AND_e;
        find_n = rtb_Switch1_j;
        if (rtb_OR_l) {
          rtb_Switch2 = rtb_Selector1_e;
        } else {
          rtb_Switch2 = CPUTask_U->para;
        }

        if (s11_iter == 0) {
          for (i = 0; i < 16; i++) {
            rtb_Assignment1[i] = rtb_DataStoreRead1_l[i];
          }
        }

        rtb_Assignment1[rtb_ForIterator_n] = rtb_Switch2;
        for (i = 0; i < 16; i++) {
          CPUTask_DW->A[i] = rtb_Assignment1[i];
        }
      }
    }
    break;

   case 4:
    {
      CPUTask_FunctionCallSubsystem(&find_n, &s26_iter);
      for (i = 0; i < 16; i++) {
        int32_T rtb_DataStoreRead2;
        int32_T rtb_DataStoreRead3;
        int32_T rtb_ForIterator;
        int32_T rtb_Selector1;
        int32_T rtb_Subtract;
        int32_T rtb_Switch1;
        int32_T rtb_Switch3;
        int8_T rtb_Selector;
        boolean_T rtb_AND;
        boolean_T rtb_NOT;
        boolean_T rtb_NOT1;
        boolean_T rtb_OR;
        rtb_DataStoreRead[i] = CPUTask_DW->Aflag[i];
        rtb_DataStoreRead1[i] = CPUTask_DW->A[i];
        rtb_ForIterator = i;
        rtb_DataStoreRead2 = find_n;
        rtb_Selector = rtb_DataStoreRead[rtb_ForIterator];
        rtb_NOT1 = (rtb_Selector == 0);
        rtb_Selector1 = rtb_DataStoreRead1[rtb_ForIterator];
        rtb_Subtract = rtb_Selector1 - CPUTask_U->taskId;
        rtb_OR = ((rtb_DataStoreRead2 != 0) || rtb_NOT1 || (rtb_Subtract != 0));
        if (rtb_OR) {
          int32_T rtb_DataStoreRead4;
          rtb_DataStoreRead4 = s26_iter;
          rtb_Switch3 = rtb_DataStoreRead4;
        } else {
          rtb_Switch3 = rtb_ForIterator;
        }

        s26_iter = rtb_Switch3;
        rtb_DataStoreRead3 = find_n;
        rtb_NOT = (rtb_DataStoreRead3 == 0);
        rtb_AND = (rtb_OR && rtb_NOT);
        rtb_Switch1 = !rtb_AND;
        find_n = rtb_Switch1;
      }
    }
    break;

   default:
    find_n = -1;
    s26_iter = -1;
    break;
  }

  CPUTask_Y->res = find_n;
  CPUTask_Y->out = s26_iter;
}

void CPUTask_initialize(RT_MODEL_CPUTask_T *const CPUTask_M, ExtU_CPUTask_T
  *CPUTask_U, ExtY_CPUTask_T *CPUTask_Y)
{
  DW_CPUTask_T *CPUTask_DW = CPUTask_M->dwork;
  (void) memset((void *)CPUTask_DW, 0,
                sizeof(DW_CPUTask_T));
  (void)memset(CPUTask_U, 0, sizeof(ExtU_CPUTask_T));
  (void)memset(CPUTask_Y, 0, sizeof(ExtY_CPUTask_T));
}

void CPUTask_terminate(RT_MODEL_CPUTask_T *const CPUTask_M)
{
  UNUSED_PARAMETER(CPUTask_M);
}
