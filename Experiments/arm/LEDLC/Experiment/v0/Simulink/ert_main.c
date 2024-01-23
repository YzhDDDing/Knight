#include "FMTM.h"
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
static RT_MODEL_FMTM_T FMTM_M_;
static RT_MODEL_FMTM_T *const FMTM_MPtr = &FMTM_M_;
static B_FMTM_T FMTM_B;
static DW_FMTM_T FMTM_DW;
static int32_T FMTM_U_SenserId;
static int32_T FMTM_U_Opcode;
static int32_T FMTM_U_TValue;
static int32_T FMTM_Y_Res;
static int32_T FMTM_Y_R;
void rt_OneStep(RT_MODEL_FMTM_T *const FMTM_M);
void rt_OneStep(RT_MODEL_FMTM_T *const FMTM_M)
{
    static boolean_T OverrunFlag = false;
    if (OverrunFlag)
    {
        rtmSetErrorStatus(FMTM_M, "Overrun");
        return;
    }

    OverrunFlag = true;
    FMTM_step(FMTM_M, FMTM_U_SenserId, FMTM_U_Opcode, FMTM_U_TValue, &FMTM_Y_Res, &FMTM_Y_R);
    OverrunFlag = false;
}

int_T main(int_T argc, const char *argv[])
{
    RT_MODEL_FMTM_T *const FMTM_M = FMTM_MPtr;
    (void)(argc);
    (void)(argv);
    FMTM_M->blockIO = &FMTM_B;
    FMTM_M->dwork = &FMTM_DW;
    FMTM_initialize(FMTM_M, &FMTM_U_SenserId, &FMTM_U_Opcode, &FMTM_U_TValue, &FMTM_Y_Res, &FMTM_Y_R);
    size_t length;
    char *dataBuf = readBinaryFile("../../TestCases/merged.bin", &length);
    int inputsDataLengthTotal = 12;
    clock_t testStartTime = clock();
    for (int j = 0; j < 1000; j++)
    {
        for (int i = 0; i < 16777216; i++)
        {
            if ((i + 1) * inputsDataLengthTotal > length)
            {
                break;
            }
            memcpy(&FMTM_U_SenserId, dataBuf + i * inputsDataLengthTotal + 0, 4);
            memcpy(&FMTM_U_Opcode, dataBuf + i * inputsDataLengthTotal + 4, 4);
            memcpy(&FMTM_U_TValue, dataBuf + i * inputsDataLengthTotal + 8, 4);
            FMTM_step(FMTM_M, FMTM_U_SenserId, FMTM_U_Opcode, FMTM_U_TValue, &FMTM_Y_Res, &FMTM_Y_R);
        }
    }
    free(dataBuf);
    clock_t testEndTime = clock();
    long long testCostTime = (testEndTime - testStartTime);
    printf("run %d times, cost : %lld\n", 1000, testCostTime);
    printf("FMTM_U_SenserId: %d\n", FMTM_U_SenserId);
    printf("FMTM_U_Opcode: %d\n", FMTM_U_Opcode);
    printf("FMTM_U_TValue: %d\n", FMTM_U_TValue);
    printf("FMTM_Y_Res: %d\n", FMTM_Y_Res);
    printf("FMTM_Y_R: %d\n", FMTM_Y_R);
    return 0;
}
