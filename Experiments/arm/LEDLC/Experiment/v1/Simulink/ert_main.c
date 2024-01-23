#include "LEDLC.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void *readBinaryFile(const char *filename, size_t *len)
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
    *len = ftell(file);
    fseek(file, 0, SEEK_SET);
    buffer = malloc(*len);
    if (buffer == NULL)
    {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }
    if (fread(buffer, 1, *len, file) != *len)
    {
        perror("Error reading file");
        free(buffer);
        fclose(file);
        return NULL;
    }
    fclose(file);
    return buffer;
}

static RT_MODEL_LEDLC_T LEDLC_M_;
static RT_MODEL_LEDLC_T *const LEDLC_MPtr = &LEDLC_M_;
static B_LEDLC_T LEDLC_B;
static DW_LEDLC_T LEDLC_DW;
static real32_T LEDLC_U_t;
static int32_T LEDLC_Y_Output;
void rt_OneStep(RT_MODEL_LEDLC_T *const LEDLC_M);
void rt_OneStep(RT_MODEL_LEDLC_T *const LEDLC_M)
{
    static boolean_T OverrunFlag = false;
    if (OverrunFlag)
    {
        rtmSetErrorStatus(LEDLC_M, "Overrun");
        return;
    }

    OverrunFlag = true;
    LEDLC_step(LEDLC_M, LEDLC_U_t, &LEDLC_Y_Output);
    OverrunFlag = false;
}

int_T main(int_T argc, const char *argv[])
{
    int testCount = (argc > 1 ? atoi(argv[1]) : 1);
    size_t len;
    char *dataBuf = readBinaryFile("../../../TestCases/merged.bin", &len);
    int inputsDatalenTotal = 4;
    RT_MODEL_LEDLC_T *const LEDLC_M = LEDLC_MPtr;
    (void)(argc);
    (void)(argv);
    LEDLC_M->blockIO = &LEDLC_B;
    LEDLC_M->dwork = &LEDLC_DW;
    LEDLC_initialize(LEDLC_M, &LEDLC_U_t, &LEDLC_Y_Output);

    clock_t testStartTime = clock();
    for (int j = 0; j < testCount; j++)
    {
        for (int i = 0; i < 16777216; i++)
        {
            if ((i + 1) * inputsDatalenTotal > len)
            {
                break;
            }
            memcpy(&LEDLC_U_t, dataBuf + i * inputsDatalenTotal + 0, 4);
            LEDLC_step(LEDLC_M, LEDLC_U_t, &LEDLC_Y_Output);
        }
    }
    free(dataBuf);
    clock_t testEndTime = clock();
    long long testCostTime = (testEndTime - testStartTime);
    printf("run %d times, cost : %lld\n", testCount, testCostTime);
    // printf("exec_SenserId: %d\n", exec_SenserId);
    // printf("exec_Opcode: %d\n", exec_Opcode);
    // printf("exec_TValue: %d\n", exec_TValue);
    // printf("exec_Res: %d\n", exec_Res);
    // printf("exec_R: %d\n", exec_R);
    return 0;
}
