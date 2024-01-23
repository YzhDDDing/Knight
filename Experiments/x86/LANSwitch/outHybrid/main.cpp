#include "define.h"
#include <stdio.h>
#include <vector>
#include <set>
#include <string>
#include <string.h>
#include <time.h>
#include "Utility.h"
#include "BitmapCov.h"
#include "TCGHybridBasic.h"
#include "TCGHybridBasicBranchRegister.h"
#include "TCGHybridBasicGlobalVariableRegister.h"
#include "TCGHybridBasicInputRegister.h"
/* Main Function of model */
int main(int argc, char *argv[]) {
    string exePath = getExeDirPath();
    clock_t testStartTime = clock();
    // TCG Hybrid init code
    BitmapCov::munitBitmapLength = 5;
    BitmapCov::branchBitmapLength = 131;
    BitmapCov::condBitmapLength = 140;
    BitmapCov::decBitmapLength = 124;
    BitmapCov::mcdcBitmapLength = 63;
    BitmapCov::mcdcMeta = new unsigned char[BitmapCov::mcdcBitmapLength] { 4, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, };
    BitmapCov::init();
    TCGHybrid::initTCGHybrid(argc, argv);
    TCGHybridBasicBranchRegister::loadTCGHybridBranchData();
    // init code
    int32_T init_LANSwitch_U_PortId;
    int32_T init_LANSwitch_U_CMD;
    int32_T init_LANSwitch_U_Arg1;
    int32_T init_LANSwitch_U_Arg2;
    int32_T init_LANSwitch_U_Arg3;
    int32_T init_LANSwitch_Y_Result;
    int32_T init_LANSwitch_Y_MSG;
    LANSwitch_init(&LANSwitch_instance, &init_LANSwitch_U_PortId, &init_LANSwitch_U_CMD, &init_LANSwitch_U_Arg1, &init_LANSwitch_U_Arg2, &init_LANSwitch_U_Arg3, &init_LANSwitch_Y_Result, &init_LANSwitch_Y_MSG);
    // TCG Hybrid Regist Global Variables code
    TCGHybridBasicGlobalVariableRegister::registAllGlobalVariables();
    // TCG Hybrid Regist Inputs code
    TCGHybridBasicInputRegister::registAllInputs();
    /* Main Loop of model */
    BitmapCov::step();
    clock_t testEndTime = clock();
    TCGHybrid::callFuzzer();
    cout << "Sleep 3s" << endl;
    _sleep(3000);
    int i;
    for(i = 0; testEndTime - testStartTime < TCGHybrid::paraMaxRunTime; i++)
    {
        if(TCGHybrid::finish || isFileExist("finish.txt"))
        {
            break;
        }
        vector<TCGHybrid::TestCaseBinary> testCasesBinary;
        bool res = TCGHybrid::minimizeTestCasesBinary(exePath + "/Fuzz/In", exePath + "/TestCaseOutputAll", testCasesBinary);
        if(res)
        {
            TCGHybrid::callSTCGForSolve();
        }
        else
        {
            cout << "testCasesBinary is empty." << endl;
        }
        cout << "Sleep 3s" << endl;
        _sleep(3000);
        testEndTime = clock();
    }
    cout << "Achieved: " << BitmapCov::branchCov << "/" << TCGHybridBasicBranchRegister::TCGHybrid_Branch.size();
    testEndTime = clock();
    long long testCostTime = (testEndTime - testStartTime);
    cout << " run " << i << " times, cost : " << testCostTime << " ms\n";
    TCGHybrid::terminateTCGHybrid();
    return 0;
}
bool tryStateBranch(char* data, int length)
{
    // exec code
    int inputsDataLengthTotal = 20;
    int sizeBuf = length;
    if (sizeBuf % inputsDataLengthTotal != 0) {
        sizeBuf += (inputsDataLengthTotal - (sizeBuf % inputsDataLengthTotal));
    }
    const uint8_t* dataBuf = new uint8_t[sizeBuf];
    memcpy((void*)dataBuf, data, length);
    /* Main Loop of model */
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
    return true;
}