#include "define.h"
struct system_76_state system_76_instance;
void system_76_Init(struct system_76_state *self)
{
}
void system_76_Update(struct system_76_state *self, float signal3[32], float signal_o3[32])
{
    float Data_StoreRead_DefaultOutport1 = 0;
    float *Data_StoreRead1_DefaultOutport1 = &(Data_StoreMemory5_S3[0]);
    int For_Iterator_DefaultOutport1 = -1;
    float T_DefaultOutport1 = 0;
    float dt_DefaultOutport1 = 0;
    float Selector_DefaultOutport1 = 0;
    float Selector1_DefaultOutport1 = 0;
    float Add_DefaultOutport1 = 0;
    float Add2_DefaultOutport1 = 0;
    float Product1_DefaultOutport1 = 0;
    float Assignment_DefaultOutport1[32] = {0};
    unsigned char Assignment_init = 0;
    float Add1_DefaultOutport1[32] = {0};
    float Product_DefaultOutport1[32] = {0};
    float Divide_DefaultOutport1[32] = {0};
    float Switch_DefaultOutport1[32] = {0};
    for (int i = 0; i < 32; i++)
    {
        Data_StoreRead_DefaultOutport1 = Data_StoreMemory2_default_hp3;
        For_Iterator_DefaultOutport1++;
        T_DefaultOutport1 = 3;
        dt_DefaultOutport1 = 3.1;
        Selector_DefaultOutport1 = signal3[For_Iterator_DefaultOutport1];
        Selector1_DefaultOutport1 = Data_StoreRead1_DefaultOutport1[For_Iterator_DefaultOutport1];
        Add_DefaultOutport1 = Data_StoreRead_DefaultOutport1 + Selector_DefaultOutport1;
        Add2_DefaultOutport1 = Selector1_DefaultOutport1 + Add_DefaultOutport1;
        Product1_DefaultOutport1 = T_DefaultOutport1 * Add2_DefaultOutport1;
        if (Assignment_init == 0)
        {
            Assignment_init = 1;
            int batchIndex = 0;
            for (batchIndex = 0; batchIndex < 32; batchIndex += 4)
            {
                float32x4_t Data_StoreRead1_DefaultOutport1_Batch =
                    vld1q_f32(Data_StoreRead1_DefaultOutport1 + batchIndex);
                vst1q_f32(Assignment_DefaultOutport1 + batchIndex, Data_StoreRead1_DefaultOutport1_Batch);
            }
        }
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Product1_DefaultOutport1;
        float32x4_t dt_DefaultOutport1_Batch = vdupq_n_f32(dt_DefaultOutport1);
        float32x4_t Data_StoreRead_DefaultOutport1_Batch = vdupq_n_f32(Data_StoreRead_DefaultOutport1);
        int batchIndex = 0;
        for (batchIndex = 0; batchIndex < 32; batchIndex += 4)
        {
            float32x4_t Assignment_DefaultOutport1_Batch = vld1q_f32(Assignment_DefaultOutport1 + batchIndex);
            float32x4_t Add1_DefaultOutport1_Batch = {0};
            Add1_DefaultOutport1_Batch = vaddq_f32(dt_DefaultOutport1_Batch, Assignment_DefaultOutport1_Batch);
            float32x4_t Product_DefaultOutport1_Batch = {0};
            Product_DefaultOutport1_Batch = vmulq_f32(Data_StoreRead_DefaultOutport1_Batch, Add1_DefaultOutport1_Batch);
            float32x4_t Divide_DefaultOutport1_Batch = {0};
            ((float *)&Divide_DefaultOutport1_Batch)[0] =
                ((float *)&Product_DefaultOutport1_Batch)[0] / ((float *)&Data_StoreRead_DefaultOutport1_Batch)[0];
            ((float *)&Divide_DefaultOutport1_Batch)[1] =
                ((float *)&Product_DefaultOutport1_Batch)[1] / ((float *)&Data_StoreRead_DefaultOutport1_Batch)[1];
            ((float *)&Divide_DefaultOutport1_Batch)[2] =
                ((float *)&Product_DefaultOutport1_Batch)[2] / ((float *)&Data_StoreRead_DefaultOutport1_Batch)[2];
            ((float *)&Divide_DefaultOutport1_Batch)[3] =
                ((float *)&Product_DefaultOutport1_Batch)[3] / ((float *)&Data_StoreRead_DefaultOutport1_Batch)[3];
            vst1q_f32(Product_DefaultOutport1 + batchIndex, Product_DefaultOutport1_Batch);
            vst1q_f32(Divide_DefaultOutport1 + batchIndex, Divide_DefaultOutport1_Batch);
        }
        for (int Switch_i = 0; Switch_i < 32; Switch_i++)
        {
            if (Product_DefaultOutport1[Switch_i] > 17.13)
            {
                Switch_DefaultOutport1[Switch_i] = Divide_DefaultOutport1[Switch_i];
            }
            else
            {
                Switch_DefaultOutport1[Switch_i] = Product_DefaultOutport1[Switch_i];
            }
        }
        int batchIndex3 = 0;
        for (batchIndex3 = 0; batchIndex3 < 32; batchIndex3 += 4)
        {
            float32x4_t Switch_DefaultOutport1_Batch = vld1q_f32(Switch_DefaultOutport1 + batchIndex3);
            vst1q_f32(signal_o3 + batchIndex3, Switch_DefaultOutport1_Batch);
        }
    }
}