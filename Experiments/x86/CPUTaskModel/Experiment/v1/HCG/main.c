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

int main(int argc, char *argv[])
{
    int testCount = (argc > 1 ? atoi(argv[1]) : 1);
    size_t length;
    char *dataBuf = readBinaryFile("../../../TestCases/merged.bin", &length);
    int inputsDataLengthTotal = 12;
    system_root_Init(&system_root_instance);
    clock_t testStartTime = clock();
    for (int j = 0; j < testCount; j++)
    {
        for (int i = 0; i < 16777216; i++)
        {
            // printf("hello");
            if ((i + 1) * inputsDataLengthTotal > length)
            {
                break;
            }
            int exec_op;
            int exec_taskId;
            int exec_para;
            int exec_res;
            int exec_out;
            memcpy(&exec_op, dataBuf + i * inputsDataLengthTotal + 0, 4);
            memcpy(&exec_taskId, dataBuf + i * inputsDataLengthTotal + 4, 4);
            memcpy(&exec_para, dataBuf + i * inputsDataLengthTotal + 8, 4);
            system_root_Update(&system_root_instance, exec_op, exec_taskId, exec_para, &exec_res, &exec_out);
        }
    }
    free(dataBuf);
    clock_t testEndTime = clock();
    long long testCostTime = (testEndTime - testStartTime);
    printf("run %d times, cost : %lld\n", testCount, testCostTime);
    return 0;
}