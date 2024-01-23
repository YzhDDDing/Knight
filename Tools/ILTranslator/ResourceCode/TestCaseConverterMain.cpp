#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "LibFuzzerUtility.h"
#include "TestCaseConverter.h"
#include "Utility.h"
using namespace std;
vector<TestCaseConverter::TestCase> testCases;
TestCaseConverter::TestCase TestOneInput(const uint8_t *data, size_t size);
int main(int argc, char *argv[])
{
    if(argc < 3)
        return -1;
    cout << "Run\n";
	string inputDir = string(argv[1]);
    string outputDir = string(argv[2]);
    if(stringEndsWith(outputDir, "/") || stringEndsWith(outputDir, "\\"))
    {
        outputDir = outputDir.substr(0, outputDir.length() - 1);
    }
    if(stringEndsWith(inputDir, "/") || stringEndsWith(inputDir, "\\"))
    {
        inputDir = inputDir.substr(0, inputDir.length() - 1);
    }
    vector<string> inputFileList;
    listFiles(inputDir, inputFileList);
    for(int i = 0; i < inputFileList.size(); i++)
    {
        int length = 0;
        char* binary = readFileBinary(inputDir + "/" + inputFileList[i], length);
        if(length > 0 && binary)
        {
            TestCaseConverter::TestCase tempTestCase = TestOneInput((uint8_t*)binary, length);
            testCases.push_back(tempTestCase);
            tempTestCase = testCases[testCases.size()-1];
            cout << "TestCse " << testCases.size() << ": " << 
                inputFileList[i] << " BinaryLen: " << setw(8) << std::left << length << 
                " Len: " << testCases[testCases.size()-1].inputList.size() << endl;
        }
        if(binary)
        {
            delete[] binary;
        }
    }
    TestCaseConverter::TestCase tempTestCase = testCases[testCases.size()-1];
    TestCaseConverter::outputTestCasesCSV(testCases, outputDir);
    TestCaseConverter::outputTestCasesXLS(testCases, outputDir);
    for(int i = 0; i < testCases.size(); i++)
    {
        for(int j = 0; j < testCases[i].inputList.size(); j++)
        {
            for(int k = 0; k < testCases[i].inputList[j]->allInputVariable.size(); k++)
            {
                TestCaseConverter::InputVariableRecord* input = &testCases[i].inputList[j]->allInputVariable[k];
                free(input->data);
            }
            delete testCases[i].inputList[j];
        }
    }
	return 0;
}