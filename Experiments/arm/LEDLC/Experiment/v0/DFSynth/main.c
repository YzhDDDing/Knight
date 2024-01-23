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
    size_t len;
    char *dataBuf = readBinaryFile("../../TestCases/merged.bin", &len);
    int inputsDatalenTotal = 4;
    system_root_Init(&system_root_instance);
    clock_t testStartTime = clock();
    float exec_t;
    int exec_Output;
    for (int j = 0; j < 100; j++)
    {
        for (int i = 0; i < 16777216; i++)
        {
            if ((i + 1) * inputsDatalenTotal > len)
            {
                break;
            }
            memcpy(&exec_t, dataBuf + i * inputsDatalenTotal + 0, 4);
            system_root_Update(&system_root_instance, exec_t, &exec_Output);
        }
    }
    free(dataBuf);
    clock_t testEndTime = clock();
    long long testCostTime = (testEndTime - testStartTime);
    printf("run %d times, cost : %lld\n", 100, testCostTime);
    // printf("exec_SenserId: %d\n", exec_SenserId);
    // printf("exec_Opcode: %d\n", exec_Opcode);
    // printf("exec_TValue: %d\n", exec_TValue);
    // printf("exec_Res: %d\n", exec_Res);
    // printf("exec_R: %d\n", exec_R);
    return 0;
}