#pragma once
#include <map>
#include <string>
#include <vector>
using namespace std;

class TestCaseConverter
{
public:
    // 用来记录程序运行过程中的一个输入参数数据
    struct InputVariableRecord
    {
        InputVariableRecord(char* data, int length, string type, string name);
        char* data = nullptr;
        int length;
        string type;
        string name;

        string toString();
    };

    // 用来记录程序一次Step执行后的全部输入参数数据
    struct InputVariableOneStep
    {
        vector<InputVariableRecord> allInputVariable;
    };
    
    struct TestCase
    {
        vector<float> timeList;
        vector<InputVariableOneStep*> inputList;
        int length = 0;
    };
    
    static string getVariableValueStr(InputVariableRecord* variableRecord);
    static string getVariableValueStr(string type, char* addr, int offset);

    static void outputTestCasesCSV(vector<TestCaseConverter::TestCase>& testCases, string outputDir);
    static void outputTestCasesXLS(vector<TestCaseConverter::TestCase>& testCases, string outputDir);
};