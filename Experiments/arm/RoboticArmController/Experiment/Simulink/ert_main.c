#include "RoboticArmController.h"
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
static RT_MODEL_RoboticArmController_T RoboticArmController_M_;
static RT_MODEL_RoboticArmController_T *const RoboticArmController_MPtr = &RoboticArmController_M_;
static B_RoboticArmController_T RoboticArmController_B;
static DW_RoboticArmController_T RoboticArmController_DW;
static int32_T RoboticArmController_U_ArmId;
static int32_T RoboticArmController_U_Op;
static int32_T RoboticArmController_U_P1;
static int32_T RoboticArmController_U_P2;
static int32_T RoboticArmController_U_P3;
static int32_T RoboticArmController_Y_Res;
static int32_T RoboticArmController_Y_B;
void rt_OneStep(RT_MODEL_RoboticArmController_T *const RoboticArmController_M);
void rt_OneStep(RT_MODEL_RoboticArmController_T *const RoboticArmController_M)
{
    static boolean_T OverrunFlag = false;
    if (OverrunFlag)
    {
        rtmSetErrorStatus(RoboticArmController_M, "Overrun");
        return;
    }

    OverrunFlag = true;
    RoboticArmController_step(RoboticArmController_M, RoboticArmController_U_ArmId, RoboticArmController_U_Op,
                              RoboticArmController_U_P1, RoboticArmController_U_P2, RoboticArmController_U_P3,
                              &RoboticArmController_Y_Res, &RoboticArmController_Y_B);
    OverrunFlag = false;
}

int_T main(int_T argc, const char *argv[])
{
    int testCount = (argc > 1 ? atoi(argv[1]) : 1);
    size_t len;
    char *dataBuf = readBinaryFile("../../TestCases/merged.bin", &len);
    int inputsDatalenTotal = 20;
    RT_MODEL_RoboticArmController_T *const RoboticArmController_M = RoboticArmController_MPtr;
    (void)(argc);
    (void)(argv);
    RoboticArmController_M->blockIO = &RoboticArmController_B;
    RoboticArmController_M->dwork = &RoboticArmController_DW;
    RoboticArmController_initialize(RoboticArmController_M, &RoboticArmController_U_ArmId, &RoboticArmController_U_Op,
                                    &RoboticArmController_U_P1, &RoboticArmController_U_P2, &RoboticArmController_U_P3,
                                    &RoboticArmController_Y_Res, &RoboticArmController_Y_B);
    clock_t testStartTime = clock();
    for (int j = 0; j < testCount; j++)
    {
        for (int i = 0; i < 16777216; i++)
        {
            if ((i + 1) * inputsDatalenTotal > len)
            {
                break;
            }
            memcpy(&RoboticArmController_U_ArmId, dataBuf + i * inputsDatalenTotal + 0, 4);
            memcpy(&RoboticArmController_U_Op, dataBuf + i * inputsDatalenTotal + 4, 4);
            memcpy(&RoboticArmController_U_P1, dataBuf + i * inputsDatalenTotal + 8, 4);
            memcpy(&RoboticArmController_U_P2, dataBuf + i * inputsDatalenTotal + 12, 4);
            memcpy(&RoboticArmController_U_P3, dataBuf + i * inputsDatalenTotal + 16, 4);
            RoboticArmController_step(RoboticArmController_M, RoboticArmController_U_ArmId, RoboticArmController_U_Op,
                                      RoboticArmController_U_P1, RoboticArmController_U_P2, RoboticArmController_U_P3,
                                      &RoboticArmController_Y_Res, &RoboticArmController_Y_B);
        }
    }
    free(dataBuf);
    clock_t testEndTime = clock();
    long long testCostTime = (testEndTime - testStartTime);
    printf("run %d times, cost : %lld\n", testCount, testCostTime);
    return 0;
}
