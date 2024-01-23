#pragma once

#include <map>
#include <string>
#include <vector>


using namespace std;

class StateSearch
{
public:
    struct StateTraceNode;

    // 用于记录程序中的全部全局变量
    struct GlobalVariableData
    {
        char* address = nullptr;
        int length;
        string type;
        string name;
        vector<int> arraySize;
    };

    // 用来记录程序运行过程中的一个全局变量数据
    struct GlobalVariableRecord
    {
        char* data = nullptr;
        //int length;
        //string type;
        //string name;
        //vector<int> arraySize;
        GlobalVariableData* pointer = nullptr;
    };

    // 用来记录程序一次Step执行后的全部全局变量数据
    struct GlobalVariableOneStep
    {
        vector<GlobalVariableRecord> allGlobalVariable;
    };

    struct InputVariableData
    {
        int length;
        string type;
        string name;
    };

    // 用来记录程序运行过程中的一个输入参数数据
    struct InputVariableRecord
    {
        char* data = nullptr;
        //int length;
        //string type;
        //string name;

        InputVariableData* pointer = nullptr;

        string toString();
    };

    // 用来记录程序一次Step执行后的全部输入参数数据
    struct InputVariableOneStep
    {
        vector<InputVariableRecord> allInputVariable;
    };
    
    struct StateTraceNode
    {
        int id = -1;
        StateTraceNode* parent = nullptr;
        vector<StateTraceNode*> children;
        map<int, int> branchChildSearchedCount;

        // 每个状态搜索节点都存储全部输入和全局变量，真实存储在这里
        InputVariableOneStep* inputVariablesOneStep = nullptr;
        GlobalVariableOneStep* globalVariablesOneStep = nullptr;

        int exceptBranchId = -1;
        bool achieveExceptBranch = false;
        bool achieveNewBranch = false;
        unsigned char* branchIdCovered;
        unsigned char* branchIdCoveredTotal;

        vector<int> solveId;

        // 用于记录当前用于状态选择的输入，记录所有状态Branch的输入
        map<int, InputVariableOneStep> solvedStateSelectInputList;
        map<int, int> solvedBranchResultMap; //记录当前节点求解不同分支的结果

        int depth = -1;
        
    };

    struct StateTraceTree
    {
        StateTraceNode* root = nullptr;
        StateTraceNode* currentNode = nullptr;
        int selectedBranchId = -1;
        int nodeCount = 0;
        
        vector<StateTraceNode*> allNodeList;
        vector<InputVariableOneStep> allInputVariableOneStepList;
    };

    struct TestCase
    {
        vector<float> timeList;
        vector<InputVariableOneStep*> inputList;
        int length = 0;
    };

    static void initStateSearch(int argc, char *argv[]);
    static void initStateSearch2();
    static void terminateStateSearch();

    static void runExistTestCaseBinary(string dirPath);

    static void registGlobalVariables(string name, string type, vector<int>& arraySize, char* address, int length);
    static void registInputs(string name, string type, int length);

    // 注册状态Branch
    static void registStateBranch(map<int, string>& branchList, map<int, int>& branchDepth);

    // 状态搜索时的状态选择函数，返回一个BranchId
    static void selectState();

    static void randomRun(int nTimes);
    
    static bool tryStateBranchInner(StateTraceNode* stateTraceNode, int expectStateBranchId, InputVariableOneStep* replaceInput = nullptr);
    static bool tryStateBranchInner2(StateTraceNode* stateTraceNode); 


    // 用某次的记录恢复全局变量
    static void resetGlobalVariables(StateTraceNode* stateTraceNode);


    // 根据 当前的全局变量 求解
    static void solveInputVariable(StateTraceNode* stateTraceNode, int branchId);

    // 生成带有新全局变量的代码文件
    static void generateCodeWithNewGlobalVariable(StateTraceNode* stateTraceNode);
    static string getVariableStr(GlobalVariableRecord* variableRecord);
    static string getVariableValueStr(GlobalVariableRecord* variableRecord, int offset);
    static string getVariableValueStr(InputVariableRecord* variableRecord);
    static string getVariableValueStr(string type, char* addr, int offset);

    // 调用CBMC求解
    static void callCBMC(int branchId);

    // 解析CBMC输出文件获得输入参数
    static void parseCBMCResult(StateTraceNode* stateTraceNode, int branchId);

    static int stateSearch(int& iteratorVariable);

    static void collectInputVariableOneStep(StateTraceNode* stateTraceNode, InputVariableOneStep* parameters);
    static void collectGlobalVariableOneStep(StateTraceNode* stateTraceNode);
    static void addStateTraceNode(StateTraceNode* stateTraceNode, int expectStateBranchId, InputVariableOneStep* replaceInput=nullptr);
    

    static void printStateTraceTree(StateTraceNode* node, string& nodeCode, string& linkCode);
    static void printStateTraceTree(string outputPath);

    static void outputTestCasesCSV(vector<TestCase>& testCases);
    static void outputTestCasesXLS(vector<TestCase>& testCases);
    static void outputTestCasesBinary(vector<TestCase>& testCases);
    static vector<TestCase> collectTestCases();

    static void printTCGSSState(int iteratorVariable);

    static void outputNewCoverageTestCase();

    static string paraBinaryTestCaseFilePath;
	static int paraMaxRunTime;
	static int paraMaxRunIterator;
    
    // 尝试一个分支，判断其是否可以走期望分支
    static int solveTimes;
    static StateTraceTree stateTraceTree;
    static int achievedCount;
    static int searchedCount;
    static map<int, string> stateBranchList;
    static vector<int> branchSolveOrder;
    static vector<GlobalVariableData> globalVariableList;
    static vector<InputVariableData> inputList;
    static int inputsDataLengthTotal;
    static int unwindCount;

    static string cbmcParameter;
    static long long startTime;
};


bool tryStateBranch(char* data, int size); // 在程序主体中实现（自动生成）