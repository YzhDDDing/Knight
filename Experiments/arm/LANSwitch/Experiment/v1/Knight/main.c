#include "define.h"
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
int main(int argc, char *argv[])
{
    int testCount = (argc > 1 ? atoi(argv[1]) : 1);
    size_t length;
    char *dataBuf = readBinaryFile("../../../TestCases/merged.bin", &length);
    system_root_Init(&system_root_instance);
    clock_t testStartTime = clock();
    int exec_PortId;
    int exec_CMD;
    int exec_Arg1;
    int exec_Arg2;
    int exec_Arg3;
    int exec_Result;
    int exec_MSG;
    for (int j = 0; j < testCount; j++)
    {
        for (int i = 0; i < 16777216; i++)
        {
            if ((i + 1) * inputsDataLengthTotal > length)
            {
                break;
            }
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
    printf("run %d times, cost : %lld\n", testCount, testCostTime);
    // printf("exec_PortId: %d.\n", exec_PortId);
    // printf("exec_CMD: %d.\n", exec_CMD);
    // printf("exec_Arg1: %d.\n", exec_Arg1);
    // printf("exec_Arg2: %d.\n", exec_Arg2);
    // printf("exec_Arg3: %d.\n", exec_Arg3);
    // printf("exec_Result: %d.\n", exec_Result);
    // printf("exec_MSG: %d.\n", exec_MSG);
    return 0;
}