#include "define.h"
struct system_85_state system_85_instance;
void system_85_Init(struct system_85_state *self)
{
}
void system_85_Update(struct system_85_state *self, int value)
{
    char Constant_DefaultOutport1;
    int Constant1_DefaultOutport1;
    int Constant2_DefaultOutport1;
    char *Data_StoreRead_DefaultOutport1 = &(Data_StoreMemory1_Aflag[0]);
    int *Data_StoreRead1_DefaultOutport1 = &(Data_StoreMemory_A[0]);
    int Data_StoreRead2_DefaultOutport1;
    int Data_StoreRead3_DefaultOutport1;
    int Data_StoreRead4_DefaultOutport1;
    int For_Iterator_DefaultOutport1 = -1;
    bool NOT_DefaultOutport1;
    char Selector_DefaultOutport1;
    int Selector1_DefaultOutport1;
    char Assignment1_DefaultOutport1[16];
    unsigned char Assignment1_init = 0;
    bool OR_DefaultOutport1;
    bool AND_DefaultOutport1;
    bool OR1_DefaultOutport1[16];
    int Switch_DefaultOutport1;
    int Switch3_DefaultOutport1;
    int Assignment_DefaultOutport1[16];
    unsigned char Assignment_init = 0;
    int Switch1_DefaultOutport1;
    char Switch2_DefaultOutport1[16];
    int Add_DefaultOutport1[16];
    int Product_DefaultOutport1[16];
    for (int i = 0; i < 16; i++)
    {
        Constant_DefaultOutport1 = 1;
        Constant1_DefaultOutport1 = 1;
        Constant2_DefaultOutport1 = 0;
        Data_StoreRead2_DefaultOutport1 = Data_StoreMemory_find;
        Data_StoreRead3_DefaultOutport1 = Data_StoreMemory_find;
        Data_StoreRead4_DefaultOutport1 = Data_StoreMemory1_ret_index;
        For_Iterator_DefaultOutport1++;
        NOT_DefaultOutport1 = !Data_StoreRead3_DefaultOutport1;
        Selector_DefaultOutport1 = Data_StoreRead_DefaultOutport1[For_Iterator_DefaultOutport1];
        Selector1_DefaultOutport1 = Data_StoreRead1_DefaultOutport1[For_Iterator_DefaultOutport1];
        if (Assignment1_init == 0)
        {
            Assignment1_init = 1;
            int batchIndex;
            for (batchIndex = 0; batchIndex < 16; batchIndex++)
            {
                Assignment1_DefaultOutport1[batchIndex] = Data_StoreRead_DefaultOutport1[batchIndex];
            }
        }
        Assignment1_DefaultOutport1[For_Iterator_DefaultOutport1] = Selector_DefaultOutport1;
        OR_DefaultOutport1 = (Data_StoreRead2_DefaultOutport1 || Selector_DefaultOutport1);
        AND_DefaultOutport1 = (OR_DefaultOutport1 && NOT_DefaultOutport1);
        if (OR_DefaultOutport1 != 0)
        {
            Switch_DefaultOutport1 = Selector1_DefaultOutport1;
        }
        else
        {
            Switch_DefaultOutport1 = value;
        }
        if (OR_DefaultOutport1 != 0)
        {
            Switch3_DefaultOutport1 = Data_StoreRead4_DefaultOutport1;
        }
        else
        {
            Switch3_DefaultOutport1 = For_Iterator_DefaultOutport1;
        }
        if (Assignment_init == 0)
        {
            Assignment_init = 1;
            int batchIndex;
            for (batchIndex = 0; batchIndex < 16; batchIndex++)
            {
                Assignment_DefaultOutport1[batchIndex] = Data_StoreRead1_DefaultOutport1[batchIndex];
            }
        }
        Assignment_DefaultOutport1[For_Iterator_DefaultOutport1] = Switch_DefaultOutport1;
        Data_StoreMemory1_ret_index = Switch3_DefaultOutport1;
        if (AND_DefaultOutport1 != 0)
        {
            Switch1_DefaultOutport1 = Constant2_DefaultOutport1;
        }
        else
        {
            Switch1_DefaultOutport1 = Constant1_DefaultOutport1;
        }
        Data_StoreMemory_find = Switch1_DefaultOutport1;
    }
    for (int i = 0; i < 16; i++)
    {
        OR1_DefaultOutport1[i] = (Data_StoreRead2_DefaultOutport1 || Assignment1_DefaultOutport1[i]);
        if (OR1_DefaultOutport1 != 0)
        {
            Switch2_DefaultOutport1[i] = Selector_DefaultOutport1;
        }
        else
        {
            Switch2_DefaultOutport1[i] = Constant_DefaultOutport1;
        }
    }
    int batchIndex;
    for (batchIndex = 0; batchIndex < 16; batchIndex++)
    {
        Add_DefaultOutport1[batchIndex] = Assignment_DefaultOutport1[batchIndex] + value;
    }
    for (int Data_StoreWrite_i = 0; Data_StoreWrite_i < 16; Data_StoreWrite_i++)
    {
        Data_StoreMemory_A[Data_StoreWrite_i] = Assignment_DefaultOutport1[Data_StoreWrite_i];
    }
    for (int Data_StoreWrite1_i = 0; Data_StoreWrite1_i < 16; Data_StoreWrite1_i++)
    {
        Data_StoreMemory1_Aflag[Data_StoreWrite1_i] = Switch2_DefaultOutport1[Data_StoreWrite1_i];
    }
    int batchIndex1;
    for (batchIndex1 = 0; batchIndex1 < 16; batchIndex1++)
    {
        Product_DefaultOutport1[batchIndex1] = Add_DefaultOutport1[batchIndex1] * value;
    }
    for (int Data_StoreWrite4_i = 0; Data_StoreWrite4_i < 16; Data_StoreWrite4_i++)
    {
        Data_StoreMemory3_B[Data_StoreWrite4_i] = Product_DefaultOutport1[Data_StoreWrite4_i];
    }
}