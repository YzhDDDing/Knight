#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include "define.h"
#include "LibFuzzerUtility.h"
#include "TestCaseConverter.h"
#include "Utility.h"
using namespace std;
unsigned char BranchCoverageLibFuzzer[163];
long long BranchCoverageStartTime = 0;
TestCaseConverter::TestCase TestOneInput(const uint8_t *data, size_t size) {
    TestCaseConverter::TestCase tempTestCase;
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
        TestCaseConverter::InputVariableOneStep* inputVariableOneStep = new TestCaseConverter::InputVariableOneStep();
        int32_T exec_LANSwitch_U_PortId = {};
        int32_T exec_LANSwitch_U_CMD = {};
        int32_T exec_LANSwitch_U_Arg1 = {};
        int32_T exec_LANSwitch_U_Arg2 = {};
        int32_T exec_LANSwitch_U_Arg3 = {};
        memcpy(&exec_LANSwitch_U_PortId, dataBuf + i * inputsDataLengthTotal + 0, 4);
        TestCaseConverter::InputVariableRecord record_LANSwitch_U_PortId((char*)&exec_LANSwitch_U_PortId, 4, "i32", "LANSwitch_U_PortId");
        inputVariableOneStep->allInputVariable.push_back(record_LANSwitch_U_PortId);
        memcpy(&exec_LANSwitch_U_CMD, dataBuf + i * inputsDataLengthTotal + 4, 4);
        TestCaseConverter::InputVariableRecord record_LANSwitch_U_CMD((char*)&exec_LANSwitch_U_CMD, 4, "i32", "LANSwitch_U_CMD");
        inputVariableOneStep->allInputVariable.push_back(record_LANSwitch_U_CMD);
        memcpy(&exec_LANSwitch_U_Arg1, dataBuf + i * inputsDataLengthTotal + 8, 4);
        TestCaseConverter::InputVariableRecord record_LANSwitch_U_Arg1((char*)&exec_LANSwitch_U_Arg1, 4, "i32", "LANSwitch_U_Arg1");
        inputVariableOneStep->allInputVariable.push_back(record_LANSwitch_U_Arg1);
        memcpy(&exec_LANSwitch_U_Arg2, dataBuf + i * inputsDataLengthTotal + 12, 4);
        TestCaseConverter::InputVariableRecord record_LANSwitch_U_Arg2((char*)&exec_LANSwitch_U_Arg2, 4, "i32", "LANSwitch_U_Arg2");
        inputVariableOneStep->allInputVariable.push_back(record_LANSwitch_U_Arg2);
        memcpy(&exec_LANSwitch_U_Arg3, dataBuf + i * inputsDataLengthTotal + 16, 4);
        TestCaseConverter::InputVariableRecord record_LANSwitch_U_Arg3((char*)&exec_LANSwitch_U_Arg3, 4, "i32", "LANSwitch_U_Arg3");
        inputVariableOneStep->allInputVariable.push_back(record_LANSwitch_U_Arg3);
        tempTestCase.timeList.push_back(i);
        tempTestCase.inputList.push_back(inputVariableOneStep);
        tempTestCase.length = i + 1;
    }
    delete[] dataBuf;
    return tempTestCase;
}
