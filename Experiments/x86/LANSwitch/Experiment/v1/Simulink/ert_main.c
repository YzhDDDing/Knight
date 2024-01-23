#include "LANSwitch.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void *readBinaryFile(const char *filename, size_t *length)
{
    FILE *file;
    void *buffer;
    file = fopen(filename, "rb");
    if (file == NULL)
    {
        perror("Error opening file");
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    *length = ftell(file);
    fseek(file, 0, SEEK_SET);
    buffer = malloc(*length);
    if (buffer == NULL)
    {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }
    if (fread(buffer, 1, *length, file) != *length)
    {
        perror("Error reading file");
        free(buffer);
        fclose(file);
        return NULL;
    }
    fclose(file);
    return buffer;
}
int inputsDataLengthTotal = 20;
static RT_MODEL_LANSwitch_T LANSwitch_M_;
static RT_MODEL_LANSwitch_T *const LANSwitch_MPtr = &LANSwitch_M_;
static B_LANSwitch_T LANSwitch_B;
static DW_LANSwitch_T LANSwitch_DW;
static int32_T LANSwitch_U_PortId;
static int32_T LANSwitch_U_CMD;
static int32_T LANSwitch_U_Arg1;
static int32_T LANSwitch_U_Arg2;
static int32_T LANSwitch_U_Arg3;
static int32_T LANSwitch_Y_Result;
static int32_T LANSwitch_Y_MSG;
void rt_OneStep(RT_MODEL_LANSwitch_T *const LANSwitch_M);
void rt_OneStep(RT_MODEL_LANSwitch_T *const LANSwitch_M)
{
    static boolean_T OverrunFlag = false;
    if (OverrunFlag)
    {
        rtmSetErrorStatus(LANSwitch_M, "Overrun");
        return;
    }

    OverrunFlag = true;
    LANSwitch_step(LANSwitch_M, LANSwitch_U_PortId, LANSwitch_U_CMD, LANSwitch_U_Arg1, LANSwitch_U_Arg2,
                   LANSwitch_U_Arg3, &LANSwitch_Y_Result, &LANSwitch_Y_MSG);
    OverrunFlag = false;
}

int_T main(int_T argc, const char *argv[])
{
    int testCount = (argc > 1 ? atoi(argv[1]) : 1);
    RT_MODEL_LANSwitch_T *const LANSwitch_M = LANSwitch_MPtr;
    size_t length;
    char *dataBuf = readBinaryFile("../../../TestCases/merged.bin", &length);
    (void)(argc);
    (void)(argv);
    LANSwitch_M->blockIO = &LANSwitch_B;
    LANSwitch_M->dwork = &LANSwitch_DW;
    LANSwitch_initialize(LANSwitch_M, &LANSwitch_U_PortId, &LANSwitch_U_CMD, &LANSwitch_U_Arg1, &LANSwitch_U_Arg2,
                         &LANSwitch_U_Arg3, &LANSwitch_Y_Result, &LANSwitch_Y_MSG);
    clock_t testStartTime = clock();
    for (int j = 0; j < testCount; j++)
    {
        for (int i = 0; i < 16777216; i++)
        {
            if ((i + 1) * inputsDataLengthTotal > length)
            {
                break;
            }
            memcpy(&LANSwitch_U_PortId, dataBuf + i * inputsDataLengthTotal + 0, 4);
            memcpy(&LANSwitch_U_CMD, dataBuf + i * inputsDataLengthTotal + 4, 4);
            memcpy(&LANSwitch_U_Arg1, dataBuf + i * inputsDataLengthTotal + 8, 4);
            memcpy(&LANSwitch_U_Arg2, dataBuf + i * inputsDataLengthTotal + 12, 4);
            memcpy(&LANSwitch_U_Arg3, dataBuf + i * inputsDataLengthTotal + 16, 4);
            LANSwitch_step(LANSwitch_M, LANSwitch_U_PortId, LANSwitch_U_CMD, LANSwitch_U_Arg1, LANSwitch_U_Arg2,
                           LANSwitch_U_Arg3, &LANSwitch_Y_Result, &LANSwitch_Y_MSG);
        }
    }
    free(dataBuf);
    clock_t testEndTime = clock();
    long long testCostTime = (testEndTime - testStartTime);
    printf("run %d times, cost : %lld\n", testCount, testCostTime);
    // printf("run %d times, cost : %lld\n", 100, testCostTime);
    // printf("LANSwitch_U_PortId: %d.\n", LANSwitch_U_PortId);
    // printf("LANSwitch_U_CMD: %d.\n", LANSwitch_U_CMD);
    // printf("LANSwitch_U_Arg1: %d.\n", LANSwitch_U_Arg1);
    // printf("LANSwitch_U_Arg2: %d.\n", LANSwitch_U_Arg2);
    // printf("LANSwitch_U_Arg3: %d.\n", LANSwitch_U_Arg3);
    // printf("LANSwitch_Y_Result: %d.\n", LANSwitch_Y_Result);
    // printf("LANSwitch_Y_MSG: %d.\n", LANSwitch_Y_MSG);
    return 0;
}
