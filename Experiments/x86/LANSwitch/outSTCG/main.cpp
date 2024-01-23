#include "define.h"
#include <stdio.h>
#include <vector>
#include <set>
#include <string>
#include <string.h>
#include <time.h>
#include "Utility.h"
#include "BitmapCov.h"
#include "TCGStateSearchBasic.h"
#include "TCGStateSearchBasicBranchRegister.h"
#include "TCGStateSearchBasicBranchRelation.h"
#include "TCGStateSearchBasicGlobalVariableRegister.h"
#include "TCGStateSearchBasicInputRegister.h"
/* Main Function of model */
int main(int argc, char *argv[]) {
    StateSearch::unwindCount = 3;
    string exePath = getExeDirPath();
    clock_t testStartTime = clock();
    // State Search init code
    BitmapCov::munitBitmapLength = 5;
    BitmapCov::branchBitmapLength = 131;
    BitmapCov::condBitmapLength = 140;
    BitmapCov::decBitmapLength = 124;
    BitmapCov::mcdcBitmapLength = 63;
    BitmapCov::mcdcMeta = new unsigned char[BitmapCov::mcdcBitmapLength] { 4, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, };
    BitmapCov::init();
    StateSearch::initStateSearch(argc, argv);
    StateSearchBasicBranchRegister::loadStateSearchBranchData();
    StateSearch::registStateBranch(StateSearchBasicBranchRegister::StateSearch_Branch, StateSearchBasicBranchRegister::StateSearch_Branch_Depth);
    vector<pair<int, string>> StateSearch_BranchReadGlobalVar;
    vector<pair<int, string>> StateSearch_BranchWriteGlobalVar;
    StateSearchBasicBranchRelation::loadStateSearchBranchRelation(StateSearch_BranchReadGlobalVar, StateSearch_BranchWriteGlobalVar);
    StateSearch::registStateBranchRelation(StateSearch_BranchReadGlobalVar, StateSearch_BranchWriteGlobalVar);
    // init code
    int32_T init_LANSwitch_U_PortId;
    int32_T init_LANSwitch_U_CMD;
    int32_T init_LANSwitch_U_Arg1;
    int32_T init_LANSwitch_U_Arg2;
    int32_T init_LANSwitch_U_Arg3;
    int32_T init_LANSwitch_Y_Result;
    int32_T init_LANSwitch_Y_MSG;
    LANSwitch_init(&LANSwitch_instance, &init_LANSwitch_U_PortId, &init_LANSwitch_U_CMD, &init_LANSwitch_U_Arg1, &init_LANSwitch_U_Arg2, &init_LANSwitch_U_Arg3, &init_LANSwitch_Y_Result, &init_LANSwitch_Y_MSG);
    // State Search Regist Global Variables code
    StateSearchBasicGlobalVariableRegister::registAllGlobalVariables();
    // State Search Regist Inputs code
    StateSearchBasicInputRegister::registAllInputs();
    /* Main Loop of model */
    BitmapCov::step();
    int achived = 0;
    StateSearch::initStateSearch2();
    int i;
    int printId = 0;
    clock_t testEndTime = clock();
    for(i = 0; i < StateSearch::paraMaxRunIterator && testEndTime - testStartTime < StateSearch::paraMaxRunTime; i++)
    {
        if(StateSearch::finish || isFileExist("finish.txt"))
        {
            break;
        }
        //string printIdStr = to_string(printId++);
        //printIdStr = stringRepeat("0",4-printIdStr.length()) + printIdStr;
        //string tempPlainPath = exePath + "/Temp/StateTraceTreeViz_svg" + printIdStr + ".svg";
        //StateSearch::printStateTraceTree(tempPlainPath);
        achived = StateSearch::stateSearch(i);
        if(BitmapCov::branchCov == StateSearchBasicBranchRegister::StateSearch_Branch.size() || achived == -1)
        {
            break;
        }
    }
    cout << "Achieved: " << BitmapCov::branchCov << "/" << StateSearchBasicBranchRegister::StateSearch_Branch.size();
    testEndTime = clock();
    long long testCostTime = (testEndTime - testStartTime);
    cout << " run " << i << " times, cost : " << testCostTime << " ms\n";
    StateSearch::terminateStateSearch();
    return 0;
}
bool tryStateBranch(char* data, int length)
{
    // exec code
    bool enoughData = false;
    if(data && length >= StateSearch::inputsDataLengthTotal) {
        enoughData = true;
    }
    int32_T exec_LANSwitch_U_PortId = {};
    int32_T exec_LANSwitch_U_CMD = {};
    int32_T exec_LANSwitch_U_Arg1 = {};
    int32_T exec_LANSwitch_U_Arg2 = {};
    int32_T exec_LANSwitch_U_Arg3 = {};
    int32_T exec_LANSwitch_Y_Result;
    int32_T exec_LANSwitch_Y_MSG;
    if(enoughData){
        memcpy(&exec_LANSwitch_U_PortId, data + 0, 4);
        memcpy(&exec_LANSwitch_U_CMD, data + 4, 4);
        memcpy(&exec_LANSwitch_U_Arg1, data + 8, 4);
        memcpy(&exec_LANSwitch_U_Arg2, data + 12, 4);
        memcpy(&exec_LANSwitch_U_Arg3, data + 16, 4);
    }
    LANSwitch_step(&LANSwitch_instance, exec_LANSwitch_U_PortId, exec_LANSwitch_U_CMD, exec_LANSwitch_U_Arg1, exec_LANSwitch_U_Arg2, exec_LANSwitch_U_Arg3, &exec_LANSwitch_Y_Result, &exec_LANSwitch_Y_MSG);
    return true;
}