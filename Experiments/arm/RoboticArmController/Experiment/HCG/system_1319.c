#include "define.h"
struct system_1319_state system_1319_instance;
void system_1319_Init(struct system_1319_state* self) {
}
void system_1319_Update(struct system_1319_state* self, int FindP, int P1, int P2, int P3) {
    bool CompareTo_Constant_DefaultOutport1 = 0;
    bool CompareTo_Constant1_DefaultOutport1 = 0;
    bool CompareTo_Constant2_DefaultOutport1 = 0;
    int Constant_DefaultOutport1 = 0;
    int Constant1_DefaultOutport1 = 0;
    int Constant2_DefaultOutport1 = 0;
    int Constant3_DefaultOutport1 = 0;
    int * Data_StoreRead_DefaultOutport1 = &(PortPool_ArmIdPool[0]);
    int * Data_StoreRead2_DefaultOutport1 = &(PortPool1_ArmIdPoolF[0]);
    int For_Iterator_DefaultOutport1 = -1;
    float rate_DefaultOutport1 = 0;
    float rate1_DefaultOutport1 = 0;
    bool Equal_DefaultOutport1 = 0;
    int Selector_DefaultOutport1 = 0;
    int Selector1_DefaultOutport1 = 0;
    int Switch2_DefaultOutport1 = 0;
    int Switch_DefaultOutport1 = 0;
    int Switch3_DefaultOutport1 = 0;
    int Assignment_DefaultOutport1[128] = {0};
    unsigned char Assignment_init = 0;
    int Switch4_DefaultOutport1 = 0;
    int Add_DefaultOutport1[128] = {0};
    int Switch1_DefaultOutport1 = 0;
    int Assignment1_DefaultOutport1[128] = {0};
    unsigned char Assignment1_init = 0;
    int Product_DefaultOutport1[128] = {0};
    int Add1_DefaultOutport1[128] = {0};
    int Product1_DefaultOutport1[128] = {0};
    for (int i = 0; i < 128; i++) {
        CompareTo_Constant_DefaultOutport1 = P1 == 3;
        CompareTo_Constant1_DefaultOutport1 = P2 == 4;
        CompareTo_Constant2_DefaultOutport1 = P3 == 5;
        Constant_DefaultOutport1 = 1;
        Constant1_DefaultOutport1 = 3;
        Constant2_DefaultOutport1 = 4;
        Constant3_DefaultOutport1 = 5;
        For_Iterator_DefaultOutport1++;
        rate_DefaultOutport1 = 3;
        rate1_DefaultOutport1 = 3;
        Equal_DefaultOutport1 = FindP == For_Iterator_DefaultOutport1;
        Selector_DefaultOutport1 = Data_StoreRead_DefaultOutport1[For_Iterator_DefaultOutport1];
        Selector1_DefaultOutport1 = Data_StoreRead2_DefaultOutport1[For_Iterator_DefaultOutport1];
        if (CompareTo_Constant_DefaultOutport1 > 0) {
            Switch2_DefaultOutport1 = Constant1_DefaultOutport1;
        }
        else {
            Switch2_DefaultOutport1 = Constant_DefaultOutport1;
        }
        if (Equal_DefaultOutport1 > 0) {
            Switch_DefaultOutport1 = Constant_DefaultOutport1;
        }
        else {
            Switch_DefaultOutport1 = Selector_DefaultOutport1;
        }
        if (CompareTo_Constant1_DefaultOutport1 > 0) {
            Switch3_DefaultOutport1 = Constant2_DefaultOutport1;
        }
        else {
            Switch3_DefaultOutport1 = Switch2_DefaultOutport1;
        }
        if (Assignment_init == 0) {
            Assignment_init = 1;
            int batchIndex = 0;
            for (batchIndex = 0;batchIndex < 128;batchIndex += 4) {
                int32x4_t Data_StoreRead_DefaultOutport1_Batch = vld1q_s32(Data_StoreRead_DefaultOutport1 + batchIndex);
                vst1q_s32(Assignment_DefaultOutport1 + batchIndex, Data_StoreRead_DefaultOutport1_Batch);
            }
        }
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Switch_DefaultOutport1;
        if (CompareTo_Constant2_DefaultOutport1 > 0) {
            Switch4_DefaultOutport1 = Constant3_DefaultOutport1;
        }
        else {
            Switch4_DefaultOutport1 = Switch3_DefaultOutport1;
        }
        int32x4_t Switch4_DefaultOutport1_Batch1 = vdupq_n_s32(Switch4_DefaultOutport1);
        float32x4_t rate_DefaultOutport1_Batch = vdupq_n_f32(rate_DefaultOutport1);
        int batchIndex = 0;
        for (batchIndex = 0;batchIndex < 128;batchIndex += 4) {
            int32x4_t Assignment_DefaultOutport1_Batch = vld1q_s32(Assignment_DefaultOutport1 + batchIndex);
            int32x4_t Add_DefaultOutport1_Batch = {0};
            Add_DefaultOutport1_Batch = vaddq_s32(Assignment_DefaultOutport1_Batch, Switch4_DefaultOutport1_Batch1);
            int32x4_t Product_DefaultOutport1_Batch = {0};
            int32x4_t rate_DefaultOutport1_BatchConvert = vcvtq_s32_f32(rate_DefaultOutport1_Batch);
            Product_DefaultOutport1_Batch = vmulq_s32(Add_DefaultOutport1_Batch, rate_DefaultOutport1_BatchConvert);
            vst1q_s32(Product_DefaultOutport1 + batchIndex, Product_DefaultOutport1_Batch);
        }
        for (int Data_StoreWrite_i = 0;Data_StoreWrite_i < 128;Data_StoreWrite_i++) {
            PortPool_ArmIdPool[Data_StoreWrite_i] = Assignment_DefaultOutport1[Data_StoreWrite_i];
        }
        if (Equal_DefaultOutport1 > 0) {
            Switch1_DefaultOutport1 = Switch4_DefaultOutport1;
        }
        else {
            Switch1_DefaultOutport1 = Selector1_DefaultOutport1;
        }
        if (Assignment1_init == 0) {
            Assignment1_init = 1;
            int batchIndex1 = 0;
            for (batchIndex1 = 0;batchIndex1 < 128;batchIndex1 += 4) {
                int32x4_t Data_StoreRead2_DefaultOutport1_Batch = vld1q_s32(Data_StoreRead2_DefaultOutport1 + batchIndex1);
                vst1q_s32(Assignment1_DefaultOutport1 + batchIndex1, Data_StoreRead2_DefaultOutport1_Batch);
            }
        }
        Assignment1_DefaultOutport1[For_Iterator_DefaultOutport1] = Switch1_DefaultOutport1;
        int32x4_t Switch4_DefaultOutport1_Batch = vdupq_n_s32(Switch4_DefaultOutport1);
        float32x4_t rate1_DefaultOutport1_Batch = vdupq_n_f32(rate1_DefaultOutport1);
        int batchIndex1 = 0;
        for (batchIndex1 = 0;batchIndex1 < 128;batchIndex1 += 4) {
            int32x4_t Assignment1_DefaultOutport1_Batch = vld1q_s32(Assignment1_DefaultOutport1 + batchIndex1);
            int32x4_t Add1_DefaultOutport1_Batch = {0};
            Add1_DefaultOutport1_Batch = vaddq_s32(Assignment1_DefaultOutport1_Batch, Switch4_DefaultOutport1_Batch);
            int32x4_t Product1_DefaultOutport1_Batch = {0};
            int32x4_t rate1_DefaultOutport1_BatchConvert = vcvtq_s32_f32(rate1_DefaultOutport1_Batch);
            Product1_DefaultOutport1_Batch = vmulq_s32(rate1_DefaultOutport1_BatchConvert, Add1_DefaultOutport1_Batch);
            vst1q_s32(Product1_DefaultOutport1 + batchIndex1, Product1_DefaultOutport1_Batch);
        }
        for (int Data_StoreWrite1_i = 0;Data_StoreWrite1_i < 128;Data_StoreWrite1_i++) {
            PortPool1_ArmIdPoolF[Data_StoreWrite1_i] = Assignment1_DefaultOutport1[Data_StoreWrite1_i];
        }
        for (int Data_StoreWrite2_i = 0;Data_StoreWrite2_i < 128;Data_StoreWrite2_i++) {
            angle_Angle[Data_StoreWrite2_i] = Product_DefaultOutport1[Data_StoreWrite2_i];
        }
        for (int Data_StoreWrite3_i = 0;Data_StoreWrite3_i < 128;Data_StoreWrite3_i++) {
            angle1_AngleF[Data_StoreWrite3_i] = Product1_DefaultOutport1[Data_StoreWrite3_i];
        }
    }
}