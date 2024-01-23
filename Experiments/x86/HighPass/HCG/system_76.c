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
                __m128 Data_StoreRead1_DefaultOutport1_Batch =
                    _mm_load_ps(Data_StoreRead1_DefaultOutport1 + batchIndex);
                _mm_store_ps(Assignment_DefaultOutport1 + batchIndex, Data_StoreRead1_DefaultOutport1_Batch);
            }
        }
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Product1_DefaultOutport1;
        __m128 dt_DefaultOutport1_Batch = _mm_set1_ps(dt_DefaultOutport1);
        __m128 Data_StoreRead_DefaultOutport1_Batch = _mm_set1_ps(Data_StoreRead_DefaultOutport1);
        int batchIndex = 0;
        for (batchIndex = 0; batchIndex < 32; batchIndex += 4)
        {
            __m128 Assignment_DefaultOutport1_Batch = _mm_load_ps(Assignment_DefaultOutport1 + batchIndex);
            __m128 Add1_DefaultOutport1_Batch = {0};
            Add1_DefaultOutport1_Batch = _mm_add_ps(dt_DefaultOutport1_Batch, Assignment_DefaultOutport1_Batch);
            __m128 Product_DefaultOutport1_Batch = {0};
            Product_DefaultOutport1_Batch =
                _mm_mul_ps(Data_StoreRead_DefaultOutport1_Batch, Add1_DefaultOutport1_Batch);
            __m128 Divide_DefaultOutport1_Batch = {0};
            Divide_DefaultOutport1_Batch =
                _mm_div_ps(Product_DefaultOutport1_Batch, Data_StoreRead_DefaultOutport1_Batch);
            _mm_store_ps(Product_DefaultOutport1 + batchIndex, Product_DefaultOutport1_Batch);
            _mm_store_ps(Divide_DefaultOutport1 + batchIndex, Divide_DefaultOutport1_Batch);
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
            __m128 Switch_DefaultOutport1_Batch = _mm_load_ps(Switch_DefaultOutport1 + batchIndex3);
            _mm_store_ps(signal_o3 + batchIndex3, Switch_DefaultOutport1_Batch);
        }
    }
}