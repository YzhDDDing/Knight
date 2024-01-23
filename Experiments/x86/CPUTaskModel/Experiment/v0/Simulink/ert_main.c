#include "CPUTask.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void *readBinaryFile(const char *filename, size_t *length)
{
    FILE *file;
    void *buffer;

    // 打开文件
    file = fopen(filename, "rb");
    if (file == NULL)
    {
        perror("Error opening file");
        return NULL;
    }

    // 获取文件大小
    fseek(file, 0, SEEK_END);
    *length = ftell(file);
    fseek(file, 0, SEEK_SET);

    // 分配内存
    buffer = malloc(*length);
    if (buffer == NULL)
    {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    // 读取文件内容到内存
    if (fread(buffer, 1, *length, file) != *length)
    {
        perror("Error reading file");
        free(buffer);
        fclose(file);
        return NULL;
    }

    // 关闭文件并返回缓冲区指针
    fclose(file);
    return buffer;
}

static RT_MODEL_CPUTask_T CPUTask_M_;
static RT_MODEL_CPUTask_T *const CPUTask_MPtr = &CPUTask_M_;
static DW_CPUTask_T CPUTask_DW;
static ExtU_CPUTask_T CPUTask_U;
static ExtY_CPUTask_T CPUTask_Y;
void rt_OneStep(RT_MODEL_CPUTask_T *const CPUTask_M);
void rt_OneStep(RT_MODEL_CPUTask_T *const CPUTask_M)
{
    static boolean_T OverrunFlag = false;
    if (OverrunFlag)
    {
        return;
    }

    OverrunFlag = true;
    CPUTask_step(CPUTask_M, &CPUTask_U, &CPUTask_Y);
    OverrunFlag = false;
}

int_T main(int_T argc, const char *argv[])
{
    RT_MODEL_CPUTask_T *const CPUTask_M = CPUTask_MPtr;
    (void)(argc);
    (void)(argv);
    CPUTask_M->dwork = &CPUTask_DW;
    CPUTask_initialize(CPUTask_M, &CPUTask_U, &CPUTask_Y);
    size_t length;
    char *dataBuf = readBinaryFile("../../TestCases/merged.bin", &length);
    int inputsDataLengthTotal = 12;
    clock_t testStartTime = clock();
    for (int j = 0; j < 10000; j++)
    {
        for (int i = 0; i < 16777216; i++)
        {
            // printf("hello");
            if ((i + 1) * inputsDataLengthTotal > length)
            {
                break;
            }
            memcpy(&CPUTask_U.op, dataBuf + i * inputsDataLengthTotal + 0, 4);
            memcpy(&CPUTask_U.taskId, dataBuf + i * inputsDataLengthTotal + 4, 4);
            memcpy(&CPUTask_U.para, dataBuf + i * inputsDataLengthTotal + 8, 4);
            CPUTask_step(CPUTask_M, &CPUTask_U, &CPUTask_Y);
        }
    }
    free(dataBuf);
    clock_t testEndTime = clock();
    long long testCostTime = (testEndTime - testStartTime);
    printf("run %d times, cost : %lld\n", 1000, testCostTime);

    CPUTask_terminate(CPUTask_M);
    return 0;
}
