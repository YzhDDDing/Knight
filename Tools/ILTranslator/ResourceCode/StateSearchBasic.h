#pragma once

#include <map>
#include <string>
#include <vector>


using namespace std;

class StateSearch
{
public:
    struct StateTraceNode;

    // ���ڼ�¼�����е�ȫ��ȫ�ֱ���
    struct GlobalVariableData
    {
        char* address = nullptr;
        int length;
        string type;
        string name;
        vector<int> arraySize;
    };

    // ������¼�������й����е�һ��ȫ�ֱ�������
    struct GlobalVariableRecord
    {
        char* data = nullptr;
        //int length;
        //string type;
        //string name;
        //vector<int> arraySize;
        GlobalVariableData* pointer = nullptr;
    };

    // ������¼����һ��Stepִ�к��ȫ��ȫ�ֱ�������
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

    // ������¼�������й����е�һ�������������
    struct InputVariableRecord
    {
        char* data = nullptr;
        //int length;
        //string type;
        //string name;

        InputVariableData* pointer = nullptr;

        string toString();
    };

    // ������¼����һ��Stepִ�к��ȫ�������������
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

        // ÿ��״̬�����ڵ㶼�洢ȫ�������ȫ�ֱ�������ʵ�洢������
        InputVariableOneStep* inputVariablesOneStep = nullptr;
        GlobalVariableOneStep* globalVariablesOneStep = nullptr;

        int exceptBranchId = -1;
        bool achieveExceptBranch = false;
        bool achieveNewBranch = false;
        unsigned char* branchIdCovered;
        unsigned char* branchIdCoveredTotal;

        vector<int> solveId;

        // ���ڼ�¼��ǰ����״̬ѡ������룬��¼����״̬Branch������
        map<int, InputVariableOneStep> solvedStateSelectInputList;
        map<int, int> solvedBranchResultMap; //��¼��ǰ�ڵ���ⲻͬ��֧�Ľ��

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

    // ע��״̬Branch
    static void registStateBranch(map<int, string>& branchList, map<int, int>& branchDepth);

    // ״̬����ʱ��״̬ѡ����������һ��BranchId
    static void selectState();

    static void randomRun(int nTimes);
    
    static bool tryStateBranchInner(StateTraceNode* stateTraceNode, int expectStateBranchId, InputVariableOneStep* replaceInput = nullptr);
    static bool tryStateBranchInner2(StateTraceNode* stateTraceNode); 


    // ��ĳ�εļ�¼�ָ�ȫ�ֱ���
    static void resetGlobalVariables(StateTraceNode* stateTraceNode);


    // ���� ��ǰ��ȫ�ֱ��� ���
    static void solveInputVariable(StateTraceNode* stateTraceNode, int branchId);

    // ���ɴ�����ȫ�ֱ����Ĵ����ļ�
    static void generateCodeWithNewGlobalVariable(StateTraceNode* stateTraceNode);
    static string getVariableStr(GlobalVariableRecord* variableRecord);
    static string getVariableValueStr(GlobalVariableRecord* variableRecord, int offset);
    static string getVariableValueStr(InputVariableRecord* variableRecord);
    static string getVariableValueStr(string type, char* addr, int offset);

    // ����CBMC���
    static void callCBMC(int branchId);

    // ����CBMC����ļ�����������
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
    
    // ����һ����֧���ж����Ƿ������������֧
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


bool tryStateBranch(char* data, int size); // �ڳ���������ʵ�֣��Զ����ɣ�