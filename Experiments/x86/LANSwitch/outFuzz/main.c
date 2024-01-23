#include "define.h"
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
unsigned char BranchCoverageLibFuzzer[163];
long long BranchCoverageStartTime = 0;
extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    BranchCoverageRegister(data, size);
    int32_T init_LANSwitch_U_PortId;
    int32_T init_LANSwitch_U_CMD;
    int32_T init_LANSwitch_U_Arg1;
    int32_T init_LANSwitch_U_Arg2;
    int32_T init_LANSwitch_U_Arg3;
    int32_T init_LANSwitch_Y_Result;
    int32_T init_LANSwitch_Y_MSG;
    LANSwitch_init(&LANSwitch_instance, &init_LANSwitch_U_PortId, &init_LANSwitch_U_CMD, &init_LANSwitch_U_Arg1, &init_LANSwitch_U_Arg2, &init_LANSwitch_U_Arg3, &init_LANSwitch_Y_Result, &init_LANSwitch_Y_MSG);
    int inputsDataLengthTotal = 20;
    int sizeBuf = size;
    if (sizeBuf % inputsDataLengthTotal != 0) {
        sizeBuf += (inputsDataLengthTotal - (sizeBuf % inputsDataLengthTotal));
    }
    const uint8_t* dataBuf = new uint8_t[sizeBuf];
    memset((void*)dataBuf, 0, sizeBuf);
    memcpy((void*)dataBuf, data, size);
    for (int i = 0; i < 16777216; i++) {
        if((i + 1) * inputsDataLengthTotal > sizeBuf) {
            break;
        }
        int32_T exec_LANSwitch_U_PortId = {};
        int32_T exec_LANSwitch_U_CMD = {};
        int32_T exec_LANSwitch_U_Arg1 = {};
        int32_T exec_LANSwitch_U_Arg2 = {};
        int32_T exec_LANSwitch_U_Arg3 = {};
        int32_T exec_LANSwitch_Y_Result;
        int32_T exec_LANSwitch_Y_MSG;
        memcpy(&exec_LANSwitch_U_PortId, dataBuf + i * inputsDataLengthTotal + 0, 4);
        memcpy(&exec_LANSwitch_U_CMD, dataBuf + i * inputsDataLengthTotal + 4, 4);
        memcpy(&exec_LANSwitch_U_Arg1, dataBuf + i * inputsDataLengthTotal + 8, 4);
        memcpy(&exec_LANSwitch_U_Arg2, dataBuf + i * inputsDataLengthTotal + 12, 4);
        memcpy(&exec_LANSwitch_U_Arg3, dataBuf + i * inputsDataLengthTotal + 16, 4);
        LANSwitch_step(&LANSwitch_instance, exec_LANSwitch_U_PortId, exec_LANSwitch_U_CMD, exec_LANSwitch_U_Arg1, exec_LANSwitch_U_Arg2, exec_LANSwitch_U_Arg3, &exec_LANSwitch_Y_Result, &exec_LANSwitch_Y_MSG);
    }
    delete[] dataBuf;
    BranchCoverageRecordTestCase();
    return 0;
}