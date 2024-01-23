#include "StateSearchBasic.h"
#include "tinyxml2.h"
#include "Utility.h"
#include "BitmapCov.h"

#include <time.h>
#include <algorithm>
#include <queue>
#include <random>
#include <unordered_map>

#include "ArgumentParser.h"
#include "BasicExcel.hpp"
using namespace YExcel;

int StateSearch::solveTimes = 0;
StateSearch::StateTraceTree StateSearch::stateTraceTree;
int StateSearch::achievedCount = 0;
int StateSearch::searchedCount = 0;
map<int, string> StateSearch::stateBranchList;
vector<int> StateSearch::branchSolveOrder;
vector<StateSearch::GlobalVariableData> StateSearch::globalVariableList;
vector<StateSearch::InputVariableData> StateSearch::inputList;
int StateSearch::inputsDataLengthTotal = 0;
int StateSearch::unwindCount = 0;
string StateSearch::cbmcParameter;
long long StateSearch::startTime;

string StateSearch::paraBinaryTestCaseFilePath;
int StateSearch::paraMaxRunTime;
int StateSearch::paraMaxRunIterator;

string StateSearch::InputVariableRecord::toString()
{
    string retCode = "(" + this->pointer->type + ")";
    if(this->pointer->type == "u8")
    {
        unsigned char ret;
        ::memcpy(&ret, data, sizeof(unsigned char));
        retCode += to_string(ret);
    }
    if(this->pointer->type == "i8")
    {
        char ret;
        ::memcpy(&ret, data, sizeof(char));
        retCode += to_string(ret);
    }
    if(this->pointer->type == "i32")
    {
        int ret;
        ::memcpy(&ret, data, sizeof(int));
        retCode += to_string(ret);
    }
    if(this->pointer->type == "i64")
    {
        long long ret;
        ::memcpy(&ret, data, sizeof(long long));
        retCode += to_string(ret);
    }
    if(this->pointer->type == "u32")
    {
        unsigned int ret;
        ::memcpy(&ret, data, sizeof(unsigned int));
        retCode += to_string(ret);
    }
    if(this->pointer->type == "u64")
    {
        unsigned long long ret;
        ::memcpy(&ret, data, sizeof(unsigned long long));
        retCode += to_string(ret);
    }
    if(this->pointer->type == "f32")
    {
        float ret;
        ::memcpy(&ret, data, sizeof(float));
        retCode += to_string(ret);
    }
    if(this->pointer->type == "f64")
    {
        double ret;
        ::memcpy(&ret, data, sizeof(double));
        retCode += to_string(ret);
    }
    return retCode;
}

void StateSearch::initStateSearch(int argc, char *argv[])
{
    ArgumentParser argumentParser;
	paraBinaryTestCaseFilePath = "";
	paraMaxRunTime = 432000000; //最多运行5天时间
	paraMaxRunIterator = 999999999;
    
    argumentParser.setDefaultValue("-b", paraBinaryTestCaseFilePath);
	argumentParser.setDefaultValue("-t", to_string(paraMaxRunTime));
	argumentParser.setDefaultValue("-i", to_string(paraMaxRunIterator));

    argumentParser.parseArguments(argc, argv);

	paraBinaryTestCaseFilePath = argumentParser.getFlagValue("-b");
	paraMaxRunTime =			 stringToInt(argumentParser.getFlagValue("-t"));
	paraMaxRunIterator         = stringToInt(argumentParser.getFlagValue("-i"));
    
    
	cout << "-b: " << paraBinaryTestCaseFilePath << endl;
	cout << "-t: " << paraMaxRunTime << endl;
	cout << "-i: " << paraMaxRunIterator << endl;
    
    srand((unsigned)time(nullptr));
    startTime = clock();

    stateTraceTree.root = new StateTraceNode();
    stateTraceTree.root->inputVariablesOneStep = new InputVariableOneStep();
    stateTraceTree.root->globalVariablesOneStep = new GlobalVariableOneStep();
    stateTraceTree.root->exceptBranchId = -1;
    stateTraceTree.root->achieveExceptBranch = true;
    stateTraceTree.root->depth = 0;
    stateTraceTree.nodeCount = 1;
    stateTraceTree.currentNode = stateTraceTree.root;
    stateTraceTree.allNodeList.push_back(stateTraceTree.root);
    
    stateTraceTree.root->branchIdCovered = new unsigned char[BitmapCov::branchBitmapLength];
    stateTraceTree.root->branchIdCoveredTotal = new unsigned char[BitmapCov::branchBitmapLength];
    
    if(isFileExist("cbmcParameter.txt"))
    {
        cbmcParameter = readFile("cbmcParameter.txt");
    }

    string exePath = getExeDirPath();
    if(!isFolderExist(exePath + "/Temp")) {
        createFolder(exePath + "/Temp");
    }
    if(!isFolderExist(exePath + "/TestCaseOutput")) {
        createFolder(exePath + "/TestCaseOutput");
    }
    if(!isFolderExist(exePath + "/TestCaseOutput/Binary")) {
        createFolder(exePath + "/TestCaseOutput/Binary");
    }
}

void StateSearch::initStateSearch2()
{
    collectGlobalVariableOneStep(stateTraceTree.root);
    
    if(!paraBinaryTestCaseFilePath.empty() && isFolderExist(paraBinaryTestCaseFilePath)){
        StateSearch::runExistTestCaseBinary(paraBinaryTestCaseFilePath);
    }
}

void StateSearch::terminateStateSearch()
{
    string exePath = getExeDirPath();
    
    //vector<TestCase> testCases = collectTestCases();
    //
    //outputTestCasesCSV(testCases);
    //outputTestCasesXLS(testCases);
    //outputTestCasesBinary(testCases);

    if(stateTraceTree.nodeCount < 100)
    {
        string tempPlainPath = exePath + "/Temp/StateTraceTreeViz_svg_final.svg";
        StateSearch::printStateTraceTree(tempPlainPath);
    }
}

void StateSearch::runExistTestCaseBinary(string dirPath)
{
    
    vector<string> fileList;
    listFiles(dirPath, fileList);
    for(int i = 0; i < fileList.size(); i++)
    {
        stateTraceTree.currentNode = stateTraceTree.root;
        int size;
        char* data = readFileBinary(dirPath + "/" + fileList[i], size);
        int stepCount = 0;
        while((stepCount + 1) * inputsDataLengthTotal <= size)
        {
            BitmapCov::clearCurrentBitmap();
            addStateTraceNode(stateTraceTree.currentNode, -1);
            tryStateBranch(data + stepCount * inputsDataLengthTotal, inputsDataLengthTotal);
            bool newBranchCovered = BitmapCov::step();
            collectGlobalVariableOneStep(stateTraceTree.currentNode);
            // 记录Step到序列中
            memcpy(stateTraceTree.currentNode->branchIdCovered, BitmapCov::branchBitmap, BitmapCov::branchBitmapLength);
            memcpy(stateTraceTree.currentNode->branchIdCoveredTotal, BitmapCov::branchAllBitmap, BitmapCov::branchBitmapLength);
            stateTraceTree.currentNode->exceptBranchId = -1;
            stateTraceTree.currentNode->achieveExceptBranch = true;
            stateTraceTree.currentNode->achieveNewBranch = newBranchCovered;
            
            stepCount++;
        }
        delete[] data;
        resetGlobalVariables(stateTraceTree.root);
        //BitmapCov::step();
        achievedCount = 0;
        for(int j = 0; j < BitmapCov::branchBitmapLength; j++) {
            if(BitmapCov::branchAllBitmap[j] != 0)
                achievedCount++;
        }
        
        string logStr = "TestCase " + stringFillBlank(to_string(i), 4, true) + ": ";
        logStr += "Achieved: " + to_string(BitmapCov::branchCov) + "/" + to_string(BitmapCov::branchBitmapLength);
        logStr += " run " + to_string(stepCount) + " steps\n";
        logStr += "TotalCover:    ";
        for(int i = 0; i < BitmapCov::branchBitmapLength; i++)
        {
            logStr += to_string(BitmapCov::branchAllBitmap[i] - 0);
        }
        logStr += "\n";
        
        cout << logStr;
        appendFile("log.txt", logStr);
        //cout << "TestCase " << setw(4) << i << ": ";
        //cout << "Achieved: " << BitmapCov::branchCov << "/" << BitmapCov::branchBitmapLength;
        //cout << " run " << stepCount << " steps\n";
        
    }
}

void StateSearch::registGlobalVariables(string name, string type, vector<int>& arraySize, char* address, int length)
{
    GlobalVariableData globalVariableData;
    globalVariableData.address = address;
    globalVariableData.length = length;
    globalVariableData.type = type;
    globalVariableData.name = name;
    globalVariableData.arraySize = arraySize;

    globalVariableList.push_back(globalVariableData);


    GlobalVariableRecord globalVariableRecord;
    globalVariableRecord.data = new char[length];
    ::memcpy(globalVariableRecord.data, address, length);
    //globalVariableRecord.length = length;
    //globalVariableRecord.type = type;
    //globalVariableRecord.name = name;
    //globalVariableRecord.arraySize = arraySize;
    globalVariableRecord.pointer = &(globalVariableList[globalVariableList.size() - 1]);

    stateTraceTree.root->globalVariablesOneStep->allGlobalVariable.push_back(globalVariableRecord);
}

void StateSearch::registInputs(string name, string type, int length)
{
    InputVariableData inputRecord;
    inputRecord.name = name;
    inputRecord.type = type;
    inputRecord.length = length;
    inputsDataLengthTotal += length;
    inputList.push_back(inputRecord);
}

void StateSearch::registStateBranch(map<int, string>& branchList, map<int, int>& branchDepth)
{
    stateBranchList = branchList;
    vector<pair<int, int>> vtMap;
    for (auto it = branchDepth.begin(); it != branchDepth.end(); it++)
        vtMap.push_back(make_pair(it->first, it->second));

    sort(vtMap.begin(), vtMap.end(), 
        [](const pair<int, int> &x, const pair<int, int> &y) -> int {
        return x.second < y.second;
    });

    for (auto it = vtMap.begin(); it != vtMap.end(); it++)
    {
        branchSolveOrder.push_back(it->first);
    }

}

namespace 
{
    int lastTestTreeNodeId = 0;
}

void StateSearch::selectState()
{
    string printStr;
    printStr = "Select State ... ";
    bool existBranchCanSolved = false;

    vector<int> unreachedBranchId;
    for(int i = 0; i < BitmapCov::branchBitmapLength; i++) {
        int branchId = branchSolveOrder[i];
        if(BitmapCov::branchAllBitmap[branchId]) {
            continue;
        }
        unreachedBranchId.push_back(branchId);
    }
    //clock_t time = clock();
    //shuffle(unreachedBranchId.begin(), unreachedBranchId.end(), std::default_random_engine(time));
    printStr += "Remain: " + stringFillBlank(to_string(unreachedBranchId.size()),8) + " ";

    for(int i = 0; i < unreachedBranchId.size(); i++) {
        int branchId = unreachedBranchId[i];
        string printStr2;
        printStr2 = "Try: " + stringFillBlank(to_string(branchId + 1), 8) + " ";
        //是否所有节点都无法解出该分支
        bool canSolved = false;
        for(int j = lastTestTreeNodeId; j < stateTraceTree.allNodeList.size(); j++)
        {
            StateTraceNode* node = stateTraceTree.allNodeList[j];
            if(node->solvedBranchResultMap.find(branchId) == node->solvedBranchResultMap.end() &&
                node->achieveExceptBranch)
            {
                string printStr3;
                printStr3 = "Node: " + stringFillBlank(to_string(j), 8, true) + "/" + stringFillBlank(to_string(stateTraceTree.allNodeList.size()),8);

                string logStr;
                logStr = printStr + printStr2 + printStr3;
                cout << logStr;
                appendFile("log.txt", logStr + "\n");

                // 还没解过
                solveInputVariable(node, branchId);

                //for(int k = 0; k < printStr.length()+printStr2.length()+printStr3.length(); k++)
                //{
                //    cout << "\b";
                //}
                cout << "\r";
                if(node->solvedBranchResultMap[branchId])
                {
                    //能解出来，执行路径
                    if(stateTraceTree.currentNode != node)
                        resetGlobalVariables(node);
                    stateTraceTree.currentNode = node;
                    stateTraceTree.selectedBranchId = branchId;

                    canSolved = true;
                    break;
                }
                else
                {
                    // 不能解出来，则继续搜索下一个节点
                    continue;
                }
            }
        }

        if(canSolved)
        {
            existBranchCanSolved = true;
            break;
        }
    }

    if(!existBranchCanSolved)
    {
        //全部分支，全部节点都不可解
        stateTraceTree.currentNode = nullptr;
        lastTestTreeNodeId = stateTraceTree.nodeCount;
        //int rand_ = rand() % stateTraceTree.allNodeList.size();
        //stateTraceTree.currentNode = stateTraceTree.allNodeList[rand_];
    }
    
}

void StateSearch::randomRun(int nTimes)
{
    if(stateTraceTree.allInputVariableOneStepList.empty())
        return;
    int rand_ = rand() % stateTraceTree.allNodeList.size();
    stateTraceTree.currentNode = stateTraceTree.allNodeList[rand_];
    resetGlobalVariables(stateTraceTree.currentNode);
    vector<int> unreachedBranchId;
    for(int i = 0; i < BitmapCov::branchBitmapLength; i++) {
        int branchId = branchSolveOrder[i];
        if(BitmapCov::branchAllBitmap[branchId]) {
            continue;
        }
        unreachedBranchId.push_back(branchId);
    }
    for(int i = 0; i < nTimes; i++)
    {
        rand_ = rand() % stateTraceTree.allInputVariableOneStepList.size();
        InputVariableOneStep* tempInput = &stateTraceTree.allInputVariableOneStepList[rand_];
        rand_ = rand() % unreachedBranchId.size();
        int exceptStateBranchId = unreachedBranchId[rand_];
        tryStateBranchInner(stateTraceTree.currentNode, exceptStateBranchId, tempInput);
        stateTraceTree.currentNode = stateTraceTree.allNodeList[stateTraceTree.allNodeList.size() - 1];
    }
}


void StateSearch::solveInputVariable(StateTraceNode* stateTraceNode, int branchId)
{
    //stateTraceNode->solvedBranchResultMap[branchId] = false;

    solveTimes++;

    stateTraceNode->solveId.push_back(solveTimes);

    generateCodeWithNewGlobalVariable(stateTraceNode);

    callCBMC(branchId);

    parseCBMCResult(stateTraceNode, branchId);
    
}

namespace 
{
    string codeTemplate;
}

void StateSearch::generateCodeWithNewGlobalVariable(StateTraceNode* stateTraceNode)
{
    GlobalVariableOneStep* currentGlobalVariables = stateTraceNode->globalVariablesOneStep;
    if(codeTemplate.empty())
    {
        codeTemplate = readFile("CodeForSolver.c");
        if(codeTemplate.empty())
            codeTemplate = readFile("main.c");
        for(int i = 0; i < currentGlobalVariables->allGlobalVariable.size(); i++)
        {
            GlobalVariableRecord* globalVariableRecord = &(currentGlobalVariables->allGlobalVariable[i]);
            string targetStr = "// Need to be modified: Variable " + globalVariableRecord->pointer->name;
            size_t endPos = codeTemplate.find(targetStr) + targetStr.length() - 1;
            size_t startPos = codeTemplate.rfind("\n", endPos) + 1;
            codeTemplate = codeTemplate.replace(startPos, endPos - startPos + 1, "${" + globalVariableRecord->pointer->name + "}$");
        }
    }

    string code = codeTemplate;
    for(int i = 0; i < currentGlobalVariables->allGlobalVariable.size(); i++)
    {
        GlobalVariableRecord* globalVariableRecord = &(currentGlobalVariables->allGlobalVariable[i]);
        string varStr = getVariableStr(globalVariableRecord);
        code = stringReplaceAll(code, "${" + globalVariableRecord->pointer->name + "}$", varStr);
    }

    writeFile("Temp/CodeForSolverTemp" + to_string(solveTimes) + ".c", code);
}

string StateSearch::getVariableValueStr(GlobalVariableRecord* variableRecord, int offset)
{
    return getVariableValueStr(variableRecord->pointer->type, variableRecord->data, offset);
}

string StateSearch::getVariableValueStr(InputVariableRecord* variableRecord)
{
    return getVariableValueStr(variableRecord->pointer->type, variableRecord->data, 0);
}

string StateSearch::getVariableValueStr(string type, char* addr, int offset)
{
    string retCode;
    if(type == "u8")
    {
        unsigned char ret;
        ::memcpy(&ret, addr + offset * sizeof(unsigned char), sizeof(unsigned char));
        retCode += to_string(ret);
    }
    if(type == "i8")
    {
        char ret;
        ::memcpy(&ret, addr + offset * sizeof(char), sizeof(char));
        retCode += to_string(ret);
    }
    if(type == "i16")
    {
        short ret;
        ::memcpy(&ret, addr + offset * sizeof(short), sizeof(short));
        retCode += to_string(ret);
    }
    if(type == "i32")
    {
        int ret;
        ::memcpy(&ret, addr + offset * sizeof(int), sizeof(int));
        retCode += to_string(ret);
    }
    if(type == "i64")
    {
        long long ret;
        ::memcpy(&ret, addr + offset * sizeof(long long), sizeof(long long));
        retCode += to_string(ret);
    }
    if(type == "u16")
    {
        unsigned short ret;
        ::memcpy(&ret, addr + offset * sizeof(unsigned short), sizeof(unsigned short));
        retCode += to_string(ret);
    }
    if(type == "u32")
    {
        unsigned int ret;
        ::memcpy(&ret, addr + offset * sizeof(unsigned int), sizeof(unsigned int));
        retCode += to_string(ret);
    }
    if(type == "u64")
    {
        unsigned long long ret;
        ::memcpy(&ret, addr + offset * sizeof(unsigned long long), sizeof(unsigned long long));
        retCode += to_string(ret);
    }
    if(type == "f32")
    {
        float ret;
        ::memcpy(&ret, addr + offset * sizeof(float), sizeof(float));
        retCode += to_string(ret);
    }
    if(type == "f64")
    {
        double ret;
        ::memcpy(&ret, addr + offset * sizeof(double), sizeof(double));
        retCode += to_string(ret);
    }
    return retCode;
}

string StateSearch::getVariableStr(GlobalVariableRecord* variableRecord)
{
    string retCode;
    string indexStr;
    

    int count = 1;
    for(int i = 0; i < variableRecord->pointer->arraySize.size(); i++)
    {
        count *= variableRecord->pointer->arraySize[i];
    }

    if(variableRecord->pointer->arraySize.empty())
    {
        retCode += variableRecord->pointer->name + " = ";
        retCode += getVariableValueStr(variableRecord, 0);
        retCode += ";\n";
    }
    for(int i = 0; i < count && count > 1; i++)
    {
        retCode += "*(" + variableRecord->pointer->name + " + " + to_string(i) + ")" + " = ";
        retCode += getVariableValueStr(variableRecord, i);
        retCode += ";\n";
    }
    
    return retCode;
}


void StateSearch::callCBMC(int branchId)
{
    string callCBMC = "cbmc.exe";

    string cmd;
	string para = "--gcc";
    para += " --arch i386";
    para += " --cover cover";
    //para += " --z3";
    para += cbmcParameter;
    para += " --xml-ui";
    para += " --partial-loops";
    para += " --reachability-slice";
    para += " --slice-formula";
    para += " --property " + stateBranchList[branchId];
    para += " --unwind " + to_string(StateSearch::unwindCount);
    para += " Temp/CodeForSolverTemp" + to_string(solveTimes) + ".c";
    cmd = callCBMC + " " + para + " > Temp/out" + to_string(solveTimes) + ".txt";
    appendFile("Temp/cmd.txt", cmd + "\n");

    //string exePath = getExeDirPath();
    //callCBMC = "D:\\LAB\\MBD\\CodeGenerator\\exe\\CBMC\\cbmc.exe";
    //systemCallWithTimeOut(callCBMC, para, 30000, exePath + "/Temp/out" + to_string(solveTimes) + ".txt");

    system(cmd.c_str());
}

void StateSearch::parseCBMCResult(StateTraceNode* stateTraceNode, int branchId)
{
    StateTraceNode* currentNode = stateTraceNode;
    tinyxml2::XMLDocument doc;
    string resultFile = "Temp/out" + to_string(solveTimes) + ".txt";
	tinyxml2::XMLError ret = doc.LoadFile(resultFile.c_str());
    if (ret != 0) {
		fprintf(stderr, "Fail to load CBMC result file: %s\n", resultFile.c_str());
        return;
	}
    tinyxml2::XMLElement* root = doc.RootElement();

    const tinyxml2::XMLElement *c = root->FirstChildElement("test");
	while (c)
	{
        InputVariableOneStep inputs;
        const tinyxml2::XMLElement *c2 = c->FirstChildElement("inputs");
	    if(c2)
	    {
	        const tinyxml2::XMLElement *c3 = c2->FirstChildElement("input");
	        while (c3)
	        {
                InputVariableRecord input;
                string name = string(c3->Attribute("id"));
                for(int i = 0; i < StateSearch::inputList.size(); i++)
                {
                    if(StateSearch::inputList[i].name == name)
                        input.pointer = &StateSearch::inputList[i];
                }
                //input.name = string(c3->Attribute("id"));
                const tinyxml2::XMLElement *c4_1 = c3->FirstChildElement("integer");
                const tinyxml2::XMLElement *c4_2 = c3->FirstChildElement("float");
                if(c4_1) {
                    string type = string(c4_1->Attribute("c_type"));
                    if(type == "int")
                    {
                        int value = c4_1->IntText();
                        input.data = new char[sizeof(value)];
                        //input.length = sizeof(value);
                        //input.type = "i32";
                        ::memcpy(input.data, &value, sizeof(value));
                    }
                    else if(type == "long long")
                    {
                        long long value = c4_1->Int64Text();
                        input.data = new char[sizeof(value)];
                        //input.length = sizeof(value);
                        //input.type = "i64";
                        ::memcpy(input.data, &value, sizeof(value));
                    }
                    else if(type == "unsigned int")
                    {
                        unsigned int value = c4_1->IntText();
                        input.data = new char[sizeof(value)];
                        //input.length = sizeof(value);
                        //input.type = "u32";
                        ::memcpy(input.data, &value, sizeof(value));
                    }
                    else if(type == "unsigned char")
                    {
                        unsigned char value = c4_1->IntText();
                        input.data = new char[sizeof(value)];
                        //input.length = sizeof(value);
                        //input.type = "u8";
                        ::memcpy(input.data, &value, sizeof(value));
                    }
                    else if(type == "char")
                    {
                        char value = c4_1->IntText();
                        input.data = new char[sizeof(value)];
                        //input.length = sizeof(value);
                        //input.type = "i8";
                        ::memcpy(input.data, &value, sizeof(value));
                    }
                    else if(type == "short")
                    {
                        short value = c4_1->IntText();
                        input.data = new char[sizeof(value)];
                        //input.length = sizeof(value);
                        //input.type = "i16";
                        ::memcpy(input.data, &value, sizeof(value));
                    }
                    else if(type == "unsigned short")
                    {
                        unsigned short value = c4_1->IntText();
                        input.data = new char[sizeof(value)];
                        //input.length = sizeof(value);
                        //input.type = "u16";
                        ::memcpy(input.data, &value, sizeof(value));
                    }

                } else if(c4_2) {
                    string type = "float";
                    if(c4_2->FindAttribute("c_type"))
                    {
                        type = string(c4_2->Attribute("c_type"));
                    }
                    else
                    {
                        string width = string(c4_2->Attribute("width"));
                        type = width == "64" ? "double" : "float";
                    }
                    if(type == "float")
                    {
                        float value = c4_2->FloatText();
                        if(isnan(value))
                            value = 0;
                        input.data = new char[sizeof(value)];
                        //input.length = sizeof(value);
                        //input.type = "f32";
                        ::memcpy(input.data, &value, sizeof(value));
                    }
                    else if(type == "double")
                    {
                        double value = c4_2->DoubleText();
                        if(isnan(value))
                            value = 0;
                        input.data = new char[sizeof(value)];
                        //input.length = sizeof(value);
                        //input.type = "f64";
                        ::memcpy(input.data, &value, sizeof(value));
                    }
                }

                inputs.allInputVariable.push_back(input);

	            c3 = c3->NextSiblingElement("input");
	        }
	    }

        if(!inputs.allInputVariable.empty())
        {
            stateTraceTree.allInputVariableOneStepList.push_back(inputs);
        }
        c2 = c->FirstChildElement("goal");
	    while(c2)
	    {
	        string pathIdStr = string(c2->Attribute("id"));

            if(stateBranchList.at(branchId) == pathIdStr)
            {
                currentNode->solvedStateSelectInputList[branchId] = inputs;
            }

            c2 = c2->NextSiblingElement("goal");
	    }

		c = c->NextSiblingElement("test");
	}
    if(currentNode->solvedStateSelectInputList.find(branchId) != currentNode->solvedStateSelectInputList.end()) {
        if(currentNode->solvedBranchResultMap.find(branchId) == currentNode->solvedBranchResultMap.end())
        {
            currentNode->solvedBranchResultMap[branchId] = 1;
        }
        else
        {
            currentNode->solvedBranchResultMap[branchId]++;
        }
    }
}

int StateSearch::stateSearch(int& iteratorVariable)
{
    StateTraceNode* currentNode = stateTraceTree.currentNode;
    
    searchedCount++;

    selectState();

    while(!stateTraceTree.currentNode)
    {
        randomRun(100);
    }

    currentNode = stateTraceTree.currentNode;
    if(!currentNode)
    {
        return -1;
    }

    
    // 已经存在子节点尝试过该期望分支了，就直接跳过此次执行
    int hadChildNode = -1;
    for(int i = 0; i < currentNode->children.size(); i++) {
        StateTraceNode* child = currentNode->children[i];
        if(child->exceptBranchId == stateTraceTree.selectedBranchId) {
            hadChildNode = i;
            break;
        }
    }
    if(hadChildNode != -1) {
        stateTraceTree.currentNode = currentNode->children[hadChildNode];
        return achievedCount;
    }
    
    bool tryRes = tryStateBranchInner(currentNode, stateTraceTree.selectedBranchId);
    
        
    achievedCount = BitmapCov::branchCov;

    outputNewCoverageTestCase();
    
    printTCGSSState(iteratorVariable);

    return BitmapCov::branchCov;
}

void StateSearch::collectGlobalVariableOneStep(StateTraceNode* stateTraceNode)
{
    GlobalVariableOneStep* globalVariablesOneStepTemp = new GlobalVariableOneStep();
    for(int i = 0; i < globalVariableList.size(); i++)
    {
        GlobalVariableData* ref = &globalVariableList[i];
        GlobalVariableRecord targetRecord;
        targetRecord.data = new char[ref->length];
        memcpy(targetRecord.data, ref->address, ref->length);
        //targetRecord.length = ref->length;
        //targetRecord.type = ref->type;
        //targetRecord.name = ref->name;
        //targetRecord.arraySize = ref->arraySize;
        targetRecord.pointer = ref;

        globalVariablesOneStepTemp->allGlobalVariable.push_back(targetRecord);
    }
    stateTraceNode->globalVariablesOneStep = globalVariablesOneStepTemp;
}

void StateSearch::collectInputVariableOneStep(StateTraceNode* stateTraceNode, InputVariableOneStep* parameters)
{
    InputVariableOneStep* inputVariablesOneStepTemp = new InputVariableOneStep();
    for(int i = 0; i < parameters->allInputVariable.size(); i++)
    {
        InputVariableRecord* refRecord = &parameters->allInputVariable[i];
        InputVariableRecord targetRecord;
        targetRecord.data = new char[refRecord->pointer->length];
        memcpy(targetRecord.data, refRecord->data, refRecord->pointer->length);
        //targetRecord.length = refRecord->length;
        //targetRecord.type = refRecord->type;
        //targetRecord.name = refRecord->name;
        targetRecord.pointer = refRecord->pointer;
        inputVariablesOneStepTemp->allInputVariable.push_back(targetRecord);
    }
    stateTraceNode->inputVariablesOneStep = inputVariablesOneStepTemp;
}

void StateSearch::addStateTraceNode(StateTraceNode* stateTraceNode, int expectStateBranchId, InputVariableOneStep* replaceInput)
{
    StateTraceNode* nodeTemp = new StateTraceNode();
    nodeTemp->id = stateTraceTree.nodeCount;
    stateTraceTree.currentNode->children.push_back(nodeTemp);
    if(stateTraceTree.currentNode->branchChildSearchedCount.find(expectStateBranchId) == stateTraceTree.currentNode->branchChildSearchedCount.end())
        stateTraceTree.currentNode->branchChildSearchedCount[expectStateBranchId] = 0;
    stateTraceTree.currentNode->branchChildSearchedCount[expectStateBranchId]++;

    nodeTemp->parent = stateTraceTree.currentNode;
    nodeTemp->depth = nodeTemp->parent->depth + 1;
    nodeTemp->exceptBranchId = expectStateBranchId;
    nodeTemp->branchIdCovered = new unsigned char[BitmapCov::branchBitmapLength];
    nodeTemp->branchIdCoveredTotal = new unsigned char[BitmapCov::branchBitmapLength];

    if(!replaceInput)
        collectInputVariableOneStep(nodeTemp, &stateTraceNode->solvedStateSelectInputList[expectStateBranchId]);
    else
        collectInputVariableOneStep(nodeTemp, replaceInput);

    stateTraceTree.currentNode = nodeTemp;
    stateTraceTree.nodeCount++;
    stateTraceTree.allNodeList.push_back(nodeTemp);

    //stateTraceTree.unsolvedNodeList.push_back(nodeTemp);
}


bool StateSearch::tryStateBranchInner(StateTraceNode* stateTraceNode, int expectStateBranchId, InputVariableOneStep* replaceInput)
{
    BitmapCov::clearCurrentBitmap();

    addStateTraceNode(stateTraceNode, expectStateBranchId, replaceInput);
    
    tryStateBranchInner2(stateTraceTree.currentNode);
    
    bool newBranchCovered = BitmapCov::step();

    collectGlobalVariableOneStep(stateTraceTree.currentNode);
    

    // 记录Step到序列中
    
    memcpy(stateTraceTree.currentNode->branchIdCovered, BitmapCov::branchBitmap, BitmapCov::branchBitmapLength);
    memcpy(stateTraceTree.currentNode->branchIdCoveredTotal, BitmapCov::branchAllBitmap, BitmapCov::branchBitmapLength);
    stateTraceTree.currentNode->exceptBranchId = expectStateBranchId;
    if(replaceInput)
    {
        int rand_ = rand() % 10000;
        stateTraceTree.currentNode->achieveExceptBranch = rand_ < 20 ? true : false;
    }
    else
        stateTraceTree.currentNode->achieveExceptBranch = BitmapCov::branchBitmap[expectStateBranchId] != 0;
    stateTraceTree.currentNode->achieveExceptBranch = newBranchCovered;
    stateTraceTree.currentNode->achieveNewBranch = newBranchCovered;


    // 记录状态搜索节点
    if(stateTraceTree.currentNode->achieveExceptBranch)
        return true;
    
    return false;
}


void StateSearch::resetGlobalVariables(StateTraceNode* stateTraceNode)
{
    GlobalVariableOneStep* globalVariables = stateTraceNode->globalVariablesOneStep;
    for(int i = 0; i < globalVariables->allGlobalVariable.size(); i++)
    {
        GlobalVariableRecord* record = &(globalVariables->allGlobalVariable[i]);
        memcpy(record->pointer->address, record->data, record->pointer->length);
    }
}

void StateSearch::printStateTraceTree(StateTraceNode* node, string& nodeCode, string& linkCode)
{
    nodeCode += to_string((int)node);
    nodeCode += "[label=\"";
    nodeCode += "ID:";
    nodeCode += to_string(node->id);
    nodeCode += "\\nExcept:";
    nodeCode += to_string(node->exceptBranchId+1);
    nodeCode += "\\nSolveId:";
    for(int i = 0; i < node->solveId.size(); i++){
        nodeCode += to_string(node->solveId[i]+1) + ",";
    }
    nodeCode += "\\nSol:";
    for(int i = 0; i < BitmapCov::branchBitmapLength; i++){
        if(node->solvedStateSelectInputList.find(i) != node->solvedStateSelectInputList.end()){
            nodeCode += to_string(i+1) + ",";
        }
    }
    nodeCode += "\\nInputs:";
    for(int i = 0; i < node->inputVariablesOneStep->allInputVariable.size(); i++){
        InputVariableRecord& input = node->inputVariablesOneStep->allInputVariable[i];
        nodeCode += input.toString() + ", ";
    }
    nodeCode += "\\nAch:";
    for(int i = 0; i < BitmapCov::branchBitmapLength; i++){
        if(node->branchIdCovered[i]){
            nodeCode += to_string(i+1) + ",";
        }
    }
    nodeCode += "\\nTot:";
    for(int i = 0; i < BitmapCov::branchBitmapLength; i++){
        if(node->branchIdCoveredTotal[i]){
            nodeCode += to_string(i+1) + ",";
        }
    }

    nodeCode += "\", width=\"1.200000\", height=\"0.600000\"];\n";

    for(int i = 0; i < node->children.size(); i++)
    {
        linkCode += to_string((int)node) + "->" + to_string((int)node->children[i]) + ";\n";
    }
    for(int i = 0; i < node->children.size(); i++)
    {
        printStateTraceTree(node->children[i], nodeCode, linkCode);
    }
}

void StateSearch::printStateTraceTree(string outputPath)
{
    string vizCode;
    
    vizCode += "digraph {\n";
	vizCode += "graph [overlap=scalexy, rankdir=LR, ranksep=\"0.800000\", nodesep=\"1.300000\"];\n";
	vizCode += "splines=spline\n";
	vizCode += "ratio=0.6\n";
	vizCode += "node [shape=record];\n";

    string nodeCode;
    string linkCode;
    printStateTraceTree(stateTraceTree.root, nodeCode, linkCode);

    vizCode += nodeCode;
    vizCode += linkCode;
    vizCode += "}\n";

    string tempDotPath = "Temp/StateTraceTreeViz.dot";

    writeFile(tempDotPath, vizCode);

    string exePath = getExeDirPath();
    //string callGraphViz = exePath + "/Graphviz/dot.exe";
    string callGraphViz = "dot.exe";
    string tempPlainPath = outputPath; //exePath + "/Temp/StateTraceTreeViz_svg.svg";
    string cmd;
	string para = "\"" + tempDotPath + "\"" + " -Tsvg" + " -o " + "\"" + tempPlainPath + "\"";
	systemCallWithTimeOut(callGraphViz, para, 5000, exePath + "/Temp/log.txt");
}


namespace 
{
    int testCaseIdCSV = 0;
}
void StateSearch::outputTestCasesCSV(vector<StateSearch::TestCase>& testCases)
{
    if(testCases.empty())
        return;
    
    string exePath = getExeDirPath();
    string csvHeadFileName = exePath + "/TestCaseOutput/TestCaseHead.csv";
    string csvHeadFile;

    csvHeadFile += "Time";
    for(int i = 0; i < testCases[0].inputList[0]->allInputVariable.size(); i++)
    {
        InputVariableRecord* input = &testCases[0].inputList[0]->allInputVariable[i];
        csvHeadFile += ",";
        csvHeadFile += input->pointer->name;
    }
    writeFile(csvHeadFileName, csvHeadFile);

    for(int i = 0; i < testCases.size(); i++)
    {
        string csvFileName = exePath + "/TestCaseOutput/TestCase" + to_string(testCaseIdCSV+1) + ".csv";
        testCaseIdCSV++;
        string csvFile;

        for(int j = 0; j < testCases[i].length; j++)
        {
            csvFile += j != 0 ? "\n" : "";
            csvFile += to_string(testCases[i].timeList[j]);
            for(int k = 0; k < testCases[i].inputList[j]->allInputVariable.size(); k++)
            {
                InputVariableRecord* input = &testCases[i].inputList[j]->allInputVariable[k];
                csvFile += ",";
                csvFile += getVariableValueStr(input);
            }
        }
        writeFile(csvFileName, csvFile);
    }
}

namespace 
{
    vector<StateSearch::TestCase> testCasesXLS;
}
void StateSearch::outputTestCasesXLS(vector<StateSearch::TestCase>& testCases)
{
    if(testCases.empty())
        return;

    testCasesXLS.insert(testCasesXLS.end(), testCases.begin(), testCases.end());

    string exePath = getExeDirPath();
    string xlsFileName = exePath + "/TestCaseOutput/TestCase.xls";

    BasicExcel e;
    e.New(testCasesXLS.size());
    for(int i = 0; i < testCasesXLS.size(); i++)
    {
        string sheetNameOri = "Sheet" + to_string(i+1);
        string sheetName = "TestCase" + to_string(i+1);
        e.RenameWorksheet(sheetNameOri.c_str(), sheetName.c_str());
	    BasicExcelWorksheet* sheet = e.GetWorksheet(i);
        BasicExcelCell* cell;

        cell = sheet->Cell(0,0);
        cell->SetString("Time");

        for(int j = 0; j < testCasesXLS[i].inputList[0]->allInputVariable.size(); j++)
        {
            InputVariableRecord* input = &testCasesXLS[i].inputList[0]->allInputVariable[j];
            cell = sheet->Cell(0, j + 1);
            cell->SetString(input->pointer->name.c_str());
        }

        for(int j = 0; j < testCasesXLS[i].length; j++)
        {
            cell = sheet->Cell(j + 1, 0);
            cell->SetDouble(testCasesXLS[i].timeList[j]);
            
            for(int k = 0; k < testCasesXLS[i].inputList[j]->allInputVariable.size(); k++)
            {
                InputVariableRecord* input = &testCasesXLS[i].inputList[j]->allInputVariable[k];
                string valStr = getVariableValueStr(input);
                cell = sheet->Cell(j + 1, k + 1);
                if(input->pointer->type == "f32" || input->pointer->type == "f64")
                    cell->SetDouble(stringToFloat(valStr));
                else
                    cell->SetInteger(stringToInt(valStr));
            }
        }
    }
    e.SaveAs(xlsFileName.c_str());
}


namespace 
{
    int testCaseIdBin = 0;
}
void StateSearch::outputTestCasesBinary(vector<TestCase>& testCases)
{
    if(testCases.empty())
        return;
    
    string exePath = getExeDirPath();
    

    for(int i = 0; i < testCases.size(); i++)
    {
        string binFileName = exePath + "/TestCaseOutput/Binary/TestCase" + to_string(testCaseIdBin+1) + ".bin";
        testCaseIdBin++;
        //string csvFile;
        ofstream file;
        file.open(binFileName, ios::out|ios::binary);

        for(int j = 0; j < testCases[i].length; j++)
        {
            //csvFile += j != 0 ? "\n" : "";
            //csvFile += to_string(testCases[i].timeList[j]);
            for(int k = 0; k < testCases[i].inputList[j]->allInputVariable.size(); k++)
            {
                InputVariableRecord* input = &testCases[i].inputList[j]->allInputVariable[k];
                //csvFile += ",";
                //csvFile += getVariableValueStr(input);
                file.write(input->data, input->pointer->length);
            }
        }
        file.close();
    }
}

vector<StateSearch::TestCase> StateSearch::collectTestCases()
{
    vector<StateSearch::TestCase> ret;
    if(stateTraceTree.root->children.empty())
        return ret;

    unordered_map<StateTraceNode*, bool> genCaseNodes;

    vector<StateTraceNode*> allAchieveNewBranchNodes;
    vector<StateTraceNode*> allAchieveNewBranchEndNodes;
    for(int i = 0; i < stateTraceTree.allNodeList.size(); i++)
    {
        if(!stateTraceTree.allNodeList[i]->achieveNewBranch)
            continue;
        allAchieveNewBranchNodes.push_back(stateTraceTree.allNodeList[i]);
        if(!stateTraceTree.allNodeList[i]->children.empty())
            continue;
        allAchieveNewBranchEndNodes.push_back(stateTraceTree.allNodeList[i]);
    }

    for(int i = 0; i < allAchieveNewBranchEndNodes.size(); i++)
    {
        StateTraceNode* node = allAchieveNewBranchEndNodes[i];
        TestCase testCase;
        testCase.length = node->depth;
        StateTraceNode* p = node;
        while(p && p != stateTraceTree.root) {
            genCaseNodes[p] = true;
            if(p->inputVariablesOneStep && !p->inputVariablesOneStep->allInputVariable.empty())
            {
                testCase.inputList.insert(testCase.inputList.begin(), p->inputVariablesOneStep);
                testCase.timeList.insert(testCase.timeList.begin(), p->depth - 1);
            }
            p = p->parent;
        }
        if(testCase.length == 1)
        {
            testCase.inputList.push_back(testCase.inputList[0]);
            testCase.timeList.push_back(1);
            testCase.length = 2;
        }
        ret.push_back(testCase);
    }
    sort(allAchieveNewBranchNodes.begin(), allAchieveNewBranchNodes.end(), 
        [](const StateTraceNode* x, const StateTraceNode* y) -> int {
        return x->depth > y->depth;
    });

    for(int i = 0; i < allAchieveNewBranchNodes.size(); i++)
    {
        StateTraceNode* node = allAchieveNewBranchNodes[i];
        if(genCaseNodes.find(node) != genCaseNodes.end()) {
            continue;
        }
        TestCase testCase;
        testCase.length = node->depth;
        StateTraceNode* p = node;
        while(p && p != stateTraceTree.root) {
            genCaseNodes[p] = true;
            if(p->inputVariablesOneStep && !p->inputVariablesOneStep->allInputVariable.empty())
            {
                testCase.inputList.insert(testCase.inputList.begin(), p->inputVariablesOneStep);
                testCase.timeList.insert(testCase.timeList.begin(), p->depth-1);
            }
            p = p->parent;
        }
        if(testCase.length == 1)
        {
            testCase.inputList.push_back(testCase.inputList[0]);
            testCase.timeList.push_back(1);
            testCase.length = 2;
        }
        ret.push_back(testCase);
    }

    //queue<StateTraceNode*> nodeList;
    //nodeList.push(stateTraceTree.root);
    //while(!nodeList.empty())
    //{
    //    StateTraceNode* node = nodeList.front();
    //    nodeList.pop();
    //
    //    if(!node->children.empty())
    //    {
    //        for(int i = 0; i < node->children.size(); i++)
    //        {
    //            nodeList.push(node->children[i]);
    //        }
    //    }
    //    else
    //    {
    //        TestCase testCase;
    //        testCase.length = node->depth;
    //
    //        StateTraceNode* p = node;
    //        while(p && p != stateTraceTree.root) {
    //            testCase.inputList.insert(testCase.inputList.begin(), p->inputVariablesOneStep);
    //            testCase.timeList.insert(testCase.timeList.begin(), p->depth);
    //            p = p->parent;
    //        }
    //        ret.push_back(testCase);
    //    }
    //}
    return ret;
}

void StateSearch::printTCGSSState(int iteratorVariable)
{
    
    string logStr;

    long long curTime = clock();
    long long testCostTime = (curTime - startTime);

    logStr += "Time: " + stringFillBlank(to_string(iteratorVariable), 6) + " ";
    logStr += "Iter: " + stringFillBlank(to_string(iteratorVariable), 6) + " ";
    logStr += "NodeCount: " + stringFillBlank(to_string(stateTraceTree.nodeCount), 6) + " ";
    logStr += "CurNode: " + stringFillBlank(to_string(stateTraceTree.currentNode->id), 6) + " ";
    logStr += "CurDepth: " + stringFillBlank(to_string(stateTraceTree.currentNode->depth), 6) + " ";
    logStr += "Path: " + stringFillBlank(to_string(stateTraceTree.selectedBranchId), 6) + " ";
    logStr += "SolveTimes: " + stringFillBlank(to_string(solveTimes), 6) + " ";
    logStr += "Achieved: " + stringFillBlank(to_string(achievedCount), 6, true) + "/" + stringFillBlank(to_string(BitmapCov::branchBitmapLength), 6) + " ";

    logStr +=  "CostTimes: " + to_string(testCostTime) + " ";
    logStr +=  "\n";
    
    cout << logStr;
    appendFile("log.txt", logStr);
}

namespace 
{
    int lastTestOutputNodeId = 0;
}
void StateSearch::outputNewCoverageTestCase()
{
    for(int i = lastTestOutputNodeId; i < stateTraceTree.allNodeList.size(); i++)
    {
        StateTraceNode* node = stateTraceTree.allNodeList[i];
        if(!node->achieveNewBranch)
            continue;
        
        TestCase testCase;
        testCase.length = node->depth;
        StateTraceNode* p = node;
        while(p && p != stateTraceTree.root) {
            if(p->inputVariablesOneStep && !p->inputVariablesOneStep->allInputVariable.empty())
            {
                testCase.inputList.insert(testCase.inputList.begin(), p->inputVariablesOneStep);
                testCase.timeList.insert(testCase.timeList.begin(), p->depth-1);
            }
            p = p->parent;
        }
        if(testCase.length == 1)
        {
            testCase.inputList.push_back(testCase.inputList[0]);
            testCase.timeList.push_back(1);
            testCase.length = 2;
        }

        vector<TestCase> tss;
        tss.push_back(testCase);
        outputTestCasesCSV(tss);
        outputTestCasesXLS(tss);
        outputTestCasesBinary(tss);
    }
    lastTestOutputNodeId = stateTraceTree.allNodeList.size();
}

bool StateSearch::tryStateBranchInner2(StateSearch::StateTraceNode* stateTraceNode)
{
    // exec code
    int len = 0;
    for(int i = 0; i < stateTraceNode->inputVariablesOneStep->allInputVariable.size(); i++)
    {
        len += stateTraceNode->inputVariablesOneStep->allInputVariable[i].pointer->length;
    }
    if(len == 0)
    {
        tryStateBranch(nullptr, len);
        return true;
    }
    char* data = (char*)malloc(len);
    char* addr = data;
    for(int i = 0; i < stateTraceNode->inputVariablesOneStep->allInputVariable.size(); i++)
    {
        memcpy(addr,
            stateTraceNode->inputVariablesOneStep->allInputVariable[i].data,
            stateTraceNode->inputVariablesOneStep->allInputVariable[i].pointer->length);
        addr += stateTraceNode->inputVariablesOneStep->allInputVariable[i].pointer->length;
    }
    tryStateBranch(data, len);
    free(data);
    return true;
}
