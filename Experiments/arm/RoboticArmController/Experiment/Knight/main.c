#include "define.h"
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

int main(int argc, char *argv[])
{
    int testCount = (argc > 1 ? atoi(argv[1]) : 1);
    size_t len;
    char *dataBuf = readBinaryFile("../../TestCases/merged.bin", &len);
    int inputsDatalenTotal = 20;
    system_root_Init(&system_root_instance);
    clock_t testStartTime = clock();
    int exec_ArmId;
    int exec_Op;
    int exec_P1;
    int exec_P2;
    int exec_P3;
    int exec_Res;
    int exec_B;
    for (int j = 0; j < testCount; j++)
    {
        for (int i = 0; i < 16777216; i++)
        {
            if ((i + 1) * inputsDatalenTotal > len)
            {
                break;
            }
            memcpy(&exec_ArmId, dataBuf + i * inputsDatalenTotal + 0, 4);
            memcpy(&exec_Op, dataBuf + i * inputsDatalenTotal + 4, 4);
            memcpy(&exec_P1, dataBuf + i * inputsDatalenTotal + 8, 4);
            memcpy(&exec_P2, dataBuf + i * inputsDatalenTotal + 12, 4);
            memcpy(&exec_P3, dataBuf + i * inputsDatalenTotal + 16, 4);
            system_root_Update(&system_root_instance, exec_ArmId, exec_Op, exec_P1, exec_P2, exec_P3, &exec_Res,
                               &exec_B);
        }
    }
    free(dataBuf);
    clock_t testEndTime = clock();
    long long testCostTime = (testEndTime - testStartTime);
    printf("run %d times, cost : %lld\n", testCount, testCostTime);
    return 0;
}