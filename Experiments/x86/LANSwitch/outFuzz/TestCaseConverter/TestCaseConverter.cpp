#include "TestCaseConverter.h"
#include "BasicExcel.hpp"
#include <string.h>
#include "Utility.h"
using namespace YCompoundFiles;
using namespace YExcel;

TestCaseConverter::InputVariableRecord::InputVariableRecord(char* data, int length, string type, string name)
{
    this->data = (char*)malloc(length);
    ::memcpy(this->data, data, length);
    this->length = length;
    this->type = type;
    this->name = name;
}

string TestCaseConverter::InputVariableRecord::toString()
{
    string retCode = "(" + type + ")";
    if(type == "u8")
    {
        unsigned char ret;
        ::memcpy(&ret, data, sizeof(unsigned char));
        retCode += to_string(ret);
    }
    if(type == "i8")
    {
        char ret;
        ::memcpy(&ret, data, sizeof(char));
        retCode += to_string(ret);
    }
    if(type == "u16")
    {
        unsigned short ret;
        ::memcpy(&ret, data, sizeof(unsigned short));
        retCode += to_string(ret);
    }
    if(type == "i16")
    {
        short ret;
        ::memcpy(&ret, data, sizeof(short));
        retCode += to_string(ret);
    }
    if(type == "i32")
    {
        int ret;
        ::memcpy(&ret, data, sizeof(int));
        retCode += to_string(ret);
    }
    if(type == "i64")
    {
        long long ret;
        ::memcpy(&ret, data, sizeof(long long));
        retCode += to_string(ret);
    }
    if(type == "u32")
    {
        unsigned int ret;
        ::memcpy(&ret, data, sizeof(unsigned int));
        retCode += to_string(ret);
    }
    if(type == "u64")
    {
        unsigned long long ret;
        ::memcpy(&ret, data, sizeof(unsigned long long));
        retCode += to_string(ret);
    }
    if(type == "f32")
    {
        float ret;
        ::memcpy(&ret, data, sizeof(float));
        retCode += to_string(ret);
    }
    if(type == "f64")
    {
        double ret;
        ::memcpy(&ret, data, sizeof(double));
        retCode += to_string(ret);
    }
    if(retCode == "nan" || retCode == "-nan" || retCode == "inf" || retCode == "-inf")
        retCode = "0";
    return retCode;
}

void TestCaseConverter::outputTestCasesCSV(vector<TestCaseConverter::TestCase>& testCases, string outputDir)
{
    if(testCases.empty())
        return;
    
    string csvHeadFileName = outputDir + "/TestCaseHead.csv";
    string csvHeadFile;

    csvHeadFile += "Time";
    int headIndex = 0;
    while(testCases[headIndex].inputList.empty())
    {
        headIndex++;
        if(headIndex >= testCases.size())
            return;
    }
    for(int i = 0; i < testCases[headIndex].inputList[0]->allInputVariable.size(); i++)
    {
        InputVariableRecord* input = &testCases[headIndex].inputList[0]->allInputVariable[i];
        csvHeadFile += ",";
        csvHeadFile += input->name;
    }
    writeFile(csvHeadFileName, csvHeadFile);

    for(int i = 0; i < testCases.size(); i++)
    {
        string csvFileName = outputDir + "/TestCase" + to_string(i+1) + ".csv";
        string csvFile;
        if(testCases[i].inputList.empty())
            continue;
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
        if(testCases[i].length == 1)
        {
            csvFile += "\n";
            csvFile += to_string(testCases[i].timeList[0] + 1);
            for(int k = 0; k < testCases[i].inputList[0]->allInputVariable.size(); k++)
            {
                InputVariableRecord* input = &testCases[i].inputList[0]->allInputVariable[k];
                csvFile += ",";
                csvFile += getVariableValueStr(input);
            }
        }
        writeFile(csvFileName, csvFile);
    }
}

void TestCaseConverter::outputTestCasesXLS(vector<TestCaseConverter::TestCase>& testCases, string outputDir)
{
    if(testCases.empty())
        return;
    
    string xlsFileName = outputDir + "/TestCase.xls";

    BasicExcel e;
    e.New(testCases.size());
    for(int i = 0; i < testCases.size(); i++)
    {
        if(testCases[i].inputList.empty())
            continue;
        string sheetNameOri = "Sheet" + to_string(i+1);
        string sheetName = "TestCase" + to_string(i+1);
        e.RenameWorksheet(sheetNameOri.c_str(), sheetName.c_str());
	    BasicExcelWorksheet* sheet = e.GetWorksheet(i);
        BasicExcelCell* cell;

        cell = sheet->Cell(0,0);
        cell->SetString("Time");

        for(int j = 0; j < testCases[i].inputList[0]->allInputVariable.size(); j++)
        {
            InputVariableRecord* input = &testCases[i].inputList[0]->allInputVariable[j];
            cell = sheet->Cell(0, j + 1);
            cell->SetString(input->name.c_str());
        }

        for(int j = 0; j < testCases[i].length; j++)
        {
            cell = sheet->Cell(j + 1, 0);
            cell->SetDouble(testCases[i].timeList[j]);
            
            for(int k = 0; k < testCases[i].inputList[j]->allInputVariable.size(); k++)
            {
                InputVariableRecord* input = &testCases[i].inputList[j]->allInputVariable[k];
                string valStr = getVariableValueStr(input);
                cell = sheet->Cell(j + 1, k + 1);
                if(input->type == "f32" || input->type == "f64")
                {
                    cell->SetDouble(stringToFloat(valStr));
                }
                else{
                    cell->SetInteger(stringToInt(valStr));
                }
            }
        }
        if(testCases[i].length == 1)
        {
            cell = sheet->Cell(2, 0);
            cell->SetDouble(testCases[i].timeList[0] + 1);
            
            for(int k = 0; k < testCases[i].inputList[0]->allInputVariable.size(); k++)
            {
                InputVariableRecord* input = &testCases[i].inputList[0]->allInputVariable[k];
                string valStr = getVariableValueStr(input);
                cell = sheet->Cell(2, k + 1);
                if(input->type == "f32" || input->type == "f64")
                {
                    cell->SetDouble(stringToFloat(valStr));
                }
                else{
                    cell->SetInteger(stringToInt(valStr));
                }
            }
        }
    }
    e.SaveAs(xlsFileName.c_str());
}

string TestCaseConverter::getVariableValueStr(InputVariableRecord* variableRecord)
{
    return getVariableValueStr(variableRecord->type, variableRecord->data, 0);
}

string TestCaseConverter::getVariableValueStr(string type, char* addr, int offset)
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
    if(type == "u16")
    {
        unsigned short ret;
        ::memcpy(&ret, addr + offset, sizeof(unsigned short));
        retCode += to_string(ret);
    }
    if(type == "i16")
    {
        short ret;
        ::memcpy(&ret, addr + offset, sizeof(short));
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
    if(retCode == "nan" || retCode == "-nan" || retCode == "inf" || retCode == "-inf")
        retCode = "0";
    return retCode;
}