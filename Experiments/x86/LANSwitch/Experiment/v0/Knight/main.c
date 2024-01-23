#include "define.h"
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
int inputsDataLengthTotal = 20;
int main(int argc, char *argv[])
{
    size_t length;
    char *dataBuf = readBinaryFile("../../TestCases/merged.bin", &length);
    system_root_Init(&system_root_instance);
    clock_t testStartTime = clock();
    for (int j = 0; j < 100; j++)
    {
        for (int i = 0; i < 16777216; i++)
        {
            // printf("hello");
            if ((i + 1) * inputsDataLengthTotal > length)
            {
                break;
            }
            int exec_PortId;
            int exec_CMD;
            int exec_Arg1;
            int exec_Arg2;
            int exec_Arg3;
            int exec_Result;
            int exec_MSG;
            memcpy(&exec_PortId, dataBuf + i * inputsDataLengthTotal + 0, 4);
            memcpy(&exec_CMD, dataBuf + i * inputsDataLengthTotal + 4, 4);
            memcpy(&exec_Arg1, dataBuf + i * inputsDataLengthTotal + 8, 4);
            memcpy(&exec_Arg2, dataBuf + i * inputsDataLengthTotal + 12, 4);
            memcpy(&exec_Arg3, dataBuf + i * inputsDataLengthTotal + 16, 4);
            system_root_Update(&system_root_instance, exec_PortId, exec_CMD, exec_Arg1, exec_Arg2, exec_Arg3,
                               &exec_Result, &exec_MSG);
        }
    }
    free(dataBuf);
    clock_t testEndTime = clock();
    long long testCostTime = (testEndTime - testStartTime);
    printf("run %d times, cost : %lld\n", 100, testCostTime);
    return 0;
}